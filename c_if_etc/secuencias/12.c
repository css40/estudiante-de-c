/*  Un productor de leche lleva el 
    registro de lo que produce en Lt. Pero 
    cuando lo vende se lo pagan en galones cuánto recibirá por la 
    entrega de su producción en un día, 
    considere que 1 galón equivale a 3.785lt.  
*/


#include <stdio.h>

int main() 
{
    double litros_producidos, galones_recibidos;
    
    printf("Ingrese la cantidad de litros producidos en un día: ");
    scanf("%lf", &litros_producidos);
    
    /*Calcular la cantidad de galones recibidos (litros / 3.785)*/
    galones_recibidos = litros_producidos / 3.785;
    printf("El productor recibirá %.2lf galones por la entrega de su producción.\n", galones_recibidos);
    
    return 0;
}
