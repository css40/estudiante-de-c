/*  El banco “Pueblo desconocido” ha decidido aumentar el límite de crédito
    de las tarjetas de crédito de sus clientes, para esto considera que si su cliente
    tiene tarjeta tipo 1, el aumento será de 25 %; si tiene tipo 2, será de 35 %; si 
    tiene tipo 3, de 40 %, y para cualquier otro tipo, de 50 %. Ahora bien. Realice un 
    algoritmo y represente su diagrama de flujo y el pseudocódigo para determinar el nuevo 
    ímite de crédito que tendrá una persona en su tarjeta. y visualice el nombre del cliente,
    la clasificación actual de su tarjeta el techo actual y el monto del aumento y el nuevo techo de su tarjeta.
*/


#include <stdio.h>

int main() 
{

    char nombre_cliente[50];
    int tipo_tarjeta;
    double limite_actual, aumento, nuevo_limite;

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nombre_cliente);

    printf("Ingrese el tipo de tarjeta (1, 2, 3 u otro): ");
    scanf("%d", &tipo_tarjeta);

    printf("Ingrese el límite de crédito actual: ");
    scanf("%lf", &limite_actual);

    switch (tipo_tarjeta) {
        case 1:
            aumento = 0.25;
             /*25%*/ 
            break;
        case 2:
            aumento = 0.35; 
             /*35%*/
            break;
        case 3:
            aumento = 0.40;  
            /*40%*/
            break;
        default:
            aumento = 0.50;  
            /*50% para cualquier otro tipo*/
    }
    nuevo_limite = limite_actual + (limite_actual * aumento);

    printf("\nCliente: %s\n", nombre_cliente);
    printf("Tipo de tarjeta: %d\n", tipo_tarjeta);
    printf("Techo actual: $%.2lf\n", limite_actual);
    printf("Monto del aumento: $%.2lf\n", limite_actual * aumento);
    printf("Nuevo techo de la tarjeta: $%.2lf\n", nuevo_limite);

    return 0;
}
