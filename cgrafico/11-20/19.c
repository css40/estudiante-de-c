#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI,trama, color;
int puntos[8] = { 300, 50, 500, 300, 100, 300, 300, 50 };
initgraph( &driver, &modo, "C:\\tc20\\bin" );
setcolor( 10 ); /*verde*/
drawpoly( 4, puntos );
trama = SLASH_FILL;
for(color = 0;color<=15;color++)
{
setfillstyle( trama, color );
floodfill( 400, 250, 10 );
getch();
}
getch(); /* Pausa */
closegraph();
}