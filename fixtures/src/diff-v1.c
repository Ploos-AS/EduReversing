/* SPDX-License-Identifier: MIT */
#include <stdio.h>
#include <stdlib.h>

static unsigned classify(unsigned x)
{
    if (x < 10)
        return x * 3u + 1u;
    return x + 7u;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 2;
    printf("%u\n", classify((unsigned)strtoul(argv[1], NULL, 10)));
    return 0;
}
