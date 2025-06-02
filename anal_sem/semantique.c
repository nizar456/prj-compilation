#include "ast.h"
#include "common.h"
#include "semantique.h"
#include <stdio.h>
#include <string.h>

extern int is_valid;

// Prototype
void analyse_semantique(ASTNode *node);

// Utilitaires pour la recherche dans la table des symboles
int get_type_symbole(const char *nom, char *type_out);
int is_const_symbole(const char *nom);

// Prototypes pour éviter les warnings et erreurs d'implicit declaration
const char* infer_literal_type(const char* value);
int is_numeric_type(const char* type);
int types_compatibles(const char* type1, const char* type2);

// Ajoute une erreur sémantique et arrête l'analyse
void erreur_semantique(const char *msg, int ligne) {
    printf("Erreur semantique : %s\n", msg);
    is_valid = 0;
}

void analyse_semantique(ASTNode *node) {
    if (!node || !is_valid) return;
    switch (node->type) {
        case AST_VARIABLE_DECLARATION: {
            // Vérifie redéclaration
            const char *nom = node->children[1]->value;
            if (symbole_existe(nom) > 1) {
                erreur_semantique("Redeclaration de la variable", 0);
            }
            break;
        }
        case AST_VARIABLE_AFFECTATION: {
            const char *nom = node->children[0]->value;
            char type[20];
            if (!get_type_symbole(nom, type)) {
                erreur_semantique("Affectation à une variable non declaree", 0);
            }
            if (is_const_symbole(nom)) {
                erreur_semantique("Modification d'une constante interdite", 0);
            }
            
            break;
        }
        case AST_FUNCTION_CALL: {
            const char *nom = node->children[0]->value;
            if (!symbole_existe(nom)) {
                erreur_semantique("Appel d'une fonction non declaree", 0);
            }
            
            break;
        }
        case AST_EXPRESSION: {
            // Vérification des types pour les opérateurs
            if (node->value) {
                const char *op = node->value;
                // Récupérer les types des opérandes
                char type_gauche[20] = "", type_droite[20] = "";
                if (node->child_count >= 1 && node->children[0]) {
                    ASTNode *gauche = node->children[0];
                    if (gauche->type == AST_IDENTIFIER) get_type_symbole(gauche->value, type_gauche);
                    if (gauche->type == AST_LITERAL) strcpy(type_gauche, infer_literal_type(gauche->value));
                }
                if (node->child_count >= 2 && node->children[1]) {
                    ASTNode *droite = node->children[1];
                    if (droite->type == AST_IDENTIFIER) get_type_symbole(droite->value, type_droite);
                    if (droite->type == AST_LITERAL) strcpy(type_droite, infer_literal_type(droite->value));
                }
                // Opérateurs arithmétiques
                if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0 || strcmp(op, "^") == 0) {
                    if (!is_numeric_type(type_gauche) || !is_numeric_type(type_droite)) {
                        erreur_semantique("Operateur arithmetique sur type non numerique", 0);
                    }
                }
                // Opérateurs logiques
                if (strcmp(op, "AND") == 0 || strcmp(op, "OR") == 0 || strcmp(op, "NOT") == 0 || strcmp(op, "XOR") == 0) {
                    if (strcmp(type_gauche, "bol") != 0 || (node->child_count >= 2 && strcmp(type_droite, "bol") != 0)) {
                        erreur_semantique("Operateur logique sur type non booleen", 0);
                    }
                }
                // Opérateurs de comparaison
                if (strcmp(op, "> ") == 0 || strcmp(op, ">=") == 0 || strcmp(op, "< ") == 0 || strcmp(op, "<=") == 0 || strcmp(op, "==") == 0 || strcmp(op, "!=") == 0) {
                    if (!types_compatibles(type_gauche, type_droite)) {
                        erreur_semantique("Operateur de comparaison sur types incompatibles", 0);
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    for (int i = 0; i < node->child_count; i++)
        analyse_semantique(node->children[i]);
}

// Recherche le type d'une variable dans la table des symboles
int get_type_symbole(const char *nom, char *type_out) {
    for (int i = 0; i < nb_symboles; i++) {
        if (strcmp(table_des_symboles[i].nom, nom) == 0) {
            strcpy(type_out, table_des_symboles[i].type);
            return 1;
        }
    }
    return 0;
}

// Vérifie si une variable est constante
int is_const_symbole(const char *nom) {
    for (int i = 0; i < nb_symboles; i++) {
        if (strcmp(table_des_symboles[i].nom, nom) == 0) {
            return table_des_symboles[i].isConst;
        }
    }
    return 0;
}

// Déduit le type d'un littéral à partir de sa valeur (très simple)
const char* infer_literal_type(const char* value) {
    if (!value) return "UNKNOWN";
    int i = 0;
    int is_num = 1, is_float = 0;
    for (; value[i]; i++) {
        if (value[i] == '.') is_float = 1;
        else if (value[i] < '0' || value[i] > '9') { is_num = 0; break; }
    }
    if (is_num && is_float) return "flt";
    if (is_num) return "int";
    if (strcmp(value, "TRUE") == 0 || strcmp(value, "FALSE") == 0) return "bol";
    if (value[0] == '"' || value[0] == '\'') return "str";
    return "UNKNOWN";
}

// Retourne 1 si le type est numérique
int is_numeric_type(const char* type) {
    return (strcmp(type, "int") == 0 || strcmp(type, "flt") == 0 || strcmp(type, "dbl") == 0);
}

// Retourne 1 si les types sont compatibles pour une comparaison
int types_compatibles(const char* type1, const char* type2) {
    if (strcmp(type1, type2) == 0) return 1;
    if ((strcmp(type1, "int") == 0 && (strcmp(type2, "flt") == 0 || strcmp(type2, "dbl") == 0)) ||
        ((strcmp(type1, "flt") == 0 || strcmp(type1, "dbl") == 0) && strcmp(type2, "int") == 0))
        return 1;
    return 0;
}