/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "lab9.y" /* yacc.c:339  */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "symtable.h"
#include "emit.h"

int level = 0; // the level of the scope we are in. 
int offset = 0; // Keeps track of fielddecl offset values
int goffset = 0; // keeps track of 
int maxoffset;

int yylex();

extern int yylineno; // import the yylineno variable
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
        // changed these to output to stderr
  fprintf(stderr, "%s ", s);

  // print out the line number of the syntax error.
  fprintf(stderr, "Error on line:  %d \n", yylineno); 
}

struct ASTnodetype *PROGRAM;


#line 98 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_AND = 258,
    T_ASSIGN = 259,
    T_BOOLTYPE = 260,
    T_BREAK = 261,
    T_CONTINUE = 262,
    T_ELSE = 263,
    T_EQ = 264,
    T_EXTERN = 265,
    T_FALSE = 266,
    T_FUNC = 267,
    T_GEQ = 268,
    T_ID = 269,
    T_IF = 270,
    T_INTCONSTANT = 271,
    T_INTTYPE = 272,
    T_LEFTSHIFT = 273,
    T_LEQ = 274,
    T_NEQ = 275,
    T_OR = 276,
    T_PACKAGE = 277,
    T_RETURN = 278,
    T_RIGHTSHIFT = 279,
    T_STRINGCONSTANT = 280,
    T_STRINGTYPE = 281,
    T_TRUE = 282,
    T_VAR = 283,
    T_VOID = 284,
    T_WHILE = 285
  };
#endif
/* Tokens.  */
#define T_AND 258
#define T_ASSIGN 259
#define T_BOOLTYPE 260
#define T_BREAK 261
#define T_CONTINUE 262
#define T_ELSE 263
#define T_EQ 264
#define T_EXTERN 265
#define T_FALSE 266
#define T_FUNC 267
#define T_GEQ 268
#define T_ID 269
#define T_IF 270
#define T_INTCONSTANT 271
#define T_INTTYPE 272
#define T_LEFTSHIFT 273
#define T_LEQ 274
#define T_NEQ 275
#define T_OR 276
#define T_PACKAGE 277
#define T_RETURN 278
#define T_RIGHTSHIFT 279
#define T_STRINGCONSTANT 280
#define T_STRINGTYPE 281
#define T_TRUE 282
#define T_VAR 283
#define T_VOID 284
#define T_WHILE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "lab9.y" /* yacc.c:355  */

    int value;
    char* string;
    struct ASTnodetype *astnode;
    enum AST_Decaf_Types asttype;
    enum AST_Operators operator;

