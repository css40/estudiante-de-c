#include <stdio.h>
#include <cs50.h>
int main()
{
    string texto = get_string("Ingrese texto: ");
    int i = 0;
    while(texto[i] != '\0')
    {
        i++;
    }
    printf("La cadena posee %d caracteres\n", i);
}
//cuenta las letras de las palabasras//