CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -nostdinc -nostdlib -no-pie -m32
AS = nasm
ASFLAGS = -f elf32

.DEFAULT_GOAL: all

.PHONY: all clean

all: name

name: name.o start.o puts.o
	cc -fno-PIC -m32 -g -c -o name.o name.c
	nasm -f elf32 -o start.o start.asm
	nasm -f elf32 -o puts.o puts.asm
	cc -nostdinc -nostdlib -no-pie -m32 name.o start.o puts.o -o name

name.o: name.c

start.o: start.asm
	$(AS) $(ASFLAGS) -o $@ $<

puts.o: puts.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	-rm -f name name.o start.o puts.o
	-rm -f *~
