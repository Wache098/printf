#include "main.h"
#include <stdio.h>

/**
 * _printf - prints an integer
 * @format:format str with specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count;

count = 0;
va_start(args, format);

while (*format)
{
if (*format != '%')
{
putchar(*format);
count++;
}
else
{
format++;
if (*format == '\0')
{
break;
}
switch (*format)
{
case 'd':
case 'i':
count += print_int(args);
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
}
format++;
}
va_end(args);
return (count);
}
