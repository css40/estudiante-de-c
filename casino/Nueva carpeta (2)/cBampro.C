#include <graphics.h>
#include <conio.h>

void drawSun() {
    setcolor(YELLOW);             
    setfillstyle(SOLID_FILL, YELLOW); 
    fillellipse(50, 50, 30, 30); 
}

void drawCloud(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    

    fillellipse(x, y, 25, 15);   
    fillellipse(x - 20, y + 5, 20, 15);
    fillellipse(x + 20, y + 5, 20, 15); 
}

void drawGrass() {
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    
  
    fillellipse(50, 400, 40, 30);
    fillellipse(90, 410, 50, 35);
    fillellipse(130, 400, 40, 30);
    
  
    fillellipse(550, 400, 40, 30);
    fillellipse(590, 410, 50, 35);
    fillellipse(630, 400, 40, 30);
}

void drawPolygon1() {
    int points1[] = {192, 171, 416, 29, 417, 88, 215, 198, 192, 171};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points1);
}

void drawPolygon2() {
    int points2[] = {417, 30, 638, 165, 637, 199, 417, 88, 417, 31};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points2);
}

void drawPolygon3() {
    int points3[] = {501, 150, 530, 408, 429, 412, 411, 113, 501, 148};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points3);
}

void drawPolygon4() {
    int points4[] = {411, 113, 323, 154, 327, 409, 429, 411, 411, 115};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points4);
}

void drawPolygon5() {
    int points5[] = {215, 198, 239, 205, 411, 112, 636, 217, 636, 198, 416, 88, 215, 197};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(7, points5);
}

void drawPolygon6() {
    int points6[] = {349, 71, 298, 45, 71, 195, 73, 214, 295, 65, 332, 81, 349, 70};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(7, points6);
}

void drawPolygon7() {
    int points7[] = {73, 214, 106, 212, 299, 82, 320, 90, 331, 81, 295, 65, 73, 214};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(7, points7);
}

void drawPolygon8() {
    int points8[] = {223, 151, 210, 147, 156, 186, 161, 248, 224, 218, 223, 200, 217, 201, 192, 171, 223, 151};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(9, points8);
}

void drawPolygon9() {
    int points9[] = {482, 227, 534, 209, 537, 228, 509, 241, 483, 227};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points9);
}

void drawPolygon10() {
    int points10[] = {533, 210, 637, 243, 636, 259, 537, 227, 533, 211};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points10);
}

void drawPolygon11() {
    int points11[] = {511, 243, 636, 271, 636, 258, 537, 228, 510, 242};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points11);
}

void drawPolygon12() {
    int points12[] = {214, 339, 101, 324, 57, 342, 67, 346, 97, 334, 212, 355, 215, 336};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(7, points12);
}

void drawPolygon13() {
    int points13[] = {68, 347, 177, 369, 211, 355, 98, 335, 67, 347};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points13);
}

void drawPolygon14() {
    int points14[] = {255, 205, 346, 228, 348, 242, 262, 221, 255, 205};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points14);
}

void drawPolygon15() {
    int points15[] = {255, 205, 14, 319, 31, 326, 262, 222, 255, 206};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points15);
}

void drawPolygon16() {
    int points16[] = {348, 243, 98, 325, 30, 327, 263, 222, 348, 242};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points16);
}

void drawPolygon17() {
    int points17[] = {77, 349, 75, 407, 430, 411, 427, 382, 76, 394};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points17);
}

void drawPolygon18() {
    int points18[] = {427, 382, 528, 380, 530, 407, 430, 412, 427, 380};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points18);
}

void drawPolygon19() {
    int points19[] = {129, 217, 35, 272, 55, 288, 142, 234, 129, 216};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points19);
}

void drawPolygon20() {
    int points20[] = {130, 218, 159, 220, 159, 235, 140, 233, 129, 218};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 7);
    fillpoly(5, points20);
}

void drawPolygon21() {
    int points21[] = {55, 287, 93, 283, 160, 242, 159, 235, 140, 233, 54, 287};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(6, points21);
}

void drawPolygon22() {
    int points22[] = {531, 408, 638, 404, 636, 218, 502, 156, 509, 217, 533, 210, 635, 242, 637, 272, 511, 244, 532, 410};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(10, points22);
}

void drawPolygon23() {
    int points23[] = {239, 205, 241, 214, 256, 206, 259, 195, 239, 204};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points23);
}

