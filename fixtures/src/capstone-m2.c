/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct channel {
    uint16_t code;
    int16_t bias;
    uint8_t rotate;
    uint8_t lane;
    uint16_t seed;
    uint32_t key;
};

static const struct channel channels[] = {
    {137,  6,  5, 1, 0x1137, 0x13579bdfu},
    {251, -5,  9, 3, 0x2251, 0x2468ace0u},
    {389, 12, 13, 2, 0x3389, 0x0f1e2d3cu},
    {503,  3, 17, 0, 0x4503, 0xa5a55a5au}
};

static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u - n)); }

static const struct channel *find_channel(unsigned code)
{
    size_t i;
    for (i = 0; i < sizeof channels / sizeof channels[0]; ++i)
        if (channels[i].code == code) return &channels[i];
    return NULL;
}

static uint32_t ticket(const struct channel *c, const unsigned char *s)
{
    uint32_t x = c->key ^ ((uint32_t)c->seed << 8);
    unsigned i = 1;
    while (*s) {
        uint32_t v = (uint32_t)*s++ + (int32_t)c->bias;
        x ^= v + i * (0x1021u + c->lane);
        x = rol32(x, c->rotate);
        ++i;
    }
    return x ^ ((uint32_t)c->code << 16);
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long code;
    const struct channel *c;
    uint32_t x;
    if (argc != 3) return 2;
    code = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || code > 65535u || strlen(argv[2]) < 2u) return 3;
    c = find_channel((unsigned)code);
    if (!c) { puts("state=unmapped"); return 4; }
    x = ticket(c, (const unsigned char *)argv[2]);
    printf("state=ok lane=%u class=%u ticket=%08lx\n",
           c->lane, (unsigned)(((x >> 29) + c->lane) & 7u), (unsigned long)x);
    return 0;
}
