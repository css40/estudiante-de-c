#ifndef RULETA_H
#define RULETA_H

#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>


static int gd = DETECT, gm;
static int resultado[3];
static char simbolos[12] = {3, 4, 5, 6, 1, 2, 30, 31, '7', '8', '9', '0'};
static char str[2];
static int colores[6] = {RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW};
static int colActual[3], velocidad, tiempoTotal, t, tecla;
static int i, j, x, xpos, ypos, baseX, intentos = 0;
static char tstr[3];

static void dibujarMarco() {
    setcolor(YELLOW);
    rectangle(100, 100, 400, 200);
    for (i = 0; i < 3; i++) {
        setcolor(colActual[i]);
        rectangle(110 + i * 70, 110, 170 + i * 70, 190);
    }
}

static void mostrarSimbolo(int pos, char simbolo) {
    str[0] = simbolo;
    str[1] = 0;
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 6);
    setcolor(WHITE);
    x = 120 + pos * 70;
    setfillstyle(SOLID_FILL, BLACK);
    bar(x - 10, 120, x + 50, 180);
    outtextxy(x, 130, str);
}

static void dibujarPalanca(int estado) {
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, BLACK);
    bar(420, 80, 470, 180);
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(420, 150, 440, 170);
    floodfill(421, 151, LIGHTGRAY);
    if (estado == 0) {
        line(430, 150, 460, 100);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(460, 100, 10, 10);
    } else {
        line(430, 170, 460, 200);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(460, 200, 10, 10);
    }
}

static void dibujarBoton(int x1, int y1, int x2, int y2, char *texto, int colorFondo) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, colorFondo);
    rectangle(x1, y1, x2, y2);
    floodfill(x1 + 1, y1 + 1, WHITE);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x1 + 10, y1 + 5, texto);
}

static void dibujarBotonesNumeros() {
    baseX = 160;
    xpos = baseX;
    ypos = 220;
    for (i = 1; i <= 4; i++) {
        sprintf(tstr, "%d", i);
        dibujarBoton(xpos, ypos, xpos + 30, ypos + 30, tstr, BLUE);
        xpos += 40;
    }
    xpos = baseX;
    ypos = 260;
    for (i = 5; i <= 8; i++) {
        sprintf(tstr, "%d", i);
        dibujarBoton(xpos, ypos, xpos + 30, ypos + 30, tstr, BLUE);
        xpos += 40;
    }
    xpos = baseX + 40;
    ypos = 300;
    dibujarBoton(xpos, ypos, xpos + 30, ypos + 30, "9", BLUE);
    dibujarBoton(xpos + 40, ypos, xpos + 70, ypos + 30, "0", BLUE);
}

static void mensajeGanaste() {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(GREEN);
    outtextxy(150, 350, "GANASTE!");
    for (i = 0; i < 50; i++) {
        setcolor(rand() % 15 + 1);
        circle(100 + rand() % 300, 100 + rand() % 200, 2 + rand() % 3);
        delay(30);
    }
}

static void mensajePerdiste() {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(RED);
    outtextxy(150, 350, "Intenta de nuevo");
    sound(200);
    delay(200);
    nosound();
}

static void limpiarMensajes() {
    setfillstyle(SOLID_FILL, BLACK);
    bar(100, 340, 400, 380);
}

static void girar() {
    velocidad = 20;
    tiempoTotal = 5000;
    t = 0;
    colActual[0] = RED;
    colActual[1] = GREEN;
    colActual[2] = BLUE;
    while (t < tiempoTotal) {
        for (j = 0; j < 3; j++) {
            resultado[j] = rand() % 12;
        }
        dibujarMarco();
        for (j = 0; j < 3; j++) {
            mostrarSimbolo(j, simbolos[resultado[j]]);
        }
        dibujarPalanca(1);
        dibujarBotonesNumeros();
        delay(velocidad);
        t += velocidad;
        if (velocidad < 300) velocidad += 10;
        for (j = 0; j < 3; j++) {
            colActual[j]++;
            if (colActual[j] > YELLOW) colActual[j] = RED;
        }
    }
    intentos++;
    if (intentos == 3) {
        resultado[0] = 8;
        resultado[1] = 8;
        resultado[2] = 8;
        intentos = 0;
    }
}


static int ruleta_jugar() {
    initgraph(&gd, &gm, "");
    srand(time(NULL));
    while (1) {
        cleardevice();
        colActual[0] = RED;
        colActual[1] = GREEN;
        colActual[2] = BLUE;
        dibujarMarco();
        dibujarPalanca(0);
        dibujarBotonesNumeros();
        limpiarMensajes();
        tecla = getch();
        if (tecla == 27) break;
        if (tecla == 13) {
            girar();
            limpiarMensajes();
            dibujarMarco();
            for (j = 0; j < 3; j++) {
                mostrarSimbolo(j, simbolos[resultado[j]]);
            }
            dibujarPalanca(0);
            dibujarBotonesNumeros();
            if (resultado[0] == 8 && resultado[1] == 8 && resultado[2] == 8)
                mensajeGanaste();
            else
                mensajePerdiste();
            settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
            setcolor(WHITE);
            outtextxy(120, 370, "ENTER = intentar de nuevo | ESC = salir");
            while (1) {
                tecla = getch();
                if (tecla == 13 || tecla == 27) break;
            }
            if (tecla == 27) break;
        }
    }
    closegraph();
    return 0;
}

#endif
