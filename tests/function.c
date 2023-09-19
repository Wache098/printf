#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_int - Prints an integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    char buffer[12];
    int count = 0;

    int n = num;
    int sign = 1;

    if (num < 0)
    {
        sign = -1;
        n = -n;
    }

    int i = 0;
    do
    {
        buffer[i++] = '0' + (n % 10);
        n /= 10;
    } while (n > 0);

    if (sign < 0)
        buffer[i++] = '-';


    while (--i >= 0)
    {
        write(1, &buffer[i], 1);
        count++;
    }

    return count;
}

/**
 * _printf - Prints output according to format
 * @format: Format string with specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
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
    return count;
}

