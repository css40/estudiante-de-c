#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int relleno, color;

initgraph( &driver, &modo, "C:\\tc20\\BIN" );
relleno = 1;
color = 1;
setlinestyle( SOLID_LINE, relleno, THICK_WIDTH );
circle( 300, 200, 80 );
getch(); /* Pausa */
setbkcolor( color );
cleardevice();
setlinestyle( SOLID_LINE, relleno, THICK_WIDTH );
circle( 400, 200, 20 );
getch(); /* Pausa */
closegraph();
getch();
}
