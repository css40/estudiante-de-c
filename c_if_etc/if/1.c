/*Realiza un algoritmo para saber si un numero ingresado es positivo negativo o es cero.*/

#include <stdio.h>

int main()
{
	int num;
	printf("ingreesa un numero ");
	scanf("%d",&num);
	
	if(num>0)
	{
		printf("su numero es positivo");
	}
	else if(num<0)
	{
		printf("su numero es negativo ");
	}
	else
	{
		printf("su numero es cero ");
	}
	
	return 0;
	getchar();
}
/*gcc algo_+-.c -o algo.exe*/
/*./algo.exe*/

