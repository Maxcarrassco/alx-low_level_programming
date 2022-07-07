#include "variadic_functions.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: format string
 * Return: Nothing
 */

void print_all(const char * const format, ...)
{
	va_list args;
	int k = 0;
	prv_t prv[] = {
		{'c', pr_ch},
		{'i', pr_int},
		{'f', pr_flt},
		{'s', pr_str}
	};
	int i = 0, len = strlen(format) - 1;
	va_start(args, format);

	while (format[i])
	{
		k = 0;
		while (k < 4)
		{
			if (prv[k].id == format[i])
			{
				prv[k].f(args);

				if (i != len)
					printf(", ");
				break;
			}
			k++;
		}

		i++;
	}

	va_end(args);
	printf("\n");
}

/**
 * pr_ch - prints char
 * @args: va_list
 * Return: Nothing
 */

void pr_ch(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * pr_int - prints int
 * @args: va_list
 * Return: Nothing
 */

void pr_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * pr_flt - prints float
 * @args: va_list
 * Return: Nothing
 */

void pr_flt(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * pr_str - prints string
 * @args: va_list
 * Return: Nothing
 */

void pr_str(va_list args)
{
	if (args == NULL)
	{
		puts("(nil)");
	}
	printf("%s", va_arg(args, char *));
}
