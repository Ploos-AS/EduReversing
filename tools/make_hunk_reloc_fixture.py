#!/usr/bin/env python3
"""Generate a course-owned multi-hunk fixture with relocation and a symbol."""
from pathlib import Path
import struct
import sys

HUNK_HEADER=0x3F3; HUNK_CODE=0x3E9; HUNK_DATA=0x3EA
HUNK_BSS=0x3EB; HUNK_RELOC32=0x3EC; HUNK_SYMBOL=0x3F0; HUNK_END=0x3F2

def u32(x): return struct.pack(">I", x)

def name(s):
    raw=s.encode("ascii")
    raw += b"\0" * ((4-len(raw)%4)%4)
    return u32(len(raw)//4)+raw

def build():
    b=bytearray()
    b += u32(HUNK_HEADER)+u32(0)+u32(3)+u32(0)+u32(2)
    b += u32(2)+u32(1)+u32(2)  # CODE=8 bytes, DATA=4, BSS=8

    b += u32(HUNK_CODE)+u32(2)
    b += bytes.fromhex("20 7c 00 00 00 00 4e 75") # MOVEA.L #relocated,A0 ; RTS
    b += u32(HUNK_RELOC32)+u32(1)+u32(1)+u32(2)+u32(0)
    b += u32(HUNK_SYMBOL)+name("entry")+u32(0)+u32(0)
    b += u32(HUNK_END)

    b += u32(HUNK_DATA)+u32(1)+bytes.fromhex("12 34 56 78")+u32(HUNK_END)
    b += u32(HUNK_BSS)+u32(2)+u32(HUNK_END)
    return bytes(b)

def main():
    p=Path(sys.argv[1] if len(sys.argv)>1 else "build/reloc.hunk")
    p.parent.mkdir(parents=True,exist_ok=True); p.write_bytes(build()); print(p)
if __name__=="__main__": main()
