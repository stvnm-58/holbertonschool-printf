#include "main.h"
#include <stdarg.h>
/*
*
* Fonction servant à print les chiffre
* également utilisé pour %i
*
*
*/
int print_d(va_list arg)
{
	int n = va_arg(arg, int);
	int count = 0;
	long nb;
	char buffer[12]; /*Assez large pour -2147483648\0 */
	int i = 0;

	nb = n;
	
	if (nb < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -nb;
	}

	if (nb == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}

	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}

	return (count);
}


/*
*
* Fonction qui print le % après un premier %
*
*/
int print_p(va_list arg)
{
	(void)arg;
	write(1, "%", 1);
	return (1);
}


/*
*
* Fonction print un char via %c 
*/
int print_c(va_list arg)
{
	char c;
	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}


/*
*
* Fonction print une chaîne de char (string)
* via %s
*/
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
