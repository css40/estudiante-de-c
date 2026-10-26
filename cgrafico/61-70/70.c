#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
struct palettetype palette;
int size, i, y=0;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de las comias mal colocadas*/
getpalette( &palette );
size = palette.size;
for( i=0; i<size; i++ ) {
y += 30;
setcolor( palette.colors[i] );
line( 20, y, 520, y );
}
getch(); /* Pausa */
for( i=0; i<size; i++ )
setrgbpalette( i, 2*i+33, 42, 63-4*i ); /* Tonos de naranja y azul */
getch(); /* Pausa */
closegraph();
getch();
}