#include <graphics.h>
#include <conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
int buf_inicial, buf_nuevo=10000;
initgraph( &driver, &modo, "C:\\TC20\\BIN");/*eror de las comias mal colocadas*/
buf_inicial = setgraphbufsize( buf_nuevo );
closegraph();
printf( "Bufer inicial: %d\tBufer nuevo: %d\n", buf_inicial, buf_nuevo );
getch();
}