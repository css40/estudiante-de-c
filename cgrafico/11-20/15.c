#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI, x, y, color,fill;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
x = 20;
y = 20;
color = 1;
fill = 1;
do {
setfillstyle( fill, color );

bar( x, y, x+40, 320 );
x += 40;
y += 10;
color = (color+1) % 16;
fill = (fill+1) % 12;
} while( x < 620 );
getch(); /* Pausa */
closegraph();
}
