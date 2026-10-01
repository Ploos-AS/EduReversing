#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
from pathlib import Path
import sys

p = Path(sys.argv[1] if len(sys.argv) > 1 else "fixtures/incident-01/config.dat")
raw = bytes.fromhex(p.read_text().strip())
if len(raw) < 6 or raw[:4] != b"ERCF":
    raise SystemExit("invalid container")
version, kind = raw[4], raw[5]
length = int.from_bytes(raw[6:8], "big")
payload = raw[8:]
if len(payload) != length:
    raise SystemExit("length mismatch")
print(f"magic=ERCF version={version} kind={kind} length={length}")
print(payload.decode("ascii"))
