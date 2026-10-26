/*  Una empresa recolectora de café les da un incentivo a sus trabajadores 
    si la producción promedio de la semana es mayor a 100 toneladas, considere 
    que el día de descanso de los trabajadores es el día domingo, se necesita 
    un algoritmo para saber si un trabajador recibirá incentivo o no y que le 
    diga cuanto le falto para recibir el incentivo.
*/



#include <stdio.h>

int main() 
{
    int produccionSemana[6]; 
    float produccionPromedio = 0.0;
    int diaDescanso = -1; 
    
    for (int i = 0; i < 6; i++) {
        printf("Ingrese la producción del día %d: ", i + 1);
        scanf("%d", &produccionSemana[i]);
        produccionPromedio += produccionSemana[i];
        
        if (produccionSemana[i] == 0) {
            diaDescanso = i;
        }
    }    
    produccionPromedio /= 6.0;

    if (diaDescanso != -1 && produccionPromedio > 100) {
        printf("El trabajador recibirá un incentivo.\n");
    } else {
        if (diaDescanso == -1) {
            printf("Error: No se especificó el día de descanso (domingo).\n");
        } else {
            
            float faltante = 100.0 - produccionPromedio;
            printf("El trabajador no recibirá el incentivo.\n");
            printf("Le faltaron %.2f toneladas para recibir el incentivo.\n", faltante);
        }
    }
    
    return 0;
}
