#include <stdio.h>
#include <cs50.h>
int main()
{
    int nota = get_int("Ingrese tamaño notas: ");
    int peque; int gran;
    int notas[nota];
    for(int i = 0; i<nota; i++)
    {
        notas[i] = get_int("Ingrese notas: ");
    }
    peque = notas[0];
    gran = notas[0];
    for(int i = 0; i<nota; i++)
    {
        if(notas[i]<peque)
        {
            peque = notas[i];
        }
        else if (notas[i] > gran)
        {
            gran = notas[i];
        }
    }
        printf("Grande: %d\nPeque:%d\n", gran, peque);

}