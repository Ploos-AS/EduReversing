/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct sample {
    uint32_t key;
    int16_t bias;
    uint8_t rotate;
    uint8_t lane;
};

static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u - n)); }

static uint32_t evaluate(uint32_t input, const struct sample *s)
{
    uint32_t x = input ^ s->key;
    x += (int32_t)s->bias;
    x ^= (uint32_t)s->lane * 0x1021u;
    return rol32(x, s->rotate);
}

int main(int argc, char **argv)
{
    static const struct sample s = {0x31415926u, -17, 7, 3};
    char *end;
    unsigned long value;
    if (argc != 2) return 2;
    value = strtoul(argv[1], &end, 0);
    if (!*argv[1] || *end || value > 0xffffffffUL) return 3;
    printf("result=%08lx\n", (unsigned long)evaluate((uint32_t)value, &s));
    return 0;
}
