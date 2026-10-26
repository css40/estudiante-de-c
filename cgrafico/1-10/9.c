#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" ); /*Error de las comias no eran las adecuadas */
setbkcolor( 4 );
circle( 300, 150, 50 );
getch(); /* Pausa */
closegraph();
getch();
}
