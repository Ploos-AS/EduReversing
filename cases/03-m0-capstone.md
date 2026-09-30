# Case file 03 — M0 mini-capstone

## Scenario

You are given one benign but undocumented native executable:

```text
build/capstone-m0
```

Determine what it accepts and how it produces its successful output.

The source exists only so the course can build a reproducible artifact. Treat it as sealed until your report is finished.

## Rules

You may statically and dynamically analyze the artifact.

Choose your own tool sequence.

Do not inspect:

```text
fixtures/src/capstone-m0.c
instructor/capstone-m0-notes.md
```

before submission.

## Required report

Use `docs/ANALYSIS-TEMPLATE.md`.

Your report must include:

- artifact identity and hash;
- input grammar/contract;
- all meaningful failure classes you can establish;
- function map;
- recovered persistent data structures/tables;
- major data-flow transformation;
- successful output format and semantics;
- relevant versus irrelevant embedded indicators;
- at least one static claim validated dynamically;
- at least one dynamic observation explained statically;
- uncertainty and remaining unknowns;
- exact reproduction commands.

## Evidence standard

Decompiler output alone is not sufficient evidence.

For important claims, point to instructions, data, XREFs, observed state, controlled executions or a combination.

## No checklist of tools

There is intentionally no suggested command sequence.

## Stop condition

A second analyst, without source access, should be able to use your report to predict the program's successful behavior for new valid inputs and explain why apparently suspicious-looking strings do or do not matter.
