/*Librerias incluidas*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>

/*variables globales*/
float saldo = 0;


/*llamado de funciones*/
void gotoxy(int, int);
void login();
void menu();
void titulo();
void titulo2();
void titulo3();
void tituloatm();
void titulorecarga();
void gotoxy(int x, int y);
void dibujarLogo();
void Presentacion();
void centrartexto(char *, int);
void ingresarR(); 
void cajeroATM(); 
void recarga();  


int main()
{
    login();
    dibujarLogo();
    return 0;
}



/*Funcion de inicio de sesion*/
void login()
{
    char usuario[30] = "Admin";
    char contra[30] = "12345";
    char usu[30], con[30];
    int intentos = 0, i;
    char caracter;
    fflush(stdin);
    do
    {
        intentos++;
        i = 0;
        clrscr();
        titulo();
        gotoxy(3, 5);
        cprintf("Usuario:  ");
        gets(usu);
        gotoxy(3, 7);
        cprintf("Contrasena:   ");
        while (caracter = getch())
        {
            if (caracter == 13)
            {
                con[i] = '\0';
                break;
            }

            else if (caracter == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }

            else
            {
                printf("*");
                con[i] = caracter;
                i++;
            }
        }
        centrartexto("CARGANDO...", 21);

        for (i = 3; i <= 76; i++)
        {
            gotoxy(i, 23);
            cprintf("%c", 177);
        }
        for (i = 3; i <= 76; i++)
        {
            gotoxy(i, 23);
            cprintf("%c", 219);
            textcolor(15);
            delay(30);
        }
        gotoxy(3, 21);
        printf("                                                                             ");
        gotoxy(3, 23);
        printf("                                                                             ");
        
        if (strcmp(usuario, usu) == 0 && strcmp(contra, con) == 0)
        {
            gotoxy(3, 22);
            cprintf("Los datos ingresados son correctos!");
            gotoxy(3, 23);
            system("pause");
            menu();
        }

        else if (intentos == 3)
        {
            gotoxy(3, 22);
            cprintf("Datos incorrectos! Ha excedido el numero de intentos!");
            gotoxy(3, 23);
            system("pause");
            textcolor(4 + 128);
            exit(0);
            clrscr();
        }
        else
        {
            gotoxy(3, 22);
            cprintf("Datos incorrectos! Intetelo de nuevo.llevas %d",intentos," intentos");
            textcolor(15);
            gotoxy(3, 23);
            system("pause");
            clrscr();
        }
    } while (intentos != 3);
}





/*funcio de la presentacion*/
void Presentacion()
{
    clrscr();
    titulo2();
    dibujarLogo();
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n");
    printf("Carrera:           Ing. de Computacion\n");
    printf("\n");
    printf("Nombre:     [Guillermo A.  Jhonatham  . Leonardo  .]\n");
    printf("\n");
    printf("Grupo:                 [ 1M1-Co ]\n");
    printf("\n");
    printf("Profesor:           [Heymer Duarte]\n");
    printf("\n");
    printf("       ---Precione cualquier tecla para volver al menu--- ");
    getch();
    menu();
    clrscr();
}




