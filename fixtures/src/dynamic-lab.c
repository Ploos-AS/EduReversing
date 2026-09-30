/* SPDX-License-Identifier: MIT
 * Benign dynamic-analysis fixture for EduReversing.
 */
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static volatile unsigned observations;

static unsigned process_value(unsigned value)
{
    unsigned x = value ^ 0x5au;
    observations++;

    if ((x & 1u) != 0u)
        x = x * 3u + 1u;
    else
        x >>= 1;

    observations += x & 3u;
    return x;
}

int main(int argc, char **argv)
{
    char *end;
    unsigned long raw;
    unsigned result;

    if (argc != 2) {
        fprintf(stderr, "usage: dynamic-lab <unsigned>\n");
        return 2;
    }

    errno = 0;
    raw = strtoul(argv[1], &end, 10);
    if (errno != 0 || *end != '\0' || raw > UINT_MAX) {
        puts("invalid");
        return 3;
    }

    result = process_value((unsigned)raw);
    printf("result=%u observations=%u\n", result, observations);
    return 0;
}
