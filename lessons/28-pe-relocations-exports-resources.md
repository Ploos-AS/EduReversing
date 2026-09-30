# Lesson 28 — PE relocations, exports and resources

## Mission

Extend the PE load model beyond sections and imports. Analyze three loader-visible mechanisms: base relocations, exports and resources.

## Base relocations

The preferred image base is not a promise that the loader will use that address. Find the base-relocation directory and explain why absolute addresses may need adjustment when an image is loaded elsewhere.

Record:

- preferred ImageBase;
- relocation-directory RVA and size;
- relocation blocks and entry types visible in the fixture;
- the relationship between ASLR and relocation information.

Do not confuse PE base relocations with imported-symbol resolution.

## Exports

Build the course DLL with:

```sh
make pe-library
```

Inspect `build/edu-reversing.dll`. Recover the export directory and identify `edu_mix` and `edu_class`.

For each export, distinguish its name, ordinal and RVA. Follow one RVA into executable code and document the mapping through the section table.

## Resources

Build the resource-bearing executable:

```sh
make pe-resource-lab
```

Inspect the resource directory of `build/pe-resource-lab.exe`. Locate the course-owned string resource and explain why resources are structured data rather than ordinary executable code.

## Analyst questions

1. Which PE structures are primarily consumed by the loader?
2. Which are useful metadata for analysts but do not prove runtime behavior?
3. How does an RVA in an export table become a virtual address?
4. Why can resources contain interesting strings without those strings being referenced by ordinary code?

## Deliverable

Add relocation, export and resource sections to your evidence ledger. Include at least one RVA-to-section mapping for each applicable structure.
