#include <conio.h>
#include <dos.h>
#include <process.h>
#include <stdlib.h>
#include <graphics.h>
#define WHITE 15
void marco(int *, int *, int *, int *, int *);
void estrellas(int *, int *);
void ambiente(void);
void ambientedos(void);
void montana(void);
void cometas(void);
void main()
{
    /*INICIALIZAR EL MODO GRAFICO DE MANERA RAPIDA*/
    int a = DETECT, b;
    int x1 = 0, y1 = 0, x2 = 640, y2 = 480, color = 6;
    int y = 0, x = 0;

    initgraph(&a, &b, "c:\\tc20\\bin");
  
    ambiente();
    ambientedos();
    marco(&x1, &y1, &x2, &y2, &color);
    estrellas(&x, &y);
    montana();
    cometas();
    getch();
}
void ambiente(void)
{
    int x = 50, y = 480;
    setbkcolor(BLUE);
    setcolor(LIGHTGRAY);
    rectangle(0, 0, 639, 479);
    moveto(x, y);
    setcolor(LIGHTGRAY);
    lineto(100, 450);
    lineto(150, 400);
    lineto(210, 370);
    lineto(0, 370);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(1, 470, LIGHTGRAY);
}
void ambientedos(void)
{
    setcolor(BROWN);
    moveto(105, 370);
    lineto(125, 350);
    lineto(155, 365);
    lineto(155, 360);
    lineto(125, 345);
    lineto(55, 345);
    lineto(22, 370);
    lineto(105, 370);
    setfillstyle(6, BROWN);
    floodfill(50, 350, BROWN);
    setcolor(BROWN);
    rectangle(30, 365, 110, 400);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(50, 385, BROWN);
    line(150, 362, 150, 382.5); /*linea lateral | */
    line(110, 400, 150, 382.5); /*union de la linea lateral con la casa*/
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(112, 385, BROWN);
    setcolor(RED);
    line(130, 367, 140, 364); /*ventana arriba --*/
    line(130, 377, 140, 374); /*ventana abajo __*/
    line(130, 367, 130, 377); /*lado derecha | */
    line(140, 364, 140, 374); /*lado izquierdo | */
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(135, 368, RED);
    line(112, 398, 112, 378);   /*puerta arriba*/
    line(112, 378, 120, 374);   /*puerta lado izquierdo*/
    line(120, 374, 120.5, 395); /*puerta lado derecho*/
    line(112, 397, 120.5, 394); /*puerta abajo*/
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(114, 380, RED);
    line(110, 365, 110, 400);
    setcolor(YELLOW);
    arc(310, 300, 90, 270, 30);
    ellipse(310, 300, 90, 270, 05, 30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 300, YELLOW);
}
void marco(int *x1, int *y1, int *x2, int *y2, int *color)
{
    setbkcolor(BLUE);
    setcolor(*color);
    rectangle(*x1, *y1, *x2, *y2);
}
void estrellas(int *x, int *y)
{
    int i, px = *x, py = *y, color, t;
    setcolor(YELLOW);
    arc(310, 180, 90, 270, 30);
    ellipse(310, 180, 90, 270, 05, 30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 180, YELLOW);
    color = getcolor();
    t = 1;
    for (i = 0; i <= 400; i++)
    {
        montana();
        setcolor(GREEN);
        putpixel(px, py, color);
        putpixel(px + 10, py + 50, WHITE);
        px = (rand() % 640);
        py = (rand() % 200);
        if (i >= 230)
            continue;
        else
        {
            putpixel(310, (480 - t) - 12, RED);
            putpixel(310, (480 - t) - 9, YELLOW);
            putpixel(310, (480 - t), BLUE);
            putpixel(t + 1, 100, RED);
            putpixel(t - 5, 100, YELLOW);
            putpixel(t - 11, 100, BLUE);
            putpixel(t + 1, 50, RED);
            putpixel(t - 5, 50, YELLOW);
            putpixel(t - 11, 50, BLUE);
            t += 3;
        }
        delay(50);
    }
}
void montana()
{
    setcolor(LIGHTGRAY);
    line(0, 250, 494, 250);   /*linea del lago superior */
    line(480, 250, 560, 200); /*monta¤a / */
    line(560, 200, 639, 250); /* monta¤a\ */
    line(480, 250, 639, 250); /* monta¤a ___ */
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    floodfill(590, 230, LIGHTGRAY);
}
void cometas(void)
{
    int i, t;
    do
    {
        t = 1;
        for (i = 0; i <= 450; i++)
        {
            if (i >= 230)
                continue;
            else
            {
                putpixel(t + 3, 65, RED);
                putpixel(t - 3, 65, YELLOW);
                putpixel(t - 9, 65, BLUE);
                putpixel(t + 13, 80, RED);
                putpixel(t + 7, 80, YELLOW);
                putpixel(t + 1, 80, BLUE);
                putpixel(t + 13, 100, RED);
                putpixel(t + 7, 100, YELLOW);
                putpixel(t + 1, 100, BLUE);
                if ((t + 1) >= 292 && (t + 1) <= 317)
                {
                    putpixel(t + 1, 180, RED);
                    putpixel(t - 5, 180, YELLOW);
                    putpixel(t - 11, 180, YELLOW);
                }
                else
                {
                    putpixel(t + 1, 180, RED);
                    putpixel(t - 5, 180, YELLOW);
                    putpixel(t - 11, 180, BLUE);
                }
                t += 3;
            }
            delay(50);
        }
        t = 0;
    } while (!kbhit());
}
/*system("cls"); la comentarie por que no me deja visualizar el contenido */