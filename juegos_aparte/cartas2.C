#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

#define ANCHO_CARTA 80
#define ALTO_CARTA 120

char simbolos_palos[] = {6, 3, 4, 5}; 
int gd = DETECT, gm;
int carta1, carta2;
char palo1, palo2;
char texto_num[3];
char texto_palo[2];
char tecla;
int intentos, jugando;
int continuar;

void dibujarCarta(int x, int y, int numero, char palo) {
    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + ANCHO_CARTA, y + ALTO_CARTA);
    setcolor(BLACK);
    rectangle(x, y, x + ANCHO_CARTA, y + ALTO_CARTA);

    sprintf(texto_num, "%d", numero);
    settextstyle(DEFAULT_FONT, 0, 1);
    outtextxy(x + 5, y + 5, texto_num); 

    settextstyle(0, 0, 4); 
    texto_palo[0] = palo;
    texto_palo[1] = '\0';
    outtextxy(x + 25, y + 40, texto_palo);

    settextstyle(DEFAULT_FONT, 0, 1); 
}

int generarNumeroCarta() {
    return rand() % 13 + 1;
}

char generarPaloCarta() {
    return simbolos_palos[rand() % 4];
}

void mostrarTextoSuperior() {
    setcolor(WHITE);
    outtextxy(10, 10, "Mayor o Menor (H = Mayor, L = Menor, ESC = Salir)");
}

void mostrarMensaje(char* mensaje, int color) {
    setcolor(color);
    outtextxy(200, 280, mensaje);
    delay(1500);
    setcolor(BLACK);
    outtextxy(200, 280, mensaje);
}

int main() {
    initgraph(&gd, &gm, "");
    srand(time(NULL));

    continuar = 1;

    while (continuar) {
        intentos = 0;
        jugando = 1;

        while (jugando && intentos < 3) {
            cleardevice();
            mostrarTextoSuperior();

            carta1 = generarNumeroCarta();
            palo1 = generarPaloCarta();
            dibujarCarta(100, 100, carta1, palo1);

            do {
                tecla = getch();
            } while (tecla != 'h' && tecla != 'l' && tecla != 27);

            if (tecla == 27) {
                jugando = 0;
                continuar = 0;
                break;
            }

            carta2 = generarNumeroCarta();
            palo2 = generarPaloCarta();
            dibujarCarta(300, 100, carta2, palo2);

            if ((tecla == 'h' && carta2 > carta1) || (tecla == 'l' && carta2 < carta1)) {
                mostrarMensaje("GANASTE!", GREEN);
            } else if (carta2 == carta1) {
                mostrarMensaje("EMPATE!", YELLOW);
            } else {
                mostrarMensaje("PERDISTE", RED);
            }

            intentos++;
        }

        if (continuar) {
            cleardevice();
            mostrarTextoSuperior();
            setcolor(WHITE);
            outtextxy(150, 200, "Quieres seguir jugando? (S = si / N = no)");

            do {
                tecla = getch();
            } while (tecla != 's' && tecla != 'n');

            if (tecla == 'n') {
                continuar = 0;
            }
        }
    }

    closegraph();
    return 0;
}
