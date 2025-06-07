%{
#include "nodoAst.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

DIGIT        [0-9]
ID           [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE   [ \t\n]+

%%

{WHITESPACE}             /* Ignorar espacios, tabs y newlines */

"int"                    { yylval.sval = strdup(yytext); return INT; }
"float"                  { yylval.sval = strdup(yytext); return FLOAT; }
"string"                 { yylval.sval = strdup(yytext); return STRING; }

"if"                     { return IF; }
"else"                   { return ELSE; }
"while"                  { return WHILE; }
"print"                  { return PRINT; }
"read"                   { return READ; }

"=="                     { return IGUALEICHON; }
"!="                     { return DIFERENTEICHON; }
"<="                     { return MENOR_O_IGUAL_A; }
">="                     { return MAYOR_O_IGUAL_A; }
"<"                      { return MENOR_A; }
">"                      { return MAYOR_A; }

"+"                      { return ADICION; }
"-"                      { return RESTACION; }
"*"                      { return MULTIPLICATEICHON; }
"/"                      { return DIVISEISHON; }

"="                      { return ASSIGN; }

";"                      { return SEMICOLON; }
","                      { return COMMA; }
"("                      { return LPAREN; }
")"                      { return RPAREN; }
"{"                      { return LBRACE; }
"}"                      { return RBRACE; }

\"([^\"\\]|\\.)*\"       {
                            /* Literal de cadena: eliminar comillas */
                            int len = yyleng;
                            char *str = malloc(len-1);
                            if (!str) exit(1);
                            memcpy(str, yytext+1, len-2);
                            str[len-2] = '\0';
                            yylval.sval = str;
                            return CADENA;
                         }

{DIGIT}"."{DIGIT}+        { yylval.fval = atof(yytext);   return DECIMAL; }
{DIGIT}+                  { yylval.ival = atoi(yytext);   return NUM;     }

{ID}                      { yylval.sval = strdup(yytext); return ID;      }

.                         { return yytext[0]; }  /* cualquier otro carácter */

%%

int yywrap(void) {
    return 1;
}
