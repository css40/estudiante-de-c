#ifndef PARCHIS_H
#define PARCHIS_H

#define TAM 20
#define BASE 6
#define PASOS 52

extern int pathX[PASOS], pathY[PASOS];

void casilla(int x, int y, int color);
void base_jugador(int x, int y, int color);
void dibujar_dado(int valor);
void dibujar_tablero(int offsetX, int offsetY);
void definir_camino(int offsetX, int offsetY);
void ficha(int x, int y, int color);
void parchis_main();


#endif
