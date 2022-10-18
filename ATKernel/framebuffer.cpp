#include <framebuffer.hpp>

namespace Graphics
{
	Framebuffer::Framebuffer(multiboot_info_t *mbi)
	{
		address = (void*)mbi->framebuffer_addr;
		width = mbi->framebuffer_width;
		height = mbi->framebuffer_height;
		pitch = mbi->framebuffer_pitch;
		size = mbi->framebuffer_height * mbi->framebuffer_pitch;
		bpp = mbi->framebuffer_bpp;
	}
	Framebuffer::Framebuffer()
	{
		address = 0;
		width = 0;
		height = 0;
		pitch = 0;
		size = 0;
		bpp = 0;
	}
	void Framebuffer::assign(multiboot_info_t *mbi)
	{
		address = (void*)mbi->framebuffer_addr;
		width = mbi->framebuffer_width;
		height = mbi->framebuffer_height;
		pitch = mbi->framebuffer_pitch;
		size = mbi->framebuffer_height * mbi->framebuffer_pitch;
		bpp = mbi->framebuffer_bpp;
	}
	void Framebuffer::putPixel(uint32_t x, uint32_t y, uint32_t color)
	{
		*(uint32_t*)((uint32_t)(address) + (x * 4) + (y * (pitch / (bpp / 8)) * 4)) = color;
	}
	void Framebuffer::clear(uint32_t color)
	{
		for (uint32_t x = 0; x < width; x++)
			for (uint32_t y = 0; y < height; y++)
				putPixel(x, y, color);

	}
	void Framebuffer::drawRectangle(uint32_t x1, uint32_t y1, uint32_t width, uint32_t height, uint32_t color)
	{
		for (uint32_t x = x1; x < (width + x1); x++)
			for (uint32_t y = y1; y < (height + y1); y++)
				putPixel(x, y, color);
	}
	void Framebuffer::drawChar(uint32_t x, uint32_t y, unsigned char c, uint32_t color)
	{
		for (uint32_t i = 0; i < 16; i++)
			for (uint32_t j = 0; j < 8; j++)
				if ((font[(c * 16) + i] & (0x80 >> j)) != 0)
					putPixel(x + j, y + i, color);
	}
	void Framebuffer::clearChar(uint32_t x, uint32_t y, uint32_t color)
	{
		for (uint32_t i = 0; i < 16; i++)
			for (uint32_t j = 0; j < 8; j++)
				putPixel(x + j, y + i, color);
	}
	void Framebuffer::printChar(const char ch, uint32_t color)
	{
		if(ch == '\n')
		{
			point_x = 0;
			point_y += 16;
		}
		else if(ch == '\r')
		{
			point_x = 0;
		}
		/*else if(ch == '\b')
		{
			// Fix this tomorrow
			if(x - 8 >= 0)
			{
				x -= 8;
				clearchar(x, y, 0x00000000);
			}
			else if (y - 16 >= 0)
			{
				y -= 16;
				x = framebuffer.width - 8;
				clearchar(x, y, 0x00000000);
			}
		}*/
		else
		{
			if(point_x + 8 > width)
			{
				point_x = 0;
				point_y += 16;
				drawChar(point_x, point_y, ch, color);
				point_x += 8;
			}
			else if (point_y + 16 > height)
			{
				// Handle this later
			}
			else
			{
				drawChar(point_x, point_y, ch, color);
				point_x += 8;
			}
		}
	}
	void Framebuffer::print(const char* str, uint32_t color)
	{
		while(*str != 0)
		{
			printChar(*str, color);
			str++;
		}
	}
	void Framebuffer::printAt(const char* str, uint32_t x, uint32_t y, uint32_t color)
	{
		while(*str != 0)
		{
			if(*str == '\n')
			{
				x = 0;
				y += 16;
			}
			else if(*str == '\r')
			{
				x = 0;
			}
			/*else if(*str == '\b')
			{
				// Fix this tomorrow
				if(x - 8 >= 0)
				{
					x -= 8;
					clearchar(x, y, 0x00000000);
				}
				else if (y - 16 >= 0)
				{
					y -= 16;
					x = framebuffer.width - 8;
					clearchar(x, y, 0x00000000);
				}
			}*/
			else
			{
				if(x + 8 > width)
				{
					x = 0;
					y += 16;
					drawChar(x, y, *str, color);
					x += 8;
				}
				else if (y + 16 > height)
				{
					// Handle this later
				}
				else
				{
					drawChar(x, y, *str, color);
					x += 8;
				}
			}
			str++;
		}
	}
} // namespace Framebuffer
