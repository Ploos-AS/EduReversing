/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct route {
    uint16_t id;
    int16_t bias;
    uint8_t rotate;
    uint8_t lane;
    uint32_t key;
};

static const struct route routes[] = {
    {121,  5,  7, 1, 0x10293847u},
    {242, -3, 11, 2, 0x55667788u},
    {363,  9, 17, 0, 0xa1b2c3d4u}
};

static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u - n)); }

static const struct route *find_route(unsigned id)
{
    size_t i;
    for (i = 0; i < sizeof routes / sizeof routes[0]; ++i)
        if (routes[i].id == id) return &routes[i];
    return NULL;
}

static uint32_t token(const struct route *r, const unsigned char *s)
{
    uint32_t x = r->key ^ r->id;
    unsigned i = 0;
    while (*s) {
        uint32_t v = (uint32_t)*s++ + (int32_t)r->bias;
        x ^= v + (i++ * (r->lane + 1u));
        x = rol32(x, r->rotate);
    }
    return x;
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long id;
    const struct route *r;
    uint32_t x;
    if (argc != 3) return 2;
    id = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || id > 65535u || !*argv[2]) return 3;
    r = find_route((unsigned)id);
    if (!r) { puts("state=unknown"); return 4; }
    x = token(r, (const unsigned char *)argv[2]);
    printf("state=ok lane=%u token=%08x\n", r->lane, (unsigned)x);
    return 0;
}
