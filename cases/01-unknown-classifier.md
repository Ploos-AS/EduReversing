# Case file 01 — Unknown classifier

## Brief

You have received a small unknown ELF executable:

```text
build/case-01
```

Your task is to determine its input contract and explain how it chooses its output class.

Treat the binary as the primary evidence. Do **not** inspect `fixtures/src/case-01.c` until your report is complete.

## Rules

The fixture is course-owned and benign, so controlled execution is permitted.

Use `docs/ANALYSIS-TEMPLATE.md`.

## Required findings

Your report must establish:

- file type and architecture;
- expected command-line input;
- validation/failure behavior;
- possible successful output classes;
- the function or code region responsible for classification;
- the major transformation stages leading to the decision;
- the final decision thresholds or equivalent semantics.

For every semantic claim, cite static or dynamic evidence.

## Suggested starting points

You may use:

```sh
file
sha256sum
readelf
strings
objdump
r2
gdb
strace
```

The list is not an ordered recipe.

## Confidence

Mark findings as:

- confirmed;
- likely;
- hypothesis;
- unknown.

## Stop condition

Stop when another analyst could reproduce your explanation of the classifier from the evidence in your report.

Then compare against the instructor notes.
