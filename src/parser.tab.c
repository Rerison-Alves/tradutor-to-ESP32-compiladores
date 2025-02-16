/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *output_file;
int canalPWM = 0;
int currentLine = 1;

void yyerror(const char *s);
int yylex(void);

char* concatenarExpressao(const char* op, char* e1, char* e2);
char* processarHttp(const char* url, const char* dados);



/* Line 189 of yacc.c  */
#line 90 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     VAR = 258,
     INTEIRO = 259,
     BOOLEANO = 260,
     TEXTO_TYPE = 261,
     CONFIG = 262,
     FIM = 263,
     REPITA = 264,
     COMO = 265,
     SAIDA = 266,
     ENTRADA = 267,
     CONFIGURAR = 268,
     LIGAR = 269,
     DESLIGAR = 270,
     LER_DIGITAL = 271,
     LER_ANALOGICO = 272,
     CONFIG_PWM = 273,
     AJUSTAR_PWM = 274,
     COM = 275,
     FREQUENCIA = 276,
     RESOLUCAO = 277,
     CONECTAR_WIFI = 278,
     ENVIAR_HTTP = 279,
     CONFIG_SERIAL = 280,
     ESCREVER_SERIAL = 281,
     LER_SERIAL = 282,
     ESPERAR = 283,
     SE = 284,
     SENAO = 285,
     ENTAO = 286,
     ENQUANTO = 287,
     VALOR = 288,
     RECEBE = 289,
     IGUAL = 290,
     DIFERENTE = 291,
     MENOR = 292,
     MAIOR = 293,
     MENOR_IGUAL = 294,
     MAIOR_IGUAL = 295,
     MAIS = 296,
     MENOS = 297,
     MULT = 298,
     DIV = 299,
     INTEIRO_LIT = 300,
     BOOL_LIT = 301,
     TEXTO_LIT = 302,
     IDENT = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 18 "parser.y"

    int ival;
    char *sval;



