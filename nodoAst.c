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

/*Declaración de arreglo*/
ASTNode *crearNodoDeclaracionArreglo(VarType varType, const char *id, int size){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_DECLARACION_ARREGLO;
    n->firstChild = n->nextSibling = NULL;
    n->dato.declArr.varType = varType;
    n->dato.declArr.id = strdup(id);
    n->dato.declArr.size = size;
    return n;
}

/*Acceso a arreglo*/
ASTNode *crearNodoAccesoArreglo(const char *id, ASTNode *index){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_ACCESO_ARREGLO;
    n->firstChild = index;
    n->nextSibling = NULL;
    n->dato.arrAccess.id = strdup(id);
    n->dato.arrAccess.index = index;
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

ASTNode *crearNodoAsignacionArreglo(const char *id, ASTNode *index, ASTNode *expr){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_ASIGNACION_ARREGLO;
    n->firstChild = index;
    index->nextSibling = expr;
    n->nextSibling = NULL;
    n->dato.asignArr.id = strdup(id);
    n->dato.asignArr.index = index;
    n->dato.asignArr.expr = expr;
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

/*Para nodo Read (Input)*/
ASTNode *crearNodoRead(const char *id, ASTNode *index) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_READ;
    n->firstChild = index;
    n->nextSibling = NULL;
    n->dato.readNode.id = strdup(id);
    n->dato.readNode.index = index;
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

/*Declaración de función*/
ASTNode *crearNodoFuncion(const char *id, ASTNode *params, ASTNode *body){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_FUNCION;
    n->firstChild = params ? params : body;
    if(params){
        ASTNode *p = params;
        while(p->nextSibling)
            p = p->nextSibling;
        p->nextSibling = body;
    }
    n->nextSibling = NULL;
    n->dato.funcion.id = strdup(id);
    n->dato.funcion.params = params;
    n->dato.funcion.body = body;
    return n;
}

/*Llamada a función*/
ASTNode *crearNodoLlamada(const char *id, ASTNode *args){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_LLAMADA;
    n->firstChild = args;
    n->nextSibling = NULL;
    n->dato.llamada.id = strdup(id);
    n->dato.llamada.args = args;
    return n;
}

/*Parametro de funcion*/
ASTNode *crearNodoParametro(VarType varType, const char *id) {
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_PARAMETRO;
    n->firstChild = n->nextSibling = NULL;
    n->dato.param.varType = varType;
    n->dato.param.id = strdup(id);
    return n;
}

/*Nodo return*/
ASTNode *crearNodoReturn(ASTNode *expr){
    ASTNode *n = malloc(sizeof(ASTNode));
    n->tipo = T_RETURN;
    n->firstChild = expr;
    n->nextSibling = NULL;
    n->dato.returnNode.expr = expr;
    return n;
}

/*Para imprimir recursivamente el árbol AST*/
const char* nombreTipo(VarType tipo){
    switch(tipo){
        case TYPE_INT: return "DIAMANTE";
        case TYPE_FLOAT: return "LAVA";
        case TYPE_STRING: return "LIBRO";
        case TYPE_FUNC: return "DIAMANTE";
        default: return "unknown";
    }
}

void imprimirAST(ASTNode *nodo, int nivel) {
    while (nodo) {
        for (int i = 0; i < nivel; i++) printf("  "); 
        //Imprimir información del nodo actual
        switch (nodo->tipo) {
            case T_DECLARACION:
                printf("Decl: tipo=%s id=%s\n",
                       nombreTipo(nodo->dato.decl.varType),
                       nodo->dato.decl.id);
                break;
            case T_DECLARACION_ASIGNACION:
                printf("Decl-Asig: tipo=%s id=%s\n",
                       nombreTipo(nodo->dato.declAsig.varType),
                       nodo->dato.declAsig.id);
                break;
            case T_ASIGNACION:
                printf("Asign: id=%s\n",
                       nodo->dato.asign.id);
                break;
            case T_IF:
                printf("ENDER:\n");
                break;
            case T_WHILE:
                printf("ZOMBIE:\n");
                break;
            case T_PRINT:
                printf("LETRERO:\n");
                break;
            case T_READ:
                printf("HORNO id=%s\n",
                       nodo->dato.readNode.id);
                break;
            case T_NUMERO:
                printf("Numero: %d\n", nodo->dato.valorEntero);
                break;
            case T_DECIMAL:
                printf("Decimal: %.2f\n", nodo->dato.valorDecimal);
                break;
            case T_CADENA:
                printf("LIBRO: \"%s\"\n", nodo->dato.cadena);
                break;
            case T_IDENTIFICADOR:
                printf("Id: %s\n", nodo->dato.identificador);
                break;
            case T_OPERACION:
                printf("Op: %s\n", nodo->dato.oper.operador);
                break;
            case T_FUNCION:
                printf("PORTAL %s:\n", nodo->dato.funcion.id);
                break;
            case T_LLAMADA:
                printf("Llamada %s\n", nodo->dato.llamada.id);
                break;
            case T_PARAMETRO:
                printf("Parametro tipo =%s id= %s\n", nombreTipo(nodo->dato.param.varType), nodo->dato.param.id);
                break;
            case T_RETURN:
                printf("TESORO\n");
                break;
            case T_DECLARACION_ARREGLO:
                printf("DeclArr: tipo=%s id=%s size=%d\n", nombreTipo(nodo->dato.declArr.varType), nodo->dato.declArr.id, nodo->dato.declArr.size);
                break;
            case T_ACCESO_ARREGLO:
                printf("AccesoArr %s\n", nodo->dato.arrAccess.id);
                break;
        }

        // aquí sólo un único llamado para recorrer todos los hijos
        if (nodo->firstChild)
            imprimirAST(nodo->firstChild, nivel+1);

        // y luego avanzamos al hermano
        nodo = nodo->nextSibling;
    }
}
