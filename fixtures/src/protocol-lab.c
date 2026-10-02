/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint16_t be16(const unsigned char *p)
{
    return (uint16_t)((uint16_t)p[0] << 8) | p[1];
}

static uint16_t checksum(const unsigned char *p, size_t n)
{
    uint32_t s = 0x1234u;
    size_t i;
    for (i = 0; i < n; ++i)
        s = ((s << 5) | (s >> 11)) ^ p[i];
    return (uint16_t)s;
}

static int hexbyte(char a, char b, unsigned char *out)
{
    unsigned v = 0;
    char c[2] = {a, b};
    unsigned i;
    for (i = 0; i < 2; ++i) {
        v <<= 4;
        if (c[i] >= '0' && c[i] <= '9') v |= (unsigned)(c[i] - '0');
        else if (c[i] >= 'a' && c[i] <= 'f') v |= (unsigned)(c[i] - 'a' + 10);
        else if (c[i] >= 'A' && c[i] <= 'F') v |= (unsigned)(c[i] - 'A' + 10);
        else return 0;
    }
    *out = (unsigned char)v;
    return 1;
}

int main(int argc, char **argv)
{
    unsigned char b[64];
    size_t hexlen, n, i, payload_len;
    uint16_t seq, got, want;
    if (argc != 2) return 2;
    for (hexlen = 0; argv[1][hexlen]; ++hexlen) {}
    if ((hexlen & 1u) || hexlen < 16u || hexlen > sizeof b * 2u) return 3;
    n = hexlen / 2u;
    for (i = 0; i < n; ++i)
        if (!hexbyte(argv[1][i * 2u], argv[1][i * 2u + 1u], &b[i])) return 3;

    if (b[0] != 0x45 || b[1] != 0x52) return 4;
    if (b[2] != 1u) return 5;
    payload_len = b[3];
    if (payload_len + 7u != n) return 6;
    seq = be16(&b[4]);
    got = be16(&b[n - 2u]);
    want = checksum(b, n - 2u);
    if (got != want) return 7;

    printf("type=%u seq=%u payload=%zu checksum=ok\n",
           (unsigned)b[2], (unsigned)seq, payload_len);
    return 0;
}
