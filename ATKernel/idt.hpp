#ifndef IDT_HPP
#define IDT_HPP

#include <stdint.h>
#include <isr.hpp>

namespace IDT
{
	
	struct [[gnu::packed]] IDTEntry
	{
		uint16_t base0;
		uint16_t selector;
		uint8_t zero;
		uint8_t flags; 
		uint16_t base1;
	};
	struct [[gnu::packed]] IDTDescriptor
	{
		uint16_t limit;
		uint32_t base;
	};
	
	void init();
	void setGate(uint8_t num, uint32_t base, uint16_t selector, uint8_t flags);

} // namespace table



#endif