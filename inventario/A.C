
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <ctype.h>
#include <static.h>


void login(void);
void menu();
void animacion(void);
void espada(void);

struct Producto 
{
    int codigo;
    char nombre[50];
    int cantidad;
    float precio;
    char categoria[20];
};

int i,j;
int opcionCategoria;
/*struct Producto productos[100];
int numProductos = 0;*/

int main()
{
    int i,x,y,clic,pasar,puntos,nivel;
    char tecla;
    int adap=DETECT;
    int tarj;
    struct Producto productos[100];
    int numProductos = 0;
    initgraph(&adap,&tarj,"");
    animacion();
    espada();
    closegraph();
    getch();

    login(); 
    menu(productos, &numProductos);
    return 0;
}

void espada()
{
	int punta[6] = {306, 99, 313, 83, 320, 99};
	int mango[16] = {308, 100,308, 108,305, 108,305, 140,322, 140,321, 110,318, 110,318, 100};
	int filo [36] = {285, 140,341, 153,301, 154,302, 292,305, 292,305, 301,307, 301,308, 310,311, 309,312, 318,315, 318,315, 310,317, 310,318, 302,322, 302,322, 293,325, 293,324, 153};

	setcolor(16);/*punta*/
	setfillstyle(1, 43);
	fillpoly(3, punta);

	setcolor(16);/*agarradero*/
	setfillstyle(1, 6);
	fillpoly(8, mango);

	setfillstyle(1, 43);
	bar(285, 140, 341, 153);

	setcolor(16);/*espada*/
	setfillstyle(1, 24);
	fillpoly(18, filo);

	getch();
}
void animacion()
{
	int i; 

	for (i=1; i<=100; i++)
	{
		setcolor(15);
		setfillstyle(1, 15);
		circle(320, 240, 1+i);
		floodfill(321, 241, 15);
		cleardevice();
	}
	setcolor(15);
	outtextxy(290, 400, "graphics.h");
	delay(400);
	cleardevice();

	setcolor(28);
	outtextxy(290, 400, "graphics.h");
	delay(400);
	cleardevice();

	setcolor(24);
	outtextxy(290, 400, "graphics.h");
	delay(400);
	cleardevice();

	setcolor(20);
	outtextxy(290, 400, "graphics.h");
	delay(400);
	cleardevice();

	setcolor(18);
	outtextxy(290, 400, "graphics.h");
	delay(400);
	cleardevice();

	setcolor(15);
	outtextxy(298, 400, "--Presenta--");

	sleep(2);

	for (i=330; i<=640; i++)
	{
		setfillstyle(1, 4);
		bar(330, 100, i, 140);
		delay(2);
	}

	for (i=620; i>=0; i--)
	{
		setfillstyle(1, 4);
		bar(640, 180, i, 220);
		delay(2);
	}

	for (i=20; i<=320; i++)
	{
		setfillstyle(1, 4);
		bar(0, 260, i, 300);
		delay(2);
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
    	cprintf("\n                \t\tBIENVENIDO A NUESTRA APLICACIoN!\t\t");
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
            /*runProgressBar();*/
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



/*Funcion para agregar un producto*/
void agregarProducto(struct Producto productos[], int *numProductos) {
    if (*numProductos < 100) {
        struct Producto nuevoProducto;
        int codigoExistente;
        char nombreExistente=0;
        char codigoEntrada[50];
        int soloDigitos = 1;
        system("cls");
                do {
                    codigoExistente = 0;
                    system("cls");
                    printf("\nCodigo del producto: ");
                    if (scanf("%d", &nuevoProducto.codigo) != 1) 
                    {
                        printf("El codigo debe ser un numero entero. Por favor, ingrese otro codigo.\n");
                        while (getchar() != '\n'); 
                    } else {
                        /* Validamos si el codigo ya existe */
                        for (i = 0; i < *numProductos; i++) {
                            if (productos[i].codigo == nuevoProducto.codigo) {
                                codigoExistente = 1;
                                break;
                            }
                        }

                        if (codigoExistente) {
                            printf("El codigo ingresado ya existe. Por favor, ingrese otro codigo.\n");
                            getch();
                            system("cls");
                        } else {
                            break; 
                        }
                    }
                } while (1);
                
            do {
                    nombreExistente = 0; 
                    printf("\nNombre del producto: ");
                    scanf("%s", nuevoProducto.nombre);
                    
                    /* Validamos si el nombre ya existe */
                    for (i = 0; i < *numProductos; i++) {
                        if (strcmp(productos[i].nombre, nuevoProducto.nombre) == 0) {
                            nombreExistente = 1;
                            break;
                        }
                    }

                    if (nombreExistente) {
                        printf("El nombre ingresado ya existe. Por favor, ingrese otro nombre.\n");
                    } else {
                        break; 
                    }
            } while (1);

       do {
            printf("\nCantidad de ingreso de producto: ");
            if (scanf("%d", &nuevoProducto.cantidad) != 1 || nuevoProducto.cantidad <= 0) {
                printf("La cantidad debe ser un numero positivo mayor que cero. \nPor favor, intente de nuevo.\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        } while (1);

        
        do {
            printf("\nPrecio del producto: ");
            if (scanf("%f", &nuevoProducto.precio) != 1 || nuevoProducto.precio <= 0) {
                printf("El precio debe ser un numero positivo mayor que cero. \nPor favor, intente de nuevo.\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        } while (1);

        
        /* Mostrar y seleccionar la categoria del producto*/
           do {
                printf("\nCategorias disponibles:\n");
                 printf("--------------------------\n");
                printf("1. Electrodomesticos\n");
                 printf("--------------------------\n");
                printf("2. Ropa\n");
                 printf("--------------------------\n");
                printf("3. Alimentos\n");
                 printf("--------------------------\n");
                printf("Seleccione la categoria del producto: ");

                if (scanf("%d", &opcionCategoria) != 1) {
                    printf("Ingrese un numero correspondiente a una categoria existente.\n");
                    while (getchar() != '\n'); 
                    continue;
                }

                switch (opcionCategoria) 
                {
                    case 1:
                        strcpy(nuevoProducto.categoria, "Electrodomesticos");
                        break;
                    case 2:
                        strcpy(nuevoProducto.categoria, "Ropa");
                        break;
                    case 3:
                        strcpy(nuevoProducto.categoria, "Alimentos");
                        break;
                    default:
                        printf("Categoria no valida. Seleccione una categoria existente.\n");
                        continue;
                }

                break; 
                

    } while (1);

        productos[*numProductos] = nuevoProducto;
        (*numProductos)++;
        printf("\nProducto agregado con exito.\n");
        getch();

    } else 
    {
        printf("No se pueden agregar mas productos. Limite alcanzado.\n");

    }
}

/* Funcion para actualizar un producto */
void actualizarProducto(struct Producto productos[], int numProductos) 
{
    int codigo;
    int opcionCampo;
    system("cls");
    printf("\nIngrese el codigo del producto a actualizar: ");
    scanf("%d", &codigo);

    /* Busqueda de el producto por codigo */
    for (i = 0; i < numProductos; i++) 
    {
        if (productos[i].codigo == codigo) 
        {
            printf("\nProducto encontrado. Seleccione el campo a actualizar:\n");
            printf("--------------------------\n");
            printf("1. Nombre del producto\n");
            printf("--------------------------\n");
            printf("2. Cantidad del producto\n");
            printf("--------------------------\n");
            printf("3. Precio del producto\n");
            printf("--------------------------\n");
            printf("4. Categoria del producto\n");
            printf("--------------------------\n");
            printf("Ingrese una opcion: ");
            
            scanf("%d", &opcionCampo);

            switch (opcionCampo) {
                case 1:
                    printf("\nIngrese el nuevo nombre del producto: ");
                    scanf("%s", productos[i].nombre);
                    printf("Nombre actualizado con exito.\n");
                    break;
                case 2:
                    printf("\nIngrese la nueva cantidad de producto: ");
                    scanf("%d", &productos[i].cantidad);
                    printf("Cantidad actualizada con exito.\n");
                    break;
                case 3:
                    printf("\nIngrese el nuevo precio del producto: ");
                    scanf("%f", &productos[i].precio);
                    printf("Precio actualizado con exito.\n");
                    break;
                case 4:
                system("cls");
                    printf("--------------------------\n");
                    printf("\nCategorias disponibles:\n");
                    printf("--------------------------\n");
                    printf("    1. Electrodomesticos\n");
                    printf("--------------------------\n");
                    printf("    2. Ropa\n");
                    printf("--------------------------\n");
                    printf("    3. Alimentos\n");
                    printf("--------------------------\n");

                    printf("Seleccione la nueva categoria del producto:\n");
                    scanf("%d", &opcionCategoria);

                    switch (opcionCategoria) {
                        case 1:
                            strcpy(productos[i].categoria, "Electrodomesticos");
                            printf("Categoria actualizada con exito.\n");
                            getch();
                            break;
                        case 2:
                            strcpy(productos[i].categoria, "Ropa");
                            printf("Categoria actualizada con exito.\n");
                            getch();
                            break;
                        case 3:
                            strcpy(productos[i].categoria, "Alimentos");
                            printf("Categoria actualizada con exito.\n");
                            getch();
                            menu();
                            break;
                        default:
                            printf("Categoria no valida.\n");
                            break;
                    }
                    break;
                default:
                    printf("Opcion incorrecta.\n");
                    break;
            }
            return;
        }
    }

    printf("Producto no encontrado.\n");
    getch();
}

/* Funcion para eliminar un producto */
void eliminarProducto(struct Producto productos[], int *numProductos) {
    int codigo;
    system("cls");
    printf("\nIngrese el codigo del producto a eliminar: ");
    scanf("%d", &codigo);
    
    for (i = 0; i < *numProductos; i++) {
        if (productos[i].codigo == codigo) {
            int opcionEliminar;
            printf("Producto encontrado. Desea eliminar el producto completo o solo una unidad?\n");
            printf("\n--------------------------\n");
            printf("1. Eliminar producto completo\n");
            printf("--------------------------\n");
            printf("2. Eliminar una unidad\n");
            printf("--------------------------\n");
            printf("\nIngrese una opcion: ");
            scanf("%d", &opcionEliminar);

            if (opcionEliminar == 1) {
                for (j = i; j < *numProductos - 1; j++) {
                    productos[j] = productos[j + 1];
                }
                (*numProductos)--;
                printf("Producto eliminado completamente.\n");
                getch();
                return;
            } else if (opcionEliminar == 2) {
                if (productos[i].cantidad > 1) {
                    int cantidadEliminar;
                    printf("Ingrese la cantidad a eliminar (hasta %d unidades): ", productos[i].cantidad);
                    scanf("%d", &cantidadEliminar);

                    if (cantidadEliminar >= productos[i].cantidad || cantidadEliminar <= 0) {
                        printf("Cantidad ingresada incorrecta o mayor a la existente. No se ha eliminado nada.\n");
                        getch();
                        return;
                    }

                    productos[i].cantidad -= cantidadEliminar;
                    printf("Se han eliminado %d unidades del producto con codigo %d.\n", cantidadEliminar, productos[i].codigo);
                    getch();
                    return;
                } else {
                    printf("No se pueden eliminar mas unidades. El producto tiene solo una unidad.\n");
                    getch();
                    return;
                }
            } else {
                printf("Opcion incorrecta.\n");
                return;
            }
        }
    }

    printf("Producto no encontrado.\n");
}


/*Funcion para buscar un producto por codigo o nombre*/
void buscarProducto(struct Producto productos[], int numProductos) {
    int opcion;
    int codigo;
    char nombreBusqueda[50];
    int encontrado = 0;
    system("cls");
    printf("--------------------------\n");
    printf("\n       Buscar por:\n");
    printf("--------------------------\n");
    printf("\n1.     Codigo\n");
    printf("--------------------------\n");
    printf("\n2.    Nombre\n");
    printf("--------------------------\n");
    printf("\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("\nIngrese el codigo del producto: ");
        scanf("%d", &codigo);

        

        for ( i = 0; i < numProductos; i++) {
            if (productos[i].codigo == codigo) {
                encontrado = 1;
                printf("--------------------------\n");
                printf("\nProducto encontrado:\n");
                printf("--------------------------\n");
                printf("Codigo: %d\n", productos[i].codigo);
                printf("Nombre: %s\n", productos[i].nombre);
                printf("Cantidad: %d\n", productos[i].cantidad);
                printf("Precio: %.2f\n", productos[i].precio);
                printf("Categoria: %s\n", productos[i].categoria);
                printf("--------------------------\n");
                getch();
                return;
            }
        }

        if (!encontrado) {
            printf("\nProducto no encontrado.\n");
            getch();
            return;
        }
    } else if (opcion == 2) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombreBusqueda);

        

        for (i = 0; i < numProductos; i++) {
            if (strcmp(productos[i].nombre, nombreBusqueda) == 0) {
                encontrado = 1;
                printf("\nProducto encontrado:\n");
                printf("--------------------------\n");
                printf("Codigo: %d\n", productos[i].codigo);
                printf("Nombre: %s\n", productos[i].nombre);
                printf("Cantidad: %d\n", productos[i].cantidad);
                printf("Precio: %.2f\n", productos[i].precio);
                printf("Categoria: %s\n", productos[i].categoria);
                printf("--------------------------\n");
                getch();
                return;
            }
        }

        if (!encontrado) {
            printf("\nProducto no encontrado.\n");
            getch();
            return;
        }
    } else {
        printf("Opcion no valida.\n");
        getch();
        menu();
    }
}


 
/*funcion de venta*/
void realizarVenta(struct Producto productos[], int numProductos) {
    int codigo;
    int cantidadVenta;
    float subtotal, iva, total;
    char deseaComprarOtro = 's';
    int i = 0;

    system("cls");

    while (deseaComprarOtro == 's' || deseaComprarOtro == 'S') {
        int encontrado = 0;

        printf("\nIngrese el codigo del producto a vender: ");
        scanf("%d", &codigo);

        for (i = 0; i < numProductos; i++) {
            if (productos[i].codigo == codigo) {
                encontrado = 1;

                if (productos[i].cantidad == 0) {
                    printf("Este articulo esta agotado. Por favor, elija otro articulo.\n");
                    getch();
                    menu();
                    encontrado = 0;
                    break;
                }

                printf("\nProducto encontrado. Realizando la venta:\n");
                printf("--------------------------\n");
                printf(" Nombre del producto: %s\n", productos[i].nombre);
                printf("--------------------------\n");
                printf(" Cantidad disponible: %d\n", productos[i].cantidad);
                printf("--------------------------\n");
                printf(" Precio unitario: %.2f\n", productos[i].precio);
                printf("--------------------------\n");

                printf("Ingrese la cantidad a vender: ");
                scanf("%d", &cantidadVenta);

                if (cantidadVenta > productos[i].cantidad || cantidadVenta <= 0) {
                    printf("Cantidad ingresada incorrecta o mayor a la existente. Intente de nuevo.\n");
                    getch();
                    encontrado = 0;
                    break;
                }

                subtotal = productos[i].precio * cantidadVenta;
                iva = subtotal * 0.15;
                total = subtotal + iva;

                productos[i].cantidad -= cantidadVenta;
                system("cls");
                printf("-----------------------------------\n");
                printf(" Universidad  Nacional de Ingenieria:.\n");
                printf(" Instituto de Estudios Superiores.\n");
                printf("----------------------------------\n");
                printf("   RUC  J020102102151\n");
                printf("-------------------------------\n");
                printf(" FECHA 30/11/23  9:00 AM\n");
                printf("-------------------------------\n");
                printf("     Venta realizada:\n");
                printf("-------------------------------\n");
                printf(" Venta realizada con exito.\n");
                printf(" Subtotal: %.2f\n", subtotal);
                printf(" IVA (15%%): %.2f\n", iva);
                printf(" Total: %.2f\n", total);
                printf("-------------------------------\n");

                break;
            }
        }

        if (!encontrado) {
            printf("\nCodigo de producto no existente o agotado.\n");
            getch();
            continue;
        }

        printf("\nDesea comprar otro articulo? (s/n): ");
        scanf(" %c", &deseaComprarOtro);

        if (deseaComprarOtro != 's' && deseaComprarOtro != 'S') {
            printf("Gracias por su compra.\n");
            getch();
            return;
        }
    }
}

void menu() 
{
    struct Producto productos[100];
    int numProductos = 0;
    int opcion;
    system("cls");
    do 
	{  system("cls");
        clrscr();
        gotoxy(20, 2);
        printf("PROYECTO INVENTARIO\n");
        printf("\n");
        textcolor(LIGHTGREEN);
        gotoxy(2, 4);
        cprintf("1. ");
        textcolor(WHITE);
        gotoxy(4, 4);
        cprintf("AGREGAR PRODUCTO");
        textcolor(LIGHTGREEN);
        gotoxy(2, 6);
        cprintf("2. ");
        textcolor(WHITE);
        gotoxy(4, 6);
        cprintf("ACTUALIZAR PRODUCTO");
        textcolor(LIGHTGREEN);
        gotoxy(2, 8);
        cprintf("3. ");
        textcolor(WHITE);
        gotoxy(4, 8);
        cprintf("ELIMINAR PRODUCTO");
        textcolor(LIGHTGREEN);
        gotoxy(2, 10);
        cprintf("4. ");
        textcolor(WHITE);
        gotoxy(4, 10);
        cprintf("BUSCAR PRODUCTO");
        textcolor(LIGHTGREEN);
        gotoxy(2, 12);
        cprintf("5. ");
        textcolor(WHITE);
        gotoxy(4, 12);
        cprintf("REALIZAR VENTA");
        textcolor(LIGHTGREEN);
        gotoxy(2, 14);
        cprintf("6. ");
        textcolor(WHITE);
        gotoxy(4, 14);
        cprintf("SALIR");

        printf("\n\n\tPresione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Dato incorrecto. Ingrese un numero correspondiente a una opcion del menu.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (opcion) 
		{

            case 1:
                agregarProducto(productos, &numProductos);
                break;
            case 2:
                actualizarProducto(productos, numProductos);
                break;
            case 3:
                eliminarProducto(productos, &numProductos);
                break;
            case 4:
                buscarProducto(productos, numProductos);
                break;
            case 5:
                realizarVenta(productos, numProductos);
                break;
            case 6:
                printf("Saliendo del programa. Hasta luego!\n");
                system("cls");
                dujujodelogo();
                exit(0);
                break;    
            default:
                printf("Opcion incorrecta. Intentelo de nuevo.\n");
                getch();
        }
    } while (opcion != 6);
  getch();
    return 0;

}