# Instructor notes — Case file 01

Do not give this file to students before they complete the case.

## Intended reconstruction

The program accepts exactly one decimal integer in the unsigned 32-bit range.

Invalid invocation exits with status 2 or 3 depending on the failure.

The value is transformed through a six-element byte table. Each round:

1. combines the input and table value;
2. multiplies by a round-dependent value;
3. XORs the accumulator;
4. rotates the accumulator left by five bits.

Classification uses the low byte of the transformed value:

- below 64 -> `amber`;
- below 160 -> `blue`;
- otherwise -> `violet`.

## Teaching points

A successful report should distinguish:

- parsing behavior from classification behavior;
- table data from code;
- observed output from inferred complete output space;
- a reconstructed rotate operation from source syntax;
- evidence from decompiler convenience.

Students do not need to recreate the exact original C syntax.

## Source reveal

After assessment, compare the report with `fixtures/src/case-01.c`. Discuss which source-level details were impossible or unnecessary to recover exactly.
