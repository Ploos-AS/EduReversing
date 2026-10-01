# Lesson 39 — Encoding, obfuscation and anti-analysis recognition

## Goal

Recognize transformations and suspicious-looking analysis signals without treating appearance as proof of malicious or evasive behavior.

## Encoding lab

Analyze `build/encoding-lab` with source sealed.

Recover:

- where the encoded bytes live;
- the transformation;
- the key or constant;
- decoded length;
- decoded plaintext;
- how runtime behavior verifies the result.

Explain why a simple reversible transform is not encryption and why high entropy, encoded strings or hidden plaintext do not establish malicious intent.

## Anti-analysis recognition

Review `fixtures/analysis-signals.txt`.

For each sample classify the observation as:

- evidence of an analysis-sensitive behavior;
- ordinary behavior with an alternative explanation;
- unreachable/misleading artifact;
- insufficient evidence.

There may be more than one defensible hypothesis. State what additional static or runtime evidence would distinguish them.

## Boundary

This lesson teaches recognition and evidence evaluation. It does not implement debugger evasion, sandbox evasion, environment fingerprinting for evasion, persistence, destructive behavior or covert execution.

## Deliverable

Use the evidence ledger. For the encoded fixture, provide a reproducible decoder or transformation description. For the inert signal set, provide calibrated findings rather than malware labels.
