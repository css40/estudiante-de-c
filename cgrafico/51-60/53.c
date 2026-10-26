#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> /*Incluir para usar strcpy*/
void main() {
int driver = EGA;
int modo = EGAHI;
int codigo_error;
char mensaje_error[100];/*declaramos una matriz para eliminar el warinig */
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
setgraphmode( 40 ); /* Creamos un ERROR debe de ser 0 o 1*/
codigo_error = graphresult();
strcpy( mensaje_error, grapherrormsg( codigo_error ) );
closegraph();
printf( "ERROR: \"%s\" (%d)\n", mensaje_error, codigo_error );
getch();
}