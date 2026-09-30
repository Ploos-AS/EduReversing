# Instructor notes — Case File 04

The student binary is generated from `fixtures/src/case-pe-01.c` with the MinGW-w64 x86-64 cross-compiler and stripped for the case target.

Expected findings:

- PE32+ / x86-64;
- input form `TAG:TEXT`;
- malformed input returns 2;
- unknown tag prints `result=unknown` and returns 4;
- valid tags are R, S and T;
- repeated rule layout contains tag, rotate count, 16-bit add value and 32-bit key;
- processing starts from the selected key, XORs each byte plus add value, then rotates left by the rule-specific count;
- output contains an eight-digit hexadecimal result and a two-bit class from bits 31..30.

Expected ABI evidence should correctly use RCX/RDX/R8/R9 for Windows x64 arguments rather than the System V AMD64 register order.

Assessment should reward evidence quality and reproducibility rather than matching decompiler syntax.
