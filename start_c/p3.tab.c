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
#line 1 "p3_c.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct symbol_table {
    char id_name[30];
    char function_name[30];
    char datatype_name[30];
    int int_value;
    int bool_value;
    char string_value[30];
} Symbol_table;


//Helper function to copy dat at every level
void compareTermandExp();
extern int yylineno;
int yyerror();
int yylex();
int yyerror_semantic();
const char* pass_msg = "Input Passed Checking\n";
const char* syn_err_msg = "syntax error at line %d\n";
void printing_symbol_table();
void printing_symbol_table_global();
void lookForID(char *word);
void addFunInglobe(char *word);
void addIDasINT(char *word);
void compAsst();
void copyIntoFactorfromString(char *word);
void copyExpressionfromExp();
void copyTermfromFactor();
void copyExpfromTerm();
void copyIntoFactorfromInt(int j);
void copyIntoFactorfromIdentifier(char *word, char *datatype);
void copyIntoFactorfromFalse();
void copyIntoFactorfromTrue();
void checkExpforReturn();
void checkIDreturn(char *word);
void checkID(char *word);
void checkIfPrintisRight();
void checkForterm();
void clearFun();
void checkIfFunexists(char *word);
void clearOutFactor();
void lookForIDorAdd(char *word);
void checkForFactor();
void checkForFactorhere();
void addInSymbolTableInput();

//Two scopes, one is global and the other is the function scope
Symbol_table* function_sts;
Symbol_table* global_sts;

int in_fun = 0;

int sem_err_check = 0;

extern int line_no;
extern int while_active;

//These are the symbol tables at all the levels
Symbol_table factor_temp;
Symbol_table term_temp;
Symbol_table expression_temp;
Symbol_table exp_temp;
Symbol_table assignment_temp;
Symbol_table callst_temp;



#line 139 "p3.tab.c" /* yacc.c:339  */

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
   by #include "p3.tab.h".  */
#ifndef YY_YY_P3_TAB_H_INCLUDED
# define YY_YY_P3_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    EQUALITY = 259,
    LESSTHEO = 260,
    GREATERTHEO = 261,
    NOTEQUAL = 262,
    COLON = 263,
    DEF = 264,
    ENDDEF = 265,
    IF = 266,
    ENDDIF = 267,
    ELSE = 268,
    WHILE = 269,
    ENDWHILE = 270,
    PRINT = 271,
    INPUT = 272,
    TRUE = 273,
    FALSE = 274,
    RETURN = 275,
    NUMBER = 276,
    IDENTIFIER = 277,
    STRING = 278,
    NI = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 81 "p3_c.y" /* yacc.c:355  */

    char *a;
    int fn;
    double d;

