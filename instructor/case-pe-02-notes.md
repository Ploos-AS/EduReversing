# Instructor notes — Case File 05

## Intended findings

Input is `ID TEXT`.

Exit behavior:

- 2: wrong argument count;
- 3: invalid/out-of-range ID text or empty TEXT;
- 4: syntactically valid but unknown ID, with `status=unknown`;
- 0: recognized profile.

Valid IDs: 101, 205, 309, 417.

The repeated profile contains, in source order:

- uint16 id;
- int16 bias;
- uint8 rotate;
- uint8 lane;
- uint16 salt;
- uint32 key.

Students should infer layout from access widths, offsets and stride rather than source syntax.

Digest semantics:

1. `x = key ^ salt`;
2. for each input byte at index i:
   - `v = byte + signed bias`;
   - `x ^= v + i * (lane + 1)`;
   - rotate x left by profile.rotate;
3. `x ^= id << 16`.

Output is `status=ok lane=<lane> token=<8 hex digits>`.

## Deliberate noise

`training-marker:PE-CASE-05` is retained in the executable but its print path is unreachable during normal execution.

The resource strings `EduReversing Case 05 training resource` and `telemetry.example.invalid` live in the PE resource tree and are not consulted by normal program logic.

Students should not infer networking from the reserved/example telemetry string.

## ABI

Reward a correctly evidenced Windows x64 call reconstruction using RCX/RDX/R8/R9 and awareness of caller shadow space. Do not require textbook prologues in optimized code.

## Assessment emphasis

The main skill is evidence triage: distinguish file-format metadata, compiler/runtime machinery, inert embedded data and actual program behavior.
