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
/* Line 2058 of yacc.c  */
#line 50 "sniptor.y"

    char *str;
    int num;
    double real;
    char chr;
    ASTNode *node;


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
