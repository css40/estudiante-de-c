#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
registerbgidriver(IBM8514LO);
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
rectangle( 20, 20, 400, 300 );
getch(); /* Pausa */
closegraph();
getch();
}