#line 210 "p3.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P3_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "p3.tab.c" /* yacc.c:358  */

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
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,    33,    31,    27,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    28,    30,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    92,    92,    94,    95,    97,    98,   100,   101,   103,
     105,   106,   108,   109,   110,   111,   112,   113,   114,   116,
     118,   120,   121,   123,   124,   125,   126,   127,   128,   129,
     131,   132,   133,   135,   136,   137,   139,   140,   141,   142,
     143,   144,   145,   146,   148,   150,   152,   153,   155,   156,
     158,   160,   162,   163,   165,   166,   168,   169,   171,   172,
     173
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "EQUALITY", "LESSTHEO",
  "GREATERTHEO", "NOTEQUAL", "COLON", "DEF", "ENDDEF", "IF", "ENDDIF",
  "ELSE", "WHILE", "ENDWHILE", "PRINT", "INPUT", "TRUE", "FALSE", "RETURN",
  "NUMBER", "IDENTIFIER", "STRING", "NI", "'('", "')'", "','", "'='",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "$accept", "PROGRAM",
  "FUNCTION_LIST", "FUNCTION", "PARAMATERS", "IDHERE", "STATEMENTS",
  "STATEMENT", "ASSIGNMENT_STMT", "RETURN_STMT", "EXPRESSION", "REL_EXP",
  "EXP", "TERM", "FACTOR", "PRINT_STMT", "INPUT_STMT", "CALL_STMT",
  "CONDITION_STMT", "IF_HEAD", "WHILE_STMT", "EXPRESSION_LIST",
  "EXPR_LIST", "END_LIST", "END", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,    44,    61,    60,
      62,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -17,    39,    87,   -62,    23,   -62,    25,   -21,   -62,
     -62,   -62,   -62,   -13,   -62,    -2,    -4,    46,    53,   -62,
     -62,    65,     5,   -62,   -62,   -62,   -62,    50,   -62,    -4,
      93,   -62,   -62,    56,   101,   -62,   -62,    79,    93,   -62,
     115,   144,    54,   153,    76,    70,    75,    51,   -62,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,   -62,
      -4,    91,   -62,    93,   103,    -4,    -4,    93,    18,   110,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   153,   -62,   153,
     -62,   -62,   -62,   115,   115,   115,   115,   115,   115,   101,
     101,   -62,   -62,   -62,   115,   -62,    90,   105,   115,    72,
     -62,   -62,   129,   117,   -62,   153,   -62,   -62,   111,   -62,
     139,   153,   -62,   146,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     4,     0,     1,     0,     0,     3,
      59,    60,    58,     2,    57,     0,     0,     0,     0,    56,
       9,     0,     0,     8,    40,    41,    37,    39,    38,     0,
       0,    53,    21,    22,    32,    35,    43,     0,     0,    46,
      55,     0,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    18,    13,    14,    17,    15,     0,    16,     0,
       7,    29,    36,    23,    26,    28,    24,    25,    27,    30,
      31,    33,    34,    52,    54,    45,     0,     0,    20,     0,
       6,    10,     0,     0,    50,     0,    19,    48,     0,     5,
       0,     0,    51,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   133,   -62,    99,   -52,   -61,   -62,   -62,
     -54,   109,   -16,   121,   -28,    13,    41,    -3,   -62,   -62,
     -62,   -62,   -62,   -62,   135
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    22,    23,    69,    70,    71,    72,
      31,    32,    33,    34,    35,    73,    74,    36,    76,    77,
      78,    37,    41,    13,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      12,    40,    48,     7,    17,     5,    93,    18,   101,     8,
      12,    96,    97,    47,    24,    25,    10,    26,    27,    28,
      20,    29,    61,     1,    21,   102,    10,   103,    30,    91,
      92,    44,    45,    83,    84,    85,    86,    87,    88,     6,
      75,   101,   101,    17,    11,   106,    99,    94,    15,   101,
      16,    98,   101,   110,    11,    49,    50,    51,    52,   113,
      49,    50,    51,    52,    24,    25,    75,    26,    27,    28,
      42,    38,    39,    43,    75,    17,    75,    82,    30,    64,
      53,    54,    55,    56,    79,    53,    54,    55,    56,    42,
      24,    25,    20,    26,    27,    28,     1,    29,   104,    75,
      75,    81,    75,     7,    30,    59,    60,    75,    75,     8,
      75,    24,    25,   105,    26,    27,    28,    82,    38,   111,
     100,    65,    55,    56,    66,    30,     7,   109,    65,    95,
      67,    66,    68,     7,    57,    58,     9,    67,    46,    68,
      65,   107,   108,    66,    80,     7,    55,    56,    19,    67,
      65,    68,     0,    66,   112,     7,     0,    65,   114,    67,
      66,    68,     7,     0,    65,     0,    67,    66,    68,     7,
      62,    63,     0,    67,     0,    68,    89,    90
};

