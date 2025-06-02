#include "ast.h"
#include <string.h>

const char* ast_node_type_to_string(ASTNodeType type) {
    switch(type) {
        case AST_PROGRAM: return "PROGRAM";
        case AST_INSTRUCTION_LIST: return "INSTRUCTION_LIST";
        case AST_VARIABLE_DECLARATION: return "VARIABLE_DECLARATION";
        case AST_VARIABLE_AFFECTATION: return "VARIABLE_AFFECTATION";
        case AST_ARRAY_DECLARATION: return "ARRAY_DECLARATION";
        case AST_LIST_INITIALIZATION: return "LIST_INITIALIZATION";
        case AST_DICT_INITIALIZATION: return "DICT_INITIALIZATION";
        case AST_EXPRESSION: return "EXPRESSION";
        case AST_FUNCTION_CALL: return "FUNCTION_CALL";
        case AST_LITERAL: return "LITERAL";
        case AST_IDENTIFIER: return "IDENTIFIER";
        case AST_TYPE: return "TYPE";
        case AST_FUNCTION_DECL: return "FUNCTION_DECL";
        case AST_PROCEDURE_DECL: return "PROCEDURE_DECL";
        case AST_PARAM_LIST: return "PARAM_LIST";
        case AST_PARAM: return "PARAM";
        case AST_ARGUMENT_LIST: return "ARGUMENT_LIST";
        case AST_ARGUMENT: return "ARGUMENT";
        default: return "UNKNOWN";
    }
}

ASTNode *create_ast_node(ASTNodeType type, const char *value) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->num_value = 0;
    node->real_value = 0.0;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

ASTNode *add_child(ASTNode *parent, ASTNode *child) {
    parent->children = (ASTNode **)realloc(parent->children, sizeof(ASTNode *) * (parent->child_count + 1));
    parent->child_count++;
    parent->children[parent->child_count - 1] = child;
    return parent;
}

void print_ast(ASTNode *node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    printf("Node type: %s", ast_node_type_to_string(node->type));
    if (node->value) printf(", value: %s", node->value);
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        print_ast(node->children[i], indent + 1);
    }
}

void free_ast(ASTNode *node) {
    if (!node) return;
    if (node->value) free(node->value);
    for (int i = 0; i < node->child_count; i++) {
        free_ast(node->children[i]);
    }
    if (node->children) free(node->children);
    free(node);
}
