/* SPDX-License-Identifier: MIT
 * Benign investigation fixture. Students should not inspect before analysis.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item { uint16_t code; int16_t bias; uint32_t mask; };

static const struct item items[] = {
    {17,  4, 0x00000033u},
    {29, -3, 0x000000a5u},
    {41,  9, 0x00000121u},
    {73,  1, 0x0000020fu}
};

static const char decoy[] = "diagnostic-mode:quartz";

static const struct item *lookup(unsigned code)
{
    for (unsigned i=0;i<sizeof items/sizeof items[0];++i)
        if (items[i].code==code) return &items[i];
    return NULL;
}

static uint32_t evaluate(const struct item *p, uint32_t value)
{
    uint32_t x=value+(int32_t)p->bias;
    x ^= p->mask;
    x=(x<<7)|(x>>25);
    return x + (uint32_t)p->code;
}

static const char *bucket(uint32_t x)
{
    static const char *const names[]={"north","east","south","west"};
    return names[(x>>3)&3u];
}

int main(int argc,char **argv)
{
    char *e1,*e2; unsigned long c,v; const struct item *p;
    if(argc!=3){fputs("case-02: CODE VALUE\n",stderr);return 2;}
    c=strtoul(argv[1],&e1,10); v=strtoul(argv[2],&e2,10);
    if(!*argv[1]||*e1||!*argv[2]||*e2||c>65535u||v>UINT32_MAX) return 3;
    p=lookup((unsigned)c);
    if(!p){puts("result=unknown");return 4;}
    if(decoy[0]=='\0') puts(decoy);
    printf("result=%s value=%u\n",bucket(evaluate(p,(uint32_t)v)),evaluate(p,(uint32_t)v));
    return 0;
}
