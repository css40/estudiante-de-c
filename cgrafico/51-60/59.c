#include <graphics.h>
#include <conio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
/*registerbgifont(1);*/ /*si descomentamos me da un warniing pero aun comentada hacemos uso de la fuente */
initgraph( &driver, &modo,"C:\\TC20\\BIN" );
outtext( "Esto es una prueba con la fuente \"Sans Serif\"" );
getch(); /* Pausa */
closegraph();
getch();
}
