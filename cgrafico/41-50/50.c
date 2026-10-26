#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> /*Incluir para usar strcpy*/

void main() {

int driver = EGA;
int modo = EGAHI;
int codigo_error;
char mensaje_error[100];

initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de comias mal posicionadas */ 
setgraphmode( 40 ); /* Creamos un ERROR */

codigo_error = graphresult();
strcpy( mensaje_error, grapherrormsg( codigo_error ) );

closegraph();

printf( "ERROR: \"%s\" (%d)\n", mensaje_error, codigo_error );
getch();
}
/*Para solucionar estos problemas, primero debes asegurarte de incluir la declaración del prototipo 
de la función strcpy. Esto se hace incluyendo el archivo de cabecera <string.h>. Además, 
necesitas asignar memoria para la cadena mensaje_error antes de copiar una cadena en ella utilizando strcpy.*/