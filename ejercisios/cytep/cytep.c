#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
void cant_min(void);
void cant_mayu(void);
void cant_espacios(void);
void convert_mayu(void);
void convert_min(void);
void menu(void);
int main(void)
{

    menu();
    int opcion = get_int("Escoja: ");
    do
    {

        switch(opcion)
        {
            case 1:
                cant_min();
                break;
            case 2:
                cant_mayu();
                break;
            case 3:
                cant_espacios();
                break;
            case 4:
                convert_mayu();
                break;
            case 5:
                convert_min();
                break;
            case 6:
                printf("Nos vemos :D");
                break;
        }
        printf("\n\n");
        menu();
        opcion = get_int("Ingrese opción: ");
    } while (opcion != 6);
}

void cant_mayu(void)
{
    string texto = get_string("Texto: ");
    int n = strlen(texto); int mayor = 0;
    for(int i = 0; i<n; i++)
    {
        if(isupper(texto[i]))
        {
            mayor++;
        }
    }
    printf("La cantidad de mayúsculas en el texto es %d\n", mayor);
}
void cant_min(void)
{
    string texto = get_string("Texto: ");
    int n = strlen(texto); int menor = 0;
    for(int i = 0; i<n; i++)
    {
        if(islower(texto[i]))
        {
            menor++;
        }
    }
    printf("La cantidad de minúsculas en el texto es %d\n", menor);
}

void cant_espacios(void)
{
    string texto = get_string("Texto: ");
    int n = strlen(texto);
    int espacio = 0;
    for(int i = 0; i<n; i++)
    {
        if(isspace(texto[i]))
        {
            espacio++;
        }
    }
    printf("La cantidad de espacios en el texto es %d\n", espacio);
}

void convert_mayu(void)
{
    string texto = get_string("Texto: ");
    printf("Cadena de original %s\n", texto);
    int n = strlen(texto);
    for(int i = 0; i<n; i++)
    {
        texto[i] = toupper(texto[i]);
    }
    printf("Cadena mayúsculas:%s\n", texto);
}

void convert_min(void)
{
    string texto = get_string("Texto: ");
    printf("Cadena de original %s\n", texto);
    int n = strlen(texto);
    for(int i = 0; i<n; i++)
    {
        texto[i] = tolower(texto[i]);
    }
    printf("Cadena minúsculas:%s\n", texto);
}

void menu(void)
{
    printf("APRENDIENDO A USAR LAS FUNCIONES DE CTYPE.H\nPor favor escoja una opción:\n1.Encontrar la cantidad de minúsculas\n2.Encontrar la cantidad de mayúsculas.\n3.Encontrar la cantidad de espacios\n4.Convertir las letras a mayúsculas\n5.Convertir las letras a mayúsculas\n6.Salir\n");
}