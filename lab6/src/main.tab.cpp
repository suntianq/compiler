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
#line 1 "src/main.y"

    #include "common.h"
    #define YYSTYPE Node *  
    extern tree parse_tree;
    symtable symtbl;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
    int str_count=0;
    int chr_count=0;

#line 82 "src/main.tab.cpp"

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
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    INCLUDE = 258,
    INT = 259,
    BOOL = 260,
    TRUE = 261,
    FALSE = 262,
    CHAR = 263,
    FLOAT = 264,
    DOUBLE = 265,
    LONG = 266,
    SHORT = 267,
    VOID = 268,
    MAIN = 269,
    THIS = 270,
    DEFAULT = 271,
    USING = 272,
    IF = 273,
    ELSE = 274,
    SWITCH = 275,
    CASE = 276,
    FOR = 277,
    WHILE = 278,
    BREAK = 279,
    CONTINUE = 280,
    DO = 281,
    GOTO = 282,
    RETURN = 283,
    CLASS = 284,
    STRUCT = 285,
    CONST = 286,
    STRING = 287,
    SCANF = 288,
    PRINTF = 289,
    MOD = 290,
    INC = 291,
    DEC = 292,
    ADD = 293,
    SUB = 294,
    MUL = 295,
    DIV = 296,
    OPAND = 297,
    OPOR = 298,
    POWER = 299,
    OPNOT = 300,
    SHIFTL = 301,
    SHIFTR = 302,
    LPAREN = 303,
    RPAREN = 304,
    LBRACKET = 305,
    RBRACKET = 306,
    LBRACE = 307,
    RBRACE = 308,
    GT = 309,
    LT = 310,
    EQ = 311,
    EQUAL = 312,
    NEQUAL = 313,
    GE = 314,
    LE = 315,
    OR = 316,
    AND = 317,
    NOT = 318,
    BIT_AND = 319,
    BIT_OR = 320,
    AEQ = 321,
    SEQ = 322,
    SQUOTE = 323,
    DQUOTE = 324,
    COLON = 325,
    SEMICOLON = 326,
    COMMA = 327,
    CONSTCHAR = 328,
    CONSTSTRING = 329,
    ID = 330,
    INTNUMBER = 331,
    UMINUS = 332
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYUNDEFTOK  2
#define YYMAXUTOK   332


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    51,    62,    66,    70,    77,    89,    93,
      94,    95,    96,    97,    98,    99,   100,   104,   105,   109,
     118,   127,   128,   129,   130,   131,   136,   148,   152,   153,
     157,   167,   171,   173,   175,   177,   179,   184,   189,   191,
     196,   202,   208,   213,   214,   228,   229,   230,   231,   237,
     246,   247,   251,   253,   255,   257,   263,   265,   269,   271,
     275,   277,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   293,   294,   295,   296,   297,   302,   303,   304,   305,
     309,   310,   312,   313,   317,   320
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "INT", "BOOL", "TRUE",
  "FALSE", "CHAR", "FLOAT", "DOUBLE", "LONG", "SHORT", "VOID", "MAIN",
  "THIS", "DEFAULT", "USING", "IF", "ELSE", "SWITCH", "CASE", "FOR",
  "WHILE", "BREAK", "CONTINUE", "DO", "GOTO", "RETURN", "CLASS", "STRUCT",
  "CONST", "STRING", "SCANF", "PRINTF", "MOD", "INC", "DEC", "ADD", "SUB",
  "MUL", "DIV", "OPAND", "OPOR", "POWER", "OPNOT", "SHIFTL", "SHIFTR",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "GT",
  "LT", "EQ", "EQUAL", "NEQUAL", "GE", "LE", "OR", "AND", "NOT", "BIT_AND",
  "BIT_OR", "AEQ", "SEQ", "SQUOTE", "DQUOTE", "COLON", "SEMICOLON",
  "COMMA", "CONSTCHAR", "CONSTSTRING", "ID", "INTNUMBER", "UMINUS",
  "$accept", "program", "compound_stmt", "stmt_list", "stmt",
  "declaration", "var_declaration", "const_declaration", "type", "idlist",
  "id_or_assign", "id", "expr_stmt", "if_stmt", "while_stmt", "for_stmt",
  "scanf_stmt", "printf_stmt", "ret_stmt", "func_call_idlist",
  "func_call_id", "conststring", "expression", "assign_expr",
  "not_expression", "or_expression", "and_expression", "relation_expr",
  "op_expr", "term", "factor", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332
};
# endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    14,    36,    56,    42,    44,   -62,    28,    53,    59,
      59,    99,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      64,    66,    67,   279,    21,   -62,    68,    71,   279,   279,
     -62,   250,    50,   -62,   -62,   -62,   160,   -62,   -62,   -62,
     -62,    50,   -15,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
      65,   -62,   -62,    74,    75,    27,   -24,    48,   -62,   279,
     274,   279,    69,    50,   122,   122,   -62,    90,   -20,   -62,
     -62,   279,   -62,   -62,     3,   -62,   -43,   -62,   -62,   -62,
     279,   279,   279,   -62,   250,   250,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,    92,   279,    73,
      93,   -62,    29,    70,   -62,   -18,   -62,   -62,   -62,   -17,
       8,   -62,    77,   -62,    50,   -62,   -62,   -62,   -62,    75,
      27,   -24,   -24,   -24,   -24,   -24,   -24,   -62,    48,    48,
     -62,   -62,   -62,   198,    78,   279,    59,   -62,   -62,    80,
     122,    83,   102,   -62,   127,   137,   279,    86,   -62,   -62,
     -62,   -62,   -62,    -6,   236,   109,   279,   -62,   -62,   -62,
      59,   110,   -62,    59,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     2,     3,    21,    23,    68,    69,    22,    24,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       6,     0,     0,    83,    30,    81,     0,     8,    10,    17,
      18,     0,    82,     9,    11,    12,    13,    15,    14,    16,
       0,    50,    51,    57,    59,    61,    70,    75,    79,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    82,    56,
      84,     0,     4,     7,     0,    27,    28,    29,    71,    72,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,     0,     0,    49,     0,    43,    47,    45,    79,
       0,    80,     0,    19,     0,    52,    50,    53,    54,    58,
      60,    62,    63,    64,    65,    66,    67,    82,    73,    74,
      78,    76,    77,     0,     0,     0,     0,    20,    48,     0,
       0,     0,    42,    26,    34,    32,     0,     0,    37,    40,
      44,    41,     5,     0,     0,     0,     0,    35,    36,    33,
       0,     0,    39,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -10,   -62,   -34,   -62,   100,   -62,   147,   113,
      63,   -23,   -62,    20,   -62,   -62,   -62,   -62,   -62,   114,
      40,   -62,   -22,   -36,   -62,   150,   103,   104,     7,    17,
     -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    12,    36,    37,    38,    39,    40,    41,    74,
      75,    42,    43,    44,    45,    46,    47,    48,    49,   105,
     106,   107,    50,    51,    52,    53,    54,    55,    56,    57,
      58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    62,    73,   109,   109,    77,    66,    67,    68,    70,
       1,    28,    20,    80,    92,    93,    78,    79,    76,     2,
      29,    78,    79,    81,    82,    14,    15,    77,     4,    18,
      19,   139,   -46,   130,   131,   132,    32,    97,    99,   100,
      76,    80,   108,   108,   116,    33,    11,    34,    35,   112,
       5,    81,    82,    25,   140,   -46,     6,   141,   115,   117,
     118,    68,    68,    68,    68,    68,    68,    68,    68,   127,
     127,   127,   127,   127,   113,   114,   134,     9,    77,   109,
     140,    86,    87,    94,    88,    89,    90,    91,    95,    96,
       7,    76,     8,   121,   122,   123,   124,   125,   126,   145,
     137,   114,    10,    14,    15,    16,    17,    18,    19,   128,
     129,    11,    59,   147,    60,    61,    64,    20,   108,    65,
     159,    21,    22,   144,   155,    34,   148,    23,    16,    17,
      24,    25,    26,    27,   161,    84,    83,    85,    28,   111,
     101,   133,   136,   157,   135,   138,   153,    29,   142,   146,
     162,   149,    30,   164,   151,   152,   154,   156,   160,   163,
      98,    28,    31,    32,    14,    15,    16,    17,    18,    19,
      29,    63,    33,   158,    34,    35,   102,   143,    20,   110,
     150,    69,    21,    22,   103,    31,    32,   119,    71,   120,
       0,    24,    25,    26,    27,    33,   104,    34,    35,    28,
       0,     0,    14,    15,    16,    17,    18,    19,    29,     0,
       0,     0,     0,    72,     0,     0,    20,     0,     0,     0,
      21,    22,     0,    31,    32,     0,    23,     0,     0,    24,
      25,    26,    27,    33,     0,    34,    35,    28,     0,     0,
      14,    15,    16,    17,    18,    19,    29,     0,     0,     0,
      11,     0,     0,     0,    20,     0,    16,    17,    21,    22,
       0,    31,    32,     0,    23,     0,     0,    24,    25,    26,
      27,    33,     0,    34,    35,    28,     0,     0,    14,    15,
      16,    17,    18,    19,    29,    16,    17,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    31,
      32,     0,     0,     0,     0,     0,    25,     0,     0,    33,
       0,    34,    35,    28,    32,     0,     0,     0,    28,     0,
       0,     0,    29,    33,     0,    34,    35,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,    32,     0,
       0,     0,    31,    32,     0,     0,     0,    33,     0,    34,
      35,     0,    33,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      10,    23,    36,    64,    65,    41,    28,    29,    31,    32,
       4,    39,    18,    56,    38,    39,    36,    37,    41,    13,
      48,    36,    37,    66,    67,     4,     5,    63,    14,     8,
       9,    49,    49,    94,    95,    96,    64,    59,    60,    61,
      63,    56,    64,    65,    80,    73,    52,    75,    76,    71,
      14,    66,    67,    32,    72,    72,     0,    49,    80,    81,
      82,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    71,    72,    98,    49,   114,   140,
      72,    54,    55,    35,    57,    58,    59,    60,    40,    41,
      48,   114,    48,    86,    87,    88,    89,    90,    91,   133,
      71,    72,    49,     4,     5,     6,     7,     8,     9,    92,
      93,    52,    48,   135,    48,    48,    48,    18,   140,    48,
     154,    22,    23,   133,   146,    75,   136,    28,     6,     7,
      31,    32,    33,    34,   156,    61,    71,    62,    39,    49,
      71,    49,    49,   153,    71,    75,    19,    48,    71,    71,
     160,    71,    53,   163,    71,    53,    19,    71,    49,    49,
      60,    39,    63,    64,     4,     5,     6,     7,     8,     9,
      48,    24,    73,   153,    75,    76,    63,   114,    18,    65,
     140,    31,    22,    23,    62,    63,    64,    84,    28,    85,
      -1,    31,    32,    33,    34,    73,    74,    75,    76,    39,
      -1,    -1,     4,     5,     6,     7,     8,     9,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    -1,    63,    64,    -1,    28,    -1,    -1,    31,
      32,    33,    34,    73,    -1,    75,    76,    39,    -1,    -1,
       4,     5,     6,     7,     8,     9,    48,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    18,    -1,     6,     7,    22,    23,
      -1,    63,    64,    -1,    28,    -1,    -1,    31,    32,    33,
      34,    73,    -1,    75,    76,    39,    -1,    -1,     4,     5,
       6,     7,     8,     9,    48,     6,     7,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    63,
      64,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    73,
      -1,    75,    76,    39,    64,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    48,    73,    -1,    75,    76,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    73,    -1,    75,
      76,    -1,    73,    -1,    75,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    13,    79,    14,    14,     0,    48,    48,    49,
      49,    52,    80,    80,     4,     5,     6,     7,     8,     9,
      18,    22,    23,    28,    31,    32,    33,    34,    39,    48,
      53,    63,    64,    73,    75,    76,    81,    82,    83,    84,
      85,    86,    89,    90,    91,    92,    93,    94,    95,    96,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    48,
      48,    48,   100,    86,    48,    48,   100,   100,    89,   103,
      89,    28,    53,    82,    87,    88,    89,   101,    36,    37,
      56,    66,    67,    71,    61,    62,    54,    55,    57,    58,
      59,    60,    38,    39,    35,    40,    41,   100,    84,   100,
     100,    71,    87,    62,    74,    97,    98,    99,   100,   108,
      97,    49,   100,    71,    72,   100,   101,   100,   100,   104,
     105,   106,   106,   106,   106,   106,   106,    89,   107,   107,
     108,   108,   108,    49,   100,    71,    49,    71,    75,    49,
      72,    49,    71,    88,    80,    82,    71,   100,    80,    71,
      98,    71,    53,    19,    19,   100,    71,    80,    91,    82,
      49,   100,    80,    49,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    78,    79,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      85,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    90,    91,    91,    91,    91,    91,    92,    93,    93,
      94,    95,    96,    97,    97,    98,    98,    98,    98,    99,
     100,   100,   101,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     5,     3,     6,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     5,     7,     5,     7,     7,     5,     9,     8,
       5,     5,     3,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     2,     3,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     2,     2
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
#line 45 "src/main.y"
{
    yyval=new Node;
    yyval=yyvsp[0];
    parse_tree.root=yyval;
    yyval->type_check();
}
#line 1552 "src/main.tab.cpp"
    break;

  case 3:
