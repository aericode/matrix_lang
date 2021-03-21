#include "lex.yy.c"
#include "grammar.h"

enum token tok;

/*
void F2() {
    switch(tok) {
        case EOL: eat(EOL); break;
        default: Instanciations();
    }
}

void FInstanciation() {
    eat(";"); F2();
}

void Matrix() {

}

void Instantiation() {
    switch(tok) {
        case VAR: eat(VAR); eat(ID); Matrix(); eat(";"); break;
        default: error();
    }
}

void Instantiations() {
    switch(tok) {
        case VAR: eat(VAR); eat(ID); eat(";"); break;
        default: error();
    }
}

void Definitions() {
    switch(tok) {
        case STU: eat(STU); eat(ID); eat("{"); Instantiations(); eat("}"); Definitions(); break;
        case FUN: eat(FUN); eat(ID); eat("("); Function1(); eat(")"); Block(); Definitions(); break;
        case VAR: eat(VAR); eat(ID); eat(";"); Definitions(); break;
        case EOF: eat(EOF); break;
    }
}

void Program() {
    switch(tok) {
        case STU: eat(STU); eat(ID); eat("{"); Instantiations(); eat("}"); Definitions(); break;
        case FUN: eat(FUN); eat(ID); eat("("); Function1(); eat(")"); Block(); Definitions(); break;
        case VAR: eat(VAR); eat(ID); eat(";"); Definitions(); break;
    }
}

void advance() {
    tok = yylex();
}

void eat(enum token t) {
    if (tok==t) advance() else error();
}
*/

void eat(enum token);
void Fid_token();

void error(){
    printf("Error (%d %d)\n", yylineno, offset );
}

void advance() {
    tok = (token) yylex();
    if(tok == EOL) eat(tok);
}

void eat(enum token t) {
    if (tok==t) advance(); else {printf("%d\n", tok); printf("%d\n",t ); error();};
}

void Dim(){
    switch(tok) {
        case (token) ';': break;
        case (token) '[': eat((token) '['); Expression(); eat((token) ']'); Dim(); break;
        default : printf("%d\n", tok ); printf("Expected var \n");
    }
}

void Matrix(){
    switch(tok) {
        case (token) ';': break;
        case (token) '[': eat((token) '['); Expression(); eat((token) ']'); Dim(); break;
        default : printf("%d\n", tok ); printf("Expected var \n");
    }
}

void Instantiation(){
    switch(tok) {
        case VAR: eat(VAR); eat(ID); Matrix(); break;
        default : printf("%d\n", tok ); printf("Expected var \n");
    }    
}

void Instantiations(){
    switch(tok) {
        case VAR: Instantiation() ; eat((token)';'); Instantiations(); break;
        case (token)'}': break;
        default : printf("%d\n", tok ); printf("Expected var \n");
    }    
}

void Struct(){
    switch(tok){
        case STU: eat(STU); eat(ID); eat((token)'{'); Instantiations(); eat((token)'}') ; break; 
        default : printf("%d\n", tok ); printf("Expected struct id { inst } \n");
    }
}

void Function_argument(){
    switch(tok) {
        case ID: eat(ID); Fid_token(); break;
        default : printf("%d\n", tok ); printf("Expected fun!\n");
    }
}

void Fid_token(){
    switch(tok) {
        case (token) ',': eat((token) ','); Function_argument(); break;
        case (token) ')':  break;
        default : printf("%d\n", tok ); printf("Expected , )!\n");
    }
}

