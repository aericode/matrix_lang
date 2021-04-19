%{
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

%}


%union{ 
    char val[1024];
};


%token  <val> INT <val> FLO <val> CHA <val> BOO <val> STR <val> IF <val> ELS <val> FOR <val> DO <val> WHI <val> RET <val> STU <val> FUN <val> PRI <val> REA <val> LOA <val> ZER <val> IDE <val> INV <val> TRA <val> EQU <val> ID <val> DIO <val> LEQ <val> LEO <val> GEQ <val> GRE <val> APL <val> AMI <val> ADI <val> AMU <val> UAD <val> USU <val> OR <val> VAR 
//%type <val> Expression //OptAssign Assign

%left '+' '-' '&' OR 
%nonassoc EQU DIO LEQ LEO GEQ GRE
%left '*' '/' '%' '!'
%right '^'

%%

First: {createFile();} Program

Program: Definition Program
    |
    ;

Definition: Instantiation ';' {addTokenToListAux(";\n");}
    | Struct 
    | Function
    ;

Struct: STU {addTokenToListAux("struct");} ID {addTokenToListAux($3);} '{' {addTokenToListAux("{");} Instantiations '}' {addTokenToListAux("}");}
    ;

Instantiations: Instantiation ';' {addTokenToListAux(";\n");}  Instantiations
    |
    ;

Instantiation: VAR {addTokenToListAux("auto");} ID {addTokenToListAux($3);} Matrix  //{printf("%c\n", sym[$2]);}
    ;

Matrix: '[' {addTokenToListAux("[");} Expression ']' {addTokenToListAux("]");} Matrix
    |
    ;

Function: FUN {addTokenToListAux("auto");} ID {addTokenToListAux($3);} '(' {addTokenToListAux("(");}  Function1 ')' {addTokenToListAux(")");}  Block
    ;

Function1: Function_argument
    |
    ;

Function_argument: ID {addTokenToListAux("void*");addTokenToListAux($1);}
    | ID {addTokenToListAux("void*");addTokenToListAux($1);} ',' {addTokenToListAux(",");} Function_argument
    ;

Block: '{' {addTokenToListAux("{\n");} Statements '}' {addTokenToListAux("}\n");}
    ;

Statements: Statement Statements
    |
    ;

Statement: Assign ';' {addTokenToListAux(";\n");}
    | Return_expr
    | For_block
    | If_block
    | While_block
    | Function_call ';' {addTokenToListAux(";\n");}
    | Print ';' {addTokenToListAux(";\n");}
    ;

Assign: Assignment
    | Instantiation OptAssign 
    ;

OptAssign: '=' {addTokenToListAux("=");} Expression 
    | '=' {addTokenToListAux("=");} Matrix_line
    |
    ;

Assignment: ID {addTokenToListAux($1);} Assignment1
    ;


Assignment1: Matrix '=' {addTokenToListAux("=");}  Expression 
    | Matrix APL {addTokenToListAux("+=");} Expression
    | Matrix AMI {addTokenToListAux("-=");} Expression
    | Matrix ADI {addTokenToListAux("/=");} Expression
    | Matrix AMU {addTokenToListAux("*=");} Expression
    | Matrix '=' {addTokenToListAux("=");} Matrix_line
    | Matrix APL {addTokenToListAux("+=");} Matrix_line
    | Matrix AMI {addTokenToListAux("-=");} Matrix_line
    | Matrix AMU {addTokenToListAux("*=");} Matrix_line
    | Matrix UAD {addTokenToListAux("++");}
    | Matrix USU {addTokenToListAux("--");}
    ;

Matrix_line: '[' {addTokenToListAux("{");} Elements ']' {addTokenToListAux("}");}

Elements: Element
    | Element ',' {addTokenToListAux(",");} Elements
    ;

Element: Expression
    | Matrix_line
    ;

Return_expr: RET {addTokenToListAux("return");} /*'(' {addTokenToListAux("(");}*/ Expression /*')' {addTokenToListAux(")");}*/ ';' {addTokenToListAux(";\n");}
    ;

For_block: FOR
'('  For_block1 ';' 
/*{
    addTokenToListAux(";\n");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "for%d:", aux);
    addTokenToListAux(gotoblk);

    addTokenToListAux("if");
    addTokenToListAux("(!(");
}*/
Expression 
/*{
    addTokenToListAux("))");
    addTokenToListAux("goto");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "end%d;\n", aux);
    push(&root, aux++);
    addTokenToListAux(gotoblk);
}*/
';'  Assignment ')'  Block_FOR_Aux
    ;


Block_FOR_Aux: '{' Statements '}'
    ;

/*Assignment_FOR: ID Assignment1_FOR
    ;

Assignment1_FOR: Matrix '=' Expression 
    | Matrix APL Expression
    | Matrix AMI Expression
    | Matrix ADI Expression
    | Matrix AMU Expression
    | Matrix '=' Matrix_line
    | Matrix APL Matrix_line
    | Matrix AMI Matrix_line
    | Matrix AMU Matrix_line
    | Matrix UAD 
    | Matrix USU 
    ;*/