#line 52 "src/main.y"
{
    yyval=new Node;
    yyval=yyvsp[0];
    parse_tree.root=yyval;
    yyval->type_check();
}
#line 1563 "src/main.tab.cpp"
    break;

  case 4:
#line 63 "src/main.y"
{   
    yyval=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype,yyvsp[-1]);
}
#line 1571 "src/main.tab.cpp"
    break;

  case 5:
#line 67 "src/main.y"
{
    yyval=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype,yyvsp[-4]);
}
#line 1579 "src/main.tab.cpp"
    break;

  case 6:
#line 71 "src/main.y"
{
    yyval=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype);
}
#line 1587 "src/main.tab.cpp"
    break;

  case 7:
#line 78 "src/main.y"
{
    Node* s = yyvsp[-1];
    if(s!=NULL){
        while(s->sibling !=NULL)
            s=s->sibling;
        s->sibling = yyvsp[0];
        yyval=yyvsp[-1];
    }
    else 
        yyval=yyvsp[0];
}
#line 1603 "src/main.tab.cpp"
    break;

  case 8:
#line 89 "src/main.y"
         {yyval=yyvsp[0];}
#line 1609 "src/main.tab.cpp"
    break;

  case 9:
#line 93 "src/main.y"
                        {yyval=yyvsp[0];}
