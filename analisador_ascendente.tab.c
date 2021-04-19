/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analisador_ascendente.y"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "stack.c"

#include "lex.yy.c"

#define CAP 100

#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")

int yylex(void);
void yyerror(char *);
#define YYDEBUG 1

typedef struct List{
    char * line;
    struct List * next;
}List;

List * init;

List * curr;

int aux;

void addTokenToList(char * tok , List * curr_list);
void addTokenToListAux(char * tok );
void print();
void createFile();

struct StackNode* root = NULL;


#line 113 "analisador_ascendente.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ANALISADOR_ASCENDENTE_TAB_H_INCLUDED
# define YY_YY_ANALISADOR_ASCENDENTE_TAB_H_INCLUDED
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
    INT = 258,
    FLO = 259,
    CHA = 260,
    BOO = 261,
    STR = 262,
    IF = 263,
    ELS = 264,
    FOR = 265,
    DO = 266,
    WHI = 267,
    RET = 268,
    STU = 269,
    FUN = 270,
    PRI = 271,
    REA = 272,
    LOA = 273,
    ZER = 274,
    IDE = 275,
    INV = 276,
    TRA = 277,
    EQU = 278,
    ID = 279,
    DIO = 280,
    LEQ = 281,
    LEO = 282,
    GEQ = 283,
    GRE = 284,
    APL = 285,
    AMI = 286,
    ADI = 287,
    AMU = 288,
    UAD = 289,
    USU = 290,
    OR = 291,
    VAR = 292
  };
#endif
/* Tokens.  */
#define INT 258
#define FLO 259
#define CHA 260
#define BOO 261
#define STR 262
#define IF 263
#define ELS 264
#define FOR 265
#define DO 266
#define WHI 267
#define RET 268
#define STU 269
#define FUN 270
#define PRI 271
#define REA 272
#define LOA 273
#define ZER 274
#define IDE 275
#define INV 276
#define TRA 277
#define EQU 278
#define ID 279
#define DIO 280
#define LEQ 281
#define LEO 282
#define GEQ 283
#define GRE 284
#define APL 285
#define AMI 286
#define ADI 287
#define AMU 288
#define UAD 289
#define USU 290
#define OR 291
#define VAR 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "analisador_ascendente.y"
 
    char val[1024];

