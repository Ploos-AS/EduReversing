# Case File 04 — Unknown PE

## Scenario

You receive `build/case-pe-01.exe`, a course-owned benign Windows x86-64 executable. Treat the binary as the primary evidence. Do not inspect `fixtures/src/case-pe-01.c` until your report is complete.

## Questions to answer

Determine and support with evidence:

- executable format, architecture and PE variant;
- section/load map and entry point;
- imported DLLs and functions relevant to your analysis;
- input grammar and failure classes;
- the accepted tag values;
- the repeated data structure used by the program;
- the major transformation applied to the text;
- output fields and their derivation;
- Windows x64 calling-convention evidence visible in at least one call path.

## Method

Choose your own tools. Static evidence is sufficient for most of the case. If you perform dynamic analysis, use an appropriate disposable Windows environment; the Linux student OCI is not a Windows execution sandbox.

Use `docs/ANALYSIS-TEMPLATE.md`. Keep observations, interpretations and unknowns distinct.

## Stop condition

Stop when another analyst could use your report to predict the program's result for a valid input and independently locate the supporting PE/code evidence.
