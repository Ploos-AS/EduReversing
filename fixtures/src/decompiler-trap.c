/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int32_t classify(uint32_t x)
{
    int32_t signed_view = (int32_t)(x ^ 0x80000000u);
    if (signed_view < -1000000) return -2;
    if ((x & 0xffu) == 0x7fu) return 3;
    return (int32_t)((x >> 29) & 7u);
}

static uint32_t select_value(const uint32_t *p, unsigned index)
{
    return p[index & 3u];
}

int main(int argc, char **argv)
{
    static const uint32_t table[4] = {
        0x7fffffff, 0x80000000u, 0x0102037fu, 0xf0000001u
    };
    char *end;
    unsigned long index;
    uint32_t value;
    if (argc != 2) return 2;
    index = strtoul(argv[1], &end, 0);
    if (!*argv[1] || *end) return 3;
    value = select_value(table, (unsigned)index);
    printf("value=%08lx class=%ld\n",
           (unsigned long)value, (long)classify(value));
    return 0;
}
