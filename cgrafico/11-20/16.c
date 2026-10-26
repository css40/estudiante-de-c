#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "c:\\tc20\\bin" );
setfillstyle( LTSLASH_FILL, 6 );
bar( 50, 50, 350, 300 );
getch(); /* Pausa */
closegraph();
}