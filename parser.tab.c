
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>   // Permite usar prints 
#include <stdlib.h>  // Funciones para asignar memoria
#include <string.h>  // Funciones para manejar cadenas
#include "nodoAst.h" // Cabecera de AST
#include "tablaSimbolos.h"
#include "generadorDeCodigo.h"

void install(char *name, VarType type); //Instala en caso de que no exista
void context_check(char *name); //Checkeo de la declaración

void yyerror(const char *s); //Función de error 
int  yylex(void); // Para el escaner

ASTNode *raiz = NULL; //Raiz del AST


/* Line 189 of yacc.c  */
#line 91 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     DECIMAL = 259,
     CADENA = 260,
     ID = 261,
     INT = 262,
     FLOAT = 263,
     STRING = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     PRINT = 268,
     READ = 269,
     FUNC = 270,
     RETORNO = 271,
     IGUALEICHON = 272,
     DIFERENTEICHON = 273,
     MENOR_A = 274,
     MENOR_O_IGUAL_A = 275,
     MAYOR_A = 276,
     MAYOR_O_IGUAL_A = 277,
     ADICION = 278,
     RESTACION = 279,
     MULTIPLICATEICHON = 280,
     DIVISEISHON = 281,
     ASSIGN = 282,
     SEMICOLON = 283,
     COMMA = 284,
     LPAREN = 285,
     RPAREN = 286,
     LBRACE = 287,
     RBRACE = 288,
     LSQUARE = 289,
     RSQUARE = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 18 "parser.y"

    int    ival;   /* literales enteros */
    float  fval;   /* literales float */
    char  *sval;   /* identificadores y cadenas */
    ASTNode *nodo; /* nodos para construir el AST */
    VarType tipoVar; /*para la variable tipo*/



