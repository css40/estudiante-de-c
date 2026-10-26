#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int puntos[8] = { 300, 50, 500, 300, 100, 300, 300, 50 };
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
drawpoly( 4, puntos );
getch(); /* Pausa */
closegraph();
getch();
}