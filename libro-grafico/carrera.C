#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void moto(int x, int y, int c);

int main() {
    int gd = DETECT, gm;
    int pos[4] = {50, 50, 50, 50};
    int laneY[4] = {0, 60, 120, 180};
    int colors[4] = {RED, GREEN, BLUE, CYAN};
    char corredores[4][20] = {"Valentino Rossi", "Marc Marquez", "Jorge Lorenzo", "Casey Stoner"};
    int apuesta, elegido, i, winner = -1, step;
    char msg[50];

    printf("==== CARRERA DE MOTOS ====\n");
    printf("Corredores disponibles:\n");
    for (i = 0; i < 4; i++) {
        printf("%d. %s (%s)\n", i + 1, corredores[i],
            (colors[i] == RED) ? "Rojo" :
            (colors[i] == GREEN) ? "Verde" :
            (colors[i] == BLUE) ? "Azul" : "Cian");
    }

    printf("Por cual corredor apuestas? (1-4): ");
    scanf("%d", &elegido);
    elegido--; 

    if (elegido < 0 || elegido > 3) {
        printf("Seleccion invalida. Cerrando programa.\n");
        return 1;
    }

    printf("Cuato quieres apostar?: $");
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

    getch();
    closegraph();
    return 0;
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
