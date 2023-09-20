#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * handle_format_specifier - Handles individual format specifiers.
 *
 * @format: Pointer to current format specifier.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_format_specifier(const char **format, va_list args)
{
int count, num;

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
case 'd':
case 'i':
{
num = va_arg(args, int);
if (num < 0)
{
putchar('-');
num = -num;
count++;
}
count += print_unsigned_helper(num, 10);
break;
}
default:
putchar('%');
putchar(**format);
count += 2;
break;
}
return (count);
}
