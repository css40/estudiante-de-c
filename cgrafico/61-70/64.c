#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA, modo = EGAHI,x_proporcion, y_proporcion;

initgraph( &driver, &modo, "C:\\TC20\\BIN");/*error de las comias mal colocadas*/
getaspectratio( &x_proporcion, &y_proporcion );
circle( 300, 150, 50 );
getch(); /* Pausa */
setaspectratio( 2*x_proporcion, y_proporcion );
circle( 300, 150, 50 );
getch(); /* Pausa */
closegraph();

getch();
}
