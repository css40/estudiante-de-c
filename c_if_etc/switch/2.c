/*  Realiza un algoritmo que le permita al 
    usuario ingresar 
    un número entre 1 y 10 y que este visualice 
    su equivalente en romano. 
*/

#include <stdio.h>

int main() 
{
    int numero;

    printf("Ingrese un número entre 1 y 10: ");
    scanf("%d", &numero);

   
    switch (numero) 
    {
        case 1:
            printf("El número %d en romano es: I\n", numero);
            break;
        case 2:
            printf("El número %d en romano es: II\n", numero);
            break;
        case 3:
            printf("El número %d en romano es: III\n", numero);
            break;
        case 4:
            printf("El número %d en romano es: IV\n", numero);
            break;
        case 5:
            printf("El número %d en romano es: V\n", numero);
            break;
        case 6:
            printf("El número %d en romano es: VI\n", numero);
            break;
        case 7:
            printf("El número %d en romano es: VII\n", numero);
            break;
        case 8:
            printf("El número %d en romano es: VIII\n", numero);
            break;
        case 9:
            printf("El número %d en romano es: IX\n", numero);
            break;
        case 10:
            printf("El número %d en romano es: X\n", numero);
            break;
        default:
            printf("Número fuera del rango (1-10).\n");
    }

    return 0;
}
