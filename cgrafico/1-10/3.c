#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "c:\\tc20\\bin" );
line( 20, 40, 350, 100 );
line( 400, 30, 50, 250 );
getch();
closegraph();
}
