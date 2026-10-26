#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI,color, relleno;
color = 10;
relleno = 11;
initgraph(&driver,&modo,"c:\\tc20\\bin");
setfillstyle( relleno, color );
bar3d( 100, 50, 300, 150, 25, 1 );

getch(); /* Pausa */
closegraph();
getch();
}
