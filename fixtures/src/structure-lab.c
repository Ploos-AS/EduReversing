/* SPDX-License-Identifier: MIT */
#include <stdio.h>

struct record {
    unsigned id;
    int score;
    unsigned flags;
    const char *label;
};

static const struct record records[] = {
    { 10,  7, 1, "alpha" },
    { 20, 13, 0, "beta" },
    { 30, -2, 1, "gamma" },
    { 40, 21, 1, "delta" }
};

int main(void)
{
    int total = 0;

    for (unsigned i = 0; i < sizeof records / sizeof records[0]; ++i) {
        if ((records[i].flags & 1u) != 0u) {
            total += records[i].score;
            puts(records[i].label);
        }
    }

    printf("total=%d\n", total);
    return 0;
}
