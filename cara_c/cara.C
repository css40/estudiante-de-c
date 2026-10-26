#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <time.h>

#define NUM_PUNTOS_BOCA 17
#define NUM_PUNTOS_LINEA1 6
#define NUM_PUNTOS_LINEA2 7
#define AMPLITUD_DESPLAZAMIENTO 10 
#define PASO 5
#define VELOCIDAD_ANIMACION 5
#define NUM_PUNTOS 43 
#define NUM_PUNTOS_CEJA1 14
#define NUM_PUNTOS_CEJA2 10 
#define NUM_PUNTOS_NARIZ 16 
#define NUM_PUNTOS_BOCA 17
#define NUM_PUNTOS_LINEA1 6
#define NUM_PUNTOS_OJO1 13
#define NUM_PUNTOS_OJO2 13
#define AMPLITUD 5
#define RETARDO 100
#define NUM_PUNTOS_LINEA2 7
#define NUM_PUNTOS_NARIZ1 4
#define NUM_PUNTOS_NARIZ2 5
#define NUM_PUNTOS_NARIZ3 8
#define NUM_PUNTOS_BARBA2 26 
#define NUM_PUNTOS_BARBA 30
#define NUM_PUNTOS_LINEABOCA2 3  
#define NUM_PUNTOS_LINEABOCA 3 


void cara();
void ceja1();
void ceja2();
void nariz();
void borrarZonaOjos();

int desplazamiento_ceja = 0;
int direccion_ceja = 1;
int pupila_dx = 0;
int direccion_pupila = 1;


int puntos_pelo[][2] = {
    {422, 333}, {441, 322}, {452, 314}, {446, 309}, {446, 298}, {457, 290},
    {463, 294}, {459, 282}, {460, 275}, {474, 268}, {480, 255}, {490, 255},
    {481, 252}, {480, 244}, {475, 239}, {481, 230}, {495, 237}, {493, 219},
    {503, 207}, {488, 196}, {505, 191}, {500, 168}, {517, 152}, {511, 156},
    {500, 139}, {495, 135}, {510, 123}, {495, 124}, {503, 112}, {487, 108},
    {492, 98}, {491, 79}, {500, 71}, {487, 53}, {488, 69}, {480, 77},
    {461, 68}, {471, 48}, {470, 35}, {435, 30}, {453, 15}, {436, 11},
    {434, 0}, {179, 0}, {160, 2}, {168, 13}, {157, 14}, {147, 9}, {145, 26},
    {143, 32}, {120, 32}, {109, 49}, {119, 71}, {96, 70}, {107, 86},
    {99, 94}, {96, 114}, {104, 119}, {102, 121}, {92, 125}, {106, 138},
    {79, 160}, {76, 170}, {115, 176}, {97, 190}, {74, 204}, {88, 218},
    {100, 231}, {90, 245}, {108, 254}, {105, 241}, {114, 258}, {121, 272},
    {133, 285}, {132, 294}, {142, 303}, {160, 318}, {156, 330}, {166, 336},
    {178, 348}, {186, 347}, {175, 271}, {150, 253}, {147, 241}, {139, 203},
    {141, 184}, {153, 176}, {155, 176}, {170, 191}, {196, 235}, {200, 235},
    {192, 221}, {195, 218}, {188, 189}, {194, 166}, {207, 155}, {219, 149},
    {223, 133}, {228, 125}, {241, 145}, {253, 139}, {250, 128}, {262, 141},
    {280, 150}, {275, 160}, {299, 158}, {313, 145}, {307, 158}, {335, 152},
    {354, 135}, {361, 144}, {365, 149}, {378, 152}, {389, 163}, {400, 173},
    {410, 190}, {415, 210}, {421, 209}, {418, 226}, {429, 220}, {430, 191},
    {441, 181}, {459, 183}, {466, 202}, {460, 228}, {447, 251}, {432, 268},
    {422, 332}
};


