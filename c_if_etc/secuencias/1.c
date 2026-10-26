/*suma de dos numeros*/

#include <stdio.h>

int main() 
{
    double numero1, numero2;
    
    printf("Ingrese el primer número: ");
    scanf("%lf", &numero1);

    printf("Ingrese el segundo número: ");
    scanf("%lf", &numero2);
    
    double suma = numero1 + numero2;
    
    printf("La suma de %.2lf y %.2lf es %.2lf\n", numero1, numero2, suma);
    
    return 0;
}
