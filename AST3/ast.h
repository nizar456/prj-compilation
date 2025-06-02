#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>

// Enum for AST node types
typedef enum {
    AST_PROGRAM,//1
    AST_INSTRUCTION_LIST,//2
    AST_VARIABLE_DECLARATION,//3
    AST_VARIABLE_AFFECTATION,//4
    AST_ARRAY_DECLARATION,//5
    AST_LIST_INITIALIZATION,//6
    AST_DICT_INITIALIZATION,//7
    AST_EXPRESSION,//8
    AST_FUNCTION_CALL,//9
    AST_LITERAL,//10
    AST_IDENTIFIER,//11
    AST_TYPE,//12
    AST_FUNCTION_DECL,//13
    AST_PROCEDURE_DECL,//14
    AST_PARAM_LIST,//15
    AST_PARAM,//16
    AST_ARGUMENT_LIST,//17
    AST_ARGUMENT,//18
    // ... add more as needed
} ASTNodeType;

typedef struct ASTNode ASTNode;

struct ASTNode {
    ASTNodeType type;
    char *value; // For identifiers, literals, etc.
    int num_value; // For numeric values if needed
    double real_value; // For real values if needed
    ASTNode **children;
    int child_count;
};

ASTNode *create_ast_node(ASTNodeType type, const char *value);
ASTNode *add_child(ASTNode *parent, ASTNode *child);
void print_ast(ASTNode *node, int indent);
const char* ast_node_type_to_string(ASTNodeType type);
void free_ast(ASTNode *node);

#endif // AST_H