void cara() {
    int i;
    int puntos[NUM_PUNTOS][2] = {
        {296, 22}, {323, 20}, {360, 31}, {389, 48},
        {411, 64}, {423, 88}, {431, 117}, {433, 152},
        {430, 191}, {444, 180}, {459, 181}, {467, 200},
        {462, 218}, {459, 230}, {448, 252}, {431, 270},
        {422, 334}, {414, 361}, {390, 389}, {346, 422},
        {300, 430}, {261, 422}, {223, 395}, {187, 364},
        {180, 329}, {179, 301}, {175, 269}, {164, 262},
        {151, 251}, {144, 234}, {139, 211}, {141, 185},
        {155, 177}, {170, 191}, {172, 171}, {174, 116},
        {183, 88}, {192, 65}, {213, 47}, {239, 32},
        {268, 24}, {296, 21}, {307, 21}
    };

    for (i = 0; i < NUM_PUNTOS - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }

    line(puntos[NUM_PUNTOS - 1][0], puntos[NUM_PUNTOS - 1][1], puntos[0][0], puntos[0][1]);
}



void barba2() {
    int puntos_barba2[NUM_PUNTOS_BARBA2][2] = {
        {301, 326}, {268, 335}, {251, 342}, {242, 342},
        {235, 352}, {231, 363}, {239, 369}, {251, 380},
        {256, 377}, {267, 382}, {280, 385}, {291, 389},
        {302, 392}, {317, 386}, {326, 385}, {336, 387},
        {354, 368}, {360, 364}, {357, 352}, {351, 338},
        {332, 335}, {300, 326}, {280, 331}, {301, 326}, 
        {300, 326}, {280, 331} 
    };


    

    int i;
    setcolor(BROWN); 
    for (i = 0; i < NUM_PUNTOS_BARBA2 - 1; i++) {
        line(puntos_barba2[i][0], puntos_barba2[i][1],
             puntos_barba2[i + 1][0], puntos_barba2[i + 1][1]);
    }

    line(puntos_barba2[NUM_PUNTOS_BARBA2 - 1][0], puntos_barba2[NUM_PUNTOS_BARBA2 - 1][1],
         puntos_barba2[0][0], puntos_barba2[0][1]);
}

void linea_nariz3() {
    int puntos_nariz3[NUM_PUNTOS_NARIZ3][2] = {
        {269, 307},
        {276, 301},
        {289, 305},
        {299, 314},
        {311, 310},
        {321, 302},
        {333, 311},
        {334, 308}
    };

    int i;
    for (i = 0; i < NUM_PUNTOS_NARIZ3 - 1; i++) {
        line(puntos_nariz3[i][0], puntos_nariz3[i][1], puntos_nariz3[i + 1][0], puntos_nariz3[i + 1][1]);
    }
}
void linea_nariz2() {
    int puntos_nariz2[NUM_PUNTOS_NARIZ2][2] = {
        {315, 270},
        {322, 282},
        {331, 289},
        {337, 298},
        {333, 312}
    };

    int i;
    for (i = 0; i < NUM_PUNTOS_NARIZ2 - 1; i++) {
        line(puntos_nariz2[i][0], puntos_nariz2[i][1], puntos_nariz2[i + 1][0], puntos_nariz2[i + 1][1]);
    }
}
void linea_nariz1() {
    int puntos_nariz1[NUM_PUNTOS_NARIZ1][2] = {
        {287, 270},
        {281, 281},
        {269, 289},
        {268, 307}
    };

    int i;
    for (i = 0; i < NUM_PUNTOS_NARIZ1 - 1; i++) {
        line(puntos_nariz1[i][0], puntos_nariz1[i][1], puntos_nariz1[i + 1][0], puntos_nariz1[i + 1][1]);
    }
}

#define NUM_PUNTOS_CEJA1 8

void ceja1() {
    int i;
    int puntos_ceja1[NUM_PUNTOS_CEJA1][2] = {
        {407, 198},
        {367, 179},
        {325, 202},
        {310, 206},
        {327, 209},
        {358, 195},
        {387, 193},
        {406, 198}
    };

    for (i = 0; i < NUM_PUNTOS_CEJA1 - 1; i++) {
        line(puntos_ceja1[i][0], puntos_ceja1[i][1], puntos_ceja1[i + 1][0], puntos_ceja1[i + 1][1]);
    }

    line(puntos_ceja1[NUM_PUNTOS_CEJA1 - 1][0], puntos_ceja1[NUM_PUNTOS_CEJA1 - 1][1], puntos_ceja1[0][0], puntos_ceja1[0][1]);
    setfillstyle(SOLID_FILL, BROWN);
    
}


