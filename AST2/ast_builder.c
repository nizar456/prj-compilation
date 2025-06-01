#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100

typedef struct {
    ASTNode* nodes[MAX_STACK];
    int top;
} Stack;

void init_stack(Stack* s) { s->top = -1; }
void push(Stack* s, ASTNode* node) { s->nodes[++s->top] = node; }
ASTNode* pop(Stack* s) { return s->top >= 0 ? s->nodes[s->top--] : NULL; }

ASTNode* build_ast_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    Stack stack;
    init_stack(&stack);
    ASTNode* program_decls = NULL;
    ASTNode** current_decl = &program_decls;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char type[32], arg1[64], arg2[64], arg3[64];
        int count = sscanf(line, "%s %s %s %s", type, arg1, arg2, arg3);

        if (strcmp(type, "NUM") == 0) {
            push(&stack, create_num_node(atoi(arg1)));
        }
        else if (strcmp(type, "REAL") == 0) {
            push(&stack, create_real_node(atof(arg1)));
        }
        else if (strcmp(type, "ID") == 0) {
            push(&stack, create_id_node(arg1));
        }
        else if (strcmp(type, "STRING") == 0) {
            // Reconstruction de la chaîne qui peut contenir des espaces
            char* value = strchr(line, ' ') + 1;
            value[strlen(value)-1] = '\0'; // Supprimer le \n final
            push(&stack, create_string_node(value));
        }
        else if (strcmp(type, "BOOL") == 0) {
            push(&stack, create_bool_node(strcmp(arg1, "True") == 0));
        }
        else if (strcmp(type, "DECL") == 0) {
            ASTNode* expr = pop(&stack);
            int is_const = (strcmp(arg1, "CONST") == 0);
            if(is_const){
                ASTNode* decl = create_decl_node(arg2, arg3, expr, is_const);
            *current_decl = decl;
            current_decl = &decl->next;
            }
            else{
                ASTNode* decl = create_decl_node(arg1, arg2, expr, is_const);
            *current_decl = decl;
            current_decl = &decl->next;
            }
            
            
            
        }
        else if (strcmp(type, "BIN_OP") == 0) {
            ASTNode* right = pop(&stack);
            ASTNode* left = pop(&stack);
            ASTNode* op = create_binop_node(arg1, left, right);
            *current_decl = op;
            current_decl = &op->next;
            push(&stack, op);
        }
        /*else if (strcmp(type, "SHOW") == 0) {
            ASTNode* expr = pop(&stack);
            ASTNode* show = create_show_node(expr);
            *current_decl = show;
            current_decl = &show->next;
        }*/
    
    }
    fclose(file);
    return create_program_node(program_decls, NULL);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <fichier_intermediaire>\n", argv[0]);
        return 1;
    }

    ASTNode* ast = build_ast_from_file(argv[1]);
    if (ast) {
        printf("AST genere:\n");
        print_ast(ast, 0);
        free_ast(ast);
    } else {
        printf("Erreur lors de la construction de l'AST\n");
    }

    return 0;
}