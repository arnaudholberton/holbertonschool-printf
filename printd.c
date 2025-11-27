#include "main.h"
#include <stdio.h>
/**
 * printd - prints a decimal (integer) number
 * @num: the integer to print
 * Return: number of characters printed
 */
int printd(long int num)
{
int count = 0;
long int buffer[12];
int j = 0;
if (num < 0)
{
	count += write(1, "-", 1);
	num = -num;
}
else
{
	num = num;
}
if (num == 0)
{
	count += write(1, "0", 1);
}
else
{
	while (num > 0)
	{
		buffer[j++] = (num % 10) + '0';
		num /= 10;
	}
	while (j--)
	{
		count += write(1, &buffer[j], 1);
	}
}
return (count);
}
