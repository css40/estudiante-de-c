# Prácticas de programación en C

En este repositorio fui guardando ejercicios y proyectos que he hecho para practicar C. Hay tareas de los temas iniciales de la materia y también programas más grandes, algunos con gráficos. Cada archivo suele ser un ejercicio independiente.

## ¿Qué hay?

- **`c_if_etc/`**: tareas de secuencias, decisiones con `if` y menús con `switch`. Hay ejercicios de operaciones, áreas, sueldos, tarjetas y otros problemas de clase. También están las guías originales en Word.
- **`ejercisios/`**: prácticas de operaciones matemáticas, arreglos, cadenas, notas y promedios, entre otras.
- **`cgrafico/`**: 113 ejercicios numerados para practicar gráficos: líneas, figuras, píxeles, colores, texto y algunas funciones de mouse.
- **`cajero/`, `inventario/` y `sistema-aero/`**: proyectos de consola con menús, inicio de sesión y funciones de cajero, inventario y reservación de asientos.
- **`casino/`, `libro-grafico/` y `juegos_aparte/`**: programas y pruebas de juegos como ruleta, billar, cartas, parchís, damas y futbolito.
- **`cara_c/` y `more-c/`**: otros programas y pruebas que fui agregando mientras practicaba.

## Cómo probar los ejercicios

No hay una sola aplicación ni una suite automática de pruebas: son programas separados. Para probar uno de los ejercicios sencillos en C, por ejemplo:

```bash
gcc c_if_etc/if/1.c -o prueba
./prueba
```

El programa pide los datos por consola. Se puede comprobar con valores distintos y revisar que el resultado tenga sentido; por ejemplo, en el ejercicio que clasifica un número, probar un valor positivo, uno negativo y el cero. En los ejercicios de menús también conviene probar una opción válida y una que no exista.

Las carpetas de gráficos y varios proyectos más antiguos usan bibliotecas como `graphics.h`, `conio.h` y `dos.h`. Algunos están hechos para Turbo C/Borland y tienen rutas de esa época, así que no necesariamente compilan directamente con GCC moderno. Para probarlos hace falta un entorno compatible con esas bibliotecas.

## Qué he practicado

Con estas tareas he trabajado la entrada y salida de datos, variables y operaciones, condiciones, ciclos, arreglos, cadenas y menús. En los proyectos más grandes practiqué organizar un programa en funciones y combinar varias partes para resolver una tarea.
