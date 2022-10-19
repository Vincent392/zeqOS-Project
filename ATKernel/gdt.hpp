#pragma once

#include <stdint.h>

/* 
	Why did I change this? Well, 2 reasons.
	I felt it was unnecessary to have an entire class just for the GDT.
	
	Typically, the GDT is a struct, not an entire class.
	This wouldn't be an issue, but to me this kinda seems a wonky way to do it.

	I am open for this change to be reversed, however, I feel like this is very unconventional to do, and it seems a bit odd.
	Not that the solution doesn't work, just that it's a bit weird.

	Along with that, the corresponding .cpp file with this, the code in it is a bit weird.

	Maybe it's because I code in C more than I do in C++, so the whole concept of classes is still something I am a still naive about.
	- xyve
*/

namespace GDT
{
	/* 
		This is the GDT Entry Structure.
		This defines each entry in the GDT.

		How do I know this is what it's supposed to be? osdev wiki for the win!

		The reason why it's packed, is because structs by default are aligned different.

		See this for more information -> [https://en.wikipedia.org/wiki/Data_structure_alignment]

		Packing the struct removes the alignment, and essentially "packs" the struct.

		This is probably the worst explanation every, but oh well.

		Here is the page on the osdev wiki about the GDT -> [https://wiki.osdev.org/GDT_Tutorial]
	*/
	struct [[gnu::packed]] GDTEntry
	{
		uint16_t limit;
		uint16_t base0;
		uint8_t base1;
		uint8_t access;
		uint8_t granularity;
		uint8_t base2;
	};
	/*
		This is the GDT Descriptior, also known as the GDTR.

		I basically just call it the GDT pointer, since this is the structure the 'lgdt' instruction expects.
		The limit is the size of the GDT, and the base being the address of the GDT.

		As per how the osdev wiki demonstates this -> [https://wiki.osdev.org/Global_Descriptor_Table]

		Since this is 32-bit, we are using the 32-bit descriptor.

	*/
	struct [[gnu::packed]] GDTDescriptor
	{
		uint16_t limit;
		uint32_t base;
	};

	void init();
	void setEntry(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

}
