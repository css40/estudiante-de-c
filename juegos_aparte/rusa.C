#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <math.h>

#define PI 3.14159265
#define NUM_SECTORES 8

void dibujarCara();
void dibujarOjo();
void dibujarOjo2();
void dibujarCuerpo();
void dibujarBrazo();
void dibujarPistola1();
void dibujarMangoPistola();
void dibujarMangoDePistola3();
void dibujarMano2();
void dibujarGatillo();
void mostrarMensajeMuerte();
void mostrarMuerte();

void dibujarFigura() {
    int points[][2] = {
        {557,66},{560,67},{565,70},{574,78},{579,87},
        {509,159},{512,168},{523,179},{515,186},{516,194},
        {522,202},{519,216},{514,222},{506,228},{499,232},
        {488,241},{492,249},{496,254},{499,260},{506,266},
        {506,270},{511,279},{503,287},{480,303},{463,277},
        {454,248},{451,231},{445,225},{447,218},{452,210},
        {452,195},{450,181},{450,179},{547,84},{553,72},
        {557,66}
    };
    int n = sizeof(points) / sizeof(points[0]);
    int i;
    for(i = 0; i < n - 1; i++)
        line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
}

void dibujarSegundaFigura() {
    int points[][2] = {
        {79,65},{84,72},{88,78},{96,90},
        {188,181},{186,189},{186,200},{187,210},{192,221},{192,225},
        {187,228},{184,238},{184,250},{177,269},{172,284},{163,297},
        {158,302},{142,295},{130,280},{131,272},{131,267},{135,264},
        {139,255},{144,252},{149,247},{150,242},{146,236},{142,232},
        {129,227},{121,219},{115,207},{116,196},{124,189},{115,177},
        {124,169},{128,161},{58,89},{64,76},{75,67},{80,66},{87,77}
    };
    int n = sizeof(points) / sizeof(points[0]);
    int i;
    for(i = 0; i < n - 1; i++)
        line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
}

void mango() {
    int points[][2] = {
        {446,222},{453,213},{458,216},{467,224},{472,223},{478,219},
        {484,219},{492,223},{498,229},{499,231},{490,235},{490,241},
        {492,247},{498,257},{504,265},{509,270},{509,274},{502,287},
        {486,301},{479,302},{473,292},{464,273},{460,263},{456,254},
        {454,243},{448,229},{446,224},{453,213},{467,223}
    };
    int n = sizeof(points) / sizeof(points[0]);
    int i;

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    for(i = 0; i < n - 1; i++)
        line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    line(points[n-1][0], points[n-1][1], points[0][0], points[0][1]);
    floodfill(460, 260, RED);
}

void mago2() {
    int points[][2] = {
        {184,213},{190,218},{192,224},{185,229},{185,238},{182,255},
        {178,270},{171,281},{165,296},{159,303},{148,300},{135,287},
        {127,279},{131,268},{134,265},{139,259},{140,254},{145,251},
        {149,248},{150,239},{139,230},{147,223},{154,219},{161,223},
        {170,225},{176,219},{181,216},{182,213},{186,215},{191,218},
        {143,235}
    };
    int n = sizeof(points) / sizeof(points[0]);
    int i;

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    for(i = 0; i < n - 1; i++)
        line(points[i][0], points[i][1], points[i+1][0], points[i+1][1]);
    line(points[n-1][0], points[n-1][1], points[0][0], points[0][1]);

    floodfill(150, 250, RED);
}

void initMouse() {
    union REGS regs;
    regs.x.ax = 0; 
    int86(0x33, &regs, &regs);
}

int mouseX() {
    union REGS regs;
    regs.x.ax = 3;  
    int86(0x33, &regs, &regs);
    return regs.x.cx;
}

int mouseY() {
    union REGS regs;
    regs.x.ax = 3; 
    int86(0x33, &regs, &regs);
    return regs.x.dx;
}

int mouseLeftPressed() {
    union REGS regs;
    regs.x.ax = 3;
    int86(0x33, &regs, &regs);
    return (regs.x.bx & 1); 
}



int clickEnBoton(int bx, int by, int bw, int bh, int x, int y) {
    return (x >= bx && x <= bx + bw && y >= by && y <= by + bh);
}

void dibujarBoton(int bx, int by, int bw, int bh, const char *texto) {
    rectangle(bx, by, bx + bw, by + bh);
    outtextxy(bx + 10, by + 10, texto);
}



void dibujarSector(int cx, int cy, int r, int startAngle, int endAngle, int color, const char *texto) {
        int midAngle = (startAngle + endAngle) / 2;
    int tx = cx + (r / 2) * cos(midAngle * M_PI / 180);
    int ty = cy - (r / 2) * sin(midAngle * M_PI / 180);
    setfillstyle(SOLID_FILL, color);
    pieslice(cx, cy, startAngle, endAngle, r);

    setcolor(WHITE);
    outtextxy(tx - textwidth(texto)/2, ty - textheight(texto)/2, texto);
}

