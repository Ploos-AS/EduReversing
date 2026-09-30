# Lesson 05 — Symbols, PLT/GOT and relocations

## Mission

Follow a function call from disassembly through dynamic-linking metadata instead of treating an imported call as magic.

## Learning objectives

You should be able to:

- inspect static and dynamic symbol tables;
- recognize undefined imported symbols;
- explain why stripped binaries can still expose dynamic imports;
- recognize PLT stubs and GOT-related references;
- inspect relocation entries;
- connect a call site to the library function eventually selected by the loader.

## Symbols

```sh
readelf -s build/elf-lab
nm build/elf-lab
nm -D build/elf-lab
```

Compare the outputs.

Questions:

1. Which symbols are defined by the executable?
2. Which are undefined?
3. Which undefined symbols reveal useful behavior?
4. What disappears after stripping?
5. What information must remain for dynamic linking?

## Dynamic dependencies

```sh
readelf -d build/elf-lab
readelf --dyn-syms build/elf-lab
```

Use `ldd` only on binaries you already trust. For an unknown specimen, prefer parsing metadata rather than invoking mechanisms that may load or inspect it in less controlled ways.

## PLT and GOT

Inspect disassembly:

```sh
objdump -d -M intel build/elf-lab
objdump -R build/elf-lab
```

Locate a call associated with an imported library function.

Trace:

```text
call site
   |
   v
PLT / linker-generated path
   |
   v
GOT-related resolution state
   |
   v
shared-library implementation
```

The exact code shape varies with toolchain, architecture and linker options. Learn the relationship, not one byte pattern.

## Relocations

```sh
readelf -r build/elf-lab
```

For several entries record:

- relocation offset;
- relocation type;
- associated symbol;
- what needs to be fixed/resolved.

## Stripping experiment

```sh
cp build/elf-lab build/elf-lab-stripped
strip --strip-all build/elf-lab-stripped
readelf -s build/elf-lab-stripped
readelf --dyn-syms build/elf-lab-stripped
objdump -d -M intel build/elf-lab-stripped
```

Compare what an analyst loses and what remains.

## Deliverable

Choose one imported function and document the evidence chain from a call instruction to dynamic symbol/relocation information.

## Principle

**A stripped binary is not an information-free binary. Runtime requirements leave evidence.**
