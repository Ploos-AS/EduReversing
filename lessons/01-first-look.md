# Lesson 01 — First look at an unknown binary

## Mission

You have received an unknown ELF executable. Do not begin by guessing what the source looked like. Build an evidence-based description of what the binary is and what it does.

This first lab is deliberately benign. The point is to establish a repeatable analysis workflow.

## Learning objectives

After this lesson you should be able to:

- identify a file before executing it;
- calculate and record a cryptographic hash;
- inspect printable strings and ELF metadata;
- distinguish observations from hypotheses;
- use disassembly to find important control flow;
- validate a static-analysis hypothesis with a debugger;
- write a short reproducible analysis note.

## Build the fixture

From the repository root:

```sh
make fixtures
```

The student-facing binary is written to `build/unknown-01`. The source in `fixtures/src/` exists so the course remains auditable, but **do not read it until you have completed the exercise**.

## Step 1 — Establish identity

Record the output of:

```sh
file build/unknown-01
sha256sum build/unknown-01
readelf -h build/unknown-01
```

Questions:

1. Which architecture does the binary target?
2. Is it 32-bit or 64-bit?
3. What byte order does it use?
4. Is it dynamically linked?
5. What is its entry point?

## Step 2 — Cheap static evidence

Without running the program:

```sh
strings -a build/unknown-01
readelf -S build/unknown-01
readelf -l build/unknown-01
readelf -d build/unknown-01
objdump -d -M intel build/unknown-01
```

Create two columns in your notes: **observation** and **hypothesis**. Never put an assumption in the observation column.

Questions:

1. Which strings appear relevant to program behavior?
2. Which imported library functions are visible?
3. Can you identify conditional branches?
4. What input does the program appear to expect?
5. What output paths can you infer?

## Step 3 — Controlled execution

Only after static inspection, execute the known-safe course fixture:

```sh
./build/unknown-01
./build/unknown-01 hello
./build/unknown-01 reversing
```

Compare the observed behavior with your hypotheses.

## Step 4 — Debug

Start GDB:

```sh
gdb ./build/unknown-01
```

Useful first commands:

```text
set disassembly-flavor intel
starti
info files
info registers
disassemble
```

Locate the code responsible for the main decision in the program. Record the comparison and the branch that selects the result.

## Deliverable

Write `analysis/unknown-01.md` containing:

- SHA-256 of the analyzed binary;
- architecture and format;
- relevant strings/imports;
- a short control-flow description;
- observed inputs and outputs;
- your reconstructed pseudocode;
- commands needed to reproduce the analysis;
- what you got wrong in your initial hypotheses.

Then inspect `fixtures/src/unknown-01.c` and compare your reconstruction with the source.

## Rule for the rest of the course

**Evidence first, execution second.**

Real reverse engineering rarely gives you source code at the end. This fixture does because the first exercise is about learning how to measure the quality of your own analysis.
