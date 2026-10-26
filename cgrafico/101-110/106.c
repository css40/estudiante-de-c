#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
void inicializar(void);
void juego_visual(void);
void fondo_de_la_pantalla(void);
void mover(void);
void main(void)
{
    inicializar();
    juego_visual();
    cleardevice();
    fondo_de_la_pantalla();
    mover();
    getch();
    restorecrtmode();
}
void inicializar(void)
{
    int adaptor = DETECT, modo, codigo;
    printf("desea seguir viendo los graficos");
initgraph(&adaptor,&modo,"c:\\tc20\\bin");
if((codigo=graphresult())!=0)

{
        printf("%s", grapherrormsg(codigo));
        exit(1);

}
}
void juego_visual(void)
{
    int i;
    setbkcolor(BLUE);
    setcolor(YELLOW);
    outtextxy(5, 5, "Cargando programa de movimiento grafico");
    rectangle(21, 20, 450, 30);
    sleep(1);
    for (i = 11; i <= 430; i++)
    {
        bar(10 + i, 20, 20 + i, 30);
        delay(50);
        if (i == 430)
        {
            moveto(480, 400);
            outtext("programa Cargado");
        }
    }
    sleep(1);
}
void mover(void)
{
    void far *buffer;
    int i;
    setcolor(WHITE);
    buffer = malloc(imagesize(127, 98, 172, 143));
    /*rectangle(127,98,172,143);*/
    i = 100;
    while (!kbhit())
    {
    ala:
        circle(127 + i, 180, 20);
        getimage(107 + i, 160, 147 + i, 200, buffer);
        sleep(1);
        putimage(107 + i, 160, buffer, XOR_PUT);
        i += 10;
        if (i == 300)
        {
            i = 100;
            goto ala;
        }
    }
    free(buffer);
}
void fondo_de_la_pantalla(void)
{
    setbkcolor(BLUE);
    setcolor(LIGHTBLUE);
    rectangle(1, 1, getmaxx() - 1, getmaxy() - 1);
    setcolor(LIGHTGRAY);
    rectangle(6, 5, 634, 20);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(10, 7, LIGHTGRAY);
    setcolor(BLUE);
    rectangle(5, 5, 100, 20);
    setcolor(RED);
    outtextxy(8, 11, "N");
    setcolor(BLACK);
    outtextxy(17, 11, "uevo Juego");
    setcolor(BLUE);
    rectangle(110, 5, 160, 20);
    setcolor(RED);
    outtextxy(116, 11, "S");
    setcolor(BLACK);
    outtextxy(124, 11, "alir");
}
