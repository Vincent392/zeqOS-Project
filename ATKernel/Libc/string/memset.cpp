#include <string.hpp>
void* memset(void* dest, int val, size_t len)
{
    unsigned char* ptr = (unsigned char*)dest;
    while(len--)
        *ptr++ = val;
    return dest;
}