static const yytype_int8 yycheck[] =
{
       3,    17,    30,    16,    25,    22,    60,    28,    69,    22,
      13,    65,    66,    29,    18,    19,     3,    21,    22,    23,
      22,    25,    38,     9,    26,    77,    13,    79,    32,    57,
      58,    26,    27,    49,    50,    51,    52,    53,    54,     0,
      43,   102,   103,    25,     3,    99,    28,    63,    25,   110,
      25,    67,   113,   105,    13,     4,     5,     6,     7,   111,
       4,     5,     6,     7,    18,    19,    69,    21,    22,    23,
      17,    25,    26,     8,    77,    25,    79,    26,    32,    25,
      29,    30,    31,    32,     8,    29,    30,    31,    32,    17,
      18,    19,    22,    21,    22,    23,     9,    25,     8,   102,
     103,    26,   105,    16,    32,    26,    27,   110,   111,    22,
     113,    18,    19,     8,    21,    22,    23,    26,    25,     8,
      10,    11,    31,    32,    14,    32,    16,    10,    11,    26,
      20,    14,    22,    16,    33,    34,     3,    20,    29,    22,
      11,    12,    13,    14,    45,    16,    31,    32,    13,    20,
      11,    22,    -1,    14,    15,    16,    -1,    11,    12,    20,
      14,    22,    16,    -1,    11,    -1,    20,    14,    22,    16,
      26,    27,    -1,    20,    -1,    22,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    36,    37,    38,    22,     0,    16,    22,    38,
      50,    51,    52,    58,    59,    25,    25,    25,    28,    59,
      22,    26,    39,    40,    18,    19,    21,    22,    23,    25,
      32,    45,    46,    47,    48,    49,    52,    56,    25,    26,
      47,    57,    17,     8,    26,    27,    46,    47,    49,     4,
       5,     6,     7,    29,    30,    31,    32,    33,    34,    26,
      27,    47,    26,    27,    25,    11,    14,    20,    22,    41,
      42,    43,    44,    50,    51,    52,    53,    54,    55,     8,
      40,    26,    26,    47,    47,    47,    47,    47,    47,    48,
      48,    49,    49,    45,    47,    26,    45,    45,    47,    28,
      10,    42,    41,    41,     8,     8,    45,    12,    13,    10,
      41,     8,    15,    41,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    41,    42,    42,    42,    42,    42,    42,    42,    43,
      44,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     8,     7,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     4,     5,     3,     4,     3,     6,
       3,     5,     3,     1,     3,     1,     2,     1,     1,     1,
       1
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
#line 92 "p3_c.y" /* yacc.c:1646  */
    {}
#line 1394 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "p3_c.y" /* yacc.c:1646  */
    {checkIfFunexists((yyvsp[-6].a)); clearFun(); }
#line 1400 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "p3_c.y" /* yacc.c:1646  */
    {checkIfFunexists((yyvsp[-5].a)); clearFun(); }
#line 1406 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "p3_c.y" /* yacc.c:1646  */
    {in_fun = 1;}
#line 1412 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "p3_c.y" /* yacc.c:1646  */
    {in_fun = 1;}
#line 1418 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "p3_c.y" /* yacc.c:1646  */
    {addIDasINT((yyvsp[0].a));}
#line 1424 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "p3_c.y" /* yacc.c:1646  */
    {}
#line 1430 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "p3_c.y" /* yacc.c:1646  */
    {}
#line 1436 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 116 "p3_c.y" /* yacc.c:1646  */
    {lookForIDorAdd((yyvsp[-2].a));}
#line 1442 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "p3_c.y" /* yacc.c:1646  */
    {checkExpforReturn();}
#line 1448 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 121 "p3_c.y" /* yacc.c:1646  */
    {copyExpressionfromExp();}
#line 1454 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 123 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1460 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1466 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1472 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 126 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1478 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1484 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 128 "p3_c.y" /* yacc.c:1646  */
    {compareTermandExp();}
#line 1490 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 131 "p3_c.y" /* yacc.c:1646  */
    {checkForterm();}
#line 1496 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 132 "p3_c.y" /* yacc.c:1646  */
    {checkForterm();}
#line 1502 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 133 "p3_c.y" /* yacc.c:1646  */
    {copyExpfromTerm();}
#line 1508 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 135 "p3_c.y" /* yacc.c:1646  */
    {checkForFactor();}
#line 1514 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 136 "p3_c.y" /* yacc.c:1646  */
    {checkForFactor();}
#line 1520 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 137 "p3_c.y" /* yacc.c:1646  */
    {copyTermfromFactor();}
#line 1526 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 139 "p3_c.y" /* yacc.c:1646  */
    {}
#line 1532 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 140 "p3_c.y" /* yacc.c:1646  */
    {copyIntoFactorfromInt((yyvsp[0].fn)); }
#line 1538 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "p3_c.y" /* yacc.c:1646  */
    {copyIntoFactorfromString((yyvsp[0].a));}
#line 1544 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 142 "p3_c.y" /* yacc.c:1646  */
    {checkID((yyvsp[0].a));}
#line 1550 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "p3_c.y" /* yacc.c:1646  */
    {copyIntoFactorfromTrue();}
#line 1556 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "p3_c.y" /* yacc.c:1646  */
    {copyIntoFactorfromFalse();}
#line 1562 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 146 "p3_c.y" /* yacc.c:1646  */
    {clearOutFactor();}
#line 1568 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 148 "p3_c.y" /* yacc.c:1646  */
    {checkIfPrintisRight();}
#line 1574 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 150 "p3_c.y" /* yacc.c:1646  */
    {addInSymbolTableInput((yyvsp[-4].a));}
#line 1580 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 152 "p3_c.y" /* yacc.c:1646  */
    {checkIDreturn((yyvsp[-2].a)); strcpy(callst_temp.datatype_name, "int");}
#line 1586 "p3.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 153 "p3_c.y" /* yacc.c:1646  */
    {checkIDreturn((yyvsp[-3].a)); strcpy(callst_temp.datatype_name, "int");}
#line 1592 "p3.tab.c" /* yacc.c:1646  */
    break;


#line 1596 "p3.tab.c" /* yacc.c:1646  */
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
#line 176 "p3_c.y" /* yacc.c:1906  */





int main(){

    //Code for debugging
    #if YYDEBUG == 1
    extern int yydebug;
    yydebug = 1;
    #endif

    global_sts = malloc(20 * sizeof * global_sts);
    function_sts = malloc(20 * sizeof * function_sts);


    for (int x = 0; x < 20; x++){
        strcpy(global_sts[x].datatype_name, "");
        strcpy(function_sts[x].datatype_name, "");
        strcpy(global_sts[x].function_name, "");
        strcpy(function_sts[x].function_name, "");
        strcpy(global_sts[x].string_value, "");
        strcpy(function_sts[x].string_value, "");
        strcpy(global_sts[x].id_name, "");
        strcpy(function_sts[x].id_name, "");
        global_sts[x].int_value = 0;
        function_sts[x].int_value = 0;
        global_sts[x].bool_value = 0;
        function_sts[x].bool_value = 0;
    }

    yyparse();

    if(sem_err_check == 0) {
        fprintf(stdout, "Input Passed Checking\n");
    }

    return 0;
}

void addInSymbolTableInput(char *word) {
    if(in_fun == 1){
        //Add in local scope
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, "") == 0) {
                //spot found
                strcpy(function_sts[i].id_name, word);
                strcpy(function_sts[i].datatype_name, "int");
                return;
            }
        }
    }
    else {
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, "") == 0) {
                //spot found
                strcpy(global_sts[i].id_name, word);
                strcpy(global_sts[i].datatype_name, "int");
                return;
            }
        }
    }
}