#line 243 "analisador_ascendente.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALISADOR_ASCENDENTE_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    43,    40,     2,
      51,    52,    41,    38,    53,    39,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    60,    62,    63,    66,    67,    68,    71,
      71,    71,    71,    74,    74,    75,    78,    78,    78,    81,
      81,    81,    82,    85,    85,    85,    85,    85,    88,    89,
      92,    93,    93,    93,    96,    96,    99,   100,   103,   104,
     105,   106,   107,   108,   109,   112,   113,   116,   116,   117,
     117,   118,   121,   121,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   135,   138,   138,   140,   141,   141,   144,
     145,   148,   148,   151,   177,   196,   197,   201,   207,   200,
     220,   224,   223,   233,   232,   242,   253,   258,   261,   252,
     277,   290,   290,   290,   293,   294,   297,   298,   298,   300,
     300,   300,   302,   311,   312,   313,   314,   315,   315,   316,
     316,   317,   317,   318,   318,   319,   319,   320,   320,   321,
     321,   322,   322,   323,   323,   324,   324,   325,   326,   327,
     328,   329,   329,   330,   330,   331,   331,   332,   332,   333,
     333,   334,   334,   335,   335,   336,   336,   337,   337,   337,
     338,   338,   338,   339,   339,   339,   340,   340,   340,   341,
     341,   341
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLO", "CHA", "BOO", "STR", "IF",
  "ELS", "FOR", "DO", "WHI", "RET", "STU", "FUN", "PRI", "REA", "LOA",
  "ZER", "IDE", "INV", "TRA", "EQU", "ID", "DIO", "LEQ", "LEO", "GEQ",
  "GRE", "APL", "AMI", "ADI", "AMU", "UAD", "USU", "OR", "VAR", "'+'",
  "'-'", "'&'", "'*'", "'/'", "'%'", "'!'", "'^'", "';'", "'{'", "'}'",
  "'['", "']'", "'('", "')'", "','", "'='", "$accept", "First", "$@1",
  "Program", "Definition", "Struct", "$@2", "$@3", "$@4", "Instantiations",
  "$@5", "Instantiation", "$@6", "$@7", "Matrix", "$@8", "$@9", "Function",
  "$@10", "$@11", "$@12", "$@13", "Function1", "Function_argument", "$@14",
  "$@15", "Block", "$@16", "Statements", "Statement", "Assign",
  "OptAssign", "$@17", "$@18", "Assignment", "$@19", "Assignment1", "$@20",
  "$@21", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "Matrix_line", "$@29", "Elements", "$@30", "Element", "Return_expr",
  "$@31", "For_block", "Block_FOR_Aux", "For_block1", "If_block", "$@32",
  "$@33", "Block_If_Aux", "Else_Block", "$@34", "$@35", "While_block",
  "$@36", "$@37", "$@38", "Block_While_aux", "Function_call", "$@39",
  "$@40", "Function_call1", "Arguments", "$@41", "Print", "$@42", "$@43",
  "Read", "Expression", "$@44", "$@45", "$@46", "$@47", "$@48", "$@49",
  "$@50", "$@51", "$@52", "$@53", "$@54", "$@55", "$@56", "$@57", "$@58",
  "$@59", "$@60", "$@61", "$@62", "$@63", "$@64", "$@65", "$@66", "$@67",
  "$@68", "$@69", "$@70", "$@71", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      38,    42,    47,    37,    33,    94,    59,   123,   125,    91,
      93,    40,    41,    44,    61
};
# endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -173,     6,    72,  -173,  -173,  -173,  -173,  -173,    72,  -173,
     -35,  -173,    -7,    -5,    -4,  -173,  -173,  -173,  -173,  -173,
     -25,   -28,   -16,  -173,  -173,  -173,  -173,   -13,    16,   180,
       2,     5,     4,     1,  -173,  -173,  -173,  -173,  -173,  -173,
       7,  -173,  -173,  -173,  -173,   -37,  -173,  -173,  -173,  -173,
    -173,  -173,   354,  -173,  -173,    13,  -173,    48,     8,    34,
      43,    44,    50,    18,   180,   180,   180,   180,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   -13,  -173,    56,    52,  -173,  -173,  -173,
    -173,  -173,  -173,    98,    98,    60,   123,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   -16,  -173,    16,  -173,  -173,  -173,   180,   180,   180,
     180,   180,   180,  -173,   184,   184,   184,   184,   184,   184,
      98,    98,    98,    98,    60,    60,    60,    60,  -173,  -173,
      -3,   207,   228,   249,   270,    55,  -173,     3,   380,  -173,
      67,  -173,  -173,  -173,    68,    57,    80,    -3,    74,  -173,
    -173,  -173,  -173,  -173,    83,    84,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,    82,   -21,    85,   180,    87,   -16,    86,
    -173,  -173,  -173,  -173,  -173,  -173,   180,   180,  -173,  -173,
      88,  -173,   406,  -173,    30,  -173,   180,    96,  -173,   291,
     180,   180,  -173,   180,   104,   105,  -173,   106,  -173,  -173,
     107,   454,  -173,  -173,  -173,   430,   312,   333,   180,    96,
     180,    96,   180,   180,    96,   180,    96,    93,   110,   136,
    -173,  -173,   454,  -173,   454,  -173,   454,   454,  -173,   454,
    -173,  -173,   119,   117,   454,    -3,   164,   124,   130,  -173,
    -173,   131,   133,  -173,   134,    -3,  -173,    93,  -173,   170,
     110,    -3,  -173,   140,  -173,  -173,  -173,   142,  -173,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     9,    23,    16,     3,     5,     7,
       0,     8,     0,     0,     0,     4,     6,    10,    24,    17,
       0,     0,    22,    11,    25,    19,    18,    15,    29,     0,
       0,     0,    30,     0,    28,   113,   114,   115,   138,   116,
       0,   166,   157,   160,   163,   140,   131,   129,   145,   135,
     139,   137,     0,    12,    13,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   147,
     149,   151,   153,   155,   141,   117,   119,   143,   121,   123,
     133,   125,    20,    15,    32,     0,     0,   167,   158,   161,
     164,   102,   170,   132,   130,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    14,     0,    34,    27,   112,     0,     0,     0,
       0,   105,     0,   136,   128,   148,   150,   152,   154,   156,
     142,   118,   120,   144,   122,   124,   134,   126,    21,    33,
      37,     0,     0,     0,     0,     0,   104,   106,     0,    87,
       0,    96,    81,   109,    52,    51,     0,    37,     0,    45,
      39,    40,    41,    42,     0,     0,   168,   159,   162,   165,
     103,   107,   171,     0,    86,     0,     0,     0,    22,    47,
      46,    35,    36,    38,    43,    44,     0,     0,    52,    85,
       0,    97,     0,   110,     0,    53,     0,     0,   108,     0,
       0,     0,    82,     0,    56,    58,    60,    62,    72,    73,
      54,    48,    74,    50,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   111,    57,    67,    59,    69,    61,    63,    71,    55,
      65,    80,     0,    76,    79,    37,    95,     0,     0,    75,
      77,     0,    91,    89,     0,    37,    99,     0,    90,     0,
       0,    37,    83,     0,    78,    92,    94,     0,   100,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,   174,  -173,  -173,  -173,  -173,  -173,   109,
    -173,     0,  -173,  -173,   -96,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,    90,  -173,  -173,  -173,  -173,  -153,  -173,
      21,  -173,  -173,  -173,   -24,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -172,  -173,   -51,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,   -45,  -173,  -173,   -52,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -139,  -173,
    -173,  -173,    29,  -173,  -173,  -173,  -173,  -173,   -29,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    12,    20,    27,    30,
      83,   155,    14,    22,    26,    29,   111,    11,    13,    21,
      28,    85,    33,    34,    55,   113,   115,   140,   156,   157,
     158,   180,   196,   197,   159,   178,   195,   225,   218,   220,
     222,   223,   226,   219,   221,   224,   241,   227,   242,   257,
     243,   160,   176,   161,   262,   190,   162,   173,   228,   246,
     253,   259,   260,   163,   175,   201,   248,   256,    50,    62,
     121,   145,   146,   186,   165,   177,   203,    51,   147,   104,
     105,   107,   108,   110,    97,    65,    64,   109,    67,   103,
     106,    66,    98,    99,   100,   101,   102,    59,   118,    60,
     119,    61,   120,    58,   117,    63,   122
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   164,    10,   188,   182,   149,     3,   150,    10,   151,
     152,    16,  -169,   153,  -101,   138,     6,    17,   164,    18,
      19,   154,    23,    24,     6,   213,    68,    31,    69,    70,
      71,    72,    73,    25,     6,    93,    94,    95,    96,    74,
      32,    75,    76,    77,    78,    79,    80,   233,    81,   235,
      53,    54,   238,    56,   240,    86,   171,   -31,    57,    87,
     204,   205,   206,   207,   208,   209,    84,    92,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   194,    31,   210,    88,     4,     5,   141,   142,
     143,   144,   251,   148,    89,    90,    35,    36,    37,    38,
      39,    91,   263,   114,   116,    81,   164,   170,   267,     6,
      40,   179,    41,    42,    43,    44,   164,    45,   174,  -101,
     183,    68,   164,    69,    70,    71,    72,    73,   181,   184,
     185,    46,    47,   187,   200,   -49,   191,    48,   193,    78,
      79,    80,   212,    81,    49,   212,    68,   192,    69,    70,
      71,    72,    73,   -66,   -68,   -70,   -64,   245,   199,    74,
     188,    75,    76,    77,    78,    79,    80,   211,    81,   249,
     250,   215,   216,   252,   217,   123,   254,   255,   149,   258,
     -93,   261,    15,    35,    36,    37,    38,    39,   268,   232,
     269,   234,   112,   236,   237,   189,   239,    40,   244,    41,
      42,    43,    44,   139,    45,   247,   264,  -170,   266,  -170,
    -170,  -170,  -170,  -170,   265,   198,     0,     0,    46,    47,
       0,     0,     0,     0,    48,    78,    79,    80,   244,    81,
      68,    49,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,     0,    74,     0,    75,    76,    77,    78,    79,
      80,    68,    81,    69,    70,    71,    72,    73,     0,   166,
       0,     0,     0,     0,    74,     0,    75,    76,    77,    78,
      79,    80,    68,    81,    69,    70,    71,    72,    73,     0,
     167,     0,     0,     0,     0,    74,     0,    75,    76,    77,
      78,    79,    80,    68,    81,    69,    70,    71,    72,    73,
       0,   168,     0,     0,     0,     0,    74,     0,    75,    76,
      77,    78,    79,    80,    68,    81,    69,    70,    71,    72,
      73,     0,   169,     0,     0,     0,     0,    74,     0,    75,
      76,    77,    78,    79,    80,    68,    81,    69,    70,    71,
      72,    73,     0,   214,     0,     0,     0,     0,    74,     0,
      75,    76,    77,    78,    79,    80,    68,    81,    69,    70,
      71,    72,    73,     0,   230,     0,     0,     0,     0,    74,
       0,    75,    76,    77,    78,    79,    80,    68,    81,    69,
      70,    71,    72,    73,     0,   231,     0,     0,     0,     0,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81,
       0,     0,     0,    68,    82,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,    74,     0,    75,    76,
      77,    78,    79,    80,     0,    81,     0,     0,     0,    68,
     172,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,    74,     0,    75,    76,    77,    78,    79,    80,
       0,    81,   202,    68,     0,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,    74,     0,    75,    76,
      77,    78,    79,    80,     0,    81,   229,    68,     0,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
      74,     0,    75,    76,    77,    78,    79,    80,     0,    81
};

