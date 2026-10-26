#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define clear \
    ;         \
    clrscr();
#define colorfondo 0
#define colorcabeza 4
#define c 1
#define bordear 40
#define bordeab 460 /*acotamos la parte valida de pantalla*/
#define bordeiz 20
#define bordede 620
void Inicio(void);
void Salir(void);
void Juego(void);
void Avanza(void);
void Crece(void);
void Libera(void);
void Pinta_serpiente(void);
void Pinta_rapido(void);
int Choque(void);
void Pinta_pantalla(void);
int Es_punto(int x, int y);
void Lee_record(void);
void Escribe_record(void);
struct bola
{
    int x;
    int y; /*La serp no es mas que una lista doble de puntos con su x y su y*/
    struct bola *sig, *ant;
};
int m, v, vel, tarj, modo, puntos, max, punt[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
int longitud = 0, radio = 5, xa, ya, superado = 0; /*No hay mas remedio que usar todas estas
          globales*/
struct bola *cabeza, *indice, *ultimo;             /*Para la lista*/
void main(void)
{
    detectgraph(&tarj, &modo); /*comprueba el hw y detecta la tarjeta a usar*/
    Inicio();
    Juego();
}

void Inicio(void)
{
    int i;
    clear;
    textcolor(14);
    for (i = 1; i < 81; i++)
    {
        gotoxy(i, 9);
        cprintf("Ä");
    }
    textcolor(1);
    gotoxy(34, 1);
    cprintf(" Û Û");
    gotoxy(34, 2);
    cprintf(" Û ÛÛ ÛÛ Û");
    gotoxy(34, 3);
    cprintf(" ÛÛÛÛÛ ÛÛÛÛÛ");
    gotoxy(34, 4);
    cprintf("ÛÛ ÛÛÛ ÛÛÛ ÛÛ");
    gotoxy(34, 5);
    cprintf("ÛÛ ÛÛÛÛÛÛÛ ÛÛ");
    gotoxy(33, 6);
    cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
    gotoxy(33, 7);
    cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
    gotoxy(34, 8);
    cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛ");
    gotoxy(38, 9);
    cprintf("Û");
    gotoxy(42, 9);
    cprintf("Û");
    textcolor(4);
    gotoxy(40, 1);
    cprintf("Û");
    gotoxy(40, 2);
    cprintf("Û");
    gotoxy(40, 3);
    cprintf("Û");
    gotoxy(40, 4);
    cprintf("Û");
    gotoxy(36, 4);
    cprintf("Û");
    gotoxy(44, 4);
    cprintf("Û");
    gotoxy(36, 5);
    cprintf("Û");
    gotoxy(44, 5);
    cprintf("Û");
    gotoxy(39, 7);
    cprintf("O");
    gotoxy(41, 7);
    cprintf("O");
    textcolor(9);
    gotoxy(31, 10);
    cprintf("ÛÛÛ Û Û ÛÛÛ ÛÛÛ ÛÛÛ");
    gotoxy(31, 11);
    cprintf("Û Û Û Û Û Û Û Û");
    gotoxy(31, 12);
    cprintf("Û ÛÛÛ ÛÛÛ Û Û ÛÛÛ");
    gotoxy(31, 13);
    cprintf("Û Û Û Û Û Û Û Û");
    gotoxy(31, 14);
    cprintf("ÛÛÛ Û Û Û Û ÛÛÛ ÛÛÛ");
    textcolor(15);
    gotoxy(29, 16);
    cprintf("Dise¤ado por Abdul Ruiz");
    gotoxy(31, 17);
    cprintf("CopyRight (c) 2002");
    getch();
    gotoxy(29, 19);
    cprintf("Espera, por favor...");
    delay(50);
    clear;
    cprintf("TECLAS:\n\n\r");
    cprintf(" -(Ar) 5(Ar)\n\r");
    cprintf("MOVIMIENTOS o en el t.num.\n\r");
    cprintf(" <Ä(Izq) (Ab) Ä>(Der) 1(Izq) 2(Ab) 3(Der)\n\r");
    cprintf("Pausa: P\n\r");
    cprintf("Salir: S\n\n\r");
    cprintf("Si utilizas el teclado numerico, asegurate de que este activado\n\n\n\r");

    cprintf("Pulsa una tecla para empezar");
    getch();
    sleep(5);
    clear;
    cprintf("Dime el nivel de dificultad 1(Minima)...9(Maxima): ");
    do
    {
        scanf("%d", &m);
    } while (m < 1 || m > 9);
    switch (m)
    {
    case 1:
        v = 9;
        break;
    case 2:
        v = 8;
        break;
    case 3:
        v = 7;
        break;
    case 4:
        v = 6;
        break;
    case 5:
        v = 5;
        break;
    case 6:
        v = 4;
        break;
    case 7:
        v = 3;
        break;
    case 8:
        v = 2;
        break;
    case 9:
        v = 1;
        break;
    }
}
void Juego(void)
{
    int obj = 0; /*Para saber si hay algo de comida en la pantalla*/
    int mov = radio * 2;
    char t, a; /*La tecla pulsada y la anterior*/
    char pito = 7;
    int x2, y2;
    initgraph(&tarj, &modo, "c:\\tc20\\bin"); /*iniciamos modo grafico*/
    setbkcolor(colorfondo);                   /*configuramos los colores del juego*/
    setcolor(colorfondo);
    setfillstyle(1, c);
    Lee_record();
    t = 77; /*ponemos una tecla (para que empiece yendo hacia la derecha)*/
    superado = 0;
    vel = v * 50;
    Crece();                     /*creamos la cabeza*/
    cabeza->x = bordeiz + radio; /*la colocamos*/
    cabeza->y = bordeab - radio;
    Crece(); /*ponemos otras dos bolitas de cuerpo*/
    Crece();
    Pinta_pantalla();
    gotoxy(35, 15);
    printf("ADELANTE");
    delay(50);
    cleardevice();

    do
    {
        /*si no hay objeto, cogemos una pos aleatoria*/
        if (obj == 0)
        {
            do
            {
                do
                {
                    x2 = (((rand() % ((bordede / (radio * 2)) - 1) + 1)) * radio * 2) - radio;
                } while (x2 > bordede - radio || x2 < bordeiz + radio);
                do
                {
                    y2 = (((rand() % ((bordeab / (radio * 2)) - 1) + 1)) * radio * 2) - radio;
                } while (y2 > bordeab - radio || y2 < bordear + radio);
            } while (Es_punto(x2, y2));
            obj = 1;
        }
        /*si se pulsa una tecla*/
        if (kbhit())
        {
            a = t;       /*se guarda la anterior*/
            t = getch(); /* y se coge*/
        }
        if (Choque())
        {
            printf("%c", pito); /*si se choca, pierde*/
            Salir();
        }
        Pinta_pantalla();
        if (obj == 1) /*si hay objeto, lo pintamos de otro color*/
        {
            setfillstyle(1, 12);
            fillellipse(x2, y2, radio - 2, radio - 2);
            setfillstyle(1, c);
        }
        switch (t) /*evalua la tecla*/
        {
        case 72:
        case '5':
            Avanza();
            cabeza->y = cabeza->y - mov;
            break; /*arriba */
        case 75:
        case '1':

            Avanza();
            cabeza->x = cabeza->x - mov;
            break; /*izquierda */
        case 77:
        case '3':
            Avanza();
            cabeza->x = cabeza->x + mov;
            break; /*derecha */
        case 80:
        case '2':
            Avanza();
            cabeza->y = cabeza->y + mov;
            break; /*abajo*/
        case 's':
        case 'S':
            /*si quiere salir, liberamos mem, cerramos el modo grafico y exit*/
            Libera();
            closegraph();
            Escribe_record();
            exit(2);
            break;
        case 'p': /*pausa*/
            cleardevice();
            Pinta_serpiente();
            gotoxy(37, 15);
            printf("Pausa");
            t = getch();
            cleardevice();
            Pinta_serpiente();
            break;
            /*si la tecla pulsada no hace nada, volvemos a poner la enterior*/
        default:
            t = a;
        }
        /*si se pasa por encima del objeto, se borra y se crece*/
        if (cabeza->x == x2 && cabeza->y == y2)
        {
            puntos += punt[v - 1];
            obj = 0;
            printf("%c", pito);
            switch (m)
            {

            case 1:
                Crece();
                break;
            case 2:
            case 3:
                Crece();
                Crece();
                break;
            case 4:
            case 5:
                Crece();
                Crece();
                Crece();
                break;
            case 6:
            case 7:
            case 8:
                Crece();
                Crece();
                Crece();
                Crece();
                Crece();
                break;
            case 9:
                Crece();
                Crece();
                Crece();
                Crece();
                Crece();
                Crece();
                break;
            }
        }
        /*cuantas mas bolas tenga que dibujar el ordenador, mas se*/
        /*ralentiza el juego, esto lo contrarestamos disminuyendo el delay*/
        /*cada 30 bolitas(lo he calculado a ojo)
       if((longitud)/(i*30)<0)
       {
       vel-=15;
       i++;
       }*/
        delay(vel);
        if (puntos > max)
        {
            max = puntos;
            superado = 1;
        }
    } while (1);
}
void Salir(void)
{
    char opc;
    /*no hace falta comentar nada*/
    if (superado != 0)
    {
        Escribe_record();
        gotoxy(11, 10);
        printf(" Puntuacion maxima conseguida, eres el mejor, felicidades");
    }
    gotoxy(11, 15);

    printf("Estas muerto, lo siento (R)Reintentar,(I)Reiniciar,(S)Salir");
    do
    {
        opc = toupper(getch());
    } while (opc != 'R' && opc != 'I' && opc != 'S');
    puntos = 0;
    switch (opc)
    {
    case 'R':
        Libera();
        Juego();
        break;
    case 'I':
        closegraph();
        Libera();
        Inicio();
        Juego();
        break;
    case 'S':
        closegraph();
        Libera();
        exit(1);
        break;
    }
}
void Avanza(void)
{
    indice = ultimo;
    xa = ultimo->x;
    ya = ultimo->y;
    /*nos quedamos con la posicion de la cola*/
    /*corremos cada bola a la pos de la bola anterior*/
    while (indice != cabeza)
    {
        indice->x = indice->ant->x;
        indice->y = indice->ant->y;
        indice = indice->ant;
    }
}
void Pinta_serpiente(void)
{
    int i = 0;
    indice = cabeza;
    setfillstyle(1, colorcabeza);

    fillellipse(indice->x, indice->y, radio, radio);
    setfillstyle(1, c);
    i++;
    indice = indice->sig;
    /*sin comentarios*/
    while (i < longitud)
    {
        fillellipse(indice->x, indice->y, radio, radio);
        i++;
        indice = indice->sig;
    }
}
/*Como hemos comprobado en anteriores versiones, al pintar la serpiente entera*/
/*, si esta media mucho, se ralentizaba el juego mogollon, y sabemos que, al pintar*/
/*una bola y moverla, se queda su estela pintada, no?, co¤o pues pintemos solo*/
/*la primera, segunda y ultima bolita, y asi, mida lo que mida la serpiente,*/
/*solo pintaremos 3 bolas, y no se ralentiza casi nada.*/
void Pinta_rapido(void)
{
    setfillstyle(1, colorcabeza);
    fillellipse(cabeza->x, cabeza->y, radio, radio);
    setfillstyle(1, c);
    fillellipse(cabeza->sig->x, cabeza->sig->y, radio, radio);
    fillellipse(ultimo->x, ultimo->y, radio, radio);
}

int Choque(void)
{
    indice = cabeza->sig;
    /* si la cabeza está en la posición de alguna bola o sale de los límites,
    devolvemos un 1 */
    while (indice != NULL)
    {
        if (cabeza->x == indice->x && cabeza->y == indice->y)
            return 1;
        if ((cabeza->y < bordear + radio) || (cabeza->x < bordeiz + radio) || (cabeza->x > bordede - radio) || (cabeza->y > bordeab - radio))
            return 1; /*Se corrigió la comparación de x en lugar de cabeza->x*/
        indice = indice->sig;
    }
    return 0;
}


void Crece(void)
{
    struct bola *este;
    este = malloc(sizeof(struct bola));
    /*pues eso, se a¤ade una struct bola al final de la lista*/
    if (cabeza == NULL)
    {
        ultimo = cabeza = este;
        cabeza->ant = NULL;
        ultimo->sig = NULL;
        cabeza->x = bordeiz + radio;
        cabeza->y = bordeab - radio;
    }
    else
    {
        ultimo->sig = este;
        este->ant = ultimo;
        ultimo = este;
        ultimo->sig = NULL;
        este->x = -100;
        este->y = -100;
    }
    indice = ultimo;
    longitud++;
}
void Libera(void)
{
    struct bola *aux;
    indice = cabeza;
    /*no hace falta comentario*/
    cabeza = ultimo = NULL;
    while (indice != ultimo)
    {
        aux = indice;
        indice = indice->sig;
        free(aux);
    }
    aux = indice;
    free(aux);
    longitud = 0;
}
void Pinta_pantalla(void)
{
    gotoxy(1, 1);
    printf(" Serpiente v1 Desarrollado por Abdul Ruiz Chaos\n\r");
    gotoxy(10, 2);
printf("Nivel : %1d Punt.Max. : %4d Puntuacion :%4d Longitud:%4d",m,max,puntos,longitud);
Pinta_rapido(); /* dibujamos la serp */
/*"borramos" la ultima bola*/
/*este metodo es mas util, porque usando un cleardevice(), la
pantalla vibraba mucho*/
setfillstyle(1,colorfondo);
fillellipse(xa,ya,radio,radio);
setfillstyle(1,c);
/* dibujamos los bordes de la pantalla */
setcolor(15);
rectangle(bordeiz-1,bordear-1,bordede+1,bordeab+1);
setcolor(0);
}
int Es_punto(int x, int y)
{
    indice = cabeza->sig;
    while (indice != NULL)
    {
        if (x == indice->x && y == indice->y)
            return 1;
        indice = indice->sig;
    }
    return 0;
}
void Lee_record(void)
{
    FILE *arch;
    if ((arch = fopen("chaos.ars", "rb")) != NULL)
    {
        fread(&max, 1, sizeof(int), arch);
        if (puntos > max)
        {
            max = puntos;
        }

        fclose(arch);
    }
    else
    {
        max = puntos;
    }
}
void Escribe_record(void)
{
    FILE *arch;
    arch = fopen("chaos.ars", "wb");
    fwrite(&max, 1, sizeof(int), arch);
    fclose(arch);
}