#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>

#define SIZE 60

char tablero[8][8] = {
    {' ','d',' ','d',' ','d',' ','d'},
    {'d',' ','d',' ','d',' ','d',' '},
    {' ','d',' ','d',' ','d',' ','d'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'D',' ','D',' ','D',' ','D',' '},
    {' ','D',' ','D',' ','D',' ','D'},
    {'D',' ','D',' ','D',' ','D',' '}
};

void dibujar_dama(int x, int y, int color) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 8, SIZE / 2 - 8);


    setcolor(WHITE);
    circle(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 12);
}

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

void mouse_init() {
    union REGS r;
    r.x.ax = 0;
    int86(0x33, &r, &r);
}

void mouse_show() {
    union REGS r;
    r.x.ax = 1;
    int86(0x33, &r, &r);
}

int mouse_click(int *x, int *y) {
    static int prevState = 0;
    union REGS r;
    int currentState = r.x.bx & 1;
    r.x.ax = 3;
    int86(0x33, &r, &r);

  

    if (currentState && !prevState) {
        *x = r.x.cx;
        *y = r.x.dx;
        prevState = currentState;
        return 1;
    }

    prevState = currentState;
    return 0;
}


int movimiento_valido(int fx, int fy, int tx, int ty, char pieza) {
    int dx = tx - fx;
    int dy = ty - fy;
    if (tablero[ty][tx] != ' ') return 0;

 

    if (pieza == 'd' && dy == -1 && (dx == -1 || dx == 1))
        return 1;
    if (pieza == 'D' && dy == 1 && (dx == -1 || dx == 1))
        return 1;

    return 0;
}

void mover_pieza(int fx, int fy, int tx, int ty) {
    tablero[ty][tx] = tablero[fy][fx];
    tablero[fy][fx] = ' ';
}

int main() {
    int gd = DETECT, gm;
    int fase = 0;
    int fx = -1, fy = -1;
    int tx, ty;
    int mx, my;
    int actualizar = 1;
    char key;

    initgraph(&gd, &gm, "");

    mouse_init();
    mouse_show();

    while (1) {
        if (actualizar) {
            dibujar_tablero();
            actualizar = 0;
        }

        if (kbhit()) {
            key = getch();
            if (key == 27) break; 
        }

        if (mouse_click(&mx, &my)) {
            tx = mx / SIZE;
            ty = my / SIZE;

            if (fase == 0) {
                if (tablero[ty][tx] == 'd' || tablero[ty][tx] == 'D') {
                    fx = tx;
                    fy = ty;
                    fase = 1;
                }
            } else {
                if (movimiento_valido(fx, fy, tx, ty, tablero[fy][fx])) {
                    mover_pieza(fx, fy, tx, ty);
                    actualizar = 1;
                }
                fase = 0;
                actualizar = 1;
            }

            delay(150);  
        }
    }

    closegraph();
    return 0;
}