static const yytype_int16 yycheck[] =
{
      29,   140,     2,    24,   157,     8,     0,    10,     8,    12,
      13,    46,    49,    16,    51,   111,    37,    24,   157,    24,
      24,    24,    47,    51,    37,   197,    23,    27,    25,    26,
      27,    28,    29,    49,    37,    64,    65,    66,    67,    36,
      24,    38,    39,    40,    41,    42,    43,   219,    45,   221,
      48,    46,   224,    52,   226,     7,    53,    53,    51,    51,
      30,    31,    32,    33,    34,    35,    53,    49,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   178,    83,    54,    51,    14,    15,   117,   118,
     119,   120,   245,   122,    51,    51,     3,     4,     5,     6,
       7,    51,   255,    47,    52,    45,   245,    52,   261,    37,
      17,    54,    19,    20,    21,    22,   255,    24,    51,    51,
      46,    23,   261,    25,    26,    27,    28,    29,    48,    46,
      46,    38,    39,    51,    46,    49,    51,    44,    51,    41,
      42,    43,    49,    45,    51,    49,    23,   176,    25,    26,
      27,    28,    29,    49,    49,    49,    49,    47,   187,    36,
      24,    38,    39,    40,    41,    42,    43,   196,    45,    50,
      53,   200,   201,     9,   203,    52,    52,    47,     8,    48,
      47,    47,     8,     3,     4,     5,     6,     7,    48,   218,
      48,   220,    83,   222,   223,   174,   225,    17,   227,    19,
      20,    21,    22,   113,    24,   229,   257,    23,   260,    25,
      26,    27,    28,    29,   259,   186,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    41,    42,    43,   257,    45,
      23,    51,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    23,    45,    25,    26,    27,    28,    29,    -1,    52,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    23,    45,    25,    26,    27,    28,    29,    -1,
      52,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    23,    45,    25,    26,    27,    28,    29,
      -1,    52,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    23,    45,    25,    26,    27,    28,
      29,    -1,    52,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    23,    45,    25,    26,    27,
      28,    29,    -1,    52,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    23,    45,    25,    26,
      27,    28,    29,    -1,    52,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    23,    45,    25,
      26,    27,    28,    29,    -1,    52,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    -1,    23,    50,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    23,
      50,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    23,    -1,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    23,    -1,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,     0,    14,    15,    37,    58,    59,    60,
      66,    72,    61,    73,    67,    58,    46,    24,    24,    24,
      62,    74,    68,    47,    51,    49,    69,    63,    75,    70,
      64,    66,    24,    77,    78,     3,     4,     5,     6,     7,
      17,    19,    20,    21,    22,    24,    38,    39,    44,    51,
     123,   132,   133,    48,    46,    79,    52,    51,   158,   152,
     154,   156,   124,   160,   141,   140,   146,   143,    23,    25,
      26,    27,    28,    29,    36,    38,    39,    40,    41,    42,
      43,    45,    50,    65,    53,    76,     7,    51,    51,    51,
      51,    51,    49,   133,   133,   133,   133,   139,   147,   148,
     149,   150,   151,   144,   134,   135,   145,   136,   137,   142,
     138,    71,    64,    80,    47,    81,    52,   159,   153,   155,
     157,   125,   161,    52,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,    69,    78,
      82,   133,   133,   133,   133,   126,   127,   133,   133,     8,
      10,    12,    13,    16,    24,    66,    83,    84,    85,    89,
     106,   108,   111,   118,   123,   129,    52,    52,    52,    52,
      52,    53,    50,   112,    51,   119,   107,   130,    90,    54,
      86,    48,    83,    46,    46,    46,   128,    51,    24,    85,
     110,    51,   133,    51,    69,    91,    87,    88,   127,   133,
      46,   120,    46,   131,    30,    31,    32,    33,    34,    35,
      54,   133,    49,   101,    52,   133,   133,   133,    93,    98,
      94,    99,    95,    96,   100,    92,    97,   102,   113,    46,
      52,    52,   133,   101,   133,   101,   133,   133,   101,   133,
     101,   101,   103,   105,   133,    47,   114,    89,   121,    50,
      53,    83,     9,   115,    52,    47,   122,   104,    48,   116,
     117,    47,   109,    83,   103,   111,   114,    83,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    57,    56,    58,    58,    59,    59,    59,    61,
      62,    63,    60,    65,    64,    64,    67,    68,    66,    70,
      71,    69,    69,    73,    74,    75,    76,    72,    77,    77,
      78,    79,    80,    78,    82,    81,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    85,    85,    87,    86,    88,
      86,    86,    90,    89,    92,    91,    93,    91,    94,    91,
      95,    91,    96,    91,    97,    91,    98,    91,    99,    91,
     100,    91,    91,    91,   102,   101,   103,   104,   103,   105,
     105,   107,   106,   108,   109,   110,   110,   112,   113,   111,
     114,   116,   115,   117,   115,   115,   119,   120,   121,   118,
     122,   124,   125,   123,   126,   126,   127,   128,   127,   130,
     131,   129,   132,   133,   133,   133,   133,   134,   133,   135,
     133,   136,   133,   137,   133,   138,   133,   139,   133,   140,
     133,   141,   133,   142,   133,   143,   133,   133,   133,   133,
     133,   144,   133,   145,   133,   146,   133,   147,   133,   148,
     133,   149,   133,   150,   133,   151,   133,   152,   153,   133,
     154,   155,   133,   156,   157,   133,   158,   159,   133,   160,
     161,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     1,     0,
       0,     0,     8,     0,     4,     0,     0,     0,     5,     0,
       0,     6,     0,     0,     0,     0,     0,    10,     1,     0,
       1,     0,     0,     5,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     2,     2,     1,     2,     0,     3,     0,
       3,     0,     0,     3,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     2,     2,     0,     4,     1,     0,     4,     1,
       1,     0,     4,     9,     3,     1,     0,     0,     0,     8,
       3,     0,     3,     0,     3,     0,     0,     0,     0,     8,
       3,     0,     0,     6,     1,     0,     1,     0,     4,     0,
       0,     6,     4,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     1,     1,
       1,     0,     4,     0,     4,     0,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     0,
       0,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 60 "analisador_ascendente.y"
       {createFile();}
#line 1680 "analisador_ascendente.tab.c"
    break;

  case 6:
#line 66 "analisador_ascendente.y"
                              {addTokenToListAux(";\n");}
#line 1686 "analisador_ascendente.tab.c"
    break;

  case 9:
#line 71 "analisador_ascendente.y"
            {addTokenToListAux("struct");}
#line 1692 "analisador_ascendente.tab.c"
    break;

  case 10:
#line 71 "analisador_ascendente.y"
                                              {addTokenToListAux((yyvsp[0].val));}
#line 1698 "analisador_ascendente.tab.c"
    break;

  case 11:
#line 71 "analisador_ascendente.y"
                                                                           {addTokenToListAux("{");}
#line 1704 "analisador_ascendente.tab.c"
    break;

  case 12:
#line 71 "analisador_ascendente.y"
                                                                                                                        {addTokenToListAux("}");}
#line 1710 "analisador_ascendente.tab.c"
    break;

  case 13:
#line 74 "analisador_ascendente.y"
                                  {addTokenToListAux(";\n");}
#line 1716 "analisador_ascendente.tab.c"
    break;

  case 16:
#line 78 "analisador_ascendente.y"
                   {addTokenToListAux("auto");}
#line 1722 "analisador_ascendente.tab.c"
    break;

  case 17:
#line 78 "analisador_ascendente.y"
                                                   {addTokenToListAux((yyvsp[0].val));}
#line 1728 "analisador_ascendente.tab.c"
    break;

  case 19:
#line 81 "analisador_ascendente.y"
            {addTokenToListAux("[");}
#line 1734 "analisador_ascendente.tab.c"
    break;

  case 20:
#line 81 "analisador_ascendente.y"
                                                     {addTokenToListAux("]");}
#line 1740 "analisador_ascendente.tab.c"
    break;

  case 23:
#line 85 "analisador_ascendente.y"
              {addTokenToListAux("auto");}
#line 1746 "analisador_ascendente.tab.c"
    break;

  case 24:
#line 85 "analisador_ascendente.y"
                                              {addTokenToListAux((yyvsp[0].val));}
#line 1752 "analisador_ascendente.tab.c"
    break;

  case 25:
#line 85 "analisador_ascendente.y"
                                                                           {addTokenToListAux("(");}
#line 1758 "analisador_ascendente.tab.c"
    break;

  case 26:
#line 85 "analisador_ascendente.y"
                                                                                                                    {addTokenToListAux(")");}
#line 1764 "analisador_ascendente.tab.c"
    break;

  case 30:
#line 92 "analisador_ascendente.y"
                      {addTokenToListAux("void*");addTokenToListAux((yyvsp[0].val));}
#line 1770 "analisador_ascendente.tab.c"
    break;

  case 31:
#line 93 "analisador_ascendente.y"
         {addTokenToListAux("void*");addTokenToListAux((yyvsp[0].val));}
#line 1776 "analisador_ascendente.tab.c"
    break;

  case 32:
#line 93 "analisador_ascendente.y"
                                                                 {addTokenToListAux(",");}
#line 1782 "analisador_ascendente.tab.c"
    break;

  case 34:
#line 96 "analisador_ascendente.y"
           {addTokenToListAux("{\n");}
#line 1788 "analisador_ascendente.tab.c"
    break;

  case 35:
#line 96 "analisador_ascendente.y"
                                                      {addTokenToListAux("}\n");}
#line 1794 "analisador_ascendente.tab.c"
    break;

  case 38:
#line 103 "analisador_ascendente.y"
                      {addTokenToListAux(";\n");}
#line 1800 "analisador_ascendente.tab.c"
    break;

  case 43:
#line 108 "analisador_ascendente.y"
                        {addTokenToListAux(";\n");}
#line 1806 "analisador_ascendente.tab.c"
    break;

  case 44:
#line 109 "analisador_ascendente.y"
                {addTokenToListAux(";\n");}
#line 1812 "analisador_ascendente.tab.c"
    break;

  case 47:
#line 116 "analisador_ascendente.y"
               {addTokenToListAux("=");}
#line 1818 "analisador_ascendente.tab.c"
    break;

  case 49:
#line 117 "analisador_ascendente.y"
          {addTokenToListAux("=");}
#line 1824 "analisador_ascendente.tab.c"
    break;

  case 52:
#line 121 "analisador_ascendente.y"
               {addTokenToListAux((yyvsp[0].val));}
#line 1830 "analisador_ascendente.tab.c"
    break;

  case 54:
#line 125 "analisador_ascendente.y"
                        {addTokenToListAux("=");}
#line 1836 "analisador_ascendente.tab.c"
    break;

  case 56:
#line 126 "analisador_ascendente.y"
                 {addTokenToListAux("+=");}
#line 1842 "analisador_ascendente.tab.c"
    break;

  case 58:
#line 127 "analisador_ascendente.y"
                 {addTokenToListAux("-=");}
#line 1848 "analisador_ascendente.tab.c"
    break;

  case 60:
#line 128 "analisador_ascendente.y"
                 {addTokenToListAux("/=");}
#line 1854 "analisador_ascendente.tab.c"
    break;

  case 62:
#line 129 "analisador_ascendente.y"
                 {addTokenToListAux("*=");}
#line 1860 "analisador_ascendente.tab.c"
    break;

  case 64:
#line 130 "analisador_ascendente.y"
                 {addTokenToListAux("=");}
#line 1866 "analisador_ascendente.tab.c"
    break;

  case 66:
#line 131 "analisador_ascendente.y"
                 {addTokenToListAux("+=");}
#line 1872 "analisador_ascendente.tab.c"
    break;

  case 68:
#line 132 "analisador_ascendente.y"
                 {addTokenToListAux("-=");}
#line 1878 "analisador_ascendente.tab.c"
    break;

  case 70:
#line 133 "analisador_ascendente.y"
                 {addTokenToListAux("*=");}
#line 1884 "analisador_ascendente.tab.c"
    break;

  case 72:
#line 134 "analisador_ascendente.y"
                 {addTokenToListAux("++");}
#line 1890 "analisador_ascendente.tab.c"
    break;

  case 73:
#line 135 "analisador_ascendente.y"
                 {addTokenToListAux("--");}
#line 1896 "analisador_ascendente.tab.c"
    break;

  case 74:
#line 138 "analisador_ascendente.y"
                 {addTokenToListAux("{");}
#line 1902 "analisador_ascendente.tab.c"
    break;

  case 75:
#line 138 "analisador_ascendente.y"
                                                        {addTokenToListAux("}");}
#line 1908 "analisador_ascendente.tab.c"
    break;

  case 77:
#line 141 "analisador_ascendente.y"
                  {addTokenToListAux(",");}
#line 1914 "analisador_ascendente.tab.c"
    break;

  case 81:
#line 148 "analisador_ascendente.y"
                 {addTokenToListAux("return");}
#line 1920 "analisador_ascendente.tab.c"
    break;

  case 82:
#line 148 "analisador_ascendente.y"
                                                                                                                                   {addTokenToListAux(";\n");}
#line 1926 "analisador_ascendente.tab.c"
    break;

  case 87:
#line 201 "analisador_ascendente.y"
{
    addTokenToListAux("if");
    addTokenToListAux("(!(");
}
#line 1935 "analisador_ascendente.tab.c"
    break;

  case 88:
#line 207 "analisador_ascendente.y"
{
    addTokenToListAux("))");
    addTokenToListAux("goto");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "else%d;\n", aux);
    push(&root, aux++);
    addTokenToListAux(gotoblk);
}
#line 1949 "analisador_ascendente.tab.c"
    break;

  case 91:
