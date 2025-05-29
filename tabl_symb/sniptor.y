%{
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
%}

%locations

%union {
    char *str;
    int num;
    double real;
    char chr;
}

%token <num> INT FLT CHR DBL STR BOL LST DICT
%token <num> NUMBER
%token <real> REAL
%token <chr> CHAR
%token <str> STRING IDENTIFIER

%token COMPLEXITY EXPLAIN PROTECT CAPTURE RAISE
%token CONTAINS SIZE ACT CASE CUT SKIP
%token CREATE FUNCTION PROCEDURE TYPE SHOW ENTER
%token TRUE FALSE REPEAT FOR WHILE FROM TO
%token WHEN DO OTHERWISE ASSIGN LBRACKET RBRACKET
%token LBRACE RBRACE LPAREN RPAREN END_INSTR COLON COMMA
%token RETURN_FUNC CONST_MARKER COMMENT SYNTAX_HELP 
%token GT GTE LT LTE EQ NEQ SQ MOD FACT POW ABS
%token AND OR NOT XOR
%token NEGATIVE_VALUE_ERROR ZERO_DIVISION_ERROR

%type <num> type
%type <str> variable_declaration variable_affectation
%type <str> expression function_call

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

program: instruction_list ;

instruction_list: instruction_list instruction
                | /* empty */
                ;

instruction: variable_declaration
           | variable_affectation
           | array_declaration
           | list_initialization
           | dict_initialization
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

variable_declaration: 
      type IDENTIFIER ASSIGN expression END_INSTR
    {
        ajouter_symbole($2, type_token_to_string($1), 0, @2.first_line);
    }
    | CONST_MARKER type IDENTIFIER ASSIGN expression END_INSTR
    {
        ajouter_symbole($3, type_token_to_string($2), 1, @3.first_line);
    }
    ;

array_declaration: LST IDENTIFIER LBRACKET NUMBER RBRACKET END_INSTR
{
    ajouter_symbole($2, "lst", 0, @2.first_line);
}
;

list_initialization: LST IDENTIFIER LBRACKET value_list RBRACKET END_INSTR
{
    ajouter_symbole($2, "lst", 0, @2.first_line);
}
;

dict_initialization: DICT IDENTIFIER LBRACE key_value_list RBRACE END_INSTR
{
    ajouter_symbole($2, "dict", 0, @2.first_line);
}
;

value_list: expression
          | value_list COMMA expression
          ;

key_value_list: STRING COLON STRING
              | key_value_list COMMA STRING COLON STRING
              ;

variable_affectation: IDENTIFIER ASSIGN expression END_INSTR ;

type: INT  { $$ = INT; }
    | FLT  { $$ = FLT; }
    | CHR  { $$ = CHR; }
    | DBL  { $$ = DBL; }
    | STR  { $$ = STR; }
    | BOL  { $$ = BOL; }
    | LST  { $$ = LST; }
    | DICT { $$ = DICT; }
    ;

expression:
      expression '+' expression { $$ = concat3($1, " + ", $3); }
    | expression '-' expression { $$ = concat3($1, " - ", $3); }
    | expression '*' expression { $$ = concat3($1, " * ", $3); }
    | expression '/' expression { $$ = concat3($1, " / ", $3); }
    | expression '%' expression { $$ = concat3($1, " % ", $3); }
    | expression '^' expression { $$ = concat3($1, " ^ ", $3); }
    | expression AND expression { $$ = concat3($1, " AND ", $3); }
    | expression OR expression  { $$ = concat3($1, " OR ", $3); }
    | NOT expression            { $$ = concat("NOT ", $2); }
    | expression XOR expression { $$ = concat3($1, " XOR ", $3); }
    | expression GT expression  { $$ = concat3($1, " > ", $3); }
    | expression GTE expression { $$ = concat3($1, " >= ", $3); }
    | expression LT expression  { $$ = concat3($1, " < ", $3); }
    | expression LTE expression { $$ = concat3($1, " <= ", $3); }
    | expression NEQ expression { $$ = concat3($1, " != ", $3); }
    | expression EQ expression  { $$ = concat3($1, " == ", $3); }
    | LPAREN expression RPAREN  { $$ = $2; }
    | '-' expression %prec NEG  { $$ = concat("-", $2); }
    | IDENTIFIER                { $$ = strdup($1); }
    | NUMBER                    { $$ = strdup("NUMBER"); }
    | REAL                      { $$ = strdup("REAL"); }
    | STRING                    { $$ = strdup($1); }
    | CHAR                      { $$ = strdup("CHAR"); }
    | TRUE                      { $$ = strdup("TRUE"); }
    | FALSE                     { $$ = strdup("FALSE"); }
    | function_call             { $$ = $1; }
    ;

conditional_statement: ACT LBRACE when_clause_list otherwise_clause RBRACE
                     | ACT LBRACE when_clause_list RBRACE  
                     ;

when_clause_list: when_clause_list when_clause
                | /* empty */
                ;

when_clause: WHEN LPAREN expression RPAREN DO LBRACE instruction_list RBRACE ;

otherwise_clause: OTHERWISE LBRACE instruction_list RBRACE ;

multiple_choice_statement: ACT LPAREN IDENTIFIER RPAREN LBRACE case_list RBRACE ;

case_list: case_list CASE NUMBER COLON instruction_list CUT
         | OTHERWISE COLON instruction_list CUT ;

loop_statement: REPEAT LBRACE for_loop RBRACE
              | REPEAT LBRACE while_loop RBRACE
              | REPEAT LBRACE do_while_loop RBRACE ;

for_loop: FOR LPAREN IDENTIFIER FROM NUMBER TO NUMBER RPAREN DO LBRACE instruction_list RBRACE ;

while_loop: WHILE LPAREN expression RPAREN DO LBRACE instruction_list RBRACE ;

do_while_loop: DO LBRACE instruction_list RBRACE WHILE LPAREN expression RPAREN ;

input_statement: ENTER STRING END_INSTR ;

output_statement: SHOW expression END_INSTR ;

function_declaration: CREATE type FUNCTION IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RETURN_FUNC expression END_INSTR RBRACE ;

procedure_declaration: CREATE PROCEDURE IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RBRACE ;

parameter_list: parameter_list COMMA parameter
              | parameter
              | /* empty */
              ;

parameter: type IDENTIFIER
{
    ajouter_symbole($2, type_token_to_string($1), 0, @2.first_line);
}
;

procedure_call: IDENTIFIER LPAREN argument_list RPAREN END_INSTR ;

function_call: IDENTIFIER LPAREN argument_list RPAREN ;

argument_list: argument_list COMMA argument
             | argument
             | /* empty */
             ;

argument: expression ;

error_handling: PROTECT LBRACE instruction_list RBRACE CAPTURE LPAREN error_type RPAREN LBRACE instruction_list RBRACE ;

error_type: ZERO_DIVISION_ERROR | NEGATIVE_VALUE_ERROR | IDENTIFIER ;

explain_statement: EXPLAIN LBRACE instruction_list RBRACE ;

complexity_statement: COMPLEXITY LBRACE instruction_list RBRACE ;

comment: COMMENT ;

%%

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