#line 1615 "src/main.tab.cpp"
    break;

  case 10:
#line 94 "src/main.y"
                        {yyval=yyvsp[0];}
#line 1621 "src/main.tab.cpp"
    break;

  case 11:
#line 95 "src/main.y"
                                        {yyval = yyvsp[0];}
#line 1627 "src/main.tab.cpp"
    break;

  case 12:
#line 96 "src/main.y"
                                {yyval = yyvsp[0];}
#line 1633 "src/main.tab.cpp"
    break;

  case 13:
#line 97 "src/main.y"
                                {yyval = yyvsp[0];}
#line 1639 "src/main.tab.cpp"
    break;

  case 14:
#line 98 "src/main.y"
                                {yyval = yyvsp[0];}
#line 1645 "src/main.tab.cpp"
    break;

  case 15:
#line 99 "src/main.y"
                                {yyval = yyvsp[0];}
#line 1651 "src/main.tab.cpp"
    break;

  case 16:
#line 100 "src/main.y"
                        {yyval=yyvsp[0];}
#line 1657 "src/main.tab.cpp"
    break;

  case 17:
#line 104 "src/main.y"
                                {yyval=yyvsp[0];}
#line 1663 "src/main.tab.cpp"
    break;

  case 18:
#line 105 "src/main.y"
                          {yyval=yyvsp[0];}
