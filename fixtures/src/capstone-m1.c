/* SPDX-License-Identifier: MIT
 * Benign EduReversing M1 PE capstone fixture.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct channel {
    uint16_t code;
    int16_t delta;
    uint8_t rotate;
    uint8_t class_bias;
    uint16_t seed;
    uint32_t mask;
};

static const struct channel channels[] = {
    {113,  5,  3, 1, 0x1101, 0x13579bdfu},
    {227, -7,  7, 2, 0x2202, 0x2468ace0u},
    {331, 11, 11, 0, 0x3303, 0x0f1e2d3cu},
    {449,  3, 17, 3, 0x4404, 0xa5a55a5au}
};

static const volatile char inert_marker[] = "capstone-marker:documentation-only";

static uint32_t rol32(uint32_t x, unsigned n)
{
    return (x << n) | (x >> (32u - n));
}

static const struct channel *select_channel(unsigned code)
{
    size_t i;
    for (i = 0; i < sizeof channels / sizeof channels[0]; ++i)
        if (channels[i].code == code)
            return &channels[i];
    return NULL;
}

static uint32_t calculate(const struct channel *c, const unsigned char *p)
{
    uint32_t x = c->mask ^ ((uint32_t)c->seed << 8);
    unsigned i = 1;
    while (*p) {
        uint32_t v = (uint32_t)*p++ + (int32_t)c->delta;
        x += v ^ (i * 0x45d9f3bu);
        x = rol32(x, c->rotate);
        ++i;
    }
    return x ^ ((uint32_t)c->code * 0x1021u);
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long code;
    const struct channel *c;
    uint32_t ticket;
    unsigned cls;

    if (argc != 3) {
        fputs("capstone-m1: CODE MESSAGE\n", stderr);
        return 2;
    }

    code = strtoul(argv[1], &end, 10);
    if (!*argv[1] || *end || code > 65535u || strlen(argv[2]) < 2u)
        return 3;

    c = select_channel((unsigned)code);
    if (!c) {
        puts("state=unmapped");
        return 4;
    }

    ticket = calculate(c, (const unsigned char *)argv[2]);
    cls = ((ticket >> 29) + c->class_bias) & 7u;

    if (inert_marker[0] == '\0')
        puts((const char *)inert_marker);

    printf("state=ok class=%u ticket=%08x\n", cls, (unsigned)ticket);
    return 0;
}
