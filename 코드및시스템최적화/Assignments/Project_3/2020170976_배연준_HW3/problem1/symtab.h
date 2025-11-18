#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

/* Node/Leaf labels produced by project3.y (edit if you changed grammar) */
#define T_DEFINE_HEADER "define_header"
#define T_FUNC_DEF      "func_def"
#define T_FUNC_ARG_DEC  "func_arg_dec"
#define T_DECL_INIT     "decl_init"
#define T_ASSIGN_STMT   "assign_stmt"
#define T_AL_EXPR       "al_expr"
#define T_VARIABLE      "variable"

#define P_ID        "ID:"
#define P_LBRACE    "LBRACE:"
#define P_RBRACE    "RBRACE:"
#define P_LBRACKET  "LBRACKET:"
#define P_RBRACKET  "RBRACKET:"
#define P_NUM       "NUM:"
#define P_NUM_BIN   "NUM_BIN:"
#define P_NUM_HEX   "NUM_HEX:"
#define P_INT       "INT:"
#define P_VOID      "VOID:"
#define P_FLOAT     "FLOAT:"

/* =====PROBLEM1===== */

/* Structure for a symbol table */
typedef struct SYMTAB {
    struct SYMTAB* parent;
    struct SYMTAB* child[16];   /* maximum child num = 16 */
    int num_child;              /* real child num */
    struct SYMBOL* entry[64];   /* maximum number of symbol table entries = 64 */
    int num_entry;              /* real entry num */

    /* Optional: use this cursor when aligning block scopes during analyses */
    int visit_i;
} SYMTAB;

/* Structure for a symbol table entry */
typedef struct SYMBOL {
    char name[64];  
    int  kind;      /* 0: func, 1: param, 2: var */
    int  type[8];   /* 0: void, 1: int,   2: float */
    int  num_type;  /* if symbol is param or var, num_type = 1. 
                       else if symbol is func, num_type can be larger than 1. (return type + args type) */    
} SYMBOL;

/* Generate a symbol table (Example implementation) */
static inline SYMTAB* NewSymTab(void) {
    SYMTAB* t = (SYMTAB*)malloc(sizeof(SYMTAB));
    t->parent = NULL;
    t->num_child = 0;
    t->num_entry = 0;
    t->visit_i = 0;
    for (int i=0;i<16;i++) t->child[i] = NULL;
    for (int i=0;i<64;i++) t->entry[i] = NULL;
    return t;
}

/* Add a symbol table to another symbol table as a child (Example) */
static inline void AddSymTab(SYMTAB* parent_symtab, SYMTAB* child_symtab) {
    parent_symtab->child[parent_symtab->num_child] = child_symtab;
    child_symtab->parent = parent_symtab;
    parent_symtab->num_child += 1;
}

/* Print a symbol table tree */
static inline void PrintSymTab(SYMTAB* symtab) {
    if (!symtab) return;
    
    printf("--------------------------------------------------------------\n");
    printf("%-15s|%-14s|%-25s\n", "name", "kind", "type");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < symtab->num_entry; i++) {
        SYMBOL* sym = symtab->entry[i];
        if (!sym) continue;
        
        char kind_str[16];
        if (sym->kind == 0) strcpy(kind_str, "func");
        else if (sym->kind == 1) strcpy(kind_str, "param");
        else strcpy(kind_str, "var");
        
        char type_str[64] = "";
        for (int j = 0; j < sym->num_type; j++) {
            if (j > 0) strcat(type_str, " ");
            if (sym->type[j] == 0) strcat(type_str, "void");
            else if (sym->type[j] == 1) strcat(type_str, "int");
            else if (sym->type[j] == 2) strcat(type_str, "float");
            
            if (j == 0 && sym->kind == 0 && sym->num_type > 1) {
                strcat(type_str, " /");
            }
        }
        
        printf("%-15s|%-14s|%-25s\n", sym->name, kind_str, type_str);
    }
    
    /* Recursively print child symbol tables */
    for (int i = 0; i < symtab->num_child; i++) {
        if (symtab->child[i]) {
            PrintSymTab(symtab->child[i]);
        }
    }
}

/* Generate a new element for symbol table */
static inline SYMBOL* NewSymbol(const char* name, int kind, int type) {
    SYMBOL* s = (SYMBOL*)malloc(sizeof(SYMBOL));
    strcpy(s->name, name);
    s->kind = kind;
    s->type[0] = type;
    s->num_type = 1;
    return s;
}

/* Insert an element to symbol table entry */
static inline void AddSymbol(SYMTAB* symtab, SYMBOL* symbol) {
    if (!symtab || !symbol) return;
    symtab->entry[symtab->num_entry] = symbol;
    symtab->num_entry++;
}

