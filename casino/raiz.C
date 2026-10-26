#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Dado.h>
#include <Presen.h>
#include <Minas.h>
#include <billar.h>
#include <carrera.h>
#include <ruleta.h>


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

int fase = 0, fx = -1, fy = -1, tx, ty, dx, dy;
int mx, my;
int actualizar = 1;
int turno = 0;
int currentState;

void dibujar_dama(int x, int y, int color) {
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 8, SIZE / 2 - 8);
    setcolor(WHITE);
    circle(x + SIZE / 2, y + SIZE / 2, SIZE / 2 - 12);
}

void damas_dibujar_tablero() {
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


void damas_mouse_init() {
    union REGS r;
    r.x.ax = 0;
    int86(0x33, &r, &r);
}

void damas_mouse_show() {
    union REGS r;
    r.x.ax = 1;
    int86(0x33, &r, &r);
}

int damas_mouse_click(int *x, int *y) {
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

void mover_pieza(int fx_param, int fy_param, int tx_param, int ty_param) {
    if ((tablero[ty_param][tx_param] == 'D' && tablero[fy_param][fx_param] == 'd') ||
        (tablero[ty_param][tx_param] == 'd' && tablero[fy_param][fx_param] == 'D')) {
        tablero[ty_param][tx_param] = ' ';
    }
    tablero[ty_param][tx_param] = tablero[fy_param][fx_param];
    tablero[fy_param][fx_param] = ' ';
}

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
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    damas_mouse_init();
    damas_mouse_show();

    while (1) {
        if (actualizar) {
            damas_dibujar_tablero();
            actualizar = 0;
        }

        if (kbhit()) {
            char key = getch();
            if (key == 27) break;
        }

        if (contar_fichas('d') == 0 || contar_fichas('D') == 0) {
            settextstyle(3, 0, 3);
            setcolor(RED);
            outtextxy(200, 250, contar_fichas('d') == 0 ? "¡Azul gana!" : "¡Rojo gana!");
            getch();
            break;
        }

        if (damas_mouse_click(&mx, &my)) {
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


void mostrarMenu() {
    int opcion;  
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    do {
        cleardevice();
        settextstyle(2, 0, 5);
        outtextxy(100, 50, "=== MENU PRINCIPAL ===");
        outtextxy(100, 100, "1. Juego de Dados");
        outtextxy(100, 130, "2. Juego de Minas");
        outtextxy(100, 160, "3. Billar");
        outtextxy(100, 190, "4. Moto GP");
        outtextxy(100, 220, "5. Tragamonedas");
        outtextxy(100, 250, "6. Damas");
        outtextxy(100, 280, "7. Salir..");

        outtextxy(100, 350, "Seleccione una opcion:");

        gotoxy(30, 22);  
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                closegraph(); iniciarJuegoDados(); initgraph(&gd, &gm, ""); break;
            case 2:
                closegraph(); iniciarJuegoMinas(); initgraph(&gd, &gm, ""); break;
            case 3:
                closegraph(); iniciarJuegoBillar(); initgraph(&gd, &gm, ""); break;
            case 4:
                closegraph(); iniciarCarrera(); initgraph(&gd, &gm, ""); break;
            case 5:
                closegraph(); ruleta_jugar(); initgraph(&gd, &gm, ""); break;
            case 6:
                closegraph(); iniciarJuegoDamas(); initgraph(&gd, &gm, ""); break;
            case 7:
                outtextxy(100, 370, "Saliendo..."); delay(1000); break;
            default:
                outtextxy(100, 370, "Opcion invalida."); getch();
        }
    } while (opcion != 7);

    closegraph();
}



int main() {
    mostrarAnimacion();  
    mostrarMenu();
    return 0;
}
