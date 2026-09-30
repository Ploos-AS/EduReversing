/* SPDX-License-Identifier: MIT
 * Benign investigation fixture. Students should not read this before analysis.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const uint8_t table[] = {11, 7, 19, 3, 23, 5};

static uint32_t transform(uint32_t x)
{
    uint32_t acc = 0x13579bdu;
    for (unsigned i = 0; i < sizeof table; ++i) {
        acc ^= (x + table[i]) * (i + 3u);
        acc = (acc << 5) | (acc >> 27);
    }
    return acc;
}

static const char *classify(uint32_t x)
{
    uint32_t v = transform(x);
    if ((v & 0xffu) < 64u)
        return "amber";
    if ((v & 0xffu) < 160u)
        return "blue";
    return "violet";
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long n;
    if (argc != 2) {
        fputs("case-01: one decimal argument required\n", stderr);
        return 2;
    }
    n = strtoul(argv[1], &end, 10);
    if (*argv[1] == '\0' || *end != '\0' || n > UINT32_MAX) {
        fputs("case-01: invalid input\n", stderr);
        return 3;
    }
    printf("result=%s\n", classify((uint32_t)n));
    return 0;
}