void ceja2(int desplazamiento, int color) {
    int puntos_ceja2[NUM_PUNTOS_CEJA2][2] = {
        {291, 195}, {266, 192}, {254, 189}, {223, 178},  
        {196, 192}, {210, 188}, {230, 193}, {270, 201},
        {290, 195}, {272, 194}
    };

    int i;
    setcolor(color);

 
    for (i = 0; i < NUM_PUNTOS_CEJA2; i++) {
        puntos_ceja2[i][1] += desplazamiento;
    }

    for (i = 0; i < NUM_PUNTOS_CEJA2 - 1; i++) {
        line(puntos_ceja2[i][0], puntos_ceja2[i][1], puntos_ceja2[i + 1][0], puntos_ceja2[i + 1][1]);
    }

    line(puntos_ceja2[NUM_PUNTOS_CEJA2 - 1][0], puntos_ceja2[NUM_PUNTOS_CEJA2 - 1][1], puntos_ceja2[0][0], puntos_ceja2[0][1]);
}



void ojo1(int pupila_dx) {
    int i;
    int puntos_ojo1[NUM_PUNTOS_OJO1][2] = {
        {270, 218}, {261, 212}, {249, 207}, {235, 203}, {222, 207},
        {212, 218}, {214, 226}, {225, 231}, {236, 233}, {250, 230},
        {260, 225}, {270, 218}, {266, 213}
    };

    setcolor(WHITE);
    for (i = 0; i < NUM_PUNTOS_OJO1 - 1; i++) {
        line(puntos_ojo1[i][0], puntos_ojo1[i][1], puntos_ojo1[i + 1][0], puntos_ojo1[i + 1][1]);
    }
    line(puntos_ojo1[NUM_PUNTOS_OJO1 - 1][0], puntos_ojo1[NUM_PUNTOS_OJO1 - 1][1],
         puntos_ojo1[0][0], puntos_ojo1[0][1]);

    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(242 + pupila_dx, 220,11, 11);

    setfillstyle(SOLID_FILL, DARKGRAY);
    fillellipse(242 + pupila_dx, 220, 6, 6);
}

void ojo2(int pupila_dx) {
    int i;
    int puntos_ojo2[NUM_PUNTOS_OJO2][2] = {
        {333, 216}, {343, 213}, {354, 205}, {367, 204}, {380, 208},
        {387, 213}, {394, 219}, {387, 227}, {372, 230}, {358, 232},
        {346, 229}, {338, 222}, {334, 215}
    };

    setcolor(WHITE);
    for (i = 0; i < NUM_PUNTOS_OJO2 - 1; i++) {
        line(puntos_ojo2[i][0], puntos_ojo2[i][1], puntos_ojo2[i + 1][0], puntos_ojo2[i + 1][1]);
    }
    line(puntos_ojo2[NUM_PUNTOS_OJO2 - 1][0], puntos_ojo2[NUM_PUNTOS_OJO2 - 1][1],
         puntos_ojo2[0][0], puntos_ojo2[0][1]);

    setfillstyle(SOLID_FILL, BROWN);
    fillellipse(361 + pupila_dx, 220, 11, 11);

    setfillstyle(SOLID_FILL, DARKGRAY);
    fillellipse(361 + pupila_dx, 220, 6, 6);
}
/*void moverOjos() {
    int pupila_dx = 0;
    int direccion = 1;
    int tiempo_inicio = clock();

    while ((clock() - tiempo_inicio) < 50) {
        borrarZonaOjos();  

        ojo1(pupila_dx);
        ojo2(pupila_dx);

        pupila_dx += direccion;
        if (pupila_dx > 5 || pupila_dx < -5) {
            direccion *= -1;
        }

        delay(50);
    }
}*/

