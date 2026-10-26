 /* Un vendedor tiene su sueldo base y recibe una comisión 
    del 10% del total de las Ventas del mes,
    él quiere saber cuánto ganará en un mes que tuvo X venta
 */

#include <stdio.h>

int main() 
{
    double sueldo_base, ventas, comision, salario_total;
    
    printf("Ingrese el sueldo base del vendedor: ");
    scanf("%lf", &sueldo_base);
    
    printf("Ingrese el monto total de ventas del mes: ");
    scanf("%lf", &ventas);
    
    comision = 0.10 * ventas;
    salario_total = sueldo_base + comision;

    printf("El salario total del vendedor es: %.2lf\n", salario_total);
    
    return 0;
}
