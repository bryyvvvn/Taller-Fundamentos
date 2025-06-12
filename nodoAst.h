
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

/*Tipos de nodos del árbol AST*/
typedef enum {
    T_DECLARACION,            /* tipo + id                              */
    T_DECLARACION_ASIGNACION, /* tipo + id + expr                      */
    T_ASIGNACION,             /* id + expr                             */
    T_IF,                     /* cond, thenBranch, elseBranch          */
    T_WHILE,                  /* cond, body                            */
    T_PRINT,                  /* expr                                  */
    T_READ,                   /* id                                    */
    T_NUMERO,                 /* literal entero                        */
    T_DECIMAL,                /* literal float                         */
    T_CADENA,                 /* literal cadena                        */
    T_IDENTIFICADOR,          /* uso de variable                       */
    T_OPERACION               /* operador binario +,==,!=,...          */
} TipoNodo;

/*Estructura del nodo AST*/
typedef struct ASTNode {
    TipoNodo tipo;               /* qué tipo de nodo es */
    struct ASTNode *firstChild;  /* primer hijo (subárbol) */
    struct ASTNode *nextSibling; /* siguiente sentencia en la lista */

/* datos específicos de cada nodo */
    union {
        /* literales simples */
        int    valorEntero;
        float  valorDecimal;
        char  *cadena;
        char  *identificador;

        /* declaración sin asignar */
        struct {
            VarType varType;
            char *id;
        } decl;

        /* declaración con asignación */
        struct {
            VarType varType;
            char      *id;
            struct ASTNode *initExpr;
        } declAsig;

        /* asignación */
        struct {
            char      *id;
            struct ASTNode *expr;
        } asign;

        /* if */
        struct {
            struct ASTNode *cond;
            struct ASTNode *thenBranch;
            struct ASTNode *elseBranch; /* NULL si no hay else */
        } ifNode;

        /* while */
        struct {
            struct ASTNode *cond;
            struct ASTNode *body;
        } whileNode;

        /* print */
        struct {
            struct ASTNode *expr;
        } printNode;

        /* read */
        struct {
            char *id;
        } readNode;

        /* operación binaria */
        struct {
            char *operador;             /* p.ej. "+", "==", "!=", "<=" */
            struct ASTNode *left;
            struct ASTNode *right;
        } oper;
    } dato;
} ASTNode;

/*Funciones para construir el AST*/
ASTNode *agregarHermano(ASTNode *primero, ASTNode *hermano);

/* Creadores de nodos */
ASTNode *crearNodoDeclaracion   (VarType VarType, const char *id);
ASTNode *crearNodoDeclaracionAsignacion(VarType varType,
                                        const char *id,
                                        ASTNode    *initExpr);
ASTNode *crearNodoAsignacion    (const char *id, ASTNode *expr);
ASTNode *crearNodoIf            (ASTNode *cond,
                                 ASTNode *thenBranch,
                                 ASTNode *elseBranch);
ASTNode *crearNodoWhile         (ASTNode *cond, ASTNode *body);
ASTNode *crearNodoPrint         (ASTNode *expr);
ASTNode *crearNodoRead          (const char *id);

ASTNode *crearNodoNumero        (int valor);
ASTNode *crearNodoDecimal       (float valor);
ASTNode *crearNodoCadena        (const char *texto);
ASTNode *crearNodoIdentificador (const char *nombre);
ASTNode *crearNodoOperacion     (const char *operador,
                                 ASTNode   *left,
                                 ASTNode   *right);

/* Imprime el AST completo (recursivo + siblings) */
void imprimirAST(ASTNode *nodo, int nivel);