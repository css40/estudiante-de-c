#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

#define max_alumnos 40
#define min_alumnos 5
#define max_asignaturas 7
#define min_asignaturas 1

int main()
{

    int i, j, cantidad_alumnos, cant_asignaturas;
    char nombres[max_alumnos][50];
    char nombreasignatura[50];
    float promedios[max_alumnos];
    float sumadenotas = 0.0;
    float nota;
    clrscr();

    do
    {
        printf("Ingrese la cantidad de alumnos(entre %d y %d): \n", min_alumnos, max_alumnos);
        scanf("%d", &cantidad_alumnos);
    } while (cantidad_alumnos < min_alumnos || cantidad_alumnos > max_alumnos);

    for (i = 0; i < cantidad_alumnos; i++)
    {
        printf("Ingrese el nombre del estudiante %d:\n" i + 1);
        scanf("%d", nombres[i]);

        do
        {
            printf("Ingrese la cantidad de asignaturas para %s (entre %d y %d)\n", nombres[i], min_asignaturas, max_asignaturas);
            scanf("%d", &cant_asignaturas);

        } while (cant_asignaturas < min_asignaturas || cant_asignaturas > max_asignaturas);

        for (j = 0; j < cant_asignaturas; j++)
        {

            printf("Ingrese el nombre de la asignatura %d para %s : \n", j + 1, nombres[i] );
            scanf("%s", nombreasignatura);

            do
            {
                printf("Ingrese la nota para %s en %s (entre 0 a 100): ", nombres[i], nombreasignatura);
                scanf("%f", &nota);
            } while (nota < 0 || nota > 100);

            sumadenotas += nota;
        }

        promedios[i] = sumadenotas / cant_asignaturas;
    }

    printf("\nReporte de Promedios:\n");
    for (i = 0; i < cantidad_alumnos; i++)
    {
        printf("Estudiante: %s - promedio: %.2f\n", nombres[i], promedios[i]);
    }

    getch();
    return 0;
}