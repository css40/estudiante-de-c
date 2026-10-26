#include <graphics.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
void main(void)
{
    struct time tiempo;
    int a = DETECT, b;
    int radio = 180;
    int seg, min, w, h;
    float angulmin, anguloseg, angulhora, hora;
    char mensaje[20];
    int xseg, yseg, xmin, ymin, xhora, yhora;
    initgraph(&a, &b, "c:\\tc20\\bin");
    circle(310, 240, 238);
    h = 0;
    for (w = 0; w <= 60; w++)
    {
        if (h % 5 == 0)
            setcolor(RED);
        else
            setcolor(WHITE);
        outtextxy(310 + sin(6 * h * (3.141592 / 180)) * 225, 240 - cos(h * (3.141592 / 180) * 6) * 225, "*");
        h += 1;
    }
    settextstyle(1, 0, 2);
    outtextxy(300, 20, "12");
    outtextxy(520, 230, "3");
    outtextxy(310, 433, "6");
    outtextxy(100, 230, "9");
    do
    {
        gettime(&tiempo);
        seg = tiempo.ti_sec;
        min = tiempo.ti_min;
        hora = tiempo.ti_hour;
        if (hora > 12)
            hora -= 12;
        hora += (min / 60);
        anguloseg = ((seg - 15) / (3 * 3.14159));
        angulmin = ((min - 15) / (3 * 3.14159));
        angulhora = ((hora * 5 - 15) / (3 * 3.14159));
        setcolor(WHITE);
        circle(310, 240, 8);
        rectangle(240, 390, 360, 420);
        sprintf(mensaje, "%2.0f: %2.0d: %2.0d", hora, tiempo.ti_min, tiempo.ti_sec);
        outtextxy(250, 390, mensaje);
        xseg = 310 + radio * cos(anguloseg);
        yseg = 240 + radio * sin(anguloseg);
        xmin = 310 + 120 * cos(angulmin);
        ymin = 240 + 120 * sin(angulmin);
        xhora = 310 + 90 * cos(angulhora);
        yhora = 240 + 90 * sin(angulhora);
        setcolor(WHITE);
        line(310, 240, xseg, yseg);
        setcolor(GREEN);
        line(310, 240, xmin, ymin);
        setcolor(RED);
        line(310, 240, xhora, yhora);
        sleep(1);
        setcolor(BLACK);
        line(310, 240, xseg, yseg);
        line(310, 240, xmin, ymin);
        line(310, 240, xhora, yhora);
        outtextxy(250, 390, mensaje);
    } while (!kbhit());
}