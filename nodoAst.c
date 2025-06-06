
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodoAst.h"

ASTNode *crearNodoNumero(int valor) {
    ASTNode *nodo = malloc(sizeof(ASTNode));
    nodo->tipo = T_NUMERO;
    nodo->dato.valorEntero = valor;
    return nodo;
}

ASTNode *crearNodoDecimal(float valor) {
    ASTNode *nodo = malloc(sizeof(ASTNode));
    nodo->tipo = T_DECIMAL;
    nodo->dato.valorDecimal = valor;
    return nodo;
}

ASTNode *crearNodoCadena(char *texto) {
    ASTNode *nodo = malloc(sizeof(ASTNode));
    nodo->tipo = T_CADENA;
    nodo->dato.cadena = strdup(texto);
    return nodo;
}

ASTNode *crearNodoIdentificador(char *nombre) {
    ASTNode *nodo = malloc(sizeof(ASTNode));
    nodo->tipo = T_IDENTIFICADOR;
    nodo->dato.identificador = strdup(nombre);
    return nodo;
}

ASTNode *crearNodoOperacion(char operador, ASTNode *izq, ASTNode *der) {
    ASTNode *nodo = malloc(sizeof(ASTNode));
    nodo->tipo = T_OPERACION;
    nodo->dato.operacion.operador = operador;
    nodo->dato.operacion.izq = izq;
    nodo->dato.operacion.der = der;
    return nodo;
}

void imprimirAST(ASTNode *nodo, int nivel) {
    if (!nodo) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    switch (nodo->tipo) {
        case T_NUMERO:
            printf("Número: %d\n", nodo->dato.valorEntero);
            break;
        case T_DECIMAL:
            printf("Decimal: %.2f\n", nodo->dato.valorDecimal);
            break;
        case T_CADENA:
            printf("Cadena: \"%s\"\n", nodo->dato.cadena);
            break;
        case T_IDENTIFICADOR:
            printf("Identificador: %s\n", nodo->dato.identificador);
            break;
        case T_OPERACION:
            printf("Operación: %c\n", nodo->dato.operacion.operador);
            imprimirAST(nodo->dato.operacion.izq, nivel + 1);
            imprimirAST(nodo->dato.operacion.der, nivel + 1);
            break;
    }
}
