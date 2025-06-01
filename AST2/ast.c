#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* create_program_node(ASTNode* declarations, ASTNode* instructions) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_PROGRAM;
    node->data_type = TYPE_UNKNOWN;
    node->value = NULL;
    node->left = declarations;
    node->right = instructions;
    node->next = NULL;
    return node;
}

ASTNode* create_decl_node(char* type, char* id, ASTNode* expr, int is_const) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = is_const ? NODE_CONST : NODE_VAR;
    
    // Déterminer le type de données
    if (strcmp(type, "int") == 0) node->data_type = TYPE_INT;
    else if (strcmp(type, "flt") == 0) node->data_type = TYPE_FLT;
    else if (strcmp(type, "str") == 0) node->data_type = TYPE_STR;
    else if (strcmp(type, "bol") == 0) node->data_type = TYPE_BOL;
    // ... autres types
    
    node->value = strdup(id);
    node->left = create_id_node(id);
    node->right = expr;
    node->next = NULL;
    return node;
}

ASTNode* create_binop_node(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_BIN_OP;
    node->data_type = TYPE_UNKNOWN; // À déterminer lors de l'analyse sémantique
    node->value = strdup(op);
    node->left = left;
    node->right = right;
    node->next = NULL;
    return node;
}
ASTNode* create_show_node(ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_SHOW;
    node->data_type = TYPE_UNKNOWN;
    node->value = NULL;
    node->left = expr;
    node->right = NULL;
    node->next = NULL;
    return node;
}

ASTNode* create_id_node(char* id) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_ID;
    node->data_type = TYPE_UNKNOWN;
    node->value = strdup(id);
    node->left = node->right = node->next = NULL;
    return node;
}

ASTNode* create_num_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_NUM;
    node->data_type = TYPE_INT;
    node->value = malloc(20);
    sprintf(node->value, "%d", value);
    node->left = node->right = node->next = NULL;
    return node;
}

ASTNode* create_real_node(double value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_REAL;
    node->data_type = TYPE_FLT;
    node->value = malloc(20);
    sprintf(node->value, "%f", value);
    node->left = node->right = node->next = NULL;
    return node;
}
ASTNode* create_string_node(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) return NULL;
    
    node->node_type = NODE_STRING;
    node->data_type = TYPE_STR;
    node->value = strdup(value);
    node->left = node->right = node->next = NULL;
    return node;
}

ASTNode* create_bool_node(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) return NULL;
    
    node->node_type = NODE_BOOL;
    node->data_type = TYPE_BOL;
    node->value = strdup(value ? "True" : "False");
    node->left = node->right = node->next = NULL;
    return node;
}

ASTNode* create_assign_node(char* id, ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->node_type = NODE_ASSIGN;
    node->data_type = TYPE_UNKNOWN;
    node->value = strdup(id);
    node->left = create_id_node(id);
    node->right = expr;
    node->next = NULL;
    return node;
}

void print_ast(ASTNode* node, int level) {
    if (!node) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    
    switch(node->node_type) {
        case NODE_PROGRAM: printf("PROGRAM\n"); break;
        case NODE_DECL: printf("DECL\n"); break;
        case NODE_CONST: printf("CONST (%s)\n", node->value); break;
        case NODE_VAR: printf("VAR (%s)\n", node->value); break;
        case NODE_BIN_OP: printf("BIN_OP (%s)\n", node->value); break;
        case NODE_ID: printf("ID (%s)\n", node->value); break;
        case NODE_NUM: printf("NUM (%s)\n", node->value); break;
        case NODE_REAL: printf("REAL (%s)\n", node->value); break;
        case NODE_ASSIGN: printf("ASSIGN (%s)\n", node->value); break;
        case NODE_SEQ: printf("SEQ\n"); break;
        case NODE_STRING: printf("STRING (%s)\n", node->value); break;
        case NODE_BOOL: printf("BOOL (%s)\n", node->value); break;
        case NODE_SHOW:
            printf("SHOW\n");
            break;
        default: printf("UNKNOWN\n");
    }
    
    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
    print_ast(node->next, level);
}

void free_ast(ASTNode* node) {
    if (!node) return;
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->next);
    if (node->value) free(node->value);
    free(node);
}