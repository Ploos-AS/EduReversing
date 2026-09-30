#!/bin/sh
set -eu

fail=0
tracked="$(git ls-files)"

reject() {
    echo "policy: committed binary/sample is not allowed: $1 ($2)" >&2
    fail=1
}

for f in $tracked; do
    case "$f" in
        *.exe|*.dll|*.sys|*.elf|*.bin|*.com|*.scr|*.so|*.dylib|*.hunk)
            reject "$f" "blocked extension"
            continue
            ;;
    esac

    [ -f "$f" ] || continue

    # Inspect content too: renaming a binary must not bypass repository policy.
    magic="$(od -An -tx1 -N4 "$f" 2>/dev/null | tr -d ' \n')"
    case "$magic" in
        7f454c46) reject "$f" "ELF magic" ;;
        4d5a*) reject "$f" "DOS/PE MZ magic" ;;
        000003f3) reject "$f" "Amiga HUNK_HEADER magic" ;;
    esac

    # Mach-O / fat Mach-O magics, both byte orders.
    case "$magic" in
        feedface|cefaedfe|feedfacf|cffaedfe|cafebabe|bebafeca)
            reject "$f" "Mach-O magic"
            ;;
    esac
done

if [ "$fail" -ne 0 ]; then
    echo "Repository policy check FAILED." >&2
    exit 1
fi

echo "Repository policy check passed."
