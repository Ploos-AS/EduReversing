# Lesson 09 — System and library tracing

## Mission

Observe the boundary between a program and its runtime environment.

## strace

For this known-safe fixture:

```sh
strace -o build/dynamic-lab.strace ./build/dynamic-lab 17
less build/dynamic-lab.strace
```

Identify:

- process startup noise;
- file-related operations;
- memory-management operations;
- output;
- process termination.

Do not confuse a libc function with a system call. The layers are related but not identical.

## Focus the trace

Use filters to reduce noise when appropriate. Consult your installed `strace` help/manual because syntax can vary by version.

The analytical question should choose the filter. Do not filter merely to make the trace shorter.

## ltrace

Where supported by the binary/toolchain:

```sh
ltrace ./build/dynamic-lab 17
```

Compare library-level observations with system-call observations.

Questions:

1. Which operations appear in both views?
2. Which library calls result in several syscalls?
3. Which library calls may not need a syscall?
4. What useful behavior is invisible to both approaches because it happens entirely inside ordinary instructions?

## Correlate three views

For one output operation, connect:

```text
disassembly / call site
        |
        v
library-level behavior
        |
        v
system-call-level behavior
```

Then state what each layer can and cannot establish.

## Safety note

Tracing executes the target. In this course, only execute fixtures explicitly supplied as benign course programs. Analysis of genuinely untrusted specimens requires a dedicated isolated workflow beyond this introductory lab.

## Deliverable

Produce a short timeline containing:

- relevant code location;
- library interaction where visible;
- syscall interaction;
- resulting observable effect.

## Principle

**Choose the observation layer that answers the question you actually have.**
