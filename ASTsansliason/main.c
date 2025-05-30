#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int main() {
    // Création des paramètres pour une fonction
    Parameter params[2] = {
        {strdup("int"), strdup("x")},
        {strdup("float"), strdup("y")}
    };
    ParameterList param_list = create_parameter_list(params, 2);
    
    // Corps de la fonction
    Instruction* body = NULL;
    append_instruction(&body, create_instruction(
        create_assignment("int", "result", 
            create_binary_expression(
                create_variable("x"),
                OP_ADD,
                create_variable("y")
            )
        )
    ));
    
    // Création de la fonction
    ASTNode* func = create_function_declaration("int", "add", param_list, body);
    
    // Affichage de l'AST
    printf("AST Representation:\n");
    print_ast(func, 0);
    
    // Libération de la mémoire
    free_ast(func);
    
    return 0;
}
