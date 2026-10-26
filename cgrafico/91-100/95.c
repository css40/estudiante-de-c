#include <graphics.h>
#include <conio.h>
#include <mouse.h>
void main()
{
    int adaptador = DETECT, modo;
    initgraph(&adaptador, &modo, "c:\\tc20\\BIN");
    do
    {
        mver();
        mocultar();/*le hacia falta punto y coma por eso daba error */
    } while (!kbhit());
    closegraph();
    getch();
}