/* Line 214 of yacc.c  */
#line 172 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 184 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    25,    27,    33,    37,    44,    46,    48,    50,
      55,    63,    67,    71,    75,    79,    83,    87,    91,    95,
      99,   103,   107,   109,   111,   113,   115,   120,   122,   130,
     142,   150,   156,   162,   171,   172,   182,   183,   185,   187,
     191,   194,   199,   200,   202,   204,   208
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    38,    39,    -1,    39,    -1,
      40,    -1,    42,    -1,    44,    -1,    45,    -1,    46,    -1,
      47,    -1,    52,    28,    -1,    55,    -1,    41,     6,    27,
      43,    28,    -1,    41,     6,    28,    -1,    41,     6,    34,
       3,    35,    28,    -1,     7,    -1,     8,    -1,     9,    -1,
       6,    27,    43,    28,    -1,     6,    34,    43,    35,    27,
      43,    28,    -1,    43,    23,    43,    -1,    43,    24,    43,
      -1,    43,    25,    43,    -1,    43,    26,    43,    -1,    43,
      17,    43,    -1,    43,    18,    43,    -1,    43,    19,    43,
      -1,    43,    20,    43,    -1,    43,    21,    43,    -1,    43,
      22,    43,    -1,    30,    43,    31,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     6,    34,    43,    35,    -1,
      52,    -1,    10,    30,    43,    31,    32,    38,    33,    -1,
      10,    30,    43,    31,    32,    38,    33,    11,    32,    38,
      33,    -1,    12,    30,    43,    31,    32,    38,    33,    -1,
      13,    30,    43,    31,    28,    -1,    14,    30,     6,    31,
      28,    -1,    14,    30,     6,    34,    43,    35,    31,    28,
      -1,    -1,    15,     6,    48,    30,    49,    31,    32,    38,
      33,    -1,    -1,    50,    -1,    51,    -1,    50,    29,    51,
      -1,    41,     6,    -1,     6,    30,    53,    31,    -1,    -1,
      54,    -1,    43,    -1,    54,    29,    43,    -1,    16,    43,
      28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    85,    87,    93,    94,    95,    96,    97,
      98,    99,   100,   105,   109,   113,   120,   121,   122,   127,
     131,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   154,   155,   160,   162,
     169,   175,   177,   180,   186,   186,   191,   192,   196,   197,
     201,   206,   211,   212,   216,   217,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "DECIMAL", "CADENA", "ID", "INT",
  "FLOAT", "STRING", "IF", "ELSE", "WHILE", "PRINT", "READ", "FUNC",
  "RETORNO", "IGUALEICHON", "DIFERENTEICHON", "MENOR_A", "MENOR_O_IGUAL_A",
  "MAYOR_A", "MAYOR_O_IGUAL_A", "ADICION", "RESTACION",
  "MULTIPLICATEICHON", "DIVISEISHON", "ASSIGN", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LSQUARE", "RSQUARE", "$accept",
  "programa", "lista_sentencias", "sentencia", "declaracion_variable",
  "tipo", "asignacion", "expresion", "seleccion", "repeticion",
  "entrada_salida", "declaracion_funcion", "$@1", "parametros",
  "lista_parametros", "parametro", "llamada_funcion", "argumentos",
  "lista_argumentos", "retorno", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    41,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    46,    48,    47,    49,    49,    50,    50,
      51,    52,    53,    53,    54,    54,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     3,     6,     1,     1,     1,     4,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     1,     7,    11,
       7,     5,     5,     8,     0,     9,     0,     1,     1,     3,
       2,     4,     0,     1,     1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     5,     0,     6,     7,     8,     9,
      10,     0,    12,     0,    52,     0,     0,     0,     0,     0,
      44,    32,    33,    34,    35,     0,     0,    37,     1,     3,
       0,    11,     0,    54,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,    14,     0,    19,    51,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    31,
      25,    26,    27,    28,    29,    30,    21,    22,    23,    24,
       0,     0,    55,     0,     0,     0,    41,    42,     0,     0,
       0,    47,    48,    36,    13,     0,     0,     0,     0,     0,
      50,     0,     0,    15,    20,    38,    40,     0,     0,    49,
       0,    43,     0,     0,    45,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    36,    17,    18,
      19,    20,    51,   100,   101,   102,    37,    44,    45,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
      61,   -17,   -74,   -74,   -74,   -12,   -10,    -7,    -2,     3,
      21,    29,    61,   -74,   -74,    24,   -74,   -74,   -74,   -74,
     -74,     4,   -74,    21,    21,    21,    21,    21,    21,    42,
     -74,   -74,   -74,   -74,   -19,    21,   254,   -74,   -74,   -74,
      19,   -74,   266,   302,    23,    32,   137,   194,   209,   224,
     -15,    22,    21,   239,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,   -74,    21,   -74,    90,   -74,   -74,
      21,    77,    74,    78,    84,    85,    21,   108,   156,   -74,
      81,    81,    70,    70,    70,    70,   312,   312,   148,   148,
     278,    86,   302,    21,    61,    61,   -74,   -74,   175,   103,
      88,    91,   -74,   -74,   -74,    96,   290,    50,    72,   100,
     -74,   110,   108,   -74,   -74,   138,   -74,   122,    61,   -74,
     116,   -74,   120,    61,   -74,   131,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -73,   -11,   -74,   -69,   -74,   -21,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,    39,     0,   -74,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int8 yytable[] =
{
      21,    39,    42,    43,    46,    47,    48,    49,    99,    30,
      23,    24,    21,    24,    53,    52,    75,    25,    26,    76,
      27,   107,   108,    28,    31,    32,    33,    34,    29,    38,
      40,    78,    41,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    99,    90,   122,    65,    66,    50,    92,
     125,    35,    77,    67,    69,    98,     1,     2,     3,     4,
       5,    70,     6,     7,     8,     9,    10,     1,     2,     3,
       4,     5,   106,     6,     7,     8,     9,    10,     1,     2,
       3,     4,     5,   115,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    91,    21,    21,    39,    39,    -1,    -1,
      56,    57,    58,    59,    93,   116,    94,    21,    21,   110,
      95,    39,    96,    97,    39,     2,     3,     4,    21,   111,
     112,   105,    21,    21,   113,    21,     1,     2,     3,     4,
       5,   117,     6,     7,     8,     9,    10,     1,     2,     3,
       4,     5,   118,     6,     7,     8,     9,    10,   123,   120,
     121,   119,     0,   124,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   126,    54,    55,    56,    57,    58,
      59,     0,    71,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,   103,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
     109,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,    72,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
      73,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,    74,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,     0,
      79,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    68,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,   104,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,   114,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    54,
      55,    56,    57,    58,    59,     0,     0,    62,    63
};

