#include "main.h"


int _printf(const char *format, ...){
	spec_t tableau[] = { {'c', print_c}, {'s', print_s}, {'%', print_p}, {'\0', NULL},
	};
	int i = 0; 
	int j;
	int len = 0;
	va_list arg;
	va_start(arg, format);
	while (format && format[i]){
		if (format[i] == '%'){
			i++;
			{
				{
					j = 0; /* Remise à zéro pour parcourir le tableau 'lettre' à chaque fois*/
					while (tableau[j].lettre != '\0')
					{
						if (format[i] == tableau[j].lettre)
						{
							len = len + tableau[j].fonction(arg);
							break;
						}
						j++;
					}
					if (tableau[j].lettre == '\0'){
						write(1,"%", 1);
						write(1,&format[i],1);
						len = len +2;
					}
				}
			}
		}
		else{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
