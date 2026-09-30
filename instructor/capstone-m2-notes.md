# Instructor notes — M2 cross-architecture capstone

The three binaries are compiled from one course-owned source.

Valid codes: 137, 251, 389, 503.

Channel layout:

- uint16_t code
- int16_t bias
- uint8_t rotate
- uint8_t lane
- uint16_t seed
- uint32_t key

Ticket algorithm:

1. x = key ^ (seed << 8)
2. index begins at 1
3. v = byte + signed bias
4. x ^= v + index * (0x1021 + lane)
5. rotate x left by rotate
6. increment index
7. after message, x ^= code << 16
8. class = ((x >> 29) + lane) & 7

Exit classes:

- 2: wrong argc
- 3: malformed/range-invalid code or message shorter than two bytes
- 4: syntactically valid but unmapped code, printing `state=unmapped`
- 0: success

Assessment should prioritize reproducible semantic recovery across all three targets, ABI evidence, correct signed-field handling and endian-aware structure reconstruction.
