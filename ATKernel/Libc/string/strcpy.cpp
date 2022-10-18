#include <string.hpp>
char* strcpy(char* dest, const char* src)
{
    char* save = dest;
    for (; (*dest = *src) != '\0'; ++src, ++dest);
	return save;
}