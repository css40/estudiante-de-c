#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA, modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
lineto( 100, 100 );
outtextxy( 15, 5, "Inicial" );
getch();
setviewport( 250, 200, 450, 300, 0 );
setcolor( 9 );
lineto( 100, 100 );
outtextxy( 15, 5, "Nueva" );
moveto( 0, 0 );
lineto( -50, -20 ); /* Fuera del área */
getch();
setviewport( 250, 200, 450, 300, 1 );
setcolor( 4 );
moveto( 120, 40 );
lineto( 150, -20 ); /* Fuera del área */
outtextxy( 25, 15, "Con recorte" );
getch(); /* Pausa */
closegraph();
getch();
}