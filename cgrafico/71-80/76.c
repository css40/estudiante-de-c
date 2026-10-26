#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int anchura, altura;
char mensaje[5] = "Hola";
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
outtextxy(10,10,mensaje);
anchura = textwidth( mensaje );
altura = textheight( mensaje );
getch();
closegraph();
printf( "El mensaje: \"%s\" tiene de anchura: %d y altura: %d\n", mensaje,
anchura, altura );
printf( "Pulsa una tecla para continuar...\n" );
getch();
}