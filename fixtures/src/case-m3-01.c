/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t cfg[] = {
  0x29,0x3f,0x28,0x2c,0x3f,0x28,0x67,0x3e,0x3f,0x37,0x35,0x74,0x33,0x34,0x2c,0x3b,0x36,0x33,0x3e,
  0x61,0x37,0x35,0x3e,0x3f,0x67,0x28,0x3f,0x2a,0x35,0x28,0x2e,0x61
};
static const char decoy[] = "debug sandbox trace persistence";
static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u-n)); }

static uint32_t digest(const unsigned char *p)
{
    uint32_t x=0x6d330001u; unsigned i=1;
    while (*p) { x ^= (uint32_t)*p++ + i*0x1021u; x=rol32(x,5); ++i; }
    return x;
}
static void decode(char *out)
{
    size_t i; for(i=0;i<sizeof cfg;i++) out[i]=(char)(cfg[i]^0x5a); out[sizeof cfg]=0;
}
int main(int argc,char **argv)
{
    char out[sizeof cfg+1]; uint32_t d;
    if(argc!=2) return 2;
    if(strlen(argv[1])<3) return 3;
    decode(out); d=digest((const unsigned char*)argv[1]);
    if (decoy[0] == '\0') puts(decoy);
    printf("state=report token=%08lx config=%zu\n",(unsigned long)d,strlen(out));
    return 0;
}
