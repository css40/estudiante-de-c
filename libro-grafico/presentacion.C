#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>

void dibujarFigura() {
    setcolor(WHITE);
    line(368,194, 499,231);
    line(499,231, 521,244);
    line(521,244, 549,307);
    line(549,307, 320,447);
    line(320,447, 311,451);
    line(311,451, 297,445);
    line(297,445, 68,309);
    line(68,309, 114,232);
    line(114,232, 246,199);
    line(246,199, 249,202);
    line(249,202, 248,213);
    line(248,213, 129,243);
    line(129,243, 95,304);
    line(95,304, 300,423);
    line(300,423, 316,429);
    line(316,429, 532,304);
    line(532,304, 530,288);
    line(530,288, 501,242);
    line(501,242, 471,233);
    line(471,233, 366,207);
    line(366,207, 361,202);
    line(361,202, 380,197);
    line(380,197, 368,194);  
}

void dibujarEstrella1() {
    setcolor(WHITE);
    line(307,146, 295,171);
    line(295,171, 267,175);
    line(267,175, 288,190);
    line(288,190, 281,222);
    line(281,222, 306,205);
    line(306,205, 330,220);
    line(330,220, 322,193);
    line(322,193, 344,176);
    line(344,176, 317,169);
    line(317,169, 307,146);
    line(307,146, 302,157);
    line(302,157, 307,146);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 180, WHITE); 
}

void dibujarEstrella2(int color) {
    setcolor(WHITE);
    line(350,176, 343,189);
    line(343,189, 329,192);
    line(329,192, 339,201);
    line(339,201, 335,218);
    line(335,218, 350,208);  
    line(350,208, 366,221);
    line(366,221, 359,202);
    line(359,202, 371,191);
    line(371,191, 356,189);
    line(356,189, 350,176);
    line(350,176, 345,187);
    line(345,187, 350,176);
    setfillstyle(SOLID_FILL, color);
    floodfill(345, 190, WHITE);
}

void dibujarEstrella3(int color) {
    setcolor(WHITE);
    line(261,173, 252,185);
    line(252,185, 234,191);
    line(234,191, 250,202);
    line(250,202, 244,219);
    line(244,219, 261,209);
    line(261,209, 277,220);
    line(277,220, 272,202);
    line(272,202, 284,193);
    line(284,193, 269,190);
    line(269,190, 260,173);
    line(260,173, 253,183);
    line(253,183, 261,173);
    setfillstyle(SOLID_FILL, color);
    floodfill(255, 190, WHITE); 
}

void dibujarEstrella4() {
    setcolor(WHITE);
    line(399,157, 395,201);
    line(395,201, 369,193);
    line(369,193, 372,190);
    line(372,190, 357,189);
    line(357,189, 350,179);
    line(350,179, 344,189);
    line(344,189, 320,192);
    line(320,192, 320,193);
    line(320,193, 344,177);
    line(344,177, 319,168);
    line(319,168, 320,93);
    line(320,93, 399,152);
    line(399,152, 400,160);
    line(400,160, 399,157);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(350, 160, WHITE);
}

void dibujarEstrella5() {
    setcolor(WHITE);
    line(246,198, 219,205);
    line(219,205, 219,148);
    line(219,148, 301,96);
    line(301,96, 296,170);
    line(296,170, 266,176);
    line(266,176, 286,190);
    line(286,190, 270,190);
    line(270,190, 261,175);
    line(261,175, 253,185);
    line(253,185, 234,190);
    line(234,190, 244,199);
    line(244,199, 246,198);
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(250, 160, WHITE);
}

void escribirCasino() {
    const char* texto = "CASINO";
    int anchoTexto = textwidth(texto);
    int x = (500 - anchoTexto) / 2;
    int y = 260; 
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(x, y, texto);
}

void escribirUniversal() {
    const char* texto = "UNI";
    int anchoTexto = textwidth(texto);
    int x = (640 - anchoTexto) / 2;
    int y = 300;  
    setcolor(LIGHTCYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(x, y, texto);
}

void dibujarCarta(int x, int y) {
    setcolor(WHITE);
    rectangle(x, y, x + 40, y + 60);
    circle(x + 5, y + 5, 5);
    circle(x + 35, y + 5, 5);
    circle(x + 5, y + 55, 5);
    circle(x + 35, y + 55, 5);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 20, y + 30, WHITE);
    setcolor(RED);
    line(x + 20, y + 20, x + 15, y + 30);
    line(x + 15, y + 30, x + 20, y + 40);
    line(x + 20, y + 40, x + 25, y + 30);
    line(x + 25, y + 30, x + 20, y + 20);
}

void dibujarCartasAleatorias() {
    int r,i;
    int posiciones[][2] = {
        {30, 30}, {550, 30}, {30, 400}, {550, 400}, {100, 50}, {500, 380}, {120, 420}, {480, 50}
    };
    int usados[8] = {0};
    for ( i = 0; i < 4; i++) {
      
        do {
            r = rand() % 8;
        } while (usados[r]);
        usados[r] = 1;
        dibujarCarta(posiciones[r][0], posiciones[r][1]);
    }
}

void escribirPresionaEnter() {
    const char* texto = "Presiona ENTER";
    int anchoTexto = textwidth(texto);
    int x = (525 - anchoTexto) / 2;
    int y = 80;  
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(x, y, texto);
}


int main() {
    int gd = DETECT, gm;
    int colores[] = {RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, LIGHTRED};
    int i = 0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    cleardevice();
    srand(time(NULL));

    dibujarFigura();
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(380, 200, WHITE);
    dibujarEstrella1();
    escribirPresionaEnter(); 
    escribirCasino();
    escribirUniversal();
    dibujarCartasAleatorias();
 

    while (!kbhit()) {
        dibujarFigura();
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(380, 200, WHITE);
    

        dibujarEstrella1();
        dibujarEstrella2(colores[i]);
        dibujarEstrella3(colores[i]);
        dibujarEstrella4();
        dibujarEstrella5();
        dibujarCartasAleatorias();

        i = (i + 1) % (sizeof(colores)/sizeof(colores[0]));
        delay(300);
    }

    getch();
    closegraph();
    return 0;
}
