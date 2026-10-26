#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de comias mal colocadas*/
pieslice( 300, 150, 45, 225, 50 );
getch(); /* Pausa */
closegraph();
getch();
}
