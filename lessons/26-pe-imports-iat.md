# Lesson 26 — PE imports and the IAT

## Mission

Recover external dependencies from `build/pe-lab.exe` and explain how imported calls reach code outside the image.

## Concepts

Distinguish:

- import directory;
- DLL import descriptor;
- imported name;
- import lookup/name information;
- Import Address Table (IAT);
- the loader's role.

The important reversing idea is that an imported API name is evidence of capability or dependency, not proof that a particular behavior occurred.

## Investigation

Use more than one view where practical:

```sh
x86_64-w64-mingw32-objdump -p build/pe-lab.exe
r2 -A build/pe-lab.exe
```

Record imported DLLs and selected imported functions. Find at least one call path from program code to an imported function and identify the IAT-related indirection.

## Evidence discipline

For each interesting import, classify your statement:

- observed: the import exists;
- inferred: why the compiler/runtime probably needs it;
- runtime claim: requires dynamic evidence and must not be asserted from the import table alone.

## Exercise

Choose three imports. For each, answer:

1. Which DLL supplies it?
2. Where is its import metadata represented?
3. Where does the loader place the resolved address?
4. Which code references it?
5. What can and cannot be concluded from that reference?

## Deliverable

Add an import map to your analysis report and cite the static evidence behind every behavioral inference.
