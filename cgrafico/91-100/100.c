#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <mouse.h>
void main()
{
    int adaptador = DETECT, modo, x, y;
    initgraph(&adaptador, &modo, "c:\\tc20\\BIN");
    do
    {
        mver();
        x = mxpos(1);
        y = mypos(1);
        if (mclick() == 1)
        {
            setcolor(GREEN);
            outtextxy(x + 30, y, "Diste un click izquierdo");
        }
        if (mclick() == 2)
        {
            setcolor(RED);
            outtextxy(x + 30, y, "Diste un click derecho");
        }
        delay(50);
        setcolor(BLACK);
        outtextxy(x + 30, y, "Diste un click izquierdo");
        outtextxy(x + 30, y, "Diste un click derecho");
    }
    while (!kbhit());
    closegraph();
    getch();
}