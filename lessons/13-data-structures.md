# Lesson 13 — Recovering data structures

## Mission

Infer useful structure from repeated memory-access patterns.

## Start from accesses

Suppose code repeatedly accesses:

```text
base + 0
base + 4
base + 8
base + 16
```

Do not immediately invent a struct definition. Record:

- access width;
- read/write direction;
- nearby operations;
- values passed to/from calls;
- repeated use across functions.

## Arrays versus structures

Look for patterns:

- fixed offsets from one base suggest fields;
- scaled indexes often suggest arrays;
- pointer chasing may suggest linked structures;
- repeated stride may reveal element size.

These are heuristics, not proofs.

## Strings and buffers

Distinguish:

- pointer to string;
- inline character array;
- length-prefixed data;
- fixed-size buffer;
- arbitrary byte region.

Library calls can provide clues, but imported function names do not remove the need to inspect arguments.

## Lab

Use the supplied `structure-lab`.

Without reading its source:

1. identify the repeated record stride;
2. infer likely field offsets and widths;
3. determine which field is used for selection;
4. determine which field is accumulated;
5. propose a C-like structure;
6. compare with the source only after documenting the evidence.

## Principle

**Recover layouts from access patterns before assigning semantic names.**
