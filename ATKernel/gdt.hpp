
#ifndef GDT_HPP
#define GDT_HPP

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
	struct [[gnu::packed]] GDTEntry
	{
		uint16_t limit;
		uint16_t base0;
		uint8_t base1;
		uint8_t access;
		uint8_t granularity;
		uint8_t base2;
	};
	struct [[gnu::packed]] GDTDescriptor
	{
		uint16_t limit;
		uint32_t base;
	};

	void init();
	void setGate(uint8_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

} // namespace table


#endif
