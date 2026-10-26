#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*eror de las comias mal colocadas*/
setlinestyle( DOTTED_LINE, 0, THICK_WIDTH );
line( 200, 300, 400, 50 );
getch(); /* Pausa */
closegraph();
getch();
}