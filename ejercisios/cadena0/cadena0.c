#include <stdio.h>
#include <cs50.h>
#include <string.h>
int main()
{
    string texto = get_string("Ingrese texto: ");
    printf("Texto original: %s\n", texto);
    for(int i = 0; i<strlen(texto); i++)
    {
        texto[i] = texto[i] + 1;
    }
    printf("Texto cambiado: %s\n", texto);
}