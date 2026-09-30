# Case File 09 — M2 cross-architecture capstone

## Scenario

You receive three stripped ELF executables believed to implement the same application logic:

- `build/capstone-m2-x86_64`
- `build/capstone-m2-aarch64`
- `build/capstone-m2-m68k`

The source and instructor notes are sealed.

## Required findings

Establish independently for each binary:

- architecture, ELF class and byte order;
- application logic versus runtime/compiler scaffolding;
- input grammar and all failure classes;
- accepted numeric codes;
- repeated data-record layout, widths and signedness;
- lookup behavior;
- complete ticket transformation;
- output fields and class derivation;
- ABI evidence for at least one meaningful call;
- one architecture-specific compiler/code-generation feature.

Then demonstrate that the three binaries are semantically equivalent despite differing ISA, ABI and endian representation.

## Evidence requirements

Your report must cross-reference machine evidence, data evidence and controlled runtime observations. Decompiled pseudocode is navigation assistance, not proof.

For the m68k binary, explicitly show how big-endian bytes map to at least one multi-byte record field. For AArch64 and x86-64, document the observed argument/return path rather than relying on a memorized ABI table.

## Dynamic boundary

Native execution is permitted for the host x86-64 fixture. Use QEMU user mode for the course-owned AArch64 and m68k fixtures. Do not introduce external or proprietary binaries.

## Stop condition

Another analyst using only your report must be able to predict valid outputs, reproduce every failure class and explain why all three executables implement the same semantics.
