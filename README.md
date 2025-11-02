# Présentation du Langage Sniptor
Sniptor est un langage de programmation éducatif conçu pour les débutants. Il allie une syntaxe intuitive, inspirée du langage naturel, à des fonctionnalités pédagogiques intégrées comme l’explication pas à pas du code, le calcul de complexité algorithmique et une gestion explicite des erreurs. Son objectif est de permettre aux apprenants de se concentrer sur la logique de programmation sans être freinés par des détails techniques complexes.
## Caractéristiques principales :
- Syntaxe claire et minimaliste

- Typage statique avec déclaration explicite

- Structures de contrôle inspirées de l’anglais courant (act, when, repeat, for...from...to)

- Aide interactive en langage naturel

- Gestion d’erreurs structurée via protect / capture

- Calcul automatique de complexité avec complexity

- Explication pas à pas avec explain

 ## Ce Que Nous Avons Réalisé
### 1. Conception du Langage Sniptor
- Syntaxe intuitive inspirée du langage naturel

- Système de types complet (int, fit, str, bol, lst, dict)

- Structures de contrôle innovantes :

- act { when (condition) do {...} otherwise {...} } pour les conditionnelles

- repeat { for (x from 1 to 10) do {...} } pour les boucles

- Fonctionnalités pédagogiques intégrées :

explain {} : explication pas à pas du code

complexity {} : calcul automatique de complexité

--aide en français-- : assistance en langage naturel

### 2. Développement du Compilateur
- Analyse lexicale avec Flex : reconnaissance des tokens

- Analyse syntaxique avec Bison : vérification de la structure grammaticale

- Table des symboles : gestion des variables, fonctions et portées

- Arbre Syntaxique Abstrait (AST) : représentation intermédiaire du code

- Analyse sémantique : vérification de la cohérence des types et déclarations

### 3. Implémentation Techniqu
 ```  
// Architecture modulaire :
- lexer.l (Flex) → Analyse lexicale
- parser.y (Bison) → Analyse syntaxique  
- common.h/c → Table des symboles
- ast.h/c → Construction de l'AST
- semantic.c → Analyse sémantique
```

## Résultats Concrets
### Exemple de Code Compilé :
```
# int x <- 10 ::
fit y <- 3.14 ::
show "Résultat : " + (x * y) ::
```
### Sortie de l'Analyse :

```
TYPE: int
IDENTIFIANT: x  
OPERATEUR: Affectation (<-)
ENTIER: 10
SYMBOLE: Fin instruction
...
```
