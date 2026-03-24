#include "main.h"
#include <stdarg.h>
#include <sys/_types/_va_list.h>


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

i = 0;
va_list arg;
va_start(arg,format);
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
write (1, format[i], 1)
}
if (format[i] == 'c' || format[i] == 's')

{
/* recup de la fonction associer*/
int print_c(va_list list)
{
char c;

c = va_arg(list, int);     /*pioche le prochain argument en le traitant comme un int*/
return (write(1, &c, 1));  /*écrit le caractère à l'adresse &c et on renvoie 1*/
}
int print_s(va_list list)
{
char *str = va_arg(list, char*); /*pioche l'argument en tant que pointeur (chaîne)*/
int i = 0;                       /*Compteur local pour cette chaîne*/

   
if (str == NULL)                 /*Si la chaîne n'existe pas (pointeur NULL)*/
str = "(null)";              /*force l'affichage de "(null)"*/
    
while (str[i])                   /*Tant qu'on n'est pas au caractère de fin '\0'*/
{
write(1, &str[i], 1);        /*affiche le caractère actuel*/
i++;                         /*passe au suivant*/
}
return (i);                      /*renvoie le nombre total de lettres écrites*/
}
}
}
}
}
va_end(arg);
printf("\n");
}