void ruletaVisual() {
    int cx, cy, r, i, resultado, angulo;
    const char *opciones[2] = {"VIDA", "MUERTE"};
    int colores[2] = {GREEN, RED};
    cx = 320;
    cy = 240;
    r = 150;
    srand(time(NULL));
    for(i = 0; i < 30; i++) {
        angulo = (i * 30 + rand() % 30) % 360;
        cleardevice();
        dibujarSector(cx, cy, r, (0 + angulo) % 360, (180 + angulo) % 360, colores[0], opciones[0]);
        dibujarSector(cx, cy, r, (180 + angulo) % 360, (360 + angulo) % 360, colores[1], opciones[1]);
        setcolor(YELLOW);
        line(cx, cy - r - 10, cx, cy - r + 10);
        delay(100);
    }
    resultado = (angulo % 360 < 180) ? 0 : 1;
    cleardevice();
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(220, 200, "RESULTADO:");
    setcolor(colores[resultado]);
    outtextxy(250, 250, opciones[resultado]);
    if (resultado == 0) {
        outtextxy(240, 300, "GANASTE");
    } else {
        outtextxy(240, 300, "MORISTE");
    }
    outtextxy(160, 350, "Presiona ENTER para jugar o ESC para salir");
    getch();
}

void ruletaAnimada() {
    int cx, cy, radio, angulo, sector, i, resultado;
    char *textos[2] = {"VIDA", "MUERTE"};
    int colores[2] = {GREEN, RED};

    cx = getmaxx() / 2;
    cy = getmaxy() / 2;
    radio = 100;

    srand(time(NULL)); 

    for (i = 0; i < 30; i++) {
        cleardevice();

  
        setfillstyle(SOLID_FILL, colores[0]);
        pieslice(cx, cy, 0, 180, radio);

     
        setfillstyle(SOLID_FILL, colores[1]);
        pieslice(cx, cy, 180, 360, radio);

     
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(cx - 30, cy - 50, textos[0]);
        outtextxy(cx - 30, cy + 30, textos[1]);

        angulo = rand() % 360;
        resultado = (angulo >= 0 && angulo < 180) ? 0 : 1; 

        setcolor(YELLOW);
        fillellipse(cx + radio * cos(angulo * M_PI / 180),
                    cy + radio * sin(angulo * M_PI / 180), 10, 10);

        delay(500);
    }


    cleardevice();

    if (resultado == 1) {
        mostrarMuerte();
    }

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    setcolor(colores[resultado]);
    outtextxy(cx - 80, cy, resultado == 0 ? "¡GANASTE!" : "¡MORISTE!");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(cx - 160, cy + 50, "Presiona una tecla para continuar...");
    getch();
}
void mostrarMuerte() {
    cleardevice(); 
    dibujarCara();
    dibujarOjo();
    dibujarOjo2();
    dibujarCuerpo();
    dibujarBrazo();
    dibujarPistola1();
    dibujarMangoPistola();
    dibujarMangoDePistola3();
    dibujarMano2();
    dibujarGatillo();
    mostrarMensajeMuerte();
    getch(); 
}

void dibujarCara() {
    int puntosX[] = {
        317, 277, 244, 224, 215, 222, 238, 262,
        299, 333, 353, 380, 398, 413, 420, 417,
        406, 387, 358, 343, 326, 303
    };
    int puntosY[] = {
        57, 66, 78, 95, 135, 159, 185, 200,
        212, 210, 206, 180, 176, 158, 131, 102,
        81, 60, 54, 53, 57, 59
    };
    int n = sizeof(puntosX) / sizeof(puntosX[0]);
    int i;

    setcolor(WHITE);
    for (i = 0; i < n - 1; i++) {
        line(puntosX[i], puntosY[i], puntosX[i + 1], puntosY[i + 1]);
    }
    line(puntosX[n - 1], puntosY[n - 1], puntosX[0], puntosY[0]);

    setfillstyle(SOLID_FILL, WHITE);
    floodfill(300, 100, WHITE);  
}


