/*  hay 5 códigos promocionales distintos: ‘PlusOro’, ‘Platino33’, ‘100Max’,
    ‘SuperSilver’ y ‘TotalBronce’ que descuentan respectivamente 25, 20, 15, 10
    y 5 $. Realice un algoritmo que elabore el descuento de un artículo dependiendo
    del código promocional y diga el total a pagar.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char codigo[20];
    double precio, descuento, total;

    printf("Ingrese el código promocional: ");
    scanf("%s", codigo);

    printf("Ingrese el precio del artículo: $");
    scanf("%lf", &precio);

    if (strcmp(codigo, "PlusOro") == 0)
    {
        descuento = 25.0;
    }
    else if (strcmp(codigo, "Platino33") == 0)
    {
        descuento = 20.0;
    }
    else if (strcmp(codigo, "100Max") == 0)
    {
        descuento = 15.0;
    }
    else if (strcmp(codigo, "SuperSilver") == 0)
    {
        descuento = 10.0;
    }
    else if (strcmp(codigo, "TotalBronce") == 0)
    {
        descuento = 5.0;
    }
    else
    {
        printf("Código promocional no válido. No se aplicará descuento.\n");
        descuento = 0.0;
    }

    total = precio - descuento;
    printf("Total a pagar después del descuento: $%.2lf\n", total);

    return 0;
}
