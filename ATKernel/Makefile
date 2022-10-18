ASFLAGS=-f elf32
CC=i686-elf-g++
CPPFLAGS=-ffreestanding -Wall -Wextra -O2 -I./ -I./Libc/include -std=c++11 -fpermissive
AS=nasm

KERNEL=iso/boot/ZeqOSEXT.bin
LDFLAGS ?= -T linker.ld -ffreestanding

CPPFILES = $(shell find . -type f -name '*.cpp')
OBJ = $(CPPFILES:.cpp=.o)

ASFILES = $(shell find . -type f -name '*.asm')
ASOBJ = $(ASFILES:.asm=.o)

all: $(KERNEL)

$(KERNEL): $(OBJ) $(ASOBJ)
	$(CC) $(LDFLAGS) -o $@ $(ASOBJ) $(OBJ) -nostdlib -lgcc
	grub-mkrescue -o ZeqOSEXT.iso iso
	qemu-system-i386 -cdrom ZeqOSEXT.iso -serial stdio

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(KERNEL) $(OBJ) $(ASOBJ) ZeqOSEXT.iso
