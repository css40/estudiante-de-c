#include <stdio.h>
#include <math.h>
#include "cs50.c"

int raiz(int n);
int expo(int n, int x);
int main()
{
    int n = get_int("Ingrese numero: ");
    int raizDevuelto = raiz(n);
    printf("La raiz de %d es %d\n",n, raizDevuelto);

    int m = get_int("base: ");
    int e = get_int("expo: ");
    printf("El exponente de %d a la %d es %d",m,e,expo(m,e));
}

int raiz(int n)
{
    int x = sqrt(n);
return x;
}

int expo(int n, int x)
{

return pow(n,x);

}