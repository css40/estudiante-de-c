/*  Una empresa desea saber cuánto dinero le tiene que dar
    a un trabajador que viajara en nombre de la empresa, 
    si estará fuera X días y la empresa asumirá los rubros 
    de: Hospedaje, Alimentación y 100 de bolsillo por día de viaje, 
    muestre las cantidades desglosadas en: 
    Total del CK para Hospedaje, Alimentación y bolsillo.
*/

#include <stdio.h>

int main() 
{
    double gasto_hospedaje, gasto_alimentacion, bolsillo_por_dia;
    int dias_de_viaje;
    

    printf("Ingrese el gasto de hospedaje por día: ");
    scanf("%lf", &gasto_hospedaje);
    
    printf("Ingrese el gasto de alimentación por día: ");
    scanf("%lf", &gasto_alimentacion);
    
    printf("Ingrese la asignación de bolsillo por día: ");
    scanf("%lf", &bolsillo_por_dia);
    
    printf("Ingrese la cantidad de días de viaje: ");
    scanf("%d", &dias_de_viaje);
    
   
    double total_hospedaje = gasto_hospedaje * dias_de_viaje;
    double total_alimentacion = gasto_alimentacion * dias_de_viaje;
    double total_bolsillo = bolsillo_por_dia * dias_de_viaje;
    
    double total_cheque = total_hospedaje + total_alimentacion + total_bolsillo;
    
    printf("\nDesglose del cheque:\n");
    printf("Total para Hospedaje: %.2lf\n", total_hospedaje);
    printf("Total para Alimentación: %.2lf\n", total_alimentacion);
    printf("Total para Bolsillo: %.2lf\n", total_bolsillo);
    printf("\nTotal del cheque: %.2lf\n", total_cheque);
    
    return 0;
}
/*El tipo de datos `double` en el lenguaje C se utiliza para representar números en coma flotante de doble precisión. 
Los números en coma flotante son números reales que pueden tener una parte fraccionaria, lo que los hace adecuados para representar valores que no son enteros, 
como números decimales o números con valores fraccionarios.
El `double` se llama "doble precisión" porque proporciona más precisión que el tipo de datos `float`, 
que es de "precisión simple". Los números `double` se almacenan utilizando 64 bits en la mayoría de las implementaciones de C,
 lo que significa que pueden representar una amplia gama de valores con una alta precisión.
`double` se utiliza comúnmente en C para:
1. Representar números con decimales: Por ejemplo, para almacenar valores monetarios (como 12.34 dólares) o medidas precisas (como 3.14159265).
2. Realizar cálculos científicos y matemáticos: Para representar valores reales en ecuaciones y cálculos numéricos que requieren alta precisión.
3. Almacenar valores muy grandes o muy pequeños: `double` puede manejar números en un rango amplio, desde números muy pequeños (cerca de cero) hasta números muy grandes (con un gran número de dígitos).
4. Trabajar con bibliotecas y funciones que requieren precisión: Muchas funciones matemáticas y científicas en C, como las de la biblioteca math.h,
 devuelven o toman argumentos de tipo `double` para garantizar resultados precisos.
En resumen, `double` se utiliza para representar números en coma flotante de alta precisión en C, lo que lo hace adecuado para una amplia gama de aplicaciones que requieren cálculos precisos con valores no enteros.*/