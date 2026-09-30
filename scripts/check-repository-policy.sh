#!/bin/sh
set -eu

fail=0

# Generated course binaries belong in build/, which is ignored.
# Keep reviewed source and text fixtures in Git; reject common executable/sample
# binary formats if they are committed elsewhere.
tracked="$(git ls-files)"

for f in $tracked; do
    case "$f" in
        *.exe|*.dll|*.sys|*.elf|*.bin|*.com|*.scr|*.so|*.dylib)
            echo "policy: committed binary/sample is not allowed: $f" >&2
            fail=1
            ;;
    esac
done

if [ "$fail" -ne 0 ]; then
    echo "Repository policy check FAILED." >&2
    exit 1
fi

echo "Repository policy check passed."