#line 1669 "src/main.tab.cpp"
    break;

  case 19:
#line 109 "src/main.y"
                         {
                    Node *p;
					yyval=parse_tree.NewRoot(DECL_NODE,VAR_DECL,NodeAttr(),Notype,yyvsp[-2],yyvsp[-1]);
				    for (p = yyvsp[-1];p;p=p->sibling){
					    p->type = yyvsp[-2]->type;
			    }
}
#line 1681 "src/main.tab.cpp"
    break;

  case 20:
#line 118 "src/main.y"
                                 {
        Node *p;
		yyval=parse_tree.NewRoot(DECL_NODE,CONST_DECL,NodeAttr(),Notype,yyvsp[-2],yyvsp[-1]);
		for (p = yyvsp[-1];p;p=p->sibling){
		    p->type = yyvsp[-2]->type;
}					
}
#line 1693 "src/main.tab.cpp"
    break;

  case 21:
#line 127 "src/main.y"
                                                    {yyval=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Integer);}
#line 1699 "src/main.tab.cpp"
    break;

  case 22:
#line 128 "src/main.y"
                                                {yyval=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Char);}
#line 1705 "src/main.tab.cpp"
    break;

  case 23:
#line 129 "src/main.y"
                                                {yyval=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Boolean);}
#line 1711 "src/main.tab.cpp"
    break;

  case 24:
