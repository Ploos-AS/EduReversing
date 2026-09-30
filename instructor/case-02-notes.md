# Instructor notes — Case file 02

## Intended findings

Arguments are decimal CODE and VALUE.

Known codes are 17, 29, 41 and 73. Other valid numeric codes reach `result=unknown` and exit 4.

The repeated record layout is semantically:

```c
uint16_t code;
int16_t bias;
uint32_t mask;
```

Students may express padding/layout observations separately from semantic fields.

Evaluation:

1. VALUE plus signed bias;
2. XOR record mask;
3. rotate left seven;
4. add code.

The class is selected from north/east/south/west using bits 3–4 of the evaluated value.

The string `diagnostic-mode:quartz` is a decoy. It is retained in the binary but the normal program logic cannot print it because its condition tests the first byte of a non-empty constant string.

## Assessment emphasis

Reward proof of:

- signed bias;
- record stride and offsets;
- lookup semantics;
- decoy reachability;
- output table indexing.

Do not require recovery of original variable/function names.
