#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
void main() {
int driver = EGA, modo = EGAHI;
char *nombre;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
strcpy( nombre, getdrivername() );
circle( 300, 150, 50 );
getch(); /* Pausa */
closegraph();
printf( "Nombre del dispositivo gráfico: %s\n", nombre );
getch();
}
