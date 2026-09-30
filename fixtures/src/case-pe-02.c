/* SPDX-License-Identifier: MIT
 * Benign advanced PE investigation fixture.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile {
    uint16_t id;
    int16_t bias;
    uint8_t rotate;
    uint8_t lane;
    uint16_t salt;
    uint32_t key;
};

static const struct profile profiles[] = {
    {101,  7,  5, 1, 0x0137, 0x10293847u},
    {205, -4,  9, 3, 0x0249, 0x55667788u},
    {309, 13, 13, 2, 0x035b, 0xa1b2c3d4u},
    {417,  2, 17, 0, 0x046d, 0x0f1e2d3cu}
};

static const volatile char diagnostic[] = "training-marker:PE-CASE-05";

static uint32_t rol32(uint32_t x, unsigned n)
{
    return (x << n) | (x >> (32u - n));
}

static const struct profile *find_profile(unsigned id)
{
    size_t i;
    for (i = 0; i < sizeof profiles / sizeof profiles[0]; ++i)
        if (profiles[i].id == id)
            return &profiles[i];
    return NULL;
}

static uint32_t digest(const struct profile *p, const unsigned char *s)
{
    uint32_t x = p->key ^ p->salt;
    unsigned i = 0;
    while (*s) {
        uint32_t v = (uint32_t)*s++ + (int32_t)p->bias;
        x ^= v + (uint32_t)(i++ * (p->lane + 1u));
        x = rol32(x, p->rotate);
    }
    return x ^ ((uint32_t)p->id << 16);
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long id;
    const struct profile *p;
    uint32_t value;

    if (argc != 3) {
        fputs("case-pe-02: ID TEXT\n", stderr);
        return 2;
    }

    id = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || id > 65535u || !*argv[2])
        return 3;

    p = find_profile((unsigned)id);
    if (!p) {
        puts("status=unknown");
        return 4;
    }

    value = digest(p, (const unsigned char *)argv[2]);
    if (diagnostic[0] == '\0')
        puts((const char *)diagnostic);

    printf("status=ok lane=%u token=%08x\n",
           (unsigned)p->lane, (unsigned)value);
    return 0;
}
