/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project3.y"

/**********PROLOGUE AREA**********/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symtab.h"

NODE *head;
char buf[100];
FILE* fp;

extern FILE *yyin;
extern char *yytext;
extern int yylineno;
char * filename;

int yylex();

void yyerror(const char *str){
    fprintf(stderr, "%s:%d: error: %s '%s' token \n", filename, yylineno, str, yytext);
}

int yywrap(){
     return 1; 
}

NODE* create_token_node(const char* token_type, const char* token_value) {
    size_t len_type = strlen(token_type);
    size_t len_value = token_value ? strlen(token_value) : 0;
    size_t len_total = len_type + 2 + len_value + 1;
    
    char *buffer = (char*)malloc(len_total);
    if (!buffer) {
        fprintf(stderr, "memory allocation failed in create_token_node\n");
        exit(1);
    }
    
    if (token_value)
        snprintf(buffer, len_total, "%s: %s", token_type, token_value);
    else
        snprintf(buffer, len_total, "%s", token_type);
    
    NODE* node = MakeNode(buffer);
    free(buffer);
    return node;
}

NODE* create_internal_node(const char* node_type, int child_count, ...) {
    NODE* parent = MakeNode((char*)node_type);
    va_list ap;
    va_start(ap, child_count);
    
    NODE* first_child = NULL;
    NODE* prev_sibling = NULL;
    
    for (int i = 0; i < child_count; ++i) {
        NODE* child = va_arg(ap, NODE*);
        if (!child) continue;
        
        if (!first_child) {
            first_child = child;
            InsertChild(parent, child);
            prev_sibling = child;
        } else {
            InsertSibling(prev_sibling, child);
            prev_sibling = child;
        }
    }
    
    va_end(ap);
    return parent;
}