void compareTermandExp() {
    //check the datatype of exp and term
    if(strcmp(term_temp.datatype_name, "int") == 0 && strcmp(exp_temp.datatype_name, "int") == 0) {
        return;
    }
    else {
        fprintf(stderr, "Relational expression needs int datatype to proceed, error at line %d\n", line_no);
    }
}

void checkExpforReturn() {

    //printf("%s\n", exp_temp.datatype_name);

    if(strcmp(callst_temp.datatype_name, "int") == 0) {
        strcpy(callst_temp.datatype_name, "");
        return;
    }
    if(strcmp(exp_temp.datatype_name, "int") != 0) {
        fprintf(stderr, "Return value is not int: at line %d\n", line_no);
        sem_err_check = 1;
        return;
    }
}

void lookForIDorAdd(char *word) {
    //printf("Datatype of expression : %s\n", expression_temp.id_name);
    //First look for thed identifdier if it exists in the fun or global
    if(in_fun == 1) {
        //Looking in function
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, word) == 0) {
                //Id exists in the function, now check its datatype with the expression data type
                if(strcmp(function_sts[i].datatype_name, expression_temp.datatype_name) != 0 && strcmp(expression_temp.datatype_name, "nothing") != 0) {
                    //If the datatype name doesnt match then throw an error
                    fprintf(stderr, "cannot assign %s value to %s of datatype %s at line %d\n", expression_temp.datatype_name, word, function_sts[i].datatype_name, line_no);
                    sem_err_check = 1;
                    return;
                }
                else {
                    return;
                }
            }
        }
    }
    //checking in global
    for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, word) == 0) {
                //Id exists in the function, now check its datatype with the expressfion data type
                if(strcmp(global_sts[i].datatype_name, expression_temp.datatype_name) != 0 && strcmp(expression_temp.datatype_name, "nothing") != 0) {
                    //If the datatype name doesnt match then throw an error
                    fprintf(stderr, "cannot assign %s value to %s of datatype %s at line %d\n", expression_temp.datatype_name, word, global_sts[i].datatype_name, line_no);
                    sem_err_check = 1;
                    return;
                }
                else {
                    return;
                }
            }
        }

        //If they dondt exist in the symbol table then adding it into symbol table
        if(in_fun == 1) {
            //adding in function
            for(int i = 0; i < 20; i++) {
                //checking for the first empty slot in function
                if(strcmp(function_sts[i].datatype_name, "") == 0) {
                    strcpy(function_sts[i].id_name, word);
                    strcpy(function_sts[i].datatype_name, expression_temp.datatype_name);
                    return;
                }
            }
        }
        else {
            for(int i = 0; i < 20; i++) {
                //checking for the first ecmpty slot in function
                if(strcmp(global_sts[i].datatype_name, "") == 0) {
                    strcpy(global_sts[i].id_name, word);
                    strcpy(global_sts[i].datatype_name, expression_temp.datatype_name);
                    return;
                }
            }
        }
}

