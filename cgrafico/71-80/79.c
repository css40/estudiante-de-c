#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int gdriver = EGA,gmodo = EGAHI;
struct fillsettingstype info;
initgraph( &gdriver, &gmodo, "C:\\tc20\\BIN" );
getfillsettings( &info );
bar( 50, 50, 350, 300 );
getch(); /* Pausa */
closegraph();
printf( "Trama de relleno: %d\tColor de relleno: %d\n",

info.pattern, info.color );
getch();
}