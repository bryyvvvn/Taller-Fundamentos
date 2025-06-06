%{
#include <stdio.h> //Permite usar prints 
#include <stdlib.h> //Incluye las funcionalidades para asginar espacios de memoria
#include <string.h> //Permite utilizar funciones para manejar cadenas
#include <nodoAst.h> //Incluye el .h del arbol

// Función para errores
void yyerror(const char *s);
int yylex(void);

ASTNode *raiz = NULL;
%}

%union {
    int ival;
    float fval;
    char *sval;
    ASTNode *nodo;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <ival> NUM
%token <fval> DECIMAL
%token <sval> CADENA
%token <sval> ID

/* Se definen los nombres de las variables */
%token IF ELSE WHILE
%token PRINT READ

%token IGUALEICHON DIFERENTEICHON MENOR_A MENOR_O_IGUAL_A MAYOR_A MAYOR_O_IGUAL_A
%token ADICION RESTACION MULTIPLICATEICHON DIVISEISHON
%token ASSIGN SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE

%type <sval> tipo
%type <nodo> expresion

%start programa

%%

programa:
    lista_sentencias {raiz = NULL;}
;

lista_sentencias:
    lista_sentencias sentencia
    | sentencia
;

sentencia:
    declaracion_variable
    | asignacion
    | seleccion
    | repeticion
    | entrada_salida
;

declaracion_variable:
    tipo ID ASSIGN expresion SEMICOLON
        { printf("Declaración de variable con asignación: %s\n", $2); imprimirAST($4, 1); }
    | tipo ID SEMICOLON
        { printf("Declaración de variable sin asignación: %s\n", $2); }
;

tipo:
    "int"   { $$ = "int"; }
    | "float" { $$ = "float"; }
    | "string" { $$ = "string"; }
;

asignacion:
    ID ASSIGN expresion SEMICOLON
        { printf("Asignación: %s = ...\n", $1); imprimirAST($3, 1); }
;

expresion:
    expresion ADICION expresion
        { $$ = crearNodoOperacion('+', $1, $3); }
    | expresion RESTACION expresion
        { $$ = crearNodoOperacion('-', $1, $3); }
    | expresion MULTIPLICATEICHON expresion
        { $$ = crearNodoOperacion('*', $1, $3); }
    | expresion DIVISEISHON expresion
        { $$ = crearNodoOperacion('/', $1, $3); }
    | expresion IGUALEICHON expresion
        { $$ = "igualdad"; }
    | expresion DIFERENTEICHON expresion
        { $$ = "diferencia"; }
    | expresion MENOR_A expresion
        { $$ = "menor que"; }
    | expresion MENOR_O_IGUAL_A expresion
        { $$ = "menor o igual"; }
    | expresion MAYOR_A expresion
        { $$ = "mayor que"; }
    | expresion MAYOR_O_IGUAL_A expresion
        { $$ = "mayor o igual"; }
    | LPAREN expresion RPAREN
        { $$ = $2; }
    | NUM     { $$ = crearNodoNumero($1); }
    | DECIMAL { $$ = crearNodoDecimal($1); }
    | CADENA  { $$ = crearNodoCadena($1); }
    | ID      { $$ = crearNodoIdentificador($1); }
;

seleccion:
    IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
        { printf("Estructura IF\n"); imprimirAST($3, 1); }
    | IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE ELSE LBRACE lista_sentencias RBRACE
        { printf("Estructura IF-ELSE\n"); imprimirAST($3, 1); }
;

repeticion:
    WHILE LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
        { printf("Estructura WHILE\n"); imprimirAST($3, 1); }
;

entrada_salida:
    PRINT LPAREN expresion RPAREN SEMICOLON
        { printf("Imprimir:\n"); imprimirAST($3, 1); }
    | READ LPAREN ID RPAREN SEMICOLON
        { printf("Leer variable: %s\n", $3); }
;

%%

// Lo hacemos acá y no donde se añaden los includes para mayor orden en el código.
void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int main() {
    printf("Iniciando el compilador...\n");
    return yyparse(); // Inicia el análisis de la gramática.
    return 0;
}

