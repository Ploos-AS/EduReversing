# Lesson 15 — Defensive triage of a suspicious-looking artifact

## Mission

Practice defensive triage on a deliberately inert course fixture.

The fixture contains suspicious-looking *data* for analysis, but it does not create persistence, contact a network service, steal data, execute another payload or alter the host.

## Triage order

1. establish provenance and hash;
2. identify format/architecture;
3. inspect metadata;
4. inventory strings;
5. inspect imports;
6. map code and data;
7. classify observations;
8. decide whether execution is necessary.

## Indicator categories

Record potential indicators as data, not conclusions:

- host/domain-like strings;
- path-like strings;
- user-agent-like strings;
- mutex/service/task-like names;
- encoded blobs;
- configuration keys;
- timestamps or version identifiers.

A suspicious string can be decoy, unused data, test data or documentation. XREF it before claiming behavior.

## Lab

Analyze `build/defensive-lab` statically first.

Find:

- the example domain;
- the example IPv4 address;
- the path-like persistence *description*;
- the configuration marker;
- the encoded configuration bytes;
- all code paths that reference them.

The domain and IP use reserved documentation namespaces and are not operational infrastructure.

## Classification

For each finding mark one:

- observed;
- inferred;
- confirmed by code path;
- unconfirmed;
- intentionally inert course data.

## Deliverable

Produce a one-page triage report using `docs/ANALYSIS-TEMPLATE.md`.

## Principle

**Indicators are leads. Behavior requires evidence.**
