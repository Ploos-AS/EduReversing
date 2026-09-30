# Instructor notes — M0 mini-capstone

Keep sealed until assessment is complete.

## Input

Exactly one argument in the form:

```text
TAG:PAYLOAD
```

TAG must be A, B or C. PAYLOAD must be non-empty.

Exit classes:

- 2: wrong argc;
- 3: malformed prefix/too short;
- 4: unknown tag;
- 5: empty payload.

## Rule layout

Semantic fields:

```c
uint8_t tag;
uint8_t shift;
uint16_t add;
uint32_t key;
```

Three records select rotation count, additive constant and initial key.

## Transformation

Initialize x from the rule key. For each payload byte:

1. add rule.add to the byte;
2. XOR into x;
3. rotate x left by rule.shift.

Output:

```text
ticket=%08x class=%u
```

Class is bits 29..31 of the final value.

## Decoys

The strings:

- `update.example.invalid`
- `autorun:training-decoy`

are inert course data. They must not be reported as network or persistence behavior.

## Assessment

A strong report demonstrates method, not source-code reconstruction.

Look for:

- separation of observation/inference;
- correct record stride/field widths;
- proof of tag lookup;
- loop/data-flow reconstruction;
- correct rotate semantics;
- evidence that decoys are irrelevant;
- reproducible static/dynamic cross-validation;
- explicit uncertainty.
