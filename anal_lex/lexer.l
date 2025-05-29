%{
#include <stdio.h>
%}
    
%option noyywrap
    
%%
"complexity" { printf("MOT-CLE: complexity\n"); }
"explain" { printf("MOT-CLE: explain\n"); }
"protect" { printf("MOT-CLE: protect\n"); }
"capture" { printf("MOT-CLE: capture\n"); }
"raise" { printf("MOT-CLE: raise\n"); }

"contains" { printf("MOT-CLE: contains\n"); }
"size" { printf("MOT-CLE: size\n"); }
"act" { printf("MOT-CLE: act\n"); }

"case" { printf("MOT-CLE: case\n"); }
"cut" { printf("MOT-CLE: cut\n"); }
"skip" { printf("MOT-CLE: skip\n"); }

"create" { printf("MOT-CLE: create\n"); }
"function" { printf("DEFINITION: Fonction\n"); }
"procedure" { printf("DEFINITION: Procédure\n"); }
"type" { printf("MOT-CLE: type\n"); }

show    { printf("COMMANDE: affichage\n"); }
enter   { printf("COMMANDE: lecture\n"); }

int     { printf("TYPE: int\n"); }
flt   { printf("TYPE: float\n"); }
chr    { printf("TYPE: char\n"); }
dbl  { printf("TYPE: double\n"); }
str     { printf("TYPE: string\n"); }
bol     { printf("TYPE: booleen\n"); }
lst     { printf("TYPE: list\n"); }
dict    { printf("TYPE: dictionnaire\n"); }

"True"         { printf("BOOL: True\n"); }
"False"         { printf("BOOL: False\n"); }

"repeat" { printf("MOT-CLE: repeat\n"); }
"for"         { printf("BOUCLE: for\n"); }
"while"         { printf("BOUCLE: while\n"); }
"from" { printf("MOT-CLE: from\n"); }
"to"   { printf("Separateur de bornes\n"); }

"when"           { printf("CONDITION: when\n"); }
"do"        { printf("INSTRUCTION: do\n"); }
"otherwise"        { printf("INSTRUCTION: otherwise\n"); }

"<-"    { printf("OPERATEUR: Affectation (<-)\n"); }
"["     { printf("SYMBOLE: Debut d'un tableau\n"); }
"]"     { printf("SYMBOLE: Fin d'un tableau\n"); }
"{"     { printf("DEBUT BLOC\n"); }
"}"     { printf("FIN BLOC\n"); }
"("  { printf("SYMBOLE: Debut d'une expression\n"); }
")"  { printf("SYMBOLE: Fin d'une expression\n"); }
"::" { printf("SYMBOLE: Fin instruction\n"); }
":" { printf("SYMBOLE: %s\n", yytext); }
"=>" { printf("SYMBOLE: RETOUR_FONCTION\n"); }
"#"  { printf("SYMBOLE: CONST_MARKER\n"); }
"\[\^" { printf("SYMBOLE: COMMENT_START\n"); }
"\^\]" { printf("SYMBOLE: COMMENT_END\n"); }
"--" { printf("SYMBOLE: SYNTAX_HELP\n"); } 

"gt"           { printf("OPERATEUR COMPARAISON: %s\n", yytext); }
"gte"          { printf("OPERATEUR COMPARAISON: %s\n", yytext); }
"lt"           { printf("OPERATEUR COMPARAISON: %s\n", yytext); }
"lte"          { printf("OPERATEUR COMPARAISON: %s\n", yytext); }
"eq"           { printf("OPERATEUR COMPARAISON: %s\n", yytext); }
"neq"          { printf("OPERATEUR COMPARAISON: %s\n", yytext); }


[+\-*/=] { printf("OPERATEUR: %s\n", yytext); }
"sq"      { printf("OPERATEUR: %s\n", yytext); }
"%"       { printf("OPERATEUR: Modulo\n");}
"!"       { printf("OPERATEUR: Factoriel\n");}
"\^"      { printf("OPERATEUR: Puissance\n");}
"|"       { printf("SYMBOLE: Valeur Absolu\n"); }

"and"      { printf("OPERATEUR: %s\n", yytext); }
"or"      { printf("OPERATEUR: %s\n", yytext); }
"not"      { printf("OPERATEUR: %s\n", yytext); }
"xor"      { printf("OPERATEUR: %s\n", yytext); }

\"[^\"]*\"       { printf("CHAINE: %s\n", yytext); }
\'[^\']\'       { printf("CHAR: %s\n", yytext); }

[0-9]+          { printf("ENTIER: %s\n", yytext); }
[0-9]+\.?[0-9]* { printf("REEL: %s\n", yytext); } 

[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIANT: %s\n", yytext); }

[ \t\n\r]+      { /* Ignore les espaces, tabulations et retours à la ligne */ }

. { printf("CARACTERE INCONNU: %s\n", yytext); }
    
%%
    
int main() {
    yylex(); // Lancer l'analyse lexicale
    return 0;
}