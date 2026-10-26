
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
void inicializar(void);
void cuadro(void);
void main(void)
{
    inicializar();
    cuadro();
     closegraph();
    restorecrtmode();
}
void inicializar(void)
{
    int adaptor = DETECT, modo, codigo;
    printf("desea seguir viendo los graficos");
    initgraph(&adaptor, &modo, "c:\\tc20\\bin");
    if ((codigo = graphresult()) != 0)
    {
        printf("%s", grapherrormsg(codigo));
        exit(1);
    }
}
void cuadro(void)
{
    int paginas = 1;
    int i = 155, j = 120; /*i=izquierda arriba eje x jes igual eje y*/
    int q = 465, w = 120; /* t= derecha arriba eje x k es igual eje y*/
    int t = 155, k = 360; /*q= izquierda abajo eje x w es igual eje y */
    int a = 465, s = 360; /*a= derecha abajo eje x s igual eje y*/
    int pentagono[] = {55, 340, 105, 410, 205, 410, 255, 340, 155, 270, 55, 340};
    int hexagono[] = {365, 360, 415, 410, 515, 410, 565, 360, 515, 310, 415, 310, 365, 360};
    while (paginas <= 4)
       
        {
            /*system("cls");*/
            setbkcolor(WHITE);
            setlinestyle(SOLID_LINE, 15, THICK_WIDTH);
            setcolor(8);
            rectangle(1, 1, getmaxx() - 1, getmaxy() - 1);
            line(310, 0, 310, 480);
            line(0, 240, 640, 240);
            setcolor(9);
            setlinestyle(SOLID_LINE, 15, NORM_WIDTH);
            if (paginas >= 1 && paginas <= 2)
            {
                settextstyle(SMALL_FONT, HORIZ_DIR, 4);
                outtextxy(400, 460, "Presione enter para ver las sig. graficas");
            }
            else
            {
                settextstyle(SMALL_FONT, HORIZ_DIR, 4);
                outtextxy(370, 460, "Fin de presentacion Presione enter para Salir");
            }
            if (paginas == 1)
            {
                cleardevice();
                /***************triangulo1**************************/
                outtextxy(i - 60, j - 90, "Triangulo Rectangulo");
                outtextxy(i - 67, j - 20, "h");
                outtextxy(i, j + 40, "b");
                outtextxy(i - 5, j + 70, "S=(b x h)/2");
                outtextxy(i - 60, j - 90, "Tri ngulo rectangulo");
                line(i - 60, j - 60, i - 60, j + 40);
                line(i - 60, j + 40, i + 100, j + 40);
                line(i + 100, j + 40, i - 60, j - 60);
                /******************triangulo2****************************/
                /* q eje x w eje y*/
                outtextxy(q - 100, w - 90, "Triangulo Rectangulo 3 lados diferentes");
                outtextxy(q - 57, w - 20, "h");
                outtextxy(q - 20, w + 40, "a");
                outtextxy(q + 10, w - 30, "b");
                outtextxy(q - 80, w - 30, "c");
                settextstyle(SMALL_FONT, HORIZ_DIR, 5);
                outtextxy(q - 45, w + 60, "S=-\/ p(p-a)(p-b)(p-c)'");
                line(q - 15, w + 60, q + 110, w + 60);
                outtextxy(q - 30, w + 75, "P=(a+b+c)/2");
                settextstyle(SMALL_FONT, HORIZ_DIR, 4);
                /*outtextxy(q-5,w+70,"(b x h)/2");*/
                outtextxy(i - 60, j - 90, "Tri ngulo rectangulo");
                outtextxy(i - 60, j - 90, "Tri ngulo rectangulo");
                outtextxy(i - 60, j - 90, "Tri ngulo rectangulo");
                setlinestyle(DOTTED_LINE, 3, NORM_WIDTH);
                line(q - 50, w - 60, q - 50, w + 40);
                setlinestyle(SOLID_LINE, 15, NORM_WIDTH);
                line(q - 50, w + 40, q + 80, w + 40);
                line(q + 80, w + 40, q - 50, w - 60);
                line(q - 50, w + 40, q - 100, w + 40);
                line(q - 100, w + 40, q - 50, w - 60);
                /*******************triangulo escaleno*****************************/
                /*t es eje x k es eje y*/
                outtextxy(t - 60, k - 90, "Triangulo Escaleno");
                outtextxy(t - 67, k - 20, "h");
                outtextxy(t, k + 40, "b");
                outtextxy(t - 5, k + 70, "S=(b x h)/2");
                line(t - 60, k - 60, t - 25, k + 40);  /*line que corta al triangulo o cat opu*/
                line(t - 25, k + 40, t + 100, k + 40); /*cat ady.*/
                line(t + 100, k + 40, t - 60, k - 60); /*hipoten.*/
                setlinestyle(DOTTED_LINE, 8, NORM_WIDTH);
                line(a + 20, s - 60, a + 20, s + 40); /*Triangulo isosceles*/
                line(t - 60, k - 60, t - 60, k + 40);
                line(t - 60, k + 40, t + 100, k + 40);
                setlinestyle(SOLID_LINE, 21, NORM_WIDTH);
                /*********************triangulo isosceles***************************/
                outtextxy(a - 40, s - 90, "Triangulo Isosceles");
                outtextxy(a + 10, s - 20, "h");
                outtextxy(a + 10, s + 40, "b");
                outtextxy(a - 5, s + 70, "S=(b x h)/2");
                line(a + 20, s - 60, a - 60, s + 40);  /*cat opt.*/
                line(a - 60, s + 40, a + 100, s + 40); /*cat ady*/
                line(a + 100, s + 40, a + 20, s - 60); /*hip*/
              
                getch();
                
            }
            if (paginas == 2)
            {
                cleardevice();
                /********************Rectangulo******************/
                line(i - 45, j - 25, i + 65, j - 25);
                line(i - 60, j + 25, i + 50, j + 25);
                line(i - 45, j - 25, i - 60, j + 25);
                line(i + 65, j - 25, i + 50, j + 25);
                setlinestyle(DOTTED_LINE, 8, NORM_WIDTH);
                line(i - 45, j - 25, i - 45, j + 25); /*altura*/
                outtextxy(i - 25, j - 90, "Rectangulo");
                outtextxy(i - 52, j, "h");
                outtextxy(i, j + 30, "b");
                outtextxy(i - 35, j + 60, "S=b x h");
                setlinestyle(SOLID_LINE, 8, NORM_WIDTH);
                /*****************************Rombo***********************/
                line(t - 90, k, t + 90, k);
                line(t, k - 60, t, k + 60);
                line(t - 90, k, t, k - 60);
                line(t, k - 60, t + 90, k);
                line(t, k + 60, t + 90, k);
                line(t - 90, k, t, k + 60);
                setlinestyle(DOTTED_LINE, 24, NORM_WIDTH);
                rectangle(t - 90, k, t + 90, k + 70);
                line(t, k - 60, t + 120, k - 60);
                line(t + 120, k - 60, t + 120, k + 60);
                line(t + 120, k + 60, t, k + 60);
                line(q - 60, w - 45, q - 60, w + 45);
                outtextxy(t - 25, k - 90, "Rombo");
                outtextxy(t - 45, k, "D");
                outtextxy(i + 3, k + 30, "d");
                outtextxy(t - 35, k + 75, "S=(D * d)/2");
                setlinestyle(SOLID_LINE, 8, NORM_WIDTH);
                /*****************************Trapecio******************************/
                line(q - 60, w - 45, q + 60, w - 45);
                line(q - 85, w + 45, q + 90, w + 45);
                line(q - 85, w + 45, q - 60, w - 45);
                line(q + 90, w + 45, q + 60, w - 45);
                outtextxy(q - 25, w - 90, "Trapecio");
                outtextxy(q - 52, w, "h");
                outtextxy(q, w + 50, "B");
                outtextxy(q, w - 60, "b");
                outtextxy(q - 35, w + 60, "S=((B + b)* h)/2");
                /*************************Pol¡gono*****************************/
                line(a - 60, s, a + 100, s);
                line(a + 100, s, a + 70, s + 45);
                line(a + 70, s + 45, a - 60, s);
                line(a + 100, s, a + 40, s - 60);
                line(a + 40, s - 60, a - 60, s);
                line(a + 40, s - 60, a - 40, s - 40);
                line(a - 60, s, a - 40, s - 40);
                outtextxy(a - 25, s - 90, "Poligono");
                outtextxy(a - 30, s - 40, "S1");
                outtextxy(a + 25, s - 30, "S2");
                outtextxy(a + 30, s + 10, "S3");
                outtextxy(a - 35, s + 60, "S= S1 + S2 + S3");
                getch();
           
            }
            if (paginas == 3)
            {
                cleardevice();
                /*********************tri ngulo equilatero*********************/
                line(i - 60, j + 55, i + 20, j - 85);  /*cat*/
                line(i + 100, j + 55, i + 20, j - 85); /*cat*/
                line(i - 60, j + 55, i + 100, j + 55); /*base*/
                outtextxy(i - 25, j - 100, "Triangulo equilatero");
                setlinestyle(DOTTED_LINE, 24, NORM_WIDTH);
                line(i + 20, j - 85, i + 20, j + 55);
                setlinestyle(SOLID_LINE, 8, NORM_WIDTH);
                outtextxy(i + 25, i - 30, "h");
                outtextxy(i + 30, i + 20, "b");
                outtextxy(i - 35, i + 55, "S= (b * h)/2");
                /*******************************cuadrado***********************/
                rectangle(q - 50, w - 50, q + 50, w + 50);
                outtextxy(q - 25, w - 100, "Cuadrado");
                outtextxy(q, w + 50, "b");
                outtextxy(q - 35, w + 65, "S= b * b");
                /****************************pent gono***********************/
                fillpoly(5, pentagono);
                outtextxy(t - 25, k - 110, "Pent gono");
                line(t, k - 20, t, k + 50);
                outtextxy(t + 10, k + 10, "a");
                outtextxy(t - 35, k + 65, "S=(P * a)/2");
                /*************Exagono o poligono regular*******************/
                fillpoly(6, hexagono);
                outtextxy(a - 65, s - 100, "Hex gono o poligono regular");
                /*setfillstyle(LINE_FILL,GREEN);
                floodfill(370,460,BLUE);*/
                line(a, s, a, s + 50);
                outtextxy(a + 10, s + 10, "a");
                outtextxy(a - 35, s + 65, "S=(P * a)/2");
                getch();
            }
            if (paginas > 4)
                exit(1);
            paginas = paginas + 1;
        }
    clrscr();
}

/* agregue cleardevice(); para poder visualizar bien las figuras y que no se dibujaran encima de las 
ya dibujadas y adeemas de eso  comentarie el cls que tenian del principio por que eso no me dejaba 
visualizar el contenido  */