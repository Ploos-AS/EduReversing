/* SPDX-License-Identifier: MIT */
#include <stdint.h>

__declspec(dllexport) uint32_t edu_mix(uint32_t x, uint32_t key)
{
    x ^= key;
    return (x << 9) | (x >> 23);
}

__declspec(dllexport) uint32_t edu_class(uint32_t x)
{
    return (x >> 28) & 0x0fu;
}