/* Line 214 of yacc.c  */
#line 181 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    50,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    17,    19,    21,    23,
      25,    29,    33,    34,    37,    39,    41,    43,    45,    47,
      51,    52,    55,    57,    59,    61,    63,    65,    67,    69,
      71,    76,    80,    84,    90,    96,   105,   112,   117,   121,
     125,   130,   138,   139,   143,   148,   152,   156,   160,   164,
     168,   172,   176,   180,   184,   188,   192,   194,   196,   198,
     200,   202,   204,   207,   210,   211,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    61,    64,    -1,    -1,    57,    58,
      -1,     3,    59,    49,    60,    50,    -1,     4,    -1,     5,
      -1,     6,    -1,    48,    -1,    60,    51,    48,    -1,     7,
      62,     8,    -1,    -1,    62,    63,    -1,    67,    -1,    69,
      -1,    70,    -1,    72,    -1,    73,    -1,     9,    65,     8,
      -1,    -1,    65,    66,    -1,    67,    -1,    68,    -1,    71,
      -1,    82,    -1,    76,    -1,    78,    -1,    75,    -1,    74,
      -1,    48,    34,    79,    50,    -1,    14,    48,    50,    -1,
      15,    48,    50,    -1,    13,    48,    10,    11,    50,    -1,
      13,    48,    10,    12,    50,    -1,    18,    48,    20,    21,
      45,    22,    45,    50,    -1,    19,    48,    20,    33,    79,
      50,    -1,    23,    48,    48,    50,    -1,    25,    45,    50,
      -1,    26,    79,    50,    -1,    24,    47,    47,    50,    -1,
      29,    79,    31,    52,    81,    77,     8,    -1,    -1,    30,
      52,    81,    -1,    32,    52,    81,     8,    -1,    79,    35,
      79,    -1,    79,    36,    79,    -1,    79,    37,    79,    -1,
      79,    38,    79,    -1,    79,    39,    79,    -1,    79,    40,
      79,    -1,    79,    41,    79,    -1,    79,    42,    79,    -1,
      79,    43,    79,    -1,    79,    44,    79,    -1,    53,    79,
      54,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      80,    -1,    27,    -1,    16,    48,    -1,    17,    48,    -1,
      -1,    81,    66,    -1,    28,    45,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    57,    58,    62,    78,    79,    80,    84,
      85,    95,   104,   105,   115,   116,   117,   118,   119,   123,
     127,   128,   138,   139,   140,   141,   142,   143,   144,   145,
     149,   159,   165,   174,   180,   189,   200,   210,   227,   235,
     244,   253,   262,   263,   272,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   301,   307,   316,   317,   327
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INTEIRO", "BOOLEANO",
  "TEXTO_TYPE", "CONFIG", "FIM", "REPITA", "COMO", "SAIDA", "ENTRADA",
  "CONFIGURAR", "LIGAR", "DESLIGAR", "LER_DIGITAL", "LER_ANALOGICO",
  "CONFIG_PWM", "AJUSTAR_PWM", "COM", "FREQUENCIA", "RESOLUCAO",
  "CONECTAR_WIFI", "ENVIAR_HTTP", "CONFIG_SERIAL", "ESCREVER_SERIAL",
  "LER_SERIAL", "ESPERAR", "SE", "SENAO", "ENTAO", "ENQUANTO", "VALOR",
  "RECEBE", "IGUAL", "DIFERENTE", "MENOR", "MAIOR", "MENOR_IGUAL",
  "MAIOR_IGUAL", "MAIS", "MENOS", "MULT", "DIV", "INTEIRO_LIT", "BOOL_LIT",
  "TEXTO_LIT", "IDENT", "':'", "';'", "','", "'\\n'", "'('", "')'",
  "$accept", "programa", "declaracoes", "declaracao_var", "tipo",
  "lista_ids", "config", "blocos_config", "bloco_config", "repita",
  "blocos_repita", "bloco_repita", "atribuicao", "controle_gpio",
  "config_pin", "config_pwm", "ajustar_pwm", "conectar_wifi",
  "config_serial", "escrever_serial", "enviar_http", "condicional",
  "cond_else", "enquanto_loop", "expressao", "leitura", "comandos",
  "esperar", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    58,
      59,    44,    10,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    59,    59,    59,    60,
      60,    61,    62,    62,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    68,    68,    69,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    77,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     5,     1,     1,     1,     1,
       3,     3,     0,     2,     1,     1,     1,     1,     1,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     5,     5,     8,     6,     4,     3,     3,
       4,     7,     0,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     0,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,    12,     4,     0,     6,     7,
       8,     0,     0,    20,     2,     0,    11,     0,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,     0,     9,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    29,
      28,    26,    27,    25,     5,     0,     0,     0,     0,    38,
       0,     0,    61,    56,    57,    58,    59,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,    64,    10,     0,
       0,     0,    37,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    31,    32,     0,
       0,    39,    66,     0,     0,    33,    34,     0,    55,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     0,
      40,    64,    44,    65,     0,     0,    42,     0,    36,     0,
       0,    35,    64,    41,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    11,    30,     7,    12,    22,    14,
      28,   123,    46,    47,    24,    25,    48,    26,    27,    49,
      50,    51,   130,    52,    68,    69,   104,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
    -119,     6,     2,  -119,    25,  -119,  -119,    -5,  -119,  -119,
    -119,   -36,    10,  -119,  -119,   -28,  -119,   -24,   -21,   -16,
     -11,     3,  -119,  -119,  -119,  -119,  -119,  -119,    -7,  -119,
     -40,    26,    18,    -9,   -10,    40,  -119,    -6,    -4,    11,
      13,    40,    -2,    40,    12,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,    15,     4,    44,    19,  -119,
      20,    22,  -119,  -119,  -119,  -119,  -119,    40,   114,  -119,
      24,    27,    52,    33,   130,    31,   162,  -119,  -119,    32,
      34,    38,  -119,  -119,  -119,    94,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,  -119,  -119,  -119,    58,
      42,  -119,  -119,    45,    47,  -119,  -119,    74,  -119,   182,
     182,   182,   182,   182,   182,   172,   172,   188,   188,    40,
    -119,  -119,  -119,  -119,    53,   146,    75,    50,  -119,    54,
     100,  -119,  -119,  -119,    96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    81,    90,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,   -41,  -119,  -118,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      74,    36,    76,   126,    13,     4,     3,    37,    38,     5,
      54,    55,    39,    15,   134,    79,    80,    40,    16,    41,
      29,    42,    43,    17,    31,    44,    85,    32,    18,     8,
       9,    10,    33,    19,    34,    20,    56,    35,    57,    58,
      59,    21,    70,    75,    71,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   122,    60,    61,    21,    72,
      73,    37,    38,    78,    77,    81,    39,    62,    83,    82,
      84,    40,    99,    41,    97,    42,    43,    98,   125,    44,
     100,   102,   105,   107,   106,    63,    64,    65,    66,    37,
      38,   119,   120,    67,    39,    21,   124,   121,   127,    40,
     131,    41,    23,    42,    43,   129,   132,    44,   133,    45,
      37,    38,     0,     0,     0,    39,     0,     0,     0,     0,
      40,     0,    41,    21,    42,    43,     0,     0,    44,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    21,     0,     0,     0,   108,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
     101,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,   103,     0,     0,   128,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    86,    87,    88,
      89,    90,    91,     0,     0,    94,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      41,     8,    43,   121,     9,     3,     0,    14,    15,     7,
      50,    51,    19,    49,   132,    11,    12,    24,     8,    26,
      48,    28,    29,    13,    48,    32,    67,    48,    18,     4,
       5,     6,    48,    23,    45,    25,    10,    34,    20,    48,
      50,    48,    48,    45,    48,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     8,    16,    17,    48,    48,
      47,    14,    15,    48,    52,    21,    19,    27,    48,    50,
      48,    24,    20,    26,    50,    28,    29,    50,   119,    32,
      47,    50,    50,    45,    50,    45,    46,    47,    48,    14,
      15,    33,    50,    53,    19,    48,    22,    52,    45,    24,
      50,    26,    12,    28,    29,    30,    52,    32,     8,    28,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    26,    48,    28,    29,    -1,    -1,    32,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    54,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    31,    -1,    -1,    50,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    44,    35,    36,    37,
      38,    39,    40,    35,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,     3,     7,    58,    61,     4,     5,
       6,    59,    62,     9,    64,    49,     8,    13,    18,    23,
      25,    48,    63,    67,    69,    70,    72,    73,    65,    48,
      60,    48,    48,    48,    45,    34,     8,    14,    15,    19,
      24,    26,    28,    29,    32,    66,    67,    68,    71,    74,
      75,    76,    78,    82,    50,    51,    10,    20,    48,    50,
      16,    17,    27,    45,    46,    47,    48,    53,    79,    80,
      48,    48,    48,    47,    79,    45,    79,    52,    48,    11,
      12,    21,    50,    48,    48,    79,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    50,    50,    50,    20,
      47,    50,    50,    31,    81,    50,    50,    45,    54,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    33,
      50,    52,     8,    66,    22,    79,    81,    45,    50,    30,
      77,    50,    52,     8,    81
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 49 "parser.y"
    {
        fprintf(output_file, "}\n\nvoid loop() {\n%s}\n", (yyvsp[(3) - (3)].sval));
        free((yyvsp[(3) - (3)].sval));
        fclose(output_file);
    ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 57 "parser.y"
    { (yyval.sval) = strdup(""); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 58 "parser.y"
    { free((yyvsp[(1) - (2)].sval)); free((yyvsp[(2) - (2)].sval)); (yyval.sval) = strdup(""); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 63 "parser.y"
    {
        if(strcmp((yyvsp[(2) - (5)].sval), "int") == 0) {
            fprintf(output_file, "int %s;\n", (yyvsp[(4) - (5)].sval));
        } else if(strcmp((yyvsp[(2) - (5)].sval), "bool") == 0) {
            fprintf(output_file, "bool %s = false;\n", (yyvsp[(4) - (5)].sval));
        } else {
            fprintf(output_file, "String %s;\n", (yyvsp[(4) - (5)].sval));
        }
        free((yyvsp[(2) - (5)].sval));
        free((yyvsp[(4) - (5)].sval));
        (yyval.sval) = strdup("");
    ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 78 "parser.y"
    { (yyval.sval) = strdup("int"); ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 79 "parser.y"
    { (yyval.sval) = strdup("bool"); ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 80 "parser.y"
    { (yyval.sval) = strdup("String"); ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 84 "parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 86 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(1) - (3)].sval)) + strlen((yyvsp[(3) - (3)].sval)) + 3);
        sprintf((yyval.sval), "%s, %s", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
        free((yyvsp[(1) - (3)].sval));
        free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 96 "parser.y"
    {
        fprintf(output_file, "\nvoid setup() {\n%s", (yyvsp[(2) - (3)].sval));
        free((yyvsp[(2) - (3)].sval));
        (yyval.sval) = strdup("");
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 104 "parser.y"
    { (yyval.sval) = strdup(""); ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 106 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(1) - (2)].sval)) + strlen((yyvsp[(2) - (2)].sval)) + 1);
        sprintf((yyval.sval), "%s%s", (yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].sval));
        free((yyvsp[(1) - (2)].sval));
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 123 "parser.y"
    { (yyval.sval) = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 127 "parser.y"
    { (yyval.sval) = strdup(""); ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 129 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(1) - (2)].sval)) + strlen((yyvsp[(2) - (2)].sval)) + 1);
        sprintf((yyval.sval), "%s%s", (yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].sval));
        free((yyvsp[(1) - (2)].sval));
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 150 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(1) - (4)].sval)) + strlen((yyvsp[(3) - (4)].sval)) + 20);
        sprintf((yyval.sval), "%s = %s;\n", (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].sval));
        free((yyvsp[(1) - (4)].sval));
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 160 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "digitalWrite(%s, HIGH);\n", (yyvsp[(2) - (3)].sval));
        free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 166 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "digitalWrite(%s, LOW);\n", (yyvsp[(2) - (3)].sval));
        free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 175 "parser.y"
    {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "pinMode(%s, OUTPUT);\n", (yyvsp[(2) - (5)].sval));
        free((yyvsp[(2) - (5)].sval));
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 181 "parser.y"
    {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "pinMode(%s, INPUT);\n", (yyvsp[(2) - (5)].sval));
        free((yyvsp[(2) - (5)].sval));
    ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 190 "parser.y"
    {
        (yyval.sval) = malloc(200);
        sprintf((yyval.sval), "ledcSetup(%d, %d, %d);\nledcAttachPin(%s, %d);\n",
               canalPWM, (yyvsp[(5) - (8)].ival), (yyvsp[(7) - (8)].ival), (yyvsp[(2) - (8)].sval), canalPWM);
        canalPWM++;
        free((yyvsp[(2) - (8)].sval));
    ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 201 "parser.y"
    {
        (yyval.sval) = malloc(100);
        sprintf((yyval.sval), "ledcWrite(%d, %s);\n", canalPWM-1, (yyvsp[(5) - (6)].sval));
        free((yyvsp[(2) - (6)].sval));
        free((yyvsp[(5) - (6)].sval));
    ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 211 "parser.y"
    {
        (yyval.sval) = malloc(500);
        sprintf((yyval.sval),
            "WiFi.begin(%s.c_str(), %s.c_str());\n"
            "while(WiFi.status() != WL_CONNECTED) {\n"
            "  delay(500);\n"
            "  Serial.println(\"Conectando ao WiFi...\");\n"
            "}\n"
            "Serial.println(\"Conectado ao WiFi!\");\n",
            (yyvsp[(2) - (4)].sval), (yyvsp[(3) - (4)].sval));
        free((yyvsp[(2) - (4)].sval));
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 228 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "Serial.begin(%d);\n", (yyvsp[(2) - (3)].ival));
    ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 236 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(2) - (3)].sval)) + 30);
        sprintf((yyval.sval), "Serial.println(%s);\n", (yyvsp[(2) - (3)].sval));
        free((yyvsp[(2) - (3)].sval));
    ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 245 "parser.y"
    {
        (yyval.sval) = processarHttp((yyvsp[(2) - (4)].sval), (yyvsp[(3) - (4)].sval));
        free((yyvsp[(2) - (4)].sval));
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 254 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(2) - (7)].sval)) + strlen((yyvsp[(5) - (7)].sval)) + strlen((yyvsp[(6) - (7)].sval)) + 50);
        sprintf((yyval.sval), "if (%s) {\n%s%s}\n", (yyvsp[(2) - (7)].sval), (yyvsp[(5) - (7)].sval), (yyvsp[(6) - (7)].sval));
        free((yyvsp[(2) - (7)].sval)); free((yyvsp[(5) - (7)].sval)); free((yyvsp[(6) - (7)].sval));
    ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 262 "parser.y"
    { (yyval.sval) = strdup(""); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 264 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(3) - (3)].sval)) + 20);
        sprintf((yyval.sval), "else {\n%s}\n", (yyvsp[(3) - (3)].sval));
        free((yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 273 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(3) - (4)].sval)) + 50);
        sprintf((yyval.sval), "while(true) {\n%s}\n", (yyvsp[(3) - (4)].sval));
        free((yyvsp[(3) - (4)].sval));
    ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 281 "parser.y"
    { (yyval.sval) = concatenarExpressao("==", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 282 "parser.y"
    { (yyval.sval) = concatenarExpressao("!=", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 283 "parser.y"
    { (yyval.sval) = concatenarExpressao("<", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 284 "parser.y"
    { (yyval.sval) = concatenarExpressao(">", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 285 "parser.y"
    { (yyval.sval) = concatenarExpressao("<=", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 286 "parser.y"
    { (yyval.sval) = concatenarExpressao(">=", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 287 "parser.y"
    { (yyval.sval) = concatenarExpressao("+", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 288 "parser.y"
    { (yyval.sval) = concatenarExpressao("-", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 289 "parser.y"
    { (yyval.sval) = concatenarExpressao("*", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 290 "parser.y"
    { (yyval.sval) = concatenarExpressao("/", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 291 "parser.y"
    { (yyval.sval) = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 292 "parser.y"
    { (yyval.sval) = malloc(20); sprintf((yyval.sval), "%d", (yyvsp[(1) - (1)].ival)); ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 293 "parser.y"
    { (yyval.sval) = malloc(10); sprintf((yyval.sval), (yyvsp[(1) - (1)].ival) ? "true" : "false"); ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 294 "parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 295 "parser.y"
    { (yyval.sval) = strdup((yyvsp[(1) - (1)].sval)); free((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 296 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 297 "parser.y"
    { (yyval.sval) = strdup("Serial.readString()"); ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 302 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "digitalRead(%s)", (yyvsp[(2) - (2)].sval));
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 308 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "analogRead(%s)", (yyvsp[(2) - (2)].sval));
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 316 "parser.y"
    { (yyval.sval) = strdup(""); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 318 "parser.y"
    {
        (yyval.sval) = malloc(strlen((yyvsp[(1) - (2)].sval)) + strlen((yyvsp[(2) - (2)].sval)) + 1);
        sprintf((yyval.sval), "%s%s", (yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].sval));
        free((yyvsp[(1) - (2)].sval));
        free((yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 328 "parser.y"
    {
        (yyval.sval) = malloc(50);
        sprintf((yyval.sval), "delay(%d);\n", (yyvsp[(2) - (3)].ival));
    ;}
    break;



/* Line 1464 of yacc.c  */
#line 2016 "parser.tab.c"
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



/* Line 1684 of yacc.c  */
#line 334 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d: %s\n", currentLine, s);
}

char* concatenarExpressao(const char* op, char* e1, char* e2) {
    char* result = malloc(strlen(e1) + strlen(e2) + strlen(op) + 4);
    sprintf(result, "(%s %s %s)", e1, op, e2);
    free(e1);
    free(e2);
    return result;
}

char* processarHttp(const char* url, const char* dados) {
    char* result = malloc(500);
    sprintf(result,
        "HTTPClient http;\n"
        "http.begin(%s);\n"
        "http.addHeader(\"Content-Type\", \"application/x-www-form-urlencoded\");\n"
        "int httpResponseCode = http.POST(%s);\n"
        "http.end();\n",
        url, dados);
    return result;
}

int main(int argc, char *argv[]) {
    yydebug = 1;
    output_file = fopen("saida.cpp", "w");
    if(!output_file) {
        perror("Erro ao criar arquivo de saída");
        return 1;
    }

    fprintf(output_file, "#include <Arduino.h>\n");
    fprintf(output_file, "#include <WiFi.h>\n");
    fprintf(output_file, "#include <HTTPClient.h>\n\n");
    fprintf(output_file, "// Configuração do PWM\n");
    fprintf(output_file, "int canalPWM = 0;\n\n");

    yyparse();
    return 0;
}
