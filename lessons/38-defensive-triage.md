# Lesson 38 — Defensive triage from inert evidence

## Goal

Practice defensive-analysis reasoning without executing malware or simulating harmful behavior.

You receive `fixtures/incident-01/`, an inert evidence bundle representing observations from a hypothetical endpoint.

## Questions

Build a timeline and distinguish:

- direct observations;
- analyst interpretations;
- indicators worth pivoting on;
- facts that remain unknown.

Correlate the process, filesystem and synthetic network records. Determine which observations support a relationship and which merely occur near each other in time.

## Configuration extraction

`config.dat` is represented as hexadecimal text. Recover its container header and payload. Determine:

- magic;
- version;
- encoding/type byte;
- payload length;
- decoded configuration fields.

Do not assume a hostname or address is malicious because it appears in an incident bundle.

## Indicator discipline

For every proposed indicator record:

- exact value;
- source evidence;
- why it matters;
- scope;
- confidence;
- whether it is an observation or interpretation.

## Deliverable

Produce a short triage report using the evidence ledger. Include a timeline, extracted configuration, indicators, unknowns and at least two alternative explanations that the supplied evidence cannot eliminate.