#line 146 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINE = 258,                  /* DEFINE  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    VOID = 261,                    /* VOID  */
    IF = 262,                      /* IF  */
    FOR = 263,                     /* FOR  */
    ELSE = 264,                    /* ELSE  */
    CONTINUE = 265,                /* CONTINUE  */
    OP_ASSIGN = 266,               /* OP_ASSIGN  */
    OP_INC = 267,                  /* OP_INC  */
    OP_DEC = 268,                  /* OP_DEC  */
    OP_ADD = 269,                  /* OP_ADD  */
    OP_MUL = 270,                  /* OP_MUL  */
    OP_LOGIC = 271,                /* OP_LOGIC  */
    OP_REL = 272,                  /* OP_REL  */
    ID = 273,                      /* ID  */
    NUM = 274,                     /* NUM  */
    NUM_BIN = 275,                 /* NUM_BIN  */
    NUM_HEX = 276,                 /* NUM_HEX  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    LBRACKET = 281,                /* LBRACKET  */
    RBRACKET = 282,                /* RBRACKET  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    LOWER_THAN_ELSE = 285          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEFINE 258
#define INT 259
#define FLOAT 260
#define VOID 261
#define IF 262
#define FOR 263
#define ELSE 264
#define CONTINUE 265
#define OP_ASSIGN 266
#define OP_INC 267
#define OP_DEC 268
#define OP_ADD 269
#define OP_MUL 270
#define OP_LOGIC 271
#define OP_REL 272
#define ID 273
#define NUM 274
#define NUM_BIN 275
#define NUM_HEX 276
#define LPAREN 277
#define RPAREN 278
#define LBRACE 279
#define RBRACE 280
#define LBRACKET 281
#define RBRACKET 282
#define COMMA 283
#define SEMICOLON 284
#define LOWER_THAN_ELSE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "project3.y"
 
    int number; 
    char *string; 
    NODE *node; 

#line 265 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINE = 3,                     /* DEFINE  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_OP_ASSIGN = 11,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_INC = 12,                    /* OP_INC  */
  YYSYMBOL_OP_DEC = 13,                    /* OP_DEC  */
  YYSYMBOL_OP_ADD = 14,                    /* OP_ADD  */
  YYSYMBOL_OP_MUL = 15,                    /* OP_MUL  */
  YYSYMBOL_OP_LOGIC = 16,                  /* OP_LOGIC  */
  YYSYMBOL_OP_REL = 17,                    /* OP_REL  */
  YYSYMBOL_ID = 18,                        /* ID  */
  YYSYMBOL_NUM = 19,                       /* NUM  */
  YYSYMBOL_NUM_BIN = 20,                   /* NUM_BIN  */
  YYSYMBOL_NUM_HEX = 21,                   /* NUM_HEX  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 26,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 27,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_c_code = 32,                    /* c_code  */
  YYSYMBOL_code = 33,                      /* code  */
  YYSYMBOL_define_header = 34,             /* define_header  */
  YYSYMBOL_func_def = 35,                  /* func_def  */
  YYSYMBOL_func_arg_dec = 36,              /* func_arg_dec  */
  YYSYMBOL_unit = 37,                      /* unit  */
  YYSYMBOL_body = 38,                      /* body  */
  YYSYMBOL_clause = 39,                    /* clause  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_init_stmt = 41,                 /* init_stmt  */
  YYSYMBOL_update_stmt = 42,               /* update_stmt  */
  YYSYMBOL_assign_stmt = 43,               /* assign_stmt  */
  YYSYMBOL_continue_stmt = 44,             /* continue_stmt  */
  YYSYMBOL_test_expr = 45,                 /* test_expr  */
  YYSYMBOL_decl_list = 46,                 /* decl_list  */
  YYSYMBOL_decl_init = 47,                 /* decl_init  */
  YYSYMBOL_number = 48,                    /* number  */
  YYSYMBOL_al_expr = 49,                   /* al_expr  */
  YYSYMBOL_rel_expr = 50,                  /* rel_expr  */
  YYSYMBOL_inc_expr = 51,                  /* inc_expr  */
  YYSYMBOL_value = 52,                     /* value  */
  YYSYMBOL_variable = 53,                  /* variable  */
  YYSYMBOL_type = 54                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  99

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   122,   130,   134,   141,   150,   162,   169,
     173,   180,   184,   192,   203,   213,   221,   230,   245,   249,
     253,   257,   267,   272,   280,   284,   291,   299,   307,   314,
     318,   323,   331,   338,   342,   346,   353,   357,   361,   366,
     374,   378,   383,   391,   396,   404,   408,   415,   420,   426,
     435,   440,   445
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE", "INT",
  "FLOAT", "VOID", "IF", "FOR", "ELSE", "CONTINUE", "OP_ASSIGN", "OP_INC",
  "OP_DEC", "OP_ADD", "OP_MUL", "OP_LOGIC", "OP_REL", "ID", "NUM",
  "NUM_BIN", "NUM_HEX", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "COMMA", "SEMICOLON", "LOWER_THAN_ELSE", "$accept", "c_code",
  "code", "define_header", "func_def", "func_arg_dec", "unit", "body",
  "clause", "statement", "init_stmt", "update_stmt", "assign_stmt",
  "continue_stmt", "test_expr", "decl_list", "decl_init", "number",
  "al_expr", "rel_expr", "inc_expr", "value", "variable", "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,   -12,   -74,   -74,   -74,    74,   -74,   -74,   -74,    -1,
      28,   -74,   -74,   -14,   -74,   -74,   -74,   -74,    51,     2,
       6,   -74,     9,    35,    25,   -74,    50,   122,   -74,    50,
     125,    52,    62,    78,   -74,   -74,     8,   -74,   -74,    85,
      87,    13,    -4,   -74,   -74,    31,    50,   -74,   100,    25,
     -74,   -74,   -74,   -74,   -74,   100,   100,   100,   -74,   101,
     -74,    80,   -74,    50,   100,   110,    39,    95,   126,   -74,
     107,   100,   100,   124,   -74,   -74,   122,   142,   137,   -74,
      25,    65,   132,   133,     6,   -74,    27,   146,   -74,   134,
     -74,   -74,   135,   122,   122,    81,    97,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    51,    52,    50,     0,     2,     4,     5,     0,
       0,     1,     3,     0,    33,    34,    35,     6,     0,     0,
       8,    29,     0,     0,     0,    47,    32,     0,    31,    30,
       0,     0,     0,     0,    27,    11,     0,     9,    10,     0,
       0,     0,     0,    48,    36,     0,    37,    21,     0,     0,
       7,    12,    18,    19,    20,     0,     0,     0,    49,     0,
      46,    28,    40,    45,     0,     0,     0,    26,    38,    39,
       0,     0,     0,     0,    22,    23,     0,    15,    42,    41,
       0,     0,     0,     0,    25,    24,     0,    14,    16,     0,
      43,    44,     0,     0,     0,     0,     0,    13,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   152,   -74,   -74,   -74,   -31,   -73,   -74,   -59,
     -74,   -74,   111,   -74,    98,   -17,   139,   -10,    92,    63,
     -74,   -74,   -20,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    19,    35,    36,    37,    38,
      64,    83,    39,    40,    59,    41,    21,    44,    45,    61,
      85,    62,    42,    22
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    20,    26,    81,    29,    51,    10,    55,    18,    31,
      46,    77,     2,     3,     4,    32,    33,    13,    34,     9,
      95,    96,    30,    88,     9,    23,    25,    25,    63,     2,
       3,     4,    66,    50,    24,    46,    46,    46,    60,    90,
      91,    24,    54,    25,    63,    56,    57,    14,    15,    16,
      51,    63,    63,    30,    60,     2,     3,     4,    58,    27,
      86,    60,    60,    84,    51,    51,    31,    24,    75,     2,
       3,     4,    32,    33,    11,    34,    30,     1,     2,     3,
       4,    47,    31,    25,    48,     2,     3,     4,    32,    33,
      87,    34,     1,     2,     3,     4,    71,    72,    31,    25,
      49,     2,     3,     4,    32,    33,    97,    34,    31,    56,
      57,     2,     3,     4,    52,    25,    53,    34,    25,    14,
      15,    16,    98,    31,    70,    25,     2,     3,     4,    32,
      33,    76,    34,    31,    78,    79,     2,     3,     4,    74,
      25,    57,    34,    25,    14,    15,    16,    67,    68,    69,
      25,    82,    43,    80,    72,    92,    89,    12,    93,    94,
      65,     0,    73,    28
};

