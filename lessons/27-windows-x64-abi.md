# Lesson 27 — Windows x64 ABI for reverse engineers

## Mission

Recognize function boundaries and arguments in Windows x86-64 code without accidentally applying the System V AMD64 rules learned from Linux ELF binaries.

## Core model

For ordinary integer and pointer arguments, Windows x64 uses:

1. RCX
2. RDX
3. R8
4. R9

The return value is normally in RAX. Additional arguments are passed on the stack.

The caller reserves 32 bytes of shadow space for the callee. Stack alignment and nonvolatile-register rules are part of the ABI and can provide useful reversing evidence.

## Contrast with System V AMD64

Do not transfer the Linux sequence RDI, RSI, RDX, RCX, R8, R9 to Windows binaries. When switching between the ELF and PE fixtures, explicitly identify which ABI applies before naming arguments.

## Practical analysis

Inspect `build/pe-lab.exe` around calls and function prologues. Look for:

- values prepared in RCX/RDX/R8/R9;
- stack adjustment before calls;
- preserved nonvolatile registers;
- return values consumed from RAX/EAX;
- compiler-generated wrappers around C runtime functions.

Optimization may remove textbook-looking frames. Treat prologue patterns as clues, not definitions.

## Exercise

Find one call with at least two meaningful arguments. Document the register state immediately before the call and reconstruct a plausible C-like call expression.

Then inspect an equivalent Linux fixture and document the ABI difference.

## Deliverable

Create a two-column Windows x64 versus System V AMD64 calling-convention note based on evidence from actual course binaries.
