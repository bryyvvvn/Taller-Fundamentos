#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodoAst.h"

ASTNode *agregarHermano(ASTNode *primero, ASTNode *hermano) {
    if (!primero) return hermano;
    ASTNode *p = primero;
    while (p->nextSibling) p = p->nextSibling;
    p->nextSibling = hermano;
    return primero;
}

ASTNode *crearNodoDeclaracion(const char *varType, const char *id) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECLARACION;
    n->firstChild = n->nextSibling = NULL;
    n->dato.decl.varType = strdup(varType);
    n->dato.decl.id      = strdup(id);
    return n;
}

ASTNode *crearNodoDeclaracionAsignacion(const char *varType,
                                        const char *id,
                                        ASTNode    *initExpr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECLARACION_ASIGNACION;
    n->firstChild = initExpr;
    n->nextSibling = NULL;
    n->dato.declAsig.varType  = strdup(varType);
    n->dato.declAsig.id       = strdup(id);
    n->dato.declAsig.initExpr = initExpr;
    return n;
}

ASTNode *crearNodoAsignacion(const char *id, ASTNode *expr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_ASIGNACION;
    n->firstChild = expr;
    n->nextSibling = NULL;
    n->dato.asign.id   = strdup(id);
    n->dato.asign.expr = expr;
    return n;
}

ASTNode *crearNodoIf(ASTNode *cond, ASTNode *thenBranch, ASTNode *elseBranch) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_IF;
    n->firstChild = cond;
    cond->nextSibling = thenBranch;
    if (elseBranch) thenBranch->nextSibling = elseBranch;
    n->nextSibling = NULL;
    n->dato.ifNode.cond       = cond;
    n->dato.ifNode.thenBranch = thenBranch;
    n->dato.ifNode.elseBranch = elseBranch;
    return n;
}

ASTNode *crearNodoWhile(ASTNode *cond, ASTNode *body) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_WHILE;
    n->firstChild = cond;
    cond->nextSibling = body;
    n->nextSibling = NULL;
    n->dato.whileNode.cond = cond;
    n->dato.whileNode.body = body;
    return n;
}

ASTNode *crearNodoPrint(ASTNode *expr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_PRINT;
    n->firstChild = expr;
    n->nextSibling = NULL;
    n->dato.printNode.expr = expr;
    return n;
}

ASTNode *crearNodoRead(const char *id) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_READ;
    n->firstChild = NULL;
    n->nextSibling = NULL;
    n->dato.readNode.id = strdup(id);
    return n;
}

ASTNode *crearNodoNumero(int valor) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_NUMERO;
    n->firstChild = n->nextSibling = NULL;
    n->dato.valorEntero = valor;
    return n;
}

ASTNode *crearNodoDecimal(float valor) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECIMAL;
    n->firstChild = n->nextSibling = NULL;
    n->dato.valorDecimal = valor;
    return n;
}

ASTNode *crearNodoCadena(const char *texto) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_CADENA;
    n->firstChild = n->nextSibling = NULL;
    n->dato.cadena = strdup(texto);
    return n;
}

ASTNode *crearNodoIdentificador(const char *nombre) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_IDENTIFICADOR;
    n->firstChild = n->nextSibling = NULL;
    n->dato.identificador = strdup(nombre);
    return n;
}

ASTNode *crearNodoOperacion(const char *operador,
                            ASTNode   *left,
                            ASTNode   *right) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_OPERACION;
    n->firstChild = left;
    left->nextSibling = right;
    right->nextSibling = NULL;
    n->nextSibling = NULL;
    n->dato.oper.operador = strdup(operador);
    n->dato.oper.left     = left;
    n->dato.oper.right    = right;
    return n;
}

void imprimirAST(ASTNode *nodo, int nivel) {
    while (nodo) {
        for (int i = 0; i < nivel; i++) printf("  ");
        switch (nodo->tipo) {
            case T_DECLARACION:
                printf("Decl: tipo=%s id=%s\n",
                       nodo->dato.decl.varType,
                       nodo->dato.decl.id);
                break;
            case T_DECLARACION_ASIGNACION:
                printf("Decl-Asig: tipo=%s id=%s\n",
                       nodo->dato.declAsig.varType,
                       nodo->dato.declAsig.id);
                break;
            case T_ASIGNACION:
                printf("Asign: id=%s\n",
                       nodo->dato.asign.id);
                break;
            case T_IF:
                printf("If:\n");
                break;
            case T_WHILE:
                printf("While:\n");
                break;
            case T_PRINT:
                printf("Print:\n");
                break;
            case T_READ:
                printf("Read id=%s\n",
                       nodo->dato.readNode.id);
                break;
            case T_NUMERO:
                printf("Numero: %d\n", nodo->dato.valorEntero);
                break;
            case T_DECIMAL:
                printf("Decimal: %.2f\n", nodo->dato.valorDecimal);
                break;
            case T_CADENA:
                printf("Cadena: \"%s\"\n", nodo->dato.cadena);
                break;
            case T_IDENTIFICADOR:
                printf("Id: %s\n", nodo->dato.identificador);
                break;
            case T_OPERACION:
                printf("Op: %s\n", nodo->dato.oper.operador);
                break;
        }

        // aquí sólo un único llamado para recorrer todos los hijos
        if (nodo->firstChild)
            imprimirAST(nodo->firstChild, nivel+1);

        // y luego avanzamos al hermano
        nodo = nodo->nextSibling;
    }
}