# Lesson 21 — Amiga Hunk format

## Mission

Learn to treat an Amiga executable as structured evidence before interpreting its 68k instructions.

## Why Hunk matters

Classic Amiga binaries are not ELF or PE. Their container structure affects:

- where code and data live;
- how relocation works;
- what symbols may be available;
- how an analyst maps file content to loaded memory.

## Analyst's first questions

Before disassembly, determine:

1. which Hunk records are present?
2. which contain code?
3. which contain initialized data?
4. which represent uninitialized storage?
5. which relocation information exists?
6. are symbols/debug records present?
7. how do references change after loading?

## Code versus container

Do not feed an entire structured executable to a raw 68k disassembler and assume every byte is an instruction.

Separate format parsing from instruction decoding.

## Relocations

A stored value can be incomplete until the loader relocates it. Record:

- relocation source;
- relocation target;
- width/type as represented by the format;
- resulting relationship after load.

This is the classic-binary equivalent of the broader rule: file address is not automatically runtime address.

## System interaction

Once code is identified, Amiga-specific analysis may involve library/device calls and OS structures. Keep these as a separate semantic layer:

```text
Hunk structure
    -> relocated code/data
    -> 68k instructions
    -> ABI / Amiga system semantics
```

## Legal and repository boundary

The course does not distribute Kickstart ROMs, AmigaOS files or proprietary application binaries. Hunk exercises must use original course-generated or otherwise redistributable fixtures.

## Future lab

The Hunk specialist track will use a tiny course-owned 68k/Hunk fixture generated from source so both parser-level and instruction-level conclusions can be checked reproducibly.

## Principle

**Parse the executable format before trusting the disassembly.**
