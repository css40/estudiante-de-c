#include<graphics.h>
#include<conio.h>
#include<mouse.h>

void main(){
int adaptador=DETECT,modo;
initgraph(&adaptador,&modo,"c:\\tc20\\BIN");
do{
mver();
 }while(!kbhit());
closegraph();
getch();
}
