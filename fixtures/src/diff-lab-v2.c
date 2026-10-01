/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t score(uint32_t x)
{
    x ^= 0x31415926u;
    x += 0x2043u;
    x = (x << 7) | (x >> 25);
    return x ^ 0x00c0ffeeu;
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long v;
    if (argc != 2) return 2;
    v = strtoul(argv[1], &end, 0);
    if (!*argv[1] || *end || v > 0xfffffffful) return 3;
    printf("mode=revised score=%08lx\n", (unsigned long)score((uint32_t)v));
    return 0;
}