#line 224 "analisador_ascendente.y"
{
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
}
#line 1961 "analisador_ascendente.tab.c"
    break;

  case 92:
#line 231 "analisador_ascendente.y"
                     {addTokenToListAux("}\n");}
#line 1967 "analisador_ascendente.tab.c"
    break;

  case 93:
#line 233 "analisador_ascendente.y"
{
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
}
#line 1979 "analisador_ascendente.tab.c"
    break;

  case 94:
#line 240 "analisador_ascendente.y"
                 {addTokenToListAux("}\n");}
#line 1985 "analisador_ascendente.tab.c"
    break;

  case 95:
#line 242 "analisador_ascendente.y"
{  
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
    addTokenToListAux("}\n");
}
#line 1998 "analisador_ascendente.tab.c"
    break;

  case 96:
#line 253 "analisador_ascendente.y"
{
    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "while%d:", aux);
    addTokenToListAux(gotoblk);
}
#line 2008 "analisador_ascendente.tab.c"
    break;

  case 97:
#line 258 "analisador_ascendente.y"
{
    addTokenToListAux("if(!(");
}
#line 2016 "analisador_ascendente.tab.c"
    break;

  case 98:
#line 261 "analisador_ascendente.y"
                            {
    addTokenToListAux("))");
    addTokenToListAux("goto");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "end%d;\n", aux);
    push(&root, aux++);
    addTokenToListAux(gotoblk);

    //addTokenToListAux("end;\n");

}
#line 2033 "analisador_ascendente.tab.c"
    break;

  case 100:
