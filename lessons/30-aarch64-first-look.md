# Lesson 30 — AArch64 first look

## Mission

Transfer the existing evidence-first workflow to an AArch64 ELF executable.

Build `build/aarch64-lab`, identify the ELF machine type and inspect it with `aarch64-linux-gnu-objdump`, `readelf` and radare2.

## Register model

AArch64 has 31 general-purpose 64-bit registers named X0–X30. Their low 32-bit views are W0–W30. X30 commonly carries the link register value; SP is the stack pointer.

For the standard AArch64 procedure-call convention, begin by testing the hypothesis that integer/pointer arguments arrive in X0–X7 and a scalar return value uses X0. Confirm this at real call sites rather than merely labeling registers from a table.

## Practical evidence

Locate the transform function or its optimized equivalent. Recover:

- its two inputs;
- the XOR;
- constant addition;
- 64-bit rotate;
- return path.

Then compare the same source-level idea with earlier x86-64 code. The goal is not matching mnemonics: it is recovering equivalent semantics from different machine evidence.

## Dynamic check

Where the student OCI provides QEMU user mode, use a controlled invocation such as:

`qemu-aarch64 -L /usr/aarch64-linux-gnu build/aarch64-lab 7`

Record the exact command and output. Dynamic evidence complements, rather than replaces, the static reconstruction.
