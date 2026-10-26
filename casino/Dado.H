
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>


int gd, gm;
int apuestaNumero, dineroApostado, dado1, dado2, suma, i, aleatorio1, aleatorio2;
int x1, y1, x2, y2;
int pantallaW, pantallaH;
char texto[80];
char respuesta;

void dibujarDado(int x, int y, int valor) {
    int cx, cy;
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + 100, y + 100);
    rectangle(x, y, x + 100, y + 100);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    cx = x + 50;
    cy = y + 50;

    if (valor == 1 || valor == 3 || valor == 5)
        fillellipse(cx, cy, 7, 7);

    if (valor >= 2) {
        fillellipse(x + 25, y + 25, 7, 7);
        fillellipse(x + 75, y + 75, 7, 7);
    }

    if (valor >= 4) {
        fillellipse(x + 75, y + 25, 7, 7);
        fillellipse(x + 25, y + 75, 7, 7);
    }

    if (valor == 6) {
        fillellipse(x + 25, y + 50, 7, 7);
        fillellipse(x + 75, y + 50, 7, 7);
    }
}

void lanzarAnimacionDados() {
    for (i = 0; i < 10; i++) {
        cleardevice();
        aleatorio1 = (rand() % 6) + 1;
        aleatorio2 = (rand() % 6) + 1;
        dibujarDado(x1, y1, aleatorio1);
        dibujarDado(x2, y2, aleatorio2);
        delay(100);
    }

    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    cleardevice();
    dibujarDado(x1, y1, dado1);
    dibujarDado(x2, y2, dado2);
}

void iniciarJuegoDados() {
    gd = DETECT;
    initgraph(&gd, &gm, "");
    srand(time(NULL));

    pantallaW = getmaxx();
    pantallaH = getmaxy();

    x1 = (pantallaW / 2) - 120;
    y1 = (pantallaH / 2) - 50;
    x2 = (pantallaW / 2) + 20;
    y2 = y1;

    do {
        cleardevice();
        settextstyle(2, 0, 5);

        printf(">> Ingresa el numero al que apuestas (1-12): ");
        scanf("%d", &apuestaNumero);

        if (apuestaNumero < 2 || apuestaNumero > 12) {
            outtextxy((pantallaW / 2) - 130, 70, "Numero invalido. Intenta de nuevo.");
            getch();
            continue;
        }

        printf(">> Cuanto dinero deseas apostar?: ");
        scanf("%d", &dineroApostado);

        outtextxy((pantallaW / 2) - 130, 110, "Presiona una tecla para lanzar los dados...");
        getch();

        lanzarAnimacionDados();

        suma = dado1 + dado2;
        sprintf(texto, "Dado 1: %d   Dado 2: %d   Total: %d", dado1, dado2, suma);
        outtextxy((pantallaW / 2) - 130, pantallaH - 80, texto);

        if (suma == apuestaNumero) {
            sprintf(texto, "Ganaste! Ganancia: %d", dineroApostado * 2);
            outtextxy((pantallaW / 2) - 130, pantallaH - 60, texto);
        } else {
            outtextxy((pantallaW / 2) - 130, pantallaH - 60, "Perdiste. Mejor suerte la proxima.");
        }

        outtextxy((pantallaW / 2) - 130, pantallaH - 40, "Deseas jugar otra vez? (s/n): ");
        printf(">> Jugar otra vez? (s/n): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 's' || respuesta == 'S');

    cleardevice();  
    return;
}