#line 278 "analisador_ascendente.y"
{
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "while%d", n);
    addTokenToListAux("goto");
    addTokenToListAux(gotoblk);
    addTokenToListAux(";\n");
    sprintf(gotoblk, "end%d:\n", n);
    addTokenToListAux(gotoblk);
}
#line 2048 "analisador_ascendente.tab.c"
    break;

  case 101:
#line 290 "analisador_ascendente.y"
                  {addTokenToListAux((yyvsp[0].val));}
#line 2054 "analisador_ascendente.tab.c"
    break;

  case 102:
#line 290 "analisador_ascendente.y"
                                               {addTokenToListAux("(");}
#line 2060 "analisador_ascendente.tab.c"
    break;

  case 103:
#line 290 "analisador_ascendente.y"
                                                                                            {addTokenToListAux(")");}
#line 2066 "analisador_ascendente.tab.c"
    break;

  case 107:
#line 298 "analisador_ascendente.y"
                     {addTokenToListAux(",");}
#line 2072 "analisador_ascendente.tab.c"
    break;

  case 109:
#line 300 "analisador_ascendente.y"
           {addTokenToListAux("printf");}
#line 2078 "analisador_ascendente.tab.c"
    break;

  case 110:
#line 300 "analisador_ascendente.y"
                                              {addTokenToListAux("(");}