void cerrarOjos() {
    borrarZonaOjos();  

   
    setcolor(WHITE);
    line(222, 220, 260, 220);  
    line(343, 220, 380, 220);  

    
}


/*void animarOjos() {
    int pupila_dx = 0;
    int dir = 1;
    int tiempo_animacion = 0;

    while (tiempo_animacion < 50) {
        borrarZonaOjos(); 
        moverOjos();   
        ojo1(pupila_dx); 
        ojo2(pupila_dx); 

        pupila_dx += dir;

        if (pupila_dx >= AMPLITUD || pupila_dx <= -AMPLITUD) {
            dir *= -1;
        }

        tiempo_animacion += RETARDO;
        delay(RETARDO);  
    }

    cerrarOjos();
    borrarZonaOjos();
    delay(3000); 
}*/

void borrarZonaOjos() {

    setcolor(BLACK); 


    ellipse(242, 220, 0, 360, 12, 12);  


    ellipse(361, 220, 0, 360, 12, 12);  
}



void cuellolinea2() {
    int puntos[][2] = {
        {405, 371}, {414, 401}, {430, 434}, {446, 453},
        {457, 469}, {463, 478}, {441, 476}
    };
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;
    
    for (i = 0; i < n - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}
void cuellolinea1() {
    int puntos[][2] = {
        {196, 371}, {183, 414}, {165, 438}, {154, 450},
        {144, 460}, {134, 472}, {133, 479}, {407, 477},
        {439, 476}, {443, 476}
    };
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;

    for (i = 0; i < n - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}
void abrirOjos() {
    borrarZonaOjos();
    ojo1(pupila_dx);
    ojo2(pupila_dx);
}



/*void animar_ceja() {
    int desplazamiento = 0;
    int direccion = 1;

    while (!kbhit()) {
        ceja2(desplazamiento, BLACK);

        desplazamiento += direccion * PASO;

        if (desplazamiento >= AMPLITUD_DESPLAZAMIENTO || desplazamiento <= -AMPLITUD_DESPLAZAMIENTO) {
            direccion *= -1;
        }
        ceja2(desplazamiento, WHITE); 

        delay(VELOCIDAD_ANIMACION);
    }
}*/

void detalle_oreja() {
    int puntos[][2] = {
        {436, 200}, {445, 196}, {453, 196}, {453, 206},
        {452, 218}, {449, 226}, {441, 241}, {437, 247}
    };
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;

    for (i = 0; i < n - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}

void detalle_oreja2() {
    int puntos[][2] = {
        {434, 215}, {439, 215}, {440, 221}, {438, 226},
        {434, 232}, {432, 235}, {433, 245}
    };
    int n = sizeof(puntos) / sizeof(puntos[0]);
    int i;

    for (i = 0; i < n - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}


void dibujar_pelo() {
    int total = sizeof(puntos_pelo) / sizeof(puntos_pelo[0]);
    int i;
    setcolor(BROWN);
    for (i = 0; i < total - 1; i++) {
        line(puntos_pelo[i][0], puntos_pelo[i][1], puntos_pelo[i + 1][0], puntos_pelo[i + 1][1]);
    }
    line(puntos_pelo[total - 1][0], puntos_pelo[total - 1][1], puntos_pelo[0][0], puntos_pelo[0][1]);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(300, 150, BROWN);
}

void dibujar_barba() {
    int puntos_barba[NUM_PUNTOS_BARBA][2] = {
        {426, 242}, {434, 265}, {423, 328}, {416, 359}, {392, 387},
        {348, 423}, {308, 429}, {260, 424}, {186, 362}, {176, 270},
        {185, 277}, {189, 291}, {201, 307}, {213, 322}, {214, 334},
        {241, 343}, {232, 363}, {250, 378}, {256, 377}, {300, 391},
        {320, 384}, {334, 388}, {361, 364}, {350, 338}, {390, 319},
        {417, 290}, {416, 257}, {426, 240}, {434, 265}, {432, 278}
    };

    setcolor(BROWN);                  
    setfillstyle(SOLID_FILL, BROWN); 
    fillpoly(NUM_PUNTOS_BARBA, (int *)puntos_barba); 
}


void lineaBoca() {
    int i;
    int puntos_lineaboca[NUM_PUNTOS_LINEABOCA][2] = {
        {266, 360}, {284, 358}, {293, 359}
    };



    for (i = 0; i < NUM_PUNTOS_LINEABOCA - 1; i++) {
        line(puntos_lineaboca[i][0], puntos_lineaboca[i][1],
             puntos_lineaboca[i + 1][0], puntos_lineaboca[i + 1][1]);
    }
}


void lineaBoca2() {
    int i;
    int puntos_lineaboca2[NUM_PUNTOS_LINEABOCA2][2] = {
        {334, 358}, {325, 358}, {314, 360}
    };

    

    for (i = 0; i < NUM_PUNTOS_LINEABOCA2 - 1; i++) {
        line(puntos_lineaboca2[i][0], puntos_lineaboca2[i][1],
             puntos_lineaboca2[i + 1][0], puntos_lineaboca2[i + 1][1]);
    }
}

void animarTodo() {
    int estado_ojos = 1;
    static int ciclo = 0;

    while (!kbhit()) {
        ciclo++;

        if (ciclo % 8 == 0) {
            ceja2(desplazamiento_ceja, BLACK);
            desplazamiento_ceja += direccion_ceja * PASO;
            if (desplazamiento_ceja >= AMPLITUD_DESPLAZAMIENTO || desplazamiento_ceja <= -AMPLITUD_DESPLAZAMIENTO) {
                direccion_ceja *= -1;
            }
            ceja2(desplazamiento_ceja, WHITE);
        }

        if (ciclo % 3 == 0) {
            borrarZonaOjos();
            ojo1(pupila_dx);
            ojo2(pupila_dx);

            pupila_dx += direccion_pupila;
            if (pupila_dx >= AMPLITUD || pupila_dx <= -AMPLITUD) {
                direccion_pupila *= -1;
            }
        }

        if (ciclo % 10 == 0) {
            if (estado_ojos == 1) {
                cerrarOjos();
                estado_ojos = 0;
            } else {
                abrirOjos();
                estado_ojos = 1;
            }
        }

        if (ciclo >= 1000) {
            ciclo = 0;
        }

        delay(1);
    }
}


/*bocas animacion*/

void boca1() {
    int puntos_boca[16][2] = {
        {253, 350}, {277, 348}, {293, 346}, {305, 346}, {315, 345},
        {328, 347}, {347, 343}, {335, 357}, {332, 367}, {325, 371},
        {304, 374}, {285, 374}, {274, 369}, {264, 360}, {254, 351},
        {253, 350}
    };

    int puntos_linea1[6][2] = {
        {425, 240},
        {419, 257},
        {416, 290},
        {404, 305},
        {391, 318},
        {386, 364}
    };

    int puntos_linea2[7][2] = {
        {177, 240},
        {185, 260},
        {184, 281},
        {191, 296},
        {209, 315},
        {214, 331},
        {218, 363}
    };

    int i;
    
    setcolor(15);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillpoly(16, (int (*)[2])puntos_boca);
    for (i = 0; i < 15; i++) {
        line(puntos_boca[i][0], puntos_boca[i][1], puntos_boca[i+1][0], puntos_boca[i+1][1]);
    }

    for (i = 0; i < 5; i++) {
        line(puntos_linea1[i][0], puntos_linea1[i][1], puntos_linea1[i+1][0], puntos_linea1[i+1][1]);
    }

    for (i = 0; i < 6; i++) {
        line(puntos_linea2[i][0], puntos_linea2[i][1], puntos_linea2[i+1][0], puntos_linea2[i+1][1]);
    }
}

void boca2() {
    int boca[11][2] = {
        {346, 342}, {328, 346}, {298, 349}, {260, 342}, {260, 356},
        {271, 376}, {292, 387}, {314, 387}, {335, 375}, {346, 343},
        {323, 346}
    };

    int dientes1[11][2] = {
        {266, 343}, {267, 353}, {272, 353}, {274, 359}, {281, 356},
        {325, 354}, {329, 358}, {339, 354}, {342, 344}, {266, 342},
        {266, 347}
    };

    int dientes2[17][2] = {
        {334, 375}, {330, 367}, {321, 368}, {322, 373}, {314, 375},
        {299, 377}, {285, 376}, {278, 370}, {280, 366}, {274, 364},
        {269, 368}, {278, 380}, {291, 386}, {303, 387}, {317, 386},
        {333, 376}, {334, 373}
    };

    int i;
    
    setcolor(15);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillpoly(11, (int (*)[2])boca);
    for (i = 0; i < 10; i++) {
        line(boca[i][0], boca[i][1], boca[i+1][0], boca[i+1][1]);
    }

    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(11, (int (*)[2])dientes1);
    for (i = 0; i < 10; i++) {
        line(dientes1[i][0], dientes1[i][1], dientes1[i+1][0], dientes1[i+1][1]);
    }

    fillpoly(17, (int*)dientes2);
    for (i = 0; i < 16; i++) {
        line(dientes2[i][0], dientes2[i][1], dientes2[i + 1][0], dientes2[i + 1][1]);
    }
 
    line(dientes2[16][0], dientes2[16][1], dientes2[0][0], dientes2[0][1]);
    
}

void boca3() {
    int boca[10][2] = {
        {254, 347}, {266, 343}, {330, 345}, {343, 338}, {336, 361},
        {306, 383}, {281, 376}, {261, 358}, {255, 348}, {263, 344}
    };

    int dientes[7][2] = {
        {264, 345}, {268, 356}, {339, 348}, {343, 337}, {328, 341},
        {265, 344}, {265, 348}
    };

    int otrosDientes[6][2] = {
        {324, 369}, {278, 374}, {304, 385}, {325, 370}, {317, 369},
        {311, 371}
    };

    int lengua[7][2] = {
        {331, 367}, {307, 363}, {292, 364}, {279, 369}, {276, 373},
        {322, 369}, {330, 366}
    };

    int i;

    setcolor(15);
    setfillstyle(SOLID_FILL, LIGHTRED);
    fillpoly(10, (int (*)[2])boca);
    for (i = 0; i < 9; i++) {
        line(boca[i][0], boca[i][1], boca[i+1][0], boca[i+1][1]);
    }

    setcolor(15);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(7, (int (*)[2])dientes);
    for (i = 0; i < 6; i++) {
        line(dientes[i][0], dientes[i][1], dientes[i+1][0], dientes[i+1][1]);
    }

    setcolor(15);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(6, (int (*)[2])otrosDientes);
    for (i = 0; i < 5; i++) {
        line(otrosDientes[i][0], otrosDientes[i][1], otrosDientes[i+1][0], otrosDientes[i+1][1]);
    }

    setcolor(15);
    setfillstyle(SOLID_FILL, RED);
    fillpoly(7, (int (*)[2])lengua);
    for (i = 0; i < 6; i++) {
        line(lengua[i][0], lengua[i][1], lengua[i+1][0], lengua[i+1][1]);
    }
}

#define NUM_PUNTOS_CAMISA1 11

void camisa1() {
    int puntos_camisa1[NUM_PUNTOS_CAMISA1][2] = {
        {164, 390}, {266, 442}, {280, 479}, {111, 479},
        {142, 394}, {165, 377}, {183, 384}, {191, 387},
        {187, 400}, {165, 391}, {150, 389}
    };

    int x[NUM_PUNTOS_CAMISA1];
    int y[NUM_PUNTOS_CAMISA1];
    int i;

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    for (i = 0; i < NUM_PUNTOS_CAMISA1; i++) {
        x[i] = puntos_camisa1[i][0];
        y[i] = puntos_camisa1[i][1];
    }

    fillpoly(NUM_PUNTOS_CAMISA1, (int *)puntos_camisa1);
}

#define NUM_PUNTOS_CAMISA2 11

void camisa2() {
    int puntos_camisa2[NUM_PUNTOS_CAMISA2][2] = {
        {288, 479}, {303, 443}, {413, 393}, {432, 379},
        {408, 378}, {411, 393}, {431, 380}, {473, 451},
        {492, 477}, {287, 478}, {303, 443}
    };

    int x[NUM_PUNTOS_CAMISA2];
    int y[NUM_PUNTOS_CAMISA2];
    int i;

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    for (i = 0; i < NUM_PUNTOS_CAMISA2; i++) {
        x[i] = puntos_camisa2[i][0];
        y[i] = puntos_camisa2[i][1];
    }

    fillpoly(NUM_PUNTOS_CAMISA2, (int *)puntos_camisa2);
}
#define NUM_PUNTOS_MANGA1 6

void manga1() {
    int puntos_manga1[NUM_PUNTOS_MANGA1][2] = {
        {473, 449}, {564, 452}, {603, 479},
        {494, 479}, {472, 449}, {490, 450}
    };

    int x[NUM_PUNTOS_MANGA1];
    int y[NUM_PUNTOS_MANGA1];
    int i;

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    for (i = 0; i < NUM_PUNTOS_MANGA1; i++) {
        x[i] = puntos_manga1[i][0];
        y[i] = puntos_manga1[i][1];
    }

    fillpoly(NUM_PUNTOS_MANGA1, (int *)puntos_manga1);
}

#define NUM_PUNTOS_MANGA2 6

void manga2() {
    int puntos_manga2[NUM_PUNTOS_MANGA2][2] = {
        {122, 450}, {22, 454}, {1, 479},
        {112, 479}, {121, 450}, {98, 450}
    };

    int x[NUM_PUNTOS_MANGA2];
    int y[NUM_PUNTOS_MANGA2];
    int i;

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    for (i = 0; i < NUM_PUNTOS_MANGA2; i++) {
        x[i] = puntos_manga2[i][0];
        y[i] = puntos_manga2[i][1];
    }

    fillpoly(NUM_PUNTOS_MANGA2, (int *)puntos_manga2);
}
#define NUM_PUNTOS_DETALLE_ORE 7

void detalleOre() {
    int puntos[NUM_PUNTOS_DETALLE_ORE][2] = {
        {165, 198}, {150, 196}, {147, 210}, {153, 225},
        {155, 235}, {158, 242}, {164, 249}
    };

    int i;
    setcolor(WHITE);
    for (i = 0; i < NUM_PUNTOS_DETALLE_ORE - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}

#define NUM_PUNTOS_DETALLE_ORE2 8

void detalleOre2() {
    int puntos[NUM_PUNTOS_DETALLE_ORE2][2] = {
        {169, 219}, {165, 219}, {163, 222}, {164, 230},
        {166, 236}, {170, 239}, {172, 239}, {174, 248}
    };

    int i;
    setcolor(WHITE);
    for (i = 0; i < NUM_PUNTOS_DETALLE_ORE2 - 1; i++) {
        line(puntos[i][0], puntos[i][1], puntos[i + 1][0], puntos[i + 1][1]);
    }
}



void cambiarBocaCada3Segundos() {
    int bocaActual = 2;

    while (1) { 
        cleardevice();

        cara();
        ceja1();
        linea_nariz1();
        linea_nariz2();
        linea_nariz3();
        cuellolinea2();
        cuellolinea1();
        detalle_oreja();
        detalle_oreja2();
        detalleOre2();
        detalleOre();
        camisa1();
        camisa2();
        manga1();
        manga2();
        lineaBoca();
        lineaBoca2();

        if (kbhit()) {  
            char tecla = getch();  

            if (tecla == 13) { 
                bocaActual = (bocaActual % 3) + 1;  
            }
            if (tecla == 27) {
                break;
            }
        }

        if (bocaActual == 1) {
            boca1();
        } else if (bocaActual == 2) {
            boca2();
        } else if (bocaActual == 3) {
            boca3();
        }

        barba2();
        dibujar_barba();
        dibujar_pelo();

        animarTodo();  
        if (kbhit()) {
            char tecla = getch();
            if (tecla == 27) {
                break; 
            }
        }


        delay(100);  
    }
}
int main() {
    int gd = DETECT, gm;
    int dir = 1;
    int pupila_dx = 0;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    cleardevice();
    
    cambiarBocaCada3Segundos() ; 

   
    closegraph();
    return 0;
}