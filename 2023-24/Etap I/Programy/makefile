GCC = gcc
CFLAGS = -std=gnu99 -static -O2 -s
LDFLAGS = -lm

all: zad1 zad2 zad3 zad4 zad5
.PHONY: clean test

zad1: zad1.c
	$(GCC) $(CFLAGS) zad1.c $(LDFLAGS) -o zad1

zad2: zad2.c
	$(GCC) $(CFLAGS) zad2.c $(LDFLAGS) -o zad2

zad3: zad3.c
	$(GCC) $(CFLAGS) zad3.c $(LDFLAGS) -o zad3

zad4: zad4.c
	$(GCC) $(CFLAGS) zad4.c $(LDFLAGS) -o zad4

zad5: zad5.c
	$(GCC) $(CFLAGS) zad5.c $(LDFLAGS) -o zad5

clean:
	rm -f zad1 zad2 zad3 zad4 zad5

test: all
	@echo "Test 1"
	@echo 4 | ./zad1
	@echo "Test 2"
	@echo "4\n9" | ./zad2
	@echo "Test 3"
	@echo "ocena" | ./zad3
	@echo "Test 4"
	@echo "8\n12\n8\n4\n13\n5\n9\n2\n8" | ./zad4
	@echo "Test 5"
	@echo "7\n5\n2\n0 5 1 8 0 0 0\n5 0 0 1 0 8 0\n1 0 0 8 0 0 8\n8 1 8 0 5 0 1\n0 0 0 5 0 1 0\n0 8 0 0 1 0 5\n0 0 8 1 0 5 0" | ./zad5