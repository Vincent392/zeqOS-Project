#include <string.hpp>
char* strncpy(char* dest, const char* src, size_t len)
{
    char* save = dest;
    char* s = (char*)src;
    for (; (*dest = *src) != '\0' && (src - s) < len; ++src, ++dest);
	return save;
}