# Lesson 35 — When decompilers mislead

## Goal

Treat decompiler output as a hypothesis-producing view, not recovered source code.

## Common traps

A plausible high-level rendering can hide or misstate:

- signed versus unsigned comparisons;
- truncation and extension;
- array bounds implied by masking;
- aliases and shared storage;
- compiler-created temporaries;
- transformed control flow;
- constants whose meaning depends on width;
- operations that are clearer in flags or bit tests than in generated pseudocode.

## Lab

Analyze `build/decompiler-trap` without reading its source.

Recover:

1. how the input selects one of four values;
2. the exact four 32-bit values;
3. the signedness of the first classification test;
4. the byte-level special case;
5. the fallback class calculation.

Use disassembly as the authority when a decompiler view and machine evidence appear to disagree.

## Required evidence ledger

For each conclusion record:

- observation;
- interpretation;
- confidence;
- competing interpretation, if any;
- cross-check.

At least one conclusion must be justified using instruction width/sign-extension or condition-code evidence rather than decompiler syntax.

## Rule

Never write “the source does X” when only a binary is available. Write what the machine evidence establishes and how strongly it establishes it.
