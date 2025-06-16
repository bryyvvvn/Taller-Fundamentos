Compilador Minecraft (usa palabras del videojuego Minecraft ) utilizando Bison y Flex

Manual de uso 

para compilar el codigo , poner lo siguiente en el terminal ( Ctrl + ñ  para abrir el terminal) 

PRIMER PASO     bison -d parser.y
SEGUNDO PASO    flex escaner.l
TERCER PASO     gcc -o Compilador parser.tab.c lex.yy.c generadorDeCodigo.c nodoAst.c tablaSimbolos.c -lm
CUARTO PASO     Get-Content Pruebas/prueba1_profe.txt | .\Compilador 
QUINTO PASO     gcc -o programa code.c
SEXTO PASO      ./programa



Lexico que ocupamos y su funcionalidad   


-Tipo de Datos
DIAMANTE	viene a ser el     int
LAVA		viene a ser el     float
LIBRO	  	viene a ser el     string

-Palabras de Control
ENDER	   	viene a ser el    if
CREEPER     viene a ser el    else
ZOMBIE	   	viene a ser el    while

-Funciones y Retorno
PORTAL      Declara las funciones
TESORO	    Sentencia return



Tokens Definidos 

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


Nuestras reglas Sintacticas principales al crear el codigo 

Estructuras Condicionales (ENDER, CREEPER):
  Permiten ejecutar bloques según el resultado de condiciones evaluadas como verdaderas o falsas. Soporta múltiples condiciones combinadas o anidadas, usando una estructura del tipo ENDER-CREEPER ENDER-CREEPER (equivalente a if-elif-else).

Estructuras Repetitivas (ZOMBIE, FORJA):
  Facilitan repetir instrucciones mientras se cumplan condiciones específicas (ZOMBIE). Además, se implementan dos tipos de ciclos FORJA (similares a los bucles for clásicos):

   Un bucle con avance definido explícitamente por el usuario (usando STEP).
   Un bucle que recorre automáticamente un rango definido implícitamente.

Nuestras reglas de asignaciones

Gestión de Variables Simples y Compuestas (Listas):
  Permite declarar variables básicas y estructuras más avanzadas, como listas. Se pueden crear listas vacías o listas ya inicializadas con elementos concretos. También es posible acceder y modificar elementos específicos dentro de estas listas mediante índices.

Operaciones Incremento (++) y Decremento (--):
  Facilita modificar rápidamente valores numéricos usando operadores especiales. Las variables pueden incrementarse (++) o decrementarse (--) directamente, simplificando la actualización de sus valores.


Nuestras Operaciones aritmeticas 

 suma (+), resta (-), multiplicación (*), división (/) y módulo (%), 

Manejo Seguro de División por Cero:
Implementa verificaciones internas para prevenir divisiones por cero. En caso de intentar realizar una división por cero, el sistema detecta esta operación inválida y genera automáticamente un mensaje de error para alertar al usuario.

Para Funciones 

Funciones con Parámetros Opcionales:
  Permite definir funciones que aceptan parámetros obligatorios junto con otros opcionales. Si no se entregan estos parámetros opcionales al llamar la función, se utilizan valores predeterminados definidos por el programador.

Retorno de Valores (TESORO):
  Las funciones pueden devolver valores usando la palabra clave TESORO. Esta característica facilita que los resultados calculados en una función puedan ser reutilizados fácilmente en otras partes del programa, favoreciendo una programación más modular y clara.

Para imprimir

Utiliza la palabra clave LETRERO para imprimir resultados o mensajes directamente en la pantalla. 




