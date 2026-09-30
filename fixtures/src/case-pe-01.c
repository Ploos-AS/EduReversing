/* SPDX-License-Identifier: MIT
 * Benign PE investigation fixture. Students should not inspect before analysis.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rule {
    char tag;
    uint8_t rotate;
    uint16_t add;
    uint32_t key;
};

static const struct rule rules[] = {
    {'R', 3,  19, 0x10203040u},
    {'S', 7,  43, 0x55667788u},
    {'T', 11, 71, 0xa1b2c3d4u}
};

static uint32_t rol32(uint32_t x, unsigned n)
{
    return (x << n) | (x >> (32u - n));
}

static const struct rule *find_rule(char tag)
{
    size_t i;
    for (i = 0; i < sizeof rules / sizeof rules[0]; ++i)
        if (rules[i].tag == tag)
            return &rules[i];
    return NULL;
}

static uint32_t process(const struct rule *r, const unsigned char *p)
{
    uint32_t x = r->key;
    while (*p) {
        x ^= (uint32_t)*p++ + r->add;
        x = rol32(x, r->rotate);
    }
    return x;
}

int main(int argc, char **argv)
{
    const struct rule *r;
    uint32_t value;

    if (argc != 2 || strlen(argv[1]) < 3 || argv[1][1] != ':') {
        fputs("case-pe-01: TAG:TEXT\n", stderr);
        return 2;
    }

    r = find_rule(argv[1][0]);
    if (!r) {
        puts("result=unknown");
        return 4;
    }

    value = process(r, (const unsigned char *)&argv[1][2]);
    printf("result=%08x class=%u\n", (unsigned)value, (unsigned)((value >> 30) & 3u));
    return 0;
}
