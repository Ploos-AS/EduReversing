# Case File 10 — Analyst investigation

## Material

- `build/case-m3-01` — stripped, course-owned benign ELF
- `fixtures/incident-02/` — inert synthetic endpoint observations

The source and instructor notes are sealed.

## Mission

Produce an analyst report that distinguishes demonstrated program behavior from coincidental or misleading artifacts.

Recover:

- executable identity and relevant functions;
- input grammar and failure classes;
- the token transformation;
- any encoded data and its decoded meaning;
- which embedded strings are reachable and behaviorally relevant;
- which incident observations can be correlated with binary evidence;
- which proposed indicators remain unsupported;
- at least two alternative explanations consistent with the evidence.

## Static before dynamic

Create an initial program map and predictions before execution. A decompiler may assist navigation, but conclusions require machine/data evidence.

## Controlled runtime

Run only this course-owned fixture. Use multiple inputs to test the recovered grammar and token hypothesis. Record where runtime evidence strengthens or falsifies static interpretations.

## Reporting standard

Use the evidence ledger and defensive-triage template. Assign confidence per finding. Preserve unknowns.

A string appearing in the binary or evidence bundle is not proof that the corresponding behavior occurs.
