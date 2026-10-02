# Lesson 40 — Persistence recognition without deployment

## Goal

Recognize evidence that may indicate automatic or recurring execution without creating persistence mechanisms.

## Evidence-first questions

When an artifact appears to reference startup or scheduling, ask:

- Is the referenced configuration actually present?
- Is it read or written by reachable code?
- Does it name an executable, command, service or trigger?
- Is the evidence historical, current, inert or merely a string?
- What platform component would consume it?
- What independent evidence shows execution occurred?

## Inert examples

Analyze descriptions of hypothetical startup entries, scheduled-task records and service metadata supplied as text by the instructor. Classify each as:

- direct persistence evidence;
- evidence of configuration only;
- stale/historical artifact;
- misleading/unreferenced string;
- insufficient evidence.

Do not create, install or activate startup entries.

## Reporting

Avoid statements such as “the program persists” when the evidence only establishes that a persistence-related string or configuration artifact exists. State the exact artifact, its provenance and what additional evidence would be needed to establish execution.
