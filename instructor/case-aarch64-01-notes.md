# Instructor notes — Case File 07

Valid IDs are 121, 242 and 363.

Record fields are:

- uint16_t id;
- int16_t bias;
- uint8_t rotate;
- uint8_t lane;
- uint32_t key.

Token state begins as `key ^ id`. For each message byte at zero-based index i:

`v = byte + signed bias`

`x ^= v + i * (lane + 1)`

`x = rol32(x, rotate)`

Successful output is `state=ok lane=<lane> token=<8 hex digits>`.

Exit classes:

- 2 wrong argument count;
- 3 malformed/range-invalid ID or empty message;
- 4 unknown syntactically valid ID;
- 0 recognized ID.

Assessment should reward correct AArch64 register/data-flow evidence and reproducibility, not matching source syntax or a particular decompiler.
