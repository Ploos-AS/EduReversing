CC ?= cc
CFLAGS ?= -O1 -fno-omit-frame-pointer -fno-inline -Wall -Wextra -Wpedantic
BUILD := build

.PHONY: all fixtures clean

all: fixtures

fixtures: $(BUILD)/unknown-01

$(BUILD)/unknown-01: fixtures/src/unknown-01.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $<
	strip --strip-all $@

clean:
	rm -rf $(BUILD)
