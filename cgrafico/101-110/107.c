#include <dos.h> para la funcion int86()
#include <stdio.h> para la funcion printf()
#include <conio.h> para la funcion getch()
void Modo13h(void)
{
    union REGS r;
    r.h.ah = 0;
    r.h.al = 0x13;
    int86(0x10, &r, &r);
}
void ModoTexto(void)
{
    union REGS r;
    r.h.ah = 0;
    r.h.al = 0x03;
    int86(0x10, &r, &r);
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