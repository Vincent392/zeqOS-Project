
#include <gdt.hpp>

namespace GDT
{
	struct GDTEntry GDTTable[5];
	void init()
	{
		setGate(0, 0, 0, 0, 0);
		setGate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
		setGate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
		setGate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
		setGate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);

		struct GDTDescriptor GDTPointer;

		GDTPointer.limit = (sizeof(struct GDTEntry) * 5) - 1;
		GDTPointer.base = (uint32_t)&GDTTable;

		asm volatile ("lgdt %0" : : "m"(GDTPointer) : "memory");		
	}
	void setGate(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
	{
		GDTTable[num].base0 = (base & 0xFFFF);
		GDTTable[num].base1 = (base >> 16) & 0xFF;
		GDTTable[num].base2 = (base >> 24) & 0xFF;

		GDTTable[num].limit = (limit & 0xFFFF);

		GDTTable[num].granularity = (limit >> 16) & 0x0F;
		GDTTable[num].granularity |= (granularity & 0xF0);

		GDTTable[num].access = access;
	}

}