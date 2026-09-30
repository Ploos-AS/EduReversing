# Lesson 03 — C → assembly → C

## Mission

Learn what familiar C constructs look like after compilation, and discover why decompilation is reconstruction rather than recovery of the original source.

## Learning objectives

You should be able to recognize likely compiler output for:

- arithmetic expressions;
- `if/else`;
- loops;
- function calls;
- arrays and pointer indexing;
- simple structures;
- optimized-away source constructs.

## The experiment

The same benign program is compiled at several optimization levels. You compare the generated machine code without changing the source.

Build it:

```sh
make compiler-lab
```

This produces:

```text
build/compiler-lab-O0
build/compiler-lab-O1
build/compiler-lab-O2
```

Inspect each:

```sh
objdump -d -M intel build/compiler-lab-O0
objdump -d -M intel build/compiler-lab-O1
objdump -d -M intel build/compiler-lab-O2
```

## Exercise A — Find the source constructs

Before reading `fixtures/src/compiler-lab.c`, answer:

1. How many meaningful functions can you identify?
2. Which function appears to contain a loop?
3. Where is a multiplication visible?
4. Can you identify array indexing?
5. Which conditional branches correspond to high-level decisions?
6. Which calls survive at each optimization level?

## Exercise B — Compare optimization levels

For each build record:

- approximate function size;
- stack-frame shape;
- obvious memory traffic;
- loop shape;
- calls that disappeared;
- values that remain in registers.

Do not describe `-O2` as merely “more optimized.” State concrete transformations visible in the binary.

## Exercise C — Reconstruct C

Choose the `-O1` binary and write plausible C for its main computational functions without consulting the source.

Your reconstruction is successful if it expresses equivalent behavior. It does **not** need the original variable names or exact syntax.

Only then compare it with the fixture source.

## Exercise D — Change one thing

Modify one constant in the source, rebuild all three binaries and locate the resulting difference in disassembly.

Repeat with one of:

- change a signed value to unsigned;
- change an array length;
- replace multiplication by a power of two;
- make a helper function `static`;
- remove `-fno-inline` from an experimental build.

Record what changed and what did not.

## Principle

**A binary preserves program behavior, not the author's original source text.**
