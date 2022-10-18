; Declare constants for the multiboot header. 
MALIGN     equ     1<<0              ; align loaded modules on page boundaries 
MEMINFO    equ     1<<1              ; provide memory map 
GFX		   equ 	   1<<2
FLAGS      equ     MALIGN | MEMINFO | GFX ; this is the Multiboot 'flag' field 
MAGIC      equ     0x1BADB002        ; 'magic number' lets bootloader find the header 
CHECKSUM   equ     -(MAGIC + FLAGS)  ; checksum of above, to prove we are multiboot 

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM
	; This is used for the framebuffer provided by GRUB
	dd 0
	dd 0
	dd 0
	dd 0
	dd 0
	dd 0
	dd 1024
	dd 768
	dd 32

section .bss
align 16
stack_bottom:
    resb 16384 ; 16 KiB
stack_top:

section .text
global _start
extern kernelMain
_start:
	
	mov esp, stack_top
	
	push eax
	push ebx
	
	call kernelMain
	
	cli
    hlt

loop:	
	jmp loop