#line 2084 "analisador_ascendente.tab.c"
    break;

  case 111:
#line 300 "analisador_ascendente.y"
                                                                                       {addTokenToListAux(")");}
#line 2090 "analisador_ascendente.tab.c"
    break;

  case 112:
#line 303 "analisador_ascendente.y"
{
    addTokenToListAux("read");
    addTokenToListAux("(");
    addTokenToListAux((yyvsp[-1].val));
    addTokenToListAux(")");
}
#line 2101 "analisador_ascendente.tab.c"
    break;

  case 113:
#line 311 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2107 "analisador_ascendente.tab.c"
    break;

  case 114:
#line 312 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2113 "analisador_ascendente.tab.c"
    break;

  case 115:
#line 313 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2119 "analisador_ascendente.tab.c"
    break;

  case 116:
#line 314 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2125 "analisador_ascendente.tab.c"
    break;

  case 117:
#line 315 "analisador_ascendente.y"
                                    {addTokenToListAux("+");}
#line 2131 "analisador_ascendente.tab.c"
    break;

  case 119:
#line 316 "analisador_ascendente.y"
                                    {addTokenToListAux("-");}
#line 2137 "analisador_ascendente.tab.c"
    break;

  case 121:
#line 317 "analisador_ascendente.y"
                                    {addTokenToListAux("*");}
