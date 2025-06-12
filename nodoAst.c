#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodoAst.h"
#include "tablaSimbolos.h"

/*Une dos nodos hermanos en la lista*/
ASTNode *agregarHermano(ASTNode *primero, ASTNode *hermano) {
    if (!primero) return hermano;
    ASTNode *p = primero;
    while (p->nextSibling) p = p->nextSibling;
    p->nextSibling = hermano;
    return primero;
}

/*Para la creación de los nodos del AST*/
/*Declaración pero sin iniciar*/
ASTNode *crearNodoDeclaracion(VarType varType, const char *id) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECLARACION;
    n->firstChild = n->nextSibling = NULL;
    n->dato.decl.varType = varType;
    n->dato.decl.id      = strdup(id);
    return n;
}

/*Declaración con inicialización*/
ASTNode *crearNodoDeclaracionAsignacion(VarType varType,
                                        const char *id,
                                        ASTNode    *initExpr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECLARACION_ASIGNACION;
    n->firstChild = initExpr;
    n->nextSibling = NULL;
    n->dato.declAsig.varType  = varType;
    n->dato.declAsig.id       = strdup(id);
    n->dato.declAsig.initExpr = initExpr;
    return n;
}

/*Nodo asignación*/
ASTNode *crearNodoAsignacion(const char *id, ASTNode *expr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_ASIGNACION;
    n->firstChild = expr;
    n->nextSibling = NULL;
    n->dato.asign.id   = strdup(id);
    n->dato.asign.expr = expr;
    return n;
}

/*Para nodo If y else*/
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

/*Para nodo While*/
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

/*Para nodo Print*/
ASTNode *crearNodoPrint(ASTNode *expr) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_PRINT;
    n->firstChild = expr;
    n->nextSibling = NULL;
    n->dato.printNode.expr = expr;
    return n;
}

/*Para nodo Read*/
ASTNode *crearNodoRead(const char *id) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_READ;
    n->firstChild = NULL;
    n->nextSibling = NULL;
    n->dato.readNode.id = strdup(id);
    return n;
}

/*Literales y variables*/
ASTNode *crearNodoNumero(int valor) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_NUMERO;
    n->firstChild = n->nextSibling = NULL;
    n->dato.valorEntero = valor;
    return n;
}

ASTNode *crearNodoDecimal(float valor) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECIMAL;  // Asegúrate de que el tipo sea T_DECIMAL
    n->firstChild = n->nextSibling = NULL;
    n->dato.valorDecimal = valor;  // Asigna correctamente el valor flotante
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

/*Operaciones aritmeticas*/
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

/*Para imprimir recursivamente el árbol AST*/
void imprimirAST(ASTNode *nodo, int nivel) {
    while (nodo) {
        for (int i = 0; i < nivel; i++) printf("  "); 
        //Imprimir información del nodo actual
        switch (nodo->tipo) {
            case T_DECLARACION:
                printf("Decl: tipo=%d id=%s\n",
                       nodo->dato.decl.varType,
                       nodo->dato.decl.id);
                break;
            case T_DECLARACION_ASIGNACION:
                printf("Decl-Asig: tipo=%d id=%s\n",
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