#include <graphics.h>
#include <conio.h>
void inicializar(void);
void main() {
int trama, color;
inicializar();
trama = SOLID_FILL;
color = 4;
setfillstyle( trama, color );
fillellipse( 300, 150, 100, 50 );
getch(); /* Pausa */
closegraph();
}
void inicializar(void)
{
int driver = EGA,modo = EGAHI;
initgraph( &driver, &modo, "C:\\tc20\\BIn" );
}
