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
%token <fval> DEC           /* literal flotante (ej. 3.14) */
%token <sval> CADENA        /* literal string entre comillas */

/* Identificadores */
%token <sval> IDENTIFIER    /* nombres de variables y funciones */

/* Tipos de datos (Minecraft → C) */
%token INT                   /* “DIAMANTE” → int */
%token FLOAT                 /* “LAVA”     → float */
%token STRING                /* “LIBRO”    → string (char*) */

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

/* Operadores */
%token ASSIGNOP              /* =  (asignación) */
%token PLUS MINUS            /* +  - (suma/resta) */
%token TIMES DIV MOD         /* *  /  % (mult, div, módulo) */

/* Relacionales */
%token EQ_OP NE_OP           /* ==  != */
%token LT_OP LE_OP           /* <   <= */
%token GT_OP GE_OP           /* >   >= */

/* Lógicos */
%token AND OR                /* &&  || */
%token NOT                   /* ! */

/* Delimitadores y símbolos */
%token COMMA SEMICOLON       /* ,  ; */
%token LP RP                 /* (  ) */
%token LB RB                 /* {  } */
```



## Nuestras reglas Sintacticas principales al crear el codigo 
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

## Nuestras reglas de asignaciones

## Nuestras Operaciones aritmeticas 
```bison
 suma (+), resta (-), multiplicación (*), división (/) y módulo (%), 
```


## Para Funciones 

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

Utiliza la palabra clave LETRERO para imprimir resultados o mensajes directamente en la pantalla. 




