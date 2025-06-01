#ifndef AST_H
#define AST_H

typedef enum {
    NODE_PROGRAM,
    NODE_DECL,
    NODE_CONST,
    NODE_VAR,
    NODE_BIN_OP,
    NODE_UNARY_OP,
    NODE_ID,
    NODE_NUM,
    NODE_REAL,
    NODE_STRING,
    NODE_BOOL,
    NODE_ASSIGN,
    NODE_CALL,
    NODE_SHOW,
    NODE_SEQ
} NodeType;

typedef enum {
    TYPE_INT,
    TYPE_FLT,
    TYPE_CHR,
    TYPE_DBL,
    TYPE_STR,
    TYPE_BOL,
    TYPE_LST,
    TYPE_DICT,
    TYPE_UNKNOWN
} DataType;

typedef struct ASTNode {
    NodeType node_type;
    DataType data_type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* next; // Pour les listes d'instructions
} ASTNode;

// Fonctions de création des nœuds
ASTNode* create_program_node(ASTNode* declarations, ASTNode* instructions);
ASTNode* create_decl_node(char* type, char* id, ASTNode* expr, int is_const);
ASTNode* create_binop_node(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_show_node(ASTNode* expr);
ASTNode* create_id_node(char* id);
ASTNode* create_num_node(int value);
ASTNode* create_real_node(double value);
ASTNode* create_string_node(const char* value);  // Ajouté
ASTNode* create_bool_node(int value);
ASTNode* create_assign_node(char* id, ASTNode* expr);

// Fonctions utilitaires
void print_ast(ASTNode* node, int level);
void free_ast(ASTNode* node);

#endif