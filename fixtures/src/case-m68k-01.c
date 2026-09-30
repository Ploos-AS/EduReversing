/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile {
    uint16_t code;
    int16_t delta;
    uint8_t rotate;
    uint8_t class_bias;
    uint16_t seed;
    uint32_t key;
};

static const struct profile profiles[] = {
    { 68,  4,  3, 1, 0x1068, 0x10203040u },
    { 99, -6,  9, 2, 0x2099, 0x55667788u },
    { 120, 7, 13, 0, 0x3120, 0xa1b2c3d4u }
};

static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u - n)); }

static const struct profile *find_profile(unsigned code)
{
    size_t i;
    for (i = 0; i < sizeof profiles / sizeof profiles[0]; ++i)
        if (profiles[i].code == code) return &profiles[i];
    return NULL;
}

static uint32_t digest(const struct profile *p, const unsigned char *s)
{
    uint32_t x = p->key ^ ((uint32_t)p->seed << 8);
    unsigned i = 1;
    while (*s) {
        uint32_t v = (uint32_t)*s++ + (int32_t)p->delta;
        x += v ^ (i++ * 0x1021u);
        x = rol32(x, p->rotate);
    }
    return x ^ p->code;
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long code;
    const struct profile *p;
    uint32_t value;
    if (argc != 3) return 2;
    code = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || code > 65535u || !*argv[2]) return 3;
    p = find_profile((unsigned)code);
    if (!p) { puts("state=unknown"); return 4; }
    value = digest(p, (const unsigned char *)argv[2]);
    printf("state=ok class=%u value=%08lx\n",
           (unsigned)(((value >> 30) + p->class_bias) & 3u),
           (unsigned long)value);
    return 0;
}
