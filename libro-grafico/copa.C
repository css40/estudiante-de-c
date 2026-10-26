#include <graphics.h>
#include <conio.h>
void copa(int offsetX, int offsetY, int color) {
    int puntos[][2] = {
        {204, 39}, {395, 39}, {398, 48}, {399, 71}, {398, 97},
        {395, 128}, {385, 162}, {376, 181}, {356, 209},
        {314, 234}, {294, 237}, {272, 229}, {247, 210},
        {219, 168}, {207, 124}, {203, 66}, {204, 39}, {217, 39}
    };
    int n = 18;
    int i;
    int polyPoints[2 * 18];
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = 25;
    int i;
    int polyPoints[2 * 25];
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = 21;
    int i;
    int polyPoints[2 * 21];  
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = 24;
    int i;
    int polyPoints[2 * 24];
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = 6;
    int i;
    int polyPoints[2 * 6];
    for (i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;
    int polyPoints[2 * 12];
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
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
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;
    int polyPoints[2 * 19];
    for ( i = 0; i < n; i++) {
        polyPoints[2 * i]     = puntos[i][0] + offsetX;
        polyPoints[2 * i + 1] = puntos[i][1] + offsetY;
    }
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(n, polyPoints);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cleardevice();
    setbkcolor(BLACK);
    copa(0, 0, YELLOW); 
    oreja1(0, 0, YELLOW);
    oreja2(0, 0, YELLOW);
    baseCopa(0, 0, YELLOW);
    cajaBase(0, 0);
    estrella(0, 0);
    destello(0, 0);
    getch();
    closegraph();
    return 0;
}
