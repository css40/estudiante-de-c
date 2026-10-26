#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI,color;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
setbkcolor( 4 );
circle( 300, 150, 50 );
color = getbkcolor();
getch(); /* Pausa */
closegraph();
printf( "Color de fondo: %d\n", color );

getch();
}