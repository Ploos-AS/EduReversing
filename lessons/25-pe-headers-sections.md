# Lesson 25 — PE headers, sections and the load map

## Mission

Turn `build/pe-lab.exe` from a sequence of bytes into a load map you can explain.

## Header chain

Start at the DOS header. Record the `MZ` signature and the `e_lfanew` value that points to the PE signature. At that location identify:

- `PE\0\0`;
- the COFF file header;
- the PE32+ optional header;
- the section table.

Do not confuse the historical DOS header/stub with the native Windows program entry point.

## File versus memory

For each section, record:

| Section | Raw offset | Raw size | RVA | Virtual size | Characteristics |
| --- | ---: | ---: | ---: | ---: | --- |

Then explain why a raw file offset is not an RVA and why an RVA is not normally a process virtual address by itself.

Use:

`VA = ImageBase + RVA`

as the starting model, while remembering that relocation can change the actual image base.

## Important optional-header fields

Locate and explain:

- AddressOfEntryPoint;
- ImageBase;
- SectionAlignment;
- FileAlignment;
- SizeOfImage;
- SizeOfHeaders;
- Subsystem;
- NumberOfRvaAndSizes.

For each field, state whether it primarily describes disk layout, loader layout or execution.

## Data directories

Find the data-directory entries. In this fixture, pay particular attention to imports, exceptions and base relocations when present.

A data-directory entry is not necessarily a file offset. Resolve its RVA through the section map.

## Deliverable

Produce a compact load map plus three worked conversions:

1. raw offset -> containing section -> RVA;
2. RVA -> containing section -> raw offset;
3. RVA -> virtual address using the preferred image base.

Every conversion must show the arithmetic.
