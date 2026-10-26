#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI,i;
struct palettetype palette;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
getpalette( &palette );
closegraph();
printf( "\t\t\t\t\tPaleta\n\nTama¤o: %d\n",palette.size);
printf("Colores: %d,",palette.colors[0] );
for( i=1; i<palette.size; i++ )
printf( "%d, ", palette.colors[i] );
printf( "\n" );
getch();
}