/*  Elabora un algoritmo que le presente al usuario un menú en el 
    que se le mostraran las siguientes opciones: sumar, restar, 
    multiplicar, dividir dos números y salir y muestre el resultado de la opción correspondiente.
*/


#include <stdio.h>

int main() 
{
    int opcion;
    double num1, num2, resultado;

    do 
    {
        printf("\nMenú de opciones:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Seleccione una opción (1-5): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el primer número: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo número: ");
                scanf("%lf", &num2);
                resultado = num1 + num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            case 2:
                printf("Ingrese el primer número: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo número: ");
                scanf("%lf", &num2);
                resultado = num1 - num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            case 3:
                printf("Ingrese el primer número: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo número: ");
                scanf("%lf", &num2);
                resultado = num1 * num2;
                printf("Resultado: %.2lf\n", resultado);
                break;
            case 4:
                printf("Ingrese el primer número: ");
                scanf("%lf", &num1);
                printf("Ingrese el segundo número: ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf\n", resultado);
                } else {
                    printf("Error: No se puede dividir por cero.\n");
                }
                break;
            case 5:

                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida (1-5).\n");
        }
    } while (opcion != 5);

    return 0;
}
