#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA, modo = EGAHI, x, y, color;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*error de comias mal posicionadas */
x = 300;
y = 100;
setfillstyle( SOLID_FILL, 2 );
fillellipse( 300, 160, 50, 150 );
color = getpixel( x, y );
getch();
closegraph();
printf( "Colores\n\nEl color del pixel (%d,%d): %d\n", x, y, color );
getch();
}
