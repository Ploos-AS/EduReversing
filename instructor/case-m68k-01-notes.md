# Instructor notes — Case File 08

Valid codes: 68, 99, 120.

Profile layout:

- uint16_t code
- int16_t delta
- uint8_t rotate
- uint8_t class_bias
- uint16_t seed
- uint32_t key

The target is Linux/m68k ELF and therefore provides a useful big-endian data-layout exercise.

Digest:

1. x = key ^ (seed << 8)
2. index begins at 1
3. v = byte + signed delta
4. x += v ^ (index * 0x1021)
5. rotate x left by profile.rotate
6. after the message, x ^= code
7. class = ((x >> 30) + class_bias) & 3

Exit classes are 2 for wrong argc, 3 for malformed/range-invalid input or empty message, 4 for unknown code, and 0 for success.

Assessment should require machine evidence for structure fields, endian interpretation and call/data flow. Matching source-level syntax is unnecessary.
