%{
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int yylex(void);
void yyerror(const char *s);
int is_valid = 1;


%}

%locations

%union {
    char *str;  // Pour les chaînes de caractères
    int num;    // Pour les entiers
    double real; // Pour les réels
    char chr;   // Pour les caractères
}

// Déclaration des tokens
%token COMPLEXITY EXPLAIN PROTECT CAPTURE RAISE
%token CONTAINS SIZE ACT CASE CUT SKIP
%token CREATE FUNCTION PROCEDURE TYPE SHOW ENTER
%token INT FLT CHR DBL STR BOL LST DICT 
%token TRUE FALSE REPEAT FOR WHILE FROM TO
%token WHEN DO OTHERWISE ASSIGN LBRACKET RBRACKET
%token LBRACE RBRACE LPAREN RPAREN END_INSTR COLON COMMA
%token RETURN_FUNC CONST_MARKER COMMENT SYNTAX_HELP 
%token GT GTE LT LTE EQ NEQ SQ MOD FACT POW ABS
%token AND OR NOT XOR UNKNOWN
%token NEGATIVE_VALUE_ERROR ZERO_DIVISION_ERROR
%token <str> STRING 
%token <num> NUMBER
%token <real> REAL
%token <chr> CHAR
%token <str> IDENTIFIER

%left OR XOR
%left AND
%left NOT
%left EQ NEQ
%left GT GTE LT LTE
%left '+' '-'
%left '*' '/' '%'
%right '^'
%right NEG


%%

// Règles de grammaire
program: instruction_list
       ;

instruction_list: instruction_list instruction
                |
                ;

instruction: variable_declaration
           | variable_affectation
           | conditional_statement
           | multiple_choice_statement
           | loop_statement
           | function_declaration
           | procedure_declaration
           | procedure_call
           | input_statement
           | output_statement
           | error_handling
           | explain_statement
           | complexity_statement
           | comment
           ;

variable_declaration: type IDENTIFIER ASSIGN expression END_INSTR
                    | CONST_MARKER type IDENTIFIER ASSIGN expression END_INSTR
                    ;

variable_affectation: IDENTIFIER ASSIGN expression END_INSTR
                    ;

type: INT | FLT | CHR | DBL | STR | BOL | LST | DICT
    ;

expression: expression '+' expression
          | expression '-' expression
          | expression '*' expression
          | expression '/' expression
          | expression '%' expression
          | expression '^' expression
          | expression AND expression
          | expression OR expression
          | NOT expression
          | expression XOR expression
          | expression GT expression
          | expression GTE expression
          | expression LT expression
          | expression LTE expression
          | expression NEQ expression
          | expression EQ expression
          | LPAREN expression RPAREN
          | '-' expression %prec NEG
          | IDENTIFIER
          | NUMBER
          | REAL
          | STRING
          | CHAR
          | TRUE
          | FALSE
          | function_call
          ;

conditional_statement: ACT LBRACE when_clause_list otherwise_clause RBRACE
                     | ACT LBRACE when_clause_list RBRACE  
                     ;

when_clause_list: when_clause_list when_clause
                | 
                ;

when_clause: WHEN LPAREN expression RPAREN DO LBRACE instruction_list RBRACE
           ;

otherwise_clause: OTHERWISE LBRACE instruction_list RBRACE
                ;

multiple_choice_statement: ACT LPAREN IDENTIFIER RPAREN LBRACE case_list RBRACE
                         ;

case_list: case_list CASE NUMBER COLON instruction_list CUT
         | OTHERWISE COLON instruction_list CUT
         ;

loop_statement: REPEAT LBRACE for_loop RBRACE
              | REPEAT LBRACE while_loop RBRACE
              | REPEAT LBRACE do_while_loop RBRACE
              ;

for_loop: FOR LPAREN IDENTIFIER FROM NUMBER TO NUMBER RPAREN DO LBRACE instruction_list RBRACE
        ;

while_loop: WHILE LPAREN expression RPAREN DO LBRACE instruction_list RBRACE
          ;

do_while_loop: DO LBRACE instruction_list RBRACE WHILE LPAREN expression RPAREN
             ;

input_statement: ENTER STRING END_INSTR
               ;

output_statement: SHOW expression END_INSTR
                ;

function_declaration: CREATE type FUNCTION IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RETURN_FUNC expression END_INSTR RBRACE
                   ;

procedure_declaration: CREATE PROCEDURE IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RBRACE
                    ;

parameter_list: parameter_list COMMA parameter
              | parameter
              | 
              ;

parameter: type IDENTIFIER
         ;

procedure_call: IDENTIFIER LPAREN argument_list RPAREN END_INSTR
              ;

function_call: IDENTIFIER LPAREN argument_list RPAREN
             ;

argument_list: argument_list COMMA argument
             | argument
             | 
             ;

argument: expression
        ;

error_handling: PROTECT LBRACE instruction_list RBRACE CAPTURE LPAREN error_type RPAREN LBRACE instruction_list RBRACE
              ;

error_type: ZERO_DIVISION_ERROR | NEGATIVE_VALUE_ERROR | IDENTIFIER
          ;

explain_statement: EXPLAIN LBRACE instruction_list RBRACE
                 ;

complexity_statement: COMPLEXITY LBRACE instruction_list RBRACE
                    ;

comment: COMMENT
       ;

%%

int main() {
    yylloc.first_line = 1;
    yylloc.first_column = 1;
    yyparse();
    if (is_valid) {
        printf("Grammaire valide\n");
    } else {
        printf(" ");
    } 
    return 0;
}

void yyerror(const char *s) {
    is_valid = 0;
    fprintf(stderr, "Erreur syntaxique ligne %d, colonne %d : %s\n", yylloc.first_line, yylloc.first_column, s);
}