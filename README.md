*Este proyecto ha sido creado como parte del currículo de 42 por jmaestre.*

# ft_printf

## Descripción

El objetivo de este proyecto es reimplementar la famosa función `printf()` de la librería estándar de C (`libc`). A través de este desarrollo, se explora el funcionamiento de las **funciones variádicas** en C utilizando las macros de `<stdarg.h>`, así como la gestión de formatos y conversiones numéricas/de caracteres.

El resultado es la librería estática `libftprintf.a`, la cual podrá ser reutilizada en futuros proyectos del currículo de 42.

### Especificadores de conversión soportados

La función tiene la siguiente forma:
```c
int ft_printf(char const *format, ...);
```

Soporta las siguientes conversiones:
- `%c`: Imprime un solo carácter.
- `%s`: Imprime una cadena de caracteres.
- `%p`: Imprime un puntero `void *` en formato hexadecimal.
- `%d`: Imprime un número decimal (base 10) con signo.
- `%i`: Imprime un entero en base 10.
- `%u`: Imprime un número decimal (base 10) sin signo.
- `%x`: Imprime un número hexadecimal (base 16) en minúsculas.
- `%X`: Imprime un número hexadecimal (base 16) en mayúsculas.
- `%%`: Imprime el símbolo del porcentaje.

---

## Instrucciones

### Compilación

El proyecto incluye un `Makefile` que compila la librería estática `libftprintf.a`.

Para compilar la parte obligatoria:
```bash
make
```

Otras reglas disponibles en el `Makefile`:
```bash
make clean    # Elimina los archivos objeto (.o)
make fclean   # Elimina los archivos objeto y la librería libftprintf.a
make re       # Ejecuta fclean y vuelve a compilar (rebuild)
make bonus    # Compila la librería incluyendo las funcionalidades bonus
```

### Uso e Integración

Para usar `ft_printf` en tu propio programa C:

1. Incluye el encabezado en tu código:
   ```c
   #include "ft_printf.h"
   ```

2. Compila tu programa enlazando la librería generada:
   ```bash
   gcc main.c -L. -llibftprintf -o mi_programa
   ```

---

## Decisión Técnica, Estructura de Datos y Algoritmo

### Estructura de Datos y Arquitectura
Para mantener la simplicidad y eficiencia en la memoria, no se utiliza una gestión de buffer compleja (de acuerdo con las restricciones del proyecto). La arquitectura se basa en:
- **Parseo secuencial:** Se recorre la cadena de formato `format` carácter a carácter.
- **Manejo variádico:** Uso de las macros de la librería `<stdarg.h>` (`va_start`, `va_arg`, `va_end`) para extraer los argumentos dinámicamente según la conversión especificada.
- **Contador de caracteres:** Un entero acumulador que registra la cantidad total de caracteres impresos en `stdout` para devolver el mismo valor que el `printf()` original.

### Algoritmo de Conversión Hexadecimal y Numérica
- **Recursión/Iteración en base $N$:** Se utiliza un algoritmo recursivo para procesar las bases 10 y 16 (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`). Dividiendo recursivamente por la base correspondiente ($10$ o $16$), el programa alcanza el dígito más significativo antes de escribir en pantalla, lo que garantiza la impresión en el orden correcto sin necesidad de asignaciones dinámicas adicionales (`malloc`) en la mayoría de los casos.

---

## Recursos e Información sobre el uso de IA

### Referencias
- Manuales de C (`man 3 printf`, `man 3 stdarg`).
- Documentación del estándar de C (ANSI C / C99) sobre funciones variádicas.

### Declaración sobre el uso de Inteligencia Artificial
En cumplimiento con las directrices del campus de 42 sobre el aprendizaje reflexivo y sin atajos:
- **Uso de IA:** Se ha utilizado asistencia de IA exclusivamente para la revisión ortográfica y formateo del archivo `README.md`, así como para consultar explicaciones conceptuales sobre la memoria de las funciones variádicas.
- **Código y Lógica:** Todo el código en C y las funciones de parsing/conversión han sido desarrollados manualmente mediante trabajo individual y discusión entre pares (peer-learning), sin copiar respuestas ni código generado automáticamente.