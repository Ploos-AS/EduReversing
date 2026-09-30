# Lesson 34 — One program, three instruction sets

## Mission

Reverse the same program compiled for x86-64, AArch64 and m68k. The source is identical; the machine evidence is not.

Build:

- `build/cross-isa-x86_64`
- `build/cross-isa-aarch64`
- `build/cross-isa-m68k`

Do not inspect `fixtures/src/cross-isa-lab.c` until the comparison report is complete.

## Questions

For each binary, establish:

- ELF class, byte order and machine;
- how arguments reach the core calculation;
- where the return value appears;
- how the structure address is formed;
- how the signed 16-bit field is loaded and extended;
- how the 32-bit key is represented in file/memory;
- how the rotate is implemented;
- which instructions are compiler/ABI scaffolding rather than algorithm.

## Compare, do not translate mechanically

Build a semantic table with rows such as:

- load key;
- XOR input/key;
- load signed bias;
- add bias;
- load lane;
- multiply/scale lane;
- XOR;
- rotate;
- return.

For every cell cite the actual instruction sequence. Equivalent semantics may have very different shapes.

## Endianness

x86-64 and AArch64 Linux fixtures here are little-endian; the m68k fixture is big-endian. Compare the raw bytes of the known 32-bit key with the value recovered by instructions.

## ABI comparison

Record observed argument and return paths. Contrast SysV AMD64, AArch64 PCS and Linux/m68k based on the generated binaries. Avoid importing AmigaOS or Windows conventions into the Linux targets.

## Dynamic cross-check

Predict one input's result from each static reconstruction. Then execute the native x86-64 build and both foreign builds under QEMU. All three must produce the same result for the same valid input.

The lesson is complete when the report demonstrates semantic equivalence without depending on source syntax or decompiler similarity.
