#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
moveto( 20, 20 );
linerel( 20, 40 );
moverel( 50, 50 );
linerel( 40, 30 );
getch();
closegraph();
}
