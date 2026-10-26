/*  Una compañía de paquetería internacional tiene servicio en algunos países de América del Norte, 
    América Central, América del Sur, Europa y Asia. El costo por el servicio de paquetería se basa en 
    el peso del paquete y la zona a la que va dirigida. Lo anterior se muestra en la tabla: Zona 1 2 3 4 5 
    Ubicación América del Norte América Central América del Sur Europa Asia Costo/gramo $ll.oo $10.oo $12.oo $24.oo 
    $27.00 Parte de su política implica que los paquetes con un peso superior a 5 kg no son transportados, esto por
    cuestiones de logística y de seguridad. Realice un algoritmo para determinar el cobro por la entrega de 
    un paque-te o, en su caso, el rechazo de la entrega.
*/

#include <stdio.h>

int main() {
    int zona;
    double peso, costo_por_gramo, costo_total;

    printf("Ingrese la zona de destino (1: América del Norte, 2: América Central, 3: América del Sur, 4: Europa, 5: Asia): ");
    scanf("%d", &zona);

    if (zona < 1 || zona > 5) {
        printf("Zona no válida. Por favor, seleccione una zona válida.\n");
        return 1;
    }

   
    printf("Ingrese el peso del paquete (en gramos): ");
    scanf("%lf", &peso);

    if (peso > 5000) {
        printf("El paquete no puede ser transportado debido a que su peso es superior a 5 kg.\n");
        return 2; 
    }

    
    switch (zona) 
    {
        case 1:
            costo_por_gramo = 11.0 / 1000.0; /*$11.00 por gramo*/
            break;
        case 2:
            costo_por_gramo = 10.0 / 1000.0; /*$10.00 por gramo*/
            break;
        case 3:
            costo_por_gramo = 12.0 / 1000.0; /*$12.00 por gramo*/
            break;
        case 4:
            costo_por_gramo = 24.0 / 1000.0; /*$24.00 por gramo*/
            break;
        case 5:
            costo_por_gramo = 27.0 / 1000.0; /*$27.00 por gramo*/
            break;
    }

    costo_total = costo_por_gramo * peso;

    printf("El costo de la entrega a la zona %d es: $%.2lf\n", zona, costo_total);

    return 0; 
}

