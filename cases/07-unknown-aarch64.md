# Case File 07 — Unknown AArch64 ELF

## Evidence

Primary evidence: `build/case-aarch64-01`.

The source is sealed until the report is complete.

## Investigation

Using the standard analysis template, establish:

- ELF class, byte order and machine architecture;
- entry/runtime scaffolding versus application logic;
- command-line grammar and failure classes;
- valid numeric identifiers;
- the repeated record layout, including signed fields;
- record-selection logic;
- token transformation;
- output semantics;
- AArch64 argument/return-register evidence at meaningful call sites;
- at least one compiler artifact that should not be mistaken for application behavior.

Static analysis must be sufficient to support the result. Controlled QEMU execution may be used to test hypotheses.

## Evidence discipline

For each major conclusion, distinguish direct observation from inference. A decompiler rendering may help navigation but is not itself proof.

## Stop condition

Stop when your report lets another analyst predict the output for an arbitrary valid identifier/message pair and reproduce each failure class without seeing the source.
