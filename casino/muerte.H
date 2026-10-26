#ifndef DAMAS_H
#define DAMAS_H

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>

#define SIZE 60

char tablero[8][8] = {
    {' ', 'd', ' ', 'd', ' ', 'd', ' ', 'd'},
    {'d', ' ', 'd', ' ', 'd', ' ', 'd', ' '},
    {' ', 'd', ' ', 'd', ' ', 'd', ' ', 'd'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'D', ' ', 'D', ' ', 'D', ' ', 'D', ' '},
    {' ', 'D', ' ', 'D', ' ', 'D', ' ', 'D'},
    {'D', ' ', 'D', ' ', 'D', ' ', 'D', ' '}
};

int fase = 0;
int fx = -1, fy = -1;
int tx, ty, dx, dy;
int mx, my;
int actualizar = 1;
int turno = 0;
int currentState;

/** Dibuja ficha con color y borde */
void dibujar_dama(int x, int y, int color) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 8, SIZE / 2 - 8);
    setcolor(WHITE);
    circle(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 12);
}

/** Dibuja tablero y fichas */
void dibujar_tablero() {
    int i, j, x1, y1, x2, y2;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            x1 = j * SIZE;
            y1 = i * SIZE;
            x2 = x1 + SIZE;
            y2 = y1 + SIZE;

            if ((i + j) % 2 == 0)
                setfillstyle(SOLID_FILL, WHITE);
            else
                setfillstyle(SOLID_FILL, DARKGRAY);

            bar(x1, y1, x2, y2);
            setcolor(BLACK);
            rectangle(x1, y1, x2, y2);

            if (tablero[i][j] == 'd')
                dibujar_dama(x1, y1, RED);
            else if (tablero[i][j] == 'D')
                dibujar_dama(x1, y1, BLUE);
        }
    }
}

/** Inicializa mouse */
void mouse_init() {
    union REGS r;
    r.x.ax = 0;
    int86(0x33, &r, &r);
}

/** Muestra cursor */
void mouse_show() {
    union REGS r;
    r.x.ax = 1;
    int86(0x33, &r, &r);
}

/** Detecta clic izquierdo */
int mouse_click(int *x, int *y) {
    static int prevState = 0;
    union REGS r;
    r.x.ax = 3;
    int86(0x33, &r, &r);

    currentState = r.x.bx & 1;
    if (currentState && !prevState) {
        *x = r.x.cx;
        *y = r.x.dx;
        prevState = currentState;
        return 1;
    }
    prevState = currentState;
    return 0;
}

/** Verifica movimiento válido */
int movimiento_valido(int fx_param, int fy_param, int tx_param, int ty_param, char pieza, int turno_param) {
    if (tx_param < 0 || tx_param > 7 || ty_param < 0 || ty_param > 7) return 0;
    if (pieza == 'd' && turno_param != 0) return 0;
    if (pieza == 'D' && turno_param != 1) return 0;

    dx = tx_param - fx_param;
    dy = ty_param - fy_param;

    if ((abs(dx) == 1 && abs(dy) == 1)) {
        if ((pieza == 'd' && (tablero[ty_param][tx_param] == 'D' || tablero[ty_param][tx_param] == ' ')) ||
            (pieza == 'D' && (tablero[ty_param][tx_param] == 'd' || tablero[ty_param][tx_param] == ' ')))
            return 1;
    }

    return 0;
}

/** Mueve pieza y elimina si es necesario */
void mover_pieza(int fx_param, int fy_param, int tx_param, int ty_param) {
    if ((tablero[ty_param][tx_param] == 'D' && tablero[fy_param][fx_param] == 'd') ||
        (tablero[ty_param][tx_param] == 'd' && tablero[fy_param][fx_param] == 'D')) {
        tablero[ty_param][tx_param] = ' ';
    }
    tablero[ty_param][tx_param] = tablero[fy_param][fx_param];
    tablero[fy_param][fx_param] = ' ';
}

/** Cuenta fichas vivas */
int contar_fichas(char ficha) {
    int count = 0, i, j;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (tablero[i][j] == ficha)
                count++;
    return count;
}
void iniciarJuegoDamas() {
    int gd = DETECT, gm;
    char key;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    mouse_init();
    mouse_show();

   
    fase = 0;
    fx = fy = -1;
    turno = 0;
    actualizar = 1;

    while (1) {
        if (actualizar) {
            dibujar_tablero();
            actualizar = 0;
        }

        if (kbhit()) {
            key = getch();
            if (key == 27) break;
        }

        if (contar_fichas('d') == 0 || contar_fichas('D') == 0) {
            settextstyle(3, 0, 3);
            setcolor(RED);
            outtextxy(200, 250, contar_fichas('d') == 0 ? "Azul gana!" : "Rojo gana!");
            getch();
            break;
        }

        if (mouse_click(&mx, &my)) {
            tx = mx / SIZE;
            ty = my / SIZE;

            if (fase == 0) {
                if ((turno == 0 && tablero[ty][tx] == 'd') ||
                    (turno == 1 && tablero[ty][tx] == 'D')) {
                    fx = tx;
                    fy = ty;
                    fase = 1;
                }
            } else {
                if (movimiento_valido(fx, fy, tx, ty, tablero[fy][fx], turno)) {
                    mover_pieza(fx, fy, tx, ty);
                    turno = 1 - turno;
                    actualizar = 1;
                }
                fase = 0;
            }

            delay(150);
        }
    }

    closegraph();
}

#endif 