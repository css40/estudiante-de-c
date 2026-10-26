#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver, modo;
/*detectgraph( &driver, &modo, );*/ /* si la descomento me da un error por estar declarandola devuelta */
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
circle( 300, 200, 80 );
getch(); /* Pausa */
closegraph();
printf( "Driver: %d\tModo: %d\n\n", driver, modo );
getch();
}