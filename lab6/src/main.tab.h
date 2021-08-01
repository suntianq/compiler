/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
