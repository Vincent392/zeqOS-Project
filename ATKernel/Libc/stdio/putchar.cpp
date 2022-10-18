#include <stdio.hpp>

/**
 * Prints character to screen
 *
 * @param ch Character to print
 */
int putchar(const char ch)
{
    putchar_(ch);
}
/**
 * Used by the printf implementation
 * 
 * @param ch Character to print
 */
void putchar_(const char ch)
{
    fb.printChar(ch, 0xffffffff);
}