static const yytype_int8 yycheck[] =
{
      10,    18,    22,    76,    24,    36,    18,    11,    22,     1,
      30,    70,     4,     5,     6,     7,     8,    18,    10,     0,
      93,    94,    26,    82,     5,    23,    18,    18,    48,     4,
       5,     6,    49,    25,    28,    55,    56,    57,    48,    12,
      13,    28,    29,    18,    64,    14,    15,    19,    20,    21,
      81,    71,    72,    26,    64,     4,     5,     6,    27,    24,
      80,    71,    72,    80,    95,    96,     1,    28,    29,     4,
       5,     6,     7,     8,     0,    10,    26,     3,     4,     5,
       6,    29,     1,    18,    22,     4,     5,     6,     7,     8,
      25,    10,     3,     4,     5,     6,    16,    17,     1,    18,
      22,     4,     5,     6,     7,     8,    25,    10,     1,    14,
      15,     4,     5,     6,    29,    18,    29,    10,    18,    19,
      20,    21,    25,     1,    23,    18,     4,     5,     6,     7,
       8,    24,    10,     1,    71,    72,     4,     5,     6,    29,
      18,    15,    10,    18,    19,    20,    21,    55,    56,    57,
      18,     9,    27,    29,    17,     9,    23,     5,    24,    24,
      49,    -1,    64,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    32,    33,    34,    35,    54,
      18,     0,    33,    18,    19,    20,    21,    48,    22,    36,
      46,    47,    54,    23,    28,    18,    53,    24,    47,    53,
      26,     1,     7,     8,    10,    37,    38,    39,    40,    43,
      44,    46,    53,    27,    48,    49,    53,    29,    22,    22,
      25,    37,    29,    29,    29,    11,    14,    15,    27,    45,
      48,    50,    52,    53,    41,    43,    46,    49,    49,    49,
      23,    16,    17,    45,    29,    29,    24,    40,    50,    50,
      29,    38,     9,    42,    46,    51,    53,    25,    40,    23,
      12,    13,     9,    24,    24,    38,    38,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    34,    35,    36,    37,
      37,    38,    38,    39,    39,    39,    39,    39,    40,    40,
      40,    40,    41,    41,    42,    42,    43,    44,    45,    46,
      46,    46,    47,    48,    48,    48,    49,    49,    49,    49,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     8,     1,     1,
       1,     1,     2,    10,     7,     5,     7,    11,     2,     2,
       2,     2,     2,     2,     1,     1,     3,     1,     1,     1,
       3,     3,     2,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     2,     2,     1,     1,     1,     3,     4,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* c_code: code  */
#line 118 "project3.y"
        {
            head = create_internal_node("c_code", 1, (yyvsp[0].node));
            (yyval.node) = head;
        }
#line 1375 "y.tab.c"
    break;

  case 3: /* c_code: c_code code  */
#line 123 "project3.y"
        {
            (yyval.node) = create_internal_node("c_code", 2, (yyvsp[-1].node), (yyvsp[0].node));
            head = (yyval.node);
        }
#line 1384 "y.tab.c"
    break;

  case 4: /* code: define_header  */
#line 131 "project3.y"
        {
            (yyval.node) = create_internal_node("code", 1, (yyvsp[0].node));
        }
#line 1392 "y.tab.c"
    break;

  case 5: /* code: func_def  */
#line 135 "project3.y"
        {
            (yyval.node) = create_internal_node("code", 1, (yyvsp[0].node));
        }
#line 1400 "y.tab.c"
    break;

  case 6: /* define_header: DEFINE ID number  */
#line 142 "project3.y"
        {
            NODE* d = create_token_node("DEFINE", (yyvsp[-2].string));
            NODE* id = create_token_node("ID", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("define_header", 3, d, id, (yyvsp[0].node));
        }
#line 1410 "y.tab.c"
    break;

  case 7: /* func_def: type ID LPAREN func_arg_dec RPAREN LBRACE body RBRACE  */
#line 151 "project3.y"
        {
            NODE* id = create_token_node("ID", (yyvsp[-6].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-5].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-3].string));
            NODE* lb = create_token_node("LBRACE", (yyvsp[-2].string));
            NODE* rb = create_token_node("RBRACE", (yyvsp[0].string));
            (yyval.node) = create_internal_node("func_def", 8, (yyvsp[-7].node), id, lp, (yyvsp[-4].node), rp, lb, (yyvsp[-1].node), rb);
        }
