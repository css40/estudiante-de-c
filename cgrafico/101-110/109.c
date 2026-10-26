#include <dos.h> para MK_FP,poke,ouportb,geninterrupt
#include <stdlib.h> para random()
#include <conio.h> para kbhit()
typedef unsigned char byte;
byte far *Video = (byte far *)MK_FP(0xA000, 0x000);
void Setrgbpalette(byte c, byte r, byte g, byte b)
{
    outportb(0x3c8, c);
    outportb(0x3c9, r);
    outportb(0x3c9, g);
    outportb(0x3c9, b);
}
void Modo13h(void)
{
    _AL = 0x13;
    _AH = 0;
    geninterrupt(0x10);
}
void ModoTexto(void)
{
    _AL = 0x03;
    _AH = 0;
    geninterrupt(0x10);
}
void main(void)
{
    int x, y, c;
    Modo13h();
    for (x = 1; x <= 32; x++)
    {
        Setrgbpalette(x, x * 2 - 1, 0, 0);
        Setrgbpalette(x + 32, 63, x * 2 - 1, 0);
        Setrgbpalette(x + 64, 63, 63, x * 2 - 1);
        Setrgbpalette(x + 96, 63, 63, 63);
    }
    do
    {
        x = 0;
        do
        {
            y = 60;
            do
            {
                c = (Video[(y << 8) + (y << 6) + x] + Video[(y << 8) + (y << 6) + x + 2] +
                     Video[(y << 8) + (y << 6) + x - 2] + Video[(y + 2) * 320 + x + 2]) /
                    4;
                if (c != 0)
                    c--;
                poke(0xA000, (y - 2) * 320 + x, (c << 8) + c);
                poke(0xA000, (y - 1) * 320 + x, (c << 8) + c);
                y += 2;
            } while (y < 202);

            y -= 2;
            Video[(y << 8) + (y << 6) + x] = random(2) * 160;
            x += 2;
           
        } while (x <= 320);
    } while (!kbhit());
    ModoTexto();
}
