# Lesson 36 — Recovering structures and message formats

## Mission

Recover an undocumented binary message format from parser behavior and controlled inputs.

The course fixture accepts one hexadecimal string. Treat the format as unknown.

## Workflow

Begin with failure classification. Change one property at a time:

- total encoded length;
- individual header bytes;
- candidate length fields;
- multi-byte values;
- payload bytes;
- trailing bytes.

Record which changes alter the exit class. Use those boundaries to propose fields before naming them.

## Static work

Find the decode loop and parser checks. Recover:

- fixed header size;
- magic bytes;
- version/type field;
- payload-length field;
- sequence field width and byte order;
- payload extent;
- integrity field location;
- integrity algorithm.

Do not call a field a checksum merely because it is near the end. Demonstrate how it is calculated and compared.

## Dynamic work

`tools/make_protocol_fixture.py` prints one valid course-owned message. Use it only after making an initial static map.

Mutate one byte or field at a time and record the resulting exit class. Then create a second valid message yourself by recomputing the integrity value.

## Deliverable

Produce a byte-level format diagram with offsets, widths, byte order and confidence for every field. Include pseudocode for validation and integrity checking.

The lesson is complete when another analyst can construct a valid message from your recovered specification without reading the fixture source.