#line 130 "src/main.y"
                                                {yyval=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Float);}
#line 1717 "src/main.tab.cpp"
    break;

  case 25:
#line 131 "src/main.y"
                                                {yyval=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),String);}
#line 1723 "src/main.tab.cpp"
    break;

  case 26:
#line 137 "src/main.y"
{
    Node* s =yyvsp[-2];
    if(s!=NULL){
        while (s->sibling!=NULL)
		    s=s->sibling;
		s->sibling = yyvsp[0];
		yyval = yyvsp[-2];
    }
    else 
	    yyval = yyvsp[0];
}
#line 1739 "src/main.tab.cpp"
    break;

  case 27:
#line 148 "src/main.y"
                        {yyval=yyvsp[0];}
#line 1745 "src/main.tab.cpp"
    break;

  case 28:
#line 152 "src/main.y"
       {yyval=yyvsp[0];}
#line 1751 "src/main.tab.cpp"
    break;

  case 29:
#line 153 "src/main.y"
                {yyval=yyvsp[0];}
#line 1757 "src/main.tab.cpp"
    break;

  case 30:
#line 158 "src/main.y"
{
    yyval=parse_tree.NewRoot(EXPR_NODE,ID_EXPR,NodeAttr(),Notype);
    yyval->attr.val.vals=yyvsp[0]->attr.val.vals;
    yyval->name=yyvsp[0]->name;
}
#line 1767 "src/main.tab.cpp"
    break;

  case 31:
#line 167 "src/main.y"
                                  {yyval=yyvsp[-1];}
#line 1773 "src/main.tab.cpp"
    break;

  case 32:
#line 172 "src/main.y"
                    {yyval = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, yyvsp[-2],yyvsp[0]);}
#line 1779 "src/main.tab.cpp"
    break;

  case 33:
#line 174 "src/main.y"
            {yyval = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype,yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 1785 "src/main.tab.cpp"
    break;

  case 34:
#line 176 "src/main.y"
                        {yyval = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, yyvsp[-2],yyvsp[0]);}
#line 1791 "src/main.tab.cpp"
    break;

  case 35:
