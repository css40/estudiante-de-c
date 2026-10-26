#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
struct fillsettingstype info;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
getfillsettings( &info );
bar( 50, 50, 350, 300 );
getch(); /* Pausa */
closegraph();
printf( "Trama de relleno: %d\tColor de relleno: %d\n", info.pattern, info.color );
getch();
}