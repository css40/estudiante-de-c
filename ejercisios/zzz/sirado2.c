#include <stdio.h>
#include <string.h>
void jiami(char Q[100],char K[100],int len_Q,int len_K)
{
    char A[100];
    int i=0,j=0,k;
    for(; i<len_Q; i++)
    {
        if(K[j]>96)
            k=K[j]-'a';
        else if(K[j]>64)
            k=K[j]-'A';
        if(Q[i]>96)
            A[i]=(Q[i]-'a'+k)%26+'a';
        else if(Q[i]>64)
            A[i]=(Q[i]-'A'+k)%26+'A';
        else if(Q[i]==" ")
            A[i]==" ";
        j=(j+1)%len_K;
    }
    A[i]='\0';
    printf("\n Obtener el texto cifrado:%s \n",A);
}

void jiemi(char Q[100],char K[100],int len_Q,int len_K)
{
    char A[100];
    int i=0,j=0,k;
    for(; i<len_Q; i++)
    {
        if(K[j]>96)
            k=K[j]-'a';
        else if(K[j]>64)
            k=K[j]-'A';
        if(Q[i]>96)
            A[i]=(Q[i]-'a'+(26-k))%26+'a';
        else if(Q[i]>64)
            A[i]=(Q[i]-'A'+(26-k))%26+'A';
        else if(Q[i]==" ")
            A[i]==" ";
        j=(j+1)%len_K;
    }
    A[i]='\0';
    printf("\ nObtener el texto cifrado:% s \ n",A);
}

int main()
{
    while(1)
    {
        fflush(stdin);
        int choice,len_Q,len_K;
        char Q[100];
        char K[100];
        printf("\n Introduzca el número de operación: 1 cifrado 2 descifrado 3 salga:");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\n ------ Agregar MI secreto de JIA ------ \n");
            fflush(stdin);
            printf("Introduzca texto sin formato:");
            gets(Q);
            fflush(stdin);
            len_Q=strlen(Q);
            printf("Introduzca la clave K:");
            gets(K);
            len_K=strlen(K);
            jiami(Q,K,len_Q,len_K);
        }
        else if(choice==2)
        {
            printf("\ n ------ Desbloquear MI secreto de JIE ------ \ n");
            fflush(stdin);
            printf("Por favor ingrese el texto cifrado:");
            gets(Q);
            fflush(stdin);
            len_Q=strlen(Q);
            printf("Introduzca la clave k:");
            gets(K);
            len_K=strlen(K);
            jiemi(Q,K,len_Q,len_K);
        }
        else if(choice==3)
            exit(0);
        else
        {
            printf("No existe tal número de operación, ¡vuelva a ingresar! \ N");
            continue;
        }
    }
    return 0;
}