/*Funcion del cajero*/
void cajeroATM()
{
    int opcion, i;
    float cantidad;
    int bandera = 0;
    int e = 0;
    char salida[10];
    clrscr();
    do
    {
        bandera = 0;
        clrscr();
        tituloatm();
        printf("\n");
        cprintf(" 1. Ingresar Saldo en cuenta\n");
        textcolor(15);
        printf("\n");
        cprintf(" 2. Retirar saldo de cuenta\n");
        textcolor(15);
        printf("\n");
        cprintf(" 3. Consultar saldo de cuenta\n");
        textcolor(15);
        printf("\n");
        cprintf(" 4. Volver al Menu Principal\n");
        printf("\n");
        textcolor(15);
        cprintf("  Ingrese su opcion: ");
        textcolor(15);
        scanf("%s", &salida);
        while (salida[e]) 
        {
            if (!isdigit(salida[e])) 
            {
                bandera = 1;
                printf("\n\n");
                printf("\tOpcion no valida\t");
                printf("\n\n");
                printf("\tPreciona cualquier tecla para reintentar\t");
                getch();
                clrscr();
                break;
            }
            e++;
        }
        if (!bandera) 
        {
            sscanf(salida, "%d", &opcion);
        }
    } while (opcion < 1 || opcion > 4 || bandera != 0 );

    switch (opcion)
        {
        case 1:
            clrscr();
            printf("Ingrese la cantidad a ingresar: ");
            scanf("%f", &cantidad);

            if (cantidad < 0 || cantidad > 10000)
            {
                printf("\n");
                printf("Cantidad no valida. Debe ser mayor que 0 y menor o igual a 10,000.\n");
                printf("\n");
                printf("Precione una tecla para volver .");
                
            }
            else
            {
                saldo += cantidad;
                printf("Saldo actual: %.2f\n", saldo);
                printf("\n");
                printf("Precione una tecla para volver .");
            } 
            getch();
            clrscr();
            cajeroATM();
            break;
        case 2:
            clrscr();
            printf("Ingrese la cantidad a retirar: ");
            scanf("%f", &cantidad);
            if (cantidad < 0 || cantidad > saldo)
            {
                printf("\n");
                printf("Cantidad no valida. Debe ser mayor que 0 y menor o igual al saldo actual.\n");
                printf("\n");
                printf("Precione una tecla para reintentar .");
            }
            else
            {
                saldo -= cantidad;
                printf("Saldo actual: %.2f\n", saldo);
                printf("\n");
                printf("Precione una tecla para volver .");
            }
            getch();
            clrscr();
            cajeroATM();
            break;
        case 3:
            clrscr();
            cprintf("Saldo actual: %.2f\n", saldo);
            printf("\n");
            printf("Precione una tecla para volver .");
            textcolor(15);
            getch();
            clrscr();
            cajeroATM();
            break;
        case 4:
            centrartexto("Saliendo de la opcion cajero", 21);
            textcolor(15);

            for (i = 3; i <= 76; i++)
            {
                gotoxy(i, 23);
                cprintf("%c", 177);
               
            }
            for (i = 3; i <= 76; i++)
            {
                gotoxy(i, 23);
                cprintf("%c", 219);
                textcolor(15);
                delay(30);
            }
            menu();
            break;
        default:
            printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
            getch();
            clrscr();
        }
}




/*Funcio de las Recargas*/
void recarga()
{
    int operador,i;
    char numero[9];
    float cantidad;
    int bandera = 0;
    int e = 0;
    char salida[10];
   do
   {
        bandera = 0;
        clrscr();
        titulorecarga();
        printf("\n\n");
        printf("1. TIGO\n");
        printf("\n");
        printf("2. CLARO\n");
        printf("\n");
        printf("3. Salir\n"); 
        printf("Ingrese su opcion: ");
       
        scanf("%s", &salida);
          while (salida[e]) 
        {
            if (!isdigit(salida[e])) 
            {
                printf("\n\n");
                printf("\tOpcion no valida\t");
                printf("\n\n");
                printf("\tPreciona cualquier tecla para reintentar\t");
                bandera = 1;
                getch();
                clrscr();
                break;
            }
            e++;
        }
        if (!bandera) 
        {
            sscanf(salida, "%d", &operador);
        }
   } while (operador < 1 ||operador >  3 || bandera != 0);
   
    switch (operador)
    {
    case 1:
        printf("\n");
        printf("Ha seleccionado TIGO.\n");
        break;
    case 2:
        printf("\n");
        printf("Ha seleccionado CLARO.\n");
        break;
    case 3:
            centrartexto("Saliendo de la opcion de recarga.", 21);
            textcolor(15);

            for (i = 3; i <= 76; i++)
            {
                gotoxy(i, 23);
                cprintf("%c", 177);
            
            }
            for (i = 3; i <= 76; i++)
            {
                gotoxy(i, 23);
                cprintf("%c", 219);
                textcolor(15);
                delay(30);
            }
            menu();
            
        return; 
    default:
        printf("Opcion no valida. Debe ser 1 para TIGO, 2 para CLARO o 3 para salir.\n");
        getch();
        recarga();
        return; 
    }
    ingresarR();
}



