#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int modo_bajo, modo_alto;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*error de comias mal posicionadas */
getmoderange( driver, &modo_bajo, &modo_alto );
closegraph();
printf( "Alcance de modos, de %d á %d\n", modo_bajo, modo_alto );

getch();
}