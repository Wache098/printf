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
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_address(va_list args);

#endif
