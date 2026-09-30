# Lesson 11 — Decompiler pitfalls

## Mission

Learn where plausible pseudocode can mislead you.

## Common losses

Machine code usually does not preserve original:

- variable names;
- comments;
- typedef names;
- loop syntax;
- macro boundaries;
- inline function boundaries;
- exact signedness intent;
- source-file organization.

Debug information changes this dramatically, which is why stripped and unstripped builds must not be treated as equivalent reversing problems.

## Type recovery

A decompiler infers types from use.

Check suspicious inferred types against:

- instruction width;
- sign/zero extension;
- comparison kind;
- pointer arithmetic;
- ABI argument/return rules;
- memory access width.

## Loop reconstruction

Several machine-code CFGs can represent the same high-level loop.

A decompiler may render code as `while`, `do/while`, `for`, or even `goto` while preserving equivalent behavior.

Do not grade reconstructed source by cosmetic similarity.

## Boolean expressions

Compiler transformations can merge, invert or reorder conditions.

For a reconstructed condition:

1. identify the comparison instructions;
2. identify branch conditions;
3. map true/false edges;
4. check signedness;
5. then simplify the boolean expression.

## Undefined behavior warning

Some C source permits compiler assumptions that surprise readers. When investigating an optimized binary, do not assume every intuitive source-level execution was required to survive compilation.

This course does not use undefined behavior as a trick in graded beginner labs, but analysts must know the issue exists.

## Differential method

When a decompiler claim is uncertain:

1. form a hypothesis;
2. inspect assembly;
3. compare another optimization level;
4. if appropriate, alter a benign source fixture;
5. rebuild;
6. compare the resulting code.

This controlled experiment is compiler archaeology.

## Lab

Open the `archaeology-lab-O2` binary in a decompiler.

Find at least three places where the pseudocode:

- hides a compiler transformation;
- assigns an uncertain type;
- reconstructs control flow differently from the source;
- makes code look simpler than the underlying machine behavior.

For each, include assembly evidence.

## Principle

**Readable pseudocode can be wrong. Ugly assembly can still be the stronger evidence.**
