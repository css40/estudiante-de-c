/*  El presidente de la república ha decidido estimular a todos los 
    estudiantes de una universidad mediante la asignación de becas mensuales
    para esto se tomarán en consideración los siguientes criterios:  Para 
    alumnos mayores de 18 años con promedio mayor o igual a 9  la beca será 
    de $2000.00; con promedio mayor o igual a 7.5  de $1000.00; para los promedios
    menores de 7.5 pero mayores o iguales a 6.0  de $500.00; a los demás se les 
    enviará una carta de invitación incitándolos a que estudien más en el próximo c
    iclo escolar. A los alumnos de 18 años o menores de esta edad con promedios mayores
    o iguales a 9 se les dará $3000; con promedios menores a 9 pero mayores o iguales
    a 8 $2000; para los alumnos con promedios menores a 8 pero mayores o iguales a 6
    e les dará $100 y a los alumnos que tengan promedios menores a 6 se les enviará
    carta de invitación. 
*/



#include <stdio.h>

int main() {
    int edad;
    float promedio;
    float beca = 0.0;


    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &edad);
    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &promedio);


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

    return 0;
}
