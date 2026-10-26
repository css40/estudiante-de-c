#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA, modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
moveto( 20, 20 );
lineto( 40, 60 );
lineto( 80, 90 );
getch();
closegraph();
}
