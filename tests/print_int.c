#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_int - prints an integer
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
int num;
int count;
char buffer[25];
int is_negative;

num = va_arg(args, int);
count = 0;

if (num < 0)
{
is_negative = 1;
num = -num;
}
if (num == 0)
{
buffer[count++] = '0';
}
else
{
while (num > 0)
{
buffer[count++] = '0' + (num % 10);
num /= 10;
}
}
if (is_negative)
{
buffer[count++] = '-';
}
while (count > 0)
{
write(1, &buffer[--count], 1);
}
return (count);
}
