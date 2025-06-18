#include <stdio.h>
#include "nodoAst.h"
#include "tablaSimbolos.h"

// Declaración anticipada de funciones
void generarCodigo(ASTNode *nodo);  // Esto declara la función
void generarBloque(ASTNode *nodo);
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
        case TYPE_INT: return "DIAMANTE";
        case TYPE_FLOAT: return "LAVA";
        case TYPE_STRING: return "LIBRO";
        case TYPE_FUNC: return "DIAMANTE";
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
    } else if (nodo->tipo == T_ACCESO_ARREGLO) {
        fprintf(salida, "%s[", nodo->dato.arrAccess.id);
        generarCodigoExpresion(nodo->dato.arrAccess.index);
        fprintf(salida, "]");
    } else if (nodo->tipo == T_LLAMADA) {
        fprintf(salida, "%s(", nodo->dato.llamada.id);
        ASTNode *arg = nodo->dato.llamada.args;
        while(arg){
            generarCodigoExpresion(arg);
            if(arg->nextSibling) fprintf(salida, ", ");
            arg = arg->nextSibling;
        }
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
    } else if (nodo->tipo == T_DECLARACION_ARREGLO) {
        fprintf(salida, "%s %s[%d];\n", obtenerTipoC(nodo->dato.declArr.varType), nodo->dato.declArr.id, nodo->dato.declArr.size);
    }
}

// Función para generar código de asignación
void generarCodigoAsignacion(ASTNode *nodo) {
    fprintf(salida, "%s = ", nodo->dato.asign.id);
    generarCodigoExpresion(nodo->dato.asign.expr);
    fprintf(salida, ";\n");
}

void generarCodigoAsignacionArreglo(ASTNode *nodo){
    fprintf(salida, "%s[", nodo->dato.asignArr.id);
    generarCodigoExpresion(nodo->dato.asignArr.index);
    fprintf(salida, "] = ");
    generarCodigoExpresion(nodo->dato.asignArr.expr);
    fprintf(salida, ";\n");
}


// Función para generar código de control de flujo (if-else)
void generarCodigoIf(ASTNode *nodo) {
    fprintf(salida, "ENDER (");
    generarCodigoExpresion(nodo->dato.ifNode.cond);
    fprintf(salida, ") {\n");
    generarBloque(nodo->dato.ifNode.thenBranch);
    fprintf(salida, "\n} ");
    if (nodo->dato.ifNode.elseBranch) {
        fprintf(salida, "CREEPER {\n");
        generarBloque(nodo->dato.ifNode.elseBranch);
        fprintf(salida, "\n}");
    }
}


// Función para generar código de ciclo while
void generarCodigoWhile(ASTNode *nodo) {
    fprintf(salida, "ZOMBIE (");
    generarCodigoExpresion(nodo->dato.whileNode.cond);
    fprintf(salida, ") {\n");
    generarBloque(nodo->dato.whileNode.body);
    fprintf(salida, "\n}\n");
}

// Función para generar código de impresión (print)
void generarCodigoPrint(ASTNode *nodo) {
    fprintf(salida, "LETRERO(\"");

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
    // Para cualquier otra expresión, se usa %f como predeterminado
    else{
        fprintf(salida, "%%f\\n\", ");  
    }

    // Ahora generamos el código para la expresión
    generarCodigoExpresion(nodo->dato.printNode.expr);

    fprintf(salida, ");\n");
}






// Función para generar código de lectura (input)
void generarCodigoRead(ASTNode *nodo) {
    if(nodo->dato.readNode.index){
        fprintf(salida, "HORNO(\"%%d\", &%s[", nodo->dato.readNode.id);
        generarCodigoExpresion(nodo->dato.readNode.index);
        fprintf(salida, "]);\n");
    } else {
        fprintf(salida, "HORNO(\"%%d\", &%s);\n", nodo->dato.readNode.id);
    }
}

// Generar código para llamadas de función
void generarCodigoLlamada(ASTNode *nodo) {
    fprintf(salida, "%s(", nodo->dato.llamada.id);
    ASTNode *arg = nodo->dato.llamada.args;
    while(arg){
        generarCodigoExpresion(arg);
        if(arg->nextSibling) fprintf(salida, ", ");
        arg = arg->nextSibling;
    }
    fprintf(salida, ");\n");
}

int contieneReturn(ASTNode *nodo){
    while(nodo){
        if(nodo->tipo == T_RETURN)
            return 1;
        if(contieneReturn(nodo->firstChild))
            return 1;
        nodo = nodo->nextSibling;
    }
    return 0;
}

void generarCodigoReturn(ASTNode *nodo){
    fprintf(salida, "TESORO ");
    if(nodo->dato.returnNode.expr)
        generarCodigoExpresion(nodo->dato.returnNode.expr);
    fprintf(salida, ";\n");
}

