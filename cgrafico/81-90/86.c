#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main() {
int driver = EGA;
int modo = EGAHI;
void *imagen;
/*int imagentam;*/
initgraph( &driver, &modo, "C:\\tc20\\BIN");/*errores de las comias mal colocadas*/
setfillstyle( SLASH_FILL, 5 );
bar( 50, 50, 350, 300 );
imagen = malloc(imagesize( 50, 50, 100, 100 ));

/*imagentam = imagesize( 50, 50, 100, 100 );*/
free( imagen );
closegraph();
getch();
}
/*En este código, he eliminado la línea imagentam = imagesize(50, 50, 100, 100); 
para evitar el warning sobre la variable imagentam asignada pero nunca utilizada. 
Ahora el código debería compilar sin generar el warning.*/