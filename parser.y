%{
#include <stdio.h> //Permite usar prints 
#include <stdlib.h> //Incluye las funcionalidades para asginar espacios de memoria
#include <string.h> //Permite utilizar funciones para manejar cadenas

// Función para errores
void yyerror(const char *s);
int yylex(void);
%}

%union {
    int ival;
    float fval;
    char *sval;
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

%token IGUALEICHON DIFERENTEICHON MENOR A MENOR O IGUAL A MAYOR A MAYOR O IGUAL A
%token ADICION RESTACION MULTIPLICATEICHON DIVISEISHON
%token ASSIGN SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE

%type <sval> tipo
%type <sval> expresion

%start programa

%%

programa:
    lista_sentencias
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
        { printf("Declaración de variable con asignación: %s = %s\n", $2, $4); }
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
        { printf("Asignación: %s = %s\n", $1, $3); }
;

expresion:
    expresion ADICION expresion
        { $$ = "suma"; }
    | expresion RESTACION expresion
        { $$ = "resta"; }
    | expresion MULTIPLICATEICHON expresion
        { $$ = "multiplicación"; }
    | expresion DIVISEISHON expresion
        { $$ = "división"; }
    | expresion IGUALEICHON expresion
        { $$ = "igualdad"; }
    | expresion DIFERENTEICHON expresion
        { $$ = "diferencia"; }
    | expresion MENOR A expresion
        { $$ = "menor que"; }
    | expresion MENOR O IGUAL A expresion
        { $$ = "menor o igual"; }
    | expresion MAYOR A expresion
        { $$ = "mayor que"; }
    | expresion MAYOR O IGUAL A expresion
        { $$ = "mayor o igual"; }
    | LPAREN expresion RPAREN
        { $$ = $2; }
    | NUM     { $$ = "entero"; }
    | DECIMAL { $$ = "decimal"; }
    | CADENA  { $$ = "cadena"; }
    | ID      { $$ = $1; }
;

seleccion:
    IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
        { printf("Estructura IF\n"); }
    | IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE ELSE LBRACE lista_sentencias RBRACE
        { printf("Estructura IF-ELSE\n"); }
;

repeticion:
    WHILE LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
        { printf("Estructura WHILE\n"); }
;

entrada_salida:
    PRINT LPAREN expresion RPAREN SEMICOLON
        { printf("Imprimir\n"); }
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
}

