#include <graphics.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI, x, y;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
moveto( 300, 150 );
x = getx();
y = gety();
printf( "Cursor gráfico\n\nX: %d\tY: %d\n", x, y );/*estaba mal posicionado  estaba abjo de el cierre de grafico*/

/*hace falta la funcion getchar() para poder ver lo que imprime en pantalla el programa*/

getchar();/*uso getchar() por que si uso la funcion que siempre usamos me da un warning que es la funcion getch()*/
closegraph();

}
