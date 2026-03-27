#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2;

    /* Test d'un caractère */
    len1 = _printf("Mon char : [%c]\n", 'H');
    len2 = printf("Vrai char: [%c]\n", 'H');
    printf("Retours: _printf = %d, printf = %d\n\n", len1, len2);

    /* Test d'une chaîne */
    len1 = _printf("Ma string : [%s]\n", "Hello Holberton");
    len2 = printf("Vrai string: [%s]\n", "Hello Holberton");
    printf("Retours: _printf = %d, printf = %d\n\n", len1, len2);

    /* Test du pourcent */
    len1 = _printf("Mon %% : [%%]\n");
    len2 = printf("Vrai %%: [%%]\n");
    printf("Retours: _printf = %d, printf = %d\n", len1, len2);

    return (0);
}
