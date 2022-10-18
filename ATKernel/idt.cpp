#include <idt.hpp>

namespace IDT
{
	struct IDTEntry IDTTable[256];
	
	void init()
	{
		/* Sets the first 32 IDT gates, which are exceptions */
		setGate(0, (uint32_t)ISR::isr0, 0x08, 0x8E);
		setGate(1, (uint32_t)ISR::isr1, 0x08, 0x8E);
		setGate(2, (uint32_t)ISR::isr2, 0x08, 0x8E);
		setGate(3, (uint32_t)ISR::isr3, 0x08, 0x8E);
		setGate(4, (uint32_t)ISR::isr4, 0x08, 0x8E);
		setGate(5, (uint32_t)ISR::isr5, 0x08, 0x8E);
		setGate(6, (uint32_t)ISR::isr6, 0x08, 0x8E);
		setGate(7, (uint32_t)ISR::isr7, 0x08, 0x8E);
		setGate(8, (uint32_t)ISR::isr8, 0x08, 0x8E);
		setGate(9, (uint32_t)ISR::isr9, 0x08, 0x8E);
		setGate(10, (uint32_t)ISR::isr10, 0x08, 0x8E);
		setGate(11, (uint32_t)ISR::isr11, 0x08, 0x8E);
		setGate(12, (uint32_t)ISR::isr12, 0x08, 0x8E);
		setGate(13, (uint32_t)ISR::isr13, 0x08, 0x8E);
		setGate(14, (uint32_t)ISR::isr14, 0x08, 0x8E);
		setGate(15, (uint32_t)ISR::isr15, 0x08, 0x8E);
		setGate(16, (uint32_t)ISR::isr16, 0x08, 0x8E);
		setGate(17, (uint32_t)ISR::isr17, 0x08, 0x8E);
		setGate(18, (uint32_t)ISR::isr18, 0x08, 0x8E);
		setGate(19, (uint32_t)ISR::isr19, 0x08, 0x8E);
		setGate(20, (uint32_t)ISR::isr20, 0x08, 0x8E);
		setGate(21, (uint32_t)ISR::isr21, 0x08, 0x8E);
		setGate(22, (uint32_t)ISR::isr22, 0x08, 0x8E);
		setGate(23, (uint32_t)ISR::isr23, 0x08, 0x8E);
		setGate(24, (uint32_t)ISR::isr24, 0x08, 0x8E);
		setGate(25, (uint32_t)ISR::isr25, 0x08, 0x8E);
		setGate(26, (uint32_t)ISR::isr26, 0x08, 0x8E);
		setGate(27, (uint32_t)ISR::isr27, 0x08, 0x8E);
		setGate(28, (uint32_t)ISR::isr28, 0x08, 0x8E);
		setGate(29, (uint32_t)ISR::isr29, 0x08, 0x8E);
		setGate(30, (uint32_t)ISR::isr30, 0x08, 0x8E);
		setGate(31, (uint32_t)ISR::isr31, 0x08, 0x8E);

		struct IDTDescriptor IDTPointer;

		IDTPointer.limit = (sizeof(struct IDTEntry) * 32) - 1;
		IDTPointer.base = (uint32_t)&IDTTable;

		asm volatile ("lidt %0" : : "m"(IDTPointer) : "memory");		
	}
	void setGate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags)
	{
		IDTTable[num].base0 = (base) & 0xFFFF;
		IDTTable[num].selector = selector;
		IDTTable[num].zero = 0;
		IDTTable[num].flags = flags; 
		IDTTable[num].base1 = (base >> 16) & 0xFFFF;
	}

}