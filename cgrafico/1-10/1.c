#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*solo eran las comias que causaba el error*/
circle( 300, 200, 80 );
getch(); /* Pausa */
closegraph();
getch();
}
