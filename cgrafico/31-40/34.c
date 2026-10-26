#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI,color;
initgraph( &driver, &modo, "C:\\Tc20\\BIN" );
setcolor( 4 );
circle( 300, 150, 50 );
color = getcolor();
getch(); /* Pausa */
closegraph();
printf( "Color del perímetro: %d\n", color );
getch();
}
