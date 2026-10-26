#include <graphics.h>
#include <stdio.h>
void main() {
int driver = EGA,modo = EGAHI;
struct textsettingstype info;
initgraph( &driver, &modo, "C:\\tc20\\BIN" );
gettextsettings( &info );
closegraph();
printf( "Texto\n\nFuente: %d\tSentido: %d\tTamaño: %d\n Justificación:\nHorizontal: %d, Vertical: %d\n",
info.font, info.direction, info.charsize, info.horiz, info.vert);
getchar();
}