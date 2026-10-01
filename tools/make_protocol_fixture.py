#!/usr/bin/env python3
# SPDX-License-Identifier: MIT
import sys

def checksum(data):
    s = 0x1234
    for b in data:
        s = (((s << 5) | (s >> 11)) & 0xffff) ^ b
    return s

payload = b"REV"
seq = 0x2345
msg = bytearray([0x45, 0x52, 1, len(payload), seq >> 8, seq & 0xff])
msg += payload
c = checksum(msg)
msg += bytes([c >> 8, c & 0xff])
print(msg.hex())
