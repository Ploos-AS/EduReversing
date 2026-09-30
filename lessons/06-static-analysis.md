# Lesson 06 — Static analysis workflow

## Mission

Turn an unfamiliar executable into a structured behavioral hypothesis without executing it.

## Workflow

Use a funnel: cheap evidence first, increasingly detailed analysis later.

1. identity and hash;
2. headers and metadata;
3. strings;
4. imports and symbols;
5. disassembly;
6. functions;
7. basic blocks and control flow;
8. data-flow notes;
9. pseudocode hypothesis;
10. only then decide what dynamic analysis is needed.

## Triage

```sh
file build/static-lab
sha256sum build/static-lab
readelf -h build/static-lab
readelf -d build/static-lab
strings -a build/static-lab
objdump -d -M intel build/static-lab
```

Do not treat every string as reachable behavior. A string is evidence that bytes exist, not proof that a path executes.

Likewise, an imported function suggests capability or dependency, not proof of a particular runtime action.

## Find candidate functions

In a symbol-rich teaching build, compare:

```sh
nm build/static-lab
objdump -d -M intel build/static-lab
```

Then create a stripped copy and repeat the exercise.

Ask what evidence still helps you infer function boundaries:

- call targets;
- returns;
- branch targets;
- alignment;
- prologue/epilogue patterns;
- references from other code;
- coherent control flow.

No single heuristic is universal.

## Basic blocks

A basic block is a straight-line sequence with one entry and no internal control-flow split.

For one function:

1. mark its entry;
2. mark branch targets;
3. end blocks at conditional/unconditional branches and returns;
4. assign simple labels such as B0, B1, B2;
5. draw directed edges between blocks.

## Control-flow graph

Your first CFG can be plain text:

```text
B0
 | condition
 +------+
 |      |
 v      v
B1     B2
 \      /
  v    v
    B3
```

Annotate edges with conditions only when supported by the comparison and branch semantics.

## Data-flow notebook

Track important values separately from control flow:

| Location | Value/source | Evidence | Confidence |
|---|---|---|---|
| rdi | argv[1]? | caller + ABI | medium |
| eax | return value | ABI + ret path | high |

Confidence is useful because reverse engineering is iterative. A hypothesis can improve without rewriting history.

## Lab

Analyze `build/static-lab` without opening its source.

Determine:

- accepted input shape;
- number of major decision stages;
- likely purpose of each helper;
- success and failure paths;
- the role of the lookup data;
- plausible high-level pseudocode.

Do not execute it yet.

## Deliverable

Write a static-analysis report containing:

- artifact identity;
- evidence inventory;
- function map;
- one CFG;
- important data-flow observations;
- pseudocode;
- unresolved questions;
- dynamic-analysis plan.

## Principle

**Static analysis produces testable hypotheses, not clairvoyance.**
