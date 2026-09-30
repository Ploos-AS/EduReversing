/* SPDX-License-Identifier: MIT
 * Benign static-analysis fixture for EduReversing.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const unsigned char weights[] = { 3, 1, 4, 1, 5, 9, 2, 6 };

static int parse_decimal(const char *s, unsigned *out)
{
    unsigned value = 0;

    if (*s == '\0')
        return 0;

    while (*s != '\0') {
        if (!isdigit((unsigned char)*s))
            return 0;
        value = value * 10u + (unsigned)(*s - '0');
        ++s;
    }

    *out = value;
    return 1;
}

static unsigned mix_value(unsigned value)
{
    unsigned acc = 0x5au;

    for (size_t i = 0; i < sizeof weights; ++i) {
        acc ^= (value >> (i & 3u)) + weights[i];
        acc = (acc << 3) | (acc >> (sizeof(acc) * 8u - 3u));
    }

    return acc;
}

static int classify(unsigned value)
{
    unsigned mixed = mix_value(value);
    return (mixed & 0x0fu) == 7u;
}

int main(int argc, char **argv)
{
    unsigned value;

    if (argc != 2) {
        puts("usage: static-lab <decimal>");
        return EXIT_FAILURE;
    }

    if (!parse_decimal(argv[1], &value)) {
        puts("invalid");
        return 2;
    }

    puts(classify(value) ? "class A" : "class B");
    return EXIT_SUCCESS;
}
