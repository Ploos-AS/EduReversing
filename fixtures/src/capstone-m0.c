/* SPDX-License-Identifier: MIT
 * Benign M0 capstone fixture. Do not inspect before completing the case.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rule { uint8_t tag; uint8_t shift; uint16_t add; uint32_t key; };

static const struct rule rules[] = {
    { 'A', 3,  17, 0x13579bdfu },
    { 'B', 5, 101, 0x2468ace0u },
    { 'C', 7, 211, 0x0f1e2d3cu }
};

static const volatile char noise1[] = "update.example.invalid";
static const volatile char noise2[] = "autorun:training-decoy";

static uint32_t rol32(uint32_t x, unsigned n) { return (x << n) | (x >> (32u-n)); }

static const struct rule *find_rule(unsigned char tag)
{
    for (unsigned i=0;i<sizeof rules/sizeof rules[0];++i)
        if (rules[i].tag==tag) return &rules[i];
    return NULL;
}

static uint32_t process(const struct rule *r, const unsigned char *s)
{
    uint32_t x=r->key;
    for (;*s;++s) {
        x ^= (uint32_t)*s + r->add;
        x=rol32(x,r->shift);
    }
    return x;
}

int main(int argc,char **argv)
{
    const struct rule *r; const char *payload; uint32_t v;
    if(argc!=2) return 2;
    if(strlen(argv[1])<3 || argv[1][1]!=':') return 3;
    r=find_rule((unsigned char)argv[1][0]);
    if(!r) return 4;
    payload=argv[1]+2;
    if(*payload=='\0') return 5;
    v=process(r,(const unsigned char*)payload);
    printf("ticket=%08x class=%u\n",v,(unsigned)((v>>29)&7u));
    if(noise1[0]=='\0' || noise2[0]=='\0') puts((const char *)noise1);
    return 0;
}