#line 178 "src/main.y"
                        {yyval = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 1797 "src/main.tab.cpp"
    break;

  case 36:
#line 180 "src/main.y"
            {yyval = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 1803 "src/main.tab.cpp"
    break;

  case 37:
#line 185 "src/main.y"
            {  yyval = parse_tree.NewRoot(STMT_NODE,WHILE_STMT,NodeAttr(),Notype,yyvsp[-2],yyvsp[0]);}
#line 1809 "src/main.tab.cpp"
    break;

  case 38:
#line 190 "src/main.y"
            {  yyval = parse_tree.NewRoot(STMT_NODE,FOR_STMT,NodeAttr(),Notype,yyvsp[-6],yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 1815 "src/main.tab.cpp"
    break;

  case 39:
#line 192 "src/main.y"
            {  yyval = parse_tree.NewRoot(STMT_NODE,FOR_STMT,NodeAttr(),Notype,yyvsp[-5],yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 1821 "src/main.tab.cpp"
    break;

  case 40:
#line 196 "src/main.y"
                                                    {
    yyval = parse_tree.NewRoot(STMT_NODE,SCANF_STMT,NodeAttr(),Notype,yyvsp[-2]);
}
#line 1829 "src/main.tab.cpp"
    break;

  case 41:
#line 202 "src/main.y"
                                                    {
    yyval = parse_tree.NewRoot(STMT_NODE,PRINTF_STMT,NodeAttr(),Notype,yyvsp[-2]);
}
#line 1837 "src/main.tab.cpp"
    break;

  case 42:
#line 208 "src/main.y"
                                {
    yyval = parse_tree.NewRoot(STMT_NODE,RET_STMT,NodeAttr(),Notype,yyvsp[-1]);
}
#line 1845 "src/main.tab.cpp"
    break;

  case 43:
#line 213 "src/main.y"
                    {yyval=yyvsp[0];}
#line 1851 "src/main.tab.cpp"
    break;

  case 44:
#line 214 "src/main.y"
                                        {
        Node* p=yyvsp[-2];
        if(p!=NULL){
            while(p->sibling!=NULL)
                p=p->sibling;
            p->sibling=yyvsp[0];
            yyval=yyvsp[-2];
        }
        else 
            yyval=yyvsp[0];
}
#line 1867 "src/main.tab.cpp"
    break;

  case 45:
#line 228 "src/main.y"
                {yyval=yyvsp[0];}
#line 1873 "src/main.tab.cpp"
    break;

  case 46:
#line 229 "src/main.y"
              {yyval=yyvsp[0];}
#line 1879 "src/main.tab.cpp"
    break;

  case 47:
#line 230 "src/main.y"
                {yyval=yyvsp[0];}
#line 1885 "src/main.tab.cpp"
    break;

  case 48:
#line 231 "src/main.y"
            {
    yyval=parse_tree.NewRoot(STMT_NODE,ID_EXPR,NodeAttr(),Reference,yyvsp[0]);
}
#line 1893 "src/main.tab.cpp"
    break;

  case 49:
#line 237 "src/main.y"
                {
    yyval = parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),String);
	yyval->attr.val.vals=yyvsp[0]->attr.val.vals;
    yyval->str_seq=str_count++;
}
#line 1903 "src/main.tab.cpp"
    break;

  case 50:
#line 246 "src/main.y"
                    {yyval=yyvsp[0];}
#line 1909 "src/main.tab.cpp"
    break;

  case 51:
#line 247 "src/main.y"
                      {yyval=yyvsp[0];}
#line 1915 "src/main.tab.cpp"
    break;

  case 52:
#line 252 "src/main.y"
                                {yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_ASSIGN),Notype,yyvsp[-2],yyvsp[0]);}
#line 1921 "src/main.tab.cpp"
    break;

  case 53:
#line 254 "src/main.y"
                {yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_AEQ),Notype,yyvsp[-2],yyvsp[0]);}
#line 1927 "src/main.tab.cpp"
    break;

  case 54:
#line 256 "src/main.y"
                {yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_SEQ),Notype,yyvsp[-2],yyvsp[0]);}
#line 1933 "src/main.tab.cpp"
    break;

  case 55:
#line 258 "src/main.y"
                {yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_ASSIGN),Notype,yyvsp[-2],yyvsp[0]);}
#line 1939 "src/main.tab.cpp"
    break;

  case 56:
#line 264 "src/main.y"
                {yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_NOT),Notype,yyvsp[0]);}
#line 1945 "src/main.tab.cpp"
    break;

  case 57:
#line 265 "src/main.y"
                  {yyval=yyvsp[0];}
#line 1951 "src/main.tab.cpp"
    break;

  case 58:
#line 270 "src/main.y"
        {  yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_OR),Notype,yyvsp[-2],yyvsp[0]);}
#line 1957 "src/main.tab.cpp"
    break;

  case 59:
#line 271 "src/main.y"
                       { yyval = yyvsp[0]; }
#line 1963 "src/main.tab.cpp"
    break;

  case 60:
#line 276 "src/main.y"
        {  yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_AND),Notype,yyvsp[-2],yyvsp[0]);}
#line 1969 "src/main.tab.cpp"
    break;

  case 61:
#line 277 "src/main.y"
                       { yyval = yyvsp[0]; }
#line 1975 "src/main.tab.cpp"
    break;

  case 62:
#line 281 "src/main.y"
                            { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(GTR),Notype,yyvsp[-2],yyvsp[0]);}
#line 1981 "src/main.tab.cpp"
    break;

  case 63:
#line 282 "src/main.y"
                                { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LSS),Notype,yyvsp[-2],yyvsp[0]);}
