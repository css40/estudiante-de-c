#include <graphics.h>
#include <conio.h>
#include <mouse.h>
void main()
{
    int adaptador = DETECT, modo;
    initgraph(&adaptador, &modo, "c:\\tc20\\BIN");
    do
    {
        outtextxy(100, 50, "Dibuj, el rect ngulo para que observaran el limite");
        rectangle(100, 100, 500, 400);
        mlimit(1, 100, 100, 500, 400);
        mver();
    }
    while (!kbhit());
    closegraph();
    getch();
}
