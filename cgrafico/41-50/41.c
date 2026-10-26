#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define EGAH 2

void main() {
int driver =EGA,modo =EGAH,color_max;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
color_max = getmaxcolor();
closegraph();
printf( "Color m ximo: %d\n", color_max );
getch();
}
/*Intentamos corregir el error asegurándonos de que EGAH esté definida 
correctamente o utilizando una constante que esté definida en graphics.h. 
Si EGAH es una constante personalizada, asegúramos de definirla en el código antes de usarla.*/