void drawPolygon24() {
    int points24[] = {289, 179, 291, 213, 257, 205, 259, 193, 289, 180};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points24);
}

void drawPolygon25() {
    int points25[] = {289, 178, 324, 161, 323, 210, 293, 214, 289, 178};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points25);
}

void drawPolygon26() {
    int points26[] = {222, 283, 215, 388, 267, 387, 269, 270, 222, 284};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points26);
}

void drawPolygon27() {
    int points27[] = {302, 258, 298, 387, 266, 386, 269, 269, 302, 258};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points27);
}
void drawPolygon28() {
    int points28[] = {218, 334, 325, 303};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points28);
}
void drawPolygon29() {
    int points29[] = {215, 368, 327, 350};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points29);
}
void drawPolygon30() {
    int points30[] = {220, 302, 326, 269};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(2, points30);
}
void drawPolygon31() {
    int points31[] = {294, 257, 227, 238, 252, 390, 240, 388, 215, 243, 247, 229, 318, 251, 297, 260, 293, 257};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(9, points31);
}
void drawPolygon32() {
    int points32[] = {220, 282, 160, 268, 177, 390, 165, 391, 146, 275, 181, 257, 218, 270, 221, 282};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(8, points32);
}
void drawPolygon33() {
    int points33[] = {111, 318, 77, 305, 87, 408, 75, 408, 62, 313, 103, 293, 127, 315, 112, 320, 109, 318};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(9, points33);
}
void drawPolygon34() {
    int points34[] = {238, 387, 252, 389, 259, 413, 232, 410, 237, 388, 251, 388};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(6, points34);
}
void drawPolygon35() {
    int points35[] = {165, 392, 158, 409, 185, 410, 178, 391, 164, 392};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points35);
}
void drawPolygon36() {
    int points36[] = {108, 212, 108, 229};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points36);
}
void drawPolygon37() {
    int points37[] = {528, 380, 637, 379, 638, 404, 532, 406, 528, 381};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points37);
}
void drawPolygon38() {
    int points38[] = {570, 258, 576, 304, 544, 301, 538, 249, 570, 258};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points38);
}
void drawPolygon39() {
    int points39[] = {577, 304, 609, 305, 602, 264, 569, 258, 577, 304};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points39);
}
void drawPolygon40() {
    int points40[] = {609, 303, 637, 306, 636, 272, 602, 263, 609, 305};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points40);
}
void drawPolygon41() {
    int points41[] = {544, 301, 516, 298, 511, 244, 537, 250, 544, 300};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points41);
}
void drawPolygon42() {
    int points42[] = {517, 299, 636, 306, 637, 346, 523, 339, 516, 298};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points42);
}
void drawPolygon43() {
    int points43[] = {549, 341, 552, 380, 527, 379, 522, 338, 549, 342};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points43);
}
void drawPolygon44() {
    int points44[] = {584, 342, 590, 378, 553, 381, 549, 340, 585, 341};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points44);
}
void drawPolygon45() {
    int points45[] = {615, 345, 618, 378, 590, 380, 585, 344, 615, 346};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points45);
}
void drawPolygon46() {
    int points46[] = {637, 346, 615, 345, 619, 379, 638, 377, 636, 346};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points46);
}
void drawPolygon47() {
    int points47[] = {533, 170, 536, 211, 532, 209, 508, 217, 502, 158, 532, 171};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(6, points47);
}
void drawPolygon48() {
    int points48[] = {572, 189, 573, 222, 536, 211, 534, 170, 573, 189};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points48);
}
void drawPolygon49() {
    int points49[] = {607, 204, 607, 232, 573, 224, 573, 188, 606, 204};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points49);
}
void drawPolygon50() {
    int points50[] = {637, 218, 637, 242, 607, 233, 608, 205, 638, 220};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points50);
}
void drawPolygon51() {
    int points51[] = {107, 211, 108, 229, 131, 218, 158, 220, 155, 187, 210, 148, 222, 150, 319, 90, 298, 82, 107, 211};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(10, points51);
}
void drawPolygon52() {
    int points52[] = {20, 379, 19, 424, 31, 424, 30, 381, 20, 378};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 6);
    fillpoly(5, points52);
}
void drawPolygon53() {
    int points53[] = {7, 380, 28, 382, 26, 359, 4, 359, 6, 380};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 2);
    fillpoly(5, points53);
}
void drawPolygon54() {
    int points54[] = {12, 360, 12, 338, 41, 342, 50, 344, 49, 363, 27, 370, 26, 361, 11, 359};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 2);
    fillpoly(8, points54);
}
void drawPolygon55() {
    int points55[] = {50, 358, 60, 365, 59, 384, 58, 393, 29, 388, 26, 370, 48, 362, 48, 358};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 2);
    fillpoly(8, points55);
}
void drawPolygon56() {
    int points56[] = {75, 408, 31, 409, 32, 423, 19, 422, 19, 410, 0, 412, 0, 478, 638, 479, 638, 404, 430, 411, 75, 409};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 2);
    fillpoly(12, points56);
}
void drawPolygon57() {
    int points57[] = {377, 134, 374, 146, 363, 157, 369, 163, 367, 178, 376, 162, 392, 167, 386, 152, 393, 139, 385, 140, 377, 135};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 10);
    fillpoly(11, points57);
}
void drawPolygon58() {
    int points58[] = {477, 143, 473, 152, 459, 152, 468, 159, 467, 177, 475, 169, 486, 183, 483, 165, 488, 161, 479, 153, 477, 144};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,2);
    fillpoly(11, points58);
}
void drawPolygon59() {
    int points59[] = {392, 140, 368, 173};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points59);
}
void drawPolygon60() {
    int points60[] = {385, 139, 369, 168};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points60);
}
void drawPolygon61() {
    int points61[] = {481, 155, 468, 173};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points61);
}
void drawPolygon62() {
    int points62[] = {485, 158, 475, 171};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 4);
    fillpoly(2, points62);
}
void drawText() {
    setcolor(BLACK);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy(340, 180, "BAMPRO");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(340, 200, "Grupo");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(340, 210, "Promerica");
}
void drawText2() {
    setcolor(WHITE);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    outtextxy(425, 180, "BAMPRO");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(425, 200, "Grupo");

    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(425, 210, "Promerica");
}

