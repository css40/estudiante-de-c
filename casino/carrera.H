#ifndef CARRERA_H
#define CARRERA_H

#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>


void copa(int offsetX, int offsetY, int color);
void oreja2(int offsetX, int offsetY, int color);
void oreja1(int offsetX, int offsetY, int color);
void baseCopa(int offsetX, int offsetY, int color);
void cajaBase(int offsetX, int offsetY);
void estrella(int offsetX, int offsetY);
void destello(int offsetX, int offsetY);
void moto(int x, int y, int c);
void iniciarCarrera();



void copa(int offsetX, int offsetY, int color) {
    int puntos[][2] = {
        {204, 39}, {395, 39}, {398, 48}, {399, 71}, {398, 97},
        {395, 128}, {385, 162}, {376, 181}, {356, 209},
        {314, 234}, {294, 237}, {272, 229}, {247, 210},
        {219, 168}, {207, 124}, {203, 66}, {204, 39}, {217, 39}
    };
    int n = 18, i;
    int polyPoints[2 * 18];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillpoly(n, polyPoints);
}

void oreja2(int offsetX, int offsetY, int color) {
    int puntos[][2] = {
        {202, 64}, {149, 64}, {143, 71}, {144, 85}, {147, 111},
        {151, 134}, {155, 150}, {163, 163}, {175, 177},
        {188, 188}, {214, 199}, {229, 202}, {242, 203},
        {228, 184}, {212, 181}, {198, 175}, {182, 163},
        {175, 153}, {172, 143}, {166, 122}, {161, 96},
        {161, 81}, {203, 81}, {203, 64}, {181, 64}
    };
    int n = 25, i;
    int polyPoints[2 * 25];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillpoly(n, polyPoints);
}

void oreja1(int offsetX, int offsetY, int color) {
    int puntos[][2] = {
        {398, 64}, {447, 64}, {452, 65}, {458, 75}, {458, 98},
        {454, 121}, {447, 145}, {433, 173}, {416, 187},
        {391, 199}, {365, 202}, {361, 202}, {375, 183},
        {387, 184}, {404, 174}, {418, 164}, {434, 133},
        {440, 101}, {440, 80}, {400, 83}, {399, 64}, {418, 63}
    };
    int n = 21, i;
    int polyPoints[2 * 21];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillpoly(n, polyPoints);
}

void baseCopa(int offsetX, int offsetY, int color) {
    int puntos[][2] = {
        {286, 234}, {287, 251}, {283, 272}, {279, 284},
        {274, 294}, {272, 297}, {256, 298}, {250, 302},
        {242, 310}, {242, 318}, {358, 317}, {357, 309},
        {350, 302}, {331, 299}, {326, 295}, {319, 275},
        {315, 256}, {313, 237}, {313, 235}, {306, 235},
        {295, 236}, {287, 235}, {286, 235}, {288, 246}
    };
    int n = 24, i;
    int polyPoints[2 * 24];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillpoly(n, polyPoints);
}

void cajaBase(int offsetX, int offsetY) {
    int puntos[][2] = {
        {206, 317}, {392, 318}, {391, 381}, {210, 380},
        {207, 317}, {218, 317}
    };
    int n = 6, i;
    int polyPoints[2 * 6];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    fillpoly(n, polyPoints);
}

void estrella(int offsetX, int offsetY) {
    int puntos[][2] = {
        {302, 91}, {289, 116}, {262, 119}, {282, 140},
        {275, 168}, {303, 155}, {329, 170}, {322, 140},
        {342, 120}, {316, 117}, {302, 90}, {294, 106}
    };
    int n = 12, i;
    int polyPoints[2 * 12];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(6);
    setfillstyle(SOLID_FILL, 6);
    fillpoly(n, polyPoints);
}

void destello(int offsetX, int offsetY) {
    int puntos[][2] = {
        {227, 47}, {225, 56}, {220, 61}, {215, 65}, {209, 65},
        {216, 67}, {221, 72}, {225, 76}, {227, 84}, {230, 77},
        {235, 70}, {241, 67}, {247, 66}, {240, 62}, {235, 57},
        {232, 55}, {228, 49}, {227, 48}, {223, 57}
    };
    int n = 19, i;
    int polyPoints[2 * 19];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i] = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(n, polyPoints);
}

