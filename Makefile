CC ?= cc
PE_CC ?= x86_64-w64-mingw32-gcc
AARCH64_CC ?= aarch64-linux-gnu-gcc
M68K_CC ?= m68k-linux-gnu-gcc
WARN := -Wall -Wextra -Wpedantic
REVERSE_FLAGS := -fno-omit-frame-pointer -fno-inline
BUILD := build

.PHONY: all fixtures compiler-lab elf-lab static-lab dynamic-lab archaeology-lab structure-lab differential-lab defensive-lab hunk-lab hunk-reloc-lab case-01 case-02 capstone-m0 pe-lab case-pe-01 pe-library pe-resource-lab case-pe-02 capstone-m1 aarch64-lab m68k-lab case-aarch64-01 case-m68k-01 cross-isa-lab capstone-m2 clean

all: fixtures compiler-lab elf-lab static-lab dynamic-lab archaeology-lab structure-lab differential-lab defensive-lab hunk-lab hunk-reloc-lab case-01 case-02 capstone-m0 pe-lab case-pe-01 pe-library pe-resource-lab case-pe-02 capstone-m1 aarch64-lab m68k-lab case-aarch64-01 case-m68k-01 cross-isa-lab capstone-m2

fixtures: $(BUILD)/unknown-01

$(BUILD)/unknown-01: fixtures/src/unknown-01.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) $(REVERSE_FLAGS) -O1 -o $@ $<
	strip --strip-all $@

compiler-lab: $(BUILD)/compiler-lab-O0 $(BUILD)/compiler-lab-O1 $(BUILD)/compiler-lab-O2

$(BUILD)/compiler-lab-O0: fixtures/src/compiler-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) $(REVERSE_FLAGS) -O0 -o $@ $<

$(BUILD)/compiler-lab-O1: fixtures/src/compiler-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) $(REVERSE_FLAGS) -O1 -o $@ $<

$(BUILD)/compiler-lab-O2: fixtures/src/compiler-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) $(REVERSE_FLAGS) -O2 -o $@ $<

elf-lab: $(BUILD)/elf-lab

$(BUILD)/elf-lab: fixtures/src/elf-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

static-lab: $(BUILD)/static-lab

$(BUILD)/static-lab: fixtures/src/static-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -fno-omit-frame-pointer -o $@ $<

dynamic-lab: $(BUILD)/dynamic-lab

$(BUILD)/dynamic-lab: fixtures/src/dynamic-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O0 -g -fno-omit-frame-pointer -fno-inline -o $@ $<

archaeology-lab: $(BUILD)/archaeology-lab-O0 $(BUILD)/archaeology-lab-O1 $(BUILD)/archaeology-lab-O2

$(BUILD)/archaeology-lab-O0: fixtures/src/archaeology-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O0 -o $@ $<

$(BUILD)/archaeology-lab-O1: fixtures/src/archaeology-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -o $@ $<

$(BUILD)/archaeology-lab-O2: fixtures/src/archaeology-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O2 -o $@ $<

structure-lab: $(BUILD)/structure-lab

$(BUILD)/structure-lab: fixtures/src/structure-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

differential-lab: $(BUILD)/diff-v1 $(BUILD)/diff-v2

$(BUILD)/diff-v1: fixtures/src/diff-v1.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

$(BUILD)/diff-v2: fixtures/src/diff-v2.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

defensive-lab: $(BUILD)/defensive-lab

$(BUILD)/defensive-lab: fixtures/src/defensive-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

hunk-lab: $(BUILD)/minimal.hunk
	python3 tools/hunk_info.py $(BUILD)/minimal.hunk

$(BUILD)/minimal.hunk: tools/make_hunk_fixture.py
	mkdir -p $(BUILD)
	python3 tools/make_hunk_fixture.py $@

hunk-reloc-lab: $(BUILD)/reloc.hunk
	python3 tools/hunk_records.py $(BUILD)/reloc.hunk

$(BUILD)/reloc.hunk: tools/make_hunk_reloc_fixture.py
	mkdir -p $(BUILD)
	python3 tools/make_hunk_reloc_fixture.py $@

case-01: $(BUILD)/case-01

$(BUILD)/case-01: fixtures/src/case-01.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O2 -s -o $@ $<

case-02: $(BUILD)/case-02

$(BUILD)/case-02: fixtures/src/case-02.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O2 -s -o $@ $<

capstone-m0: $(BUILD)/capstone-m0

$(BUILD)/capstone-m0: fixtures/src/capstone-m0.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O2 -s -o $@ $<

pe-lab: $(BUILD)/pe-lab.exe

$(BUILD)/pe-lab.exe: fixtures/src/pe-lab.c
	mkdir -p $(BUILD)
	$(PE_CC) $(WARN) -O1 -fno-inline -o $@ $<

