#include "tablaSimbolos.h"
#include <stdio.h>

symrec *sym_table = NULL; // Tabla inicia en nodo vacío

int errores = 0; // Para contar errores semanticos

//Para insertar nuevo simbolo
symrec *putsym(const char *name, VarType type){
    symrec *node = malloc(sizeof(symrec));
    node->name = malloc(strlen(name)+1);
    strcpy(node->name,name);
    node->type = type;
    node->next = sym_table;
    sym_table = node;
    return node;
}

//Busca un símbolo existente
symrec *getsym(const char *name){
    for(symrec *ptr = sym_table; ptr; ptr=ptr->next)
        if(strcmp(ptr->name,name)==0){
            return ptr;
        }
    return NULL;
}

void install(char *name, VarType type) {
    if (getsym(name)) {
        fprintf(stderr, "Error: la variable '%s' ya ha sido declarada.\n", name);
        errores++;
    } else {
        putsym(name, type);
    }
}

void context_check(char *name) {
    if (!getsym(name)) {
        fprintf(stderr, "Error: la variable '%s' no ha sido declarada.\n", name);
        errores++;
    }
}
