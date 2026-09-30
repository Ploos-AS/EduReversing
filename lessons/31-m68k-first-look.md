# Lesson 31 — m68k first look

## Mission

Analyze a Linux/m68k ELF fixture and learn to read 68k-family evidence without confusing it with Amiga Hunk or AmigaOS conventions.

## Register model

The classic model separates data registers D0–D7 from address registers A0–A7. A7 is the stack pointer. Addressing modes are central to reading 68k code: register direct, indirect, displacement, indexed, immediate and PC-relative forms can encode much of the data-flow story.

m68k is big-endian. Verify byte order from the ELF header and from a known multi-byte constant in the generated fixture.

## Practical evidence

Build `build/m68k-lab` and inspect it with `m68k-linux-gnu-objdump`, `readelf` and radare2.

Recover:

- input validation;
- the 32-bit XOR constant;
- rotate operation;
- final addition;
- output path.

Document stack accesses and call sites from observed code. Do not import assumptions from Windows x64, SysV AMD64 or AmigaOS merely because all are familiar environments.

## Cross-architecture question

Write the transformation as architecture-neutral pseudocode, then cite the machine instructions that support each operation. This separates semantic recovery from instruction-set familiarity.
