%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "semantique.h"

int yylex(void);
void yyerror(const char *s);
int is_valid = 1;
ASTNode *root = NULL;

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
    ASTNode *node;
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
%type <node> program instruction_list instruction variable_declaration variable_affectation array_declaration list_initialization dict_initialization expression function_call when_clause_list argument_list argument function_declaration procedure_declaration parameter_list parameter

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

program: instruction_list { root = $1; $$ = root; };

instruction_list: instruction_list instruction { $$ = add_child($1, $2); }
                | /* empty */ { $$ = create_ast_node(AST_INSTRUCTION_LIST, NULL); }
                ;

instruction: variable_declaration { $$ = $1; }
           | variable_affectation { $$ = $1; }
           | array_declaration { $$ = $1; }
           | list_initialization { $$ = $1; }
           | dict_initialization { $$ = $1; }
           | conditional_statement { $$ = NULL; }
           | multiple_choice_statement { $$ = NULL; }
           | loop_statement { $$ = NULL; }
           | function_declaration { $$ = $1; }
           | procedure_declaration { $$ = $1; }
           | procedure_call { $$ = NULL; }
           | input_statement { $$ = NULL; }
           | output_statement { $$ = NULL; }
           | error_handling { $$ = NULL; }
           | explain_statement { $$ = NULL; }
           | complexity_statement { $$ = NULL; }
           | comment { $$ = NULL; }
           | /* ...other instructions... */ { $$ = NULL; }
           ;

variable_declaration: 
      type IDENTIFIER ASSIGN expression END_INSTR
    {
        ajouter_symbole($2, type_token_to_string($1), 0, @2.first_line);
        ASTNode *type_node = create_ast_node(AST_TYPE, type_token_to_string($1));
        ASTNode *id_node = create_ast_node(AST_IDENTIFIER, $2);
        ASTNode *assign_node = create_ast_node(AST_VARIABLE_DECLARATION, NULL);
        add_child(assign_node, type_node);
        add_child(assign_node, id_node);
        add_child(assign_node, $4);
        $$ = assign_node;
    }
    | CONST_MARKER type IDENTIFIER ASSIGN expression END_INSTR
    {
        ajouter_symbole($3, type_token_to_string($2), 1, @3.first_line);
        ASTNode *type_node = create_ast_node(AST_TYPE, type_token_to_string($2));
        ASTNode *id_node = create_ast_node(AST_IDENTIFIER, $3);
        ASTNode *assign_node = create_ast_node(AST_VARIABLE_DECLARATION, "const");
        add_child(assign_node, type_node);
        add_child(assign_node, id_node);
        add_child(assign_node, $5);
        $$ = assign_node;
    }
    ;

array_declaration: LST IDENTIFIER LBRACKET NUMBER RBRACKET END_INSTR
{
    ajouter_symbole($2, "lst", 0, @2.first_line);
    $$ = NULL;
}
;

list_initialization: LST IDENTIFIER LBRACKET value_list RBRACKET END_INSTR
{
    ajouter_symbole($2, "lst", 0, @2.first_line);
    $$ = NULL;
}
;

dict_initialization: DICT IDENTIFIER LBRACE key_value_list RBRACE END_INSTR
{
    ajouter_symbole($2, "dict", 0, @2.first_line);
    $$ = NULL;
}
;

value_list: expression
          | value_list COMMA expression
          ;

key_value_list: STRING COLON STRING
              | key_value_list COMMA STRING COLON STRING
              ;