#line 2143 "analisador_ascendente.tab.c"
    break;

  case 123:
#line 318 "analisador_ascendente.y"
                                    {addTokenToListAux("/");}
#line 2149 "analisador_ascendente.tab.c"
    break;

  case 125:
#line 319 "analisador_ascendente.y"
                                    {addTokenToListAux("^");}
#line 2155 "analisador_ascendente.tab.c"
    break;

  case 127:
#line 320 "analisador_ascendente.y"
                                    {addTokenToListAux("==");}
#line 2161 "analisador_ascendente.tab.c"
    break;

  case 129:
#line 321 "analisador_ascendente.y"
                                    {addTokenToListAux("-");}
#line 2167 "analisador_ascendente.tab.c"
    break;

  case 131:
#line 322 "analisador_ascendente.y"
                                    {addTokenToListAux("+");}
#line 2173 "analisador_ascendente.tab.c"
    break;

  case 133:
#line 323 "analisador_ascendente.y"
                                    {addTokenToListAux("%");}
#line 2179 "analisador_ascendente.tab.c"
    break;

  case 135:
#line 324 "analisador_ascendente.y"
                                    {addTokenToListAux("(");}
#line 2185 "analisador_ascendente.tab.c"
    break;

  case 136:
#line 324 "analisador_ascendente.y"
                                                                             {addTokenToListAux(")");}
#line 2191 "analisador_ascendente.tab.c"
    break;

  case 138:
#line 326 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2197 "analisador_ascendente.tab.c"
    break;

  case 140:
#line 328 "analisador_ascendente.y"
                                    {addTokenToListAux((yyvsp[0].val));}
#line 2203 "analisador_ascendente.tab.c"
    break;

  case 141:
#line 329 "analisador_ascendente.y"
                                    {addTokenToListAux("||");}
#line 2209 "analisador_ascendente.tab.c"
    break;

  case 143:
#line 330 "analisador_ascendente.y"
                                    {addTokenToListAux("&");}
#line 2215 "analisador_ascendente.tab.c"
    break;

  case 145:
#line 331 "analisador_ascendente.y"
                                    {addTokenToListAux("!");}
