#include "main.h"

/**
 * main - Test safe version of _printf
 * Return: 0
 */
int main(void)
{
    /* Test _printf with NULL format (should not print anything) */
    _printf(NULL);

    /* Test _printf with empty string (should not print anything) */
    _printf("");

    /* Test with only literal characters */
    _printf("This is a safe test.\n");

    /* Test with characters and strings */
    _printf("Character: %c, String: %s, Percent: %%\n", 'A', "Hello");

    /* End of main */
    return (0);
}

