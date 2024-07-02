GCC = gcc
CFLAGS = -std=gnu99 -static -O2 -s
LDFLAGS = -lm

all: zad1 zad2 zad3 zad4 zad5
.PHONY: clean

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