#include "tokens.h"

enum token tok;

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

int main( argc, argv )
int argc;
char **argv;
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