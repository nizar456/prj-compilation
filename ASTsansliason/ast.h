#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_INSTRUCTION_LIST,
    NODE_DECLARATION,
    NODE_FUNCTION_DECL,
    NODE_PROCEDURE_DECL,
    NODE_ASSIGNMENT,
    NODE_VARIABLE,
    NODE_CONSTANT,
    NODE_EXPRESSION,
    NODE_BINARY_EXPRESSION,
    NODE_UNARY_EXPRESSION,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_CALL,
    NODE_INPUT,
    NODE_OUTPUT,
    NODE_TRY_CATCH,
    NODE_RAISE,
    NODE_COMMENT,
    NODE_COMPLEXITY,
    NODE_EXPLAIN
} NodeType;

typedef struct ASTNode ASTNode;

typedef struct {
    char* type;
    char* name;
} Parameter;

typedef struct ParameterList {
    Parameter* params;
    int param_count;
} ParameterList;

typedef struct Instruction {
    ASTNode* node;
    struct Instruction* next;
} Instruction;

typedef struct {
    char* var_type;
    char* var_name;
    ASTNode* value;
} Assignment;

typedef enum { OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_EQ, OP_LT, OP_GT } Operator;

typedef struct {
    ASTNode* left;
    Operator op;
    ASTNode* right;
} BinaryExpression;

typedef struct {
    Operator op;
    ASTNode* expr;
} UnaryExpression;

struct ASTNode {
    NodeType type;
    union {
        struct {
            char* return_type;
            char* name;
            ParameterList params;
            Instruction* body;
        } function_decl;

        struct {
            char* name;
            ParameterList params;
            Instruction* body;
        } procedure_decl;

        Assignment assignment;
        BinaryExpression binary_expr;
        UnaryExpression unary_expr;

        struct {
            ASTNode* condition;
            Instruction* body;
        } loop;

        struct {
            char* name;
            ASTNode** arguments;
            int arg_count;
        } func_call;

        struct {
            ASTNode* expr;
        } input_output;

        struct {
            ASTNode* body;
            ASTNode* error_handling;
        } try_catch;

        struct {
            char* text;
        } comment;
        
        struct {
            char* value;
        } constant;
        
        struct {
            char* name;
        } variable;
    };
};

ParameterList create_parameter_list(Parameter* params, int count);
Instruction* create_instruction(ASTNode* node);
void append_instruction(Instruction** list, Instruction* new_instr);
ASTNode* create_function_declaration(char* return_type, char* name, ParameterList params, Instruction* body);
ASTNode* create_procedure_declaration(char* name, ParameterList params, Instruction* body);
ASTNode* create_assignment(char* var_type, char* var_name, ASTNode* value);
ASTNode* create_binary_expression(ASTNode* left, Operator op, ASTNode* right);
ASTNode* create_unary_expression(Operator op, ASTNode* expr);
ASTNode* create_variable(char* name);
ASTNode* create_constant(char* value);
ASTNode* create_while_loop(ASTNode* condition, Instruction* body);
ASTNode* create_function_call(char* name, ASTNode** args, int arg_count);
void print_ast(ASTNode* node, int indent);
void free_ast(ASTNode* node);

#endif // AST_H
