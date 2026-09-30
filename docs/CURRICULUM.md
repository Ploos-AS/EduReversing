# EduReversing Curriculum

## M0 curriculum contract

EduReversing teaches reverse engineering from first principles, with assembly as the working language of analysis rather than as an end in itself.

The course should be usable both as a guided course and as a self-study book. Each practical chapter should converge on a repeatable analysis workflow and produce evidence the student can explain.

## Part 0 — Orientation

### 00. What reverse engineering is

- legitimate and defensive uses
- source code versus machine code
- disassembly versus decompilation
- static versus dynamic analysis
- evidence, hypotheses and reproducibility

### 01. Build the analysis lab

- host versus guest separation
- snapshots and disposable environments
- hashes and provenance
- network isolation
- course OCI environment
- GUI tools outside the OCI where appropriate

### 02. First unknown binary

The student receives a tiny benign binary before learning every tool. The goal is to establish the basic loop:

1. identify
2. inspect
3. hypothesize
4. test
5. document

## Part I — Assembly for reverse engineers

### 03. Numbers, bytes and memory

- hexadecimal
- endian order
- signed and unsigned integers
- pointers
- memory views

### 04. x86-64 execution model

- general-purpose registers
- instruction pointer
- flags
- stack pointer
- register widths

### 05. Moving and transforming data

- mov and lea
- arithmetic
- bitwise operations
- shifts
- comparisons

### 06. Control flow

- conditional branches
- loops
- calls and returns
- indirect branches
- control-flow graphs

### 07. Stack and functions

- stack frames
- arguments
- local variables
- saved registers
- return values

### 08. Calling conventions

- System V AMD64
- Windows x64 overview
- x86 historical conventions
- why ABI knowledge matters in reversing

## Part II — C to assembly and back

### 09. C expressions in assembly

### 10. if, switch and loops

### 11. arrays, pointers and structures

### 12. functions and recursion

### 13. strings and library calls

### 14. reconstructing C from disassembly

Students repeatedly compile small source examples, remove the source, and reconstruct behavior from the resulting binary.

## Part III — Executable files

### 15. Anatomy of ELF

- headers
- program headers
- sections
- symbols
- relocations
- dynamic linking

### 16. ELF tooling

- file
- readelf
- objdump
- nm
- strings
- ldd where appropriate

### 17. Anatomy of PE/COFF

- DOS and PE headers
- sections
- imports and exports
- relocations
- resources

### 18. Debug information and stripped binaries

- symbols
- DWARF overview
- stripped versus unstripped binaries

## Part IV — Static analysis

### 19. Static triage

- file identity
- hashes
- metadata
- strings
- imports
- entropy as a clue, not a verdict

### 20. Disassembly workflow

### 21. Ghidra fundamentals

### 22. radare2 and Cutter fundamentals

### 23. Functions and cross-references

### 24. Data structures and global state

### 25. Building a program map

## Part V — Dynamic analysis

### 26. GDB fundamentals

- breakpoints
- stepping
- registers
- memory
- stack

### 27. Watchpoints and data flow

### 28. System and library interactions

- syscall tracing
- library-call tracing
- files
- processes
- environment

### 29. Static hypotheses versus runtime evidence

## Part VI — Compiler archaeology

### 30. Optimization levels

Compare `-O0`, `-O1`, `-O2` and selected higher-level transformations.

### 31. Inlining and eliminated abstractions

### 32. switch tables and jump tables

### 33. tail calls and transformed loops

### 34. recognizing compiler idioms

### 35. when decompilers mislead

## Part VII — Reverse-engineering methodology

### 36. A disciplined reversing workflow

### 37. Naming and annotation

### 38. Recovering structures and protocols

### 39. Differential analysis

### 40. Binary patch analysis

The emphasis is understanding changes between benign program versions, not bypassing protections.

## Part VIII — Defensive malware analysis

All repository samples in this part are benign simulations or inert fixtures.

### 41. Malware-analysis terminology

### 42. Safe triage

### 43. Behavioral indicators

- filesystem observations
- process behavior
- configuration artifacts
- network indicators represented by controlled fixtures

### 44. Configuration extraction

Students learn to recognize and decode configuration data from purpose-built non-malicious samples.

### 45. Persistence patterns

Conceptual and analytical treatment using benign demonstrations.

### 46. Packers, encoding and obfuscation

Safe teaching examples focus on identifying transformations and recovering program meaning.

### 47. Anti-analysis concepts

Recognition and reasoning, using synthetic examples.

### 48. Writing an analysis report

- evidence
- confidence
- unknowns
- indicators
- reproducibility

## Part IX — Other architectures

### 49. x86 32-bit refresher

### 50. ARM/AArch64 reversing

### 51. Motorola 68000 reversing

This module links naturally to the wider Ploos retro-computing curriculum.

### 52. Architecture-independent reasoning

Students analyze equivalent functions compiled for several architectures and identify what remains conceptually the same.

## Part X — Historical and specialist formats

### 53. Amiga Hunk introduction

### 54. Reverse engineering a small Amiga program

### 55. Comparing ELF, PE and Hunk

## Part XI — Investigations

### 56. Unknown program I

Static-analysis-only investigation.

### 57. Unknown program II

Static plus dynamic analysis.

### 58. Unknown program III

Stripped optimized binary.

### 59. Defensive incident sample

A benign synthetic sample designed to resemble an analyst triage case without containing malicious payloads.

## Part XII — Capstone

### 60. Capstone investigation

The student receives an undocumented benign executable and produces:

- provenance and hashes
- executable-format assessment
- function map
- reconstructed behavior
- selected annotated disassembly
- runtime observations
- indicators or relevant artifacts
- confidence levels
- unresolved questions
- final analysis report

## Exercise philosophy

Exercises should progress through four levels:

1. **Guided** — exact commands and questions.
2. **Prompted** — goals are supplied, commands are not.
3. **Unknown** — the student gets a binary and an investigation question.
4. **Case file** — the student produces an analyst-style report.

The student should frequently encounter binaries without corresponding source code, even though the repository may contain generators or source material used by maintainers to create safe fixtures.

## Completion target

A student completing EduReversing should be capable of approaching an unfamiliar native binary methodically, explaining its relevant behavior from evidence, and documenting the analysis without depending on automated decompiler output as an unquestioned answer.