#line 2221 "analisador_ascendente.tab.c"
    break;

  case 147:
#line 332 "analisador_ascendente.y"
                                    {addTokenToListAux("!=");}
#line 2227 "analisador_ascendente.tab.c"
    break;

  case 149:
#line 333 "analisador_ascendente.y"
                                    {addTokenToListAux("<=");}
#line 2233 "analisador_ascendente.tab.c"
    break;

  case 151:
#line 334 "analisador_ascendente.y"
                                    {addTokenToListAux("<");}
#line 2239 "analisador_ascendente.tab.c"
    break;

  case 153:
#line 335 "analisador_ascendente.y"
                                    {addTokenToListAux(">=");}
#line 2245 "analisador_ascendente.tab.c"
    break;

  case 155:
#line 336 "analisador_ascendente.y"
                                    {addTokenToListAux(">");}
#line 2251 "analisador_ascendente.tab.c"
    break;

  case 157:
#line 337 "analisador_ascendente.y"
          {addTokenToListAux("identity");}
#line 2257 "analisador_ascendente.tab.c"
    break;

  case 158:
#line 337 "analisador_ascendente.y"
                                               {addTokenToListAux("(");}
#line 2263 "analisador_ascendente.tab.c"
    break;

  case 159:
#line 337 "analisador_ascendente.y"
                                                                                        {addTokenToListAux(")");}
#line 2269 "analisador_ascendente.tab.c"
    break;

  case 160:
#line 338 "analisador_ascendente.y"
          {addTokenToListAux("inverse");}
#line 2275 "analisador_ascendente.tab.c"
    break;

  case 161:
#line 338 "analisador_ascendente.y"
                                              {addTokenToListAux("(");}
#line 2281 "analisador_ascendente.tab.c"
    break;

  case 162:
#line 338 "analisador_ascendente.y"
                                                                                       {addTokenToListAux(")");}
#line 2287 "analisador_ascendente.tab.c"
    break;

  case 163:
#line 339 "analisador_ascendente.y"
          {addTokenToListAux("transposed");}
#line 2293 "analisador_ascendente.tab.c"
    break;

  case 164:
#line 339 "analisador_ascendente.y"
                                                 {addTokenToListAux("(");}
#line 2299 "analisador_ascendente.tab.c"
    break;

  case 165:
#line 339 "analisador_ascendente.y"
                                                                                          {addTokenToListAux(")");}
#line 2305 "analisador_ascendente.tab.c"
    break;

  case 166:
#line 340 "analisador_ascendente.y"
          {addTokenToListAux("zero");}
#line 2311 "analisador_ascendente.tab.c"
    break;

  case 167:
#line 340 "analisador_ascendente.y"
                                           {addTokenToListAux("(");}
#line 2317 "analisador_ascendente.tab.c"
    break;

  case 168:
#line 340 "analisador_ascendente.y"
                                                                                    {addTokenToListAux(")");}
#line 2323 "analisador_ascendente.tab.c"
    break;

  case 169:
#line 341 "analisador_ascendente.y"
         {addTokenToListAux("&");addTokenToListAux((yyvsp[0].val));}
#line 2329 "analisador_ascendente.tab.c"
    break;

  case 170:
#line 341 "analisador_ascendente.y"
                                                             {addTokenToListAux("[");addTokenToListAux("(int)");}
#line 2335 "analisador_ascendente.tab.c"
    break;

  case 171:
#line 341 "analisador_ascendente.y"
                                                                                                                                 {addTokenToListAux("]");}
#line 2341 "analisador_ascendente.tab.c"
    break;


#line 2345 "analisador_ascendente.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 345 "analisador_ascendente.y"


void addTokenToList(char * tok , List * curr_list){
    if (init != NULL)
    {
        List * str = (List *) malloc(sizeof(struct List));
        str->line = tok;
        curr_list->next = str;
        curr = curr_list->next;
    }
    else{
        List * str = (List *) malloc(sizeof(struct List));
        str->line = tok;
        init = str;
        curr = str;
    }
    FILE *fptr;
    fptr = fopen("result.c","a");
    //fseek(fptr, 0, SEEK_END);
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
    fprintf(fptr, "%s ", curr->line);
    fclose(fptr);

    //printf("%s ", curr->line);
}

void addTokenToListAux(char * tok){
    addTokenToList(tok, curr);
}

void print(){
    List * a = init;
    while(a != NULL){
        printf("%s ", a->line);
        a = a->next ;
    }
}

void createFile(){
    FILE * x = fopen("result.c", "w");

    fprintf(x, "#include <stdio.h>\n#include <ctype.h>\n#include <string.h>\n#include <stdarg.h>\n#include \"lib.h\"\n");
    fclose(x);
}

void 
yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int main( int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 ) {
        yyin = fopen( argv[0], "r" );
    } else {
        yyin = stdin;
    }

    yyparse();
    //print();

    printf("Finished!\n");
}