/* Find an element with corresponding name from symbol table, considering scope */
static inline SYMBOL* FindSymbol(SYMTAB* symtab, const char* name) {
    if (!symtab || !name) return NULL;
    
    /* Search in current scope */
    for (int i = 0; i < symtab->num_entry; i++) {
        if (symtab->entry[i] && strcmp(symtab->entry[i]->name, name) == 0) {
            return symtab->entry[i];
        }
    }
    
    /* Search in parent scope */
    if (symtab->parent) {
        return FindSymbol(symtab->parent, name);
    }
    
    return NULL;
}

static inline void ProcessBody(SYMTAB* current_scope, NODE* body_node);

/* Helper: Process declaration list recursively */
static inline void ProcessDeclList(NODE* decl_list, int* param_count, SYMBOL* func_sym) {
    if (!decl_list) return;
    
    if (strcmp(decl_list->name, T_DECL_INIT) == 0) {
        (*param_count)++;
        if (*param_count < 7) {
            func_sym->type[func_sym->num_type] = 1; /* int */
            func_sym->num_type++;
        }
    } else if (strcmp(decl_list->name, "decl_list") == 0) {
        /* Process children recursively */
        if (decl_list->child) {
            ProcessDeclList(decl_list->child, param_count, func_sym);
        }
        /* Process siblings recursively */
        if (decl_list->next) {
            ProcessDeclList(decl_list->next, param_count, func_sym);
        }
    } else {
        /* Skip other tokens like COMMA, LPAREN, RPAREN, etc. */
        /* But still process siblings */
        if (decl_list->next) {
            ProcessDeclList(decl_list->next, param_count, func_sym);
        }
    }
}

/* Helper: get type from type node */
static inline int GetType(NODE* type_node) {
    if (!type_node || !type_node->child) return 1; /* default: int */
    
    NODE* child = type_node->child;
    if (strncmp(child->name, P_VOID, strlen(P_VOID)) == 0) return 0;
    if (strncmp(child->name, P_INT, strlen(P_INT)) == 0) return 1;
    if (strncmp(child->name, P_FLOAT, strlen(P_FLOAT)) == 0) return 2;
    return 1;
}

/* Helper: get variable name from variable node */
static inline void GetVarName(NODE* var_node, char* name) {
    if (!var_node) return;
    
    /* If this is an ID token, extract the name */
    if (strncmp(var_node->name, "ID:", 3) == 0) {
        /* Skip the "ID: " part (4 characters including space) */
        strcpy(name, var_node->name + 4);
        return;
    }
    
    /* If this is a variable node, traverse to find the ID */
    if (strcmp(var_node->name, T_VARIABLE) == 0 && var_node->child) {
        GetVarName(var_node->child, name);
    }
}

/* Helper: Process declaration list for local variables */
static inline void ProcessDeclListForVariables(SYMTAB* current_scope, NODE* decl_list) {
    if (!decl_list) return;
    
    if (strcmp(decl_list->name, T_DECL_INIT) == 0) {
        NODE* type_n = decl_list->child;
        NODE* var_n = type_n ? type_n->next : NULL;
        
        if (var_n) {
            char var_name[64] = "";
            GetVarName(var_n, var_name);
            if (strlen(var_name) > 0) {
                SYMBOL* var_sym = NewSymbol(var_name, 2, GetType(type_n));
                AddSymbol(current_scope, var_sym);
            }
        }
    } else if (strcmp(decl_list->name, "decl_list") == 0) {
        /* Process children recursively */
        if (decl_list->child) {
            ProcessDeclListForVariables(current_scope, decl_list->child);
        }
        /* Process siblings recursively */
        if (decl_list->next) {
            ProcessDeclListForVariables(current_scope, decl_list->next);
        }
    } else {
        /* Skip other tokens like COMMA, LPAREN, RPAREN, etc. */
        /* But still process siblings */
        if (decl_list->next) {
            ProcessDeclListForVariables(current_scope, decl_list->next);
        }
    }
}

/* Helper: Add parameters to function scope */
static inline void AddParamsToScope(SYMTAB* func_scope, NODE* decl_list) {
    if (!decl_list) return;
    
    if (strcmp(decl_list->name, T_DECL_INIT) == 0) {
        NODE* type_n = decl_list->child;
        NODE* var_n = type_n ? type_n->next : NULL;
        
        if (var_n) {
            char param_name[64] = "";
            GetVarName(var_n, param_name);
            if (strlen(param_name) > 0) {
                SYMBOL* param_sym = NewSymbol(param_name, 1, GetType(type_n));
                AddSymbol(func_scope, param_sym);
            }
        }
    } else if (strcmp(decl_list->name, "decl_list") == 0) {
        /* Process children recursively */
        if (decl_list->child) {
            AddParamsToScope(func_scope, decl_list->child);
        }
        /* Process siblings recursively */
        if (decl_list->next) {
            AddParamsToScope(func_scope, decl_list->next);
        }
    } else {
        /* Skip other tokens like COMMA, LPAREN, RPAREN, etc. */
        /* But still process siblings */
        if (decl_list->next) {
            AddParamsToScope(func_scope, decl_list->next);
        }
    }
}

