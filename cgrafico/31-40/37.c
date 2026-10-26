#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
char trama1[8] = { 0x33, 0xEE, 0x33, 0xEE, 0x33, 0xEE, 0x33, 0xEE };
char trama2[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
initgraph( &driver, &modo, "C:\\tc20\\bin" );
getfillpattern( trama2 );
bar( 50, 50, 150, 150 );
setfillpattern( trama1, 9 );
bar( 160, 50, 260, 150 );
setfillpattern( trama2, 4 );
bar( 105, 160, 205, 260 );
getch(); /* Pausa */
closegraph();
getch();
}