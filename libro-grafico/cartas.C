#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define CARD_WIDTH 100
#define CARD_HEIGHT 150
#define START_X 100
#define START_Y 100
#define GAP 50
#define BUTTON_HEIGHT 30

int gd, gm;
int cartas[3];
char simbolos[3] = {3, 5, 4};
int apuesta, simboloApostado;

void dibujarCarta(int x, int y, int id, int bocaAbajo, int esGanadora) {
    char texto[2];
    int bordeColor = WHITE;
    int i;

    if (!bocaAbajo) {
        bordeColor = esGanadora ? GREEN : RED;
    }

    setcolor(bordeColor);

   
    for (i = 0; i < 3; i++) {
        rectangle(x - i, y - i, x + CARD_WIDTH + i, y + CARD_HEIGHT + i);
    }

    if (bocaAbajo) {
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(x + 2, y + 2, bordeColor);
    } else {
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x + 2, y + 2, bordeColor);

        setcolor(RED);
        settextstyle(DEFAULT_FONT, 0, 4);
        texto[0] = simbolos[id];
        texto[1] = '\0';
        outtextxy(x + 40, y + 60, texto);
    }

    setcolor(WHITE);
    rectangle(x, y + CARD_HEIGHT + 10, x + CARD_WIDTH, y + CARD_HEIGHT + 10 + BUTTON_HEIGHT);
    outtextxy(x + 25, y + CARD_HEIGHT + 18, "Voltear");
}



void mezclarCartas() {
    int i, r, temp;
    cartas[0] = 0;
    cartas[1] = 1;
    cartas[2] = 2;
    for (i = 0; i < 3; i++) {
        r = rand() % 3;
        temp = cartas[i];
        cartas[i] = cartas[r];
        cartas[r] = temp;
    }
}

void pedirApuesta() {
    char desc[50];
    cleardevice();
    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(DEFAULT_FONT, 0, 1);
    outtextxy(50, 30, "== JUEGO DE LAS CARTAS ==");
    outtextxy(50, 60, "Reglas:");
    outtextxy(60, 80, "- Hay 3 cartas:");

    sprintf(desc, "- %c (Corazon), %c (Trebol), %c (Diamante)", 3, 5, 4);
    outtextxy(60, 100, desc);
    outtextxy(60, 120, "- Si volteas la carta con el simbolo que apostaste, ganas $100.");
    outtextxy(60, 140, "- Si no, pierdes tu apuesta.");
    outtextxy(50, 180, "Ingresa tu apuesta (numero): ");
    gotoxy(45, 14);
    scanf("%d", &apuesta);
    cleardevice();
    outtextxy(50, 100, "Apuesta por un simbolo:");
    outtextxy(60, 130, "0 - Corazon");
    outtextxy(60, 150, "1 - Trebol");
    outtextxy(60, 170, "2 - Diamante");
    outtextxy(50, 200, "Seleccion (0-2): ");
    gotoxy(45, 17);
    scanf("%d", &simboloApostado);
    cleardevice();
}

void mostrarCartasBocaAbajo() {
    int i, x;
    for (i = 0; i < 3; i++) {
        x = START_X + i * (CARD_WIDTH + GAP);
        dibujarCarta(x, START_Y, cartas[i], 1, 0);
    }

    settextstyle(DEFAULT_FONT, 0, 1);
    setcolor(WHITE);
    outtextxy(80, 300, "Presiona 1, 2 o 3 para voltear una carta");
}

int main() {
    int seleccionHecha;
    char key;
    int index, x;
    char continuar;
    int esGanadora;

    gd = DETECT;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    srand(time(NULL));

    while (1) {
        seleccionHecha = 0;
        pedirApuesta();
        mezclarCartas();
        cleardevice();
        mostrarCartasBocaAbajo();

        while (!seleccionHecha) {
            key = getch();
            if (key == '1' || key == '2' || key == '3') {
                index = key - '1';
                x = START_X + index * (CARD_WIDTH + GAP);
                esGanadora = (cartas[index] == simboloApostado);
                dibujarCarta(x, START_Y, cartas[index], 0, esGanadora);
                seleccionHecha = 1;

                settextstyle(DEFAULT_FONT, 0, 1);
                if (esGanadora) {
                    setcolor(GREEN);
                    outtextxy(100, 350, "Ganaste $100!");
                } else {
                    setcolor(RED);
                    outtextxy(100, 350, "Perdiste tu apuesta.");
                }

                setcolor(WHITE);
                outtextxy(100, 380, "Presiona ESC para salir o cualquier otra tecla para jugar otra ronda...");
                continuar = getch();
                if (continuar == 27) {
                    closegraph();
                    return 0;
                }
                break;
            }
        }
    }

    closegraph();
    return 0;
}
