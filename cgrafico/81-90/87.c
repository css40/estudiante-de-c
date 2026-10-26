#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main() {
int driver = EGA;
int modo = EGAHI;
void *imagen;
int imagentam;
initgraph( &driver, &modo, "C:\\tc20\\BIN");/*error de las comias malcolocadas*/
setfillstyle( SLASH_FILL, 5 );
bar( 50, 50, 350, 300 );
imagentam = imagesize( 50, 50, 100, 100 );
imagen = malloc( imagentam );
getimage( 50, 50, 100, 100, imagen );
free( imagen );
getch();
}
/*En este ejemplo solo conseguimos el tamaño de la imagen y guardamos la imagen en un
buffer*/