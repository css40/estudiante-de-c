#include <mouse.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define ESC 27
void main()
{
    int a = DETECT, b;
    int posx, posy, h, z = 0;
    initgraph(&a, &b, "c:\\tc20\\bin");
    setcolor(YELLOW);
    outtextxy(10, 10, "a) click izq sostenido para dibujar ");
    outtextxy(10, 20, "b) click izq dibuja una linea desde la pos. anterior hasta la nueva pos.");
outtextxy(10,30,"c) presionar una vez click der indica que se escogera un nuevo puntodonde");
outtextxy(10,40," empezara a dibujar el click debe ser fuera del dibujo en caso contrario");
outtextxy(10,50," se borrara");
outtextxy(10,60,"d) click der sostenido para borrar");
outtextxy(10,70,"e) presiona una tecla para salir o click si no has empezado ha dibujar");

outtextxy(10,420,"Hecho por:");
settextstyle(4,0,1);
outtextxy(10,430," Bismarck Salvador Tra¤a L¢pez");
outtextxy(10+textwidth("Hecho por: "),450,"Juan Carlos Guti,rrez Barquero");
while(mclick()!=1)
{
        setcolor(WHITE);
        rectangle(100, 100, getmaxx() - 100, getmaxy() - 100);
        mver();
        posx = mxpos(1);
        posy = mypos(1);
}
while(!kbhit())
{
        setcolor(WHITE);
        mlimit(1, 100, 100, getmaxx() - 100, getmaxy() - 100);
        rectangle(100, 100, getmaxx() - 100, getmaxy() - 100);
        mver();
        mocultar();
        if (mclick() == 1)
        {
            if (z == 1)
            {
                z = 0;
                posx = mxpos(1);
                posy = mypos(1);
            }
            line(posx, posy, mxpos(1), mypos(1));
            posx = mxpos(1);
            posy = mypos(1);
        }
        else if (mclick() == 2)
        {
            z = 1;
            setcolor(BLACK);
            for (h = 0; h <= 20; h++)
                circle(mxpos(1), mypos(1), h);
            floodfill(mxpos(1), mypos(1), BLACK);
        }
        mlimit(1, 100, 100, getmaxx() - 100, getmaxy() - 100);
}
clrscr();
}