#include "main.h"
#include <stdlib.h>

/**
 * print_R - a function that prints a string in rot13
 * @R: represents the string to print
 *
 * Return: the string translated in ROT13
 */
int print_R(va_list R)
{
	char *str;
	unsigned int i, p;
	int count = 0;
	char inside[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outside[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (i = 0; str[i]; i++)
	{
		for (p = 0; inside[p]; p++)
		{
			if (inside[p] == str[i])
			{
				_putchar(outside[p]);
				count++;
				break;
			}
		}
		if (!inside[p])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}