/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
     COMPLEXITY = 258,
     EXPLAIN = 259,
     PROTECT = 260,
     CAPTURE = 261,
     RAISE = 262,
     CONTAINS = 263,
     SIZE = 264,
     ACT = 265,
     CASE = 266,
     CUT = 267,
     SKIP = 268,
     CREATE = 269,
     FUNCTION = 270,
     PROCEDURE = 271,
     TYPE = 272,
     SHOW = 273,
     ENTER = 274,
     INT = 275,
     FLT = 276,
     CHR = 277,
     DBL = 278,
     STR = 279,
     BOL = 280,
     LST = 281,
     DICT = 282,
     TRUE = 283,
     FALSE = 284,
     REPEAT = 285,
     FOR = 286,
     WHILE = 287,
     FROM = 288,
     TO = 289,
     WHEN = 290,
     DO = 291,
     OTHERWISE = 292,
     ASSIGN = 293,
     LBRACKET = 294,
     RBRACKET = 295,
     LBRACE = 296,
     RBRACE = 297,
     LPAREN = 298,
     RPAREN = 299,
     END_INSTR = 300,
     COLON = 301,
     COMMA = 302,
     RETURN_FUNC = 303,
     CONST_MARKER = 304,
     COMMENT = 305,
     SYNTAX_HELP = 306,
     GT = 307,
     GTE = 308,
     LT = 309,
     LTE = 310,
     EQ = 311,
     NEQ = 312,
     SQ = 313,
     MOD = 314,
     FACT = 315,
     POW = 316,
     ABS = 317,
     AND = 318,
     OR = 319,
     NOT = 320,
     XOR = 321,
     UNKNOWN = 322,
     NEGATIVE_VALUE_ERROR = 323,
     ZERO_DIVISION_ERROR = 324,
     STRING = 325,
     NUMBER = 326,
     REAL = 327,
     CHAR = 328,
     IDENTIFIER = 329,
     NEG = 330
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 15 "sniptor.y"

    char *str;  // Pour les chaînes de caractères
    int num;    // Pour les entiers
    double real; // Pour les réels
    char chr;   // Pour les caractères


/* Line 2058 of yacc.c  */
#line 140 "sniptor.tab.h"
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
