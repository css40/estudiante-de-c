/*Promedio de 4 Notas.*/

#include <stdio.h>

int main() 
{
    double nota1, nota2, nota3, nota4;
    
    printf("Ingrese la primera nota: ");
    scanf("%lf", &nota1);
    printf("Ingrese la segunda nota: ");
    scanf("%lf", &nota2);
    printf("Ingrese la tercera nota: ");
    scanf("%lf", &nota3);
    printf("Ingrese la cuarta nota: ");
    scanf("%lf", &nota4);
    double promedio = (nota1 + nota2 + nota3 + nota4) / 4.0;
    printf("El promedio de las notas es: %.2lf\n", promedio);
    
    return 0;
}
