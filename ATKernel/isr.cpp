#include <isr.hpp>

namespace ISR
{
	const char *ExceptionMessages[] = {
		"Division By Zero",
		"Debug",
		"Non Maskable Interrupt",
		"Breakpoint",
		"Into Detected Overflow",
		"Out of Bounds",
		"Invalid Opcode",
		"No Coprocessor",

		"Double Fault",
		"Coprocessor Segment Overrun",
		"Bad TSS",
		"Segment Not Present",
		"Stack Fault",
		"General Protection Fault",
		"Page Fault",
		"Unknown Interrupt",

		"Coprocessor Fault",
		"Alignment Check",
		"Machine Check",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",

		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved",
		"Reserved"
	};
	void init()
	{

	}
	void installHandler(uint8_t num, void (*handler)(struct registers *))
	{

	}
	extern "C" void isrHandler(struct registers r)
	{
        printf("Exception: %s [%u]\n", ExceptionMessages[r.int_no], r.int_no);

		printf("Faulting Address (EIP) = 0x%08X\n", r.eip);
		printf("EDI = 0x%08X ESI = 0x%08X\n", r.edi, r.esi);
		printf("EBP = 0x%08X ESP = 0x%08X\n", r.ebp, r.esp);
		printf("EDX = 0x%08X ECX = 0x%08X\n", r.edx, r.ecx);
		printf("EBX = 0x%08X EAX = 0x%08X\n", r.ebx, r.eax);
		printf("CS  = 0x%08X SS  = 0x%08X\n", r.cs , r.ss);
        printf("CR4 = 0x%08X CR3 = 0x%08X\n", Ports::readCR4(), Ports::readCR3());
        printf("CR2 = 0x%08X CR0 = 0x%08X\n", Ports::readCR2(), Ports::readCR0());
		printf("EFLAGS = 0x%08X\n", r.eflags);

		for(;;) {
			asm("hlt");
		}
	}

} // namespace Interrupts