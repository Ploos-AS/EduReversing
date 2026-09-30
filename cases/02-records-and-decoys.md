# Case file 02 — Records and decoys

## Brief

Analyze `build/case-02`.

It is a benign course-owned ELF artifact. Source is withheld during the investigation.

Determine what inputs matter and how the successful result is produced.

## Deliverable

Use `docs/ANALYSIS-TEMPLATE.md`.

Your report must contain a function map, an inferred data-layout section and an evidence ledger.

## Questions

Your final report should answer:

- What is the input contract?
- Which inputs are accepted but produce no normal classified result?
- Is there a repeated data structure? If so, infer its layout.
- How is a record selected?
- What transformation is applied?
- How is the textual class selected?
- Which apparently interesting evidence is irrelevant to normal output?
- How did you prove that irrelevance rather than merely assume it?

## Constraints

There is deliberately less procedural guidance than in Case 01.

You may execute the fixture because it is known-safe course material. Do not inspect `fixtures/src/case-02.c` before submitting your analysis.

## Stop condition

Another analyst should be able to predict the program's result for a valid input using your reconstructed semantics.
