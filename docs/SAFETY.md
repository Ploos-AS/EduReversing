# Safety and Lab Policy

EduReversing is a defensive reverse-engineering and malware-analysis course.

## Repository rule

**Real malware must never be committed to this repository.**

This includes live payloads, droppers, ransomware, credential stealers, worms, botnet clients, exploit kits, or other executable malicious samples.

Course material must remain safe to clone, inspect and build on an ordinary development machine.

## Allowed teaching material

The course may use:

- benign binaries written specifically for the course;
- small C/C++ programs compiled with different optimization settings;
- synthetic samples that imitate observable malware-analysis patterns without performing harmful actions;
- inert byte fixtures;
- encoded or packed benign payloads;
- generated PE/ELF fixtures;
- mock network indicators using reserved/example domains and addresses;
- deliberately stripped binaries;
- old or unusual benign executables used for format study;
- diff pairs representing harmless software updates.

## Isolation principles

Students should learn the following workflow before the defensive-malware modules:

1. preserve the original sample;
2. calculate hashes;
3. record provenance;
4. work on a copy;
5. use snapshots or disposable machines for dynamic analysis;
6. isolate networking unless network access is explicitly required by a safe lab;
7. never expose personal credentials or production data to an analysis environment;
8. document all environment assumptions.

## Network exercises

Network-related labs must use controlled endpoints, local fixtures, loopback, private lab networks, or documentation-reserved names and addresses.

Labs must not instruct students to contact real command-and-control infrastructure or unrelated third-party systems.

## Analysis versus development

The malware section teaches analysts to recognize and understand behaviors such as persistence, packing, configuration storage, process interaction and anti-analysis concepts.

Labs should be structured around observation, reconstruction and reporting rather than development of harmful payloads.

## Sample generation

Where a lab needs a binary with particular characteristics, prefer a reproducible generator or benign source program. Generated artifacts should be easy to rebuild and verify.

## Reporting

Students should distinguish:

- directly observed facts;
- deductions supported by evidence;
- hypotheses requiring verification;
- unknowns.

This discipline is part of the safety model as well as the technical curriculum.
