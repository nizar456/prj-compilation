/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "sniptor.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

int yylex(void);
void yyerror(const char *s);
int is_valid = 1;

char* concat(const char* a, const char* b) {
    size_t len = strlen(a) + strlen(b) + 1;
    char* result = malloc(len);
    if (!result) exit(1);
    strcpy(result, a);
    strcat(result, b);
    return result;
}

char* concat3(const char* a, const char* b, const char* c) {
    size_t len = strlen(a) + strlen(b) + strlen(c) + 1;
    char* result = malloc(len);
    if (!result) exit(1);
    strcpy(result, a);
    strcat(result, b);
    strcat(result, c);
    return result;
}

const char* type_token_to_string(int token) {
    switch(token) {
        case INT: return "int";
        case FLT: return "flt";
        case CHR: return "chr";
        case DBL: return "dbl";
        case STR: return "str";
        case BOL: return "bol";
        case LST: return "lst";
        case DICT: return "dict";
        default: return "UNKNOWN";
    }
}

/* Line 371 of yacc.c  */
#line 112 "sniptor.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sniptor.tab.h".  */
#ifndef YY_YY_SNIPTOR_TAB_H_INCLUDED
# define YY_YY_SNIPTOR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLT = 259,
     CHR = 260,
     DBL = 261,
     STR = 262,
     BOL = 263,
     LST = 264,
     DICT = 265,
     NUMBER = 266,
     REAL = 267,
     CHAR = 268,
     STRING = 269,
     IDENTIFIER = 270,
     COMPLEXITY = 271,
     EXPLAIN = 272,
     PROTECT = 273,
     CAPTURE = 274,
     RAISE = 275,
     CONTAINS = 276,
     SIZE = 277,
     ACT = 278,
     CASE = 279,
     CUT = 280,
     SKIP = 281,
     CREATE = 282,
     FUNCTION = 283,
     PROCEDURE = 284,
     TYPE = 285,
     SHOW = 286,
     ENTER = 287,
     TRUE = 288,
     FALSE = 289,
     REPEAT = 290,
     FOR = 291,
     WHILE = 292,
     FROM = 293,
     TO = 294,
     WHEN = 295,
     DO = 296,
     OTHERWISE = 297,
     ASSIGN = 298,
     LBRACKET = 299,
     RBRACKET = 300,
     LBRACE = 301,
     RBRACE = 302,
     LPAREN = 303,
     RPAREN = 304,
     END_INSTR = 305,
     COLON = 306,
     COMMA = 307,
     RETURN_FUNC = 308,
     CONST_MARKER = 309,
     COMMENT = 310,
     SYNTAX_HELP = 311,
     GT = 312,
     GTE = 313,
     LT = 314,
     LTE = 315,
     EQ = 316,
     NEQ = 317,
     SQ = 318,
     MOD = 319,
     FACT = 320,
     POW = 321,
     ABS = 322,
     AND = 323,
     OR = 324,
     NOT = 325,
     XOR = 326,
     NEGATIVE_VALUE_ERROR = 327,
     ZERO_DIVISION_ERROR = 328,
     NEG = 329
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 47 "sniptor.y"

    char *str;
    int num;
    double real;
    char chr;


/* Line 387 of yacc.c  */
#line 237 "sniptor.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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

