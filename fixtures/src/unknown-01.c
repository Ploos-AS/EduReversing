/* SPDX-License-Identifier: MIT
 * Benign EduReversing teaching fixture.
 */
#include <stdio.h>
#include <string.h>

static unsigned checksum(const char *s)
{
    unsigned value = 0x31u;
    while (*s != '\0') {
        value = (value * 33u) ^ (unsigned char)*s++;
    }
    return value;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        puts("usage: unknown-01 <word>");
        return 2;
    }

    if (strcmp(argv[1], "reversing") == 0) {
        printf("accepted:%08x\n", checksum(argv[1]));
        return 0;
    }

    printf("rejected:%08x\n", checksum(argv[1]));
    return 1;
}