void drawPolygon63() {
    int points63[] = {107, 355, 108, 392, 123, 392, 122, 358, 106, 355};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points63);
}
void drawPolygon64() {
    int points64[] = {103, 324, 132, 314, 128, 328, 103, 324};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(4, points64);
}
void drawPolygon65() {
    int points65[] = {151, 308, 133, 313, 128, 326, 154, 330, 151, 306};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points65);
}
void drawPolygon66() {
    int points66[] = {192, 295, 192, 318, 167, 318, 166, 304, 191, 294};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points66);
}
void drawPolygon67() {
    int points67[] = {192, 318, 192, 335, 170, 333, 167, 319, 192, 318};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points67);
}
void drawPolygon68() {
    int points68[] = {221, 302, 192, 312, 192, 294, 221, 284, 221, 301};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points68);
}
void drawPolygon69() {
    int points69[] = {219, 332, 206, 339, 191, 336, 193, 312, 221, 303, 219, 333};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(6, points69);
}
void drawPolygon70() {
    int points70[] = {302, 258, 302, 276, 325, 270, 324, 250, 303, 258};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points70);
}
void drawPolygon71() {
    int points71[] = {302, 276, 300, 309, 324, 303, 325, 270, 303, 277};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points71);
}
void drawPolygon72() {
    int points72[] = {300, 309, 299, 354, 326, 350, 324, 303, 299, 310};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points72);
}
void drawPolygon73() {
    int points73[] = {299, 354, 299, 385, 326, 385, 325, 351, 299, 354};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points73);
}
void drawPolygon74() {
    int points74[] = {140, 361, 140, 392, 157, 391, 155, 364, 139, 361};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 8);
    fillpoly(5, points74);
}
void drawPolygon75() {
    int points75[] = {294, 214, 323, 209, 323, 223, 293, 215};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(4, points75);
}
void drawPolygon76() {
    int points76[] = {222, 201, 238, 205, 240, 212, 224, 218, 223, 200};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points76);
}
void drawPolygon77() {
    setcolor(BLACK);  
    line(157, 189, 217, 150);
    line(217, 150, 217, 155);
    line(217, 155, 157, 195);
    line(157, 195, 156, 201);
    line(156, 201, 197, 177);
    line(197, 177, 201, 181);
    line(201, 181, 157, 207);
    line(157, 207, 158, 210);
    line(158, 210, 205, 186);
    line(205, 186, 208, 191);
    line(208, 191, 161, 214);
    line(161, 214, 158, 218);
    line(158, 218, 160, 220);
    line(160, 220, 214, 196);
    line(214, 196, 217, 199);
    line(217, 199, 160, 226);
    line(160, 226, 159, 227);
    line(159, 227, 159, 232);
    line(159, 232, 222, 203);
    line(222, 203, 223, 209);
    line(223, 209, 161, 241);
    line(161, 241, 224, 213);
    line(224, 213, 223, 217);
    line(223, 217, 161, 247);
    line(161, 247, 157, 187);
    line(157, 187, 157, 189);  
}



