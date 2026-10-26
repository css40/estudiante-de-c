#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void far _graphfreemem( void far *ptr, unsigned tamanyo ) {
printf( "__graphfreemem ha sido llamado para "
"desadjudicar %d bytes en memoria\n" );
printf( "para el montón (heap) interno\n", tamanyo );
printf( "Pulse cualquier tecla...\n\n" );
getch();
free( ptr );
}
void far * far _graphgetmem( unsigned tamanyo ) {
printf( "__graphgetmem ha sido llamado para "
"adjudicar %d bytes en memoria\n" );
printf( "para el montón (heap) interno\n", tamanyo );
printf( "Pulse cualquier tecla...\n\n" );
getch();
return malloc( tamanyo );
}
void main() {
int driver = EGA, modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN");
circle( 200, 100, 50 );
getch();
closegraph();
getch();
}