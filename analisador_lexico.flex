%{
#include <math.h>
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

{DIGIT}+            { offset += yyleng; return INT; }
{DIGIT}+"."{DIGIT}* { offset += yyleng; return FLO; }
{CHARACTER}         { offset += yyleng; return CHA; }
{BOOLEAN}           { offset += yyleng; return BOO; }
{STRING}            { offset += yyleng; return STR; }

var        { offset += yyleng; return VAR; }
if         { offset += yyleng; return IF; }
else       { offset += yyleng; return ELS; }
for        { offset += yyleng; return FOR; }
do         { offset += yyleng; return DO; }
while      { offset += yyleng; return WHI; }
return     { offset += yyleng; return RET; }
struct     { offset += yyleng; return STU; }
fun        { offset += yyleng; return FUN; }
print      { offset += yyleng; return PRI; }
read       { offset += yyleng; return REA; }
load       { offset += yyleng; return LOA; }
zero       { offset += yyleng; return ZER; }
identity   { offset += yyleng; return IDE; }
inverse    { offset += yyleng; return INV; }
transposed { offset += yyleng; return TRA; }

{ID}   { offset += yyleng; return ID; }

"("    { offset += yyleng; return '('; }
")"    { offset += yyleng; return ')'; }

"{"    { offset += yyleng; return '{'; }
"}"    { offset += yyleng; return '}'; }

"["    { offset += yyleng; return '['; }
"]"    { offset += yyleng; return ']'; }

"=="   { offset += yyleng; return EQU; }
"!="   { offset += yyleng; return DIO; }
"<="   { offset += yyleng; return LEQ; }
"<"    { offset += yyleng; return LEO; }
">="   { offset += yyleng; return GEQ; }
">"    { offset += yyleng; return GRE; }

"="    { offset += yyleng; return '='; }
"+="   { offset += yyleng; return APL; }
"-="   { offset += yyleng; return AMI; }
"/="   { offset += yyleng; return ADI; }
"*="   { offset += yyleng; return AMU; }

"++"   { offset += yyleng; return UAD; }
"--"   { offset += yyleng; return USU; }

"&"    { offset += yyleng; return '&'; }
"!"    { offset += yyleng; return '!'; }
"||"    { offset += yyleng; return OR; }

"+"    { offset += yyleng; return '+'; }
"-"    { offset += yyleng; return '-'; }
"*"    { offset += yyleng; return '*'; }
"/"    { offset += yyleng; return '/'; }
"%"    { offset += yyleng; return '%'; }
"^"    { offset += yyleng; return '^'; }

","    { offset += yyleng; return ','; }
";"    { offset += yyleng; return ';'; }
"."    { offset += yyleng; return '.'; }

\n      { offset = 1; }

"//".*   /* one-line comments */

[ \t]+  { offset += yyleng; }

<<EOF>> { offset += yyleng; return EOF; }

.       { printf( "%d %d Lexical error: %s\n", yylineno, offset, yytext ); offset += yyleng; }

%%
