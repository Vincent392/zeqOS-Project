#include <string.hpp>

char* strrchr(const char* haystack, int needle)
{
    char* save;
    for(save = 0;*haystack != '\0'; haystack++)
    {
        if (*haystack == needle)
            save = (char*) haystack;
    }
    return save;
}