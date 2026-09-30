# Lesson 14 — Differential analysis

## Mission

Use controlled differences to reduce the search space.

## Build two benign versions

```sh
make differential-lab
```

The two programs are intentionally related but not identical.

First establish behavior:

```sh
./build/diff-v1 7
./build/diff-v2 7
```

Then compare metadata and disassembly.

Useful tools include:

```sh
sha256sum build/diff-v1 build/diff-v2
size build/diff-v1 build/diff-v2
objdump -d -M intel build/diff-v1 > build/v1.asm
objdump -d -M intel build/diff-v2 > build/v2.asm
diff -u build/v1.asm build/v2.asm
```

Raw address differences can create noise. Your job is to identify semantic differences.

## Questions

Determine:

- which behavior changed;
- which constants changed;
- whether control flow changed;
- which functions are likely unchanged;
- which evidence is merely a consequence of layout/address movement.

## Benign patch analysis

A binary patch is simply a difference between byte sequences. In this course, patch analysis is used to understand benign version changes, bug fixes and compiler output.

Do not use this lab to bypass licensing, authentication, access controls or security protections.

## Source reveal

After completing the binary comparison, inspect:

```text
fixtures/src/diff-v1.c
fixtures/src/diff-v2.c
```

Compare your inferred change set with the actual source changes.

## Principle

**A controlled comparison turns “what does this binary do?” into the smaller question “what changed?”**
