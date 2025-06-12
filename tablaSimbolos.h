#pragma once

#include <string.h>
#include <stdlib.h>

/*VarType permite distinguir entre variables de tipo int y float*/
typedef enum{TYPE_INT, TYPE_FLOAT, TYPE_STRING} VarType;

/*Nodo para la tabla de simbolos*/
typedef struct symrec{
    char *name; /*nombre del indentificador*/
    VarType type; /*tipo de variable (Int o Float)*/
    struct symrec *next; /*para pasar al siguiente en la lista*/
} symrec;

/*Cabeza de la lista*/
extern symrec *sym_table;

extern int errores;

//Para gestionar la lista
/*Si no hay simbolos, inserta uno*/
symrec *putsym(const char *name, VarType type);

/*Busca el símbolo*/
symrec *getsym(const char *name);

void install(char *name, VarType type);  // Inserta un símbolo
void context_check(char *name);  // Revisa si el símbolo está declarado

