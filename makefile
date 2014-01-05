vpath %.o util

.PHONY: all
all:
	@echo "##Target not found##"

004: 004.o string.o
	$(CC) -o $@ $+

005: 005.o gen.o
	$(CC) -o $@ $+

007: 007.o gen.o
	$(CC) -o $@ $+

008: 008.o slinklist.o gen.o
	$(CC) -o $@ $+

010: 010.o gen.o
	$(CC) -o $@ $+