#line 1423 "y.tab.c"
    break;

  case 8: /* func_arg_dec: decl_list  */
#line 163 "project3.y"
        {
            (yyval.node) = create_internal_node("func_arg_dec", 1, (yyvsp[0].node));
        }
#line 1431 "y.tab.c"
    break;

  case 9: /* unit: clause  */
#line 170 "project3.y"
        {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1439 "y.tab.c"
    break;

  case 10: /* unit: statement  */
#line 174 "project3.y"
        {
            (yyval.node) = (yyvsp[0].node);
        }
#line 1447 "y.tab.c"
    break;

  case 11: /* body: unit  */
#line 181 "project3.y"
        { 
            (yyval.node) = create_internal_node("body", 1, (yyvsp[0].node));
        }
#line 1455 "y.tab.c"
    break;

  case 12: /* body: body unit  */
#line 185 "project3.y"
        {
            (yyval.node) = create_internal_node("body", 2, (yyvsp[-1].node), create_internal_node("body", 1, (yyvsp[0].node)));
        }
#line 1463 "y.tab.c"
    break;

  case 13: /* clause: FOR LPAREN init_stmt test_expr SEMICOLON update_stmt RPAREN LBRACE body RBRACE  */
#line 193 "project3.y"
        {
            NODE* for_tok = create_token_node("FOR", (yyvsp[-9].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-8].string));
            NODE* semi = create_token_node("SEMICOLON", (yyvsp[-5].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-3].string));
            NODE* lb = create_token_node("LBRACE", (yyvsp[-2].string));
            NODE* rb = create_token_node("RBRACE", (yyvsp[0].string));
            (yyval.node) = create_internal_node("clause", 10, for_tok, lp, (yyvsp[-7].node), (yyvsp[-6].node), semi, (yyvsp[-4].node), rp, lb, (yyvsp[-1].node), rb);
        }
#line 1477 "y.tab.c"
    break;

  case 14: /* clause: IF LPAREN test_expr RPAREN LBRACE body RBRACE  */
#line 204 "project3.y"
        {
            NODE* tok_if = create_token_node("IF", (yyvsp[-6].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-5].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-3].string));
            NODE* lb = create_token_node("LBRACE", (yyvsp[-2].string));
            NODE* rb = create_token_node("RBRACE", (yyvsp[0].string));
            (yyval.node) = create_internal_node("clause", 7, tok_if, lp, (yyvsp[-4].node), rp, lb, (yyvsp[-1].node), rb);
        }