void clearOutFactor() {
        strcpy(factor_temp.datatype_name, "");
        strcpy(factor_temp.function_name, "");
        strcpy(factor_temp.string_value, "");
        strcpy(factor_temp.id_name, "");
        factor_temp.int_value = 0;
        factor_temp.bool_value = 0;
}

void clearFun() {
    for (int x = 0; x < 20; x++){
        strcpy(function_sts[x].datatype_name, "");
        strcpy(function_sts[x].function_name, "");
        strcpy(function_sts[x].string_value, "");
        strcpy(function_sts[x].id_name, "");
        function_sts[x].int_value = 0;
        function_sts[x].bool_value = 0;
    }
    in_fun = 0;
}

void checkIfFunexists(char *word) {
    //Only look in global variable
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].id_name, word) == 0) {
            fprintf(stderr, "function %s already declared before : error at line %d\n", word, line_no);
            sem_err_check = 1;
            return;
        }
    }
    addFunInglobe(word);
}

void checkForExphere() {
        //Checking whdether exp exists or not

    if(strcmp(exp_temp.id_name, "") != 0) {
    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, exp_temp.id_name) == 0) {
                
                //If founfd then ffcheck ffor ddatatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, exp_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }

    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", exp_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        if(strcmp(exp_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }
    
}

