%{
#include <stdio.h>   // Permite usar prints 
#include <stdlib.h>  // Funciones para asignar memoria
#include <string.h>  // Funciones para manejar cadenas
#include "nodoAst.h" // Cabecera de AST
#include "tablaSimbolos.h"
#include "generadorDeCodigo.h"

void install(char *name, VarType type); //Instala en caso de que no exista
void context_check(char *name); //Checkeo de la declaración

void yyerror(const char *s); //Función de error 
int  yylex(void); // Para el escaner

ASTNode *raiz = NULL; //Raiz del AST
%}

%union {
    int    ival;   /* literales enteros */
    float  fval;   /* literales float */
    char  *sval;   /* identificadores y cadenas */
    ASTNode *nodo; /* nodos para construir el AST */
    VarType tipoVar; /*para la variable tipo*/
}

/* Tokens para literales y nombres */
%token <ival>  NUM
%token <fval> DECIMAL
%token <sval> CADENA
%token <sval> ID

%token <tipoVar> INT       /* palabra clave 'int' */
%token <tipoVar> FLOAT     /* palabra clave 'float' */
%token <tipoVar> STRING    /* palabra clave 'string' */


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

%type <tipoVar>   tipo
%type <nodo>   expresion

/* declaración de todos los no-terminales que usan $$ = <ASTNode*> */
%type <nodo>   programa
%type <nodo>   lista_sentencias sentencia
%type <nodo>   declaracion_variable asignacion
%type <nodo>   seleccion repeticion entrada_salida

%start programa

%%

/* Regla inicial del programa*/
programa:
    /*Se utiliza esta regla para poder utilizar agregarHermano*/
    lista_sentencias     { raiz = $1;
    if(errores > 0){
      fprintf(stderr, "Se encontraron %d errores semánticos\n", errores);
      exit(1);
    } 
    generarCodigo(raiz); /*Llamado para la función de generar el código C*/
    $$ = $1; }
;

/*Se ocupa agregarHermano para concatenar los nodos en el árbol*/
lista_sentencias:
    lista_sentencias sentencia
    { $$ = agregarHermano($1,$2);}
  | sentencia
    { $$ = $1;}
;

/*Las sentencias podrían ser*/
sentencia:
    declaracion_variable { $$ = $1; }
  | asignacion { $$ = $1; }
  | seleccion { $$ = $1; }
  | repeticion { $$ = $1; }
  | entrada_salida { $$ = $1; }
;

/*Se declaran las variables*/
declaracion_variable:
    tipo ID ASSIGN expresion SEMICOLON
      {install($2,$1); //Inserta la tabla en caso de que no exista
        /* Se construye nodo de declaración y asignación */
      $$ = crearNodoDeclaracionAsignacion($1, $2, $4);}
  | tipo ID SEMICOLON
      {install($2,$1); //Inserta sin inicializar
        /* Nodo declaración sin inicializar */
      $$ = crearNodoDeclaracion($1, $2);}
;

/*Tipos de variables*/
tipo:
    INT    { $$ = TYPE_INT; }
  | FLOAT  { $$ = TYPE_FLOAT; }
  | STRING { $$ =  TYPE_STRING; }
;

/*Asignación*/
asignacion:
    ID ASSIGN expresion SEMICOLON
      {context_check($1); //Error si no estaba declarado
        /*Nodo de asignación*/
        $$ = crearNodoAsignacion($1, $3);}
;

/*Todas las expresiones que utiliza el lenguaje*/
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
  | ID                                  {context_check($1); // Verifica si existe
                                          $$ = crearNodoIdentificador($1); }
;

/*Funciones if y else*/
seleccion:
    IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
      { $$ = crearNodoIf($3, $6, NULL); }
  | IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
    ELSE LBRACE lista_sentencias RBRACE
      { $$ = crearNodoIf($3, $6, $10); }
;

/*Función para el ciclo while*/
repeticion:
    WHILE LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE
      { $$ = crearNodoWhile($3, $6); }
;

/*Para el print*/
entrada_salida:
    PRINT LPAREN expresion RPAREN SEMICOLON
      { $$ = crearNodoPrint($3); }
  | READ LPAREN ID RPAREN SEMICOLON
      {context_check($3); // Para que no se lea si no está declarado
         $$ = crearNodoRead($3); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int main() {
    printf("Iniciando el compilador...\n");
    yyparse();
    imprimirAST(raiz,0);
    return 0;
}