#line 1490 "y.tab.c"
    break;

  case 15: /* clause: IF LPAREN test_expr RPAREN statement  */
#line 214 "project3.y"
        {
            NODE* tok_if = create_token_node("IF", (yyvsp[-4].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-3].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("clause", 5, tok_if, lp, (yyvsp[-2].node), rp, (yyvsp[0].node));
        }
#line 1501 "y.tab.c"
    break;

  case 16: /* clause: IF LPAREN test_expr RPAREN statement ELSE statement  */
#line 222 "project3.y"
        {
            NODE* tok_if = create_token_node("IF", (yyvsp[-6].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-5].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-3].string));
            NODE* tok_else = create_token_node("ELSE", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("clause", 7, tok_if, lp, (yyvsp[-4].node), rp, (yyvsp[-2].node), tok_else, (yyvsp[0].node));
        }
#line 1513 "y.tab.c"
    break;

  case 17: /* clause: IF LPAREN test_expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE  */
#line 231 "project3.y"
        {
            NODE* tok_if = create_token_node("IF", (yyvsp[-10].string));
            NODE* lp = create_token_node("LPAREN", (yyvsp[-9].string));
            NODE* rp = create_token_node("RPAREN", (yyvsp[-7].string));
            NODE* lb1 = create_token_node("LBRACE", (yyvsp[-6].string));
            NODE* rb1 = create_token_node("RBRACE", (yyvsp[-4].string));
            NODE* tok_else = create_token_node("ELSE", (yyvsp[-3].string));
            NODE* lb2 = create_token_node("LBRACE", (yyvsp[-2].string));
            NODE* rb2 = create_token_node("RBRACE", (yyvsp[0].string));
            (yyval.node) = create_internal_node("clause", 11, tok_if, lp, (yyvsp[-8].node), rp, lb1, (yyvsp[-5].node), rb1, tok_else, lb2, (yyvsp[-1].node), rb2);
        }
#line 1529 "y.tab.c"
    break;

  case 18: /* statement: assign_stmt SEMICOLON  */
#line 246 "project3.y"
        {
            (yyval.node) = create_internal_node("statement", 2, (yyvsp[-1].node), create_token_node("SEMICOLON", (yyvsp[0].string)));
        }
#line 1537 "y.tab.c"
    break;

  case 19: /* statement: continue_stmt SEMICOLON  */
#line 250 "project3.y"
        {
            (yyval.node) = create_internal_node("statement", 2, (yyvsp[-1].node), create_token_node("SEMICOLON", (yyvsp[0].string)));
        }
#line 1545 "y.tab.c"
    break;

  case 20: /* statement: decl_list SEMICOLON  */
#line 254 "project3.y"
        {
            (yyval.node) = create_internal_node("statement", 2, (yyvsp[-1].node), create_token_node("SEMICOLON", (yyvsp[0].string)));
        }
#line 1553 "y.tab.c"
    break;

  case 21: /* statement: error SEMICOLON  */
#line 258 "project3.y"
        {
            yyerrok;
            NODE* err = create_token_node("ERROR", "error");
            NODE* semi = create_token_node("SEMICOLON", (yyvsp[0].string));
            (yyval.node) = create_internal_node("statement", 2, err, semi);
        }
#line 1564 "y.tab.c"
    break;

  case 22: /* init_stmt: assign_stmt SEMICOLON  */
#line 268 "project3.y"
        {
            NODE* semi = create_token_node("SEMICOLON", (yyvsp[0].string));
            (yyval.node) = create_internal_node("init_stmt", 2, (yyvsp[-1].node), semi);
        }
#line 1573 "y.tab.c"
    break;

  case 23: /* init_stmt: decl_list SEMICOLON  */
#line 273 "project3.y"
        {
            NODE* semi = create_token_node("SEMICOLON", (yyvsp[0].string));
            (yyval.node) = create_internal_node("init_stmt", 2, (yyvsp[-1].node), semi);
        }
#line 1582 "y.tab.c"
    break;

  case 24: /* update_stmt: inc_expr  */
#line 281 "project3.y"
        {
            (yyval.node) = create_internal_node("update_stmt", 1, (yyvsp[0].node));
        }
#line 1590 "y.tab.c"
    break;

  case 25: /* update_stmt: decl_list  */
