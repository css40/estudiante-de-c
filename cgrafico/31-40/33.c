#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA, modo = EGAHI;
int x_proporcion, y_proporcion;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
getaspectratio( &x_proporcion, &y_proporcion );
circle( 300, 150, 50 );
getch(); /* Pausa */
closegraph();
printf( "Proporción anchura-altura.\nFactor x: %d\tFactor y: %d\n",
x_proporcion, y_proporcion );
getch();
}
