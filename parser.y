%{
#include <stdio.h>   // Permite usar prints 
#include <stdlib.h>  // Funciones para asignar memoria
#include <string.h>  // Funciones para manejar cadenas
#include "nodoAst.h" // Cabecera de tu AST

void yyerror(const char *s);
int  yylex(void);

ASTNode *raiz = NULL;
%}

%union {
    int    ival;   /* literales enteros */
    float  fval;   /* literales float */
    char  *sval;   /* identificadores y cadenas */
    ASTNode *nodo; /* para construir el AST */
}

/* Tokens para literales y nombres */
%token <ival>  NUM
%token <fval> DECIMAL
%token <sval> CADENA
%token <sval> ID

%token <sval> INT       /* palabra clave 'int' */
%token <sval> FLOAT     /* palabra clave 'float' */
%token <sval> STRING    /* palabra clave 'string' */


%token IF ELSE WHILE PRINT READ

/* Operadores relacionales y aritméticos */
%token IGUALEICHON DIFERENTEICHON MENOR_A MENOR_O_IGUAL_A MAYOR_A MAYOR_O_IGUAL_A
%token ADICION RESTACION MULTIPLICATEICHON DIVISEISHON

/* Puntuación */
%token ASSIGN SEMICOLON COMMA
%token LPAREN RPAREN LBRACE RBRACE

/* Precedencia y asociatividad */
%left ADICION RESTACION
%left MULTIPLICATEICHON DIVISEISHON
%nonassoc IGUALEICHON DIFERENTEICHON
%nonassoc MENOR_A MENOR_O_IGUAL_A MAYOR_A MAYOR_O_IGUAL_A

%type <sval>   tipo
%type <nodo>   expresion

/* declaración de todos los no-terminales que usan $$ = <ASTNode*> */
%type <nodo>   programa
%type <nodo>   lista_sentencias sentencia
%type <nodo>   declaracion_variable asignacion
%type <nodo>   seleccion repeticion entrada_salida

%start programa

%%

programa:
    lista_sentencias     { raiz = $1; }
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
      {/* Se construye nodo de declaración y asignación */
      $$ = crearNodoDeclaracionAsignacion($1, $2, $4);}
  | tipo ID SEMICOLON
      {/* Nodo declaración sin inicializar */
      $$ = crearNodoDeclaracion($1, $2);}
;

tipo:
    INT    { $$ = $1; }
  | FLOAT  { $$ = $1; }
  | STRING { $$ = $1; }
;

asignacion:
    ID ASSIGN expresion SEMICOLON
      {/*Nodo de asignación*/
        $$ = crearNodoAsignacion($1, $3);}
;

expresion:
    expresion ADICION        expresion { $$ = crearNodoOperacion("+",  $1, $3); }
  | expresion RESTACION      expresion { $$ = crearNodoOperacion("-",  $1, $3); }
  | expresion MULTIPLICATEICHON expresion { $$ = crearNodoOperacion("*",  $1, $3); }
  | expresion DIVISEISHON    expresion { $$ = crearNodoOperacion("/",  $1, $3); }
  | expresion IGUALEICHON    expresion { $$ = crearNodoOperacion("==", $1, $3); }
  | expresion DIFERENTEICHON expresion { $$ = crearNodoOperacion("!=", $1, $3); }
  | expresion MENOR_A        expresion { $$ = crearNodoOperacion("<",  $1, $3); }
  | expresion MENOR_O_IGUAL_A expresion { $$ = crearNodoOperacion("<=", $1, $3); }
  | expresion MAYOR_A        expresion { $$ = crearNodoOperacion(">",  $1, $3); }
  | expresion MAYOR_O_IGUAL_A expresion { $$ = crearNodoOperacion(">=", $1, $3); }
  | LPAREN expresion RPAREN             { $$ = $2; }
  | NUM                                 { $$ = crearNodoNumero($1); }
  | DECIMAL                             { $$ = crearNodoDecimal($1); }
  | CADENA                              { $$ = crearNodoCadena($1); }
  | ID                                  { $$ = crearNodoIdentificador($1); }
;

seleccion:
    IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
      { $$ = crearNodoIf($3, $6, NULL); }
  | IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
    ELSE LBRACE lista_sentencias RBRACE
      { $$ = crearNodoIf($3, $6, $10); }
;

repeticion:
    WHILE LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
      { printf("Estructura WHILE\n"); imprimirAST($3,1); }
;

entrada_salida:
    PRINT LPAREN expresion RPAREN SEMICOLON
      { printf("Imprimir:\n"); imprimirAST($3,1); }
  | READ LPAREN ID RPAREN SEMICOLON
      { printf("Leer variable: %s\n", $3); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int main() {
    printf("Iniciando el compilador...\n");
    return yyparse();
}
