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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALISADOR_ASCENDENTE_TAB_H_INCLUDED  */