variable_affectation: IDENTIFIER ASSIGN expression END_INSTR {
    ASTNode *id_node = create_ast_node(AST_IDENTIFIER, $1);
    ASTNode *aff_node = create_ast_node(AST_VARIABLE_AFFECTATION, NULL);
    add_child(aff_node, id_node);
    add_child(aff_node, $3);
    $$ = aff_node;
};

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
      expression '+' expression { $$ = create_ast_node(AST_EXPRESSION, "+"); add_child($$, $1); add_child($$, $3); }
    | expression '-' expression { $$ = create_ast_node(AST_EXPRESSION, "-"); add_child($$, $1); add_child($$, $3); }
    | expression '*' expression { $$ = create_ast_node(AST_EXPRESSION, "*"); add_child($$, $1); add_child($$, $3); }
    | expression '/' expression { $$ = create_ast_node(AST_EXPRESSION, "/"); add_child($$, $1); add_child($$, $3); }
    | expression '%' expression { $$ = create_ast_node(AST_EXPRESSION, "%"); add_child($$, $1); add_child($$, $3); }
    | expression '^' expression { $$ = create_ast_node(AST_EXPRESSION, "^"); add_child($$, $1); add_child($$, $3); }
    | expression AND expression { $$ = create_ast_node(AST_EXPRESSION, "AND"); add_child($$, $1); add_child($$, $3); }
    | expression OR expression  { $$ = create_ast_node(AST_EXPRESSION, "OR"); add_child($$, $1); add_child($$, $3); }
    | NOT expression            { $$ = create_ast_node(AST_EXPRESSION, "NOT"); add_child($$, $2); }
    | expression XOR expression { $$ = create_ast_node(AST_EXPRESSION, "XOR"); add_child($$, $1); add_child($$, $3); }
    | expression GT expression  { $$ = create_ast_node(AST_EXPRESSION, "> "); add_child($$, $1); add_child($$, $3); }
    | expression GTE expression { $$ = create_ast_node(AST_EXPRESSION, ">="); add_child($$, $1); add_child($$, $3); }
    | expression LT expression  { $$ = create_ast_node(AST_EXPRESSION, "< "); add_child($$, $1); add_child($$, $3); }
    | expression LTE expression { $$ = create_ast_node(AST_EXPRESSION, "<="); add_child($$, $1); add_child($$, $3); }
    | expression NEQ expression { $$ = create_ast_node(AST_EXPRESSION, "!="); add_child($$, $1); add_child($$, $3); }
    | expression EQ expression  { $$ = create_ast_node(AST_EXPRESSION, "=="); add_child($$, $1); add_child($$, $3); }
    | LPAREN expression RPAREN  { $$ = $2; }
    | '-' expression %prec NEG  { $$ = create_ast_node(AST_EXPRESSION, "NEG"); add_child($$, $2); }
    | IDENTIFIER                { $$ = create_ast_node(AST_IDENTIFIER, $1); }
    | NUMBER { char buf[32]; snprintf(buf, sizeof(buf), "%d", $1); $$ = create_ast_node(AST_LITERAL, buf); }
    | REAL { char buf[32]; snprintf(buf, sizeof(buf), "%f", $1); $$ = create_ast_node(AST_LITERAL, buf); }
    | STRING { $$ = create_ast_node(AST_LITERAL, $1); }
    | CHAR { char buf[2] = { $1, 0 }; $$ = create_ast_node(AST_LITERAL, buf); }
    | TRUE { $$ = create_ast_node(AST_LITERAL, "TRUE"); }
    | FALSE { $$ = create_ast_node(AST_LITERAL, "FALSE"); }
    | function_call { $$ = $1; }
    ;

conditional_statement: ACT LBRACE when_clause_list otherwise_clause RBRACE
                     | ACT LBRACE when_clause_list RBRACE  
                     ;

when_clause_list: when_clause_list when_clause { $$ = $1; }
                | /* empty */ { $$ = NULL; }
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

function_declaration: CREATE type FUNCTION IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RETURN_FUNC expression END_INSTR RBRACE {
    ASTNode *node = create_ast_node(AST_FUNCTION_DECL, NULL);
    add_child(node, create_ast_node(AST_TYPE, type_token_to_string($2)));
    add_child(node, create_ast_node(AST_IDENTIFIER, $4));
    add_child(node, $6); // parameter_list
    add_child(node, $9); // instruction_list
    add_child(node, $11); // return expression
    $$ = node;
};

procedure_declaration: CREATE PROCEDURE IDENTIFIER LPAREN parameter_list RPAREN LBRACE instruction_list RBRACE {
    ASTNode *node = create_ast_node(AST_PROCEDURE_DECL, NULL);
    add_child(node, create_ast_node(AST_IDENTIFIER, $3));
    add_child(node, $5); // parameter_list
    add_child(node, $8); // instruction_list
    $$ = node;
};

parameter_list: parameter_list COMMA parameter { $$ = add_child($1, $3); }
              | parameter { $$ = create_ast_node(AST_PARAM_LIST, NULL); add_child($$, $1); }
              | /* empty */ { $$ = create_ast_node(AST_PARAM_LIST, NULL); }
              ;

parameter: type IDENTIFIER {
    ajouter_symbole($2, type_token_to_string($1), 0, @2.first_line);
    ASTNode *node = create_ast_node(AST_PARAM, NULL);
    add_child(node, create_ast_node(AST_TYPE, type_token_to_string($1)));
    add_child(node, create_ast_node(AST_IDENTIFIER, $2));
    $$ = node;
};

procedure_call: IDENTIFIER LPAREN argument_list RPAREN END_INSTR ;

function_call: IDENTIFIER LPAREN argument_list RPAREN {
    ASTNode *node = create_ast_node(AST_FUNCTION_CALL, NULL);
    add_child(node, create_ast_node(AST_IDENTIFIER, $1));
    add_child(node, $3);
    $$ = node;
};

argument_list: argument_list COMMA argument { $$ = add_child($1, $3); }
             | argument { $$ = create_ast_node(AST_ARGUMENT_LIST, NULL); add_child($$, $1); }
             | /* empty */ { $$ = create_ast_node(AST_ARGUMENT_LIST, NULL); }
             ;

argument: expression { ASTNode *node = create_ast_node(AST_ARGUMENT, NULL); add_child(node, $1); $$ = node; };

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
        analyse_semantique(root);
    }
    if (is_valid) {
        printf("Grammaire et sémantique valides\n\nAST :\n");
        print_ast(root, 0);
        printf("\nTable des symboles :\n");
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
    if (root) free_ast(root);
    return 0;
}

void yyerror(const char *s) {
    is_valid = 0;
    fprintf(stderr, "Erreur syntaxique ligne %d, colonne %d : %s\n", yylloc.first_line, yylloc.first_column, s);
}
