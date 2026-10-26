#include <graphics.h>
#include <conio.h>
#include <mouse.h>
#include <stdlib.h>
void main(void)
{
    int adaptador = DETECT, modo;
    int x, y;
    char *strx, *stry;
    initgraph(&adaptador, &modo, "c:\\tc20\\bin");
    setbkcolor(BLUE);

     /*Asigna memoria dinámica para strx y stry*/
    strx = (char *)malloc(20 * sizeof(char)); 
    stry = (char *)malloc(20 * sizeof(char));
    while (!kbhit())
    {
        setfillstyle(SOLID_FILL, BLUE);
        mver();
        x = mxpos(1);
        y = mypos(1);
        itoa(x, strx, 10);
        itoa(y, stry, 10);
        outtextxy(100, 100, strx);
        outtextxy(100, 120, stry);
        if (x != mxpos(1) || y != mypos(1))
        {
            setcolor(BLUE);
            outtextxy(100, 100, strx);
            outtextxy(100, 120, stry);
            setcolor(WHITE);
        }
    }
    free(strx);
    free(stry);
}
/*Para solucionar estos warnings, necesitas asignar memoria dinámica para las 
variables strx y stry antes de usarlas con la función itoa.*/