/*funcion donde hacemos el menu de opciones*/
void menu()
{
    int op ,a;
    int bandera = 0;
    int i = 0;
    char salida[10];
    do
    {
        bandera = 0;
        clrscr();
        titulo3();
        printf("\n");
        printf("\n");
        cprintf("1. Presentacion\n");
        printf("\n");
        textcolor(15); 
        cprintf("2. Cajero ATM - UNI\n");
        printf("\n");
        textcolor(15);
        cprintf("3. Recarga\n");
        printf("\n");
        textcolor(15);
        cprintf("4. Cerrar Sesion\n");
        printf("\n");
        textcolor(15);
        cprintf("5. Salir del Programa\n");
        textcolor(15);
        printf("\n");
        cprintf("--Ingrese una opcion: ");
        textcolor(15);
        scanf("%s", &salida);
        while (salida[i]) 
        {
            if (!isdigit(salida[i])) 
            {
                printf("\n");
                cprintf("Opcion no valida");
                textcolor(15);
                printf("\n\n");
                cprintf("Preciona cualquier tecla para reintentar");
                textcolor(15);
                bandera = 1;
                getch();
                clrscr();
                break;
            }
            i++;
        }
        if (!bandera) 
        {
            sscanf(salida, "%d", &op);
        }

    } while (op < 1 || op > 5 || bandera != 0 );

    switch (op)
    {
    case 1:
        Presentacion();
        break;

    case 2:
        cajeroATM();
        break;

    case 3:
        recarga();
        break;

    case 4:
        centrartexto("Cerrando sesion ...", 21);

        for (i = 3; i <= 76; i++)
        {
            gotoxy(i, 23);
            cprintf("%c", 177);
        }
        for (i = 3; i <= 76; i++)
        {
            gotoxy(i, 23);
            cprintf("%c", 219);
            textcolor(15);
            delay(30);
        }
        clrscr();
        login();
        break;

    case 5:
        clrscr();
        dibujarLogo();
        exit(0);
        break;

    default:
        printf("opcion invalida ");
    }
}



/********************************************************************************************************/
/********************* funciones secundarias que me ayudaron a dar estilo entre otros *******************/
/********************************************************************************************************/


/*Esta funcion me ayuda para formar el pequeño recuadro de los titulos*/
void recuadro(int x, int y, int xi, int yi)
{
    int z;
    for (z = x; z <= xi; z++)
    {
        gotoxy(z, y);
        printf("%c", 196);
        gotoxy(z, yi);
        printf("%c", 196);
    }

    for (z = y; z <= yi; z++)
    {
        gotoxy(x, z);
        printf("%c", 179);
        gotoxy(xi, z);
        printf("%c", 179);
    }
    gotoxy(x, y);
    printf("%c", 218);
    gotoxy(xi, yi);
    printf("%c", 217);
    gotoxy(xi, y);
    printf("%c", 191);
    gotoxy(x, yi);
    printf("%c", 192);
}


/*con es sta funcionn logro centrar los titulos entre otros*/
void centrartexto(char *texto, int y)
{
    int longitud = strlen(texto);
    gotoxy(40 - (longitud / 2), y);
    printf(texto);
}




