# Lesson 08 — Dynamic analysis with GDB

## Mission

Test static-analysis hypotheses by observing a known-safe program while it executes.

Dynamic analysis is not a substitute for static analysis. It gives you observations for particular executions.

## Learning objectives

You should be able to:

- start and stop a program under GDB;
- set breakpoints by symbol and address;
- inspect registers, flags, stack and memory;
- single-step instructions;
- distinguish `stepi` from `nexti`;
- use watchpoints to detect data changes;
- connect runtime addresses to static disassembly;
- record observations reproducibly.

## Prepare

```sh
make dynamic-lab
gdb ./build/dynamic-lab
```

The fixture is benign and built from repository source. Do not generalize that trust to arbitrary binaries.

## Establish context

Inside GDB:

```text
set disassembly-flavor intel
info files
start
info registers
disassemble
```

Compare the runtime addresses with `objdump` output. If address randomization/PIE changes addresses, document that rather than assuming the static and runtime address spaces are identical.

## Breakpoints

Set a breakpoint on a function:

```text
break process_value
run 17
```

Inspect:

```text
info registers
x/16gx $rsp
x/10i $pc
disassemble process_value
```

Find the argument according to the ABI and follow it through the function.

## Instruction stepping

Use:

```text
stepi
nexti
```

Before each important instruction, predict what will change. Then step and verify.

For a comparison and conditional branch, record:

- operands;
- relevant flags;
- branch mnemonic;
- whether the branch was taken.

## Memory

Use `x` with explicit formats rather than staring at an undifferentiated dump.

Examples:

```text
x/16bx ADDRESS
x/8wx ADDRESS
x/s ADDRESS
```

Always record what you believe the address represents and why.

## Watchpoints

A watchpoint asks the debugger to stop when a value changes.

Find the fixture's mutable state and try:

```text
watch VARIABLE
continue
```

At the stop, inspect the instruction and call stack:

```text
x/i $pc
bt
```

## Multiple executions

Run the program with at least three different inputs. A dynamic observation applies to the path you executed; it does not prove unexecuted paths do not exist.

Build a table:

| Input | Path/branch | State change | Output |
|---|---|---|---|

## Deliverable

Update your earlier static hypothesis with:

- confirmed claims;
- disproved claims;
- newly discovered behavior;
- paths still not tested.

## Principle

**One execution proves what happened once, not everything the program can do.**
