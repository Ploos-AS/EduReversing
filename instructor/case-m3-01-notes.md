# Instructor notes — Case 10

The binary is benign and does not access files, spawn processes, resolve DNS or create network traffic.

Input: exactly one argument of length >= 3. Exit 2 for wrong argc; 3 for short input.

The configuration bytes are XOR 0x5a and decode to:
`server=demo.invalid;mode=report;`

Token:
- x starts 0x6d330001
- index starts 1
- x ^= byte + index * 0x1021
- rol32(x, 5)
- increment index

The decoy string `debug sandbox trace persistence` is deliberately embedded but the branch printing it is unreachable under the C abstract-machine value of the static string. Students should not promote those words to behavioral indicators.

Incident 02 is synthetic correlation material. The binary itself provides no evidence of process creation, file reads, DNS or networking. Strong reports explicitly separate bundle observations from binary capabilities.
