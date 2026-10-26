#include <graphics.h>
#include <conio.h>
# include <dos.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI,i;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
setcolor(BLUE);
i=1;
do{ delay(100);/*lo cambie  de 30000 a 100 para que sea mas rapida la animacion */
rectangle(10+i,10,100+i,100);
setfillstyle(i,BLUE);
floodfill(20,20,BLUE);
i++;
}while(!kbhit());
}