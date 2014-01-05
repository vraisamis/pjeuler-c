vpath %.c $(SourceDir)
vpath %.h $(HeaderDir)
vpath %.o .

SourceDir := src
HeaderDir := hdr
ObjectDir := .
Objects := $(patsubst src/%.c,%.o,$(wildcard src/*.c))


.PHONY:all
all: $(Objects)


$(ObjectDir)/%.o: $(SourceDir)/%.c $(HeaderDir)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<


$(ObjectDir)/gen.o: $(SourceDir)/gen.c $(HeaderDir)/gen.h
	$(CC) $(CFLAGS) -c -o $@ $< -lm

