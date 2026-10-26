/*Librerias incluidas*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>

#define ASIENTOS_TOTALES 10
#define PRECIO_POR_ASIENTO 100.00

void login();
void menu();
void Presentacion();
void boletos();
void centrartexto(char *, int);

struct socio
{
    char nombres[50];
    char telefono[11];
    char ciudad[20];
    char correo[100];

    int estado;
} s[10];

int main()
{
    login();
    return 0;
}

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
            cprintf("Datos incorrectos! Intetelo de nuevo.llevas %d", intentos, " intentos");
            textcolor(15);
            gotoxy(3, 23);
            system("pause");
            clrscr();
        }
    } while (intentos != 3);
}

void menu()
{
    int op, a;
    int bandera = 0;
    int i = 0;
    char salida[10];
    do
    {
        bandera = 0;
        clrscr();

        printf("\n");
        printf("\n");
        cprintf("1. Presentacion\n");
        printf("\n");
        textcolor(15);
        cprintf("2. Adquirir Boletos\n");
        printf("\n");
        textcolor(15);
        cprintf("3.	Cancelar Boletos.\n");
        printf("\n");
        textcolor(15);
        cprintf("4.	Ver Boletos Disponibles\n");
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

    } while (op < 1 || op > 5 || bandera != 0);

    switch (op)
    {
    case 1:
        Presentacion();
        break;

    case 2:
        boletos();
        break;

    case 3:

        break;

    case 4:

        break;

    case 5:
        clrscr();
        exit(0);
        break;

    default:
        printf("opcion invalida ");
    }
}

void Presentacion()
{
    clrscr();

    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n");
    printf("Carrera:           Ing. de Computacion\n");
    printf("\n");
    printf("Nombre:     [Guillermo A.]\n");
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

void boletos()
{
    int i, j, n_cuenta, rep, aux = 0;
    int cantidad_asientos;
    int asientos_disponibles[ASIENTOS_TOTALES];
    double monto_total = 0.0;

    clrscr();

    printf("\t\t\t\t\t   ===========================\n");
    printf("\t\t\t\t\t        SISTEMA BANCARIO     \n");
    printf("\t\t\t\t\t   ===========================\n\n\n");
    printf("REGISTRAR SOCIO\n");
    printf("---------------\n\n");
    fflush(stdin);
    for (i = 0; i < 10; i++)
    {
        if (s[i].estado == 0)
        {

            aux = 1;

            printf("Ingrese nombres:     ");
            gets(s[i].nombres);

            printf("Ingrese ciudad:      ");
            gets(s[i].ciudad);

            printf("Ingrese telefono:    ");
            gets(s[i].telefono);

            do
            {
                rep = 0;
                printf("Ingrese correo electronico: ");
                scanf("%i", &n_cuenta);

                for (j = 0; j < 10; j++)
                {
                    if (n_cuenta == s[j].correo)
                    {
                        rep = 1;
                    }
                }
            } while (rep == 1);

            s[i].estado = 1;
            while (1)
            {
                printf("¿Cuántos asientos desea comprar (1-3)? ");
                scanf("%d", &cantidad_asientos);
                if (cantidad_asientos >= 1 && cantidad_asientos <= 3)
                {
                    break;
                }
                else
                {
                    printf("Debe comprar entre 1 y 3 asientos.\n");
                }
            }
            printf("Asientos disponibles:");

            for (int i = 0; i < ASIENTOS_TOTALES; i++)
            {
                if (asientos_disponibles[i] != -1)
                {
                    printf(" %d", asientos_disponibles[i]);
                }
            }
            printf("\n");

            // Solicitar la selección de asientos
            int asientos_comprados[cantidad_asientos];
            for (int i = 0; i < cantidad_asientos; i++)
            {
                while (1)
                {
                    printf("Seleccione el asiento %d: ", i + 1);
                    int numero_asiento;
                    scanf("%d", &numero_asiento);

                    int asiento_valido = 0;
                    for (int j = 0; j < ASIENTOS_TOTALES; j++)
                    {
                        if (asientos_disponibles[j] == numero_asiento)
                        {
                            asientos_comprados[i] = numero_asiento;
                            asientos_disponibles[j] = -1; // Marcar el asiento como reservado
                            asiento_valido =
                                asiento 1;
                            break;
                        }
                    }

                    if (asiento_valido)
                    {
                        break;
                    }
                    else
                    {

                        printf("Ese asiento no está disponible. Elija otro.\n");
                    }
                }
            }

            // Calcular el monto total a pagar
            monto_total = cantidad_asientos * PRECIO_POR_ASIENTO;

            monto_total = cantidad_asientos * PRECIO
                                                  // Mostrar la factura
                                                  printf("\nFACTURA:\n");
            printf("Nombre del cliente: %s %s\n", nombre, apellidos);
            printf("Correo electrónico: %s\n", correo);
            printf("Número de celular: %s\n", numero_de_celular);
            printf("Asientos comprados:");
            for (int i = 0; i < cantidad_asientos; i++)
            {
                printf(" %d", asientos_comprados[i]);
            }
            printf("\nMonto a pagar: $%.2lf\n", monto_total);

            return 0;
        }

        if (aux == 0)
        {
            printf("\nNo se pueden registrar mas socios.\n");
            system("pause");
            menu();
        }

        getch();
    }
}

void centrartexto(char *texto, int y)
{
    int longitud = strlen(texto);
    gotoxy(40 - (longitud / 2), y);
    printf(texto);
}