# Lesson 33 — m68k addressing, calls and data flow

## Goal

Read 68k-family compiler output as evidence rather than as a list of unfamiliar mnemonics.

## D and A registers

D0–D7 are data registers. A0–A7 are address registers, with A7 serving as SP. Treat these as roles to verify in the current function: compiler allocation can move application values between registers and memory.

## Effective addresses

Practice identifying:

- register direct;
- address-register indirect;
- postincrement and predecrement;
- displacement from an address register;
- indexed forms;
- absolute and PC-relative references;
- immediate values.

An effective address often tells you more about a structure access than the operation mnemonic alone.

## Calls and stack

At call sites, reconstruct which values are placed on the stack or otherwise prepared according to the active ABI. Follow cleanup and return-value use. Do not substitute AmigaOS calling conventions for Linux/m68k evidence.

## Big-endian reconstruction

When bytes in a data region appear to form 16- or 32-bit fields, decode them in big-endian order and cross-check against instructions that consume those fields.

## Lab

Use `build/m68k-lab`. Recover its input path and transformation, then write architecture-neutral pseudocode. Cite machine instructions and data addresses supporting each step.

Finally run the fixture with `qemu-m68k -L /usr/m68k-linux-gnu` and compare runtime output with your static prediction.
