#include <graphics.h>
# include<conio.h>
#include <stdio.h>
void main() {
int driver = EGA;
int modo = EGAHI;
struct textsettingstype info;
initgraph( &driver, &modo, "C:\\TC20\\BIN" );
gettextsettings( &info );
closegraph();
printf( "Texto\n\nFuente: %d\tSentido: %d\tTamano: %d\nJustificacion:\nHorizontal: %d, Vertical: %d \n",
info.font, info.direction, info.charsize, info.horiz, info.vert);
getch();
}
/*hay un error de formato en la cadena de caracteres, 
y también hay un problema con la forma en que has dividido la cadena en varias líneas.*/