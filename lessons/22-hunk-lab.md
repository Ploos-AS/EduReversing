# Lesson 22 — Build and reverse a minimal Hunk file

## Mission

Generate, parse and independently verify a tiny course-owned 68000 executable container.

No Kickstart ROM, AmigaOS component or proprietary program is required.

## Generate

```sh
make hunk-lab
```

This creates:

```text
build/minimal.hunk
```

The binary is generated from repository source and is intentionally not tracked.

## First look

Before using the supplied parser:

```sh
sha256sum build/minimal.hunk
file build/minimal.hunk
xxd -g 4 build/minimal.hunk
```

Do not assume `file` will identify every historical format.

## Parse

```sh
python3 tools/hunk_info.py build/minimal.hunk
```

Expected structural sequence:

```text
HUNK_HEADER
HUNK_CODE
HUNK_END
```

The parser is intentionally small enough to audit.

## Manual verification

Use the hex dump to locate:

- big-endian Hunk identifiers;
- header table values;
- code size in longwords;
- four code bytes;
- end marker.

The code bytes represent two 68000 instructions. Decode them independently using your 68k reference material.

Questions:

1. Why is byte order important when reading the container?
2. Why is code size represented differently from a byte count?
3. Which bytes are format metadata and which are CPU instructions?
4. What would go wrong if you disassembled the whole file as raw 68000 code?

## Source reveal

Only after your analysis, inspect `tools/make_hunk_fixture.py`.

Compare the generator's intent with your evidence-based reconstruction.

## Extend the parser

As an exercise, add recognition for another *documented Hunk record type* using a newly generated benign fixture. Keep parsing bounds-checked and reject truncated input.

## Principle

**A tiny format parser is often more valuable than blindly disassembling bytes.**
