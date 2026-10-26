/*  Una tienda ofrece un 15% de descuento por cada compra, 
    un cliente desea saber cuánto pagará por su compra.
*/

#include <stdio.h>

int main() 
{
    double precio_original, descuento, precio_con_descuento;
    
    printf("Ingrese el precio original del producto: ");
    scanf("%lf", &precio_original);  
    descuento = 0.15 * precio_original;
    precio_con_descuento = precio_original - descuento;
    
    printf("El precio con descuento del producto es: %.2lf\n", precio_con_descuento);
    
    return 0;
}
