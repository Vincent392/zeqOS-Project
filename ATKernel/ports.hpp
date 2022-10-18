
#ifndef PORT_HPP
#define PORT_HPP

#include <stdint.h>

/* 
	Why did I change this? Well, 2 reasons.
	I felt it was unnecessary to have an entire class just for one function, it seems a bit unnecessary.
	I ended up resorting to using functions, which I feel like are a much better fit for this task at hand.
	- xyve
*/

namespace Ports
{
	static inline uint8_t inByte (uint16_t port) {
		uint8_t result;
		asm("in %%dx, %%al" : "=a" (result) : "d" (port));
		return result;
	}

	static inline void outByte (uint16_t port, uint8_t data) {
		asm("out %%al, %%dx" : : "a" (data), "d" (port));
	}

	static inline uint16_t inWord (uint16_t port) {
		uint16_t result;
		asm("in %%dx, %%ax" : "=a" (result) : "d" (port));
		return result;
	}

	static inline void outWord (uint16_t port, uint16_t data) {
		asm("out %%ax, %%dx" : : "a" (data), "d" (port));
	}
	static inline uint32_t readCR0()
	{
		uint32_t cr;
		__asm__ __volatile__ ( "mov %%cr0, %0" : "=r"(cr) );
		return cr;
	}

	static inline uint32_t readCR2()
	{
		uint32_t cr;
		__asm__ __volatile__ ( "mov %%cr2, %0" : "=r"(cr) );
		return cr;
	}

	static inline uint32_t readCR3()
	{
		uint32_t cr;
		__asm__ __volatile__ ( "mov %%cr3, %0" : "=r"(cr) );
		return cr;
	}

	static inline uint32_t readCR4()
	{
		uint32_t cr;
		__asm__ __volatile__ ( "mov %%cr4, %0" : "=r"(cr) );
		return cr;
	}
} // namespace ports


#endif