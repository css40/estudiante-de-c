#include <graphics.h>
#include <conio.h>
#include <mouse.h>
void main()
{
    int adaptador = DETECT, modo;
    initgraph(&adaptador, &modo, "c:\\tc20\\BIN");
    msituar(1, 310, 240); /*Coloca el cursor en el centro de la pantalla*/
    do
    {
        mver();
    } while (!kbhit());
    closegraph();
    getch();
}