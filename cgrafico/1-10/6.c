#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI,radio;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
for( radio = 25; radio < 175; radio += 25 )
arc( 320, 175, 45, 135, radio );
getch(); /* Pausa */
closegraph();
}