static const yytype_int8 yycheck[] =
{
       0,    12,    23,    24,    25,    26,    27,    28,    77,     6,
      27,    30,    12,    30,    35,    34,    31,    34,    30,    34,
      30,    94,    95,    30,     3,     4,     5,     6,    30,     0,
       6,    52,    28,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   112,    65,   118,    27,    28,     6,    70,
     123,    30,    30,    34,    31,    76,     6,     7,     8,     9,
      10,    29,    12,    13,    14,    15,    16,     6,     7,     8,
       9,    10,    93,    12,    13,    14,    15,    16,     6,     7,
       8,     9,    10,    33,    12,    13,    14,    15,    16,    19,
      20,    21,    22,     3,    94,    95,   107,   108,    17,    18,
      19,    20,    21,    22,    27,    33,    32,   107,   108,     6,
      32,   122,    28,    28,   125,     7,     8,     9,   118,    31,
      29,    35,   122,   123,    28,   125,     6,     7,     8,     9,
      10,    31,    12,    13,    14,    15,    16,     6,     7,     8,
       9,    10,    32,    12,    13,    14,    15,    16,    32,    11,
      28,   112,    -1,    33,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    33,    17,    18,    19,    20,    21,
      22,    -1,    35,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    28,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    17,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    12,    13,    14,    15,
      16,    37,    38,    39,    40,    41,    42,    44,    45,    46,
      47,    52,    55,    27,    30,    34,    30,    30,    30,    30,
       6,     3,     4,     5,     6,    30,    43,    52,     0,    39,
       6,    28,    43,    43,    53,    54,    43,    43,    43,    43,
       6,    48,    34,    43,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    28,    27,    28,    34,    28,    31,
      29,    35,    31,    31,    31,    31,    34,    30,    43,    31,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,     3,    43,    27,    32,    32,    28,    28,    43,    41,
      49,    50,    51,    35,    28,    35,    43,    38,    38,    35,
       6,    31,    29,    28,    28,    33,    33,    31,    32,    51,
      11,    28,    38,    32,    33,    38,    33
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    { raiz = (yyvsp[(1) - (1)].nodo);
    if(errores > 0){
      fprintf(stderr, "Se encontraron %d errores semánticos\n", errores);
      exit(1);
    } 
    generarCodigo(raiz); /*Llamado para la función de generar el código C*/
    (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { (yyval.nodo) = agregarHermano((yyvsp[(1) - (2)].nodo),(yyvsp[(2) - (2)].nodo));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (2)].nodo); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {install((yyvsp[(2) - (5)].sval),(yyvsp[(1) - (5)].tipoVar)); //Inserta la tabla en caso de que no exista
        /* Se construye nodo de declaración y asignación */
      (yyval.nodo) = crearNodoDeclaracionAsignacion((yyvsp[(1) - (5)].tipoVar), (yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].nodo));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {install((yyvsp[(2) - (3)].sval),(yyvsp[(1) - (3)].tipoVar)); //Inserta sin inicializar
        /* Nodo declaración sin inicializar */
      (yyval.nodo) = crearNodoDeclaracion((yyvsp[(1) - (3)].tipoVar), (yyvsp[(2) - (3)].sval));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {install((yyvsp[(2) - (6)].sval),(yyvsp[(1) - (6)].tipoVar));
        (yyval.nodo) = crearNodoDeclaracionArreglo((yyvsp[(1) - (6)].tipoVar),(yyvsp[(2) - (6)].sval),(yyvsp[(4) - (6)].ival));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { (yyval.tipoVar) = TYPE_INT; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval.tipoVar) = TYPE_FLOAT; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { (yyval.tipoVar) =  TYPE_STRING; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {context_check((yyvsp[(1) - (4)].sval)); //Error si no estaba declarado
        /*Nodo de asignación*/
        (yyval.nodo) = crearNodoAsignacion((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].nodo));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {context_check((yyvsp[(1) - (7)].sval));
        (yyval.nodo) = crearNodoAsignacionArreglo((yyvsp[(1) - (7)].sval),(yyvsp[(3) - (7)].nodo),(yyvsp[(6) - (7)].nodo));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("+",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("-",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("*",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("/",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("==", (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("!=", (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("<",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { (yyval.nodo) = crearNodoOperacion("<=", (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { (yyval.nodo) = crearNodoOperacion(">",  (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { (yyval.nodo) = crearNodoOperacion(">=", (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    { (yyval.nodo) = (yyvsp[(2) - (3)].nodo); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    { (yyval.nodo) = crearNodoNumero((yyvsp[(1) - (1)].ival)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { (yyval.nodo) = crearNodoDecimal((yyvsp[(1) - (1)].fval)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval.nodo) = crearNodoCadena((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {context_check((yyvsp[(1) - (1)].sval)); // Verifica si existe
                                          (yyval.nodo) = crearNodoIdentificador((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {context_check((yyvsp[(1) - (4)].sval)); (yyval.nodo) = crearNodoAccesoArreglo((yyvsp[(1) - (4)].sval),(yyvsp[(3) - (4)].nodo)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { (yyval.nodo) = crearNodoIf((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo), NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval.nodo) = crearNodoIf((yyvsp[(3) - (11)].nodo), (yyvsp[(6) - (11)].nodo), (yyvsp[(10) - (11)].nodo)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    { (yyval.nodo) = crearNodoWhile((yyvsp[(3) - (7)].nodo), (yyvsp[(6) - (7)].nodo)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval.nodo) = crearNodoPrint((yyvsp[(3) - (5)].nodo)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {context_check((yyvsp[(3) - (5)].sval)); // Para que no se lea si no está declarado
         (yyval.nodo) = crearNodoRead((yyvsp[(3) - (5)].sval), NULL); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {context_check((yyvsp[(3) - (8)].sval)); (yyval.nodo) = crearNodoRead((yyvsp[(3) - (8)].sval), (yyvsp[(5) - (8)].nodo)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {install((yyvsp[(2) - (2)].sval), TYPE_FUNC); push_scope();;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    { (yyval.nodo) = crearNodoFuncion((yyvsp[(2) - (9)].sval),(yyvsp[(5) - (9)].nodo),(yyvsp[(8) - (9)].nodo)); pop_scope(); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {(yyval.nodo) = NULL;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {(yyval.nodo) = (yyvsp[(1) - (1)].nodo);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    { (yyval.nodo) = agregarHermano((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { install((yyvsp[(2) - (2)].sval),(yyvsp[(1) - (2)].tipoVar)); (yyval.nodo) = crearNodoParametro((yyvsp[(1) - (2)].tipoVar), (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    { (yyval.nodo) = crearNodoLlamada((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].nodo)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { (yyval.nodo) = NULL; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.nodo) = (yyvsp[(1) - (1)].nodo); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval.nodo) = agregarHermano((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.nodo) = crearNodoReturn((yyvsp[(2) - (3)].nodo)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1923 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 225 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}

int main() {
    printf("Iniciando el compilador...\n");
    push_scope();
    yyparse();
    pop_scope();
    imprimirAST(raiz,0);
    return 0;
}

