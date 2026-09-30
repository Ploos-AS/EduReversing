# Lesson 02 — Registers, flags, stack and calls

## Mission

Learn enough x86-64 assembly to follow existing code. The goal is not to memorize every instruction; it is to recognize state, data flow, decisions and function boundaries.

## Learning objectives

You should be able to:

- classify the general-purpose registers;
- follow values through common data-movement and arithmetic instructions;
- explain how `cmp` and `test` affect later conditional branches;
- recognize stack growth, `push`, `pop`, `call` and `ret`;
- recognize a conventional function prologue/epilogue;
- follow the System V AMD64 integer argument registers;
- distinguish a register's architectural name from its role at a particular point in a program.

## 1. Registers are state, not variables

On x86-64, registers such as `rax`, `rbx`, `rcx`, `rdx`, `rsi`, `rdi` and `r8`–`r15` are architectural storage locations.

Do not automatically rename `rax` to something like `result`. First establish what value it contains at the point you are analyzing.

Useful subregister relationships include:

- `rax` → `eax` → `ax` → `al`
- `rdi` → `edi` → `di` → `dil`

Writing a 32-bit general-purpose register zero-extends into the corresponding 64-bit register.

## 2. Data flow

Study these instruction families in disassembly:

```asm
mov
movzx
movsx
lea
add
sub
and
or
xor
shl
shr
sar
imul
```

For every instruction ask:

1. What state is read?
2. What state is written?
3. Is the value data, an address, or not yet known?
4. Are flags changed?

## 3. Decisions: flags plus branches

A comparison is usually a two-step story.

```asm
cmp edi, 10
je  somewhere
```

`cmp` updates status flags as if a subtraction had occurred without storing the subtraction result. The later conditional jump interprets those flags.

Similarly:

```asm
test eax, eax
jne somewhere
```

is a common way to test whether a value is non-zero.

Build a small reference table in your own notes for:

`je/jz`, `jne/jnz`, `ja`, `jae`, `jb`, `jbe`, `jg`, `jge`, `jl`, `jle`.

Pay particular attention to the distinction between signed and unsigned comparisons.

## 4. The stack

The stack normally grows toward lower addresses. `rsp` identifies the current stack top.

A classic unoptimized function may contain:

```asm
push rbp
mov rbp, rsp
sub rsp, 32
...
leave
ret
```

But optimized code may omit this shape entirely. Treat prologue patterns as evidence, not universal laws.

## 5. Calls and arguments

For the System V AMD64 ABI used by ordinary 64-bit Linux programs, the first integer/pointer arguments are normally passed in:

```text
rdi, rsi, rdx, rcx, r8, r9
```

The integer return value is normally in `rax`.

This is one of the highest-value facts when beginning Linux x86-64 reversing: a call preceded by writes to those registers often exposes what is being passed to the callee.

## Lab

Build the course fixtures and open `build/unknown-01`:

```sh
make fixtures
objdump -d -M intel build/unknown-01 | less
```

Without reading the fixture source, find evidence for:

- argument-count handling;
- at least one library call;
- a comparison;
- a conditional branch;
- a return value;
- the loop used by one function.

Then use GDB to stop before and after a comparison and record the relevant registers and flags.

## Deliverable

Create a trace table with columns:

| Address | Instruction | Inputs | Outputs | Meaning/hypothesis |
|---|---|---|---|---|

Trace at least one complete path from a function entry to its return.

## Principle

**Registers have values. Analysts infer roles. Keep those two facts separate.**
