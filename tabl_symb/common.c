#include <string.h>
#include <stdio.h>
#include "common.h"

Symbole table_des_symboles[MAX_SYMBOLES];
int nb_symboles = 0;

int symbole_existe(const char *nom) {
    for (int i = 0; i < nb_symboles; i++) {
        if (strcmp(table_des_symboles[i].nom, nom) == 0) {
            return 1;
        }
    }
    return 0;
}

int ajouter_symbole(const char *nom, const char *type, int isConst, int ligne) {
    if (nb_symboles >= MAX_SYMBOLES) {
        fprintf(stderr, "Erreur : Table des symboles pleine\n");
        return 0;
    }

    if (symbole_existe(nom)) {
        fprintf(stderr, "Erreur : Symbole '%s' déjà déclaré\n", nom);
        return 0;
    }

    Symbole *sym = &table_des_symboles[nb_symboles++];
    strncpy(sym->nom, nom, sizeof(sym->nom) - 1);
    strncpy(sym->type, type, sizeof(sym->type) - 1);
    sym->isConst = isConst;
    sym->ligne = ligne;

    return 1;
}
