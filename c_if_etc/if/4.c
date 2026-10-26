/*  El banco “Pueblo desconocido” ha decidido aumentar el límite de crédito
    de las tarjetas de crédito de sus clientes, para esto considera que, si su 
    cliente tiene tarjeta tipo 1, el aumento será de 25 %; si tiene tipo 2, será 
    de 35 %; si tiene tipo 3, de 40 %. Ahora bien, determine el nuevo techo de 
    crédito que tendrá una persona en su tarjeta, visualice el techo actual y el monto que aumento.
*/


#include <stdio.h>

int main()
{
    int tipoTarjeta;
    float techoActual, aumento, nuevoTecho;
    
    printf("Ingrese el tipo de tarjeta (1, 2 o 3): ");
    scanf("%d", &tipoTarjeta);
    printf("Ingrese el techo de credito actual: $");
    scanf("%f", &techoActual);

    switch (tipoTarjeta) {
        case 1:
            aumento = techoActual * 0.25;
            break;
        case 2:
            aumento = techoActual * 0.35;
            break;
        case 3:
            aumento = techoActual * 0.40;
            break;
        default:
            printf("Tipo de tarjeta no válido.\n");
            return 1; 
    }
    nuevoTecho = techoActual + aumento;
    printf("Techo de credito actual: $%.2f\n", techoActual);
    printf("Monto del aumento: $%.2f\n", aumento);
    printf("Nuevo techo de credito: $%.2f\n", nuevoTecho);

    return 0;
}
