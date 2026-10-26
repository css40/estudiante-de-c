#include <string.h>
#include <stdio.h>
#include <cs50.h>
void comparacion(void);
void longitud(void);
void copiar(void);
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
                comparacion();
                break;
            case 2:
                longitud();
                break;
            case 3:
                copiar();
                break;
            case 4:
            printf("nos vemos :D");
            break;
        }
        printf("\n\n");
        menu();
        opcion = get_int("Ingrese opción: ");
    } while (opcion != 4);

}
void comparacion(void)
{
    string texto1 = get_string("Ingrese primer texto: ");
    string texto2 = get_string("Ingrse segundo texto: ");
    //la función strcmp retorna 0 si las dos cadenas son iguales
    if(strcmp(texto1, texto2) == 0)
    {
        printf("iguales\n");
    }
    else
    {
        printf("distintos\n");
    }
}

void longitud(void)
{
    string texto = get_string("Ingrese texto: ");
    int longitud = strlen(texto);
    //strlen no cuenta el \0
    printf("La longitud de la cadena es %d\n", longitud);
}
void copiar(void)
{
    string texto = get_string("Ingrese texto: ");
    int numero = strlen(texto);
    char cadena[numero];
    strcpy(cadena, texto);
    printf("La cadena copio el dato:%s\n", cadena);
}
void menu(void)
{
     printf("APRENDIENDO A USAR LAS FUNCIONES DE STRING.H\nPor favor escoja una opción:\n1.Comparar dos cadenas\n2.Encontrar la longitud de una cadena.\n3.Copiar una cadena\n4.Salir\n");
}