/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t mix(uint32_t x, uint32_t key)
{
    x ^= key;
    x = (x << 5) | (x >> 27);
    return x + 0x68000u;
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long x;
    if (argc != 2) return 2;
    x = strtoul(argv[1], &end, 0);
    if (!*argv[1] || *end || x > 0xffffffffUL) return 3;
    printf("result=%08lx\n", (unsigned long)mix((uint32_t)x, 0x4d36386bu));
    return 0;
}
