# include <conio.h>
# include <graphics.h>
# include <math.h>
# include <dos.h>
void inicializar(void);
void cuerpo(void);
void main(void)
{
inicializar();
cuerpo();
}
void inicializar(void)
{
int drive=DETECT,modo;
initgraph(&drive,&modo,"c:\\tc20\\bin");
}
void cuerpo()
{
    double x, y;
    while (!kbhit())
    {
        x = -180;
        while (x <= 180 && !kbhit())
        {
            y = sqrt(15000 * (1 - ((x * x) / 32400)));
            circle(x + 310, 240 - y, 20);
            delay(50); /*delay original 15000*/
            x += 1;
        }

        x = 180;
        while (x >= -180 && !kbhit())
        {
            y = -1 * sqrt(15000 * (1 - ((x * x) / 32400)));
            circle(x + 310, 240 - y, 20);
            delay(50); /*delay original 15000*/
            x -= 1;
        }

        cleardevice(); 
    }
    getch();
}

