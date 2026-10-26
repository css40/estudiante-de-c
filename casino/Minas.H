#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FILAS 8
#define COLUMNAS 8
#define TAM 30

static int matriz[FILAS][COLUMNAS];
static int seleccionadas[FILAS][COLUMNAS];
static int puntos;
static int apuesta;
static int jugando;
static int mousex, mousey;

union REGS in_regs, out_regs;

static void mouse_init() {
    in_regs.x.ax = 0;
    int86(0x33, &in_regs, &out_regs);
}

static void mostrar_mouse() {
    in_regs.x.ax = 1;
    int86(0x33, &in_regs, &out_regs);
}

static void ocultar_mouse() {
    in_regs.x.ax = 2;
    int86(0x33, &in_regs, &out_regs);
}

static int leer_mouse() {
    in_regs.x.ax = 3;
    int86(0x33, &in_regs, &out_regs);
    mousex = out_regs.x.cx;
    mousey = out_regs.x.dx;
    return out_regs.x.bx & 1;
}

static void iniciar_tablero() {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 6 == 0 ? -1 : 1;
            seleccionadas[i][j] = 0;
        }
    }
}

static void dibujar_casilla(int i, int j) {
    int x = 50 + j * TAM;
    int y = 80 + i * TAM;
    if (seleccionadas[i][j] == 0)
        setfillstyle(SOLID_FILL, BLUE);
    else if (matriz[i][j] == -1)
        setfillstyle(SOLID_FILL, RED);
    else
        setfillstyle(SOLID_FILL, GREEN);
    bar(x, y, x + TAM - 2, y + TAM - 2);
    rectangle(x, y, x + TAM - 2, y + TAM - 2);
}

static void dibujar_tablero() {
    int i, j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            dibujar_casilla(i, j);
        }
    }
}

static void mostrar_texto() {
    char msg[40];
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
    sprintf(msg, "Puntos: %d", puntos);
    outtextxy(20, 20, msg);
    sprintf(msg, "Apuesta: %d", apuesta);
    outtextxy(200, 20, msg);
}

static void procesar_clic() {
    int col = (mousex - 50) / TAM;
    int fil = (mousey - 80) / TAM;
    if (col >= 0 && col < COLUMNAS && fil >= 0 && fil < FILAS) {
        if (seleccionadas[fil][col] == 0 && jugando) {
            seleccionadas[fil][col] = 1;
            if (matriz[fil][col] == -1) {
                jugando = 0;
                puntos -= apuesta;
            } else {
                puntos += apuesta * 2;
            }
            dibujar_casilla(fil, col);
            mostrar_texto();
        }
    }
}

static void pedir_apuesta() {
    char entrada[6] = "";
    char tecla;
    int valor = 0, pos = 0;

    while (1) {
        setfillstyle(SOLID_FILL, BLACK);
        bar(80, 80, 400, 160);
        setcolor(WHITE);
        rectangle(80, 80, 400, 160);
        outtextxy(100, 100, "Ingresa tu apuesta (1 - tus puntos):");

        pos = 0;
        entrada[0] = '\0';

        while (1) {
            tecla = getch();

            if (tecla >= '0' && tecla <= '9' && pos < 4) {
                entrada[pos++] = tecla;
                entrada[pos] = '\0';
            } else if (tecla == 8 && pos > 0) {
                pos--;
                entrada[pos] = '\0';
            } else if (tecla == 13 && pos > 0) {
                break;
            }

            setfillstyle(SOLID_FILL, BLACK);
            bar(100, 130, 300, 150);
            outtextxy(100, 130, entrada);
        }

        valor = atoi(entrada);
        if (valor > 0 && valor <= puntos) {
            apuesta = valor;
            break;
        } else {
            setcolor(RED);
            outtextxy(100, 160, "Apuesta invalida. Intenta de nuevo.");
            delay(1000);
            setfillstyle(SOLID_FILL, BLACK);
            bar(100, 160, 400, 180);
        }
    }
}

void iniciarJuegoMinas() {
    char respuesta;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    srand(time(NULL));
    puntos = 100;
    mouse_init();
    mostrar_mouse();

    while (1) {
        cleardevice();
        pedir_apuesta();
        iniciar_tablero();
        cleardevice();
        dibujar_tablero();
        mostrar_texto();
        jugando = 1;

        while (jugando) {
            if (leer_mouse()) {
                ocultar_mouse();
                procesar_clic();
                delay(200);
                while (leer_mouse());
                mostrar_mouse();
            }
            delay(10);
        }

        if (puntos <= 0) {
            setcolor(YELLOW);
            outtextxy(100, 350, "Te quedaste sin puntos!");
            outtextxy(100, 370, "Tus puntos se reiniciaran a 100.");
            puntos = 100;
            getch();
        }

        setcolor(YELLOW);
        outtextxy(100, 390, "Quieres seguir jugando? (S/N)");

        do {
            respuesta = getch();
            if (respuesta == 'n' || respuesta == 'N') {
                closegraph();
                return;
            }
        } while (respuesta != 's' && respuesta != 'S');
    }

    cleardevice();
    outtextxy(100, 200, "Juego terminado. Gracias por jugar.");
    getch();
    return;
}
