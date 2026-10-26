#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;

initgraph( &driver, &modo, "C:\\tc20\\BIN");/*las comias estaban mal posicionadas */
circle( 300, 200, 80 );
getch(); /* Pausa */
closegraph();
getch();
}