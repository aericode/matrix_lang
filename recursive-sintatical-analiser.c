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

void Instanciation() {
    eat(VAR); eat(ID); Matrix();
}

void Instanciations() {
    Instanciation(); FInstanciation();
}

void Definition() {
    switch(tok) {
        case STU: eat(STU); eat(ID); eat("{"); Instantiations(); eat("}"); Definition(); break;
        case FUN: eat(FUN); eat(ID); eat("("); Function1(); eat(")"); Block(); Definition(); break;
        case VAR: eat(VAR); eat(ID); eat(";"); Definition(); break;
    }
}

void Definitions() {
    switch(tok) {
        case STU: eat(STU); eat(ID); eat("{"); Instantiations(); eat("}"); Definition(); Definitions(); break;
        case FUN: eat(FUN); eat(ID); eat("("); Function1(); eat(")"); Block(); Definition(); Definitions(); break;
        case VAR: eat(VAR); eat(ID); eat(";"); Definition(); Definitions(); break;
        case EOF: eat(EOF); break;
    }
}

void Program() {
    switch(tok) {
        case STU: eat(STU); eat(ID); eat("{"); Instantiations(); eat("}"); Definition(); Definitions(); break;
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