/*  Diseñe un algoritmo para saber qué operación quiere realizar un usuario 
    (suma, resta, multiplicación, división) con dos números previamente ingresados,
    el algoritmo debe leer el signo de la operación (+ - * /)
*/


#include <stdio.h>

int main() {
    float num1, num2;
    char operador;

   
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);

    printf("Ingrese el signo de la operacióo (+, -, *, /): ");
    scanf(" %c", &operador);

    switch (operador) 
    {
        case '+':
            printf("Resultado: %.2f\n", num1 + num2);
            break;
        case '-':
            printf("Resultado: %.2f\n", num1 - num2);
            break;
        case '*':
            printf("Resultado: %.2f\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %.2f\n", num1 / num2);
            } else {
                printf("Error: No se puede dividir por cero.\n");
            }
            break;
        default:
            printf("Error: Operador no válido.\n");
    }

    return 0;
}