/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*con estas funciones logro centrar los titulos*/
void titulo()
{
    recuadro(1, 1, 78, 3);
    centrartexto("INICIO DE SESION", 2);
    textcolor(15);
}
void titulo2()
{
    recuadro(1, 1, 78, 3);
    centrartexto("Presentacion del trabajo", 2);
    textcolor(15);
}
void titulo3()
{
    recuadro(1, 1, 78, 3);
    centrartexto("MENU PRINCIPAL", 2);
    textcolor(15);
}
void tituloatm()
{
    recuadro(1, 1, 78, 3);
    centrartexto("Cajero ATM - UNI", 2);
    textcolor(15);
}
void titulorecarga()
{
    recuadro(1, 1, 78, 3);
    centrartexto("R e c a r g a", 2);
    textcolor(15);
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*ESTA FUNCION ME PERMITE DIBUJAR UN LOGO MEDIANTES COORDENADAS QUE LE ESPECIFICO*/
void dibujarLogo()
{
    int x, y;

    for (y = 5; y <= 10; y++)
    {
        gotoxy(18, y);
        textcolor(BLUE);
        cprintf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
        delay(100);
    }

    for (x = 18; x <= 35; x++)
    {
        gotoxy(x, 11);
        cprintf("%c", 219);
        gotoxy(x, 12);
        cprintf("%c", 219);
        gotoxy(x, 13);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 13; y >= 8; y--)
    {
        gotoxy(35, y);
        cprintf("%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 7; y <= 9; y++)
    {
        gotoxy(27, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 27; x <= 47; x++)
    {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 5; y <= 13; y++)
    {
        gotoxy(42, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 42; x <= 52; x++)
    {
        gotoxy(x, 11);
        cprintf("%c", 219);
        gotoxy(x, 12);
        cprintf("%c", 219);
        gotoxy(x, 13);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }

    for (y = 13; y >= 8; y--)
    {
        gotoxy(50, y);
        cprintf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219);
        delay(100);
        textcolor(BLUE);
    }

    for (x = 50; x <= 55; x++)
    {
        gotoxy(x, 5);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        gotoxy(x, 6);
        cprintf("%c", 219);
        delay(100);
        textcolor(BLUE);
    }
}




/*CON esta funcion valido los numeros de las recargas entre otros*/
void ingresarR() 
{

    char numero[9];
    float cantidad;
    int i, todosCeros= 1;
    printf("\n");
    printf("Ingrese el numero telefonico (8 digitos): ");
    scanf("%s", numero);

    if (strlen(numero) != 8)
    {
        printf("\n");
        printf("Numero no valido.\n");
        printf("Precione cualquier tecla para reintentar");
        getch();
        recarga();
        return; 
    }
    for (i = 0; i < 8; i++) 
    {
        if (!isdigit(numero[i])) 
        {
            printf("\n");
            printf("Numero no valido.\n");
            printf("Precione cualquier tecla para reintentar");
            getch();
            recarga();
            return;
        }
        if (numero[i] != '0') 
        {
            todosCeros = 0;
        }
    }
    if (todosCeros)
    {
        printf("\n");
        printf("Este numero no existe.\n");
        printf("\n");
        printf("Precione cualquier tecla para reintentar");
        getch();
        recarga();
        return;
    }
    
    printf("\n");
    printf("Ingrese la cantidad a recargar: ");
    scanf("%f", &cantidad);

    if (cantidad < 0 || cantidad > saldo)
    {
        printf("\n");
        printf("Cantidad no valida. Debe ser mayor que 0 y menor o igual al saldo actual.\n");
        printf("Precione cualquier tecla para reintentar");
        getch();
        recarga();
        return; 
    }
    else
    {
        printf("\n");
        saldo -= cantidad;
        printf("Saldo actual: %.2f\n", saldo);
        printf("\n");
        printf("Precione cualquier tecla para volver al menu");
    }
    getch();
    recarga();
}



/*errores mas comunes que tubimos al crear el codigo*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Errores a solucionados/
/*1. no me almacena correctamente la variable saldo*/
/*2. cuando entro a presentacion todo se pinta de azul*/
/*3. validacion de letras*/
/*4. declarar en funcion recargas que no se puede recargar al ingrsar 8(0) )*/
/*5. solucionar las recargas flotantesS*/