/* SPDX-License-Identifier: MIT */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct profile { uint16_t id; int16_t bias; uint8_t rot,lane; uint16_t seed; uint32_t key; };
static const struct profile p[]={{41,4,5,1,0x1041,0x13579bdf},{73,-3,9,2,0x2073,0x2468ace0},{109,7,13,0,0x3109,0x0f1e2d3c}};
static const uint8_t cfg[]={0x29,0x3f,0x28,0x2c,0x3f,0x28,0x67,0x3e,0x3f,0x37,0x35,0x74,0x33,0x34,0x2c,0x3b,0x36,0x33,0x3e,0x61,0x37,0x35,0x3e,0x3f,0x67,0x28,0x3f,0x2a,0x35,0x28,0x2e,0x61};
static const char decoy[]="sandbox debugger autorun";
static uint32_t rol(uint32_t x,unsigned n){return(x<<n)|(x>>(32-n));}
static const struct profile* find(unsigned id){size_t i;for(i=0;i<sizeof p/sizeof p[0];i++)if(p[i].id==id)return&p[i];return NULL;}
static uint32_t calc(const struct profile*q,const unsigned char*s){uint32_t x=q->key^((uint32_t)q->seed<<8);unsigned i=1;while(*s){x^=(uint32_t)(*s+++(int32_t)q->bias)+i*(0x1021u+q->lane);x=rol(x,q->rot);i++;}return x^q->id;}
int main(int ac,char**av){char*e;unsigned long id;const struct profile*q;uint32_t x;if(ac!=3)return 2;id=strtoul(av[1],&e,10);if(!*av[1]||*e||id>65535||strlen(av[2])<2)return 3;q=find((unsigned)id);if(!q){puts("state=unknown");return 4;}x=calc(q,(unsigned char*)av[2]);if(decoy[0]==0)puts(decoy);printf("state=ok lane=%u ticket=%08lx cfg=%zu\n",q->lane,(unsigned long)x,sizeof cfg);return 0;}
