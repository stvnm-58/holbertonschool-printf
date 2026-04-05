📌 Description

_printf est une implémentation simplifiée de la fonction standard printf en langage C.  
  
Le projet consiste à recréer un moteur de formatage capable d’interpréter une chaîne et d’afficher différents types de données en fonction de spécificateurs.  
  
*************************************************  
  
📁 Structure du projet  
.  
├── README.md  
├── _printf.c        # Fonction principale  
├── main.h           # Prototypes + structures  
├── sub_functions.c  # Fonctions associées aux spécificateurs  
  
*************************************************  
  
🧩 Spécificateurs supportés  
Spécificateur	Description  
%c	Caractère  
%s	Chaîne de caractères  
%%	Symbole %  
%d	Entier  
%i	Entier  
  
*************************************************  
  
🧠 Fonctionnement interne  
Utilisation de va_list pour gérer les arguments variables  
Parcours caractère par caractère de format  
Si % détecté :  
Recherche dans un tableau de structures (spec_t)  
Appel de la fonction correspondante  
Si caractère normal :  
Écriture directe avec write  
Comptage du nombre total de caractères affichés  
  
*************************************************  
  
🔧 Tableau de correspondance  
spec_t tableau[] = {  
    {'c', print_c},  
    {'s', print_s},  
    {'%', print_p},  
    {'d', print_d},  
    {'i', print_d},  
    {'\0', NULL}  
};  
  
*************************************************  
  
🔁 Exemple d'utilisation  
_printf("Value: %d\n", 42);  
  
Sortie :  
  
Value: 42  
  
*************************************************  
  
👨‍💻 Auteurs  
  
Steven MARIANI, Marie LOPEZ  
