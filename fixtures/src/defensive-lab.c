/* SPDX-License-Identifier: MIT
 * Inert defensive-analysis teaching fixture.
 * It performs no networking, persistence, payload execution or host modification.
 */
#include <stdio.h>
#include <stddef.h>

static const volatile char documentation_domain[] = "telemetry.example.com";
static const volatile char documentation_ip[] = "192.0.2.42";
static const volatile char persistence_description[] = "example:auto-start-entry";
static const volatile char analysis_note[] = "sandbox-check:documentation-only";

/* Encoded benign text: version=1;mode=training */
static const unsigned char encoded_config[] = {
    0x2c,0x3f,0x28,0x29,0x33,0x35,0x34,0x67,0x6b,0x61,0x37,0x35,
    0x3e,0x3f,0x67,0x2e,0x28,0x3b,0x33,0x34,0x33,0x34,0x3d
};

static void decode_config(char *out, size_t out_size)
{
    size_t n = sizeof encoded_config;
    if (out_size == 0)
        return;
    if (n >= out_size)
        n = out_size - 1;

    for (size_t i = 0; i < n; ++i)
        out[i] = (char)(encoded_config[i] ^ 0x5a);

    out[n] = '\0';
}

int main(void)
{
    char config[64];

    decode_config(config, sizeof config);

    puts("EduReversing defensive-analysis fixture");
    printf("config:%s\n", config);

    /* Keep documentation indicators present and referenced, but inert. */
    if (documentation_domain[0] == '\0' || documentation_ip[0] == '\0' ||
        persistence_description[0] == '\0' || analysis_note[0] == '\0')
        return 1;

    return 0;
}
