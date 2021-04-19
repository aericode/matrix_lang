%{
#include <math.h>
#include "test.h"
#include "analisador_ascendente.tab.h"

int offset = 1;
%}

%option noyywrap
%option yylineno

DIGIT      [0-9]
ID         [a-zA-Z][a-zA-Z0-9\_]*
CHARACTER  \'.\'
BOOLEAN    true|false
STRING     \".*\"

%%

{DIGIT}+            { offset += yyleng; strcpy(yylval.val, yytext); return INT; }
{DIGIT}+"."{DIGIT}* { offset += yyleng; strcpy(yylval.val, yytext); return FLO; }
{CHARACTER}         { offset += yyleng; strcpy(yylval.val, yytext); return CHA; }
{BOOLEAN}           { offset += yyleng; strcpy(yylval.val, yytext); return BOO; }
{STRING}            { offset += yyleng; strcpy(yylval.val, yytext); return STR; }

var        { offset += yyleng; strcpy(yylval.val, yytext); return VAR; }
if         { offset += yyleng; strcpy(yylval.val, yytext); return IF; }
else       { offset += yyleng; strcpy(yylval.val, yytext); return ELS; }
for        { offset += yyleng; strcpy(yylval.val, yytext); return FOR; }
do         { offset += yyleng; strcpy(yylval.val, yytext); return DO; }
while      { offset += yyleng; strcpy(yylval.val, yytext); return WHI; }
return     { offset += yyleng; strcpy(yylval.val, yytext); return RET; }
struct     { offset += yyleng; strcpy(yylval.val, yytext); return STU; }
fun        { offset += yyleng; strcpy(yylval.val, yytext); return FUN; }
print      { offset += yyleng; strcpy(yylval.val, yytext); return PRI; }
read       { offset += yyleng; strcpy(yylval.val, yytext); return REA; }
load       { offset += yyleng; strcpy(yylval.val, yytext); return LOA; }
zero       { offset += yyleng; strcpy(yylval.val, yytext); return ZER; }
identity   { offset += yyleng; strcpy(yylval.val, yytext); return IDE; }
inverse    { offset += yyleng; strcpy(yylval.val, yytext); return INV; }
transposed { offset += yyleng; strcpy(yylval.val, yytext); return TRA; }

{ID}   { offset += yyleng; strcpy(yylval.val, yytext); return ID; }

"("    { offset += yyleng; strcpy(yylval.val, yytext); return '('; }
")"    { offset += yyleng; strcpy(yylval.val, yytext); return ')'; }

"{"    { offset += yyleng; strcpy(yylval.val, yytext); return '{'; }
"}"    { offset += yyleng; strcpy(yylval.val, yytext); return '}'; }

"["    { offset += yyleng; strcpy(yylval.val, yytext); return '['; }
"]"    { offset += yyleng; strcpy(yylval.val, yytext); return ']'; }

"=="   { offset += yyleng; strcpy(yylval.val, yytext); return EQU; }
"!="   { offset += yyleng; strcpy(yylval.val, yytext); return DIO; }
"<="   { offset += yyleng; strcpy(yylval.val, yytext); return LEQ; }
"<"    { offset += yyleng; strcpy(yylval.val, yytext); return LEO; }
">="   { offset += yyleng; strcpy(yylval.val, yytext); return GEQ; }
">"    { offset += yyleng; strcpy(yylval.val, yytext); return GRE; }

"="    { offset += yyleng; strcpy(yylval.val, yytext); return '='; }
"+="   { offset += yyleng; strcpy(yylval.val, yytext); return APL; }
"-="   { offset += yyleng; strcpy(yylval.val, yytext); return AMI; }
"/="   { offset += yyleng; strcpy(yylval.val, yytext); return ADI; }
"*="   { offset += yyleng; strcpy(yylval.val, yytext); return AMU; }

"++"   { offset += yyleng; strcpy(yylval.val, yytext); return UAD; }
"--"   { offset += yyleng; strcpy(yylval.val, yytext); return USU; }

"&"    { offset += yyleng; strcpy(yylval.val, yytext); return '&'; }
"!"    { offset += yyleng; strcpy(yylval.val, yytext); return '!'; }
"||"    { offset += yyleng; strcpy(yylval.val, yytext); return OR; }

"+"    { offset += yyleng; strcpy(yylval.val, yytext); return '+'; }
"-"    { offset += yyleng; strcpy(yylval.val, yytext); return '-'; }
"*"    { offset += yyleng; strcpy(yylval.val, yytext); return '*'; }
"/"    { offset += yyleng; strcpy(yylval.val, yytext); return '/'; }
"%"    { offset += yyleng; strcpy(yylval.val, yytext); return '%'; }
"^"    { offset += yyleng; strcpy(yylval.val, yytext); return '^'; }

","    { offset += yyleng; strcpy(yylval.val, yytext); return ','; }
";"    { offset += yyleng; strcpy(yylval.val, yytext); return ';'; }
"."    { offset += yyleng; strcpy(yylval.val, yytext); return '.'; }

\n      { offset = 1; }

"//".*   /* one-line comments */

[ \t]+  { offset += yyleng; }

<<EOF>> { offset += yyleng; strcpy(yylval.val, yytext); return EOF; }

.       { printf( "%d %d Lexical error: %s\n", yylineno, offset, yytext ); offset += yyleng; }

%%
