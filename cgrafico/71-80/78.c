#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI,radio;
struct arccoordstype info_arco;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
for( radio=25; radio<=100; radio+=25 ) {
arc( 300, 150, 45, 315, radio );
getarccoords( &info_arco );
moveto( info_arco.xstart, info_arco.ystart );
lineto( info_arco.xend, info_arco.yend );
}
getch(); /* Pausa */
closegraph();
}