#line 1987 "src/main.tab.cpp"
    break;

  case 64:
#line 283 "src/main.y"
                               { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(EQU),Notype,yyvsp[-2],yyvsp[0]);}
#line 1993 "src/main.tab.cpp"
    break;

  case 65:
#line 284 "src/main.y"
                                { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(NEQU),Notype,yyvsp[-2],yyvsp[0]);}
#line 1999 "src/main.tab.cpp"
    break;

  case 66:
#line 285 "src/main.y"
                            { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(GEQ),Notype,yyvsp[-2],yyvsp[0]);}
#line 2005 "src/main.tab.cpp"
    break;

  case 67:
#line 286 "src/main.y"
                                { yyval =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LEQ),Notype,yyvsp[-2],yyvsp[0]);}
#line 2011 "src/main.tab.cpp"
    break;

  case 68:
#line 287 "src/main.y"
                        {yyval=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Boolean);yyval->attr.val.valb=true;}
#line 2017 "src/main.tab.cpp"
    break;

  case 69:
#line 288 "src/main.y"
                        {yyval=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Boolean);yyval->attr.val.valb=false;}
#line 2023 "src/main.tab.cpp"
    break;

  case 70:
#line 289 "src/main.y"
                    {yyval=yyvsp[0];}
#line 2029 "src/main.tab.cpp"
    break;

  case 71:
#line 293 "src/main.y"
                                            { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_INC),Notype,yyvsp[-1]);}
#line 2035 "src/main.tab.cpp"
    break;

  case 72:
#line 294 "src/main.y"
                                        { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_DEC),Notype,yyvsp[-1]);}
#line 2041 "src/main.tab.cpp"
    break;

  case 73:
#line 295 "src/main.y"
                            { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_PLUS),Notype,yyvsp[-2],yyvsp[0]);}
#line 2047 "src/main.tab.cpp"
    break;

  case 74:
#line 296 "src/main.y"
                                { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MINUS),Notype,yyvsp[-2],yyvsp[0]);}
#line 2053 "src/main.tab.cpp"
    break;

  case 75:
#line 297 "src/main.y"
                                    {yyval=yyvsp[0];}
#line 2059 "src/main.tab.cpp"
    break;

  case 76:
#line 302 "src/main.y"
                                { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MUL),Notype,yyvsp[-2],yyvsp[0]);}
#line 2065 "src/main.tab.cpp"
    break;

  case 77:
#line 303 "src/main.y"
                        { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_DIV),Notype,yyvsp[-2],yyvsp[0]);}
#line 2071 "src/main.tab.cpp"
    break;

  case 78:
#line 304 "src/main.y"
                        { yyval = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MOD),Notype,yyvsp[-2],yyvsp[0]);}
#line 2077 "src/main.tab.cpp"
    break;

  case 79:
#line 305 "src/main.y"
                                {yyval=yyvsp[0];}
#line 2083 "src/main.tab.cpp"
    break;

  case 80:
#line 309 "src/main.y"
                                {yyval=yyvsp[-1];}
#line 2089 "src/main.tab.cpp"
    break;

  case 81:
#line 310 "src/main.y"
                {yyval=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Integer);
                    yyval->attr.val.vali=yyvsp[0]->attr.val.vali;}
#line 2096 "src/main.tab.cpp"
    break;

  case 82:
#line 312 "src/main.y"
        {yyval=yyvsp[0];}
#line 2102 "src/main.tab.cpp"
    break;

  case 83:
#line 313 "src/main.y"
                {yyval = parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Char);
					yyval->attr.val.valc=yyvsp[0]->attr.val.valc;
                    yyval->chr_seq=chr_count++;
                    }
#line 2111 "src/main.tab.cpp"
    break;

  case 84:
#line 317 "src/main.y"
              {yyval=yyvsp[0];
                yyval->type=Reference;
    }
#line 2119 "src/main.tab.cpp"
    break;

  case 85:
#line 320 "src/main.y"
                                {   
    			yyval=parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_UMINUS),Integer,yyvsp[0]);
                yyval->attr.val.vali=-yyvsp[0]->attr.val.vali;
}
#line 2128 "src/main.tab.cpp"
    break;


#line 2132 "src/main.tab.cpp"

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
#line 327 "src/main.y"



int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
