# Instructor notes — M3 capstone

Both programs are benign.

Profiles: IDs 41, 73, 109 with identical record data in both versions.

Common ticket basis:
- x = key ^ (seed << 8)
- index begins 1
- add signed bias to each byte
- XOR transformed byte plus index multiplier
- rotate by profile rot
- final XOR with ID

Semantic update: multiplier basis changes from `0x1021 + lane` in v1 to `0x2043 + lane` in v2.

Presentation update: success prefix changes from `state=ok` to `state=revised`.

Encoded configuration uses XOR 0x5a. v1 decodes to `server=demo.invalid;mode=report;`. v2 decodes to `server=demo.invalid;mode=strict;`.

The decoy string is not evidence of sandbox/debugger detection or persistence. Neither executable implements filesystem, process creation, DNS or networking.

Exit classes: 2 wrong argc, 3 malformed/range/short message, 4 unknown ID, 0 success.
