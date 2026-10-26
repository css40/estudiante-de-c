#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
circle( 300, 200, 80 );
getch(); /* Pausa */
closegraph();
}
