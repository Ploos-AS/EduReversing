/* SPDX-License-Identifier: MIT
 * Benign compiler-output laboratory for EduReversing.
 */
#include <stddef.h>
#include <stdio.h>

struct sample {
    int bias;
    int scale;
};

static int transform(int value, const struct sample *cfg)
{
    if (value < cfg->bias)
        return cfg->bias - value;

    return (value - cfg->bias) * cfg->scale;
}

static int accumulate(const int *values, size_t count,
                      const struct sample *cfg)
{
    int total = 0;

    for (size_t i = 0; i < count; ++i)
        total += transform(values[i], cfg);

    return total;
}

int main(void)
{
    static const int values[] = { 3, 8, 13, 21, 34 };
    const struct sample cfg = { 10, 3 };

    printf("%d\n", accumulate(values,
                               sizeof values / sizeof values[0],
                               &cfg));
    return 0;
}
