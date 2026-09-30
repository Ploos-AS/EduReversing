#!/usr/bin/env python3
"""Generate a tiny course-owned Amiga Hunk-style fixture.

Only generated output is binary. No AmigaOS/Kickstart/proprietary bytes are used.
"""
from pathlib import Path
import struct
import sys

HUNK_HEADER = 0x000003F3
HUNK_CODE = 0x000003E9
HUNK_END = 0x000003F2

# 68000 instructions:
#   moveq #42,d0
#   rts
CODE = bytes.fromhex("70 2a 4e 75")


def be32(value: int) -> bytes:
    return struct.pack(">I", value)


def build() -> bytes:
    out = bytearray()
    out += be32(HUNK_HEADER)
    out += be32(0)       # no resident library names
    out += be32(1)       # table size
    out += be32(0)       # first hunk
    out += be32(0)       # last hunk
    out += be32(1)       # hunk size: one longword

    out += be32(HUNK_CODE)
    out += be32(1)       # code length in longwords
    out += CODE
    out += be32(HUNK_END)
    return bytes(out)


def main() -> int:
    target = Path(sys.argv[1] if len(sys.argv) > 1 else "build/minimal.hunk")
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(build())
    print(target)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