void checkForFactorhere() {
        //Checking whether exp exists or not
    if(strcmp(factor_temp.id_name, "") != 0) {
    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                
                //If founfd then ffcheck ffor ddatatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }

    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", exp_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        if(strcmp(factor_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }
    
}

void checkForterm() {

    //  printf("EXP : %s is of datatype %s\n", exp_temp.id_name, exp_temp.datatype_name);
    //  printf("TERM : %s is of datatype %s\n", term_temp.id_name, term_temp.datatype_name);
    //Checking for int dvatatype

    if(strcmp(term_temp.id_name, "") != 0) {

    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                }
                return;
            }
        }
    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", term_temp.id_name, line_no);
    sem_err_check = 1;
    }
    else {
        //If no id name then check the datatype
        if(strcmp(term_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
        }
    }

    checkForExphere();

}

void checkForFactor() {

    

    //  printf("EXP : %s is of datatype %s\n", exp_temp.id_name, exp_temp.datatype_name);
    //printf("TERM : f%s is of datatype %ds\n", term_temp.id_name, term_temp.datatype_name);
    //Checking for int dvatatype

    if(strcmp(term_temp.id_name, "") != 0) {

    if(in_fun == 1) {
        for (int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    checkForFactorhere();
                    return;
                }
                checkForFactorhere();
                return;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, term_temp.id_name) == 0) {
                //If found then check for datatype
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    //Throw error
                    fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    return;
                    checkForFactorhere();
                }
                checkForFactorhere();
                return;
            }
        }
    fprintf(stderr, "Variable %s is undeclared before use in this expression : line %d\n", term_temp.id_name, line_no);
    sem_err_check = 1;
    checkForFactorhere();
    }
    else {
        //If no id name then check the datatype
        if(strcmp(term_temp.datatype_name, "int") != 0) {
            fprintf(stderr, "variable is not of type int to perform this operation at line %d\n", line_no);
                    sem_err_check = 1;
                    checkForFactorhere();
                    return;
        }
    }

    

}

void checkID(char *word) {

    if(while_active == 1) {
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(function_sts[i].datatype_name, "bool") != 0) {
                    fprintf(stderr, "while variable doesnt have boolean datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
                
                }
            }
        }
    
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(global_sts[i].datatype_name, "bool") != 0) {
                    fprintf(stderr, "while variable doesnt have boolean datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
            }
        }

    }

    if(in_fun == 1) {
        for(int i = 0; i< 20; i++) {
            if(strcmp(function_sts[i].id_name, word) == 0) {
                copyIntoFactorfromIdentifier(word, function_sts[i].datatype_name);
                return;
            }
        }
    }
    //checking in global
        for(int i = 0; i< 20; i++) {
            if(strcmp(global_sts[i].id_name, word) == 0) {
                copyIntoFactorfromIdentifier(word, global_sts[i].datatype_name);
                return;
            }
        }

        //If not found then throwin an error
        fprintf(stderr, "Identifier %s undeclared before use\n", word);
        strcpy(factor_temp.datatype_name,"nothing");
        strcpy(factor_temp.id_name,word);
        sem_err_check = 1;

    

    if(while_active == 3) {
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(function_sts[i].datatype_name, "int") != 0) {
                    fprintf(stderr, "while variable doesnt have int datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
                
                }
            }
        }
    
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, factor_temp.id_name) == 0) {
                if(strcmp(global_sts[i].datatype_name, "int") != 0) {
                    fprintf(stderr, "while variable doesnt have int datatype : at line %d\n", line_no);
                    sem_err_check = 1;
                    while_active = 0;
                    return;
                }
            }
        }

    }

}

void checkIDreturn(char *word) {
    //Searching for the function in global
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].id_name, word) == 0) {
            return;
        }
    }
    fprintf(stderr, "This identifier/function doesn't exist: at line %d\n", line_no);
    sem_err_check = 1;
    return;
}

void addIDasINT(char *word) {
    for(int i = 0; i < 20; i++) {
        if(strcmp(function_sts[i].datatype_name, "") == 0) {
            strcpy(function_sts[i].datatype_name, "int");
            strcpy(function_sts[i].id_name, word);
            // printf("%s\n", function_sts[i].datatype_name);
            // printf("%s\n", function_sts[i].id_name);
            return;
        }
    }
    return;
}

