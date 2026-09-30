# Lesson 24 — First look at PE/COFF

## Mission

Build the course-owned Windows x86-64 fixture and explain its executable-file structure without running it.

The binary is generated locally from `fixtures/src/pe-lab.c`. Generated PE files belong in `build/` and must never be committed.

## Build

```sh
make pe-lab
```

The result is `build/pe-lab.exe`.

## Evidence to recover

Identify and record:

- the DOS `MZ` signature and the location of the PE header;
- the `PE\0\0` signature;
- COFF machine type and number of sections;
- whether the optional header is PE32 or PE32+;
- image base, entry point and section alignment;
- section names, virtual addresses, raw offsets and permissions;
- imported DLLs and imported functions;
- evidence that the program targets Windows x86-64.

Useful CLI tools include `file`, `objdump`, `r2` and a hex viewer. Do not treat one tool's interpretation as the only evidence.

## Analyst questions

1. Which fields describe the file on disk, and which describe the image after loading?
2. Why can raw offsets differ from virtual addresses?
3. Which imports are compiler/runtime scaffolding, and which reveal likely program behavior?
4. What evidence distinguishes PE32+ from PE32?
5. What can you infer without executing the program?

## Windows x64 ABI bridge

When inspecting code, remember the first four integer/pointer arguments are normally passed in RCX, RDX, R8 and R9. The caller also reserves shadow space. Compare this with the System V AMD64 convention used by the Linux fixtures.

## Safety boundary

This is a benign program built from course-owned source. The exercise is executable-format analysis, not malware execution. Dynamic Windows analysis comes later and must use an appropriate disposable Windows environment.

## Deliverable

Add a short evidence ledger using `docs/ANALYSIS-TEMPLATE.md`. Separate observed PE facts from interpretations about program behavior.
