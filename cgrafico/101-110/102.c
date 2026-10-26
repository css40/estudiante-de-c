#include <graphics.h>
#include <conio.h>
#include <mouse.h>
void main()
{
    int adaptador = DETECT, modo;
    initgraph(&adaptador, &modo, "c:\\tc20\\BIN");
    setbkcolor(BLUE);
    do
    {
        setcolor(WHITE);
        outtextxy(210, 105, "pasa el mouse por encima del boton y veras el efecto");
        mver();
        rectangle(100, 100, 200, 120);
        if (minlimit(1, 100, 100, 200, 120) == 1)
        {
            outtextxy(310, 240, "Haz pulsado el raton por encima del boton");
            delay(50);
            setcolor(BLACK);
            outtextxy(310, 240, "Haz pulsado el raton por encima del boton");
        }
    } while (!kbhit());
    closegraph();
    getch();
}
