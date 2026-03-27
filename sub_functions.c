#include "main.h"
#include <stdarg.h>
/*
 *
 * TASK 0 :
 *
 * préparer fonction c
 * préparer fonction s
 *
 * TASK 1 :
 *
 * préparer fonction d
 * préparer fonction i
 *
 */

int print_p(va_list arg)
{
		write(1, "%", 1);
		return (1);
}

int print_c(va_list arg)
{
	char c;
	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

int print_s(va_list arg)
{
	char *str = va_arg(arg, char *);
	int x;

	if (str == NULL)
	{
		str = "(nil)";
	}

	for (x = 0; str[x] != '\0'; x++)
	{
		write(1, &str[x], 1);
	}
	return (x + 1);
}
