#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de las comias mal colocadas*/
settextjustify( RIGHT_TEXT, BOTTOM_TEXT );
moveto(300, 200);
outtext( "(RIGHT_TEXT, BOTTOM_TEXT)" );
settextjustify( RIGHT_TEXT, TOP_TEXT );
moveto(300, 200);
outtext( "(RIGHT_TEXT, TOP_TEXT)" );
settextjustify( LEFT_TEXT, BOTTOM_TEXT );
moveto(300, 200);

outtext( "(LEFT_TEXT, BOTTOM_TEXT)" );
settextjustify( LEFT_TEXT, TOP_TEXT );
moveto(300, 200);
outtext( "(LEFT_TEXT, TOP_TEXT)" );
setcolor( 1 );
line( 300, 200, 300, 100 );
setcolor( 2 );
line( 300, 200, 300, 300 );
setcolor( 3 );
line( 300, 200, 100, 200 );
setcolor( 4 );
line( 300, 200, 500, 200 );
getch();
closegraph();
getch();
}
