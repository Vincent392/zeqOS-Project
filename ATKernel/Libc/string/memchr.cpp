#include <string.hpp>

void* memchr(const char* haystack, int needle, size_t len)
{
    while(len--)
    {
        if (*haystack == needle)
            return (char*) haystack;
    }
    return 0;
}