/* Construct a symbol table tree using parse tree */
static inline SYMTAB* ConstructSymTab(SYMTAB* root, NODE* head) {
    if (!head) return root;
    
    /* Process children first */
    if (head->child) {
        ConstructSymTab(root, head->child);
    }
    
    /* Process siblings */
    if (head->next) {
        ConstructSymTab(root, head->next);
    }
    
    /* Process define_header */
    if (strcmp(head->name, T_DEFINE_HEADER) == 0) {
        NODE* id_node = head->child->next;
        if (id_node && strncmp(id_node->name, P_ID, strlen(P_ID)) == 0) {
            char name[64];
            strcpy(name, id_node->name + strlen(P_ID));
            SYMBOL* sym = NewSymbol(name, 2, 1); /* var, int */
            AddSymbol(root, sym);
        }
    }
    
    /* Process func_def */
    if (strcmp(head->name, T_FUNC_DEF) == 0) {
        NODE* type_node = head->child;
        NODE* id_node = type_node ? type_node->next : NULL;
        
        if (id_node && strncmp(id_node->name, P_ID, strlen(P_ID)) == 0) {
            char func_name[64];
            strcpy(func_name, id_node->name + strlen(P_ID));
            
            SYMBOL* func_sym = NewSymbol(func_name, 0, GetType(type_node));
            
            /* Parse function arguments - find func_arg_dec node */
            NODE* func_arg = id_node->next;
            while (func_arg && strcmp(func_arg->name, "func_arg_dec") != 0) {
                func_arg = func_arg->next;
            }
            
            if (func_arg && func_arg->child) {
                NODE* decl_list = func_arg->child;
                
                /* Count parameters by traversing the decl_list structure */
                int param_count = 0;
                ProcessDeclList(decl_list, &param_count, func_sym);
            }
            
            AddSymbol(root, func_sym);
            
            /* Add parameters to the same scope as the function */
            if (func_arg && func_arg->child) {
                AddParamsToScope(root, func_arg->child);
            }
            
            /* Create child scope for function body */
            SYMTAB* func_scope = NewSymTab();
            AddSymTab(root, func_scope);
            
            /* Process function body */
            NODE* body_node = func_arg;
            while (body_node && strcmp(body_node->name, "body") != 0) {
                body_node = body_node->next;
            }
            
            if (body_node) {
                ProcessBody(func_scope, body_node);
            }
        }
    }
    
    return root;
}

/* Helper: Process function body for variable declarations and nested scopes */
static inline void ProcessBody(SYMTAB* current_scope, NODE* body_node) {
    if (!body_node) return;
    
    NODE* curr = body_node->child;
    
    while (curr) {
        /* Handle statement nodes - they may contain variable declarations */
        if (strcmp(curr->name, "statement") == 0) {
            NODE* stmt_child = curr->child;
            if (stmt_child && strcmp(stmt_child->name, "decl_list") == 0) {
                ProcessDeclListForVariables(current_scope, stmt_child);
            } else if (stmt_child && strcmp(stmt_child->name, T_DECL_INIT) == 0) {
                NODE* type_n = stmt_child->child;
                NODE* var_n = type_n ? type_n->next : NULL;
                
                if (var_n) {
                    char var_name[64] = "";
                    GetVarName(var_n, var_name);
                    if (strlen(var_name) > 0) {
                        SYMBOL* var_sym = NewSymbol(var_name, 2, GetType(type_n));
                        AddSymbol(current_scope, var_sym);
                    }
                }
            }
        }
        
        /* Handle for loops - create new scope */
        if (strcmp(curr->name, "for") == 0 || strcmp(curr->name, "clause") == 0) {
            /* Check if this clause contains a body that creates a new scope */
            NODE* clause_body = curr->child;
            while (clause_body) {
                if (strcmp(clause_body->name, "body") == 0) {
                    SYMTAB* nested_scope = NewSymTab();
                    AddSymTab(current_scope, nested_scope);
                    ProcessBody(nested_scope, clause_body);
                    break;
                }
                clause_body = clause_body->next;
            }
        }
        
        /* Handle nested body */
        if (strcmp(curr->name, "body") == 0) {
            ProcessBody(current_scope, curr);
        }
        
        curr = curr->next;
    }
}

/* =====PROBLEM2===== */
/*  Do scope-analysis for every variables in the code
    for detecting undefined variables */

static inline void ScopeAnalysis(SYMTAB* symtab, NODE* head) {
    /* TODO */
}

/* ======PROBLEM3===== */
/*  Do type-analysis for every arithmetic & logic expressions in the code
    for detecting type error
     1. array index should be integer
     2. float number cannot be stored in integer variable */
     
static inline void TypeAnalysis(SYMTAB* symtab, NODE* head) {
    /* TODO */
}

#endif 
