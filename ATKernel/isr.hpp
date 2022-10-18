#ifndef ISR_HPP
#define ISR_HPP

#include <stdint.h>
#include <ports.hpp>
#include <stdio.hpp>

namespace ISR
{
	/* These are the software interrupts reserved by Intel for exceptions */
	extern "C" void isr0();
	extern "C" void isr1();
	extern "C" void isr2();
	extern "C" void isr3();
	extern "C" void isr4();
	extern "C" void isr5();
	extern "C" void isr6();
	extern "C" void isr7();
	extern "C" void isr8();
	extern "C" void isr9();
	extern "C" void isr10();
	extern "C" void isr11();
	extern "C" void isr12();
	extern "C" void isr13();
	extern "C" void isr14();
	extern "C" void isr15();
	extern "C" void isr16();
	extern "C" void isr17();
	extern "C" void isr18();
	extern "C" void isr19();
	extern "C" void isr20();
	extern "C" void isr21();
	extern "C" void isr22();
	extern "C" void isr23();
	extern "C" void isr24();
	extern "C" void isr25();
	extern "C" void isr26();
	extern "C" void isr27();
	extern "C" void isr28();
	extern "C" void isr29();
	extern "C" void isr30();
	extern "C" void isr31();

	/* Struct which aggregates many registers */
	struct registers {
		uint32_t ds; /* Data segment selector */
		uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; /* Pushed by pusha. */
		uint32_t int_no, err_code; /* Interrupt number and error code (if applicable) */
		uint32_t eip, cs, eflags, useresp, ss; /* Pushed by the processor automatically */
	};

	void init();
	void installHandler(uint8_t num, void (*handler)(struct registers *));

} // namespace Interrupts



#endif