For_block1: Assign
    |
    ;

If_block: IF
{
    addTokenToListAux("if");
    addTokenToListAux("(!(");
}
'('  Expression ')' 

{
    addTokenToListAux("))");
    addTokenToListAux("goto");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "else%d;\n", aux);
    push(&root, aux++);
    addTokenToListAux(gotoblk);
}
                    
 /*Block*/ Block_If_Aux Else_Block 
    ;

Block_If_Aux: '{' Statements '}'
    ;

Else_Block: ELS 
{
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
}
            If_block {addTokenToListAux("}\n");}
    | ELS 
{
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
}
    Block_If_Aux {addTokenToListAux("}\n");} 
    |
{  
    char * gotoblk = malloc(1024);
    int n = pop(&root);
    sprintf(gotoblk, "else%d:", n);
    addTokenToListAux(gotoblk);
    addTokenToListAux("{\n");
    addTokenToListAux("}\n");
}
    ;

While_block: WHI 
{
    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "while%d:", aux);
    addTokenToListAux(gotoblk);
} '(' 
{
    addTokenToListAux("if(!(");
}
             Expression ')' {
    addTokenToListAux("))");
    addTokenToListAux("goto");

    char * gotoblk = malloc(1024);
    sprintf(gotoblk, "end%d;\n", aux);
    push(&root, aux++);
    addTokenToListAux(gotoblk);

    //addTokenToListAux("end;\n");

}
    Block_While_aux
    //Block
    ;

Block_While_aux: '{'  Statements '}' 
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
    ;

Function_call: ID {addTokenToListAux($1);} '(' {addTokenToListAux("(");} Function_call1 ')' {addTokenToListAux(")");}
    ;

Function_call1: Arguments 
    |
    ;

Arguments: Expression 
    | Expression ',' {addTokenToListAux(",");} Arguments

Print: PRI {addTokenToListAux("printf");} '(' {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");};

Read: REA '('  STR  ')' 
{
    addTokenToListAux("read");
    addTokenToListAux("(");
    addTokenToListAux($3);
    addTokenToListAux(")");
}
    ;

Expression: INT                     {addTokenToListAux($1);}//*/ /*{sprintf($$, "%s", $1);}*/
    | FLO                           {addTokenToListAux($1);}
    | CHA                           {addTokenToListAux($1);}
    | STR                           {addTokenToListAux($1);}//{sprintf($$, "%s", $1);}
    | Expression '+'                {addTokenToListAux("+");}  Expression       //{sprintf($$, "%d", atoi($1) + atoi($3));}
    | Expression '-'                {addTokenToListAux("-");}  Expression       //{sprintf($$, "%d", atoi($1) - atoi($3));}
    | Expression '*'                {addTokenToListAux("*");}  Expression       //{$$ = $1 * $3;}
    | Expression '/'                {addTokenToListAux("/");}  Expression       //{$$ = $1 / $3;}
    | Expression '^'                {addTokenToListAux("^");}  Expression       //{$$ = $1 + $3;}
    | Expression EQU                {addTokenToListAux("==");} Expression
    | '-'                           {addTokenToListAux("-");}  Expression                //{sprintf($$, "%d",-atoi($2));}
    | '+'                           {addTokenToListAux("+");}  Expression                //{sprintf($$, "%d",atoi($2));}
    | Expression '%'                {addTokenToListAux("%");} Expression 
    | '('                           {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");}
    | Read
    | BOO                           {addTokenToListAux($1);}
    | Function_call
    | ID                            {addTokenToListAux($1);}
    | Expression OR                 {addTokenToListAux("||");} Expression
    | Expression '&'                {addTokenToListAux("&");} Expression
    | '!'                           {addTokenToListAux("!");} Expression
    | Expression DIO                {addTokenToListAux("!=");} Expression     //{$$ = $1 != $3;}
    | Expression LEQ                {addTokenToListAux("<=");} Expression     //{$$ = $1 <= $3;}
    | Expression LEO                {addTokenToListAux("<");} Expression     //{$$ = $1 < $3;}
    | Expression GEQ                {addTokenToListAux(">=");} Expression     //{$$ = $1 >= $3;}
    | Expression GRE                {addTokenToListAux(">");} Expression     //{$$ = $1 > $3;}
    | IDE {addTokenToListAux("identity");} '(' {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");}
    | INV {addTokenToListAux("inverse");} '(' {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");}
    | TRA {addTokenToListAux("transposed");} '(' {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");}
    | ZER {addTokenToListAux("zero");} '(' {addTokenToListAux("(");} Expression ')' {addTokenToListAux(")");}
    | ID {addTokenToListAux("&");addTokenToListAux($1);} '[' {addTokenToListAux("[");addTokenToListAux("(int)");} Expression ']' {addTokenToListAux("]");}
    ;


%%

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