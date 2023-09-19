#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#define BUFFER_SIZE 1024

int print_char_to_buffer(char *buffer, int *index, char c);
int print_string_to_buffer(char *buffer, int *index, const char *str);
int print_int_to_buffer(char *buffer, int *index, int num);
int handle_format_specifier(const char **format, va_list args);

/**
 * _printf - Produces output according to a format and stores it in a buffer.
 * @format: A character string with  format specifiers.
 *
 * @buffer: The buffer where the output is stored
 * Return: The number of characters printed except NULL.
 */
int _printf(char *buffer, const char *format, ...)
{
	va_list args;
	int count, index;

	count = 0;
	index = 0;

	va_start(args, *format);
	while (*format)
	{
		if (*format != '%')
		{
			count += print_char_to_buffer(buffer, &index, *format);
		}
		else
		{
			format++;
			count += handle_format_specifier(&format, args, buffer, &index);
		}
		format++;
	}
	 buffer[index] = '\0';
	 va_end(args);
	 return (count);
}
