#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct nodo
{
    char nombre[30];
    struct nodo *siguiente;
} nodo;

nodo *table[26];
nodo *crear_nodos();

void buscar(void);
void liberacion(void);
int hash(string nombre);

int main()
{
    string nombre;
    int posicion;
    nodo *p;
    // Agregamos datos a nuestra ht
    for (int i = 0; i < 5; i++)
    {
        p = crear_nodos();
        posicion = hash(p->nombre);
        // ingresamos en la cubeta correcta
        // table[posicion] funciona como nuestro nodo cabeza
        p->siguiente = table[posicion];
        table[posicion] = p;
    }
    for (int i = 0; i < 26; i++)
    {
        for (nodo *j = table[i]; j != NULL; j = j->siguiente)
        {
            printf("%s\n", j->nombre);
        }
    }
    char pregunta = get_char("¿Quiere buscar a alguien? S/N: ");
    if(pregunta != 'N' && pregunta !='n')
    {
        buscar();
    }
    printf("Adios :D\n");
    liberacion();
}

/*la funcion hash se encarga de evaluar en que
cubeta debe estar mi palabra*/
int hash(string nombre)
{
    nombre[0] = toupper(nombre[0]);
    int posicion = nombre[0] - 65;
    return posicion;
}

nodo *crear_nodos()
{
    nodo *tmp = malloc(sizeof(nodo));
    tmp->siguiente = NULL;
    string nombre = get_string("Ingrese su nombre: ");
    strcpy(tmp->nombre, nombre);
    return tmp;
}

void buscar(void)
{
    string nombre = get_string("Escriba el nombre de la persona que quiere buscar: ");
    int posicion = hash(nombre);
    for(nodo*i=table[posicion]; i!=NULL; i=i->siguiente)
    {
        if(strcmp(nombre, i->nombre) == 0)
        {
            printf("Se encontró a %s en la lista\n", i->nombre);
            return;
        }
    }
    printf("No se encontró a %s en la lista\n", nombre);
}

void liberacion(void)
{
    nodo * aux;
    for(int i = 0; i<26; i++)
    {
        while(table[i] !=NULL)
        {
            aux = table[i]->siguiente;
            free(table[i]);
            table[i] = aux;
        }
    }
}