#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
void main() {
int driver = IBM8514;
int modo = IBM8514HI,i;
char nombre[100];/*original (char *nombre;) 3 warning ocaciona*/
int num_modo;
initgraph( &driver, &modo,"C:\\TC20\\BIN");
num_modo = getgraphmode();
strcpy(nombre,getmodename(num_modo));
closegraph();
for(i=0;nombre[i];i++)
printf("%c",nombre[i]);
getch();
}
/*Los warning que estamos recibiendo indica que estamos 
utilizando la variable nombre antes de que se haya definido. 
Esto se debe a que estabamos intentando copiar una cadena de caracteres en nombre 
utilizando la función strcpy antes de asignarle memoria.*/