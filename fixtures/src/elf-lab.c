/* SPDX-License-Identifier: MIT
 * Benign ELF structure laboratory for EduReversing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char banner[] = "EduReversing ELF laboratory";
static int initialized_counter = 7;
static unsigned char workspace[256];

static size_t prepare(const char *input)
{
    size_t n = strlen(input);
    if (n > sizeof workspace - 1)
        n = sizeof workspace - 1;

    memcpy(workspace, input, n);
    workspace[n] = '\0';
    initialized_counter += (int)n;
    return n;
}

int main(int argc, char **argv)
{
    puts(banner);

    if (argc != 2) {
        fputs("usage: elf-lab <text>\n", stderr);
        return EXIT_FAILURE;
    }

    printf("bytes=%zu counter=%d text=%s\n",
           prepare(argv[1]), initialized_counter, workspace);
    return EXIT_SUCCESS;
}