void checkIfPrintisRight() {
    if(strcmp(expression_temp.datatype_name, "string") == 0) {
        return;
    }
    if(in_fun == 1) {
        //Inside the function then
        for(int i = 0; i < 20; i++) {
            if(strcmp(function_sts[i].id_name, expression_temp.id_name) == 0) {
                return;
                }
            }
        }
        for(int i = 0; i < 20; i++) {
            if(strcmp(global_sts[i].id_name, expression_temp.id_name) == 0) {
                return;
            }
        }

        fprintf(stderr, "print statement is printing out the variable that doesnt exist : at line %d\n", line_no);
        sem_err_check = 1;
}

void addFunInglobe(char *word) {
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].datatype_name, "") == 0) {
            strcpy(global_sts[i].datatype_name, "function");
            strcpy(global_sts[i].id_name, word);
            // printf("%s\n", function_sts[i].datatype_name);
            // printf("%s\n", fundction_sts[i].id_name);
            return;
        }
    }
    return;
}

void printing_symbol_table_global() {
printf("Symbol table starts here : ...................GLOBAL......................\n");
int k = 1;
    for(int i = 0; i < 20; i++) {
        if(strcmp(global_sts[i].datatype_name, "") != 0) {
            printf("Record : %d\n", k);
            printf("Datatype: %s\n", global_sts[i].datatype_name);
            printf("ID: %s\n", global_sts[i].id_name);
            printf("int_value: %d\n", global_sts[i].int_value);
            k++;
        }
    }
}

void copyIntoFactorfromString(char *word) {
    strcpy(factor_temp.string_value, word);
    strcpy(factor_temp.datatype_name, "string");
    return;
}

void copyIntoFactorfromTrue() {
    strcpy(factor_temp.datatype_name, "bool");
    factor_temp.bool_value = 1;
}

void copyIntoFactorfromFalse() {
    strcpy(factor_temp.datatype_name, "bool");
    factor_temp.bool_value = 0;
}

void copyIntoFactorfromInt(int j) {
    strcpy(factor_temp.datatype_name, "int");
    factor_temp.int_value = j;
    return;
}

void copyIntoFactorfromIdentifier(char *word, char *datatype) {
    strcpy(factor_temp.id_name, word);
    strcpy(factor_temp.datatype_name, datatype);
    return;
}

void copyTermfromFactor() {

    //printf("Copying term from factor : %s\n", factor_temp.datatype_name);

    strcpy(term_temp.string_value, factor_temp.string_value);
    strcpy(term_temp.datatype_name, factor_temp.datatype_name);
    strcpy(term_temp.id_name, factor_temp.id_name);
    term_temp.int_value = factor_temp.int_value;
    term_temp.bool_value = factor_temp.bool_value;
    
    //clearing factor
    strcpy(factor_temp.datatype_name, "");
    strcpy(factor_temp.function_name, "");
    strcpy(factor_temp.string_value, "");
    strcpy(factor_temp.id_name, "");
    factor_temp.int_value = 0;
    factor_temp.bool_value = 0;

}

void addIDinExpression(char *word) {
    strcpy(assignment_temp.datatype_name, expression_temp.datatype_name);
    strcpy(assignment_temp.string_value, expression_temp.string_value);
    assignment_temp.int_value = expression_temp.int_value;
    assignment_temp.bool_value = expression_temp.bool_value;
    strcpy(assignment_temp.id_name, word);
}

void copyExpfromTerm() {
    strcpy(exp_temp.string_value, term_temp.string_value);
    strcpy(exp_temp.datatype_name, term_temp.datatype_name);
    strcpy(exp_temp.id_name, term_temp.id_name);
    exp_temp.int_value = term_temp.int_value;
    exp_temp.bool_value = term_temp.bool_value;

    //clearing term
    // strcpy(term_temp.datatype_name, "");
    // strcpy(term_temp.function_name, "");
    // strcpy(term_temp.string_value, "");
    // strcpy(term_temp.id_name, "");
    // term_temp.int_value = 0;
    // term_temp.bool_value = 0;
}

