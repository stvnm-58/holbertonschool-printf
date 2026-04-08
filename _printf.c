#include "main.h"
/**
 * _printf - Produit une sortie selon un format.
 * écrit chaque caractère jusqu'à rencontrer un %
 * Lorsqu'un % est trouvé, regarde le caractère suivant
 * Si le caractère suivant correspond à l'un renseigné sur le tableau
 * Alors il appelle la fonction associé
 * 
 * sinon, écrit le % ainsi que le caractère suivant 
 * 
 * Return: Le nombre de caractères imprimés (excluant l'octet nul final).
 */
int _printf(const char *format, ...)
{
	spec_t tableau[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_p}, {'d', print_d}, {'i', print_d}, {'\0', NULL}};
	int i = 0, j, len = 0;
	va_list arg;
	if (format == NULL)
		return (-1);

	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(arg);
				return (-1);
			}
			j = 0;
			while (tableau[j].lettre != '\0')
			{
				if (format[i] == tableau[j].lettre)
				{
					len = len + tableau[j].fonction(arg);
					break;
				}
				j++;
			}
			if (tableau[j].lettre == '\0')
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				len = len + 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
