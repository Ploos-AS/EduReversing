# Lesson 17 — Recognizing defensive analysis patterns

## Mission

Learn the vocabulary and evidence patterns associated with suspicious software without implementing harmful behavior.

## Persistence indicators

Examples you may encounter in reports or inert fixtures include references to:

- startup folders;
- service configuration;
- scheduled execution;
- shell/profile startup files;
- autostart mechanisms.

A string naming one of these is not proof that persistence occurs. Look for the code that would use it.

This course does not provide code that installs persistence.

## Packing and obfuscation

Analytical signs can include:

- unusually high-entropy regions;
- few useful strings;
- a small visible loader-like region;
- runtime-created code/data;
- indirect control flow;
- encoded strings.

Benign software can also exhibit several of these properties.

Our exercises use only benign encoding and controlled transformations.

## Anti-analysis concepts

Analysts may encounter software that checks aspects of its environment or changes behavior under observation.

In this course these ideas are studied descriptively and through inert metadata/examples. We do not build operational debugger-evasion, sandbox-evasion or analysis-bypass mechanisms.

## Reporting discipline

Prefer:

> The artifact contains the string X, referenced by function Y.

over:

> The artifact definitely establishes persistence.

until the behavior is supported by code or controlled observation.

## Exercise

Given the course fixture, separate:

1. suspicious-looking strings;
2. reachable behavior;
3. inert decoy/documentation data;
4. unknowns.

Explain the evidence needed to promote each hypothesis to a conclusion.

## Principle

**Recognition is not attribution, and suspicious appearance is not proof of malicious behavior.**
