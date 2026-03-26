#include "main.h"
#include <stdarg.h>


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
						write(1,"%", 1);
						write(1,&format[i],1);
						len = len +2;
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
