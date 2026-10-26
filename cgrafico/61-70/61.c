#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de las comias mal colocadas*/
setfillstyle( SOLID_FILL, 6 );
sector( 300, 150, 45, -45, 150, 50 );
getch(); /* Pausa */
closegraph();
getch();
}
