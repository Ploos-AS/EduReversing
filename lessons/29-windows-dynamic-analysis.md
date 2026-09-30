# Lesson 29 — Safe Windows dynamic analysis

## Mission

Test static PE hypotheses at runtime without treating the Linux student OCI as a Windows sandbox.

## Environment boundary

The course OCI builds and statically inspects PE files. Native Windows execution belongs in a disposable Windows analysis environment appropriate to the student's licensing and host setup.

Recommended properties:

- disposable VM or equivalent isolated test system;
- snapshot before analysis;
- no personal files or credentials;
- no shared writable folders unless specifically required;
- network disabled unless a benign lab explicitly needs controlled connectivity;
- hashes and provenance recorded before execution.

All EduReversing repository fixtures are benign and course-owned. These habits exist so the same workflow remains disciplined when analysts later work in authorized defensive environments.

## Debugging workflow

For the benign PE fixtures:

1. establish a static hypothesis;
2. choose a breakpoint that can confirm or reject it;
3. record arguments using the Windows x64 ABI;
4. inspect relevant memory/register state;
5. step only as far as needed;
6. record the observation;
7. return to static analysis and revise the model.

Suitable Windows-side debuggers may include WinDbg or x64dbg. GUI tools are host-side rather than bundled into the student OCI.

## Cross-validation exercises

For `case-pe-01.exe`, confirm at least:

- the input reaches the expected parser;
- one selected rule is found;
- argument registers at one meaningful call site;
- the transformation state changes as predicted;
- the final output agrees with the static reconstruction.

## Reporting

A runtime observation is stronger evidence for an executed path, but one execution does not prove all possible behavior. Record exact input, environment and breakpoint location so another analyst can reproduce the observation.
