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

Definition: Instantiation ';' { printf("; (%d %d)\n", yylineno, offset ); }
    | Struct 
    | Function
    ;

Struct: STU { printf("STRUCT (%d %d)\n", yylineno, offset ); } ID { printf("ID (%d %d)\n", yylineno, offset ); } '{' { printf("{ (%d %d)\n", yylineno, offset ); } Instantiations '}' { printf("} (%d %d)\n", yylineno, offset ); }
    ;

Instantiations: Instantiation ';' { printf("; (%d %d)\n", yylineno, offset ); } Instantiations
    |
    ;

Instantiation: VAR { printf("VAR (%d %d)\n", yylineno, offset ); } ID { printf("ID (%d %d)\n", yylineno, offset ); } Matrix
    ;

Matrix: '[' { printf("[ (%d %d)\n", yylineno, offset ); } Expression ']' { printf("] (%d %d)\n", yylineno, offset ); } Matrix
    |
    ;

Function: FUN { printf("FUNCTION (%d %d)\n", yylineno, offset ); } ID { printf("ID (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Function1 ')' { printf(") (%d %d)\n", yylineno, offset ); } Block
    ;

Function1: Function_argument
    |
    ;

Function_argument: ID { printf("ID (%d %d)\n", yylineno, offset ); }
    | ID { printf("ID (%d %d)\n", yylineno, offset ); } ',' Function_argument
    ;

Block: '{' { printf("{ (%d %d)\n", yylineno, offset ); } Statements '}' { printf("} (%d %d)\n", yylineno, offset ); }
    ;

Statements: Statement Statements
    |
    ;

Statement: Assign ';' { printf("; (%d %d)\n", yylineno, offset ); }
    | Return_expr
    | For_block
    | If_block
    | While_block
    | Function_call ';' { printf("; (%d %d)\n", yylineno, offset ); }
    | Print ';' { printf("; (%d %d)\n", yylineno, offset ); }
    ;

Assign: Assignment
    | Instantiation OptAssign
    ;

OptAssign: '=' { printf("= (%d %d)\n", yylineno, offset ); } Expression
    | '=' { printf("= (%d %d)\n", yylineno, offset ); } Matrix_line
    |
    ;

Assignment: ID { printf("ID (%d %d)\n", yylineno, offset ); } Assignment1
    ;


Assignment1: Matrix '=' { printf("= (%d %d)\n", yylineno, offset ); } Expression
    | Matrix APL { printf("+= (%d %d)\n", yylineno, offset ); } Expression
    | Matrix AMI { printf("-= (%d %d)\n", yylineno, offset ); } Expression
    | Matrix ADI { printf("/= (%d %d)\n", yylineno, offset ); } Expression
    | Matrix AMU { printf("*= (%d %d)\n", yylineno, offset ); } Expression
    | Matrix '=' { printf("= (%d %d)\n", yylineno, offset ); } Matrix_line
    | Matrix APL { printf("+= (%d %d)\n", yylineno, offset ); } Matrix_line
    | Matrix AMI { printf("-= (%d %d)\n", yylineno, offset ); } Matrix_line
    | Matrix AMU { printf("*= (%d %d)\n", yylineno, offset ); } Matrix_line
    | Matrix UAD { printf("++ (%d %d)\n", yylineno, offset ); }
    | Matrix USU { printf("-- (%d %d)\n", yylineno, offset ); }
    ;

Matrix_line: '[' { printf("[ (%d %d)\n", yylineno, offset ); } Elements ']' { printf("] (%d %d)\n", yylineno, offset ); }

Elements: Element
    | Element ',' { printf(", (%d %d)\n", yylineno, offset ); } Elements
    ;

Element: Expression
    | Matrix_line
    ;

Return_expr: RET { printf("RETURN (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); } ';' { printf("; (%d %d)\n", yylineno, offset ); }
    ;

For_block: FOR { printf("FOR (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } For_block1 ';' { printf("; (%d %d)\n", yylineno, offset ); } Expression ';' { printf("; (%d %d)\n", yylineno, offset ); } Assignment ')' { printf(") (%d %d)\n", yylineno, offset ); } Block
    ;

For_block1: Assign
    |
    ;

If_block: IF { printf("IF (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); } Block Else_Block
    ;

Else_Block: ELS { printf("ELSE (%d %d)\n", yylineno, offset ); } If_block
    | ELS { printf("ELSE (%d %d)\n", yylineno, offset ); } Block
    |
    ;

While_block: WHI { printf("WHILE (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); } Block
    ;

Function_call: ID { printf("ID (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Function_call1 ')' { printf(") (%d %d)\n", yylineno, offset ); }
    ;

Function_call1: Arguments 
    |
    ;

Arguments: Expression 
    | Expression ',' { printf(", (%d %d)\n", yylineno, offset ); } Arguments

Print: PRI { printf("PRINT (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    ;

Read: REA { printf("READ (%d %d)\n", yylineno, offset ); } '(' { printf("( (%d %d)\n", yylineno, offset ); } STR { printf("STRING (%d %d)\n", yylineno, offset ); } ')' { printf(") (%d %d)\n", yylineno, offset ); }
    ;

Expression: INT { printf("INT (%d %d)\n", yylineno, offset ); }
    | FLO { printf("FLOAT (%d %d)\n", yylineno, offset ); }
    | CHA { printf("CHAR (%d %d)\n", yylineno, offset ); }
    | STR { printf("STRING (%d %d)\n", yylineno, offset ); }
    | Expression '+' { printf("+ (%d %d)\n", yylineno, offset ); } Expression 
    | Expression '-' { printf("- (%d %d)\n", yylineno, offset ); } Expression 
    | Expression '*' { printf("* (%d %d)\n", yylineno, offset ); } Expression 
    | Expression '/' { printf("/ (%d %d)\n", yylineno, offset ); } Expression 
    | Expression '^' { printf("^ (%d %d)\n", yylineno, offset ); } Expression 
    | Expression EQU Expression
    | '-' { printf("- (%d %d)\n", yylineno, offset ); } Expression 
    | '+' { printf("+ (%d %d)\n", yylineno, offset ); } Expression 
    | Expression '%' { printf("MOD (%d %d)\n", yylineno, offset ); } Expression 
    | '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    /* | Bool_Expression */
    | Read 
    | BOO { printf("BOOLEAN (%d %d)\n", yylineno, offset ); }
    | Function_call 
    | ID { printf("ID (%d %d)\n", yylineno, offset ); }
    | Expression OR { printf("OR (%d %d)\n", yylineno, offset ); } Expression
    | Expression '&' { printf("AND (%d %d)\n", yylineno, offset ); } Expression
    | '!' { printf("! (%d %d)\n", yylineno, offset ); } Expression
    | Expression DIO { printf("!= (%d %d)\n", yylineno, offset ); } Expression
    | Expression LEQ { printf("<= (%d %d)\n", yylineno, offset ); } Expression
    | Expression LEO { printf("< (%d %d)\n", yylineno, offset ); } Expression
    | Expression GEQ { printf(">= (%d %d)\n", yylineno, offset ); } Expression
    | Expression GRE { printf("< (%d %d)\n", yylineno, offset ); } Expression
    | IDE '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    | INV '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    | TRA '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    | ZER '(' { printf("( (%d %d)\n", yylineno, offset ); } Expression ')' { printf(") (%d %d)\n", yylineno, offset ); }
    | ID '[' { printf("[ (%d %d)\n", yylineno, offset ); } Expression ']' { printf("] (%d %d)\n", yylineno, offset ); }
    ;
/*
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
*/
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