void drawPolygon78() {
    int points80[] = {519, 305};
    line(519, 305, 636, 312);

    points80[0] = 636; points80[1] = 312;
    line(636, 312, 635, 317);

    points80[0] = 635; points80[1] = 317;
    line(635, 317, 521, 313);

    points80[0] = 521; points80[1] = 313;
    line(521, 313, 521, 319);

    points80[0] = 521; points80[1] = 319;
    line(521, 319, 636, 324);

    points80[0] = 636; points80[1] = 324;
    line(636, 324, 636, 328);

    points80[0] = 636; points80[1] = 328;
    line(636, 328, 521, 326);

    points80[0] = 521; points80[1] = 326;
    line(521, 326, 523, 332);

    points80[0] = 523; points80[1] = 332;
    line(523, 332, 636, 335);

    points80[0] = 636; points80[1] = 335;
    line(636, 335, 636, 343);

    points80[0] = 636; points80[1] = 343;
    line(636, 343, 523, 335);

    points80[0] = 523; points80[1] = 335;
    line(523, 335, 517, 300);
}
void drawPolygon79() {
    int points81[] = {299, 354, 325, 351, 326, 384, 299, 386, 299, 354};
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points81);
}
void drawPolygon80() {
    int points82[] = {607, 206, 608, 233, 636, 240, 636, 216, 607, 205};
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, 9);
    fillpoly(5, points82);
}








int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

	drawSun();
	drawCloud(150, 80);
    drawCloud(230, 60);
    drawCloud(500, 70);
    drawCloud(650, 90);
	/*drawGrass();*/

    drawPolygon1();
    drawPolygon2();
    drawPolygon3();
    drawPolygon4();
    drawPolygon5();
    drawPolygon6();
    drawPolygon7();
    drawPolygon8();
    drawPolygon9();
    drawPolygon10();
    drawPolygon11();
    drawPolygon12();
    drawPolygon13();
    drawPolygon14();
    drawPolygon15();
    drawPolygon16();
    drawPolygon17();
    drawPolygon18();
    drawPolygon19();
    drawPolygon20();
    drawPolygon21();
    drawPolygon22();
    drawPolygon23();
    drawPolygon24();
    drawPolygon25();
    drawPolygon26();
    drawPolygon27();
	drawPolygon29();
	drawPolygon30();
	drawPolygon31();
	drawPolygon32();
	drawPolygon33();
	drawPolygon34();
	drawPolygon35();
	drawPolygon36();
	drawPolygon37();
	drawPolygon38();
	drawPolygon39();
	drawPolygon40();
	drawPolygon41();
	drawPolygon42();
	drawPolygon43();
	drawPolygon44();
	drawPolygon45();
	drawPolygon46();
	drawPolygon47();
	drawPolygon48();
	drawPolygon49();
	drawPolygon51();
	drawPolygon52();
	drawPolygon53();
	drawPolygon54();
	drawPolygon55();
	drawPolygon56();
	drawPolygon57();
	drawPolygon58();
	drawPolygon59();
	drawPolygon60();
	drawPolygon61();
	drawPolygon62();
	drawText();
	drawText2();
	drawPolygon63();
	drawPolygon64();
	drawPolygon65();
	drawPolygon66();
	drawPolygon67();
	drawPolygon68();
	drawPolygon69();
	drawPolygon70();
	drawPolygon71();
	drawPolygon72();
	drawPolygon73();
	drawPolygon74();
	drawPolygon75();
	drawPolygon75();
	drawPolygon76();
	drawPolygon77();
	drawPolygon78();
	drawPolygon79();
	drawPolygon80();


    getch();
    closegraph();
    return 0;
}