void copyExpressionfromExp() {
    strcpy(expression_temp.string_value, exp_temp.string_value);
    strcpy(expression_temp.datatype_name, exp_temp.datatype_name);
    strcpy(expression_temp.id_name, exp_temp.id_name);
    expression_temp.int_value = exp_temp.int_value;
    expression_temp.bool_value = exp_temp.bool_value;

    //clearing exp
    strcpy(exp_temp.datatype_name, "");
    strcpy(exp_temp.function_name, "");
    strcpy(exp_temp.string_value, "");
    strcpy(exp_temp.id_name, "");
    exp_temp.int_value = 0;
    exp_temp.bool_value = 0;
}

void compAsst() {
    for(int i = 0; i < 20; i++) {
        //Checking in the function first
        if(strcmp(function_sts[i].id_name, assignment_temp.id_name) == 0) {
            //If it is present in the global, look for its datatype
            if(strcmp(function_sts[i].datatype_name, assignment_temp.datatype_name) == 0) {
                //if it matched then update the value
                strcpy(function_sts[i].string_value, assignment_temp.string_value);
                function_sts[i].int_value = assignment_temp.int_value;
                function_sts[i].bool_value = assignment_temp.bool_value;
                return;
            }
            else {
                fprintf(stderr, "Variable assigned with different value at line %d\n", line_no);
                sem_err_check = 1;
                return;
            }
        }
    }
    for(int i = 0; i < 20; i++) {
        //Checking in the global first
        if(strcmp(global_sts[i].id_name, assignment_temp.id_name) == 0) {
            //If it is present in the global, look for its datatype
            if(strcmp(global_sts[i].datatype_name, assignment_temp.datatype_name) == 0) {
                //if it matched then update the value
                strcpy(global_sts[i].string_value, assignment_temp.string_value);
                global_sts[i].int_value = assignment_temp.int_value;
                global_sts[i].bool_value = assignment_temp.bool_value;
                return;
            }
            else {
                fprintf(stderr, "Variable assigned with different value at line %d\n", line_no);
                sem_err_check = 1;
                return;
            }
        }
    }
    //Now adding the variable to the symbol_table
    if(in_fun == 1) {
        //Adding in function
        for(int j = 0; j < 20; j++) {
            if(strcmp(function_sts[j].datatype_name,"") == 0) {
                //Adding in function
                strcpy(function_sts[j].id_name, assignment_temp.id_name);
                strcpy(function_sts[j].datatype_name, assignment_temp.datatype_name);
                strcpy(function_sts[j].string_value, assignment_temp.string_value);
                function_sts[j].int_value = assignment_temp.int_value;
                function_sts[j].bool_value = assignment_temp.bool_value;
                return;
            }
        }
    }
    else {
        for(int j = 0; j < 20; j++) {
            if(strcmp(global_sts[j].datatype_name,"") == 0) {
                //Adding in function
                strcpy(global_sts[j].id_name, assignment_temp.id_name);
                strcpy(global_sts[j].datatype_name, assignment_temp.datatype_name);
                strcpy(global_sts[j].string_value, assignment_temp.string_value);
                global_sts[j].int_value = assignment_temp.int_value;
                global_sts[j].bool_value = assignment_temp.bool_value;
                return;
            }
        }
    }
}



void printing_symbol_table() {
    printf("Symbol table starts here : .................FUNCTION........................\n");
    int k = 1;
    for(int i = 0; i < 20; i++) {
        if(strcmp(function_sts[i].datatype_name, "") != 0) {
            printf("Record : %d\n", k);
            printf("Datatype: %s\n", function_sts[i].datatype_name);
            printf("ID: %s\n", function_sts[i].id_name);
            printf("int_value: %d\n", function_sts[i].int_value);
            k++;
        }
    }
}

int yyerror(){
   fprintf(stderr, syn_err_msg, line_no);
   exit(-1);
}
