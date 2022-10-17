
//This File Belongs To The AT-Kernel Project
// Used In: ZeqOS EXT Project Extension, AtomOS
// Project License: Apache License 2.0
// Project: ZeqOS EXT
// ---------------------------------------KERNEL.CPP---------------------------------------


#include "types.h"

#include "gdt.h"

// #include "interrupts.h"


void printf(char* str)
{
	static uint16_t* VideoMemory = (uint16_t*)0xb8000;
	
	static uint8_t x=0 , y=0;

	for(int i = 0; str[i] != '\0'; ++i)
	{
		switch(str[i])
		{
			case '\n':
				
				y++;
				x = 0;
				break;
			default:
				VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | str[i];
				x++;
				break;
		}
		
		
		if(x >= 80)
		{
			y++;
			x = 0;
		}
		
		if(y >= 25)
		{
			for(y = 0; y < 25; y++)
				for(x = 0; x < 80; x++)
					VideoMemory[80*y+x] = (VideoMemory[80*y+x] & 0xFF00) | ' ';
			
			x = 0, y = 0;
		}
	}
}



typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for (constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}



// im tired of extern "C" like what?
extern "C" void kernelMain(const void* multiboot_structure, uint32_t magicnumber)
{
	printf("-----\n");
	printf("   / \n");
	printf("  / \n");
	printf(" ----- \n");
	printf("Apache License 2.0 \n");
	printf("Welcome To ZeqOS-Project-OS-Extension-16.05! \n");

	GlobalDescriptorTable gdt;

	while(1);
}
