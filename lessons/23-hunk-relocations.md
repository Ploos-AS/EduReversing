# Lesson 23 — Hunk relocation, data, BSS and symbols

## Mission

Reconstruct a small multi-hunk program image rather than treating the executable as a flat byte stream.

## Build

```sh
make hunk-reloc-lab
xxd -g 4 build/reloc.hunk
python3 tools/hunk_records.py build/reloc.hunk
```

The generated fixture contains three hunks:

1. CODE;
2. DATA;
3. BSS.

The CODE hunk also carries a 32-bit relocation and a symbol.

## The unresolved value

The instruction bytes contain a placeholder address. The relocation record says that the longword at a particular CODE offset refers to another hunk.

Answer from evidence:

- which hunk contains the relocation site?
- what is its byte offset?
- which hunk is the target?
- why can the file not contain the final runtime address?
- what must a loader know before applying the relocation?

Do not confuse the target hunk number with a runtime address.

## DATA and BSS

Compare the two:

- DATA has initialized bytes stored in the file;
- BSS reserves memory but does not need equivalent initialized payload bytes in the file.

Explain how that distinction affects file size versus loaded memory size.

## Symbol record

Find the course-owned `entry` symbol and its value.

Symbols are useful evidence when present, but a reversing methodology must continue to work when they are stripped.

## Reconstruct a load map

Choose hypothetical, clearly marked load bases for the three hunks. Then calculate what value the relocation would produce.

This is arithmetic on a benign course fixture, not execution.

Document:

| Hunk | File content | Size | Hypothetical base |
|---|---|---:|---:|
| CODE | instructions | | |
| DATA | initialized bytes | | |
| BSS | zero-initialized storage | | |

Then show the relocation calculation.

## Source reveal

After finishing, inspect `tools/make_hunk_reloc_fixture.py` and compare it with your reconstruction.

## Principle

**Relocation connects file structure to a load-time address space.**
