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
	return (x);
}
/********************************/
int _printf(const char *format, ...)
{
	/*
	 *
	 * Tableau de fonction ici
	 *
	 */
	spec_t tableau[] = {
		{'c', print_c},
		{'s', print_s},
		{'\0', NULL},
	};
	/*moteur du programme ici*/
	int i = 0;
	int j;
	int len = 0;
	/*compteur de taille du print*/
	va_list arg;

	va_start(arg, format);
	while (format[i])
	{
		/*ci-dessous, si le defilement trouve un %*/
		if (format[i] == '%')
		{
			i++;
			{
				/* ci-dessous, erciture du % s'il est precédé d'un %*/
				if (format[i] == '%')
				{
					write(1, &format[i], 1);
					len++;
				}
				else
				{
					j = 0; /* Remise à zéro pour parcourir le tableau 'lettre' à chaque fois*/

					while (tableau[j].lettre != '\0')
					{
						if (format[i] == tableau[j].lettre)
						{
							/*appel la fonction correspondante ET ajoute le retour au compte len*/
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
			}
		}
/*ci dessous, écrit chaque char un par un tant que c'est pas un % (auquel cas, voir code plus haut)*/
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
/******************************/

// int print_s(va_list list)
// {
//    char *str = va_arg(list, char *); /*pioche l'argument en tant que pointeur (chaîne)*/
//    int i = 0;                        /*Compteur local pour cette chaîne*/
//
//    if (str == NULL)    /*Si la chaîne n'existe pas (pointeur NULL)*/
//        str = "(null)"; /*force l'affichage de "(null)"*/
//
//    while (str[i]) /*Tant qu'on n'est pas au caractère de fin '\0'*/
//    {
//        write(1, &str[i], 1); /*affiche le caractère actuel*/
//        i++;                  /*passe au suivant*/
//   }
