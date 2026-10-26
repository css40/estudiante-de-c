#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA,modo = EGAHI,t;
initgraph( &driver, &modo, "c:\\tc20\\bin" );/* error por las comias no eran las adecuadas */
for( t=0; t<200; t++ )
putpixel( 100+t, 50+t, t%16 );
getch();
closegraph();
}
