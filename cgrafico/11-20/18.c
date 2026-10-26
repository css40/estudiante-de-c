#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI,trama, color;
int puntos[6] = { 300, 50, 500, 300, 100, 300 };
initgraph( &driver, &modo, "C:\\tc20\\bin" );
trama = SLASH_FILL;
for(color=0;color<=15;color++)
{
setfillstyle( trama, color );

fillpoly( 3, puntos );
getch();
}
getch(); /* Pausa */
closegraph();
}
/*Este programa te muestra los diferentes colores con una misma trama trata de
modificarlo para que obtengas todas las tramas con todos los colores*/
