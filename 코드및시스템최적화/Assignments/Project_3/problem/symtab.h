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
    /* TODO */
}

/* Generate a new element for symbol table */
static inline SYMBOL* NewSymbol(const char* name, int kind, int type) {
    /* TODO */

}

/* Insert an element to symbol table entry */
static inline void AddSymbol(SYMTAB* symtab, SYMBOL* symbol) {
    /* TODO */
}

/* Find an element with corresponding name from symbol table, considering scope */
static inline SYMBOL* FindSymbol(SYMTAB* symtab, const char* name) {
    /* TODO */
    return NULL;
}

/* Construct a symbol table tree using parse tree */
static inline SYMTAB* ConstructSymTab(SYMTAB* root, NODE* head) {
    /* TODO */
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
