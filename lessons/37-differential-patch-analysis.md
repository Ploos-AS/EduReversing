# Lesson 37 — Differential and benign patch analysis

## Mission

Determine exactly what changed between two stripped versions of the same course-owned program:

- `build/diff-lab-v1`
- `build/diff-lab-v2`

Do not read the fixture sources until the report is complete.

## First rule: difference is not meaning

Hashes prove that files differ. Byte offsets show where files differ. Neither tells you which differences change application semantics.

Compiler/linker layout, addresses, padding and metadata may move even when a function's meaning does not.

## Workflow

1. Establish provenance and hashes.
2. Compare executable metadata and section layout.
3. Recover the externally visible behavior of each version.
4. Build a function-level map for both binaries.
5. Match functions using evidence, not addresses.
6. Identify changed constants, branches, data references and strings.
7. Classify each observed difference as semantic, presentation-only, layout/toolchain, or unresolved.
8. Predict an input for which the versions produce different output.
9. Test that prediction.
10. Explain the smallest semantic patch that accounts for the behavioral change.

## Patch-analysis boundary

The exercise asks what a benign software update changed. Do not alter a binary to bypass licensing, authentication, access control, integrity protection or another security boundary.

## Deliverable

Produce a version-difference table:

| Evidence | v1 | v2 | Classification | Behavioral consequence | Confidence |
|---|---|---|---|---|---|

Your conclusion must distinguish the changed presentation string from the changed arithmetic behavior.

## Source reveal

After completing the report, compare it with the two source fixtures. Record any conclusion that was correct for the wrong reason.
