#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);

int handle_format_specifier(const char **format, va_list args);

/**
 * _printf - Produce output according to  format.
 * @format: char str containing format specifiers.
 *
 * Return: no of characters printed except null.
 */
int _printf(const char *format, ...)
{
va_list args;
int count;

va_start(args, format);

count = 0;

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
count += handle_format_specifier(&format, args);
}
format++;
}

va_end(args);
return (count);
}

/**
 * print_char - Prints out a character.
 * @args: List of arguments.
 *
 * Return: No of printed characters.
 */
int print_char(va_list args)
{
int c;

c = va_arg(args, int);
return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: List of arguments.
 *
 * Return: no  of characters printed.
 */
int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count;

count = 0;

if (str == NULL)
{
write(1, "(null)", 6);
return (6);
}
else
{
while (*str)
{
write(1, str, 1);
str++;
count++;
}
return (count);
}
}

/**
 * print_int - Prints an integer.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
char buffer[12];

int count = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, count);
return (count);
}

/**
 * handle_format_specifier - Individual format specifiers.
 * @format: Pointer to the current format specifier.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_format_specifier(const char **format, va_list args)
{
int count;

count = 0;
switch (**format)
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case 'd':
case 'i':
count += print_int(args);
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
putchar(**format);
count += 2;
}
return (count);
}