//Generar bloque de sentencias, sin abrir archivo ni main
void generarBloque(ASTNode *nodo){
    while (nodo) {
        switch (nodo->tipo) {
            case T_DECLARACION:
            case T_DECLARACION_ASIGNACION:
            case T_DECLARACION_ARREGLO:
                generarCodigoDeclaracion(nodo);
                break;
            case T_ASIGNACION:
                generarCodigoAsignacion(nodo);
                break;
            case T_ASIGNACION_ARREGLO:
                generarCodigoAsignacionArreglo(nodo);
                break;
            case T_OPERACION:
                generarCodigoExpresion(nodo);
                fprintf(salida, ";\n");
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
            case T_LLAMADA:
                generarCodigoLlamada(nodo);
                break;
            case T_RETURN:
                generarCodigoReturn(nodo);
                break;
            default:
                break;
        }
        nodo = nodo->nextSibling;  // Avanza al siguiente hermano en el AST
    }
}

void generarCodigoFuncion(ASTNode *nodo){
    int tieneRetorno = contieneReturn(nodo->dato.funcion.body);
    fprintf(salida, "%s %s(", tieneRetorno ? "DIAMANTE" : "void", nodo->dato.funcion.id);
    ASTNode *param = nodo->dato.funcion.params;
    while(param && param != nodo->dato.funcion.body){
        VarType tipo; 
        const char *nombre;
        switch(param->tipo){
            case T_PARAMETRO:
                tipo = param->dato.param.varType;
                nombre = param->dato.param.id;
                break;
            case T_DECLARACION:
                tipo = param->dato.decl.varType;
                nombre = param->dato.decl.id;
                break;
            case T_DECLARACION_ASIGNACION:
                tipo = param->dato.declAsig.varType;
                nombre = param->dato.declAsig.id;
                break;
            default:
                tipo = TYPE_INT;
                nombre = "unknown";
                break;
        }
        fprintf(salida, "%s %s", obtenerTipoC(tipo), nombre);
        if(param->nextSibling && param->nextSibling != nodo->dato.funcion.body)
        fprintf(salida, ", ");
        param = param->nextSibling;
    }
    fprintf(salida, ") {\n");
    generarBloque(nodo->dato.funcion.body);
    fprintf(salida, "}\n\n");
}

void generarCodigo(ASTNode *nodo){
    inicializarSalida(); // abre archivo
     fprintf(salida, "#include <stdio.h>\n"); //escribe codigo inicial en c
     /*Se definen todas las variables de mi lexico*/
    fprintf(salida, "#define DIAMANTE int\n");
    fprintf(salida, "#define LAVA float\n");
    fprintf(salida, "#define LIBRO char*\n");
    fprintf(salida, "#define ENDER if\n");
    fprintf(salida, "#define CREEPER else\n");
    fprintf(salida, "#define ZOMBIE while\n");
    fprintf(salida, "#define LETRERO printf\n");
    fprintf(salida, "#define HORNO scanf\n");
    fprintf(salida, "#define PORTAL\n");
    fprintf(salida, "#define TESORO return\n\n");
    
    ASTNode *iter = nodo;
    // Primero, imprimir declaraciones globales
    while(iter){
        if(iter->tipo == T_DECLARACION || iter->tipo == T_DECLARACION_ASIGNACION || iter->tipo == T_DECLARACION_ARREGLO){
            generarCodigoDeclaracion(iter);
        }
        iter = iter->nextSibling;
    }

    // Luego, funciones
    iter = nodo;
    while(iter){
        if(iter->tipo == T_FUNCION){
            generarCodigoFuncion(iter);
        }
        iter = iter -> nextSibling;
    }

    fprintf(salida, "int main() {\n"); //Agrega cuerpo principal

    iter = nodo;
    while(iter){
        if(iter->tipo != T_FUNCION && iter->tipo != T_DECLARACION && iter->tipo != T_DECLARACION_ASIGNACION && iter->tipo != T_DECLARACION_ARREGLO){
            switch (iter->tipo)
            {
            case T_DECLARACION:
            case T_DECLARACION_ASIGNACION:
                generarCodigoDeclaracion(iter);
                break;
            case T_ASIGNACION:
                generarCodigoAsignacion(iter);
                break;
            case T_ASIGNACION_ARREGLO:
                generarCodigoAsignacionArreglo(iter);
                break;
            case T_OPERACION:
                generarCodigoExpresion(iter);
                fprintf(salida, ";\n");
                break;
            case T_IF:
                generarCodigoIf(iter);
                break;
            case T_WHILE:
                generarCodigoWhile(iter);
                break;
            case T_PRINT:
                generarCodigoPrint(iter);
                break;
            case T_READ:
                generarCodigoRead(iter);
                break;
            case T_LLAMADA:
                generarCodigoLlamada(iter);
                break;
            default:
                break;
            }
        }
        iter=iter->nextSibling;
    }
    fprintf(salida, "\n return 0;\n}\n");
    fclose(salida); // Cierra el archivo
}


