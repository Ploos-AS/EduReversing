# Case File 11 — M3 capstone investigation

## Material

- `build/capstone-m3-v1`
- `build/capstone-m3-v2`
- `fixtures/incident-m3-capstone/`

Both executables are stripped, benign and course-owned. Sources and instructor notes are sealed.

## Mission

Produce a defensible analyst report explaining the program family and the update from v1 to v2.

Your report must recover:

- input grammar and failure classes;
- repeated profile structure, field widths and signedness;
- accepted IDs and lookup behavior;
- ticket algorithm for each version;
- encoded configuration in each version;
- reachable behavior versus misleading embedded artifacts;
- semantic changes between v1 and v2;
- presentation-only or layout differences;
- which incident observations are supported by binary capabilities and which are not;
- confidence and unresolved questions.

## Differential requirement

Find an input that distinguishes v1 and v2, predict both outputs from your recovered algorithms, then verify them dynamically.

Do not treat changed addresses or raw byte offsets as semantic changes without supporting evidence.

## Defensive-analysis requirement

Build a timeline from the inert evidence bundle. Strings such as `sandbox`, `debugger` and `autorun` are clues only. DNS/network/file observations in the bundle do not prove that either executable implements those actions.

## Final report

Use the evidence ledger, differential-analysis template and defensive-triage template. Include reproducible commands and at least two alternative explanations for evidence that remains ambiguous.
