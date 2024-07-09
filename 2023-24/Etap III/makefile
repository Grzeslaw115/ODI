GCC = gcc
CFLAGS = -std=gnu99 -static -O2 -s
LDFLAGS = -lm

all: zad1
.PHONY: clean

zad1: zad1.c
	$(GCC) $(CFLAGS) zad1.c -o zad1 $(LDFLAGS)

clean:	
	rm -f zad1

test: all
	@echo "Test 1"