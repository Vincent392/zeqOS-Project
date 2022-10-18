#ifndef STDIO_H
#define STDIO_H

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <printf.hpp>
#include <zeqos.hpp>

int puts(const char * str);
int putchar(const char ch);
void putchar_(const char ch);

#endif