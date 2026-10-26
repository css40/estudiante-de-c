#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main() {
    int driver = EGA;
    int modo = EGAHI;
    struct palettetype *palette = NULL;
    int i;

    initgraph(&driver, &modo, "C:\\tc20\\BIN");
    
    /*Obtener la paleta*/
    palette = getpalettetype();

    /*Verificar si se obtuvo correctamente la paleta*/
    if (palette != NULL) {
        /*Imprimir información sobre la paleta*/
        printf("Paleta\n\nTamaño: %d\nColores: %d", palette->size, palette->colors[0]);
        for (i = 1; i < palette->size; i++) {
            printf(", %d", palette->colors[i]);
        }
        printf("\n");
    } else {
        printf("No se pudo obtener la paleta.\n");
    }


    getch();

  
    closegraph();
}
