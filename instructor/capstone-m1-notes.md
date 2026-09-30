# Instructor notes — M1 PE capstone

## Input and exits

Invocation is `CODE MESSAGE`.

- exit 2: wrong argument count;
- exit 3: invalid/out-of-range CODE or MESSAGE shorter than two bytes;
- exit 4: syntactically valid but unknown CODE; prints `state=unmapped`;
- exit 0: recognized channel.

Valid codes: 113, 227, 331, 449.

## Repeated structure

Source layout:

- uint16_t code;
- int16_t delta;
- uint8_t rotate;
- uint8_t class_bias;
- uint16_t seed;
- uint32_t mask.

Students should recover this from binary access patterns and stride rather than requiring exact C declarations.

## Calculation

Initial state:

`x = mask ^ (seed << 8)`

For MESSAGE bytes, with index starting at 1:

`v = byte + signed delta`

`x += v ^ (i * 0x45d9f3b)`

`x = rol32(x, rotate)`

After the loop:

`x ^= code * 0x1021`

Class:

`((ticket >> 29) + class_bias) & 7`

Output:

`state=ok class=<0..7> ticket=<8 hex digits>`

## Deliberate evidence noise

ASCII inert marker:

`capstone-marker:documentation-only`

Its normal print condition is unreachable.

PE resources include:

- `EduReversing M1 Capstone`;
- `Course-owned benign Windows fixture`;
- `sync.example.invalid`.

The reserved/example domain is not evidence of networking. The normal program does not consume the resource strings.

## Assessment

A strong report:

- distinguishes PE metadata, runtime/compiler scaffolding and application logic;
- reconstructs the record layout and signed delta correctly;
- applies Windows x64 rather than System V register conventions;
- supports behavior claims with code/data evidence;
- does not infer network behavior from the resource decoy;
- documents uncertainty and reproducible observations.

Exact decompiler pseudocode is not required.
