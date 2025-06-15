/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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

#line 88 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_DECIMAL = 4,                    /* DECIMAL  */
  YYSYMBOL_CADENA = 5,                     /* CADENA  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_READ = 14,                      /* READ  */
  YYSYMBOL_FUNC = 15,                      /* FUNC  */
  YYSYMBOL_RETORNO = 16,                   /* RETORNO  */
  YYSYMBOL_IGUALEICHON = 17,               /* IGUALEICHON  */
  YYSYMBOL_DIFERENTEICHON = 18,            /* DIFERENTEICHON  */
  YYSYMBOL_MENOR_A = 19,                   /* MENOR_A  */
  YYSYMBOL_MENOR_O_IGUAL_A = 20,           /* MENOR_O_IGUAL_A  */
  YYSYMBOL_MAYOR_A = 21,                   /* MAYOR_A  */
  YYSYMBOL_MAYOR_O_IGUAL_A = 22,           /* MAYOR_O_IGUAL_A  */
  YYSYMBOL_ADICION = 23,                   /* ADICION  */
  YYSYMBOL_RESTACION = 24,                 /* RESTACION  */
  YYSYMBOL_MULTIPLICATEICHON = 25,         /* MULTIPLICATEICHON  */
  YYSYMBOL_DIVISEISHON = 26,               /* DIVISEISHON  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 28,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 29,                     /* COMMA  */
  YYSYMBOL_LPAREN = 30,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 31,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 32,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_LSQUARE = 34,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 35,                   /* RSQUARE  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_programa = 37,                  /* programa  */
  YYSYMBOL_lista_sentencias = 38,          /* lista_sentencias  */
  YYSYMBOL_sentencia = 39,                 /* sentencia  */
  YYSYMBOL_declaracion_variable = 40,      /* declaracion_variable  */
  YYSYMBOL_tipo = 41,                      /* tipo  */
  YYSYMBOL_asignacion = 42,                /* asignacion  */
  YYSYMBOL_expresion = 43,                 /* expresion  */
  YYSYMBOL_seleccion = 44,                 /* seleccion  */
  YYSYMBOL_repeticion = 45,                /* repeticion  */
  YYSYMBOL_entrada_salida = 46,            /* entrada_salida  */
  YYSYMBOL_declaracion_funcion = 47,       /* declaracion_funcion  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_parametros = 49,                /* parametros  */
  YYSYMBOL_lista_parametros = 50,          /* lista_parametros  */
  YYSYMBOL_parametro = 51,                 /* parametro  */
  YYSYMBOL_llamada_funcion = 52,           /* llamada_funcion  */
  YYSYMBOL_argumentos = 53,                /* argumentos  */
  YYSYMBOL_lista_argumentos = 54,          /* lista_argumentos  */
  YYSYMBOL_retorno = 55                    /* retorno  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "DECIMAL",
  "CADENA", "ID", "INT", "FLOAT", "STRING", "IF", "ELSE", "WHILE", "PRINT",
  "READ", "FUNC", "RETORNO", "IGUALEICHON", "DIFERENTEICHON", "MENOR_A",
  "MENOR_O_IGUAL_A", "MAYOR_A", "MAYOR_O_IGUAL_A", "ADICION", "RESTACION",
  "MULTIPLICATEICHON", "DIVISEISHON", "ASSIGN", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LSQUARE", "RSQUARE", "$accept",
  "programa", "lista_sentencias", "sentencia", "declaracion_variable",
  "tipo", "asignacion", "expresion", "seleccion", "repeticion",
  "entrada_salida", "declaracion_funcion", "$@1", "parametros",
  "lista_parametros", "parametro", "llamada_funcion", "argumentos",
  "lista_argumentos", "retorno", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -73,   -11,   -74,   -69,   -74,   -21,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,    39,     0,   -74,   -74,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    16,    36,    17,    18,
      19,    20,    51,   100,   101,   102,    37,    44,    45,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    41,    42,
      42,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    46,    48,    47,    49,    49,    50,    50,
      51,    52,    53,    53,    54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     3,     6,     1,     1,     1,     4,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     4,     1,     7,    11,
       7,     5,     5,     8,     0,     9,     0,     1,     1,     3,
       2,     4,     0,     1,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_sentencias  */