#line 206 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    45,     2,     2,
      33,    34,    43,    41,    36,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      39,     2,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   140,   141,   144,   167,   168,   171,   175,
     182,   183,   189,   205,   221,   241,   242,   250,   273,   250,
     295,   296,   299,   314,   335,   335,   359,   360,   366,   384,
     403,   404,   414,   415,   416,   417,   418,   419,   420,   421,
     425,   428,   434,   437,   450,   461,   462,   463,   469,   498,
     530,   556,   590,   600,   603,   608,   611,   627,   630,   631,
     652,   653,   654,   655,   656,   657,   660,   661,   678,   679,
     682,   683,   711,   712,   713,   714,   715,   716,   717,   720,
     741,   742,   763,   764,   765,   786,   791,   811,   812,   816,
     817,   820,   821,   824,   829,   836,   845,   851
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_AND", "T_ASSIGN", "T_BOOLTYPE",
  "T_BREAK", "T_CONTINUE", "T_ELSE", "T_EQ", "T_EXTERN", "T_FALSE",
  "T_FUNC", "T_GEQ", "T_ID", "T_IF", "T_INTCONSTANT", "T_INTTYPE",
  "T_LEFTSHIFT", "T_LEQ", "T_NEQ", "T_OR", "T_PACKAGE", "T_RETURN",
  "T_RIGHTSHIFT", "T_STRINGCONSTANT", "T_STRINGTYPE", "T_TRUE", "T_VAR",
  "T_VOID", "T_WHILE", "'{'", "'}'", "'('", "')'", "';'", "','", "'['",
  "']'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "Program", "Externs", "ExternDefn", "ExternParmList",
  "FullExternParmList", "FieldDecls", "FieldDecl", "MethodDecls",
  "MethodDecl", "$@1", "$@2", "IdTypeList", "IdTypeList1", "Block", "$@3",
  "VarDecls", "VarDecl", "Statements", "Statement", "ContinueStmt",
  "WhileStmt", "BreakStmt", "IfStmt", "ReturnStmt", "Assign", "Lvalue",
  "MethodCall", "MethodArg", "MethodArgs", "FullMethodArgs", "Expr",
  "Simpleexpression", "Relop", "Additiveexpression", "Addop", "Term",
  "Multop", "Factor", "ExternType", "Type", "MethodType", "BoolConstant",
  "ArrayType", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   123,   125,    40,    41,    59,    44,    91,    93,    60,
      62,    43,    45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF -106

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-106)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      26,     3,    40,    37,    26,    50,  -106,    58,  -106,    42,
      51,     8,    53,  -106,  -106,  -106,    39,  -106,    43,  -106,
      62,    71,    53,    45,     8,     9,    77,    64,    71,  -106,
    -106,  -106,    60,  -106,    81,    18,    65,  -106,  -106,  -106,
    -106,    61,    74,  -106,  -106,    69,     1,  -106,  -106,  -106,
    -106,    70,    84,  -106,  -106,     1,    72,  -106,    68,    45,
      84,  -106,  -106,    76,  -106,  -106,    80,    95,    63,    80,
       9,    75,    78,   -26,    79,    23,    82,  -106,    85,    63,
    -106,  -106,  -106,  -106,  -106,    83,   107,    86,  -106,    87,
      88,  -106,  -106,    38,    38,    38,     5,  -106,    38,  -106,
    -106,  -106,    38,  -106,  -106,  -106,   -25,  -106,    38,    38,
      38,  -106,    89,    90,  -106,  -106,    48,   -32,    -1,  -106,
    -106,    91,    92,    93,    96,    97,  -106,    38,    98,  -106,
    -106,    38,  -106,  -106,  -106,  -106,  -106,  -106,  -106,    38,
    -106,  -106,    38,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
      38,  -106,    76,  -106,    99,    76,   100,  -106,  -106,   -32,
      -1,  -106,   106,  -106,  -106,  -106,    76,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,     0,     4,     0,
       0,     6,    10,    90,    89,    87,     0,     7,     8,    88,
       0,    15,    10,     0,     6,     0,     0,     0,    15,    11,
      91,    92,     0,     9,     0,     0,     0,    17,     2,    16,
       5,     0,     0,    12,    13,     0,     0,    94,    96,    93,
      97,     0,    20,    95,    14,     0,     0,    21,    22,     0,
      20,    18,    23,     0,    24,    19,    26,     0,    30,    26,
       0,     0,     0,    49,     0,     0,     0,    32,     0,    30,
      39,    36,    38,    35,    37,     0,     0,     0,    27,     0,
       0,    42,    40,    53,     0,     0,     0,    45,     0,    25,
      31,    33,     0,    34,    28,    29,    79,    85,     0,     0,
       0,    80,    55,     0,    54,    52,    57,    58,    66,    70,
      82,     0,     0,     0,     0,     0,    48,     0,     0,    86,
      84,    53,    51,    62,    64,    63,    65,    60,    61,     0,
      68,    69,     0,    75,    77,    76,    78,    72,    73,    74,
       0,    50,     0,    46,     0,     0,     0,    83,    56,    59,
      67,    71,    44,    47,    41,    81,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,   112,  -106,   103,  -106,   111,  -106,   108,  -106,
    -106,  -106,    59,  -106,   -63,  -106,    66,  -106,    41,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,   -13,  -106,     6,
    -106,   -67,  -106,  -106,     0,  -106,    -2,  -106,  -105,  -106,
     -22,    94,  -106,    73,   102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    16,    17,    21,    22,    27,    28,
      45,    63,    56,    57,    77,    66,    68,    69,    78,    79,
      80,    81,    82,    83,    84,    85,    86,   111,   112,   113,
     114,   115,   116,   139,   117,   142,   118,   150,   119,    18,
      19,    32,    50,    36,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    31,   143,    35,   129,   130,    13,    93,    93,   140,
     141,    94,   127,    13,    13,     5,    47,   144,    14,   106,
     145,    48,    42,   146,    53,    14,    14,   121,   122,   124,
     107,   125,    49,    58,    15,   126,     1,    31,   108,   123,
       6,   128,   147,   148,   149,   161,    34,   109,    89,    47,
      13,   110,   106,    43,    48,    87,    96,   133,    97,     7,
     156,   134,    14,   107,     9,    49,    87,   135,   136,    71,
      72,   108,    10,    23,    30,    11,    25,    73,    74,    24,
     109,    20,    12,    26,   110,    47,    75,   137,   138,   162,
      48,    37,   164,    76,    64,    40,    38,    41,    55,    46,
      44,    49,    52,   167,    60,    54,    59,    64,    67,    70,
      91,   102,    95,    92,   166,    98,     8,    99,   101,    62,
     100,   103,   104,   105,   132,   131,   152,    33,   153,   151,
     154,   155,   157,    29,   163,    88,    39,   158,   165,   159,
     160,     0,     0,    90,    51,     0,     0,     0,     0,     0,
       0,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      63,    23,     3,    25,   109,   110,     5,    33,    33,    41,
      42,    37,    37,     5,     5,    12,    11,    18,    17,    14,
      21,    16,     4,    24,    46,    17,    17,    94,    95,    96,
      25,    98,    27,    55,    26,   102,    10,    59,    33,    34,
       0,   108,    43,    44,    45,   150,    37,    42,    70,    11,
       5,    46,    14,    35,    16,    68,    33,     9,    35,    22,
     127,    13,    17,    25,    14,    27,    79,    19,    20,     6,
       7,    33,    14,    34,    29,    33,    14,    14,    15,    36,
      42,    28,    31,    12,    46,    11,    23,    39,    40,   152,
      16,    14,   155,    30,    31,    35,    32,    16,    14,    38,
      35,    27,    33,   166,    36,    35,    34,    31,    28,    14,
      35,     4,    33,    35,     8,    33,     4,    32,    35,    60,
      79,    35,    35,    35,    34,    36,    34,    24,    35,    38,
      34,    34,    34,    22,    35,    69,    28,   131,    38,   139,
     142,    -1,    -1,    70,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    48,    49,    50,    12,     0,    22,    49,    14,
      14,    33,    31,     5,    17,    26,    51,    52,    86,    87,
      28,    53,    54,    34,    36,    14,    12,    55,    56,    53,
      29,    87,    88,    51,    37,    87,    90,    14,    32,    55,
      35,    16,     4,    35,    35,    57,    38,    11,    16,    27,
      89,    91,    33,    87,    35,    14,    59,    60,    87,    34,
      36,    88,    59,    58,    31,    61,    62,    28,    63,    64,
      14,     6,     7,    14,    15,    23,    30,    61,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    63,    87,
      90,    35,    35,    33,    37,    33,    33,    35,    33,    32,
      65,    35,     4,    35,    35,    35,    14,    25,    33,    42,
      46,    74,    75,    76,    77,    78,    79,    81,    83,    85,
      91,    78,    78,    34,    78,    78,    78,    37,    78,    85,
      85,    36,    34,     9,    13,    19,    20,    39,    40,    80,
      41,    42,    82,     3,    18,    21,    24,    43,    44,    45,
      84,    38,    34,    35,    34,    34,    78,    34,    76,    81,
      83,    85,    61,    35,    61,    38,     8,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    55,    57,    58,    56,
      59,    59,    60,    60,    62,    61,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    68,    69,    70,    70,    71,    71,    71,    72,    73,
      73,    74,    75,    76,    76,    77,    77,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     0,     2,     8,     0,     1,     1,     3,
       0,     2,     4,     4,     6,     0,     2,     0,     0,     9,
       0,     1,     2,     4,     0,     5,     0,     2,     4,     4,
       0,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       2,     5,     2,     7,     5,     2,     4,     5,     3,     1,
       4,     4,     1,     0,     1,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 130 "lab9.y" /* yacc.c:1646  */
    {
                PROGRAM = ASTCreateNode(A_PROGRAM);
                PROGRAM->S1 = (yyvsp[-6].astnode);
                PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
                PROGRAM->S2->name = (yyvsp[-4].string);
                PROGRAM->S2->S1 = (yyvsp[-2].astnode);
                PROGRAM->S2->S2 = (yyvsp[-1].astnode);
        }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = NULL; }
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "lab9.y" /* yacc.c:1646  */
    { (yyvsp[-1].astnode)->next = (yyvsp[0].astnode); }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 144 "lab9.y" /* yacc.c:1646  */
    {
                // we need to see if $3 has already been defined.
                // if so => BARF
                if (Search((yyvsp[-5].string), level, 0) != NULL) {
                        yyerror("Symbol already deafined");
                        yyerror((yyvsp[-5].string));
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_EXTERN);
                (yyval.astnode)->name = (yyvsp[-5].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype);
                (yyval.astnode)->size = 0; 
                (yyval.astnode)->S1 = (yyvsp[-3].astnode); // set the S1 to the list of params node

                // set our symbol to the return value of Insert()
                (yyval.astnode)->symbol = Insert((yyvsp[-5].string),(yyvsp[-1].asttype),ID_Sub_Type_Extern_Method, level, 0, 0, (yyvsp[-3].astnode));
                // offset++;
                
                // moved to main
                 if(mydebug) Display(); // Display the table for debugging
        }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 167 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = NULL; }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 168 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = (yyvsp[0].astnode);}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_ExternType);
                (yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
        }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 175 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_ExternType);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 182 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[-1].astnode);
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used
                if (Search((yyvsp[-2].string), level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror((yyvsp[-2].string));
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VARDEC);
                (yyval.astnode)->name = (yyvsp[-2].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype); 
                (yyval.astnode)->size = 1; // scalars are size 1
                
                // insert the variable into the symtable
                (yyval.astnode)->symbol = Insert((yyvsp[-2].string),(yyvsp[-1].asttype),ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used
                if (Search((yyvsp[-2].string), level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror((yyvsp[-2].string));
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VARDEC);
                (yyval.astnode)->name = (yyvsp[-2].string);
                (yyval.astnode)->S1 = (yyvsp[-1].astnode); // set S1 to the ArrayType
                (yyval.astnode)->A_Declared_Type = (yyvsp[-1].astnode)->A_Declared_Type; // duplicate the type in the array
                (yyval.astnode)->size = (yyvsp[-1].astnode)->size; // Arrays are based on the ArrayType value
                // insert the variable into the symtable
                (yyval.astnode)->symbol = Insert((yyvsp[-2].string),(yyvsp[-1].astnode)->A_Declared_Type,ID_Sub_Type_Array, level, (yyval.astnode)->size, offset, NULL);
                offset += (yyvsp[-1].astnode)->size; // increment the offset by the size of the array.
        }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 221 "lab9.y" /* yacc.c:1646  */
    {
                // we do the same thing in here that we did for the one without the T_ASSIGN

                // Before we create the node let's check if the T_ID is used
                if (Search((yyvsp[-4].string), level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror((yyvsp[-4].string));
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VARDEC);
                (yyval.astnode)->name = (yyvsp[-4].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-3].asttype); // set type to the Type output node 
                (yyval.astnode)->size = 1; // this is still a scalar so we set size to 1. 
                (yyval.astnode)->symbol = Insert((yyvsp[-4].string),(yyvsp[-3].asttype),ID_Sub_Type_Scalar, level,(yyval.astnode)->size, offset, NULL);
                offset++; // increment offset by 1 because it's a scalar. 
                (yyval.astnode)->S2 = (yyvsp[-1].astnode); // set S2 to the Constant node

        }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 241 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = NULL;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 242 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[-1].astnode);
                (yyval.astnode)->next = (yyvsp[0].astnode); // set the next to the right recursive value
        }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *s;

                s = Search((yyvsp[0].string), level, 0);

                if (s != NULL){
                        fprintf(stderr, "Symbol %s has already been used in a method\n", (yyvsp[0].string));
                        yyerror("duplicate method name");
                        exit(1);
                } else {
                        s = Insert((yyvsp[0].string),0,ID_Sub_Type_Method, level, 0, 0, NULL);
                        // update the type after we get it
                        if (mydebug) Display();

                        // set offset for start of method
                        goffset = offset;
                        offset = 2;
                        maxoffset = offset; 
                }



                
        }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 273 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *s;
                s = Search((yyvsp[-5].string), level, 0);
                s->Type = (yyvsp[0].asttype);
                s->fparms = (yyvsp[-2].astnode);
                
        }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 279 "lab9.y" /* yacc.c:1646  */
    {
                
                // increment anything greater than $2 by 1 for the new component
                (yyval.astnode) = ASTCreateNode(A_METHODDEC);
                (yyval.astnode)->name = (yyvsp[-7].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
                // $$->size = 1; changed to offset
                (yyval.astnode)->S1 = (yyvsp[-4].astnode); // $5;
                (yyval.astnode)->S2 = (yyvsp[0].astnode); // $9;
                (yyval.astnode)->symbol = Search((yyvsp[-7].string), level, 0);
                (yyval.astnode)->size = maxoffset;
                (yyval.astnode)->symbol->mysize = maxoffset; // max size needed to run program
                offset = goffset;
        }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 295 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = NULL; }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 296 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 299 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used
                if(Search ((yyvsp[-1].string), level + 1, 0)!= NULL) {
                        yyerror("Duplicate method arg name");
                        yyerror((yyvsp[-1].string));
                }
                
                (yyval.astnode) = ASTCreateNode(A_METHODID);
                (yyval.astnode)->name = (yyvsp[-1].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
                (yyval.astnode)->size = 1;

                (yyval.astnode)->symbol=Insert((yyvsp[-1].string),(yyvsp[0].asttype),ID_Sub_Type_Scalar, level+1, 1, offset, NULL);
                offset++; // increment offset by 1 as per instructions
        }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 314 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used

                // check if there are duplicate args
                if(Search ((yyvsp[-3].string), level + 1, 0)!= NULL) {
                        yyerror("Duplicate method arg name");
                        yyerror((yyvsp[-3].string));
                }
                (yyval.astnode) = ASTCreateNode(A_METHODID);
                (yyval.astnode)->name = (yyvsp[-3].string);
                (yyval.astnode)->A_Declared_Type = (yyvsp[-2].asttype);
                (yyval.astnode)->size = 1;

                // we do level + 1 because the args are part of the block created by the method. 
                (yyval.astnode)->symbol=Insert((yyvsp[-3].string),(yyvsp[-2].asttype),ID_Sub_Type_Scalar, level+1, 1, offset, NULL);
                offset++; // increment offset by 1 as per instructions
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 335 "lab9.y" /* yacc.c:1646  */
    { level++; }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 335 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_BLOCK);

                // incremented these because added in-rule action
                (yyval.astnode)->S1 = (yyvsp[-2].astnode); // set S1 to the VarDecls
                (yyval.astnode)->S2 = (yyvsp[-1].astnode); // set S2 to the Statements
                if(mydebug) Display(); // Display here so we can see the symtab at each level

                // if the offset is greater than the maxoffset of the method
                // then we set the maxoffset to the offset to fix it's max value
                if (offset > maxoffset) {
                        maxoffset = offset;
                }

                // We delete all the symbols at the current level before leaving. 
                // this way they don't conflict with levels lower. 
                offset -= Delete(level); 
                
                // decrement level since we finished the block
                level--;
                
        }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 359 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = NULL; }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 360 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[-1].astnode);
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 366 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used
                if (Search((yyvsp[-2].string), level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror((yyvsp[-2].string));
                        exit(1);
                }

                // Create an A_VARDEC node 
                (yyval.astnode) = ASTCreateNode(A_VARDEC);
                (yyval.astnode)->name = (yyvsp[-2].string); // set it's name to T_ID
                (yyval.astnode)->A_Declared_Type = (yyvsp[-1].asttype); // set it's type to outpit of Type

                // insert the variable into the symtable
                (yyval.astnode)->symbol = Insert((yyvsp[-2].string),(yyvsp[-1].asttype),ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
                // Display(); // debugging only 
        }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 384 "lab9.y" /* yacc.c:1646  */
    {
                // Before we create the node let's check if the T_ID is used
                if (Search((yyvsp[-2].string), level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror((yyvsp[-2].string));
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VARDEC);
                (yyval.astnode)->name = (yyvsp[-2].string);
                (yyval.astnode)->S1 = (yyvsp[-1].astnode); // set S1 to the ArrayType node
                (yyval.astnode)->A_Declared_Type = (yyvsp[-1].astnode)->A_Declared_Type;
                (yyval.astnode)->size = (yyvsp[-1].astnode)->size; // set the size to the size of the ArrayType node

                // insert the variable into the symtable
                (yyval.astnode)->symbol = Insert((yyvsp[-2].string),(yyvsp[-1].astnode)->A_Declared_Type, ID_Sub_Type_Array, level, (yyval.astnode)->size, offset, NULL);
                offset += (yyvsp[-1].astnode)->size; // increment offset by the size of the array.
        }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 403 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = NULL; }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 404 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[-1].astnode);
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 415 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[-1].astnode); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 416 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[-1].astnode); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 420 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 421 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "lab9.y" /* yacc.c:1646  */
    {(yyval.astnode) = ASTCreateNode(A_CONTINUE);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 428 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_WHILESTMT);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode); // set S1 to thje Expr
                (yyval.astnode)->S2 = (yyvsp[0].astnode); // Set S2 to the Block
        }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 434 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = ASTCreateNode(A_BREAK); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 437 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_IF); 
                (yyval.astnode)->S1 = (yyvsp[-4].astnode); // set S1 to the Expression node
                (yyval.astnode)->S2 = ASTCreateNode(A_IFBODY); // create a separate node for the body in S2
                (yyval.astnode)->S2->S1 = (yyvsp[-2].astnode);  // set the S1 of the body to the block of the IF
                (yyval.astnode)->S2->S2 = (yyvsp[0].astnode); // create a new node for the else statement after the body

                /*I modified my original implementation to 
                not have an A_ELSE node. Instead we just store the blocks
                directly in the S1 and S2 of the A_IFBODY respectively. 
                This makes the logic on the emit.c side much simpler*/

        }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 450 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_IF);

                // Set S1 to the Expression node
                (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                (yyval.astnode)->S2 = ASTCreateNode(A_IFBODY);  // create a separate node for the body in S2
                (yyval.astnode)->S2->S1 = (yyvsp[0].astnode); // set the S1 of the body to the block
                (yyval.astnode)->S2->S2 = NULL;  // since we have no Else we set it's node to NULL this time
        }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 461 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = ASTCreateNode(A_RETURN);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 462 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = ASTCreateNode(A_RETURN);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 463 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_RETURN);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode);  // set the S1 to the expression we returned
        }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 469 "lab9.y" /* yacc.c:1646  */
    {

                // make sure the left and right hand types are matching
                if ( (yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type) {
                        yyerror("Type mismatch on assignment");
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_ASSIGN);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode); // set the S1 to the left hand side 
                (yyval.astnode)->S2 = (yyvsp[0].astnode); // set the S2 to the right hand side
                (yyval.astnode)->name = TEMP_CREATE();
                 // create a temporary symbol to hold value
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name, (yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);

                // Determine if we need to increment offset
                // Yes we do because the assignments need temporary values 
                // in the function's space
                offset++;
        }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 498 "lab9.y" /* yacc.c:1646  */
    {
                /* I am using A_VAR_RVALUE for both the LVALUE and RVALUE
                Mostly because the node serves the same purpose.
                 */

                /* well apparently that was wrong so I changed to a new 
                   node type LVALUE which now has it's own case and enum
                */

                // grab the symbol from the table corresponding the T_ID
                struct SymbTab *p; 
                p = Search((yyvsp[0].string), level, 1);

                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror((yyvsp[0].string));
                        exit(1);
                }
                
                // Make sure the type is a scalar and not an array/method
                if (p->SubType != ID_Sub_Type_Scalar){
                        yyerror((yyvsp[0].string));
                        yyerror("needs to be a scalar, wrong subtype");
                        exit(1);
                }

                (yyval.astnode) = ASTCreateNode(A_VAR_LVALUE);
                (yyval.astnode)->name = (yyvsp[0].string);
                (yyval.astnode)->symbol = p;
                (yyval.astnode)->A_Declared_Type = p->Type;
        }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 530 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *p;
                p = Search((yyvsp[-3].string), level, 1);

                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror((yyvsp[-3].string));
                        exit(1);
                }
                
                // Make sure it's an array and not a Scalar/Method
                if (p->SubType != ID_Sub_Type_Array){
                        yyerror((yyvsp[-3].string));
                        yyerror("needs to be an array, wrong subtype");
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VAR_LVALUE);
                (yyval.astnode)->name = (yyvsp[-3].string);
                (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                (yyval.astnode)->symbol = p;
                (yyval.astnode)->A_Declared_Type = p->Type; // the type is the same as the symbol we got it from
        }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 556 "lab9.y" /* yacc.c:1646  */
    {
                 struct SymbTab *p;
                p = Search((yyvsp[-3].string), level, 1);
                
                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Method symbol not defined");
                        yyerror((yyvsp[-3].string));
                        exit(1);
                }

                // Make sure it's a Method or Extern Method and not an Array/Scalar
                if ((p->SubType != ID_Sub_Type_Method) && (p->SubType != ID_Sub_Type_Extern_Method)){
                        yyerror((yyvsp[-3].string));
                        yyerror("needs to be a method, wrong subtype");
                        exit(1);
                }

                // check that the formal params match the params of the method
                // definition

                if (check_parameters(p->fparms, (yyvsp[-1].astnode)) == 0) {
                        yyerror("Formal and actual params do not match");
                        yyerror((yyvsp[-3].string));
                        exit(1);
                }
                
                (yyval.astnode) = ASTCreateNode(A_METHODCALL);
                (yyval.astnode)->name = (yyvsp[-3].string);
                (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                (yyval.astnode)->symbol = p;
                (yyval.astnode)->A_Declared_Type = p->Type; // type matches it's formal type
        }
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 590 "lab9.y" /* yacc.c:1646  */
    {
        (yyval.astnode) = (yyvsp[0].astnode);
     // create a temporary symbol to hold value
        (yyval.astnode)->symbol = Insert(TEMP_CREATE(),(yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);

        // increment offset by 1 because of the temporary value being stored
        offset++;
        }
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 600 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = NULL;
        }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 603 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[0].astnode);
        }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 608 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[0].astnode);
        }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 611 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[-2].astnode);
                (yyval.astnode)->next = (yyvsp[0].astnode);
        }
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 627 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 630 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 631 "lab9.y" /* yacc.c:1646  */
    {

                // make type of left is type of right 
                if (((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type)) {
                        yyerror("both sides need to be the same type");
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_EXPR);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode); // set S1 to left hand side 
                (yyval.astnode)->operator = (yyvsp[-1].operator); // set the operator to return of Relop
                (yyval.astnode)->S2 = (yyvsp[0].astnode); // set S2 to the right hand side
                (yyval.astnode)->A_Declared_Type = (yyvsp[-2].astnode)->A_Declared_Type; // duplicate the type from one of the left or right (left)
                (yyval.astnode)->name = TEMP_CREATE(); // create a temporary symbol to hold value
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name,(yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);

                // increment offset by 1 because of the temporary value being stored
                offset++;
                
        }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 652 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LT; }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 653 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GT; }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 654 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_EQ; }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 655 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LEQ; }
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 656 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_GEQ; }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 657 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_NEQ; }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 660 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 661 "lab9.y" /* yacc.c:1646  */
    {
        if (((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type) ||
	    (check_operators((yyvsp[-1].operator), (yyvsp[-2].astnode)->A_Declared_Type) == 0)) {
		yyerror("addition and subtraction need INTs only");
		exit(1);
	}
                (yyval.astnode) = ASTCreateNode(A_EXPR);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                (yyval.astnode)->operator = (yyvsp[-1].operator);
                (yyval.astnode)->S2 = (yyvsp[0].astnode);
                (yyval.astnode)->A_Declared_Type = A_Decaf_INT;
                (yyval.astnode)->name = TEMP_CREATE();
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name,(yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 678 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_PLUS; }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 679 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_MINUS; }
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 682 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 683 "lab9.y" /* yacc.c:1646  */
    {
                // check that left is equal to right
                if ((yyvsp[-2].astnode)->A_Declared_Type != (yyvsp[0].astnode)->A_Declared_Type) {
                        yyerror("type mismatch");
                        exit(1);
                }

                // use my check_operators() function to make sure the operator
                // is compatible with the types
                if (check_operators((yyvsp[-1].operator), (yyvsp[-2].astnode)->A_Declared_Type) == 0) {
                        if((yyvsp[-2].astnode)->A_Declared_Type == A_Decaf_BOOL) {
                                yyerror("Cannot use BOOL in INT operation");
                        } else {
                                yyerror("Cannot use INT in BOOL operation");
                        }
                        exit(1);
                }

                (yyval.astnode) = ASTCreateNode(A_EXPR);
                (yyval.astnode)->S1 = (yyvsp[-2].astnode);
                (yyval.astnode)->operator = (yyvsp[-1].operator);
                (yyval.astnode)->S2 = (yyvsp[0].astnode);
                (yyval.astnode)->name = TEMP_CREATE();
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name,(yyval.astnode)->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 711 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_TIMES; }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 712 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_DIVIDE; }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 713 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_MOD; }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 714 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_AND; }
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 715 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_OR; }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 716 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LEFTSHIFT; }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 717 "lab9.y" /* yacc.c:1646  */
    { (yyval.operator) = A_RIGHTSHIFT; }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 720 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *p;
                p = Search((yyvsp[0].string), level, 1);

                if(p == NULL) {
                        yyerror("Symbol on RVALUE not defined");
                        yyerror((yyvsp[0].string));
                        exit(1);
                }

                if (p->SubType != ID_Sub_Type_Scalar){
                        yyerror((yyvsp[0].string));
                        yyerror("needs to be an scalar, wrong subtype");
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_VAR_RVALUE);
                (yyval.astnode)->name = (yyvsp[0].string);
                (yyval.astnode)->symbol = p;
                (yyval.astnode)->A_Declared_Type = p->Type;

        }
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 741 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 742 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *p;
                p = Search((yyvsp[-3].string), level, 1);
                if(p == NULL) {
                        yyerror("Symbol on RVALUE not defined");
                        yyerror((yyvsp[-3].string));
                        exit(1);
                }

                if (p->SubType != ID_Sub_Type_Array){
                        yyerror((yyvsp[-3].string));
                        yyerror("needs to be an array, wrong subtype");
                        exit(1);
                }

                (yyval.astnode) = ASTCreateNode(A_VAR_RVALUE);
                (yyval.astnode)->name = (yyvsp[-3].string);
                (yyval.astnode)->S1 = (yyvsp[-1].astnode);
                (yyval.astnode)->symbol = p;
                (yyval.astnode)->A_Declared_Type = p->Type;
        }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 763 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[0].astnode); }
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 764 "lab9.y" /* yacc.c:1646  */
    { (yyval.astnode) = (yyvsp[-1].astnode); }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 765 "lab9.y" /* yacc.c:1646  */
    {

                // check if our right is a bool
                if ((yyvsp[0].astnode)->A_Declared_Type != A_Decaf_BOOL) {
                        yyerror("Type mismatch, expected boolean");
                        exit(1);
                }

                (yyval.astnode) = ASTCreateNode(A_EXPR);
                (yyval.astnode)->operator = A_NOT;
                (yyval.astnode)->S1 = (yyvsp[0].astnode);

                // set type to boolean because !bool is a bool 
                (yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;

                (yyval.astnode)->name = TEMP_CREATE();
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name,A_Decaf_BOOL, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 786 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_CONSTANT_STRING);
                (yyval.astnode)->name = (yyvsp[0].string);
                (yyval.astnode)->A_Declared_Type = A_Decaf_STRING;
        }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 791 "lab9.y" /* yacc.c:1646  */
    {
                // check if our right is an int
                if ((yyvsp[0].astnode)->A_Declared_Type != A_Decaf_INT) {
                        yyerror("Type mismatch, expected integer");
                        exit(1);
                }
                (yyval.astnode) = ASTCreateNode(A_EXPR);
                (yyval.astnode)->operator = A_UMINUS;
                (yyval.astnode)->S1 = (yyvsp[0].astnode);
                // set type to boolean because UMINUS is for numbers 
                (yyval.astnode)->A_Declared_Type = A_Decaf_INT;
                (yyval.astnode)->name = TEMP_CREATE();
                (yyval.astnode)->symbol = Insert((yyval.astnode)->name,A_Decaf_BOOL, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 811 "lab9.y" /* yacc.c:1646  */
    { (yyval.asttype) = A_Decaf_STRING; }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 816 "lab9.y" /* yacc.c:1646  */
    { (yyval.asttype) = A_Decaf_INT; }
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 817 "lab9.y" /* yacc.c:1646  */
    { (yyval.asttype) = A_Decaf_BOOL; }
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 820 "lab9.y" /* yacc.c:1646  */
    { (yyval.asttype) = A_Decaf_VOID; }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 821 "lab9.y" /* yacc.c:1646  */
    { (yyval.asttype) = (yyvsp[0].asttype); }
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 824 "lab9.y" /* yacc.c:1646  */
    {
        (yyval.astnode) = ASTCreateNode(A_CONSTANT_BOOL);
        (yyval.astnode)->value = 1;
        (yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
        }
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 829 "lab9.y" /* yacc.c:1646  */
    {
        (yyval.astnode) = ASTCreateNode(A_CONSTANT_BOOL);
        (yyval.astnode)->value = 0;
        (yyval.astnode)->A_Declared_Type = A_Decaf_BOOL;
        }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 836 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_ARRAYTYPE);
                (yyval.astnode)->value = (yyvsp[-2].value);
                (yyval.astnode)->A_Declared_Type = (yyvsp[0].asttype);
                (yyval.astnode)->size = (yyvsp[-2].value);
                // printf("THE SIZE IS %d %d", $2, $$->size);// debug 
        }
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 845 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = ASTCreateNode(A_CONSTANT_INT);
                (yyval.astnode)->value = (yyvsp[0].value);
                (yyval.astnode)->A_Declared_Type = A_Decaf_INT;
        }
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 851 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.astnode) = (yyvsp[0].astnode);
        }
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2509 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 854 "lab9.y" /* yacc.c:1906  */
    /* end of rules, start of program */

int main(int argc, char ** argv){

        for (int i = 1; i<argc; i++) {
                /* printf("argv: %d is %s\n", i, argv[i]); */

                // set debug flag
                if (strcmp(argv[i], "-d") == 0) {
                        mydebug = 1;
                }

                // check next argument for open file argument 
                if (strcmp(argv[i], "-o") == 0) {
                        char filename[100]; // new file name stored
                        strcat(filename, argv[i+1]);
                        strcat(filename, ".asm");
                        /* printf("file name is %s\n", filename); */
                        fp = fopen(filename, "w"); 
                        if (fp == NULL) {
                                printf("unable to open %s \n", filename);
                                exit(1);
                        }
                }

        }
        /* printf("argc: %d \n", argc); */
        /* exit(1); */
        yyparse();
        printf("Parsing completed\n");
        if(mydebug){
                Display(); // I noticed in cooper's output he Displays after the printf
                // We know PROGRAM points to our AST
                ASTprint(0, PROGRAM);
                printf("Finished printing AST ");
        }
        emit_all(PROGRAM);
}
