# Case File 08 — Unknown m68k ELF

Primary evidence is `build/case-m68k-01`. Source and instructor notes remain sealed during the investigation.

Establish:

- ELF class, machine and byte order;
- runtime scaffolding versus application logic;
- argument grammar and failure classes;
- valid numeric codes;
- repeated record layout with field widths and signedness;
- how big-endian representation affects manual decoding;
- record lookup;
- digest transformation and final class calculation;
- stack/call evidence and return-value handling;
- effective-address forms that reveal structure access.

Use the standard evidence labels and distinguish observations from hypotheses.

Static analysis must support the conclusions. QEMU user-mode execution is permitted as a controlled oracle after a prediction has been written.

Stop when another analyst can reproduce the failure paths and predict valid output without source access.
