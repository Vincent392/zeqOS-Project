#include <stdio.hpp>

/**
 * Prints string to screen
 *
 * @param str String to print
 */
int puts(const char * str)
{
    fb.print(str, 0xffffffff);
}