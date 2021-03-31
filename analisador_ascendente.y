%{
#include <stdio.h>
#include <ctype.h>
#include "lex.yy.c"

int yylex(void);
void yyerror(char *);
%}

%token INT FLO CHA BOO STR IF ELS FOR DO WHI RET STU FUN PRI REA LOA ZER IDE INV TRA EQU ID DIO LEQ LEO GEQ GRE APL AMI ADI AMU UAD USU OR VAR EOL

%left '+' '-'
%left '*' '/' '%'
%right '^'

%%

input: line 
    | input EOL line
    ;

line: /* empty */
    | expr
    ;

expr: INT
    | FLO
    | ID
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '^' expr
    | '(' expr ')'
    ;

%%

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

    printf("Finished!\n");
}