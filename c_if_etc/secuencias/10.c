/*  Se requiere determinar el sueldo semanal 
    de un trabajador con base a las horas 
    trabajadas y el pago por hora que recibe. 
*/

#include <stdio.h>

int main() 
{
    double horas_trabajadas, pago_por_hora, sueldo_semanal;
    
    printf("Ingrese las horas trabajadas en la semana: ");
    scanf("%lf", &horas_trabajadas);
    printf("Ingrese el pago por hora: ");
    scanf("%lf", &pago_por_hora);

    sueldo_semanal = horas_trabajadas * pago_por_hora;

    printf("El sueldo semanal del trabajador es: %.2lf\n", sueldo_semanal);
    
    return 0;
}
