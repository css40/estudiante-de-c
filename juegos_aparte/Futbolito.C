#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

void dibujarPeon(int x, int y, int color) {
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	fillellipse(x, y, 10, 10);
	bar(x - 5, y + 10, x + 5, y + 30);
}

void dibujarPelota(int x, int y) {
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, WHITE);
	fillellipse(x, y, 6, 6);
}

void borrarPelotaInteligente(int x, int y) {
	int dx = x - 310;
	int dy = y - 230;
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	fillellipse(x, y, 7, 7);
	if (x >= 308 && x <= 312) {
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
		line(310, 60, 310, 410);
	}
	if (dx * dx + dy * dy <= 50 * 50) {
		setcolor(WHITE);
		circle(310, 230, 50);
	}
}

void dibujarCampo() {
	int rec[] = {10,60,630,60,630,410,10,410,10,60};
	setcolor(GREEN);
	setfillstyle(SOLID_FILL, GREEN);
	drawpoly(5, rec);
	fillpoly(5, rec);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE,1,THICK_WIDTH);
	line(10,60,630,60);
	line(630,60,630,410);
	line(630,410,10,410);
	line(10,410,10,60);
	line(10,200,40,200);
	line(40,200,40,260);
	line(40,260,10,260);
	line(10,160,80,160);
	line(80,160,80,300);
	line(80,300,10,300);
	arc(90,230,250,110,30);
	circle(310,230,50);
	line(310,60,310,410);
	line(630,200,600,200);
	line(600,200,600,260);
	line(600,260,630,260);
	line(630,165,560,165);
	line(560,165,560,300);
	line(560,300,630,300);
	arc(570,233,110,250,30);
	arc(10,60,270,3,20);
	arc(630,60,180,3,20);
	arc(10,410,360,90,20);
	arc(630,410,1,170,20);
}

int moverPelota(int x1, int y1, int x2, int y2) {
	float dx = (x2 - x1) / 20.0;
	float dy = (y2 - y1) / 20.0;
	int i;
	int px, py, prevX = x1, prevY = y1;
	for(i = 0; i <= 20; i++) {
		px = x1 + dx * i;
		py = y1 + dy * i;
		borrarPelotaInteligente(prevX, prevY);
		dibujarPelota(px, py);
		if(px < 20 || px > 620) {
			return 1;
		}
		prevX = px;
		prevY = py;
		delay(35);
	}
	return 0;
}

void main() {
	int pantalla = DETECT, modo;
	int j1X[11] = {15, 85, 85, 85, 85, 240, 240, 240, 420, 420, 420};
	int j1Y[11] = {230, 110, 190, 265, 350, 150, 225, 310, 75, 225, 390};
	int j2X[11] = {615, 560, 560, 560, 560, 400, 400, 400, 190, 190, 190};
	int j2Y[11] = {230, 110, 190, 265, 350, 150, 225, 310, 75, 225, 390};
	int i, j, posX[22], posY[22], colores[22];
	int actual, siguiente, gol;
	int pelotaX = 310, pelotaY = 230;

	randomize();
	clrscr();
	initgraph(&pantalla, &modo, "C:\\TC\\BGI");

	for(i = 0; i < 11; i++) {
		posX[i] = j1X[i];
		posY[i] = j1Y[i];
		colores[i] = RED;
	}
	for(i = 0; i < 11; i++) {
		posX[i + 11] = j2X[i];
		posY[i + 11] = j2Y[i];
		colores[i + 11] = BLUE;
	}

	dibujarCampo();
	for(i = 0; i < 22; i++) {
		dibujarPeon(posX[i], posY[i], colores[i]);
	}

	actual = random(22);
	pelotaX = posX[actual];
	pelotaY = posY[actual];
	dibujarPelota(pelotaX, pelotaY);
	delay(500);

	for(i = 0; i < 100; i++) {
		if(kbhit()) {
			char tecla = getch();
			if(tecla == 27) {
				break;
			}
		}

		do {
			siguiente = random(22);
		} while(siguiente == actual);

		gol = moverPelota(pelotaX, pelotaY, posX[siguiente], posY[siguiente]);

		for(j = 0; j < 22; j++) {
			dibujarPeon(posX[j], posY[j], colores[j]);
		}

		if(gol == 1) {
			setcolor(WHITE);
			settextstyle(3, 0, 4);
			if(colores[actual] == RED)
				outtextxy(180, 200, "GOOOOL EQUIPO ROJO");
			else
				outtextxy(180, 200, "GOOOOL EQUIPO AZUL");
			break;
		}

		pelotaX = posX[siguiente];
		pelotaY = posY[siguiente];
		actual = siguiente;
	}

	getch();
	closegraph();
}