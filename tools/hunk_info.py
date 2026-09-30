#!/usr/bin/env python3
"""Small educational parser for the EduReversing minimal Hunk fixture."""
from pathlib import Path
import struct
import sys

NAMES = {
    0x000003F3: "HUNK_HEADER",
    0x000003E9: "HUNK_CODE",
    0x000003F2: "HUNK_END",
}


class Reader:
    def __init__(self, data: bytes):
        self.data = data
        self.off = 0

    def u32(self) -> int:
        if self.off + 4 > len(self.data):
            raise ValueError("truncated input")
        value = struct.unpack_from(">I", self.data, self.off)[0]
        self.off += 4
        return value

    def take(self, n: int) -> bytes:
        if self.off + n > len(self.data):
            raise ValueError("truncated input")
        value = self.data[self.off:self.off+n]
        self.off += n
        return value


def parse(path: Path) -> None:
    r = Reader(path.read_bytes())

    kind = r.u32()
    if kind != 0x000003F3:
        raise ValueError("not the expected HUNK_HEADER")

    resident_names = r.u32()
    if resident_names != 0:
        raise ValueError("fixture parser expects no resident names")

    table_size = r.u32()
    first = r.u32()
    last = r.u32()
    print(f"HUNK_HEADER table={table_size} first={first} last={last}")

    count = last - first + 1
    sizes = [r.u32() & 0x3fffffff for _ in range(count)]
    print("HUNK_SIZES " + ",".join(str(x) for x in sizes))

    kind = r.u32()
    if kind != 0x000003E9:
        raise ValueError("expected HUNK_CODE")

    longs = r.u32()
    code = r.take(longs * 4)
    print(f"HUNK_CODE longs={longs} bytes={code.hex()}")

    kind = r.u32()
    if kind != 0x000003F2:
        raise ValueError("expected HUNK_END")
    print("HUNK_END")

    if r.off != len(r.data):
        raise ValueError("trailing data")


def main() -> int:
    if len(sys.argv) != 2:
        print("usage: hunk_info.py FILE", file=sys.stderr)
        return 2
    try:
        parse(Path(sys.argv[1]))
    except (OSError, ValueError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
