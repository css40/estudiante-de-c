#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver =IBM8514LO,modo=IBM8514HI;
struct viewporttype info;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
getviewsettings( &info );
closegraph();
printf( "Pantalla\n\nIzquierda: %d\tSuperior: %d\tDerecha: %d\t Inferior: %d\tBanderín: %d\n",
info.left, info.top, info.right, info.bottom, info.clip);
getch();
}