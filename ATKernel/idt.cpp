#include <idt.hpp>

namespace IDT
{
	/*
		Just like the GDT, this is the IDT.
		Same way the GDT is defined, just bigger.
	*/
	struct IDTEntry IDTTable[256];
	
	void init()
	{
		/* 
			Sets the first 32 IDT gates, which are exceptions

			The first parameter is which element of the array you're assigning.
			The second parameter is the base.
			The third parameter is the selector.
			The fourth parameter is the flags.

			The base is just the function that defined.

			Whenever a CPU exception happens, the CPU will jump to that function.

			As for the flags and selectors, no clue.
		*/
		setEntry(0, (uint32_t)ISR::isr0, 0x08, 0x8E);
		setEntry(1, (uint32_t)ISR::isr1, 0x08, 0x8E);
		setEntry(2, (uint32_t)ISR::isr2, 0x08, 0x8E);
		setEntry(3, (uint32_t)ISR::isr3, 0x08, 0x8E);
		setEntry(4, (uint32_t)ISR::isr4, 0x08, 0x8E);
		setEntry(5, (uint32_t)ISR::isr5, 0x08, 0x8E);
		setEntry(6, (uint32_t)ISR::isr6, 0x08, 0x8E);
		setEntry(7, (uint32_t)ISR::isr7, 0x08, 0x8E);
		setEntry(8, (uint32_t)ISR::isr8, 0x08, 0x8E);
		setEntry(9, (uint32_t)ISR::isr9, 0x08, 0x8E);
		setEntry(10, (uint32_t)ISR::isr10, 0x08, 0x8E);
		setEntry(11, (uint32_t)ISR::isr11, 0x08, 0x8E);
		setEntry(12, (uint32_t)ISR::isr12, 0x08, 0x8E);
		setEntry(13, (uint32_t)ISR::isr13, 0x08, 0x8E);
		setEntry(14, (uint32_t)ISR::isr14, 0x08, 0x8E);
		setEntry(15, (uint32_t)ISR::isr15, 0x08, 0x8E);
		setEntry(16, (uint32_t)ISR::isr16, 0x08, 0x8E);
		setEntry(17, (uint32_t)ISR::isr17, 0x08, 0x8E);
		setEntry(18, (uint32_t)ISR::isr18, 0x08, 0x8E);
		setEntry(19, (uint32_t)ISR::isr19, 0x08, 0x8E);
		setEntry(20, (uint32_t)ISR::isr20, 0x08, 0x8E);
		setEntry(21, (uint32_t)ISR::isr21, 0x08, 0x8E);
		setEntry(22, (uint32_t)ISR::isr22, 0x08, 0x8E);
		setEntry(23, (uint32_t)ISR::isr23, 0x08, 0x8E);
		setEntry(24, (uint32_t)ISR::isr24, 0x08, 0x8E);
		setEntry(25, (uint32_t)ISR::isr25, 0x08, 0x8E);
		setEntry(26, (uint32_t)ISR::isr26, 0x08, 0x8E);
		setEntry(27, (uint32_t)ISR::isr27, 0x08, 0x8E);
		setEntry(28, (uint32_t)ISR::isr28, 0x08, 0x8E);
		setEntry(29, (uint32_t)ISR::isr29, 0x08, 0x8E);
		setEntry(30, (uint32_t)ISR::isr30, 0x08, 0x8E);
		setEntry(31, (uint32_t)ISR::isr31, 0x08, 0x8E);

		struct IDTDescriptor IDTPointer;

		IDTPointer.limit = (sizeof(struct IDTEntry) * 32) - 1;
		IDTPointer.base = (uint32_t)&IDTTable;

		asm volatile ("lidt %0" : : "m"(IDTPointer) : "memory");		
	}
	void setEntry(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags)
	{
		IDTTable[num].base0 = (base) & 0xFFFF;
		IDTTable[num].selector = selector;
		IDTTable[num].zero = 0;
		IDTTable[num].flags = flags; 
		IDTTable[num].base1 = (base >> 16) & 0xFFFF;
	}

}