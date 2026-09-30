# Lesson 04 — ELF anatomy

## Mission

Before interpreting instructions, learn to map the container that holds them. ELF metadata often answers important questions without executing a single instruction.

## Learning objectives

You should be able to:

- recognize an ELF file and its architecture;
- explain the difference between sections and segments;
- locate the entry point;
- identify executable, writable and read-only regions;
- find the dynamic linker and shared-library dependencies;
- distinguish file layout from process memory layout;
- use `readelf`, `objdump`, `nm` and `file` as complementary tools.

## Start with identity

```sh
file build/elf-lab
readelf -h build/elf-lab
```

Record:

- ELF class;
- byte order;
- machine;
- object type;
- entry point;
- program-header count;
- section-header count.

## Sections

```sh
readelf -S build/elf-lab
objdump -h build/elf-lab
```

Locate at least:

`.text`, `.rodata`, `.data`, `.bss`, `.dynsym`, `.dynstr`.

For each, ask whether it primarily contains code, initialized data, zero-initialized storage, strings or linker metadata.

Sections are especially useful to linkers and analysis tools. Do not assume the operating system maps each section independently.

## Segments

```sh
readelf -l build/elf-lab
```

Program headers describe how the executable is mapped for execution.

Find:

- `LOAD` entries;
- their R/W/X permissions;
- the interpreter;
- the section-to-segment mapping.

Explain why a section and a segment are not interchangeable concepts.

## File offsets versus virtual addresses

Pick one recognizable object from the file and record both where it resides in the file and where it is expected to reside in memory.

This distinction becomes essential when comparing hex dumps, disassembly and debugger addresses.

## Lab

Without reading the source:

1. identify the likely code region;
2. identify writable initialized data;
3. identify zero-initialized storage;
4. locate human-readable constant data;
5. determine which shared libraries are requested;
6. find the interpreter path;
7. identify whether the executable is PIE on your build platform.

Then inspect `fixtures/src/elf-lab.c` and explain which source objects ended up in which ELF areas.

## Deliverable

Draw a simple two-column map:

```text
ELF file                         process image
---------                        -------------
headers          --->            loader metadata
.text            --->            executable mapping
.rodata          --->            read-only mapping
.data/.bss       --->            writable mapping
...
```

Annotate it with evidence from your actual build.

## Principle

**The executable file is not the running process. ELF metadata describes the bridge between them.**
