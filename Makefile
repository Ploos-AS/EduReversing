CC ?= cc
WARN := -Wall -Wextra -Wpedantic
REVERSE_FLAGS := -fno-omit-frame-pointer -fno-inline
BUILD := build

.PHONY: all fixtures compiler-lab clean

all: fixtures compiler-lab

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

clean:
	rm -rf $(BUILD)
