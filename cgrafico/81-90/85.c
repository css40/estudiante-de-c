#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

void main() {
    int driver = EGA;
    int modo = EGAHI;
    void *imagen;
    int imagentam;

    initgraph(&driver, &modo, "C:\\tc20\\BIN"); /*error de las comillas mal colocadas*/
    setfillstyle(SLASH_FILL, 5);
    bar(50, 50, 350, 300);
    imagen = malloc(100 * 100);
    imagentam = imagesize(50, 50, 100, 100); 
    closegraph();

   
    if (imagen != NULL && imagentam > 0) {
        printf("Se ha reservado memoria para una imagen de tamaño %d bytes.\n", imagentam);
    }

    free(imagen); 

    getch();
}
/*En este ejemplo, se ha utilizado la variable imagen para reservar memoria 
para una imagen y imagentam para almacenar el tamaño de la imagen. Luego, se han utilizado ambas variables para 
imprimir un mensaje que indique el tamaño de la imagen. Esto debería resolver los warnings que eteniamos con las 
variables de imagen y imagentam*/