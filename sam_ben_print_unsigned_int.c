#include "main.h"

/**
 * print_u - a function that prints an unsigned int in decimal form
 * @u: represents the unsigned int we want to print
 *
 * Return: the number we printed
 */
int print_u(va_list u)
{
	unsigned int z[10];
	unsigned int i, q, r, addition;
	int count;

	r = va_arg(u, unsigned int);
	q = 1000000000; /* (10 ^ 9) */
	z[0] = r / q;
	for (i = 1; i < 10; i++)
	{
		q /= 10;
		z[i] = (r / q) % 10;
	}
	for (i = 0, addition = 0, count = 0; i < 10; i++)
	{
		addition += z[i];
		if (addition || i == 9)
		{
			_putchar('0' + z[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_o - represents a function that takes in an unsigned integer
 *           and display it in octal form
 * @o: represents unsigned integer
 *
 * Return: printed digits
 */
int print_o(va_list o)
{
	unsigned int z[11];
	unsigned int i, q, r, addition;
	int count;

	r = va_arg(o, unsigned int);
	q = 1073741824; /* (8 ^ 10) */
	z[0] = r / q;
	for (i = 1; i < 11; i++)
	{
		q /= 8;
		z[i] = (r / q) % 8;
	}
	for (i = 0, addition = 0, count = 0; i < 11; i++)
	{
		addition += z[i];
		if (addition || i == 10)
		{
			_putchar('0' + z[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_b - represents a function that takes in unsigned int and
 *           prints in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int r, q, i, addition;
	unsigned int z[32];
	int count;

	r = va_arg(b, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	z[0] = r / q;
	for (i = 1; i < 32; i++)
	{
		q /= 2;
		z[i] = (r / q) % 2;
	}
	for (i = 0, addition = 0, count = 0; i < 32; i++)
	{
		addition += z[i];
		if (addition || i == 31)
		{
			_putchar('0' + z[i]);
			count++;
		}
	}
	return (count);
}