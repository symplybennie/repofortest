#include "main.h"
#include <stdarg.h>

/**
 * conv_specifier - searches for the correct conversion specifier
 * @format: the right conversion specifier
 *
 * Return: the valid specifier or zero
 */
static int (*conv_specifier(const char *format))(va_list)
{
	unsigned int i;
	/* An array of the printout function shown below */
	printout_t q[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (i = 0; q[i].m != NULL; i++)
	{
		if (*(q[i].m) == *format)
		{
			break;
		}
	}
	return (q[i].n);
}

/**
 * _printf - a function that prints the character supplied
 * @format: the argument type to the function
 *
 * Return: the character supplied
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*n)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		n = conv_specifier(&format[i + 1]);
		if (n != NULL)
		{
			count += n(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(valist);
	return (count);
}