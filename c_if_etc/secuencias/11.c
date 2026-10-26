/*  Una compañía de agua requiere determinar el pago que debe realizar una persona por e
    l total de metros cúbicos
    que consume de agua al llenar una piscina de la siguiente forma.
*/

#include <stdio.h>

int main()
{
    double costo_por_metro_cubico, metros_cubicos_consumidos, monto_total;

    printf("Ingrese el costo por metro cúbico de agua: ");
    scanf("%lf", &costo_por_metro_cubico);
    printf("Ingrese la cantidad de metros cúbicos consumidos para llenar la piscina: ");
    scanf("%lf", &metros_cubicos_consumidos);
    monto_total = costo_por_metro_cubico * metros_cubicos_consumidos;
    printf("El monto total a pagar por el consumo de agua es: %.2lf\n", monto_total);

    return 0;
}
