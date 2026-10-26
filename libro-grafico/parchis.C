#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define TAM 20
#define BASE 6
#define PASOS 52

int pathX[PASOS], pathY[PASOS];

void casilla(int x, int y, int color) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, color);
    rectangle(x, y, x + TAM, y + TAM);
    floodfill(x + 1, y + 1, WHITE);
}

void base_jugador(int x, int y, int color) {
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + TAM * BASE, y + TAM * BASE);
}

void dibujar_dado(int valor) {
    int x = 300, y = 300;
    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + 60, y + 60);
    setcolor(BLACK);
    rectangle(x, y, x + 60, y + 60);

    setfillstyle(SOLID_FILL, BLACK);

    if (valor == 1 || valor == 3 || valor == 5)
        fillellipse(x + 30, y + 30, 4, 4);
    if (valor >= 2)
        fillellipse(x + 15, y + 15, 4, 4);
    if (valor >= 2)
        fillellipse(x + 45, y + 45, 4, 4);
    if (valor >= 4)
        fillellipse(x + 15, y + 45, 4, 4);
    if (valor >= 4)
        fillellipse(x + 45, y + 15, 4, 4);
    if (valor == 6) {
        fillellipse(x + 15, y + 30, 4, 4);
        fillellipse(x + 45, y + 30, 4, 4);
    }
}

void dibujar_tablero(int offsetX, int offsetY) {
    int i;
    base_jugador(offsetX, offsetY, RED);
    base_jugador(offsetX + TAM * (BASE + 3), offsetY, BLUE);
    base_jugador(offsetX, offsetY + TAM * (BASE + 3), YELLOW);
    base_jugador(offsetX + TAM * (BASE + 3), offsetY + TAM * (BASE + 3), GREEN);

    for (i = 0; i < 6; i++) {
        casilla(offsetX + TAM * i, offsetY + TAM * 6, LIGHTGRAY);
        casilla(offsetX + TAM * 6, offsetY + TAM * i, LIGHTGRAY);
        casilla(offsetX + TAM * (8 + i), offsetY + TAM * 6, LIGHTGRAY);
        casilla(offsetX + TAM * 8, offsetY + TAM * i, LIGHTGRAY);
        casilla(offsetX + TAM * i, offsetY + TAM * 8, LIGHTGRAY);
        casilla(offsetX + TAM * 6, offsetY + TAM * (8 + i), LIGHTGRAY);
        casilla(offsetX + TAM * (8 + i), offsetY + TAM * 8, LIGHTGRAY);
        casilla(offsetX + TAM * 8, offsetY + TAM * (8 + i), LIGHTGRAY);
    }

    for (i = 1; i < 6; i++) {
        casilla(offsetX + TAM * 6, offsetY + TAM * (6 + i), GREEN);
        casilla(offsetX + TAM * (6 + i), offsetY + TAM * 8, RED);
        casilla(offsetX + TAM * 8, offsetY + TAM * (8 - i), BLUE);
        casilla(offsetX + TAM * (8 - i), offsetY + TAM * 6, YELLOW);
    }

    setfillstyle(SOLID_FILL, WHITE);
    bar(offsetX + TAM * 6, offsetY + TAM * 6, offsetX + TAM * 9, offsetY + TAM * 9);
}

void definir_camino(int offsetX, int offsetY) {
    int i, idx = 0;

    for (i = 0; i < 6; i++) {
        pathX[idx] = offsetX + TAM * i;
        pathY[idx++] = offsetY + TAM * 6;
    }
    for (i = 0; i < 6; i++) {
        pathX[idx] = offsetX + TAM * 6;
        pathY[idx++] = offsetY + TAM * (5 - i);
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX + TAM * (6 + i);
        pathY[idx++] = offsetY;
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX + TAM * 11;
        pathY[idx++] = offsetY + TAM * i;
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX + TAM * (11 - i);
        pathY[idx++] = offsetY + TAM * 6;
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX + TAM * 6;
        pathY[idx++] = offsetY + TAM * (6 + i);
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX + TAM * (6 - i);
        pathY[idx++] = offsetY + TAM * 11;
    }
    for (i = 1; i < 6; i++) {
        pathX[idx] = offsetX;
        pathY[idx++] = offsetY + TAM * (11 - i);
    }
}

void ficha(int x, int y, int color) {
    setfillstyle(SOLID_FILL, color);
    fillellipse(x + TAM / 2, y + TAM / 2, 7, 7);
}

int main() {
    int gd = DETECT, gm;
    int pos = 0, dado, tecla;
    int offsetX = 100, offsetY = 50;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    srand(time(NULL));

    dibujar_tablero(offsetX, offsetY);
    definir_camino(offsetX, offsetY);

    ficha(pathX[pos], pathY[pos], RED);
    dibujar_dado(1);

    while (1) {
        tecla = getch();
        if (tecla == 27) break;

        dado = rand() % 6 + 1;

        dibujar_dado(dado);

        ficha(pathX[pos], pathY[pos], LIGHTGRAY);

        pos += dado;
        if (pos >= PASOS) pos %= PASOS;

        ficha(pathX[pos], pathY[pos], RED);
    }

    closegraph();
    return 0;
}