#endif /* !YY_YY_SNIPTOR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 278 "sniptor.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   910

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    78,     2,     2,
       2,     2,    76,    74,     2,    75,     2,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    79,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    80
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    49,    56,    63,    70,    77,    79,    83,
      87,    93,    98,   100,   102,   104,   106,   108,   110,   112,
     114,   118,   122,   126,   130,   134,   138,   142,   146,   149,
     153,   157,   161,   165,   169,   173,   177,   181,   184,   186,
     188,   190,   192,   194,   196,   198,   200,   206,   211,   214,
     215,   224,   229,   237,   244,   249,   254,   259,   264,   277,
     286,   295,   299,   303,   317,   327,   331,   333,   334,   337,
     343,   348,   352,   354,   355,   357,   369,   371,   373,   375,
     380,   385
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      82,     0,    -1,    83,    -1,    83,    84,    -1,    -1,    85,
      -1,    91,    -1,    86,    -1,    87,    -1,    88,    -1,    94,
      -1,    98,    -1,   100,    -1,   106,    -1,   107,    -1,   110,
      -1,   104,    -1,   105,    -1,   114,    -1,   116,    -1,   117,
      -1,   118,    -1,    92,    15,    43,    93,    50,    -1,    54,
      92,    15,    43,    93,    50,    -1,     9,    15,    44,    11,
      45,    50,    -1,     9,    15,    44,    89,    45,    50,    -1,
      10,    15,    46,    90,    47,    50,    -1,    93,    -1,    89,
      52,    93,    -1,    14,    51,    14,    -1,    90,    52,    14,
      51,    14,    -1,    15,    43,    93,    50,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    93,    74,    93,    -1,    93,    75,
      93,    -1,    93,    76,    93,    -1,    93,    77,    93,    -1,
      93,    78,    93,    -1,    93,    79,    93,    -1,    93,    68,
      93,    -1,    93,    69,    93,    -1,    70,    93,    -1,    93,
      71,    93,    -1,    93,    57,    93,    -1,    93,    58,    93,
      -1,    93,    59,    93,    -1,    93,    60,    93,    -1,    93,
      62,    93,    -1,    93,    61,    93,    -1,    48,    93,    49,
      -1,    75,    93,    -1,    15,    -1,    11,    -1,    12,    -1,
      14,    -1,    13,    -1,    33,    -1,    34,    -1,   111,    -1,
      23,    46,    95,    97,    47,    -1,    23,    46,    95,    47,
      -1,    95,    96,    -1,    -1,    40,    48,    93,    49,    41,
      46,    83,    47,    -1,    42,    46,    83,    47,    -1,    23,
      48,    15,    49,    46,    99,    47,    -1,    99,    24,    11,
      51,    83,    25,    -1,    42,    51,    83,    25,    -1,    35,
      46,   101,    47,    -1,    35,    46,   102,    47,    -1,    35,
      46,   103,    47,    -1,    36,    48,    15,    38,    11,    39,
      11,    49,    41,    46,    83,    47,    -1,    37,    48,    93,
      49,    41,    46,    83,    47,    -1,    41,    46,    83,    47,
      37,    48,    93,    49,    -1,    32,    14,    50,    -1,    31,
      93,    50,    -1,    27,    92,    28,    15,    48,   108,    49,
      46,    83,    53,    93,    50,    47,    -1,    27,    29,    15,
      48,   108,    49,    46,    83,    47,    -1,   108,    52,   109,
      -1,   109,    -1,    -1,    92,    15,    -1,    15,    48,   112,
      49,    50,    -1,    15,    48,   112,    49,    -1,   112,    52,
     113,    -1,   113,    -1,    -1,    93,    -1,    18,    46,    83,
      47,    19,    48,   115,    49,    46,    83,    47,    -1,    73,
      -1,    72,    -1,    15,    -1,    17,    46,    83,    47,    -1,
      16,    46,    83,    47,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    89,    90,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   113,   117,   123,   129,   135,   141,   142,   145,
     146,   149,   151,   152,   153,   154,   155,   156,   157,   158,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   190,   191,   194,   195,
     198,   200,   202,   204,   205,   207,   208,   209,   211,   213,
     215,   217,   219,   221,   223,   225,   226,   227,   230,   236,
     238,   240,   241,   242,   245,   247,   249,   249,   249,   251,
     253,   255
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLT", "CHR", "DBL", "STR", "BOL",
  "LST", "DICT", "NUMBER", "REAL", "CHAR", "STRING", "IDENTIFIER",
  "COMPLEXITY", "EXPLAIN", "PROTECT", "CAPTURE", "RAISE", "CONTAINS",
  "SIZE", "ACT", "CASE", "CUT", "SKIP", "CREATE", "FUNCTION", "PROCEDURE",
  "TYPE", "SHOW", "ENTER", "TRUE", "FALSE", "REPEAT", "FOR", "WHILE",
  "FROM", "TO", "WHEN", "DO", "OTHERWISE", "ASSIGN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "END_INSTR", "COLON",
  "COMMA", "RETURN_FUNC", "CONST_MARKER", "COMMENT", "SYNTAX_HELP", "GT",
  "GTE", "LT", "LTE", "EQ", "NEQ", "SQ", "MOD", "FACT", "POW", "ABS",
  "AND", "OR", "NOT", "XOR", "NEGATIVE_VALUE_ERROR", "ZERO_DIVISION_ERROR",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "NEG", "$accept", "program",
  "instruction_list", "instruction", "variable_declaration",
  "array_declaration", "list_initialization", "dict_initialization",
  "value_list", "key_value_list", "variable_affectation", "type",
  "expression", "conditional_statement", "when_clause_list", "when_clause",
  "otherwise_clause", "multiple_choice_statement", "case_list",
  "loop_statement", "for_loop", "while_loop", "do_while_loop",
  "input_statement", "output_statement", "function_declaration",
  "procedure_declaration", "parameter_list", "parameter", "procedure_call",
  "function_call", "argument_list", "argument", "error_handling",
  "error_type", "explain_statement", "complexity_statement", "comment", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,    43,    45,    42,    47,    37,    94,
     329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    87,    88,    89,    89,    90,
      90,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    97,    98,    99,    99,   100,   100,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   108,   108,   109,   110,
     111,   112,   112,   112,   113,   114,   115,   115,   115,   116,
     117,   118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     6,     6,     6,     1,     3,     3,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     0,
       8,     4,     7,     6,     4,     4,     4,     4,    12,     8,
       8,     3,     3,    13,     9,     3,     1,     0,     2,     5,
       4,     3,     1,     0,     1,    11,     1,     1,     1,     4,
       4,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     3,     5,     7,     8,     9,     6,     0,
      10,    11,    12,    16,    17,    13,    14,    15,    18,    19,
      20,    21,     0,     0,     0,    93,     4,     4,     4,    69,
       0,    38,    39,     0,     0,    59,    60,    62,    61,    58,
      63,    64,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,    94,     0,    92,     0,     0,     0,
       0,     0,     0,     0,    93,     0,    48,    57,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,    27,     0,     0,    31,     0,
       0,   100,    99,     0,     0,     0,    67,    68,     0,     0,
      87,     0,     0,    56,    50,    51,    52,    53,    55,    54,
      46,    47,    49,    40,    41,    42,    43,    44,    45,     0,
       0,     4,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    91,     0,     0,     4,    66,     0,
       0,     0,    86,    87,    90,     0,     0,     0,     0,    22,
      24,    25,    28,    29,    26,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,    23,     0,
      98,    97,    96,     0,     0,    71,     4,     0,    72,     4,
      85,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     4,     0,     4,     0,     4,     4,    74,     4,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    95,    70,    73,     0,     0,     0,     4,    83,     0,
      78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    23,    24,    25,    26,    27,   114,   117,
      28,    29,    74,    30,    80,   127,   128,    31,   190,    32,
     108,   109,   110,    33,    34,    35,    36,   171,   172,    37,
      66,    75,    76,    38,   203,    39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
     -55,     7,   630,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
      36,    37,    11,   -38,    12,    21,    -7,     9,    16,    43,
      42,   217,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    53,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,    45,    54,    16,    16,   -55,   -55,   -55,   -55,
      84,   -55,   -55,    93,    79,   -55,   -55,   -55,   -55,    67,
     -55,   -55,    16,    16,    16,   687,   -55,    66,    24,   102,
      75,    22,   110,   710,   802,    17,   -55,   181,   234,   267,
       0,    76,    85,   119,    16,    52,   825,   -55,   -55,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,   -55,    87,    88,    94,    91,    95,
      96,   101,    16,   100,   -41,   802,   104,    -4,   -55,    89,
      16,   -55,   -55,   127,    99,   111,   -55,   -55,   109,   112,
     217,   115,    38,   -55,   -54,   -54,   -54,   -54,   831,   831,
     825,    92,    92,    26,    26,    80,    80,    80,    80,   150,
      16,   -55,   -55,   -55,   -55,    16,   733,   122,   123,    16,
     160,   125,   163,   -55,   -55,   131,    16,   -55,   -55,   151,
     177,    44,   -55,   217,   -55,   156,   618,   300,   756,   -55,
     -55,   -55,   802,   -55,   -55,   144,   -10,   641,   333,   149,
     -15,   -55,   155,   217,    46,   192,   164,   170,   -55,   195,
     -55,   -55,   -55,   161,   173,   -55,   -55,   200,   -55,   -55,
     -55,   169,   178,   172,   182,   -55,   183,   185,   366,   194,
     399,   -55,   221,   -55,    16,   -55,   -55,   -55,   -55,   -55,
     432,   184,   465,   664,   498,   531,   564,    16,   193,   -55,
     -55,   -55,   -55,   -55,   779,   201,   199,   -55,   -55,   597,
     -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -45,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -11,   -18,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,    81,    55,   -55,
     -55,   171,   133,   -55,   -55,   -55,   -55,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,    77,    78,    79,   158,   200,    54,     3,    46,   207,
      69,   159,     4,     5,     6,     7,     8,     9,    51,    52,
      98,    99,   100,   101,   102,   103,    73,    55,    56,    57,
      58,    59,   208,   113,    56,    57,    58,    59,    53,    49,
     124,    50,   125,   161,    85,    86,    87,   126,   162,    60,
      61,    42,    43,   115,    44,    60,    61,    67,    47,    45,
     105,   106,   201,   202,    62,   107,   119,    48,    70,   120,
      62,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    63,   174,    68,    71,
     120,    64,    63,   192,   156,   211,   193,    64,   193,    81,
      72,   133,   100,   101,   102,   103,   177,    83,    82,    89,
      90,    91,    92,    93,    94,    84,   104,   111,   112,   170,
      95,    96,   188,    97,   116,   129,    98,    99,   100,   101,
     102,   103,   176,   130,   131,   149,   150,   178,   152,   163,
     151,   182,   153,   154,   155,   157,   165,   166,   187,    89,
      90,    91,    92,    93,    94,   160,   168,   167,   169,   103,
      95,   218,   170,   173,   220,   175,    98,    99,   100,   101,
     102,   103,   180,   181,   183,   184,   230,   185,   232,   186,
     234,   235,   170,   236,     4,     5,     6,     7,     8,     9,
      10,    11,   191,   189,   195,   199,    12,    13,    14,    15,
     206,   209,   249,   212,    16,   213,   233,   214,    17,   215,
     216,   219,    18,    19,   217,   221,    20,   222,   223,   244,
       4,     5,     6,     7,     8,     9,    51,    52,   121,   225,
     224,   226,   231,   238,   245,    21,    22,     4,     5,     6,
       7,     8,     9,    10,    11,   228,   248,   247,   210,    12,
      13,    14,    15,   164,   194,   132,     0,    16,     0,     0,
       0,    17,     0,     0,     0,    18,    19,     0,     0,    20,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,   122,    12,    13,    14,    15,     0,     0,    21,    22,
      16,     0,     0,     0,    17,     0,     0,     0,    18,    19,
       0,     0,    20,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,   123,    12,    13,    14,    15,     0,
       0,    21,    22,    16,     0,     0,     0,    17,     0,     0,
       0,    18,    19,     0,     0,    20,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,   197,    12,    13,
      14,    15,     0,     0,    21,    22,    16,     0,     0,     0,
      17,     0,     0,     0,    18,    19,     0,     0,    20,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
     205,    12,    13,    14,    15,     0,     0,    21,    22,    16,
       0,   227,     0,    17,     0,     0,     0,    18,    19,     0,
       0,    20,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,    12,    13,    14,    15,     0,     0,
      21,    22,    16,     0,     0,     0,    17,     0,     0,     0,
      18,    19,     0,     0,    20,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,     0,   229,    12,    13,    14,
      15,     0,     0,    21,    22,    16,     0,     0,     0,    17,
       0,     0,     0,    18,    19,     0,     0,    20,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
      12,    13,    14,    15,     0,   237,    21,    22,    16,     0,
       0,     0,    17,     0,     0,     0,    18,    19,     0,     0,
      20,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,   239,    12,    13,    14,    15,     0,     0,    21,
      22,    16,     0,     0,     0,    17,     0,     0,     0,    18,
      19,     0,     0,    20,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,   241,    12,    13,    14,    15,
       0,     0,    21,    22,    16,     0,     0,     0,    17,     0,
       0,     0,    18,    19,     0,     0,    20,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,   242,    12,
      13,    14,    15,     0,     0,    21,    22,    16,     0,   243,
       0,    17,     0,     0,     0,    18,    19,     0,     0,    20,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,     0,    12,    13,    14,    15,     0,     0,    21,    22,
      16,     0,     0,     0,    17,     0,     0,     0,    18,    19,
       0,     0,    20,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,   250,    12,    13,    14,    15,     0,
       0,    21,    22,    16,     0,     0,     0,    17,     0,     0,
       0,    18,    19,     0,     0,    20,     0,   196,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,     0,     0,     0,    21,    22,    95,    96,     0,    97,
     204,     0,    98,    99,   100,   101,   102,   103,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,    95,
      96,     0,    97,   240,     0,    98,    99,   100,   101,   102,
     103,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,    95,    96,     0,    97,     0,    88,    98,    99,
     100,   101,   102,   103,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,    95,    96,     0,    97,     0,
     118,    98,    99,   100,   101,   102,   103,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,    95,    96,
       0,    97,     0,   179,    98,    99,   100,   101,   102,   103,
      89,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,    95,    96,     0,    97,     0,   198,    98,    99,   100,
     101,   102,   103,    89,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,    95,    96,     0,    97,     0,   246,
      98,    99,   100,   101,   102,   103,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,     0,    95,    96,     0,
      97,     0,     0,    98,    99,   100,   101,   102,   103,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
      95,    96,     0,    97,     0,     0,    98,    99,   100,   101,
     102,   103,    89,    90,    91,    92,    93,    94,    89,    90,
      91,    92,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,    98,    99,   100,   101,   102,
     103
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      18,    46,    47,    48,    45,    15,    17,     0,    46,    24,
      21,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      74,    75,    76,    77,    78,    79,    44,    11,    12,    13,
      14,    15,    47,    11,    12,    13,    14,    15,    29,    46,
      40,    48,    42,    47,    62,    63,    64,    47,    52,    33,
      34,    15,    15,    71,    43,    33,    34,    14,    46,    48,
      36,    37,    72,    73,    48,    41,    49,    46,    15,    52,
      48,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    70,    49,    46,    44,
      52,    75,    70,    49,   112,    49,    52,    75,    52,    15,
      46,    49,    76,    77,    78,    79,   151,    28,    15,    57,
      58,    59,    60,    61,    62,    48,    50,    15,    43,   130,
      68,    69,   167,    71,    14,    49,    74,    75,    76,    77,
      78,    79,   150,    48,    15,    48,    48,   155,    47,    50,
      46,   159,    47,    47,    43,    45,    19,    48,   166,    57,
      58,    59,    60,    61,    62,    51,    47,    46,    46,    79,
      68,   206,   173,    48,   209,    15,    74,    75,    76,    77,
      78,    79,    50,    50,    14,    50,   221,    14,   223,    48,
     225,   226,   193,   228,     3,     4,     5,     6,     7,     8,
       9,    10,    15,    42,    38,    51,    15,    16,    17,    18,
      51,    46,   247,    11,    23,    41,   224,    37,    27,    14,
      49,    11,    31,    32,    41,    46,    35,    39,    46,   237,
       3,     4,     5,     6,     7,     8,     9,    10,    47,    46,
      48,    46,    11,    49,    41,    54,    55,     3,     4,     5,
       6,     7,     8,     9,    10,    51,    47,    46,   193,    15,
      16,    17,    18,   120,   173,    84,    -1,    23,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    47,    15,    16,    17,    18,    -1,    -1,    54,    55,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    47,    15,    16,    17,    18,    -1,
      -1,    54,    55,    23,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    47,    15,    16,
      17,    18,    -1,    -1,    54,    55,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      47,    15,    16,    17,    18,    -1,    -1,    54,    55,    23,
      -1,    25,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      54,    55,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    47,    15,    16,    17,
      18,    -1,    -1,    54,    55,    23,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    -1,    -1,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    -1,    53,    54,    55,    23,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    47,    15,    16,    17,    18,    -1,    -1,    54,
      55,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    47,    15,    16,    17,    18,
      -1,    -1,    54,    55,    23,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    47,    15,
      16,    17,    18,    -1,    -1,    54,    55,    23,    -1,    25,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    -1,    -1,    54,    55,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    47,    15,    16,    17,    18,    -1,
      -1,    54,    55,    23,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    54,    55,    68,    69,    -1,    71,
      49,    -1,    74,    75,    76,    77,    78,    79,    57,    58,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    71,    49,    -1,    74,    75,    76,    77,    78,
      79,    57,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    -1,    50,    74,    75,
      76,    77,    78,    79,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      50,    74,    75,    76,    77,    78,    79,    57,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    -1,    50,    74,    75,    76,    77,    78,    79,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    71,    -1,    50,    74,    75,    76,
      77,    78,    79,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,    50,
      74,    75,    76,    77,    78,    79,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    57,
      58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    -1,    -1,    74,    75,    76,    77,
      78,    79,    57,    58,    59,    60,    61,    62,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    74,    75,    76,    77,    78,
      79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    82,    83,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    15,    16,    17,    18,    23,    27,    31,    32,
      35,    54,    55,    84,    85,    86,    87,    88,    91,    92,
      94,    98,   100,   104,   105,   106,   107,   110,   114,   116,
     117,   118,    15,    15,    43,    48,    46,    46,    46,    46,
      48,     9,    10,    29,    92,    11,    12,    13,    14,    15,
      33,    34,    48,    70,    75,    93,   111,    14,    46,    92,
      15,    44,    46,    93,    93,   112,   113,    83,    83,    83,
      95,    15,    15,    28,    48,    93,    93,    93,    50,    57,
      58,    59,    60,    61,    62,    68,    69,    71,    74,    75,
      76,    77,    78,    79,    50,    36,    37,    41,   101,   102,
     103,    15,    43,    11,    89,    93,    14,    90,    50,    49,
      52,    47,    47,    47,    40,    42,    47,    96,    97,    49,
      48,    15,   112,    49,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    48,
      48,    46,    47,    47,    47,    43,    93,    45,    45,    52,
      51,    47,    52,    50,   113,    19,    48,    46,    47,    46,
      92,   108,   109,    48,    49,    15,    93,    83,    93,    50,
      50,    50,    93,    14,    50,    14,    48,    93,    83,    42,
      99,    15,    49,    52,   108,    38,    49,    47,    50,    51,
      15,    72,    73,   115,    49,    47,    51,    24,    47,    46,
     109,    49,    11,    41,    37,    14,    49,    41,    83,    11,
      83,    46,    39,    46,    48,    46,    46,    25,    51,    47,
      83,    11,    83,    93,    83,    83,    83,    53,    49,    47,
      49,    47,    47,    25,    93,    41,    50,    46,    47,    83,
      47
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

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 22:
/* Line 1792 of yacc.c  */
#line 114 "sniptor.y"
    {
        ajouter_symbole((yyvsp[(2) - (5)].str), type_token_to_string((yyvsp[(1) - (5)].num)), 0, (yylsp[(2) - (5)]).first_line);
    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 118 "sniptor.y"
    {
        ajouter_symbole((yyvsp[(3) - (6)].str), type_token_to_string((yyvsp[(2) - (6)].num)), 1, (yylsp[(3) - (6)]).first_line);
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 124 "sniptor.y"
    {
    ajouter_symbole((yyvsp[(2) - (6)].str), "lst", 0, (yylsp[(2) - (6)]).first_line);
}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 130 "sniptor.y"
    {
    ajouter_symbole((yyvsp[(2) - (6)].str), "lst", 0, (yylsp[(2) - (6)]).first_line);
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 136 "sniptor.y"
    {
    ajouter_symbole((yyvsp[(2) - (6)].str), "dict", 0, (yylsp[(2) - (6)]).first_line);
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 151 "sniptor.y"
    { (yyval.num) = INT; }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 152 "sniptor.y"
    { (yyval.num) = FLT; }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 153 "sniptor.y"
    { (yyval.num) = CHR; }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 154 "sniptor.y"
    { (yyval.num) = DBL; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 155 "sniptor.y"
    { (yyval.num) = STR; }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 156 "sniptor.y"
    { (yyval.num) = BOL; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 157 "sniptor.y"
    { (yyval.num) = LST; }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 158 "sniptor.y"
    { (yyval.num) = DICT; }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 162 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " + ", (yyvsp[(3) - (3)].str)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 163 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " - ", (yyvsp[(3) - (3)].str)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 164 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " * ", (yyvsp[(3) - (3)].str)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 165 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " / ", (yyvsp[(3) - (3)].str)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 166 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " % ", (yyvsp[(3) - (3)].str)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 167 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " ^ ", (yyvsp[(3) - (3)].str)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 168 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " AND ", (yyvsp[(3) - (3)].str)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 169 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " OR ", (yyvsp[(3) - (3)].str)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 170 "sniptor.y"
    { (yyval.str) = concat("NOT ", (yyvsp[(2) - (2)].str)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 171 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " XOR ", (yyvsp[(3) - (3)].str)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 172 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " > ", (yyvsp[(3) - (3)].str)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 173 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " >= ", (yyvsp[(3) - (3)].str)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 174 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " < ", (yyvsp[(3) - (3)].str)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 175 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " <= ", (yyvsp[(3) - (3)].str)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 176 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " != ", (yyvsp[(3) - (3)].str)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 177 "sniptor.y"
    { (yyval.str) = concat3((yyvsp[(1) - (3)].str), " == ", (yyvsp[(3) - (3)].str)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 178 "sniptor.y"
    { (yyval.str) = (yyvsp[(2) - (3)].str); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 179 "sniptor.y"
    { (yyval.str) = concat("-", (yyvsp[(2) - (2)].str)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 180 "sniptor.y"
    { (yyval.str) = strdup((yyvsp[(1) - (1)].str)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 181 "sniptor.y"
    { (yyval.str) = strdup("NUMBER"); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 182 "sniptor.y"
    { (yyval.str) = strdup("REAL"); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 183 "sniptor.y"
    { (yyval.str) = strdup((yyvsp[(1) - (1)].str)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 184 "sniptor.y"
    { (yyval.str) = strdup("CHAR"); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 185 "sniptor.y"
    { (yyval.str) = strdup("TRUE"); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 186 "sniptor.y"
    { (yyval.str) = strdup("FALSE"); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 187 "sniptor.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 231 "sniptor.y"
    {
    ajouter_symbole((yyvsp[(2) - (2)].str), type_token_to_string((yyvsp[(1) - (2)].num)), 0, (yylsp[(2) - (2)]).first_line);
}
    break;


/* Line 1792 of yacc.c  */
#line 2197 "sniptor.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


/* Line 2055 of yacc.c  */
#line 257 "sniptor.y"


int main() {
    yylloc.first_line = 1;
    yylloc.first_column = 1;
    yyparse();
    if (is_valid) {
        printf("Grammaire valide\n\nTable des symboles :\n");
        for (int i = 0; i < nb_symboles; i++) {
            printf("Nom: %s, Type: %s, Constante: %s, Ligne: %d\n",
                   table_des_symboles[i].nom,
                   table_des_symboles[i].type,
                   table_des_symboles[i].isConst ? "Oui" : "Non",
                   table_des_symboles[i].ligne);
        }
    } else {
        printf("Analyse invalide.\n");
    }
    return 0;
}

void yyerror(const char *s) {
    is_valid = 0;
    fprintf(stderr, "Erreur syntaxique ligne %d, colonne %d : %s\n", yylloc.first_line, yylloc.first_column, s);
}
