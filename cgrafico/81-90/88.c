#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main() {
int driver = EGA,modo = EGAHI, imagentam;
void *imagen;
initgraph( &driver, &modo, "C:\\tc20\\BIN");/*error de las comias mal colocadas*/
setfillstyle( SLASH_FILL, 5 );
bar( 50, 50, 350, 300 );
imagentam = imagesize( 50, 50, 100, 100 );
imagen = malloc( imagentam );
getimage( 50, 50, 100, 100, imagen );
putimage( 400, 50, imagen, COPY_PUT );
getch();
putimage( 400, 110, imagen, COPY_PUT );
getch(); /* Pausa */
closegraph();
free( imagen );
getch();
}
