#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int handle_format_specifier(const char **format, va_list args);
int print_string(va_list args);
int _putchar(char c);

#endif
