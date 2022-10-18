#include <string.hpp>

char* strchr(const char* haystack, int needle)
{
    for(;*haystack != '\0'; haystack++)
    {
        if (*haystack == needle)
            return (char*) haystack;
    }
    return 0;
}