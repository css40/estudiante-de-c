#include <stdio.h>
#include <conio.h>

int main() {
    int edad, opc, op;
    float promedio;
    float beca = 0.0;
    int num1, num2, num3, numero;
    float califi, asistencias;
	clrscr();
    printf("\n\tElije una opcion \n");
    printf("\n\t1.aprobados \n");
    printf("\n\t2.numeros \n");
    printf("\n\t3.becas \n");
    printf("\n\t4.salir \n");
    scanf("%d", &opc);
	clrscr();

    switch (opc) {
		clrscr();
        case 1: /* aprobados */
            printf("ingrese la calificacion del alumno: \n");
            scanf("%f", &califi);
            printf("ingrese el porcentaje de asistencias del alumno: \n");
            scanf("%f", &asistencias);
            if (califi >= 70 && asistencias >= 80) {
                printf("el alumno esta aprobado \n");
            } else {
                printf("el alumno esta reprobado: \n");
            }
			getch();
            break;
			
        case 2: /* submenu de numeros */
			clrscr();
            printf("\n\tElije una opcion \n");
            printf("\n\t1.valor intermedio \n");
            printf("\n\t2.cantidad de digitos\n");
            printf("\n\t3.salir \t");
            scanf("%d", &op);
			clrscr();
            switch (op) {
                case 1:
                    printf("ingrese el primer numero\n");
                    scanf("%d", &num1);
                    printf("ingrese el segundo numero\n");
                    scanf("%d", &num2);
                    printf("ingrese el tercer numero\n");
                    scanf("%d", &num3);
                    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3)) {
                        printf("el numero intermedio es %d\n", num1);
                    } else if ((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3)) {
                        printf("el numero intermedio es %d\n", num2);
                    } else {
                        printf("el numero intermedio es %d\n", num3);
                    }
					getch();
                    break;
					
                case 2:
                    printf("ingrese un numero entero menor a mil \n");
                    scanf("%d", &numero);
                    if (numero >= 0 && numero < 1000) {
                        int digitos = 0;
                        int tn = numero;
                        while (tn > 0) {
                            tn /= 10;
                            digitos++;
                        }
                        printf("el numero %d tiene %d digitos \n", numero, digitos);
                    } else {
                        printf("el numero ingresado no es valido, debe ser menor a 1000\n");
                    }
					getch();
                    break;
					
                default:
                    printf("Saliendo del programa\n");
                    break;
					
            }
            break;
        case 3: /* becas */
			clrscr();
            printf("Ingrese la edad del estudiante: ");
            scanf("%d", &edad);
            printf("Ingrese el promedio del estudiante: ");
            scanf("%f", &promedio);
			clrscr();

            if (edad > 18) {
                if (promedio >= 9.0) {
                    beca = 2000.0;
                } else if (promedio >= 7.5) {
                    beca = 1000.0;
                } else if (promedio >= 6.0) {
                    beca = 500.0;
                }
            } else {
                if (promedio >= 9.0) {
                    beca = 3000.0;
                } else if (promedio >= 8.0) {
                    beca = 2000.0;
                } else if (promedio >= 6.0) {
                    beca = 100.0;
                }
            }

            if (beca > 0) {
                printf("El estudiante recibe una beca de $%.2f\n", beca);
            } else {
                printf("El estudiante no cumple con los criterios para recibir una beca.\n");
                printf("Se le envía una carta de invitación para estudiar más.\n");
            }
			getch();
            break;
        case 4:
            printf("saliendo del programa");
            break;
        default:
            printf("Opción no válida.\n");
			getch();
            break;
			
    }
    return 0;
}	getch();
