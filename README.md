# EduReversing

**Assembly, Reverse Engineering and Defensive Malware Analysis**

EduReversing is a practical course and book project that teaches how to understand compiled programs from the bottom up.

The course starts with assembly language as it appears in real disassembly, then moves through compiler output, executable formats, static analysis, debugging, reverse engineering workflows, and defensive malware analysis.

The project is designed for students who may already know some C or assembly, but it does not require prior reverse-engineering experience.

## Goals

Students should learn to:

- read x86 and x86-64 disassembly confidently;
- recognize common C constructs in compiler output;
- understand stack frames, calling conventions, registers, flags and control flow;
- inspect ELF and PE binaries;
- use command-line reversing tools and debuggers;
- use Ghidra and radare2/Cutter as analysis aids rather than black boxes;
- distinguish code, data, imports, relocations and metadata;
- reconstruct program behavior from unknown binaries;
- document findings clearly and reproducibly;
- perform defensive malware analysis in a safe lab environment;
- extract indicators and behavioral observations without executing real malware from this repository.

## Scope

Primary architecture:

- x86-64
- x86

Secondary architecture modules:

- ARM/AArch64
- Motorola 68000 family

Primary binary formats:

- ELF
- PE/COFF

Additional material may cover Amiga Hunk and other historical formats where useful.

## Safety model

EduReversing is a defensive education project.

The repository must **not contain real malware**.

Labs use small purpose-built programs, synthetic samples, benign packed/encoded data, compiler-generated binaries, and other non-malicious fixtures created specifically for teaching analysis techniques.

Students are taught isolation, provenance, hashing, evidence handling, snapshots, and repeatable analysis before any malware-analysis concepts are introduced.

See [`docs/SAFETY.md`](docs/SAFETY.md).

## Student environment

The course will provide a standalone student OCI image so learners are not dependent on Ploos infrastructure.

The baseline image is Debian minimal and will include the command-line toolchain required by the course. GUI tools may be installed separately on the host where appropriate.

## Course structure

The initial curriculum is split into the following parts:

1. Orientation and safe analysis
2. Assembly for reverse engineers
3. C to assembly and back again
4. Executable formats
5. Static analysis
6. Dynamic analysis
7. Compiler patterns and optimization
8. Reverse-engineering workflows
9. Defensive malware analysis
10. Obfuscation and anti-analysis concepts
11. Multi-architecture reversing
12. Capstone investigations

See [`docs/CURRICULUM.md`](docs/CURRICULUM.md) for the detailed M0 curriculum.

## Relationship to other Ploos courses

EduReversing complements rather than replaces CPU- and architecture-specific assembly courses. Those courses teach how processors work and how to write assembly; EduReversing focuses on reading and reasoning about code that already exists.

It is especially complementary to EduC, EduPOSIX and Edu65xx.

## Publishing

Course content is intended to be published from a shared Markdown source to web and book formats through the Ploos publishing workflow.

## License

Course and documentation content: **CC BY 4.0**.

Code examples and supporting tooling may use a permissive software license where noted.

Copyright © Ploos AS.
