#include <graphics.h>
# include<conio.h>
#include <stdio.h>
void main() {
int driver = VGA, modo = VGAHI;
struct viewporttype info;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
getviewsettings( &info );
closegraph();
printf( "\t\t\t\tPantalla\n\nIzquierda: %d\tSuperior: %d\tDerecha: %d\t"
"Inferior: %d\tBander¢n: %d\n",
info.left, info.top, info.right, info.bottom, info.clip );
getch();
}