void dibujarOjo() {
    int x[] = {299, 283, 269, 258, 256, 267, 281, 294, 306, 309, 304, 297};
    int y[] = {124, 124, 127, 132, 151, 157, 161, 158, 146, 134, 124, 124};
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    setcolor(BLACK);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    setfillstyle(SOLID_FILL, BLACK);
    floodfill(280, 140,BLACK); 
}
void dibujarOjo2() {
    int x[] = {336, 352, 365, 379, 380, 378, 372, 360, 345, 339, 333, 332, 339};
    int y[] = {120, 116, 118, 123, 133, 145, 150, 154, 151, 147, 136, 123, 119};
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    setcolor(BLACK);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    setfillstyle(SOLID_FILL, BLACK);
    floodfill(350, 130,BLACK);  
}
void dibujarCuerpo() {
    int x[] = {
        232, 227, 222, 216, 210, 199, 195, 210, 242,
        267, 283, 303, 342, 348, 335, 321, 334, 347,
        358, 363, 364, 350, 328, 364, 373, 368, 357,
        344, 323, 361, 366, 360, 346, 329, 324, 319,
        308, 294, 280, 227, 257, 272, 273, 392, 384,
        383, 361, 333, 312, 272, 254, 237, 231, 224
    };
    int y[] = {
        180, 187, 205, 229, 250, 274, 290, 306, 330,
        337, 348, 361, 364, 357, 348, 341, 346, 348,
        348, 338, 325, 319, 313, 322, 315, 302, 296,
        293, 299, 298, 293, 285, 284, 288, 292, 297,
        303, 320, 315, 285, 212, 263, 290, 293, 204,
        192, 208, 216, 214, 209, 199, 181, 181, 192
    };
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    setcolor(WHITE);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    setfillstyle(SOLID_FILL, WHITE);
    floodfill(300, 280, WHITE);

}
void dibujarPistola1() {
    int x[] = {475, 481, 497, 508, 506, 492, 428, 409, 393, 383, 377, 374, 472, 476, 482};
    int y[] = {54, 67, 72, 74, 88, 98, 127, 115, 126, 119, 112, 101, 53, 56, 67};
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    int cx = 0, cy = 0;

    setcolor(WHITE);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    for (i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
    }
    cx /= n;
    cy /= n;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(cx, cy, WHITE);
}

void dibujarMano2() {
    int x[] = {
        527, 538, 553, 568, 578, 575, 567, 559, 535, 521,
        513, 523, 536, 516, 512, 502, 499, 525, 484, 473,
        473, 492, 534, 525, 528, 541
    };
    int y[] = {
        75, 82, 89, 101, 125, 139, 130, 135, 150, 148,
        140, 134, 127, 135, 137, 130, 119, 110, 123, 115,
        112, 102, 87, 79, 74, 83
    };
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    int cx = 0, cy = 0;

    setcolor(WHITE);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    for (i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
    }
    cx /= n;
    cy /= n;

    setfillstyle(SOLID_FILL, WHITE);
    floodfill(cx, cy, WHITE);
}
void dibujarMangoPistola() {
    int x[] = {
        489, 509, 512, 519, 523, 529, 532, 510, 489, 505, 508
    };
    int y[] = {
        103, 89, 76, 67, 68, 88, 87, 95, 103, 89, 90
    };
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    int cx = 0, cy = 0;

    setcolor(RED);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    for (i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
    }
    cx /= n;
    cy /= n;

    setfillstyle(SOLID_FILL, RED);
    floodfill(cx, cy, RED);
}

void dibujarMangoDePistola3() {
    int x[] = {
        523, 526, 535, 582, 580, 567, 554, 531, 523, 525, 533
    };
    int y[] = {
        149, 166, 181, 164, 152, 129, 138, 148, 150, 157, 179
    };
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    int cx = 0, cy = 0;

    setcolor(RED);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    for (i = 0; i < n; i++) {
        cx += x[i];
        cy += y[i];
    }
    cx /= n;
    cy /= n;

    setfillstyle(SOLID_FILL, RED);
    floodfill(cx, cy, RED);
}

void dibujarGatillo() {
    int x[] = {
        450, 458, 468, 485, 501, 498, 490, 476, 467, 461, 451, 453, 463
    };
    int y[] = {
        121, 133, 140, 139, 132, 123, 126, 131, 137, 116, 119, 127, 136
    };
    int n = sizeof(x) / sizeof(x[0]);
    int i;

    setcolor(RED);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    setfillstyle(SOLID_FILL, RED);
   
}
void dibujarBrazo() {
int x[] = {398, 383, 386, 473, 529, 514, 462, 397, 387};
int y[] = {184, 193, 204, 229, 170, 144, 206, 185, 190};

    int n = sizeof(x) / sizeof(x[0]);
    int i;

    setcolor(WHITE);
    for (i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);

    setfillstyle(SOLID_FILL, WHITE);
 
}
void mostrarMensajeMuerte() {
    setcolor(RED);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
    outtextxy(180, 400, "HAS MUERTO");
}



int main() {
    int gd = DETECT, gm;
    int bx = 290, by_comenzar = 240, by_salir = 320;
    int bw = 120, bh = 40;
    int key;

    initgraph(&gd, &gm, "");

    dibujarFigura();
    dibujarSegundaFigura();
    mango();
    mago2();
    dibujarBoton(bx, by_comenzar, bw, bh, "COMENZAR");
    dibujarBoton(bx, by_salir, bw, bh, "SALIR");

    while (1) {
        if (kbhit()) {
            key = getch();
            if (key == 27) break;
            if (key == 13) {
                cleardevice();
                ruletaAnimada();
                cleardevice();
                dibujarFigura();
                dibujarSegundaFigura();
                mango();
                mago2();
                dibujarBoton(bx, by_comenzar, bw, bh, "COMENZAR");
                dibujarBoton(bx, by_salir, bw, bh, "SALIR");
            }
        }
    }

    closegraph();
    return 0;
}
