#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int visual=1;
printf( "Instrucciones:\nPulsa el espacio para cambiar de pagina, cualquier otra tecla parasalir\n" );
printf( "(Pulsa cualquier tecla para entrar en modo grafico)\n" );
getch();
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
setactivepage( 0 );
setfillstyle( SOLID_FILL, 6 );
sector( 300, 150, 45, 315, 150, 50 );
setactivepage( 1 );
setfillstyle( SOLID_FILL, 6 );
sector( 300, 150, 90, 270, 150, 50 );
while( getch() == ' ' ) {
setvisualpage( visual );
visual = 0==visual ? 1 : 0;
}
closegraph();
getch();
}
