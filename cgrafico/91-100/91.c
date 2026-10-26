#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main(void)
{
char *string="545";
long int valor_entero;
clrscr();
valor_entero=atoi(string);
printf("La cadena es %s, el valor entero correspondiente es %d\n",string,valor_entero);
getch();
}