#line 285 "project3.y"
        {
            (yyval.node) = create_internal_node("update_stmt", 1, (yyvsp[0].node));
        }
#line 1598 "y.tab.c"
    break;

  case 26: /* assign_stmt: variable OP_ASSIGN al_expr  */
#line 292 "project3.y"
        {
            NODE* assign_tok = create_token_node("OP_ASSIGN", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("assign_stmt", 3, (yyvsp[-2].node), assign_tok, (yyvsp[0].node));
        }
#line 1607 "y.tab.c"
    break;

  case 27: /* continue_stmt: CONTINUE  */
#line 300 "project3.y"
        {
            NODE* cont = create_token_node("CONTINUE", (yyvsp[0].string));
            (yyval.node) = create_internal_node("continue_stmt", 1, cont);
        }
#line 1616 "y.tab.c"
    break;

  case 28: /* test_expr: rel_expr  */
#line 308 "project3.y"
        {
            (yyval.node) = create_internal_node("test_expr", 1, (yyvsp[0].node));
        }
#line 1624 "y.tab.c"
    break;

  case 29: /* decl_list: decl_init  */
#line 315 "project3.y"
        {
            (yyval.node) = create_internal_node("decl_list", 1, (yyvsp[0].node));
        }
#line 1632 "y.tab.c"
    break;

  case 30: /* decl_list: decl_list COMMA variable  */
#line 319 "project3.y"
        {
            NODE* comma = create_token_node("COMMA", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("decl_list", 3, (yyvsp[-2].node), comma, (yyvsp[0].node));
        }
#line 1641 "y.tab.c"
    break;

  case 31: /* decl_list: decl_list COMMA decl_init  */
#line 324 "project3.y"
        {
            NODE* comma = create_token_node("COMMA", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("decl_list", 3, (yyvsp[-2].node), comma, (yyvsp[0].node));
        }
#line 1650 "y.tab.c"
    break;

  case 32: /* decl_init: type variable  */
#line 332 "project3.y"
        {
            (yyval.node) = create_internal_node("decl_init", 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1658 "y.tab.c"
    break;

  case 33: /* number: NUM  */
#line 339 "project3.y"
        {
            (yyval.node) = create_token_node("NUM", (yyvsp[0].string));
        }
#line 1666 "y.tab.c"
    break;

  case 34: /* number: NUM_BIN  */
#line 343 "project3.y"
        {
            (yyval.node) = create_token_node("NUM_BIN", (yyvsp[0].string));
        }
#line 1674 "y.tab.c"
    break;

  case 35: /* number: NUM_HEX  */
#line 347 "project3.y"
        {
            (yyval.node) = create_token_node("NUM_HEX", (yyvsp[0].string));
        }
#line 1682 "y.tab.c"
    break;

  case 36: /* al_expr: number  */
#line 354 "project3.y"
        {
            (yyval.node) = create_internal_node("al_expr", 1, (yyvsp[0].node));
        }
#line 1690 "y.tab.c"
    break;

  case 37: /* al_expr: variable  */
#line 358 "project3.y"
        {
            (yyval.node) = create_internal_node("al_expr", 1, (yyvsp[0].node));
        }
#line 1698 "y.tab.c"
    break;

  case 38: /* al_expr: al_expr OP_ADD al_expr  */
#line 362 "project3.y"
        {
            NODE* add_tok = create_token_node("OP_ADD", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("al_expr", 3, (yyvsp[-2].node), add_tok, (yyvsp[0].node));
        }
#line 1707 "y.tab.c"
    break;

  case 39: /* al_expr: al_expr OP_MUL al_expr  */
#line 367 "project3.y"
        {
            NODE* mul_tok = create_token_node("OP_MUL", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("al_expr", 3, (yyvsp[-2].node), mul_tok, (yyvsp[0].node));
        }
#line 1716 "y.tab.c"
    break;

  case 40: /* rel_expr: value  */
#line 375 "project3.y"
        {
            (yyval.node) = create_internal_node("rel_expr", 1, (yyvsp[0].node));
        }
#line 1724 "y.tab.c"
    break;

  case 41: /* rel_expr: rel_expr OP_REL rel_expr  */
#line 379 "project3.y"
        {
            NODE* rel_tok = create_token_node("OP_REL", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("rel_expr", 3, (yyvsp[-2].node), rel_tok, (yyvsp[0].node));
        }
#line 1733 "y.tab.c"
    break;

  case 42: /* rel_expr: rel_expr OP_LOGIC rel_expr  */
#line 384 "project3.y"
        {
            NODE* logic_tok = create_token_node("OP_LOGIC", (yyvsp[-1].string));
            (yyval.node) = create_internal_node("rel_expr", 3, (yyvsp[-2].node), logic_tok, (yyvsp[0].node));
        }
#line 1742 "y.tab.c"
    break;

  case 43: /* inc_expr: variable OP_INC  */
#line 392 "project3.y"
        {
            NODE* tok = create_token_node("OP_INC", (yyvsp[0].string));
            (yyval.node) = create_internal_node("inc_expr", 2, (yyvsp[-1].node), tok);
        }
#line 1751 "y.tab.c"
    break;

  case 44: /* inc_expr: variable OP_DEC  */
#line 397 "project3.y"
        {
            NODE* tok = create_token_node("OP_DEC", (yyvsp[0].string));
            (yyval.node) = create_internal_node("inc_expr", 2, (yyvsp[-1].node), tok);
        }
#line 1760 "y.tab.c"
    break;

  case 45: /* value: variable  */
#line 405 "project3.y"
        {
            (yyval.node) = create_internal_node("value", 1, (yyvsp[0].node));
        }
#line 1768 "y.tab.c"
    break;

  case 46: /* value: number  */
#line 409 "project3.y"
        {
            (yyval.node) = create_internal_node("value", 1, (yyvsp[0].node));
        }
#line 1776 "y.tab.c"
    break;

  case 47: /* variable: ID  */
#line 416 "project3.y"
        {
            NODE* id_tok = create_token_node("ID", (yyvsp[0].string));
            (yyval.node) = create_internal_node("variable", 1, id_tok);
        }
#line 1785 "y.tab.c"
    break;

  case 48: /* variable: variable LBRACKET RBRACKET  */
#line 421 "project3.y"
        {
            NODE* lb = create_token_node("LBRACKET", (yyvsp[-1].string));
            NODE* rb = create_token_node("RBRACKET", (yyvsp[0].string));
            (yyval.node) = create_internal_node("variable", 3, (yyvsp[-2].node), lb, rb);
        }
#line 1795 "y.tab.c"
    break;

  case 49: /* variable: variable LBRACKET al_expr RBRACKET  */
#line 427 "project3.y"
        {
            NODE* lb = create_token_node("LBRACKET", (yyvsp[-2].string));
            NODE* rb = create_token_node("RBRACKET", (yyvsp[0].string));
            (yyval.node) = create_internal_node("variable", 4, (yyvsp[-3].node), lb, (yyvsp[-1].node), rb);
        }
#line 1805 "y.tab.c"
    break;

  case 50: /* type: VOID  */
#line 436 "project3.y"
        {
            NODE* tok = create_token_node("VOID", (yyvsp[0].string));
            (yyval.node) = create_internal_node("type", 1, tok);
        }
#line 1814 "y.tab.c"
    break;

  case 51: /* type: INT  */
#line 441 "project3.y"
        {
            NODE* tok = create_token_node("INT", (yyvsp[0].string));
            (yyval.node) = create_internal_node("type", 1, tok);
        }
#line 1823 "y.tab.c"
    break;

  case 52: /* type: FLOAT  */
#line 446 "project3.y"
        {
            NODE* tok = create_token_node("FLOAT", (yyvsp[0].string));
            (yyval.node) = create_internal_node("type", 1, tok);
        }
#line 1832 "y.tab.c"
    break;


#line 1836 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 451 "project3.y"


/**********EPILOGUE AREAR AREA**********/
//THIS AREA WILL BE COPIED TO y.tab.c CODE

int main(int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "usage: %s <source.c>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin){
        fprintf(stderr, "cannot open %s\n", argv[1]);
        return 1;
    }
    
    filename = argv[1];
    
    yyparse();
    
    /* Construct symbol table */
    SYMTAB* root_symtab = NewSymTab();
    ConstructSymTab(root_symtab, head);
    
    /* Print symbol table */
    PrintSymTab(root_symtab);
    
    /* Perform scope analysis */
    ScopeAnalysis(root_symtab, head);
    
    /* Perform type analysis */
    TypeAnalysis(root_symtab, head);
    
    fclose(yyin);
    return 0;
}
