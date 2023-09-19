#include "main.h"
#include <unistd.h>

/**
 * print_int - prints an integer
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
int num = va_arg(args, int);
int count;

count = 0;

if (num < 0)
{
write(1, "-", 1);
count++;
num = -num;
}

if (num == 0)
{
write(1, "0", 1);
count++;
}
else
{
int rev_num;
char digit;

rev_num = 0;
while (num > 0)
{
rev_num = rev_num * 10 + num % 10;
num /= 10;
}
while (rev_num > 0)
{
digit = '0' + (rev_num % 10);
write(1, &digit, 1);
rev_num /= 10;
count++;
}
}

return (count);
}

/**
 * handle_format_specifier - individual format specifiers
 * @format: pointer to current format specifier
 * @args: list of arguments
 *
 * Return: number of characters printed
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
case 'd':
case 'i':
count += print_int(args);
break;
default;
putchar('%');
putchar(**format);
count += 2;
break;
}
return (count);
}
