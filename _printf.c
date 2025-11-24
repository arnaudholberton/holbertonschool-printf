#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: the format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;
    char c;
    char *s;

    va_start(args, format);

    if (!format)
        return (-1);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            if (*p == 'c')
            {
                c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (*p == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                    count += write(1, s++, 1);
            }
            else if (*p == '%')
                count += write(1, "%", 1);
            else
            {
                count += write(1, "%", 1);
                count += write(1, p, 1);
            }
        }
        else
        {
            count += write(1, p, 1);
        }
    }

    va_end(args);
    return (count);
}