case-pe-01: $(BUILD)/case-pe-01.exe

$(BUILD)/case-pe-01.exe: fixtures/src/case-pe-01.c
	mkdir -p $(BUILD)
	$(PE_CC) $(WARN) -O2 -s -o $@ $<

pe-library: $(BUILD)/edu-reversing.dll

$(BUILD)/edu-reversing.dll: fixtures/src/pe-library.c
	mkdir -p $(BUILD)
	$(PE_CC) $(WARN) -O1 -shared -o $@ $<

pe-resource-lab: $(BUILD)/pe-resource-lab.exe

$(BUILD)/pe-resource-lab.exe: fixtures/src/pe-resource-lab.c fixtures/src/pe-resource.rc
	mkdir -p $(BUILD)
	x86_64-w64-mingw32-windres fixtures/src/pe-resource.rc -O coff -o $(BUILD)/pe-resource.res
	$(PE_CC) $(WARN) -O1 -o $@ fixtures/src/pe-resource-lab.c $(BUILD)/pe-resource.res

case-pe-02: $(BUILD)/case-pe-02.exe

$(BUILD)/case-pe-02.exe: fixtures/src/case-pe-02.c fixtures/src/case-pe-02.rc
	mkdir -p $(BUILD)
	x86_64-w64-mingw32-windres fixtures/src/case-pe-02.rc -O coff -o $(BUILD)/case-pe-02.res
	$(PE_CC) $(WARN) -O2 -s -o $@ fixtures/src/case-pe-02.c $(BUILD)/case-pe-02.res

capstone-m1: $(BUILD)/capstone-m1.exe

$(BUILD)/capstone-m1.exe: fixtures/src/capstone-m1.c fixtures/src/capstone-m1.rc
	mkdir -p $(BUILD)
	x86_64-w64-mingw32-windres fixtures/src/capstone-m1.rc -O coff -o $(BUILD)/capstone-m1.res
	$(PE_CC) $(WARN) -O2 -s -o $@ fixtures/src/capstone-m1.c $(BUILD)/capstone-m1.res

aarch64-lab: $(BUILD)/aarch64-lab

$(BUILD)/aarch64-lab: fixtures/src/aarch64-lab.c
	mkdir -p $(BUILD)
	$(AARCH64_CC) $(WARN) -O1 -fno-inline -o $@ $<

m68k-lab: $(BUILD)/m68k-lab

$(BUILD)/m68k-lab: fixtures/src/m68k-lab.c
	mkdir -p $(BUILD)
	$(M68K_CC) $(WARN) -O1 -fno-inline -o $@ $<

case-aarch64-01: $(BUILD)/case-aarch64-01

$(BUILD)/case-aarch64-01: fixtures/src/case-aarch64-01.c
	mkdir -p $(BUILD)
	$(AARCH64_CC) $(WARN) -O2 -s -o $@ $<

case-m68k-01: $(BUILD)/case-m68k-01

$(BUILD)/case-m68k-01: fixtures/src/case-m68k-01.c
	mkdir -p $(BUILD)
	$(M68K_CC) $(WARN) -O2 -s -o $@ $<

cross-isa-lab: $(BUILD)/cross-isa-x86_64 $(BUILD)/cross-isa-aarch64 $(BUILD)/cross-isa-m68k

$(BUILD)/cross-isa-x86_64: fixtures/src/cross-isa-lab.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O1 -fno-inline -o $@ $<

$(BUILD)/cross-isa-aarch64: fixtures/src/cross-isa-lab.c
	mkdir -p $(BUILD)
	$(AARCH64_CC) $(WARN) -O1 -fno-inline -o $@ $<

$(BUILD)/cross-isa-m68k: fixtures/src/cross-isa-lab.c
	mkdir -p $(BUILD)
	$(M68K_CC) $(WARN) -O1 -fno-inline -o $@ $<

capstone-m2: $(BUILD)/capstone-m2-x86_64 $(BUILD)/capstone-m2-aarch64 $(BUILD)/capstone-m2-m68k

$(BUILD)/capstone-m2-x86_64: fixtures/src/capstone-m2.c
	mkdir -p $(BUILD)
	$(CC) $(WARN) -O2 -s -o $@ $<

$(BUILD)/capstone-m2-aarch64: fixtures/src/capstone-m2.c
	mkdir -p $(BUILD)
	$(AARCH64_CC) $(WARN) -O2 -s -o $@ $<

$(BUILD)/capstone-m2-m68k: fixtures/src/capstone-m2.c
	mkdir -p $(BUILD)
	$(M68K_CC) $(WARN) -O2 -s -o $@ $<

clean:
	rm -rf $(BUILD)
