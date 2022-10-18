#ifndef STRING_H
#define STRING_H

#include <stddef.h>
//#include <string.h>

char* strcat(char* dest, const char* src);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t len);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t len);
size_t strlen(const char* str);
// strlwr
void strrev(char* str);
// strupr
char* strchr(const char* haystack, int needle);
char* strrchr(const char* haystack, int needle);

void* memset(void* dest, int val, size_t len);
void* memcpy(void* dest, const void* src, size_t len);
int memcmp(const void* s1, const void* s2, size_t len);

#endif