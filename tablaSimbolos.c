#include "tablaSimbolos.h"
#include <stdio.h>

/* Pila de scopes. Cada scope contiene su propia lista de símbolos */
Scope *scope_stack = NULL;

/* Para compatibilidad se expone el puntero a la tabla actual */
symrec *sym_table = NULL;

int errores = 0; // Para contar errores semanticos

/* Crea un nuevo scope y lo coloca en la pila */
void push_scope(){
    Scope *nuevo = malloc(sizeof(Scope));
    nuevo->symbols = NULL;
    nuevo->next = scope_stack;
    scope_stack = nuevo;
    sym_table = scope_stack->symbols;
}

/* Libera todos los símbolos de un scope */
static void free_symbols(symrec *s){
    while(s){
        symrec *tmp = s;
        s = s->next;
        free(tmp->name);
        free(tmp);
    }
}

/* Saca el scope actual de la pila */
void pop_scope(){
    if(!scope_stack) return;
    Scope *salir = scope_stack;
    scope_stack = scope_stack->next;
    free_symbols(salir->symbols);
    free(salir);
    sym_table = scope_stack ? scope_stack->symbols : NULL;
}

//Inserta nuevo simbolo en el scope actual
symrec *putsym(const char *name, VarType type){
    if(!scope_stack) push_scope();
    symrec *node = malloc(sizeof(symrec));
    node->name = malloc(strlen(name)+1);
    strcpy(node->name,name);
    node->type = type;
    node->next = scope_stack->symbols;
    scope_stack->symbols = node;
    sym_table = scope_stack->symbols;
    return node;
}

//Busca un símbolo existente
static symrec *getsym_local(const char *name){
    if(!scope_stack) return NULL;
    for(symrec *ptr = scope_stack->symbols; ptr; ptr = ptr->next)
        if(strcmp(ptr->name,name)==0) return ptr;
    return NULL;
}

//Busca un símbolo existente desde el scope actual hacia afuera
symrec *getsym(const char *name){
    for(Scope *s = scope_stack; s; s = s->next){
        for(symrec *ptr = s->symbols; ptr; ptr = ptr->next)
            if(strcmp(ptr->name,name)==0)
                return ptr;
    }
    return NULL;
}

void install(char *name, VarType type) {
    if (getsym_local(name)) {
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
