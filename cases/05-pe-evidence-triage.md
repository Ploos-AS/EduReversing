# Case File 05 — PE evidence triage

## Scenario

You receive `build/case-pe-02.exe`, an optimized and stripped course-owned PE32+ x86-64 executable. Source and instructor notes are sealed until the report is complete.

The image deliberately contains evidence of different value: executable logic, compiler/runtime scaffolding, a diagnostic marker and resource strings. Your task is not to collect every string. Your task is to determine what matters.

## Required findings

Support each conclusion with evidence:

- PE variant, architecture, entry point and section/load map;
- imported DLLs and selected imports, separated into runtime scaffolding and behavior-relevant evidence;
- resource directory contents and whether each resource affects normal execution;
- input grammar and distinct failure classes;
- valid numeric IDs;
- recovered repeated-record layout, including signed and unsigned fields;
- record-selection logic;
- the main transformation applied to the text;
- output fields and their derivation;
- at least one Windows x64 ABI argument reconstruction;
- at least two pieces of embedded evidence that are irrelevant to normal program behavior, with a justification.

## Constraints

Do not inspect `fixtures/src/case-pe-02.c` or `fixtures/src/case-pe-02.rc` before completing the report.

Static analysis should be enough to reconstruct the program. Dynamic analysis is optional and, if used, belongs in a disposable Windows environment.

## Evidence grading

Label important claims as:

- confirmed;
- strongly supported;
- hypothesis;
- unknown.

An import or string alone does not establish behavior.

## Stop condition

Stop when another analyst can predict the output for an arbitrary valid ID/text pair, explain all normal failure paths, and distinguish executable behavior from PE/resource/compiler noise.
