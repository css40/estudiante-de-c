#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main() {
int driver = VGA;
int modo = EGAHI;
int x_max, y_max;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*Error de las comias no eran las adecuadas */
x_max = getmaxx();
y_max = getmaxy();
closegraph();
printf( "X maxima: %d\tY maxima: %d\n", x_max, y_max );
getch();
}