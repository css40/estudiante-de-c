#include <graphics.h>
#include <conio.h>
void main() {
int driver = VGA;
int modo = VGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
setcolor( 4 );
setviewport( 250, 150, 350, 250, 1 );
graphdefaults();
circle( 300, 200, 50 );
getch();
closegraph();
getch();
}