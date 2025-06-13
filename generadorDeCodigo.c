#include <stdio.h>
#include "nodoAst.h"
#include "tablaSimbolos.h"

// Declaración anticipada de la función generarCodigo
void generarCodigo(ASTNode *nodo);  // Esto declara la función
FILE *salida = NULL;

// Para inicializar el archivo de salida
void inicializarSalida() {
    salida = fopen("code.c", "w");  // Abre el archivo para escribir
    if (salida == NULL) {
        fprintf(stderr, "Error al abrir el archivo de salida.\n");
        exit(1);  // Si no se puede abrir el archivo, el programa se detiene
    }
}

// Función para obtener el tipo de variable en C (para la generación de código)
const char* obtenerTipoC(VarType tipo) {
    switch (tipo) {
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_STRING: return "char*";
        default: return "unknown";
    }
}

// Función para generar el código de una expresión
void generarCodigoExpresion(ASTNode *nodo) {
    if (nodo->tipo == T_NUMERO) {
        fprintf(salida, "%d", nodo->dato.valorEntero); 
    } else if (nodo->tipo == T_DECIMAL) {
        fprintf(salida, "%f", nodo->dato.valorDecimal);
    } else if (nodo->tipo == T_CADENA) {
        fprintf(salida, "\"%s\"", nodo->dato.cadena);
    } else if (nodo->tipo == T_IDENTIFICADOR) {
        fprintf(salida, "%s", nodo->dato.identificador);
    } else if (nodo->tipo == T_OPERACION) {
        fprintf(salida, "(");
        generarCodigoExpresion(nodo->dato.oper.left);
        fprintf(salida, " %s ", nodo->dato.oper.operador);
        generarCodigoExpresion(nodo->dato.oper.right);
        fprintf(salida, ")");
    }
}



// Función para generar el código de declaración de variables
void generarCodigoDeclaracion(ASTNode *nodo) {
    if (nodo->tipo == T_DECLARACION) {
        fprintf(salida, "%s %s;\n", obtenerTipoC(nodo->dato.decl.varType), nodo->dato.decl.id);
    } else if (nodo->tipo == T_DECLARACION_ASIGNACION) {
        fprintf(salida, "%s %s = ", obtenerTipoC(nodo->dato.declAsig.varType), nodo->dato.declAsig.id);
        generarCodigoExpresion(nodo->dato.declAsig.initExpr);
        fprintf(salida, ";\n");
    }
}

// Función para generar código de asignación
void generarCodigoAsignacion(ASTNode *nodo) {
    fprintf(salida, "%s = ", nodo->dato.asign.id);
    generarCodigoExpresion(nodo->dato.asign.expr);
    fprintf(salida, ";\n");
}


// Función para generar código de control de flujo (if-else)
void generarCodigoIf(ASTNode *nodo) {
    fprintf(salida, "if (");
    generarCodigoExpresion(nodo->dato.ifNode.cond);
    fprintf(salida, ") {\n");
    generarCodigo(nodo->dato.ifNode.thenBranch);
    fprintf(salida, "\n} ");
    if (nodo->dato.ifNode.elseBranch) {
        fprintf(salida, "else {\n");
        generarCodigo(nodo->dato.ifNode.elseBranch);
        fprintf(salida, "\n}");
    }
}


// Función para generar código de ciclo while
void generarCodigoWhile(ASTNode *nodo) {
    fprintf(salida, "while (");
    generarCodigoExpresion(nodo->dato.whileNode.cond);
    fprintf(salida, ") {\n");
    generarCodigo(nodo->dato.whileNode.body);
    fprintf(salida, "\n}");
}

// Función para generar código de impresión (print)
void generarCodigoPrint(ASTNode *nodo) {
    fprintf(salida, "printf(\"");

    // Si es un número entero, se imprime como %d
    if (nodo->dato.printNode.expr->tipo == T_NUMERO) {
        fprintf(salida, "%%d\\n\", ");
    }
    // Si es una cadena, se imprime como %s
    else if (nodo->dato.printNode.expr->tipo == T_CADENA) {
        fprintf(salida, "%%s\\n\", ");
    }
    // Si es un float (decimal), se imprime como %f
    else if (nodo->dato.printNode.expr->tipo == T_DECIMAL) {
        fprintf(salida, "%%f\\n\", ");  // Esto es para flotantes, %f
    }
    // Si es un identificador (variable), se imprime también como %s si es char* (cadena)
    else if (nodo->dato.printNode.expr->tipo == T_IDENTIFICADOR) {
        // Primero, obtenemos la variable identificada
        char *id = nodo->dato.printNode.expr->dato.identificador;
        symrec *symbol = getsym(id);  // Obtener el símbolo de la tabla de símbolos

        // Verificar si la variable es de tipo char* (cadena)
        if (symbol != NULL && symbol->type == TYPE_STRING) {
            fprintf(salida, "%%s\\n\", ");  // Si es una cadena (char*), imprimir con %s
        } else if (symbol != NULL && symbol->type == TYPE_FLOAT) {
            fprintf(salida, "%%f\\n\", ");  // Si es flotante, usar %f
        } else {
            fprintf(salida, "%%d\\n\", ");  // Si es entero, usar %d
        }
    }

    // Ahora generamos el código para la expresión
    generarCodigoExpresion(nodo->dato.printNode.expr);

    fprintf(salida, ");\n");
}






// Función para generar código de lectura (read)
void generarCodigoRead(ASTNode *nodo) {
    fprintf(salida, "scanf(\"%%d\", &%s);\n", nodo->dato.readNode.id);
}

// Función principal para recorrer el AST y generar el código
void generarCodigo(ASTNode *nodo) {
    inicializarSalida();  // Abre el archivo

    // Escribir el código inicial en C
    fprintf(salida, "#include <stdio.h>\n\n");
    fprintf(salida, "int main() {\n");

    // Recorrer los nodos del AST y generar el código
    while (nodo) {
        switch (nodo->tipo) {
            case T_DECLARACION:
            case T_DECLARACION_ASIGNACION:
                generarCodigoDeclaracion(nodo);
                break;
            case T_ASIGNACION:
                generarCodigoAsignacion(nodo);
                break;
            case T_OPERACION:
                generarCodigoExpresion(nodo);
                break;
            case T_IF:
                generarCodigoIf(nodo);
                break;
            case T_WHILE:
                generarCodigoWhile(nodo);
                break;
            case T_PRINT:
                generarCodigoPrint(nodo);
                break;
            case T_READ:
                generarCodigoRead(nodo);
                break;
        }
        nodo = nodo->nextSibling;  // Avanza al siguiente hermano en el AST
    }

    // Escribir el cierre de la función main
    fprintf(salida, "\n    return 0;\n}");
    fclose(salida);  // Cierra el archivo
    
}
