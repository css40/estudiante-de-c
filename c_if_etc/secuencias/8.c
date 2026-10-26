/*  Se desea calcular la cantidad de CD necesario para almacenar 
    toda la información el cual se encuentra en un disco 
    duro lleno de información, considere que la capacidad del disco
    duro esta expresado en GB,
    1GB es 1,024 MB y la capacidad máxima de un CD es de 700MB.
*/

#include <stdio.h>

int main() 
{
    double capacidad_disco_duro_gb;
    int cantidad_cds;
    const int capacidad_cd_mb = 700;

    printf("Ingrese la capacidad del disco duro en GB: ");
    scanf("%lf", &capacidad_disco_duro_gb);

    double capacidad_disco_duro_mb = capacidad_disco_duro_gb * 1024;
    
    cantidad_cds = capacidad_disco_duro_mb / capacidad_cd_mb;
    printf("Se necesitan %d CDs para almacenar toda la información del disco duro.\n", cantidad_cds);
    
    return 0;
}
