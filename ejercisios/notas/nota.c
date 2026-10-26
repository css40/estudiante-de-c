#include <stdio.h>
#include <cs50.h>

int main()
{
    int nota[5];
    //rellenamos arreglo
    for(int i = 0; i<5; i++)
    {
        nota[i] = get_int("Ingrese nota %d: ", i+1);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("La nota %d es igual a %d\n", i+1, nota[i]);
    }
}