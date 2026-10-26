#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
rectangle( 20, 20, 400, 300 );
getch(); /* Pausa */
closegraph();
}
