# M1 Capstone — Unknown Windows executable

## Evidence package

You receive one file: `build/capstone-m1.exe`.

It is a course-owned benign Windows executable. Treat it as an unknown PE. Source files and instructor notes are sealed until assessment is complete.

## Task

Produce a defensible reverse-engineering report using `docs/ANALYSIS-TEMPLATE.md`.

Your report must be sufficient for another analyst to independently reproduce your conclusions. Choose your own tools and analysis order.

At minimum, establish:

- file identity, architecture and PE variant;
- disk/load structure and entry-point context;
- meaningful imports and what they do — and do not — prove;
- resource evidence and its relationship to executable behavior;
- accepted input model and failure behavior;
- important internal data structures;
- program control-flow model;
- transformation/output semantics;
- at least one function-call reconstruction grounded in the Windows x64 ABI;
- compiler/runtime artifacts that should not be mistaken for application logic;
- inert or irrelevant embedded evidence;
- remaining uncertainty.

## Evidence standard

Decompiler output is not a conclusion. Strings are not behavior. Imports are not execution evidence.

For important findings, cross-check independent evidence where practical: raw structure, disassembly, cross-references, data layout, controlled execution or debugger observations.

If dynamic analysis is used, perform it only in the disposable Windows environment described by the course.

## Source seal

Do not inspect:

- `fixtures/src/capstone-m1.c`;
- `fixtures/src/capstone-m1.rc`;
- `instructor/capstone-m1-notes.md`

until the report has been submitted or self-assessment has begun.

## Stop condition

Stop when a second analyst could use only your report and the binary to predict valid behavior, reproduce failure cases, locate the supporting PE structures/code and understand which suspicious-looking evidence is inert.
