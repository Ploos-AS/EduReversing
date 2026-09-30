/* SPDX-License-Identifier: MIT
 * Benign compiler-archaeology fixture for EduReversing.
 */
#include <stdio.h>
#include <stdlib.h>

static int small_adjust(int x)
{
    return x * 8 + 3;
}

static int dispatch(unsigned code, int value)
{
    switch (code) {
    case 0: return value + 11;
    case 1: return value - 7;
    case 2: return value * 3;
    case 3: return value ^ 0x55;
    case 4: return value + 101;
    case 5: return value - 42;
    case 6: return value * 5;
    case 7: return value ^ 0xaa;
    default: return -1;
    }
}

static int tail_target(int x)
{
    return x > 20 ? x - 20 : x + 20;
}

static int tail_candidate(int x)
{
    return tail_target(x);
}

static int calculate(unsigned code, int value)
{
    int unused = value * 99;
    (void)unused;

    value = small_adjust(value);
    value = dispatch(code, value);
    return tail_candidate(value);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        puts("usage: archaeology-lab <0-7> <value>");
        return 2;
    }

    unsigned code = (unsigned)strtoul(argv[1], NULL, 10);
    int value = (int)strtol(argv[2], NULL, 10);

    printf("%d\n", calculate(code, value));
    return 0;
}
