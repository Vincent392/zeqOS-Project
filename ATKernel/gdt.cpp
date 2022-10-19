
#include <gdt.hpp>

namespace GDT
{
	/* 
		This is the actual GDT.
		It's just an array of the GDT entries.


	*/
	struct GDTEntry GDTTable[5];
	
	void init()
	{
		/*
			This sets all of the GDT entries.

			The first parameter is which element of the array you're assigning.
			The second parameter is the base.
			The third parameter is the limit.
			The fourth parameter is the access.
			The fifth parameter is the granularity.

			As for what this does? I'm gonna be honest, I have no clue.

			For more information about this, click here -> [https://wiki.osdev.org/GDT_Tutorial]
		*/
		/*
			The first entry of the GDT is ALWAYS NULL
		*/
		setEntry(0, 0, 0, 0, 0);
		/*
			This defines the Kernel Mode Code Segment.
		*/
		setEntry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
		/*
			This defines the Kernel Mode Data Segment.
		*/
		setEntry(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
		/*
			This defines the User Mode Code Segment.
		*/
		setEntry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
		/*
			This defines the User Mode Data Segment.
		*/
		setEntry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

		/*
			If you remember, this is the GDT Descriptor.
			This kinda points to the GDT.
		*/
		struct GDTDescriptor GDTPointer;

		/*
			The limit is pretty much the size of the GDT minus 1;
		*/
		GDTPointer.limit = (sizeof(struct GDTEntry) * 5) - 1;
		/*
			The base is the address of the GDT.
		*/
		GDTPointer.base = (uint32_t)&GDTTable;
		/*
			Finally, it loads the GDT.
		*/
		asm volatile ("lgdt %0" : : "m"(GDTPointer) : "memory");		
	}
	void setEntry(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
	{
		/*
			This just sets all of the base and limits and stuff, I don't think I need to get into that.
		*/
		GDTTable[num].base0 = (base & 0xFFFF);
		GDTTable[num].base1 = (base >> 16) & 0xFF;
		GDTTable[num].base2 = (base >> 24) & 0xFF;

		GDTTable[num].limit = (limit & 0xFFFF);

		GDTTable[num].granularity = (limit >> 16) & 0x0F;
		GDTTable[num].granularity |= (granularity & 0xF0);

		GDTTable[num].access = access;
	}

}