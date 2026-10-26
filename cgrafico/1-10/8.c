#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
ellipse( 300, 150, 45, 225, 100, 50 );
getch(); /* Pausa */
closegraph();
}