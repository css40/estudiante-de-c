#include <graphics.h>
#include <conio.h>
void main() {

int driver = EGA;
int modo = EGAHI;
struct palettetype palette;
int size, temp, i, y=0;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*erro de las comias mal colocadas*/
getpalette( &palette );
size = palette.size;
for( i=0; i<size; i++ ) {
y += 30;
setcolor( palette.colors[i] );
line( 20, y, 520, y );
}
getch(); /* Pausa */
for( i=0; i<size/2; i++ ) {
temp = palette.colors[i];
palette.colors[i] = palette.colors[size-1-i];
palette.colors[size-1-i] = temp;
}
setallpalette( &palette );
getch(); /* Pausa */
closegraph();
getch();
}