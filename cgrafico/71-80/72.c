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
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*erro de las comias mal colocadas*/
settextstyle( SANS_SERIF_FONT, 0, 0 );
setusercharsize( 1, 4, 1, 2 ); /* 25% de ancho; 50% de alto */
outtextxy( 100, 50, mensaje );
settextstyle( SANS_SERIF_FONT, 0, 1 );
outtextxy( 100, 125, mensaje );
settextstyle( SANS_SERIF_FONT, 1, 0 );
setusercharsize( 1, 2, 3, 4 ); /* 50% de ancho; 75% de alto */
outtextxy( 400, 150, mensaje );
getch();
closegraph();
getch();
}