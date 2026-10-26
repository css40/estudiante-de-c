#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
char mensaje[40];
char nombre[25];
printf( "Escribe tu nombre: " );
scanf( "%s", nombre );
sprintf( mensaje, "Hola %s!", nombre );
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*Error de comias mal colocadas*/
outtext( mensaje );
outtextxy( 300, 150, mensaje );
getch();
closegraph();
getch();
}