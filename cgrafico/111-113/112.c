#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include <conio.h>
#include "tecla.c"
float A, B, TAM = 15, fi = -M_PI / 7, teta = -M_PI / 7, pro_X, pro_Y;
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Definicion de funciones º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
*/
void IniciarGraficos();
void xyz();
void ProyectaPunto(float, float, float);
void Objeto();
void instrucciones();
/*****************************************************************/
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ ProyectaPunto ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Funcion: Localiza un punto en la pantalla 3D º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
*/
void ProyectaPunto(float x, float y, float z)
{
    pro_X = y * cos(teta) + x * sin(teta);
    pro_Y = z * cos(fi) + x * cos(teta) * sin(fi) - y * sin(fi) * sin(teta);
}
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ IniciarGraficos ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Funcion: Inicializa el modo grafico º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
*/
void IniciarGraficos()
{
    int Tarjeta = VGA, Modo = VGAHI;
    initgraph(&Tarjeta, &Modo, "");
    if (graphresult() != grOk)
    {
        printf("\nSi perdiste el archivo EGAVGA.BGI no podes correr el programa :(asi que buscalo el C:\\tc\\bgi");
        getch();
        exit(0);
    }
}
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Main ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Funcion: Main. º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
*/
void main()
{

    IniciarGraficos();
    A = getmaxx() / 2, B = getmaxy() / 2;
    xyz();
    Objeto();
    closegraph();
}
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ xyz ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Funcion: Dibuja Lineas de Guia en las coordenadas X,Y,Z º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
*/
void xyz()
{
    float X0, Y0, X, Y, z, tam = 3;
    int x, y;
    setcolor(8);
    ProyectaPunto(0, 0, 0);
    X0 = pro_X, Y0 = pro_Y;
    ProyectaPunto(tam, 0, 0);
    X = pro_X, Y = pro_Y;
    line(A + X0 * TAM, B - Y0 * TAM, A + X * TAM, B - Y * TAM);
    x = A + X * TAM, y = B - Y * TAM;
    setcolor(8);
    outtextxy(x, y, "x");
    setcolor(8);
    ProyectaPunto(0, tam, 0);
    X = pro_X, Y = pro_Y;
    line(A + X0 * TAM, B - Y0 * TAM, A + X * TAM, B - Y * TAM);
    x = A + X * TAM, y = B - Y * TAM;
    setcolor(8);
    outtextxy(x, y, "y");
    setcolor(8);
    ProyectaPunto(0, 0, tam);
    X = pro_X, Y = pro_Y;
    line(A + X0 * TAM, B - Y0 * TAM, A + X * TAM, B - Y * TAM);
    setcolor(8);
    x = A + X * TAM, y = B - Y * TAM;
    outtextxy(x, y, "z");
    ProyectaPunto(0, 10, 0);
    X = pro_X, Y = pro_Y;
    x = A + X * TAM, y = B - Y * TAM;
    setcolor(RED);
    outtextxy(x, y, "JDZx");
    setcolor(8);
}
/*
ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Objeto ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»
º Funcion: Dibuja un objeto 3D º
º º
ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼
123
*/
void Objeto()
{
    float angulo = -M_PI / 100.0;
    float AA[8], BB[8], CC[12], estrellas[2], EE[8], FF[8],
        xa1 = 3, ya1 = -3, za1 = -3, xa2 = -3, ya2 = -3, za2 = -3,
        xa3 = -3, ya3 = -3, za3 = 3, xa4 = 3, ya4 = -3, za4 = 3,
        xb1 = 3, yb1 = 3, zb1 = -3, xb2 = -3, yb2 = 3, zb2 = -3,
        xb3 = -3, yb3 = 3, zb3 = 3, xb4 = 3, yb4 = 3, zb4 = 3;
    float x, y;
    unsigned char tecla;
    int fo;
    do
    {
        ProyectaPunto(xa1, ya1, za1);
        AA[0] = pro_X, AA[1] = pro_Y;
        ProyectaPunto(xa2, ya2, za2);
        AA[2] = pro_X, AA[3] = pro_Y;
        ProyectaPunto(xa3, ya3, za3);
        AA[4] = pro_X, AA[5] = pro_Y;
        ProyectaPunto(xa4, ya4, za4);
        AA[6] = pro_X, AA[7] = pro_Y;
        /*-------------------------------------------*/
        ProyectaPunto(xb1, yb1, zb1);
        BB[0] = pro_X, BB[1] = pro_Y;
        ProyectaPunto(xb2, yb2, zb2);
        BB[2] = pro_X, BB[3] = pro_Y;
        ProyectaPunto(xb3, yb3, zb3);
        BB[4] = pro_X, BB[5] = pro_Y;
        ProyectaPunto(xb4, yb4, zb4);
        BB[6] = pro_X, BB[7] = pro_Y;
        ProyectaPunto(5, 8, 0);
        CC[0] = pro_X, CC[1] = pro_Y;
        ProyectaPunto(-4, -8, 0);
        CC[4] = pro_X, CC[5] = pro_Y;
        ProyectaPunto(5, -5, 3);
        CC[6] = pro_X, CC[7] = pro_Y;
        ProyectaPunto(10, 5, -1);
        CC[8] = pro_X, CC[9] = pro_Y;
        ProyectaPunto(0, 0, 0);
        CC[10] = pro_X, CC[11] = pro_Y;
        setcolor(1);
        circle(A + CC[0] * TAM, B - CC[1] * TAM, TAM * 0.52);
        setcolor(2);
        circle(A + CC[4] * TAM, B - CC[5] * TAM, TAM * 0.25);
        setcolor(3);
        circle(A + CC[6] * TAM, B - CC[7] * TAM, TAM * 0.8);
        setcolor(4);
        circle(A + CC[8] * TAM, B - CC[9] * TAM, TAM * 2.5);
        setcolor(YELLOW);
        circle(A + CC[10] * TAM, B - CC[11] * TAM, TAM * 2.2);
        /*-----------------------*/
        ProyectaPunto(5, 0, 2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        putpixel(A + estrellas[0] * TAM, B - estrellas[1] * TAM, 7);
        ProyectaPunto(-15 - 0.2, 5, -2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        setcolor(8);
        circle(A + estrellas[0] * TAM, B - estrellas[1] * TAM, TAM * 0.2);
        ProyectaPunto(-10, -3, -2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        putpixel(A + estrellas[0] * TAM, B - estrellas[1] * TAM, 7);
        ProyectaPunto(-10, -3, -2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        putpixel(B + estrellas[1] * TAM, A - estrellas[1] * TAM, 7);

        ProyectaPunto(-5, 3, -2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        putpixel(A + estrellas[0] * TAM, B - estrellas[1] * TAM, 7);
        ProyectaPunto(10, -3, -2);
        estrellas[0] = pro_X, estrellas[1] = pro_Y;
        putpixel(A + estrellas[0] * TAM, B - estrellas[1] * TAM, 7);
        xyz();
        line(A + AA[0] * TAM, B - AA[1] * TAM, A + AA[2] * TAM, B - AA[3] * TAM);
        line(A + AA[4] * TAM, B - AA[5] * TAM, A + AA[6] * TAM, B - AA[7] * TAM);
        line(A + AA[0] * TAM, B - AA[1] * TAM, A + AA[6] * TAM, B - AA[7] * TAM);
        line(A + AA[2] * TAM, B - AA[3] * TAM, A + AA[4] * TAM, B - AA[5] * TAM);
        line(A + AA[0] * TAM, B - AA[1] * TAM, A + BB[0] * TAM, B - BB[1] * TAM);
        line(A + AA[2] * TAM, B - AA[3] * TAM, A + BB[2] * TAM, B - BB[3] * TAM);
        line(A + AA[4] * TAM, B - AA[5] * TAM, A + BB[4] * TAM, B - BB[5] * TAM);
        line(A + AA[6] * TAM, B - AA[7] * TAM, A + BB[6] * TAM, B - BB[7] * TAM);
        line(A + BB[0] * TAM, B - BB[1] * TAM, A + BB[2] * TAM, B - BB[3] * TAM);
        line(A + BB[2] * TAM, B - BB[3] * TAM, A + BB[4] * TAM, B - BB[5] * TAM);
        line(A + BB[4] * TAM, B - BB[5] * TAM, A + BB[6] * TAM, B - BB[7] * TAM);
        line(A + BB[6] * TAM, B - BB[7] * TAM, A + BB[0] * TAM, B - BB[1] * TAM);
        tecla = IZQUIERDA;
        if (kbhit())
        {
            tecla = getch();
        }
        setfillstyle(1, 0);
        switch (tecla)
        {
        case DERECHA:
            teta -= angulo;
            break;
        case IZQUIERDA:
            teta += angulo;
            break;
        case ABAJO:
            fi += angulo;
            break;
        case ARRIBA:
            fi -= angulo;
            break;
        case 122:
            if (TAM > 0)
                TAM -= 0.2;
            break;
        case 120:
            if (TAM < 30)
                TAM += 0.2;
            break;
        } /*endcase*/
        if (!kbhit())
        {
            delay(50);
        }
        bar(0, 0, getmaxx(), getmaxy());
    } while (tecla != ESC);
}