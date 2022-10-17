
#include "port.h"

Port::Port(uint16_t portnumber)
{
	this->portnumber = portnumber;
}

	
Port88it::Port88it(uint16_t portnumber)
: Port(portnumber)
{
}


void Port88it::Write(uint8_t data)
{
	__asm__ volatile("outb %0, %1" : : "a" (data), "Nd" (portnumber));
}
			
uint8_t Port88it::Read()
{
	uint8_t result;
	__asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (portnumber));
	return result;
}


Port88itSlow::Port88itSlow(uint16_t portnumber)
: Port88it(portnumber)
{
}

void Port88itSlow::Write(uint8_t data)
{
	__asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:" : : "a" (data), "Nd" (portnumber));
}


Port16it::Port16it(uint16_t portnumber)
: Port(portnumber)
{
}


void Port16it::Write(uint16_t data)
{
	__asm__ volatile("outw %0, %1" : : "a" (data), "Nd" (portnumber));
}
			
uint16_t Port16it::Read()
{
	uint16_t result;
	__asm__ volatile("inw %1, %0" : "=a" (result) : "Nd" (portnumber));
	return result;
}

Port32it::Port32it(uint32_t portnumber)
: Port(portnumber)
{
}

void Port32it::Write(uint32_t data)
{
	__asm__ volatile("outl %0, %1" : : "a" (data), "Nd" (portnumber));
}
			
uint32_t Port32it::Read()
{
	uint32_t result;
	__asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (portnumber));
	return result;
}