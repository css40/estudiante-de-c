# include <graphics.h>
# include <dos.h>
# include <stdlib.h>
# include <conio.h>
void main(){
int driver=DETECT,modo,i;
initgraph(&driver,&modo,"c:\\tc20\\BIN");
i=0;
do
{
setcolor(i);
circle(random(639),random(479),random(i+8));/*Random definida en stdlib*/
delay(100); /*Detiene la ejecución del programa durante 30000 milisegundos*/
/*cambie loa 30000 milisegundos para que la animacion se acelerara mas */
i=(i<16)?i:0;
i++;
}while(!kbhit());
} 
