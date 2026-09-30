CC ?= cc
WARN := -Wall -Wextra -Wpedantic
REVERSE_FLAGS := -fno-omit-frame-pointer -fno-inline
BUILD := build

.PHONY: all fixtures compiler-lab elf-lab static-lab dynamic-lab archaeology-lab structure-lab differential-lab defensive-lab hunk-lab hunk-reloc-lab case-01 case-02 clean

all: fixtures compiler-lab elf-lab static-lab dynamic-lab archaeology-lab structure-lab differential-lab defensive-lab hunk-lab hunk-reloc-lab case-01 case-02

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

clean:
	rm -rf $(BUILD)
