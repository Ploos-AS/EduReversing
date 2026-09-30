# EduReversing student environment

The course provides a standalone Debian Bookworm based OCI environment. You do not need Ploos infrastructure to complete the command-line course labs.

## Build

From the repository root:

```sh
docker build -t edureversing-student:m0 -f student/Dockerfile .
```

## Run

Mount the repository as the working directory:

```sh
docker run --rm -it -v "$PWD:/work" edureversing-student:m0
```

Inside the container:

```sh
make all
```

The image includes GCC/G++, binutils/multiarch tools, GDB, strace, ltrace, NASM/YASM, Python, common command-line utilities and a pinned radare2 6.2.2 build.

## GUI tools

Ghidra and Cutter are useful optional host-side tools. They are not required for the baseline OCI smoke test and are intentionally not bundled into the command-line student image.

## First exercise

Start with:

```text
lessons/01-first-look.md
```

Then progress through the lessons before attempting `cases/`.

## Safety

Only execute binaries that the course explicitly identifies as generated benign fixtures. The repository does not distribute real malware.

Generated binaries live under `build/` and are not committed.
