%{
#include <stdio.h>
#include <ctype.h>
#include "lex.yy.c"

int yylex(void);
void yyerror(char *);
%}

%token INT FLO CHA BOO STR IF ELS FOR DO WHI RET STU FUN PRI REA LOA ZER IDE INV TRA EQU ID DIO LEQ LEO GEQ GRE APL AMI ADI AMU UAD USU OR VAR '{' '}' '(' ')' '[' ']' 

%left '+' '-' '&' OR EQU DIO LEQ LEO GEQ GRE
%left '*' '/' '%' '!'
%right '^'

%%

Program: Definition Program
    |
    ;

Definition: Instantiation ';'
    | Struct 
    | Function
    ;

Struct: STU ID '{' Instantiations '}'
    ;

Instantiations: Instantiation ';' Instantiations
    |
    ;

Instantiation: VAR ID Matrix
    ;

Matrix: '[' INT ']' Matrix
    |
    ;

Function: FUN ID '(' Function_argument ')' Block
    | FUN ID '('  ')' Block
    ;

Function_argument: ID
    | ID ',' Function_argument
    ;

Block: '{' Statements '}'
    ;

Statements: Statement Statements
    |
    ;

Statement: Assign ';'
    | Return_expr
    | For_block
    | If_block
    | While_block
    | Function_call
    | Print
    ;

Assign: Assignment
    | Instantiation OptAssign
    ;

OptAssign: '=' Expression
    |
    ;

Assignment: ID Matrix '=' Expression
    | ID Matrix APL Expression
    | ID Matrix AMI Expression
    | ID Matrix ADI Expression
    | ID Matrix AMU Expression
    | ID Matrix '=' Matrix_line
    | ID Matrix APL Matrix_line
    | ID Matrix AMI Matrix_line
    | ID Matrix AMU Matrix_line
    | ID Matrix UAD
    | ID Matrix USU
    ;

Matrix_line: '[' Elements ']'

Elements: Element
    | Element ',' Elements
    ;

Element: Expression
    | Matrix_line
    ;

Return_expr: RET '(' Expression ')' ';'
    ;

For_block: FOR '(' Assign ';' Bool_Expression ';' Assignment ')' Block
    | FOR '('  ';' Bool_Expression ';' Assignment ')' Block
    ;

If_block: IF '(' Bool_Expression ')' Block Else_Block
    ;

Else_Block: ELS If_block
    | ELS Block
    |
    ;

While_block: WHI '(' Bool_Expression ')' Block
    ;

Function_call: ID '(' Arguments ')'
    ;

Arguments: Expression 
    | Expression ',' Arguments

Print: PRI '(' Expression ')'
    ;

Read: REA '(' ID ')'
    ;

Expression: INT
    | FLO
    | CHA
    | STR
    | Expression '+' Expression 
    | Expression '-' Expression 
    | Expression '*' Expression 
    | Expression '/' Expression 
    | Expression '^' Expression 
    | Expression EQU Expression
    | '-' Expression 
    | '+' Expression 
    | Expression '%' Expression 
    | '(' Expression ')'
    | Bool_Expression 
    | Read 
    ;

Bool_Expression: BOO
    | ID
    | Function_call
    | Bool_Expression OR Bool_Expression
    | Bool_Expression '&' Bool_Expression
    | '!' Bool_Expression
    | Bool_Expression DIO Bool_Expression
    | Bool_Expression LEQ Bool_Expression
    | Bool_Expression LEO Bool_Expression
    | Bool_Expression GEQ Bool_Expression
    | Bool_Expression GRE Bool_Expression
    ;

/*
Bool_Expression: TLog Expression1 
    ;

Expression1: OR TLog Expression1
    |
    ;

TLog: FLog TLog1
    ;

TLog1: '&' FLog TLog1 
    | 
    ;

FLog: '!' ERel 
    | ERel
    ;

ERel: LRel FLRel
    ;

FLRel: EQU LRel 
    |
    ; 

LRel: LERel FLERel
    ;

FLERel: LEO LERel 
    | 
    ;

LERel: GRel FGRel
    ;

FGRel: LEQ GRel 
    | 
    ;

GRel: GERel FGERel
    ;

FGERel: GRE GERel 
    |
    ;

GERel: DRel FDRel
    ;

FDRel: GEQ DRel 
    | 
    ;

DRel: AOp FAOp
    ;

FAOp: DIO AOp 
    | 
    ;

AOp: BOO
    | ID
    ;
*/

/*
Bool_Expression: BOO
    | ID
    | Function_call
    | Bool_Expression OR Bool_Expression
    | Bool_Expression '&' Bool_Expression
    | '!' Bool_Expression
    | Expression EQU Expression
    
    | Bool_Expression EQU Bool_Expression
    | Bool_Expression DIO Bool_Expression
    | Bool_Expression LEQ Bool_Expression
    | Bool_Expression LEO Bool_Expression
    | Bool_Expression GEQ Bool_Expression
    | Bool_Expression GRE Bool_Expression
    | '!' Bool_Expression
    | '(' Bool_Expression ')'
    | Expression '&' Expression
    | Expression OR Expression
    ;
*/

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