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
/* Esta fuente ha de ser enlazada antes de poder registrarla
registerbgifont( sansserif_font );
*/
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de las comias mal colocadas*/
settextstyle( DEFAULT_FONT, 0, 2 );
outtextxy( 100, 50, mensaje );
settextstyle( DEFAULT_FONT, 1, 2 );
outtextxy( 200, 125, mensaje );
settextstyle( SANS_SERIF_FONT, 1, 3 );
outtextxy( 400, 150, mensaje );
getch();
closegraph();
getch();
}