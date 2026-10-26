#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

void main(void)
{
    char *stringx, *stringy;
    int x = 150, y = 150;
    int adaptador = DETECT, modo;
    
    initgraph(&adaptador, &modo, "c:\\tc20\\bin");
    cleardevice();

    /*Asigna memoria dinámica para stringx y stringy*/
    stringx = (char *)malloc(20 * sizeof(char)); /*por ejemplo, asignamos memoria para 20 caracteres*/
    stringy = (char *)malloc(20 * sizeof(char));

    itoa(x, stringx, 10);
    itoa(y, stringy, 10);

    outtextxy(150, 130, "LOS VALORES DE X e Y SON:");
    outtextxy(150, 150, "x="); 
    outtextxy(170, 150, stringx);
    outtextxy(150, 160, "y="); 
    outtextxy(170, 160, stringy);

    getch();

    /*Liberamos la memoria asignada dinámicamente*/
    free(stringx);
    free(stringy);
}
/*En este código, hemos asignado memoria dinámicamente para stringx y stringy utilizando 
la función malloc. Recuerda siempre liberar 
la memoria utilizando free una vez que ya no la necesites para evitar fugas de memoria.Y de esta manera resolvemos los
4 warning que nos daba la funcion " possible use of stringx before definition in funtion main " */