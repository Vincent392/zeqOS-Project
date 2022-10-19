#pragma once

#include <stdint.h>
#include <isr.hpp>

/*
	Here is my explaination on what the IDT is.

	(Note: this is an insanely dumbed down explaination of what the IDT is, is it accurate? Absolutely not.)

	So, think of the IDT as a fat array of about, lets say 10 number of entries.

	Let me define some psuedocode for an array:

		IDT = [10]

	Each entry of that array, is basically a pointer to a function.

	More psuedocode:

		IDT[0] = func0()
		IDT[1] = func1()
		IDT[2] = func2()
		IDT[3] = func3()
		IDT[4] = func4()

	The IDTR basically just points to that array.
	
	Now, once you load the IDTR, the IDTR has the address and size of the IDT.
	Now, whenever an interrupt happens, the CPU knows where the IDT is and what the IDT's size is.
	With this information, it can jump to the function that handles it.

	In this implementations case that I have done, the functions are declared in the isr.hpp file.
	The isrh.asm defines which then takes care of them.

*/

namespace IDT
{
	/* 
		This is the IDT Entry Structure.
		This defines each entry in the IDT.

		How do I know this is what it's supposed to be? osdev wiki for the win!

		The reason why it's packed, is because structs by default are aligned different.

		See this for more information -> [https://en.wikipedia.org/wiki/Data_structure_alignment]

		Packing the struct removes the alignment, and essentially "packs" the struct.

		This is probably the worst explanation every, but oh well.

		Here is the page on the osdev wiki about the IDT -> [https://wiki.osdev.org/Interrupts_tutorial]
	*/
	struct [[gnu::packed]] IDTEntry
	{
		uint16_t base0;
		uint16_t selector;
		uint8_t zero;
		uint8_t flags; 
		uint16_t base1;
	};
	/*
		This is the IDT Descriptior, also known as the IDTR.

		I basically just call it the IDT pointer, since this is the structure the 'lidt' instruction expects.
		The limit is the size of the IDT, and the base being the address of the IDT.

		As per how the osdev wiki demonstates this -> [https://wiki.osdev.org/Interrupt_Descriptor_Table]

		Since this is 32-bit, we are using the 32-bit descriptor.

	*/
	struct [[gnu::packed]] IDTDescriptor
	{
		uint16_t limit;
		uint32_t base;
	};
	
	void init();
	void setEntry(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

}