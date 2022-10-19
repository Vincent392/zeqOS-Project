#pragma once

#include <stdint.h>
#include <multiboot.h>
#include <font.hpp>

/*
	This is the Graphics namespace.

	I'll be adding many graphics operations here, the VERY basic ones.

	Most of the GUI will be in userspace.
*/
namespace Graphics
{
	/*
		I'm not even gonna lie, this entire class looks like shit.
		I wrote this right as I was about to go to bed, so forgive me please.

		If you're seeing this, I'll be rewriting this soon, so you know, it doesn't give someone eye cancer everytime they see it.
	*/
	/*
		So, what is a framebuffer?

		I'll give a simple explanation, but here are better resources than me:
			[https://wiki.osdev.org/Drawing_In_a_Linear_Framebuffer]
			[https://en.wikipedia.org/wiki/Framebuffer]

		Now, for my oversimplification.

		A framebuffer is just a location in memory where you can plot pixels with colors and BOOM, it pops up on the screen.

		There are more things that should be taken into account like the width, height, pitch, size, bpp, etc etc.

		But for this, I did it for you!!!!


	*/
	class Framebuffer
	{
	private:
		/*
			This is just the location of the framebuffer, nothing special.
		*/
		void * address;
		uint32_t width;
		uint32_t height;
		uint32_t pitch;
		uint32_t size;
		uint16_t bpp;

		/*
			Some functions will need to store their last x and y position internally, so the functions can actually print stuff without having to constantly having the user to remember/store the previous location.
		*/
		uint32_t x = 0;
		uint32_t y = 0;
	public:
		Framebuffer(multiboot_info_t *mbi);
		Framebuffer();
		void assign(multiboot_info_t *mbi);
		void putPixel(uint32_t x, uint32_t y, uint32_t color);
		void clear(uint32_t color);
		void drawRectangle(uint32_t x1, uint32_t y1, uint32_t width, uint32_t height, uint32_t color);
		void printChar(const char ch, uint32_t color);
		void drawChar(uint32_t x, uint32_t y, unsigned char c, uint32_t color);
		void clearChar(uint32_t x, uint32_t y, uint32_t color);
		void print(const char* str, uint32_t color);
		void printAt(const char* str, uint32_t x, uint32_t y, uint32_t color);
	};
}
