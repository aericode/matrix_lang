%{
#include <math.h>

int offset = 1;
%}

%option yylineno

DIGIT      [0-9]
ID         [a-zA-Z][a-zA-Z0-9\_]*
CHARACTER  \'.\'
BOOLEAN    true|false
STRING     \".*\"

%%

{DIGIT}+            { printf( "%d %d INTEGER: %d\n", yylineno, offset, atoi( yytext )); offset += yyleng; }
{DIGIT}+"."{DIGIT}* { printf( "%d %d FLOAT: %f\n", yylineno, offset, atof( yytext )); offset += yyleng; }
{CHARACTER}         { printf( "%d %d CHARACTER: %s\n", yylineno, offset, yytext ); offset += yyleng; }
{BOOLEAN}           { printf( "%d %d BOOLEAN: %s\n", yylineno, offset, yytext ); offset += yyleng; }
{STRING}            { printf( "%d %d STRING: %s\n", yylineno, offset, yytext ); offset += yyleng; }

if         { printf( "%d %d MAIN: %s\n", yylineno, offset, yytext); offset += yyleng; }
for        { printf( "%d %d FOR: %s\n", yylineno, offset, yytext); offset += yyleng; }
do         { printf( "%d %d DO: %s\n", yylineno, offset, yytext); offset += yyleng; }
while      { printf( "%d %d WHILE: %s\n", yylineno, offset, yytext); offset += yyleng; }
return     { printf( "%d %d RETURN: %s\n", yylineno, offset, yytext); offset += yyleng; }
fun        { printf( "%d %d FUN: %s\n", yylineno, offset, yytext); offset += yyleng; }
main       { printf( "%d %d MAIN: %s\n", yylineno, offset, yytext); offset += yyleng; }
print      { printf( "%d %d PRINT: %s\n", yylineno, offset, yytext); offset += yyleng; }
read       { printf( "%d %d READ: %s\n", yylineno, offset, yytext); offset += yyleng; }
load       { printf( "%d %d LOAD: %s\n", yylineno, offset, yytext); offset += yyleng; }
zero       { printf( "%d %d ZERO: %s\n", yylineno, offset, yytext); offset += yyleng; }
identity   { printf( "%d %d IDENTITY: %s\n", yylineno, offset, yytext); offset += yyleng; }
inverse    { printf( "%d %d INVERSE: %s\n", yylineno, offset, yytext); offset += yyleng; }
transposed { printf( "%d %d TRANSPOSED: %s\n", yylineno, offset, yytext); offset += yyleng; }

{ID}   { printf( "%d %d ID: %s\n", yylineno, offset, yytext ); offset += yyleng; }

"("    { printf( "%d %d OPENING_PARENTHESIS: %s\n", yylineno, offset, yytext); offset += yyleng; }
")"    { printf( "%d %d CLOSING_PARENTHESIS: %s\n", yylineno, offset, yytext); offset += yyleng; }

"{"    { printf( "%d %d OPENING_BRACES: %s\n", yylineno, offset, yytext); offset += yyleng; }
"}"    { printf( "%d %d CLOSING_BRACES: %s\n", yylineno, offset, yytext); offset += yyleng; }

"["    { printf( "%d %d OPENING_SQUARE_BRACKET: %s\n", yylineno, offset, yytext); offset += yyleng; }
"]"    { printf( "%d %d CLOSING_SQUARE_BRACKET: %s\n", yylineno, offset, yytext); offset += yyleng; }

"="    { printf( "%d %d ASSIGN_OPERATOR: %s\n", yylineno, offset, yytext); offset += yyleng; }
"+="   { printf( "%d %d ASSING_PLUS_OPERATOR: %s\n", yylineno, offset, yytext); offset += yyleng; }
"-="   { printf( "%d %d ASSING_MINUS_OPERATOR: %s\n", yylineno, offset, yytext); offset += yyleng; }

"+"    { printf( "%d %d ADDITION: %s\n", yylineno, offset, yytext); offset += yyleng; }
"-"    { printf( "%d %d SUBTRACTION: %s\n", yylineno, offset, yytext); offset += yyleng; }
"*"    { printf( "%d %d MULTIPLICATION: %s\n", yylineno, offset, yytext); offset += yyleng; }
"/"    { printf( "%d %d DIVISION: %s\n", yylineno, offset, yytext); offset += yyleng; }
"%"    { printf( "%d %d MODULUS: %s\n", yylineno, offset, yytext); offset += yyleng; }

";"    { printf( "%d %d SEMICOLON: %s\n", yylineno, offset, yytext ); offset += yyleng; }

[\n]+  offset = 1;

"//".*             /* one-line comments */

[ \t\n]+          /* whitespace */

.      { printf( "%d %d Unrecognized character: %s\n", yylineno, offset, yytext ); offset += yyleng; }

%%

int main( argc, argv )
int argc;
char **argv;
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
}