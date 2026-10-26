#include <graphics.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI, x, y;

initgraph( &driver, &modo, "C:\\TC20\\BIN" );/*error de las comias no eran las adecuadas */
moveto( 300, 150 );
x = getx();
y = gety();
printf( "Cursor gráfico\n\nX: %d\tY: %d\n", x, y );/*estaba mal posicionado  estaba abjo de el cierre de grafico*/

getchar();
/*uso getchar() por que si uso la funcion que siempre usamos me da un warning que es la funcion getch()*/
closegraph();

}
