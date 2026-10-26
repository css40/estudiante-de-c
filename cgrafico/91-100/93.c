#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
void main(void)
{
int adaptador=DETECT,modo;
initgraph(&adaptador,&modo,"c:\\tc20\\bin");
while(!kbhit())
{
 putpixel(rand(),rand(),random(16));
}
}