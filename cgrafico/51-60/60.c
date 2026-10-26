#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
outtext( "Esto es una prueba para cambiar entre modo gráfico..." );
getch();
restorecrtmode();
printf( "...y en modo texto.\nPulsa una tecla para volver\n" );
getch();
setgraphmode( modo );
rectangle( 200, 100, 400, 250 );
getch(); /* Pausa */
closegraph();
getch();
}