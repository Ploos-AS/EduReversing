# Lesson 19 — ARM and AArch64

## Mission

Transfer evidence-driven reversing to a load/store RISC architecture.

## Registers first

For AArch64, become comfortable with:

- `x0`–`x30` and their 32-bit `wN` views;
- `sp`;
- link register `x30`;
- condition flags;
- argument and return registers under the platform ABI.

Writing a `wN` register affects its corresponding `xN` value. Track width explicitly.

## Load/store model

Arithmetic generally operates on registers. Memory is accessed through explicit loads/stores.

This often makes data-flow boundaries clearer, but address calculation can still be non-trivial.

Watch for:

- base + immediate;
- indexed addressing;
- paired loads/stores;
- PC-relative address construction.

## Calls and returns

Identify branch-with-link and return patterns, but remember that optimization can alter expected shapes.

Recover:

- incoming arguments;
- preserved registers;
- local state;
- outgoing call arguments;
- return value.

## Conditional behavior

Map comparisons and conditional branches as you did on x86. The mnemonics change; the evidence workflow does not.

## ARM versus AArch64

Treat 32-bit ARM as a related but distinct target. Do not transfer AArch64 register names, instruction encodings or ABI assumptions blindly.

## Exercise

Given equivalent pseudocode from an earlier x86 lab, sketch the questions you would ask when faced with its AArch64 binary:

1. where are arguments?
2. where is the return value?
3. how are addresses formed?
4. where are memory accesses?
5. which branches form the CFG?

## Principle

**Learn the target's ISA and ABI; keep the same evidence discipline.**
