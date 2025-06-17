# Compilador Minecraft    utilizando Bison y Flex 🟩⛏️

## Manual de uso 📖

Para compilar el codigo , poner lo siguiente en el terminal ( Ctrl + ñ  para abrir el terminal en VSC) 



| **Paso**         | **Acción**                                                                                |
| ---------------- | ----------------------------------------------------------------------------------------- |
| **PRIMER PASO**  | bison -d parser.y                                                                         |
| **SEGUNDO PASO** | flex escaner.l                                                                            |
| **TERCER PASO**  | gcc -o Compilador parser.tab.c lex.yy.c generadorDeCodigo.c nodoAst.c tablaSimbolos.c -lm |
| **CUARTO PASO**  | Get-Content Pruebas/prueba1\_profe.txt \| .\Compilador                                    |
| **QUINTO PASO**  | gcc -o programa code.c                                                                    |
| **SEXTO PASO**   | ./programa                                                                                |




## Lexico que ocupamos y su funcionalidad   


| **Tipo de Dato** | **Equivale a** |
| ---------------- | -------------- |
| DIAMANTE         | int            |
| LAVA             | float          |
| LIBRO            | string         |


| **Palabra de Control** | **Equivale a** |
| ---------------------- | -------------- |
| ENDER                  | if             |
| CREEPER                | else           |
| ZOMBIE                 | while          |



| **Funciones y Retorno** | **Función**                   |
| ------------ | ----------------------------- |
| PORTAL       | Declara las funciones         |
| TESORO       | Sentencia de retorno (return) |
| LETRERO       | print            |
| HORNO            | input          |



## Tokens Definidos 
```bison
/* Literales */
%token <ival> NUM           /* literal entero (ej. 42) */
%token <fval> DECIMAL       /* literal flotante (ej. 3.14) */
%token <sval> CADENA        /* literal string entre comillas */

/* Identificadores */
%token <sval>    ID         /* nombres de variables y funciones */

/* Tipos de datos (Minecraft → C) */
%token <tipoVar> INT                /* “DIAMANTE” → int */
%token <tipoVar> FLOAT              /* “LAVA”     → float */
%token <tipoVar> STRING             /* “LIBRO”    → string (char*) */

/* Palabras de control */
%token IF                    /* “ENDER”    → if */
%token ELSE                  /* “CREEPER”  → else */
%token WHILE                 /* “ZOMBIE”   → while */

/* Entrada/Salida */
%token PRINT                 /* “LETRERO”  → print */
%token READ                  /* “HORNO”    → read */

/* Funciones */
%token FUNC                  /* “PORTAL”   → func */
%token RETORNO               /* “TESORO”   → return */

/* Operadores aritméticos */
%token           ADICION            /* + */
%token           RESTACION          /* - */
%token           MULTIPLICATEICHON  /* * */
%token           DIVISEISHON        /* / */

/* Operadores relacionales */
%token           IGUALEICHON        /* == */
%token           DIFERENTEICHON     /* != */
%token           MENOR_A            /* < */
%token           MENOR_O_IGUAL_A    /* <= */
%token           MAYOR_A            /* > */
%token           MAYOR_O_IGUAL_A    /* >= */

/* Asignación */
%token           ASSIGN             /* = */

/* Puntuación y delimitadores */
%token           SEMICOLON          /* ; */
%token           COMMA              /* , */
%token           LPAREN RPAREN      /* ( ) */
%token           LBRACE RBRACE      /* { } */
%token           LSQUARE RSQUARE    /* [ ] */
```



## Nuestras reglas Sintacticas principales al crear el codigo 

### Tipos de datos (DIAMANTES,LAVA Y LIBRO)
```bison
  DIAMANTE gestiona valores enteros sin decimales (como contadores o índices),
  LAVA maneja números con parte fraccionaria (útil para cálculos precisos con decimales),
  LIBRO almacena texto completo (mensajes, nombres o cualquier cadena de caracteres).
```

### Estructuras Condicionales (ENDER, CREEPER):
```bison
  Permiten ejecutar bloques según el resultado de condiciones evaluadas como verdaderas o falsas
  Soporta múltiples condiciones combinadas o anidadas,
  usando una estructura del tipo ENDER-CREEPER ENDER-CREEPER (equivalente a if-else).
```

### Estructuras Repetitivas (ZOMBIE):
```bison
   Facilita repetir instrucciones mientras se cumplan condiciones específicas (ZOMBIE).
   Un bucle que recorre automáticamente hasta que se cumpla una condición acordada.
```
### Funciones y Flujo de Ejecución (PORTAL, LETRERO, TESORO):
```bison
El PORTAL define una nueva función en tu programa.
El LETRERO imprime uno o varios valores en pantalla, agregando salto de línea al final.
El TESORO devuelve un valor desde el interior de una función y finaliza su ejecución.
```

### Entrada de valores (HORNO):
```bison
Permite pausar la ejecución y leer un valor ingresado por el usuario desde el teclado. 
La variable destino debe estar declarada previamente.  
Soporta lectura de DIAMANTE, LAVA y LIBRO según el tipo de la variable.
```

## Nuestras Operaciones aritmeticas 
```bison
 suma (+), resta (-), multiplicación (*), división (/).
```




### Funciones con Parámetros Opcionales:
```bison
  Permite definir funciones que aceptan parámetros obligatorios junto con otros opcionales.
  Si no se entregan estos parámetros opcionales al llamar la función,
  se utilizan valores predeterminados definidos por el programador.
```

### Retorno de Valores (TESORO):
```bison
  Las funciones pueden devolver valores usando la palabra clave TESORO
  Esta característica facilita que los resultados calculados
  en una función puedan ser reutilizados fácilmente en otras partes del programa
  favoreciendo una programación más modular y clara.
```

## Para imprimir
```bison
  Utiliza la palabra clave LETRERO para imprimir resultados o mensajes directamente en la pantalla. 
```

### Integrantes del github 
```bison
  Benjamin Bustamante 21.507.588-5 benjamin.bustamante@alumnos.ucn.cl 
  Bryan Carvajal 21.177.361-8 bryan.carvajal@alumnos.ucn.cl
```



