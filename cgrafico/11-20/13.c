#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI,x_max;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
x_max = getmaxx();
closegraph();
printf( "X maxima: %d\n", x_max );
getch();
}