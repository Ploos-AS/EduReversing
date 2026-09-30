# Lesson 32 — AArch64 ABI and data flow

## Goal

Recover function boundaries, arguments and return values from AArch64 machine code rather than translating x86-64 habits.

## ABI evidence

For ordinary integer and pointer calls, investigate X0–X7 as argument registers and X0 as the scalar return register. Observe X29/X30 save/restore patterns where the compiler emits a frame, and distinguish SP movement from application data flow.

W-register writes affect the low 32-bit value and zero the upper half of the corresponding X register. This matters when following 32-bit arithmetic through a 64-bit register file.

## Lab

Use `build/aarch64-lab` first. At each call site, record:

1. values prepared before the branch-and-link;
2. registers carrying those values;
3. which registers are consumed by the callee;
4. where the result is observed after return.

Then repeat on optimized code and note which source-level boundaries disappear.

## Instruction patterns

Become comfortable recognizing evidence from:

- `bl` and `ret`;
- `stp`/`ldp` frame patterns;
- `adrp` plus address-forming instructions;
- `ldr`/`str`;
- shifts, ORs and rotate aliases;
- conditional branches and compare/test forms.

Do not assign meaning from a mnemonic alone. Tie it to register provenance, control flow and referenced data.

## Cross-check

Run the benign fixture under QEMU only after writing a static prediction. Compare the observed result with the prediction and document any discrepancy.
