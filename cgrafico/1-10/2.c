#include <graphics.h>
# include<process.h>
# include <conio.h>
void main() {
int driver = VGA;
int modo = VGAHI;
int resultado;
initgraph(&driver,&modo,"c:\\tc20\\bin");
resultado=graphresult();
if(resultado!=grOk)
{
getch();
exit(0);
}
getch();
}