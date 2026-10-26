#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {

int driver = EGA, modo = EGAHI; /*El error era que estabamos declarando 3 veces la variable llamada modo*/

initgraph( &driver, &modo, "C:\\tc20\\BIN" );

modo = getgraphmode();
bar( 50, 50, 350, 300 );

getch(); /* Pausa */
closegraph();

printf( "Modo grafico: %d\n", modo );
getch();
}