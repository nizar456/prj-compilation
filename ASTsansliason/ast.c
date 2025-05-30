
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>  
#include <string.h>

// Fonction pour créer une liste de paramètres
ParameterList create_parameter_list(Parameter* params, int count) {
    ParameterList pl;
    pl.params = params;
    pl.param_count = count;
    return pl;
}

// Fonction pour créer une instruction
Instruction* create_instruction(ASTNode* node) {
    Instruction* instr = malloc(sizeof(Instruction));
    instr->node = node;
    instr->next = NULL;
    return instr;
}

// Ajouter une instruction à la fin d'une liste d'instructions
void append_instruction(Instruction** list, Instruction* new_instr) {
    if (*list == NULL) {
        *list = new_instr;
    } else {
        Instruction* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_instr;
    }
}

// Fonctions de création des nœuds de l'AST
ASTNode* create_function_declaration(char* return_type, char* name, ParameterList params, Instruction* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_FUNCTION_DECL;
    node->function_decl.return_type = strdup(return_type);
    node->function_decl.name = strdup(name);
    node->function_decl.params = params;
    node->function_decl.body = body;
    return node;
}

ASTNode* create_procedure_declaration(char* name, ParameterList params, Instruction* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_PROCEDURE_DECL;
    node->procedure_decl.name = strdup(name);
    node->procedure_decl.params = params;
    node->procedure_decl.body = body;
    return node;
}

ASTNode* create_assignment(char* var_type, char* var_name, ASTNode* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_ASSIGNMENT;
    node->assignment.var_type = strdup(var_type);
    node->assignment.var_name = strdup(var_name);
    node->assignment.value = value;
    return node;
}

ASTNode* create_binary_expression(ASTNode* left, Operator op, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_BINARY_EXPRESSION;
    node->binary_expr.left = left;
    node->binary_expr.op = op;
    node->binary_expr.right = right;
    return node;
}

ASTNode* create_unary_expression(Operator op, ASTNode* expr) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_UNARY_EXPRESSION;
    node->unary_expr.op = op;
    node->unary_expr.expr = expr;
    return node;
}

ASTNode* create_variable(char* name) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_VARIABLE;
    node->variable.name = strdup(name);
    return node;
}

ASTNode* create_constant(char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_CONSTANT;
    node->constant.value = strdup(value);
    return node;
}

ASTNode* create_while_loop(ASTNode* condition, Instruction* body) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_WHILE;
    node->loop.condition = condition;
    node->loop.body = body;
    return node;
}

ASTNode* create_function_call(char* name, ASTNode** args, int arg_count) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = NODE_CALL;
    node->func_call.name = strdup(name);
    node->func_call.arguments = args;
    node->func_call.arg_count = arg_count;
    return node;
}

// Fonction pour afficher l'AST
void print_ast(ASTNode* node, int indent) {
    if (node == NULL) return;
    
    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (node->type) {
        case NODE_FUNCTION_DECL:
            printf("Function: %s -> %s\n", node->function_decl.name, node->function_decl.return_type);
            for (int i = 0; i < node->function_decl.params.param_count; i++) {
                for (int j = 0; j < indent+1; j++) printf("  ");
                printf("Param: %s %s\n", node->function_decl.params.params[i].type, 
                                         node->function_decl.params.params[i].name);
            }
            for (Instruction* instr = node->function_decl.body; instr != NULL; instr = instr->next) {
                print_ast(instr->node, indent+1);
            }
            break;
            
        case NODE_ASSIGNMENT:
            printf("Assign: %s %s =\n", node->assignment.var_type, node->assignment.var_name);
            print_ast(node->assignment.value, indent+1);
            break;
            
        case NODE_BINARY_EXPRESSION: {
            const char* ops[] = {"+", "-", "*", "/", "==", "<", ">"};
            printf("Binary Op: %s\n", ops[node->binary_expr.op]);
            print_ast(node->binary_expr.left, indent+1);
            print_ast(node->binary_expr.right, indent+1);
            break;
        }
            
        case NODE_VARIABLE:
            printf("Variable: %s\n", node->variable.name);
            break;
            
        case NODE_CONSTANT:
            printf("Constant: %s\n", node->constant.value);
            break;
            
        case NODE_WHILE:
            printf("While:\n");
            print_ast(node->loop.condition, indent+1);
            for (Instruction* instr = node->loop.body; instr != NULL; instr = instr->next) {
                print_ast(instr->node, indent+1);
            }
            break;
            
        case NODE_CALL:
            printf("Call: %s\n", node->func_call.name);
            for (int i = 0; i < node->func_call.arg_count; i++) {
                print_ast(node->func_call.arguments[i], indent+1);
            }
            break;
            
        default:
            printf("Unknown node type\n");
    }
}

// Fonction pour libérer la mémoire de l'AST
void free_ast(ASTNode* node) {
    if (node == NULL) return;
    
    switch (node->type) {
        case NODE_FUNCTION_DECL:
            free(node->function_decl.return_type);
            free(node->function_decl.name);
            for (int i = 0; i < node->function_decl.params.param_count; i++) {
                free(node->function_decl.params.params[i].type);
                free(node->function_decl.params.params[i].name);
            }
            free(node->function_decl.params.params);
            for (Instruction* instr = node->function_decl.body; instr != NULL; ) {
                Instruction* next = instr->next;
                free_ast(instr->node);
                free(instr);
                instr = next;
            }
            break;
            
        case NODE_ASSIGNMENT:
            free(node->assignment.var_type);
            free(node->assignment.var_name);
            free_ast(node->assignment.value);
            break;
            
        case NODE_BINARY_EXPRESSION:
            free_ast(node->binary_expr.left);
            free_ast(node->binary_expr.right);
            break;
            
        case NODE_VARIABLE:
            free(node->variable.name);
            break;
            
        case NODE_CONSTANT:
            free(node->constant.value);
            break;
            
        case NODE_WHILE:
            free_ast(node->loop.condition);
            for (Instruction* instr = node->loop.body; instr != NULL; ) {
                Instruction* next = instr->next;
                free_ast(instr->node);
                free(instr);
                instr = next;
            }
            break;
            
        case NODE_CALL:
            free(node->func_call.name);
            for (int i = 0; i < node->func_call.arg_count; i++) {
                free_ast(node->func_call.arguments[i]);
            }
            free(node->func_call.arguments);
            break;
            
        default:
            break;
    }
    
    free(node);
}