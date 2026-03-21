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

int print_c(va_list list)
{
write (1, va_arg(list, int), 1);
}


int print_s(va_list list)
{
char *str = va_arg(list, char*);
int x;

if (str == NULL)
{
	str == "(nil)";
}

for (x = 0; str[x] != '\0'; x++)
{
write (1, str, x);
}

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


}