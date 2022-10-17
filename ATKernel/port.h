
#ifndef __PORT_H
#define __PORT_H

#include "types.h"


	class Port
	{
		protected:
			uint16_t portnumber;
			Port(uint16_t portnumber);
	};
	
	class Port88it : public Port
	{
		public:
			uint16_t portnumber;
			Port88it(uint16_t portnumber);
			virtual void Write(uint8_t data);
			virtual uint8_t Read();
	};
	
	class Port88itSlow : public Port88it
	{
		public:
			uint16_t portnumber;
			Port88itSlow(uint16_t portnumber);
			virtual void Write(uint8_t data);
	};
	
	class Port16it : public Port
	{
		public:
			uint16_t portnumber;
			Port16it(uint16_t portnumber);
			virtual void Write(uint16_t data);
			virtual uint16_t Read();
	};
	
	class Port32it : public Port
	{
		public:
			uint16_t portnumber;
			Port32it(uint32_t portnumber);
			virtual void Write(uint32_t data);
			virtual uint32_t Read();
	};

#endif