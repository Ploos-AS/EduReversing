# Lesson 10 — Compiler archaeology

## Mission

Recognize the traces left when a compiler transforms source-level ideas into machine code.

## Learning objectives

You should be able to identify or investigate:

- inlining;
- constant folding and propagation;
- dead-code elimination;
- strength reduction;
- loop transformations;
- switch lowering and jump tables;
- tail calls;
- branchless selections;
- register allocation effects.

## Build the specimens

```sh
make archaeology-lab
```

The same source is built at `-O0`, `-O1` and `-O2`.

Compare functions rather than merely comparing file sizes.

## 1. Disappearing functions

A source function may cease to exist as an independent machine-code function after inlining.

Ask:

- can you still find a call?
- can you find the computation inside its caller?
- did the compiler specialize it using known constants?

Absence of a function symbol does not imply absence of its behavior.

## 2. Arithmetic that changes shape

Source expressions can be replaced with equivalent operations.

Look for multiplication/division by constants and compare the generated instruction sequences across optimization levels.

Your task is to establish semantic equivalence, not to guess the original spelling.

## 3. Switch lowering

A `switch` may become:

- a chain of comparisons;
- a decision tree;
- a lookup table;
- a jump table;
- arithmetic plus bounds checking.

Find the dispatch strategy used by your compiler for the fixture.

## 4. Dead code

A compiler can prove some work irrelevant and remove it.

When something is absent, distinguish:

- stripped metadata;
- optimized-away computation;
- unreachable source;
- analysis-tool failure.

## 5. Tail positions

A call at the end of a function may be transformed so the usual `call ... ret` shape disappears.

Do not use `ret` counting as a function-counting method.

## Lab report

For at least five transformations record:

| Source idea | O0 evidence | O1 evidence | O2 evidence | Interpretation |
|---|---|---|---|---|

For every interpretation cite addresses/instructions from your own build.

## Principle

**Reverse the semantics that survived compilation, not the syntax that disappeared.**
