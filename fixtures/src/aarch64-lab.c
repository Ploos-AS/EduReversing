/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint64_t rol64(uint64_t x, unsigned n) { return (x << n) | (x >> (64u - n)); }

static uint64_t transform(uint64_t x, uint64_t key)
{
    x ^= key;
    x += 0x12345u;
    return rol64(x, 9);
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long long x;
    if (argc != 2) return 2;
    x = strtoull(argv[1], &end, 0);
    if (!*argv[1] || *end) return 3;
    printf("result=%016llx\n", (unsigned long long)transform((uint64_t)x, 0x1122334455667788ULL));
    return 0;
}
