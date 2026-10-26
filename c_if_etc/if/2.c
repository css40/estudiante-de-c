/*Realiza un algoritmo para saber si un número es par o impar.*/

#include <stdio.h>

int main() {
    int numero;

   
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("El numero ingresado es par.\n");
    } else {
        printf("El numero ingresado es impar.\n");
    }

    return 0;
}
