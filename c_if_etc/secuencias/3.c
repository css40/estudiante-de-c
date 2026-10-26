/*  Escriba un algoritmo que calcule 
    e imprima el área de un triángulo, 
    teniendo en consideración: b*h/2.
*/

#include <stdio.h>

int main() 
{
    double base, altura;

    printf("Ingrese la longitud de la base del triángulo: ");
    scanf("%lf", &base);
    printf("Ingrese la altura del triángulo: ");
    scanf("%lf", &altura);
    double area = (base * altura) / 2.0;
    printf("El área del triángulo es: %.2lf\n", area);
    
    return 0;
}
