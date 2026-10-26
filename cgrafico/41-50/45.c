#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int num_colores;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*error de comias mal posicionadas */
num_colores = getpalettesize();
closegraph();
printf( "Paleta\n\nNumero de colores: %d\n", num_colores );
getch();
}
