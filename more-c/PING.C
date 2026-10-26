#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <static.h>
#include  <dos.h>

void login(void);
void menu(void);
void Presentacion(void);


struct Usuario {
    char nombre[50];
    char apellido[50];
    char telefono[15];
    char correo[100];
    int asientos_comprados[3];
};

struct Factura {
    char fecha[20];
    struct Usuario usuario;
    int asientos_restantes;
};

int asientos_disponibles[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int validarCorreo(const char *correo) {
    int longitud = strlen(correo);
    const char *dominio = "@gmail.com";
    int longitud_dominio = strlen(dominio);

    if (longitud < 8 || strcmp(correo + longitud - longitud_dominio, dominio) != 0) {
        return 0;
    }
    return 1;
}

int main()
{
    hola();
    getch();
    login(); 
    menu();
    return 0;
}
/*barra de carga*/
void progressBar(int progress, int x, int y) {
    int barLength = 50, i;
    int numChars = (int)(((float)progress / 100) * barLength);
    gotoxy(x, y);
    printf("                         __|__\n");
    gotoxy(x, y + 1);
    printf("                  ------oo(_)oo------");
    gotoxy(x, y + 3);
    printf("[");
    for (i = 0; i < barLength; i++) {
        if (i < numChars) {
            printf("%c", 223);
        } else {
            printf(" ");
        }
    }
    printf("] %d%%", progress);
}

void runProgressBar(void) {
    int progress = 0;
    int centerX = 40; 
    int centerY = 12; 
    int barX = centerX - 25;
    int barY = centerY - 2; 
    clrscr();
    
    while (progress <= 100) {
        progressBar(progress, barX, barY + 4); 
        delay(30);
        progress++;
    }
}

void login(void)
{

    char usuario[30] = "A";
    char contra[30] = "1";
    char usu[30], con[30];
    int intentos = 0, i;
    char caracter;

    fflush(stdin);
    do
    {
        intentos++;
        i = 0;
        clrscr();
    cprintf("\t\tBIENVENIDO A NUESTRA APLICACIoN!\t\t");
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
      

        if (strcmp(usuario, usu) == 0 && strcmp(contra, con) == 0)
        {
            gotoxy(3, 22);
            cprintf("Los datos ingresados son correctos!");
            gotoxy(3, 23);
            system("pause");
            runProgressBar();
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


void Presentacion(void)
{
    clrscr();
    dujujodelogo();
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("\n");
    printf(" Carrera:                Ing. de Computacion\n");
    printf("\n");
    printf(" Nombre:        [Guillermo A. Jean Carlos. Cristopher Lenin. ]\n");
    printf("\n");
    printf(" Grupo:                      [ 1M1-Co ]\n");
    printf("\n");
    printf(" Profesor:                [Heymer Duarte]\n");
    printf("\n");
    printf("       ---Precione cualquier tecla para volver al menu--- ");
    getch();
    menu();
    system("cls");
}



void menu(void) {
    
    struct Factura *facturas = (struct Factura *)malloc(10 * sizeof(struct Factura));
    int num_facturas = 0;
    int num_asientos;
    int asiento_elegido;
    int encontrado = 0;
    char nombre_buscar[50];
    int indice_cancelar = -1;
    char nombre_cancelar[50];
    struct Factura nueva_factura;
    struct Usuario nuevo_usuario;
    int opcion;
    int i, j, k;
    int asiento_cancelado = 0;
    int comprar_asientos;
    int nombre_existente = 0;
    int asientos_disponibles_count = 0;
    char input[10];
    int asiento_valido = 1;
    int asiento_disponible = 0;
    int asiento_comprado = 0;
   
    
    while (1) {
        system("cls");
        clrscr();
        gotoxy(20, 2);
        printf("AEROLINE - IES \n");
        printf("                                                __|__\n");
        printf("                                         ------oo(_)oo------\n");
        printf("\n");
        textcolor(LIGHTGREEN);
        gotoxy(2, 4);
        cprintf("1. ");
        textcolor(WHITE);
        gotoxy(4, 4);
        cprintf("PRESENTACION");
        textcolor(LIGHTGREEN);
        gotoxy(2, 6);
        cprintf("2. ");
        textcolor(WHITE);
        gotoxy(4, 6);
        cprintf("COMPRAR BOLETO");
        textcolor(LIGHTGREEN);
        gotoxy(2, 8);
        cprintf("3. ");
        textcolor(WHITE);
        gotoxy(4, 8);
        cprintf("VER FACTURA");
        textcolor(LIGHTGREEN);
        gotoxy(2, 10);
        cprintf("4. ");
        textcolor(WHITE);
        gotoxy(4, 10);
        cprintf("CANCELAR BOLETOS");
        textcolor(LIGHTGREEN);
        gotoxy(2, 12);
        cprintf("5. ");
        textcolor(WHITE);
        gotoxy(4, 12);
        cprintf("ASIENTOS DISPONIBLES");
        textcolor(LIGHTGREEN);
        gotoxy(2, 14);
        cprintf("6. ");
        textcolor(WHITE);
        gotoxy(4, 14);
        cprintf("SALIR");
        printf("\n\n\tPresione una opcion: ");


        scanf("%s", input);

        if (strlen(input) != 1 || !isdigit(input[0])) {
      
            printf("\n\n\tOpcion no valida.\n");
            getch();
            continue;
        }

   
        opcion = atoi(input);

        nombre_existente = 0;

        switch (opcion) 
        {

            case 1:
                Presentacion();
                getch();
                break;
            case 2:
                system("cls");
                if (num_facturas < 10) {
                    printf("Ingrese nombre: ");
                    while (1) {
                        scanf("%s", nuevo_usuario.nombre);
                        if (strlen(nuevo_usuario.nombre) > 3) {
                            break;
                        } else {
                            printf("El nombre debe tener mas de 3 caracteres. \nIntentelo de nuevo: ");
                        }
                    }

                    for (i = 0; i < num_facturas; i++) {
                        if (strcmp(facturas[i].usuario.nombre, nuevo_usuario.nombre) == 0) {
                            nombre_existente = 1;
                            break;
                        }
                    }

                    if (nombre_existente) {
                        printf("El nombre de usuario ya existe. Elija otro nombre.\n");
                        getch();
                        break;
                    }

                    printf("Ingrese apellido: ");
                    while (1) {
                        scanf("%s", nuevo_usuario.apellido);
                        if (strlen(nuevo_usuario.apellido) > 3) {
                            break;
                        } else {
                            printf("El apellido debe tener mas de 3 caracteres. \nIntentelo de nuevo: ");
                        }
                    }

                    printf("Ingrese telefono: ");
                    while (1) {
                        scanf("%s", nuevo_usuario.telefono);
                        if (strlen(nuevo_usuario.telefono) == 8) {
                            
                            int esCero = 1;
                            for (i = 0; i < 7; i++) {
                                if (nuevo_usuario.telefono[i] != '0') {
                                    esCero = 0;
                                    break;
                                }
                            }
                            if (esCero) {
                                printf("El numero no puede ser '00000000'. \nIntentelo de nuevo: ");
                                getch();
                                
                            } 

                            else {
                                break;
                            }
                        } else {
                            printf("El numero de telefono debe tener 7 digitos. \nIntentelo de nuevo: ");
                            getch();
                            
                        }
                    }

                    printf("Ingrese correo electronico (termina en @gmail.com): ");
                    while (1) {
                        scanf("%s", nuevo_usuario.correo);
                        if (strlen(nuevo_usuario.correo) > 5 && validarCorreo(nuevo_usuario.correo)) {
                            break;
                        } else {
                            printf("El correo debe tener mas de 5 caracteres y terminar en @gmail.com. \nIntentelo de nuevo: ");
                        }
                    }

                    nuevo_usuario.asientos_comprados[0] = 0;
                    nuevo_usuario.asientos_comprados[1] = 0;
                    nuevo_usuario.asientos_comprados[2] = 0;

                    do
                    {

                        system("cls");
                        printf("Cuantos asientos desea comprar? (maximo 3): ");
                        if (scanf("%d", &num_asientos) != 1) {
                        printf("Caracter no valido. Debe ingresar un numero.\n");
                        while (getchar() != '\n');
                        continue;
                        }
                        if(num_asientos < 0||num_asientos > 3)
                        {
                        printf("Ingrese un numero de asientos valido");
                        delay(1500);
                        system("cls");

                        }
                    
                    } while (num_asientos < 0||num_asientos > 3);
                    

                    asientos_disponibles_count = 0;
                    for (i = 0; i < 10; i++) {
                        if (asientos_disponibles[i] != 0) {
                            asientos_disponibles_count++;
                        }
                    }

                    if (num_asientos <= 3 && num_asientos > 0) {
        if (num_asientos > asientos_disponibles_count) {
            printf("No hay suficientes asientos disponibles. Actualmente solo hay %d asiento(s) disponible(s).\n", asientos_disponibles_count);
        } else {
            printf("Asientos disponibles: ");
            for (i = 0; i < 10; i++) {
                if (asientos_disponibles[i] != 0) {
                    printf("%d ", asientos_disponibles[i]);
                }
            }
                        for (i = 0; i < num_asientos; i++) {
                            printf("\nElija el asiento %d: ", i + 1);
                            
                            if (scanf("%d", &asiento_elegido) != 1) {
                                printf("Caracter no valido. Debe ingresar un numero.\n");
                                while (getchar() != '\n');
                                i--;
                                continue;
                            }
                            
                            
                            for (j = 0; j < 10; j++) {
                                if (asientos_disponibles[j] == asiento_elegido) {
                                    asiento_disponible = 1;
                                    break;
                                }
                            }
                            
                            if (asiento_disponible) {
                                for (j = 0; j < num_facturas; j++) {
                                    for (k = 0; k < 3; k++) {
                                        if (facturas[j].usuario.asientos_comprados[k] == asiento_elegido) {
                                            printf("El asiento %d ya ha sido comprado por otro usuario (%s).\n", asiento_elegido, facturas[j].usuario.nombre);
                                            asiento_disponible = 0;
                                            break;
                                        }
                                    }
                                    if (!asiento_disponible) {
                                        break; 
                                    }
                                }
                            }
                            
                            if (asiento_disponible) {
                                nuevo_usuario.asientos_comprados[i] = asiento_elegido;
                                for (j = 0; j < 10; j++) {
                                    if (asientos_disponibles[j] == asiento_elegido) {
                                        asientos_disponibles[j] = 0;
                                        break;
                                    }
                                }
                            } else {
                                printf("El asiento %d no esta disponible. Elija otro asiento.\n", asiento_elegido);
                                i--;
                            }
                        }

                            strcpy(nueva_factura.fecha, "Fecha de compra");
                            nueva_factura.usuario = nuevo_usuario;
                            nueva_factura.asientos_restantes = 3 - num_asientos;

                            facturas[num_facturas] = nueva_factura;
                            num_facturas++;
                        }
                    } else {
                        printf("Maximo de asientos excedido.\n");
                    }
                } else {
                    printf("Límite de facturas alcanzado.\n");
                }
                getch();
                break;
            case 3:
    system("cls");
    printf("Ingrese el nombre del usuario: ");
    scanf("%s", nombre_buscar);

    for (i = 0; i < num_facturas; i++) {
        if (strcmp(facturas[i].usuario.nombre, nombre_buscar) == 0) {
            printf("=========================================\n");
            printf("          FACTURA DE VENTA\n");
            printf("=========================================\n");

            printf("Fecha: %s\n", facturas[i].fecha);
            printf("\n");
            printf("Nombre: %s %s\n", facturas[i].usuario.nombre, facturas[i].usuario.apellido);
            printf("\n");
            printf("Telefono: %s\n", facturas[i].usuario.telefono);
            printf("\n");
            printf("Correo electronico: %s\n", facturas[i].usuario.correo);
            printf("\n");
            printf("Asientos comprados: ");
            for (j = 0; j < 3; j++) {
                if (facturas[i].usuario.asientos_comprados[j] != 0) {
                    printf("%d ", facturas[i].usuario.asientos_comprados[j]);

      
                    for (k = 0; k < 10; k++) {
                        if (asientos_disponibles[k] == facturas[i].usuario.asientos_comprados[j]) {
                            asientos_disponibles[k] = 0;
                        }
                    }
                }
            }
            printf("\n");

            if (facturas[i].asientos_restantes > 0) {
                printf("Deseas comprar los asientos restantes (%d)? (1: Si, 0: No): ", facturas[i].asientos_restantes);
                scanf("%d", &comprar_asientos);

                if (comprar_asientos == 1) {
                    for (j = 0; j < facturas[i].asientos_restantes; j++) {
                        printf("Elija el asiento adicional %d: ", j + 1);
                        scanf("%d", &asiento_elegido);

                    
                       
                        for (k = 0; k < 3; k++) {
                            if (facturas[i].usuario.asientos_comprados[k] == asiento_elegido) {
                                asiento_comprado = 1;
                                break;
                            }
                        }

                        if (!asiento_comprado) {
                          
                            int asiento_disponible = 0;
                            for (k = 0; k < 10; k++) {
                                if (asientos_disponibles[k] == asiento_elegido) {
                                    asiento_disponible = 1;
                                    break;
                                }
                            }

                            if (asiento_disponible) {
                                facturas[i].usuario.asientos_comprados[3 - facturas[i].asientos_restantes + j] = asiento_elegido;
                                facturas[i].asientos_restantes--;

                              
                                for (k = 0; k < 10; k++) {
                                    if (asientos_disponibles[k] == asiento_elegido) {
                                        asientos_disponibles[k] = 0;
                                    }
                                }
                            } else {
                                printf("El asiento %d no está disponible. Elija otro asiento.\n", asiento_elegido);
                                j--;
                            }
                        } else {
                            printf("El asiento %d ya ha sido comprado por este usuario.\n", asiento_elegido);
                        }
                    }
                }
            }
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Usuario no encontrado.\n");
    }
    getch();
    break;


            case 4:
                system("cls");
                printf("Ingrese el nombre del usuario: ");
                scanf("%s", nombre_cancelar);

                for (i = 0; i < num_facturas; i++) {
                    if (strcmp(facturas[i].usuario.nombre, nombre_cancelar) == 0) {
                        printf("Asientos comprados por %s %s: ", facturas[i].usuario.nombre, facturas[i].usuario.apellido);
                        for (j = 0; j < 3; j++) {
                            if (facturas[i].usuario.asientos_comprados[j] != 0) {
                                printf("%d ", facturas[i].usuario.asientos_comprados[j]);
                            }
                        }
                        printf("\nElija el asiento a cancelar: ");
                        scanf("%d", &asiento_elegido);

                        for (j = 0; j < 3; j++) {
                            if (facturas[i].usuario.asientos_comprados[j] == asiento_elegido) {
                                facturas[i].usuario.asientos_comprados[j] = 0;
                                asiento_cancelado = asiento_elegido;
                                break;
                            }
                        }

                        if (asiento_cancelado > 0) {
                            for (k = 0; k < 10; k++) {
                                if (asientos_disponibles[k] == 0) {
                                    asientos_disponibles[k] = asiento_cancelado;
                                    break;
                                }
                            }
                            printf("Asiento %d cancelado exitosamente.\n", asiento_cancelado);
                        } else {
                            printf("Asiento no encontrado o no se pudo cancelar.\n");
                        }
                        encontrado = 1;
                        break;
                    }
                }
                if (!encontrado) {
                    printf("Usuario no encontrado.\n");
                }
                getch();
                break;
            case 5:
                system("cls");
                printf("Asientos disponibles:\n");
                for (i = 0; i < 10; i++) {
                    if (asientos_disponibles[i] != 0) {
                        printf("Asiento %d\n", asientos_disponibles[i]);
                    }
                }
                getch();
                break;
            case 6:
                clrscr();
                adios();
                getch();
                exit(0);
                free(facturas);
                break;
            default:
                printf("Opcion no valida.\n");
                getch();
        }
    }

    free(facturas);


}
