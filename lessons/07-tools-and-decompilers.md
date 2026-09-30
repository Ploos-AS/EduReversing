# Lesson 07 — radare2, Cutter and Ghidra without surrendering reasoning

## Mission

Use analysis frameworks and decompilers to accelerate reasoning while retaining the ability to verify their claims against machine code.

## Command-line baseline

Begin with the same evidence you already know. For radare2:

```sh
r2 -A build/static-lab
```

Useful exploratory commands include:

```text
iI
iS
ii
afl
pdf
axt
iz
```

Consult the installed tool's help for exact behavior and version-specific changes.

## GUI tools

Cutter and Ghidra can provide:

- discovered function lists;
- cross-references;
- graph views;
- renamed variables/functions;
- comments;
- type propagation;
- decompiler output.

These are analysis aids, not authorities.

## Verification loop

When a decompiler produces a convincing statement such as:

```c
if (value == 7) ...
```

verify:

1. which machine instruction performs the comparison;
2. signed or unsigned interpretation;
3. which conditional branch follows;
4. which path corresponds to true;
5. whether a prior cast/truncation changes the meaning.

## Renaming discipline

Prefer names that encode evidence:

```text
FUN_00101230
  -> parses_decimal?
  -> parse_decimal
```

A question mark can be useful while a role remains hypothetical. Promote a name when evidence supports it.

Avoid naming a function `decrypt_password` merely because it processes bytes.

## Cross-references

Use XREFs to answer:

- who calls this function?
- where is this string used?
- which code reads this global?
- are there multiple callers with different argument patterns?

Cross-references often reveal context faster than reading a function in isolation.

## Lab

Analyze `static-lab` three ways:

1. `objdump/readelf/strings`;
2. radare2;
3. Ghidra or Cutter if available on your host.

Compare:

- discovered function boundaries;
- inferred types;
- CFG;
- pseudocode;
- anything a tool got wrong or expressed misleadingly.

## Deliverable

Choose three decompiler claims and provide the underlying assembly evidence that supports or contradicts each one.

## Principle

**Never cite the decompiler as the reason. Cite the machine-code evidence.**
