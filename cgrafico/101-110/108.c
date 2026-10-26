#include <dos.h> para la funcion int86()
#include <stdio.h> para la funcion printf()
#include <conio.h> para la funcion getch()
unsigned char *DIR_VGA = (unsigned char *)MK_FP(0xA000, 0);
void Modo13h(void)
{
    _AX = 0x0013;
    geninterrupt(0x10);
}
void ModoTexto(void)
{
    _AX = 0x0003;
    geninterrupt(0x10);
}
void main(void)
{
    Modo13h();
    printf("Inicializacion correcta\npresione una tecla para volver\n al modo grafico");
    getch();
    ModoTexto();
    printf("Regreso a modo VGA");
    getch();
}