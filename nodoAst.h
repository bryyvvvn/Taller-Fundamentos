
#pragma once

typedef enum {
    T_NUMERO,
    T_DECIMAL,
    T_CADENA,
    T_IDENTIFICADOR,
    T_OPERACION
} TipoNodo;

typedef struct ASTNode {
    TipoNodo tipo;

    union {
        int valorEntero;
        float valorDecimal;
        char *cadena;
        char *identificador;
        struct {
            char operador;
            struct ASTNode *izq;
            struct ASTNode *der;
        } operacion;
    } dato;
} ASTNode;

ASTNode *crearNodoNumero(int valor);
ASTNode *crearNodoDecimal(float valor);
ASTNode *crearNodoCadena(char *texto);
ASTNode *crearNodoIdentificador(char *nombre);
ASTNode *crearNodoOperacion(char operador, ASTNode *izq, ASTNode *der);
void imprimirAST(ASTNode *nodo, int nivel);


