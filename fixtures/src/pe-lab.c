/* SPDX-License-Identifier: MIT
 * Benign PE/COFF fixture for EduReversing.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t rol32(uint32_t x, unsigned n)
{
    return (x << n) | (x >> (32u - n));
}

static uint32_t transform(uint32_t value)
{
    value ^= 0x13579bdfu;
    value += 0x2468u;
    return rol32(value, 5);
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long value;

    if (argc != 2) {
        fputs("pe-lab: decimal-value\n", stderr);
        return 2;
    }

    value = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || value > UINT32_MAX) {
        fputs("pe-lab: invalid input\n", stderr);
        return 3;
    }

    printf("result=%08x\n", (unsigned)transform((uint32_t)value));
    return 0;
}