void moto(int x, int y, int c) {
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    moveto(134 + x, 131 + y);
    lineto(146 + x, 144 + y);
    lineto(147 + x, 149 + y);
    lineto(153 + x, 152 + y);
    lineto(154 + x, 160 + y);
    lineto(151 + x, 167 + y);
    lineto(144 + x, 169 + y);
    lineto(134 + x, 164 + y);
    lineto(131 + x, 158 + y);
    lineto(132 + x, 166 + y);
    lineto(101 + x, 168 + y);
    lineto(101 + x, 163 + y);
    lineto(99  + x, 163 + y);
    lineto(94  + x, 170 + y);
    lineto(36  + x, 169 + y);
    lineto(79  + x, 164 + y);
    lineto(77  + x, 160 + y);
    lineto(79  + x, 153 + y);
    lineto(84  + x, 148 + y);
    lineto(91  + x, 149 + y);
    lineto(100 + x, 154 + y);
    lineto(102 + x, 153 + y);
    lineto(96  + x, 145 + y);
    lineto(81  + x, 138 + y);
    lineto(92  + x, 137 + y);
    lineto(97  + x, 141 + y);
    lineto(102 + x, 134 + y);
    lineto(107 + x, 127 + y);
    lineto(113 + x, 125 + y);
    lineto(119 + x, 120 + y);
    lineto(120 + x, 117 + y);
    lineto(125 + x, 115 + y);
    lineto(130 + x, 121 + y);
    lineto(126 + x, 126 + y);
    lineto(121 + x, 125 + y);
    lineto(121 + x, 129 + y);
    lineto(124 + x, 137 + y);
    lineto(128 + x, 137 + y);
    lineto(134 + x, 140 + y);
    lineto(137 + x, 137 + y);
    lineto(133 + x, 132 + y);
    lineto(136 + x, 133 + y);
    lineto(143 + x, 141 + y);
    lineto(134 + x, 131 + y);
}


void iniciarCarrera() {
    int gd = DETECT, gm;
    int pos[4] = {50, 50, 50, 50};
    int laneY[4] = {0, 60, 120, 180};
    int colors[4] = {RED, GREEN, BLUE, CYAN};
    char corredores[4][20] = {"Valentino Rossi", "Marc Marquez", "Jorge Lorenzo", "Casey Stoner"};
    int apuesta, elegido, i, winner = -1, step;
    char msg[100];

    printf("==== CARRERA DE MOTOS ====\n");
    for (i = 0; i < 4; i++) {
        printf("%d. %s (%s)\n", i + 1, corredores[i],
            (colors[i] == RED) ? "Rojo" :
            (colors[i] == GREEN) ? "Verde" :
            (colors[i] == BLUE) ? "Azul" : "Cian");
    }

    printf("Por cual corredor apuestas? (1-4): ");
    scanf("%d", &elegido);
    elegido--;

    printf("Cuanto quieres apostar?: $");
    scanf("%d", &apuesta);

    initgraph(&gd, &gm, "");
    srand(time(NULL));

    while (winner == -1) {
        cleardevice();
        for (i = 0; i < 4; i++) {
            step = 1 + rand() % 5;
            pos[i] += step;
            if (pos[i] + 150 >= getmaxx() && winner == -1)
                winner = i;
            moto(pos[i], laneY[i], colors[i]);
        }
        delay(100);
    }

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(50, 250, "Carrera terminada");
    sprintf(msg, "Gana la moto #%d: %s", winner + 1, corredores[winner]);
    outtextxy(50, 280, msg);

    if (winner == elegido) {
        sprintf(msg, "Ganaste! Has ganado $%d", apuesta * 2);
    } else {
        sprintf(msg, "Perdiste. Has perdido $%d", apuesta);
    }
    outtextxy(50, 310, msg);
    outtextxy(50, 340, "Presiona una tecla para ver al ganador...");
    getch();

    cleardevice();
    setbkcolor(BLACK);
    copa(0, 0, YELLOW);
    oreja1(0, 0, YELLOW);
    oreja2(0, 0, YELLOW);
    baseCopa(0, 0, YELLOW);
    cajaBase(0, 0);
    estrella(0, 0);
    destello(0, 0);

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    sprintf(msg, "Ganador: %s", corredores[winner]);
    outtextxy(200, 400, msg);

    if (winner == elegido) {
        sprintf(msg, "Ganaste! Premio: $%d", apuesta * 2);
    } else {
        sprintf(msg, "Perdiste. Apostaste: $%d", apuesta);
    }
    outtextxy(200, 430, msg);

    getch();
    closegraph();
}

#endif
