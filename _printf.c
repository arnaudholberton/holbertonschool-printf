#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;
    char c, *s;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0') /* % at the end */
                break;

            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    count += write(1, s, 1);
                    s++;
                }
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                /* Unknown format, print % and the character */
                count += write(1, "%", 1);
                count += write(1, &format[i], 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (count);
}

