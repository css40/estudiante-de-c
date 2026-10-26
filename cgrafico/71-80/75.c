#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
setfillstyle( SOLID_FILL, 1 );
bar( 50, 50, 500, 300 );
setwritemode( COPY_PUT );
setcolor( 10 );
line( 20, 60, 220, 100 );
setwritemode( XOR_PUT );
line( 20, 80, 220, 120 );
getch();
closegraph();
getch();
}