#line 74 "parser.y"
                         { raiz = (yyvsp[0].nodo);
    if(errores > 0){
      fprintf(stderr, "Se encontraron %d errores semánticos\n", errores);
      exit(1);
    } 
    generarCodigo(raiz); /*Llamado para la función de generar el código C*/
    (yyval.nodo) = (yyvsp[0].nodo); }
#line 1254 "parser.tab.c"
    break;

  case 3: /* lista_sentencias: lista_sentencias sentencia  */
#line 86 "parser.y"
    { (yyval.nodo) = agregarHermano((yyvsp[-1].nodo),(yyvsp[0].nodo));}
#line 1260 "parser.tab.c"
    break;

  case 4: /* lista_sentencias: sentencia  */
#line 88 "parser.y"
    { (yyval.nodo) = (yyvsp[0].nodo);}
#line 1266 "parser.tab.c"
    break;

  case 5: /* sentencia: declaracion_variable  */
#line 93 "parser.y"
                         { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1272 "parser.tab.c"
    break;

  case 6: /* sentencia: asignacion  */
#line 94 "parser.y"
               { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1278 "parser.tab.c"
    break;

  case 7: /* sentencia: seleccion  */
#line 95 "parser.y"
              { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1284 "parser.tab.c"
    break;

  case 8: /* sentencia: repeticion  */
#line 96 "parser.y"
               { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1290 "parser.tab.c"
    break;

  case 9: /* sentencia: entrada_salida  */
#line 97 "parser.y"
                   { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1296 "parser.tab.c"
    break;

  case 10: /* sentencia: declaracion_funcion  */
#line 98 "parser.y"
                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1302 "parser.tab.c"
    break;

  case 11: /* sentencia: llamada_funcion SEMICOLON  */
#line 99 "parser.y"
                              { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1308 "parser.tab.c"
    break;

  case 12: /* sentencia: retorno  */
#line 100 "parser.y"
            { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1314 "parser.tab.c"
    break;

  case 13: /* declaracion_variable: tipo ID ASSIGN expresion SEMICOLON  */
#line 106 "parser.y"
      {install((yyvsp[-3].sval),(yyvsp[-4].tipoVar)); //Inserta la tabla en caso de que no exista
        /* Se construye nodo de declaración y asignación */
      (yyval.nodo) = crearNodoDeclaracionAsignacion((yyvsp[-4].tipoVar), (yyvsp[-3].sval), (yyvsp[-1].nodo));}
#line 1322 "parser.tab.c"
    break;

  case 14: /* declaracion_variable: tipo ID SEMICOLON  */
#line 110 "parser.y"
      {install((yyvsp[-1].sval),(yyvsp[-2].tipoVar)); //Inserta sin inicializar
        /* Nodo declaración sin inicializar */
      (yyval.nodo) = crearNodoDeclaracion((yyvsp[-2].tipoVar), (yyvsp[-1].sval));}
#line 1330 "parser.tab.c"
    break;

  case 15: /* declaracion_variable: tipo ID LSQUARE NUM RSQUARE SEMICOLON  */
#line 114 "parser.y"
      {install((yyvsp[-4].sval),(yyvsp[-5].tipoVar));
        (yyval.nodo) = crearNodoDeclaracionArreglo((yyvsp[-5].tipoVar),(yyvsp[-4].sval),(yyvsp[-2].ival));}
#line 1337 "parser.tab.c"
    break;

  case 16: /* tipo: INT  */
#line 120 "parser.y"
           { (yyval.tipoVar) = TYPE_INT; }
#line 1343 "parser.tab.c"
    break;

  case 17: /* tipo: FLOAT  */
#line 121 "parser.y"
           { (yyval.tipoVar) = TYPE_FLOAT; }
#line 1349 "parser.tab.c"
    break;

  case 18: /* tipo: STRING  */
#line 122 "parser.y"
           { (yyval.tipoVar) =  TYPE_STRING; }
#line 1355 "parser.tab.c"
    break;

  case 19: /* asignacion: ID ASSIGN expresion SEMICOLON  */
#line 128 "parser.y"
      {context_check((yyvsp[-3].sval)); //Error si no estaba declarado
        /*Nodo de asignación*/
        (yyval.nodo) = crearNodoAsignacion((yyvsp[-3].sval), (yyvsp[-1].nodo));}
#line 1363 "parser.tab.c"
    break;

  case 20: /* asignacion: ID LSQUARE expresion RSQUARE ASSIGN expresion SEMICOLON  */
#line 132 "parser.y"
      {context_check((yyvsp[-6].sval));
        (yyval.nodo) = crearNodoAsignacionArreglo((yyvsp[-6].sval),(yyvsp[-4].nodo),(yyvsp[-1].nodo));}
#line 1370 "parser.tab.c"
    break;

  case 21: /* expresion: expresion ADICION expresion  */
#line 138 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("+",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1376 "parser.tab.c"
    break;

  case 22: /* expresion: expresion RESTACION expresion  */
#line 139 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("-",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1382 "parser.tab.c"
    break;

  case 23: /* expresion: expresion MULTIPLICATEICHON expresion  */
#line 140 "parser.y"
                                          { (yyval.nodo) = crearNodoOperacion("*",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1388 "parser.tab.c"
    break;

  case 24: /* expresion: expresion DIVISEISHON expresion  */
#line 141 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("/",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1394 "parser.tab.c"
    break;

  case 25: /* expresion: expresion IGUALEICHON expresion  */
#line 142 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("==", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1400 "parser.tab.c"
    break;

  case 26: /* expresion: expresion DIFERENTEICHON expresion  */
#line 143 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("!=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1406 "parser.tab.c"
    break;

  case 27: /* expresion: expresion MENOR_A expresion  */
#line 144 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion("<",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1412 "parser.tab.c"
    break;

  case 28: /* expresion: expresion MENOR_O_IGUAL_A expresion  */
#line 145 "parser.y"
                                        { (yyval.nodo) = crearNodoOperacion("<=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1418 "parser.tab.c"
    break;

  case 29: /* expresion: expresion MAYOR_A expresion  */
#line 146 "parser.y"
                                       { (yyval.nodo) = crearNodoOperacion(">",  (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1424 "parser.tab.c"
    break;

  case 30: /* expresion: expresion MAYOR_O_IGUAL_A expresion  */
#line 147 "parser.y"
                                        { (yyval.nodo) = crearNodoOperacion(">=", (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1430 "parser.tab.c"
    break;

  case 31: /* expresion: LPAREN expresion RPAREN  */
#line 148 "parser.y"
                                        { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1436 "parser.tab.c"
    break;

  case 32: /* expresion: NUM  */
#line 149 "parser.y"
                                        { (yyval.nodo) = crearNodoNumero((yyvsp[0].ival)); }
#line 1442 "parser.tab.c"
    break;

  case 33: /* expresion: DECIMAL  */
#line 150 "parser.y"
                                        { (yyval.nodo) = crearNodoDecimal((yyvsp[0].fval)); }
#line 1448 "parser.tab.c"
    break;

  case 34: /* expresion: CADENA  */
#line 151 "parser.y"
                                        { (yyval.nodo) = crearNodoCadena((yyvsp[0].sval)); }
#line 1454 "parser.tab.c"
    break;

  case 35: /* expresion: ID  */
#line 152 "parser.y"
                                        {context_check((yyvsp[0].sval)); // Verifica si existe
                                          (yyval.nodo) = crearNodoIdentificador((yyvsp[0].sval)); }
#line 1461 "parser.tab.c"
    break;

  case 36: /* expresion: ID LSQUARE expresion RSQUARE  */
#line 154 "parser.y"
                                        {context_check((yyvsp[-3].sval)); (yyval.nodo) = crearNodoAccesoArreglo((yyvsp[-3].sval),(yyvsp[-1].nodo)); }
#line 1467 "parser.tab.c"
    break;

  case 37: /* expresion: llamada_funcion  */
#line 155 "parser.y"
                                        { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1473 "parser.tab.c"
    break;

  case 38: /* seleccion: IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE  */
#line 161 "parser.y"
      { (yyval.nodo) = crearNodoIf((yyvsp[-4].nodo), (yyvsp[-1].nodo), NULL); }
#line 1479 "parser.tab.c"
    break;

  case 39: /* seleccion: IF LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE ELSE LBRACE lista_sentencias RBRACE  */
#line 164 "parser.y"
      { (yyval.nodo) = crearNodoIf((yyvsp[-8].nodo), (yyvsp[-5].nodo), (yyvsp[-1].nodo)); }
#line 1485 "parser.tab.c"
    break;

  case 40: /* repeticion: WHILE LPAREN expresion RPAREN LBRACE lista_sentencias RBRACE  */
#line 170 "parser.y"
      { (yyval.nodo) = crearNodoWhile((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1491 "parser.tab.c"
    break;

  case 41: /* entrada_salida: PRINT LPAREN expresion RPAREN SEMICOLON  */
#line 176 "parser.y"
      { (yyval.nodo) = crearNodoPrint((yyvsp[-2].nodo)); }
#line 1497 "parser.tab.c"
    break;

  case 42: /* entrada_salida: READ LPAREN ID RPAREN SEMICOLON  */
#line 178 "parser.y"
      {context_check((yyvsp[-2].sval)); // Para que no se lea si no está declarado
         (yyval.nodo) = crearNodoRead((yyvsp[-2].sval), NULL); }
#line 1504 "parser.tab.c"
    break;

  case 43: /* entrada_salida: READ LPAREN ID LSQUARE expresion RSQUARE RPAREN SEMICOLON  */
#line 181 "parser.y"
      {context_check((yyvsp[-5].sval)); (yyval.nodo) = crearNodoRead((yyvsp[-5].sval), (yyvsp[-3].nodo)); }
#line 1510 "parser.tab.c"
    break;

  case 44: /* $@1: %empty  */
#line 186 "parser.y"
              {install((yyvsp[0].sval), TYPE_FUNC); push_scope();}
#line 1516 "parser.tab.c"
    break;

  case 45: /* declaracion_funcion: FUNC ID $@1 LPAREN parametros RPAREN LBRACE lista_sentencias RBRACE  */
#line 187 "parser.y"
        { (yyval.nodo) = crearNodoFuncion((yyvsp[-7].sval),(yyvsp[-4].nodo),(yyvsp[-1].nodo)); pop_scope(); }
#line 1522 "parser.tab.c"
    break;

  case 46: /* parametros: %empty  */
#line 191 "parser.y"
                {(yyval.nodo) = NULL;}
#line 1528 "parser.tab.c"
    break;

  case 47: /* parametros: lista_parametros  */
#line 192 "parser.y"
                       {(yyval.nodo) = (yyvsp[0].nodo);}
#line 1534 "parser.tab.c"
    break;

  case 48: /* lista_parametros: parametro  */
#line 196 "parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1540 "parser.tab.c"
    break;

  case 49: /* lista_parametros: lista_parametros COMMA parametro  */
#line 197 "parser.y"
                                       { (yyval.nodo) = agregarHermano((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1546 "parser.tab.c"
    break;

  case 50: /* parametro: tipo ID  */
#line 201 "parser.y"
             { install((yyvsp[0].sval),(yyvsp[-1].tipoVar)); (yyval.nodo) = crearNodoParametro((yyvsp[-1].tipoVar), (yyvsp[0].sval)); }
#line 1552 "parser.tab.c"
    break;

  case 51: /* llamada_funcion: ID LPAREN argumentos RPAREN  */
#line 207 "parser.y"
      { (yyval.nodo) = crearNodoLlamada((yyvsp[-3].sval), (yyvsp[-1].nodo)); }
#line 1558 "parser.tab.c"
    break;

  case 52: /* argumentos: %empty  */
#line 211 "parser.y"
                  { (yyval.nodo) = NULL; }
#line 1564 "parser.tab.c"
    break;

  case 53: /* argumentos: lista_argumentos  */
#line 212 "parser.y"
                       { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1570 "parser.tab.c"
    break;

  case 54: /* lista_argumentos: expresion  */
#line 216 "parser.y"
                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1576 "parser.tab.c"
    break;

  case 55: /* lista_argumentos: lista_argumentos COMMA expresion  */
#line 217 "parser.y"
                                       { (yyval.nodo) = agregarHermano((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1582 "parser.tab.c"
    break;

  case 56: /* retorno: RETORNO expresion SEMICOLON  */
#line 222 "parser.y"
                                { (yyval.nodo) = crearNodoReturn((yyvsp[-1].nodo)); }
#line 1588 "parser.tab.c"
    break;


#line 1592 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

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
