#include <graphics.h>
#include <conio.h>
void main() {
int a = EGA,b = EGAHI,color;
initgraph( &a, &b, "C:\\tc20\\BIN" );
setviewport( 150, 150, 350, 350, 0 );
for( color = 0; color<16; color++ ) {
circle( 100, 100, 60 );
getch();
setbkcolor( color );
clearviewport();
}
getch(); /* Pausa */
closegraph();
}