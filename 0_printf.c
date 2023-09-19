#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * print_char - prints out a character
 * @args:list of arguments
 *
 * Return:no of printed characters.
 */

int print_char(va_list args)
{
int c;

c = va_arg(args, int);
return (write(1, &c, 1));
}
/**
 * print_string - prints a string
 * @args:list of arguments
 *
 * Return:no of characters printed
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
 * handle_format_specifier - individual format specifiers
 * @format:pointer to current format specifier
 * @args:list of arguments
 *
 * Return:no of chars printed
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
	case '%':
		putchar('%');
		count++;
		break;
	default:
		putchar('%');
		putchar(**format);
		count += 2;
		break;
}
return (count);
}
/**
 * _printf -prints output depending on format
 * @format:format str with specifiers
 *
 * Return:no of char printed except null byte
 */

int _printf(const char *format, ...)
{
va_list args;
int count;

count = 0;

if (format == NULL)
{
	return (-1);
}
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
count += handle_format_specifier(&format, args);
}
}
format++;
}
va_end(args);
return (count);
}
