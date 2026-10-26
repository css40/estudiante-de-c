/*  Una empresa constructora vende terrenos 
    con la siguiente forma. 
    Realice un algoritmo para obtener el área respectiva
    del terreno para medidas de cualquier valor.
*/

#include <stdio.h>

int main() 
{
    int num_lados;
    double area = 0.0;

   
    printf("Ingrese el número de lados del terreno: ");
    scanf("%d", &num_lados);

   
    if (num_lados < 3) {
        printf("El terreno no puede tener menos de tres lados.\n");
        return 1;
    }

   
    double x[num_lados];
    double y[num_lados];

    printf("Ingrese las coordenadas de los vértices:\n");
    for (int i = 0; i < num_lados; i++) {
        printf("Vértice %d (x y): ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    for (int i = 0; i < num_lados - 2; i++) {
        double x1 = x[0];
        double y1 = y[0];
        double x2 = x[i + 1];
        double y2 = y[i + 1];
        double x3 = x[i + 2];
        double y3 = y[i + 2];

        
        double temp_area = 0.5 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));

        if (temp_area < 0) {
            temp_area = -temp_area;
        }

    
        area += temp_area;
    }

  
    printf("El área del terreno es: %.2lf unidades cuadradas\n", area);

    return 0;
}
