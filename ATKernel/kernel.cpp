
//This File Belongs To The AT-Kernel Project
// Used In: ZeqOS EXT Project Extension, AtomOS
// Project License: Apache License 2.0
// Project: ZeqOS EXT
// ---------------------------------------KERNEL.CPP---------------------------------------


#include <gdt.hpp>
#include <idt.hpp>
#include <stdio.hpp>
#include <multiboot.h>
#include <framebuffer.hpp>
#include <zeqos.hpp>

Graphics::Framebuffer fb;

// #include "interrupts.h"


/*typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for (constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}*/



// im tired of extern "C" like what?
extern "C" void kernelMain(multiboot_info_t *mbi, uint32_t magic, uintptr_t esp)
{
	fb.assign(mbi);
	printf("-----  \n");
	printf("   /   \n");
	printf("  /    \n");
	printf(" ----- \n");
	printf("Apache License 2.0\n");
	printf("Welcome To ZeqOS-Project-OS-Extension-16.05!\n");

	GDT::init();
	IDT::init();

	asm("int $0");

	for(;;) {
        asm("hlt");
    }
}
