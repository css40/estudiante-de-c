#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
struct linesettingstype info;
initgraph( &driver, &modo, "C:\\tc20\\bin" );
setlinestyle( DOTTED_LINE, 0xFF33, THICK_WIDTH );
circle( 350, 250, 50 );
getlinesettings( &info );
getch(); /* Pausa */
closegraph();
printf( "Líneas rectas.\nEstilo: %d\tTrama: %X\tGrosor: %d\n",
info.linestyle, info.upattern, info.thickness );
getch();
}