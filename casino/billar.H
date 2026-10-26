
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

union REGS reg_in, reg_out;

int mx, my, mb;

#define MAX_BOLAS 6
#define MAX_HOYOS 4

int click_x = 0, click_y = 0;
int release_x = 0, release_y = 0;
int clicked = 0;

struct Bola {
    int x, y;
    float dx, dy;
    int color;
};

struct Bola bolas[MAX_BOLAS];

struct Hoyo {
    int x, y;
    int radio;
};

struct Hoyo hoyos[MAX_HOYOS];


void initmouse() {
    reg_in.x.ax = 0;
    int86(0x33, &reg_in, &reg_out);
}

void showmouseptr() {
    reg_in.x.ax = 1;
    int86(0x33, &reg_in, &reg_out);
}

void hidemouseptr() {
    reg_in.x.ax = 2;
    int86(0x33, &reg_in, &reg_out);
}

void getmousepos(int *x, int *y, int *b) {
    reg_in.x.ax = 3;
    int86(0x33, &reg_in, &reg_out);
    *b = reg_out.x.bx;
    *x = reg_out.x.cx;
    *y = reg_out.x.dx;
}

void draw_table() {
    setfillstyle(SOLID_FILL, GREEN);
    bar(0, 0, getmaxx(), getmaxy());
    setcolor(BROWN);
    rectangle(50, 50, 590, 430);
}

void draw_ball(int x, int y, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(x, y, 8, 8);
}

void init_bolas() {
    bolas[0].x = 320; bolas[0].y = 240; bolas[0].dx = 0; bolas[0].dy = 0; bolas[0].color = WHITE;
    bolas[1].x = 400; bolas[1].y = 240; bolas[1].dx = 0; bolas[1].dy = 0; bolas[1].color = RED;
    bolas[2].x = 420; bolas[2].y = 250; bolas[2].dx = 0; bolas[2].dy = 0; bolas[2].color = YELLOW;
    bolas[3].x = 420; bolas[3].y = 230; bolas[3].dx = 0; bolas[3].dy = 0; bolas[3].color = BLUE;
    bolas[4].x = 440; bolas[4].y = 240; bolas[4].dx = 0; bolas[4].dy = 0; bolas[4].color = CYAN;
    bolas[5].x = 440; bolas[5].y = 260; bolas[5].dx = 0; bolas[5].dy = 0; bolas[5].color = MAGENTA;
}

void draw_hoyos() {
    int h;
    for ( h = 0; h < MAX_HOYOS; h++) {
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(hoyos[h].x, hoyos[h].y, hoyos[h].radio, hoyos[h].radio);
    }
}

void update_bolas() {
    int i, j, h;

    draw_table();
    draw_hoyos();

    for (i = 0; i < MAX_BOLAS; i++) {
        bolas[i].x += bolas[i].dx;
        bolas[i].y += bolas[i].dy;

        if (bolas[i].x <= 58 || bolas[i].x >= 582) bolas[i].dx = -bolas[i].dx;
        if (bolas[i].y <= 58 || bolas[i].y >= 422) bolas[i].dy = -bolas[i].dy;

        bolas[i].dx *= 0.98;
        bolas[i].dy *= 0.98;

        if (fabs(bolas[i].dx) < 0.2) bolas[i].dx = 0;
        if (fabs(bolas[i].dy) < 0.2) bolas[i].dy = 0;

        for (h = 0; h < MAX_HOYOS; h++) {
            float dx = bolas[i].x - hoyos[h].x;
            float dy = bolas[i].y - hoyos[h].y;
            float dist = sqrt(dx * dx + dy * dy);
            if (dist <= hoyos[h].radio) {
                if (i != 0) {
                    bolas[i].x = -100;
                    bolas[i].y = -100;
                    bolas[i].dx = 0;
                    bolas[i].dy = 0;
                    bolas[i].color = BLACK;
                } else {
                    bolas[i].dx = 0;
                    bolas[i].dy = 0;
                }
            }
        }
    }

    for (i = 0; i < MAX_BOLAS; i++) {
        for (j = i + 1; j < MAX_BOLAS; j++) {
            float dx = bolas[j].x - bolas[i].x;
            float dy = bolas[j].y - bolas[i].y;
            float dist = sqrt(dx * dx + dy * dy);
            if (dist <= 16 && dist > 0) {
                float nx = dx / dist;
                float ny = dy / dist;

                float p = 2 * (bolas[i].dx * nx + bolas[i].dy * ny - bolas[j].dx * nx - bolas[j].dy * ny) / 2;

                bolas[i].dx = bolas[i].dx - p * nx;
                bolas[i].dy = bolas[i].dy - p * ny;
                bolas[j].dx = bolas[j].dx + p * nx;
                bolas[j].dy = bolas[j].dy + p * ny;
            }
        }
    }

    for (i = 0; i < MAX_BOLAS; i++) {
        draw_ball(bolas[i].x, bolas[i].y, bolas[i].color);
    }
}

void iniciarJuegoBillar() 
{
    int gd = DETECT, gm;
    int h;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    initmouse();
    showmouseptr();

    hoyos[0].x = 70;  hoyos[0].y = 70;
    hoyos[1].x = 570; hoyos[1].y = 70;
    hoyos[2].x = 70;  hoyos[2].y = 410;
    hoyos[3].x = 570; hoyos[3].y = 410;
    for (h = 0; h < MAX_HOYOS; h++) hoyos[h].radio = 12;

    init_bolas();

    while (!kbhit()) 
    {
        getmousepos(&mx, &my, &mb);

        if ((mb & 1) && !clicked) 
        {
            clicked = 1;
            click_x = mx;
            click_y = my;
        }

        if (!(mb & 1) && clicked) 
        {
            release_x = mx;
            release_y = my;

            bolas[0].dx = (click_x - release_x) / 5.0;
            bolas[0].dy = (click_y - release_y) / 5.0;

            clicked = 0;
        }

        update_bolas();
        delay(20);  
        }

}


