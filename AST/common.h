#ifndef COMMON_H
#define COMMON_H

#include "ast.h"
#include "sniptor.tab.h"  // Contient les définitions de tokens générées par Bison

// Structure représentant une entrée dans la table des symboles
typedef struct {
    char nom[50];       // nom de la variable, constante ou fonction
    char type[20];      // type : "INT", "FLT", "STR", etc.
    int isConst;        // 1 si c’est une constante, 0 sinon
    int ligne;          // ligne de déclaration
} Symbole;

// Table des symboles (taille maximale configurable)
#define MAX_SYMBOLES 100

extern Symbole table_des_symboles[MAX_SYMBOLES];
extern int nb_symboles;

// Fonctions associées à la table des symboles
int ajouter_symbole(const char *nom, const char *type, int isConst, int ligne);
int symbole_existe(const char *nom);
const char* type_token_to_string(int token); // convertit un token de type en chaîne lisible

#endif // COMMON_H
