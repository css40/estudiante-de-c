/*  Realiza un algoritmo que le diga al usuario 
    su tiempo de vida en: años,
    meses, semanas, 
    días, horas, minutos, segundos.
*/

#include <stdio.h>

int main() 
{
    long long edad_en_segundos;
    
    printf("Ingrese su edad en segundos: ");
    scanf("%lld", &edad_en_segundos);
    
    long long segundos_en_un_minuto = 60;
    long long segundos_en_una_hora = 60 * segundos_en_un_minuto;
    long long segundos_en_un_dia = 24 * segundos_en_una_hora;
    long long segundos_en_una_semana = 7 * segundos_en_un_dia;
    long long segundos_en_un_mes = 30 * segundos_en_un_dia;
    long long segundos_en_un_anio = 365 * segundos_en_un_dia;
    
    long long anios = edad_en_segundos / segundos_en_un_anio;
    long long meses = (edad_en_segundos % segundos_en_un_anio) / segundos_en_un_mes;
    long long semanas = (edad_en_segundos % segundos_en_un_mes) / segundos_en_una_semana;
    long long dias = (edad_en_segundos % segundos_en_una_semana) / segundos_en_un_dia;
    long long horas = (edad_en_segundos % segundos_en_un_dia) / segundos_en_una_hora;
    long long minutos = (edad_en_segundos % segundos_en_una_hora) / segundos_en_un_minuto;
    long long segundos = edad_en_segundos % segundos_en_un_minuto;
    
    /* Mostrar el resultado*/
    printf("Tu tiempo de vida es aproximadamente:\n");
    printf("Años: %lld\n", anios);
    printf("Meses: %lld\n", meses);
    printf("Semanas: %lld\n", semanas);
    printf("Días: %lld\n", dias);
    printf("Horas: %lld\n", horas);
    printf("Minutos: %lld\n", minutos);
    printf("Segundos: %lld\n", segundos);
    
    return 0;
}
/*long long = El tipo de dato `long long` en el lenguaje C 
se utiliza para representar números enteros más grandes que los que pueden ser representados por los tipos de datos 
`int` o `long`. Es una extensión del tipo `long` y permite almacenar enteros con una mayor amplitud.

El tipo `long long` es útil cuando necesitas trabajar con números enteros que pueden 
ser extremadamente grandes o cuando deseas garantizar que una variable puede almacenar números enteros muy grandes 
sin desbordamiento.

Aquí hay un ejemplo de cuándo podrías usar `long long`:

#include <stdio.h>

int main() {
    long long numero_grande = 1234567890123456789LL; // LL indica que el número es long long
    
    printf("Número grande: %lld\n", numero_grande);
    
    return 0;
}
```

En este ejemplo, `numero_grande` se declara como `long long` 
y se inicializa con un número extremadamente grande. La 'LL' al final del número literal indica al 
compilador que debe tratar ese número como un `long long`.

`long long` es especialmente útil en aplicaciones científicas y 
de ingeniería, así como en situaciones en las que se necesitan representar números enteros muy grandes, 
como cálculos financieros, operaciones con fechas y horas, y manipulación de números grandes en matemáticas o 
criptografía.*/