void Function1(){
    switch(tok) {
        case (token) ')':  break;
        case ID: Function_argument(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Expression(){
    switch(tok) {
        case ID: eat(ID); break;
        case INT: eat(INT); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Return(){
    switch(tok) {
        case RET: eat(RET); eat((token)'('); Expression(); eat((token)')'); eat((token) ';'); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}


void Print(){
    switch(tok) {
        case PRI: eat(PRI); eat((token)'('); Expression(); eat((token)')'); eat((token) ';'); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Read(){
    switch(tok) {
        case REA: eat(REA); eat((token)'('); eat(ID); eat((token)')'); eat((token) ';'); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Fassign(){
    switch(tok) {
        case ID: Expression(); break;
        case INT: Expression(); break;
    }
}

void FExpression(){
    switch(tok) {
        case (token) ',': eat((token)',') ; Arguments(); break;
        case (token) ')': break;
    }    
}

void Arguments(){
    switch(tok) {
        case ID: Expression(); FExpression(); break;
        case INT: Expression(); FExpression(); break;
    }
}

void Fid_token1(){
    switch(tok) {
        case (token)'=':  eat((token)'='); Fassign(); break;
        case (token)'-':  eat((token)'-'); eat((token)'=') ; Fassign(); break;
        case (token)'+':  eat((token)'+'); eat((token)'=') ; Fassign(); break;
        case (token)'*':  eat((token)'*'); eat((token)'=') ; Fassign(); break;
        case (token)'/':  eat((token)'/'); eat((token)'=') ; Expression(); break;
        case UAD: eat(UAD); break;
        case USU: eat(USU); break;
        case (token)'(':  eat((token)'('); Arguments() ; eat((token) ')'); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Assignment(){
    switch(tok) {
        case ID:  eat(ID); Fid_token1(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Assign1(){
    switch(tok) {
        case ID: Assignment(); break;
        case VAR: Instantiation(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Assign(){
    switch(tok) {
        case ID: Assign1(); eat((token) ';'); break;
        case VAR: Assign1(); eat((token) ';'); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void If_block(){
    switch(tok) {
        case IF: eat(IF); eat((token)'('); Expression(); eat((token)')'); Block(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void F1(){
    switch(tok) {
        case ID: Assignment() ; eat((token)';') ; Expression() ; eat((token)';') ; Assignment() ; eat((token)')') ; Block(); break;
        case (token) ';': eat((token)';') ; Expression() ; eat((token)';') ; Assignment() ; eat((token)')') ; Block(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Ffor(){
    switch(tok) {
        case (token) '(': eat((token) '('); F1(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void For_block(){
    switch(tok) {
        case FOR: eat(FOR); Ffor(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void While_block(){
    switch(tok) {
        case WHI: eat(WHI); eat((token) '('); Expression(); eat((token) ')'); Block(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}


void Statement(){
    switch(tok) {
        case REA: Read(); break;
        case PRI: Print(); break;
        case RET: Return(); break;
        case ID: Assign(); break;
        case VAR: Assign(); break;
        case IF: If_block(); break;
        case FOR: For_block(); break;
        case WHI: While_block(); break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Statements(){
    switch(tok) {
        case REA: Statement(); Statements() ; break;
        case PRI: Statement(); Statements() ; break;
        case RET: Statement(); Statements() ; break;
        case ID:  Statement(); Statements() ; break;
        case VAR: Statement(); Statements() ; break;
        case IF:  Statement(); Statements() ; break;
        case FOR: Statement(); Statements() ; break;
        case WHI: Statement(); Statements() ; break;
        case (token) '}': break;
        default : printf("%d\n", tok ); printf("Expected ID )!\n");
    }
}

void Block(){
    switch(tok) {
        case (token) '{': eat((token) '{'); Statements(); eat((token)'}'); break;
        default : printf("%d\n", tok ); printf("{!\n");
    }
}

void Function(){
    switch(tok) {
        case FUN: eat(FUN); eat(ID); eat((token)'('); Function1(); eat((token)')'); Block(); break;
        default : printf("%d\n", tok ); printf("Expected fun!\n");
    }
}

void Definition(){
    switch(tok) {
        case VAR: Instantiation(); eat((token)';'); break;
        case STU: Struct(); break;
        case FUN: Function(); break;
        default : printf("%d\n", tok ); printf("Expected var!\n");
    }
}

void Program() {
    switch(tok) {
        case VAR: Definition(); Program(); break;
        case STU: Definition(); Program(); break;
        case FUN: Definition(); Program(); break;
        case EOFF: break;
        default:  printf("%d\n", tok ); printf("Expected var.\n");
    }
}

int main( int argc, char **argv )
{
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 ) {
        yyin = fopen( argv[0], "r" );
    } else {
        yyin = stdin;
    }

    advance();
    Program();
}