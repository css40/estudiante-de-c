#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main() {
    int driver = EGA, modo = EGAHI, i;
    struct palettetype palette;

    initgraph(&driver, &modo, "C:\\tc20\\BIN");
    getpalette(&palette);
    
    circle(300, 150, 50);
    getch(); /* Pausa */
    closegraph();

    printf("Paleta\n\nTamaño: %d\nColores: %d", palette.size, palette.colors[0]);
    for (i = 1; i < palette.size; i++)
        printf(", %d", palette.colors[i]);
    printf("\n");

    getch();
}
/*En este código, he utilizado getpalette en lugar de getpalettetype
 para obtener la paleta de colores. Además, he declarado palette como
  una estructura palettetype en lugar de un puntero a esta estructura.
 Con estos cambios, el código debería funcionar correctamente*/
