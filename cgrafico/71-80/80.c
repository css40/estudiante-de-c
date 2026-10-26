#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int gdriver = EGA;
int gmodo = EGAHI;
struct linesettingstype info;
initgraph( &gdriver, &gmodo, "C:\\tc20\\BIN" );
setlinestyle( DOTTED_LINE, 0xFF33, THICK_WIDTH );
circle( 350, 250, 50 );
getlinesettings( &info );
getch(); /* Pausa */
closegraph();
printf( "Líneas rectas.\nEstilo: %d\tTrama: %X\tGrosor: %d\n",info.linestyle, info.upattern,
info.thickness );
getch();
}