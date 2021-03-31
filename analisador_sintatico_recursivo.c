#include "lex.yy.c"
#include "grammar.h"

enum token tok;

void eat(enum token);
void Fid_token();

void error(){
    fprintf(stderr, "Error (%d %d)\n", yylineno, offset );
}

void advance() {
    tok = (token) yylex();
    if(tok == EOL) eat(tok);
}

void eat(enum token t) {
    if (tok==t) advance(); else {error();};
}

void Dim(){
    switch(tok) {
        case (token) ';': break;
        case (token) '=': break;
        case APL: break;
        case AMI: break;
        case ADI: break;
        case AMU: break;
        case UAD: break;
        case USU: break;
        case (token) '(': break;
        case (token) '[': eat((token) '['); Expression(); eat((token) ']'); Dim(); break;

        case (token) '^': break;
        case (token) '+': break;
        case (token) '-': break;
        case (token) '*': break;
        case (token) '/': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default : error();
    }
}

void Matrix(){
    switch(tok) {
        case (token) ';': break;
        case (token) '[': eat((token) '['); Expression(); eat((token) ']'); Dim(); break;
        default : error();
    }
}

void Instantiation(){
    switch(tok) {
        case VAR: eat(VAR); eat(ID); Matrix(); break;
        default : error();
    }    
}

void Instantiations(){
    switch(tok) {
        case VAR: Instantiation() ; eat((token)';'); Instantiations(); break;
        case (token)'}': break;
        default : error();
    }    
}

void Struct(){
    switch(tok){
        case STU: eat(STU); eat(ID); eat((token)'{'); Instantiations(); eat((token)'}') ; break; 
        default : error();
    }
}

void Function_argument(){
    switch(tok) {
        case ID: eat(ID); Fid_token(); break;
        default : error();
    }
}

void Fid_token(){
    switch(tok) {
        case (token) ',': eat((token) ','); Function_argument(); break;
        case (token) ')':  break;
        default : error();
    }
}

void Function1(){
    switch(tok) {
        case (token) ')':  break;
        case ID: Function_argument(); break;
        default : error();
    }
}

void OptFunCall(){
    switch(tok) {
        case (token) '(': eat((token) '('); Arguments(); eat((token) ')'); break;
        case (token) '^': break;
        case (token) '/': break;
        case (token) '+': break;
        case (token) '-': break;
        case (token) '!': break;
        case GEQ: break;
        case GRE: break;
        case LEO: break;
        case LEQ: break;
        case EQU: break;
        case (token) '&': break;
        case OR: break;
        case (token) '*': break;
        case (token) '}': break;
        case (token) ',': break;
        case (token) ';': break;
    }    
}

void Var(){
    switch(tok) {
        case INT: eat(INT); break;
        case FLO: eat(FLO); break;
        case BOO: eat(BOO); break;
        case STR: eat(STR); break;
        case CHA: eat(CHA); break;
        case ID: eat(ID); Dim(); OptFunCall(); break;
        default: error();
    }
}

void Bra(){
    switch(tok) {
        case INT: Var(); break;
        case FLO: Var(); break;
        case BOO: Var(); break;
        case STR: Var(); break;
        case CHA: Var(); break;
        case ID: Var(); break;
        case (token)'(': eat((token)'('); Expression(); eat((token)')') ;break;
        default: error();
    }
}

void Tra(){
    switch(tok) {
        case INT: Bra(); break;
        case FLO: Bra(); break;
        case BOO: Bra(); break;
        case STR: Bra(); break;
        case CHA: Bra(); break;
        case ID: Bra(); break;
        case (token) '(': Bra();break;
        case TRA: eat(TRA); eat((token)'('); Expression(); eat((token)')') ;break;
        default: error();
    }
}

void Inv(){
    switch(tok) {
        case INT: Tra(); break;
        case FLO: Tra(); break;
        case BOO: Tra(); break;
        case STR: Tra(); break;
        case CHA: Tra(); break;
        case ID: Tra(); break;
        case TRA: Tra(); break;
        case (token) '(': Tra(); break;
        case INV: eat(INV); eat((token)'('); Expression(); eat((token)')') ;break;
        default: error();
    }
}

void Id(){
    switch(tok) {
        case INT: Inv(); break;
        case FLO: Inv(); break;
        case BOO: Inv(); break;
        case STR: Inv(); break;
        case CHA: Inv(); break;
        case ID: Inv(); break;
        case INV: Inv(); break;
        case TRA: Inv(); break;
        case (token) '(': Inv(); break;
        case IDE: eat(IDE); eat((token)'('); Expression(); eat((token)')') ;break;
        default: error();
    }
}

void Zer(){
    switch(tok) {
        case INT: Id(); break;
        case FLO: Id(); break;
        case BOO: Id(); break;
        case STR: Id(); break;
        case CHA: Id(); break;
        case ID: Id(); break;
        case INV: Id(); break;
        case IDE: Id(); break;
        case TRA: Id(); break;
        case (token) '(': Id(); break;
        case ZER: eat(ZER); eat((token)'('); Expression(); eat((token)')') ;break;
        default: error();
    }
}

void MaUn(){
    switch(tok) {
        case INT: Zer(); break;
        case FLO: Zer(); break;
        case BOO: Zer(); break;
        case STR: Zer(); break;
        case CHA: Zer(); break;
        case ID: Zer(); break;
        case ZER: Zer(); break;
        case INV: Zer(); break;
        case IDE: Zer(); break;
        case TRA: Zer(); break;
        case (token) '(': Zer(); break;
        case (token) '+': eat((token) '+'); Expression(); break;
        default: error();
    }
}

void MeUn(){
    switch(tok) {
        case INT: MaUn(); break;
        case FLO: MaUn(); break;
        case BOO: MaUn(); break;
        case STR: MaUn(); break;
        case CHA: MaUn(); break;
        case ID: MaUn(); break;
        case ZER: MaUn(); break;
        case INV: MaUn(); break;
        case IDE: MaUn(); break;
        case TRA: MaUn(); break;
        case (token) '(': MaUn(); break;
        case (token) '+': MaUn(); break;
        case (token) '-': eat((token) '-'); Expression(); break;
        default: error();
    }
}

void FMeUn(){
    switch(tok) {
        case (token) '^': eat((token) '^'); EOp(); break;
        case (token) ';': break;
        case (token) '+': break;
        case (token) '-': break;
        case (token) '*': break;
        case (token) '/': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default: error();
    }
}

void EOp(){
    switch(tok) {
        case INT: MeUn(); FMeUn(); break;
        case FLO: MeUn(); FMeUn(); break;
        case BOO: MeUn(); FMeUn(); break;
        case STR: MeUn(); FMeUn(); break;
        case CHA: MeUn(); FMeUn(); break;
        case ID: MeUn(); FMeUn(); break;
        case ZER: MeUn(); FMeUn(); break;
        case INV: MeUn(); FMeUn(); break;
        case IDE: MeUn(); FMeUn(); break;
        case TRA: MeUn(); FMeUn(); break;
        case (token) '(': MeUn(); FMeUn(); break;
        case (token) '-': MeUn(); FMeUn(); break;
        case (token) '+': MeUn(); FMeUn(); break;
        default: error();
    }
}

void DOp1(){
    switch(tok) {
        case (token) '/': eat((token) '/'); EOp(); DOp1(); break;
        case (token) ';': break;
        case (token) '+': break;
        case (token) '-': break;
        case (token) '*': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default: error();
    }
}

void DOp(){
    switch(tok) {
        case INT: EOp(); DOp1(); break;
        case FLO: EOp(); DOp1(); break;
        case BOO: EOp(); DOp1(); break;
        case STR: EOp(); DOp1(); break;
        case CHA: EOp(); DOp1(); break;
        case ID: EOp(); DOp1(); break;
        case ZER: EOp(); DOp1(); break;
        case INV: EOp(); DOp1(); break;
        case IDE: EOp(); DOp1(); break;
        case TRA: EOp(); DOp1(); break;
        case (token) '(': EOp(); DOp1(); break;
        case (token) '-': EOp(); DOp1(); break;
        case (token) '+': EOp(); DOp1(); break;
        default: error();
    }
}

void MOp1(){
    switch(tok) {
        case (token) '*': eat((token) '*'); DOp(); MOp1(); break;
        case (token) ';': break;
        case (token) '+': break;
        case (token) '-': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default: error();
    }
}

void MOp(){
    switch(tok) {
        case INT: DOp(); MOp1(); break;
        case FLO: DOp(); MOp1(); break;
        case BOO: DOp(); MOp1(); break;
        case STR: DOp(); MOp1(); break;
        case CHA: DOp(); MOp1(); break;
        case ID: DOp(); MOp1(); break;
        case ZER: DOp(); MOp1(); break;
        case INV: DOp(); MOp1(); break;
        case IDE: DOp(); MOp1(); break;
        case TRA: DOp(); MOp1(); break;
        case (token) '(': DOp(); MOp1(); break;
        case (token) '-': DOp(); MOp1(); break;
        case (token) '+': DOp(); MOp1(); break;
        default: error();
    }
}

void SOp1(){
    switch(tok) {
        case (token) '-': eat((token) '-'); MOp(); SOp1(); break;
        case (token) ';': break;
        case (token) '+': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default: error();
    }
}

void SOp(){
    switch(tok) {
        case INT: MOp(); SOp1(); break;
        case FLO: MOp(); SOp1(); break;
        case BOO: MOp(); SOp1(); break;
        case STR: MOp(); SOp1(); break;
        case CHA: MOp(); SOp1(); break;
        case ID: MOp(); SOp1(); break;
        case ZER: MOp(); SOp1(); break;
        case INV: MOp(); SOp1(); break;
        case IDE: MOp(); SOp1(); break;
        case TRA: MOp(); SOp1(); break;
        case (token) '(': MOp(); SOp1(); break;
        case (token) '-': MOp(); SOp1(); break;
        case (token) '+': MOp(); SOp1(); break;
        default: error();
    }
}

void AOp1(){
    switch(tok) {
        case (token) '+': eat((token) '+'); SOp(); AOp1(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        case DIO: break;
        default: error();
    }
}

void AOp(){
    switch(tok) {
        case INT: SOp(); AOp1(); break;
        case FLO: SOp(); AOp1(); break;
        case BOO: SOp(); AOp1(); break;
        case STR: SOp(); AOp1(); break;
        case CHA: SOp(); AOp1(); break;
        case ID: SOp(); AOp1(); break;
        case ZER: SOp(); AOp1(); break;
        case INV: SOp(); AOp1(); break;
        case IDE: SOp(); AOp1(); break;
        case TRA: SOp(); AOp1(); break;
        case (token) '(': SOp(); AOp1(); break;
        case (token) '-': SOp(); AOp1(); break;
        case (token) '+': SOp(); AOp1(); break;
        default: error();
    }
}

void FAOp(){
    switch(tok) {
        case DIO: eat(DIO); AOp(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        case GEQ: break;
        default: error();
    }
}

void DRel(){
    switch(tok) {
        case INT: AOp(); FAOp(); break;
        case FLO: AOp(); FAOp(); break;
        case BOO: AOp(); FAOp(); break;
        case STR: AOp(); FAOp(); break;
        case CHA: AOp(); FAOp(); break;
        case ID: AOp(); FAOp(); break;
        case ZER: AOp(); FAOp(); break;
        case INV: AOp(); FAOp(); break;
        case IDE: AOp(); FAOp(); break;
        case TRA: AOp(); FAOp(); break;
        case (token) '(': AOp(); FAOp(); break;
        case (token) '-': AOp(); FAOp(); break;
        case (token) '+': AOp(); FAOp(); break;
        default: error();
    }
}

void FDRel(){
    switch(tok) {
        case GEQ: eat(GEQ); DRel(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        case GRE: break;
        default: error();
    }
}

void GERel(){
    switch(tok) {
        case INT: DRel(); FDRel(); break;
        case FLO: DRel(); FDRel(); break;
        case BOO: DRel(); FDRel(); break;
        case STR: DRel(); FDRel(); break;
        case CHA: DRel(); FDRel(); break;
        case ID: DRel(); FDRel(); break;
        case ZER: DRel(); FDRel(); break;
        case INV: DRel(); FDRel(); break;
        case IDE: DRel(); FDRel(); break;
        case TRA: DRel(); FDRel(); break;
        case (token) '(': DRel(); FDRel(); break;
        case (token) '-': DRel(); FDRel(); break;
        case (token) '+': DRel(); FDRel(); break;
        default: error();
    }
}

void FGERel(){
    switch(tok) {
        case GRE: eat(GRE); GERel(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        case LEQ: break;
        default: error();
    }
}

void GRel(){
    switch(tok) {
        case INT: GERel(); FGERel(); break;
        case FLO: GERel(); FGERel(); break;
        case BOO: GERel(); FGERel(); break;
        case STR: GERel(); FGERel(); break;
        case CHA: GERel(); FGERel(); break;
        case ID: GERel(); FGERel(); break;
        case ZER: GERel(); FGERel(); break;
        case INV: GERel(); FGERel(); break;
        case IDE: GERel(); FGERel(); break;
        case TRA: GERel(); FGERel(); break;
        case (token) '(': GERel(); FGERel(); break;
        case (token) '-': GERel(); FGERel(); break;
        case (token) '+': GERel(); FGERel(); break;
        default: error();
    }
}

void FGRel(){
    switch(tok) {
        case LEQ: eat(LEQ); GRel(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        case LEO: break;
        default: error();
    }
}

void LERel(){
    switch(tok) {
        case INT: GRel(); FGRel(); break;
        case FLO: GRel(); FGRel(); break;
        case BOO: GRel(); FGRel(); break;
        case STR: GRel(); FGRel(); break;
        case CHA: GRel(); FGRel(); break;
        case ID: GRel(); FGRel(); break;
        case ZER: GRel(); FGRel(); break;
        case INV: GRel(); FGRel(); break;
        case IDE: GRel(); FGRel(); break;
        case TRA: GRel(); FGRel(); break;
        case (token) '(': GRel(); FGRel(); break;
        case (token) '-': GRel(); FGRel(); break;
        case (token) '+': GRel(); FGRel(); break;
        default: error();
    }
}

void FLERel(){
    switch(tok) {
        case LEO: eat(LEO); LERel(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        case EQU: break;
        default: error();
    }
}

void LRel(){
    switch(tok) {
        case INT: LERel(); FLERel(); break;
        case FLO: LERel(); FLERel(); break;
        case BOO: LERel(); FLERel(); break;
        case STR: LERel(); FLERel(); break;
        case CHA: LERel(); FLERel(); break;
        case ID: LERel(); FLERel(); break;
        case ZER: LERel(); FLERel(); break;
        case INV: LERel(); FLERel(); break;
        case IDE: LERel(); FLERel(); break;
        case TRA: LERel(); FLERel(); break;
        case (token) '(': LERel(); FLERel(); break;
        case (token) '-': LERel(); FLERel(); break;
        case (token) '+': LERel(); FLERel(); break;
        default: error();
    }
}

void FLRel(){
    switch(tok) {
        case EQU: eat(EQU); LRel(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        case (token) '&': break;
        default: error();
    }
}

void ERel(){
    switch(tok) {
        case INT: LRel(); FLRel(); break;
        case FLO: LRel(); FLRel(); break;
        case BOO: LRel(); FLRel(); break;
        case STR: LRel(); FLRel(); break;
        case CHA: LRel(); FLRel(); break;
        case ID: LRel(); FLRel(); break;
        case ZER: LRel(); FLRel(); break;
        case INV: LRel(); FLRel(); break;
        case IDE: LRel(); FLRel(); break;
        case TRA: LRel(); FLRel(); break;
        case (token) '(': LRel(); FLRel(); break;
        case (token) '-': LRel(); FLRel(); break;
        case (token) '+': LRel(); FLRel(); break;
        default: error();
    }
}

void FLog(){
    switch(tok) {
        case (token) '!': eat((token) '!'); ERel(); break;
        case INT: ERel(); break;
        case FLO: ERel(); break;
        case BOO: ERel(); break;
        case STR: ERel(); break;
        case CHA: ERel(); break;
        case ID: ERel(); break;
        case ZER: ERel(); break;
        case INV: ERel(); break;
        case IDE: ERel(); break;
        case TRA: ERel(); break;
        case (token) '(': ERel(); break;
        case (token) '-': ERel(); break;
        case (token) '+': ERel(); break;
        default: error();
    }
}

void TLog1(){
    switch(tok) {
        case (token) '&': eat((token) '&'); FLog(); TLog1(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        case OR: break;
        default: error();
    }
}

void TLog(){
    switch(tok) {
        case INT: FLog(); TLog1(); break;
        case FLO: FLog(); TLog1(); break;
        case BOO: FLog(); TLog1(); break;
        case STR: FLog(); TLog1(); break;
        case CHA: FLog(); TLog1(); break;
        case ID: FLog(); TLog1(); break;
        case ZER: FLog(); TLog1(); break;
        case INV: FLog(); TLog1(); break;
        case IDE: FLog(); TLog1(); break;
        case TRA: FLog(); TLog1(); break;
        case (token) '!': FLog(); TLog1(); break;
        case (token) '(': FLog(); TLog1(); break;
        case (token) '-': FLog(); TLog1(); break;
        case (token) '+': FLog(); TLog1(); break;
        default: error();
    }
}

void Expression1(){
    switch(tok) {
        case OR: eat(OR); TLog(); Expression1(); break;
        case (token) ';': break;
        case (token) ')': break;
        case (token) ',': break;
        case (token) ']': break;
        default: error();
    }
}

void Expression(){
    switch(tok) {
        //case IDE:  TLog(); Expression1(); break;
        case INT: TLog(); Expression1(); break;
        case FLO: TLog(); Expression1(); break;
        case BOO: TLog(); Expression1(); break;
        case STR: TLog(); Expression1(); break;
        case CHA: TLog(); Expression1(); break;
        case ID:  TLog(); Expression1(); break;
        case ZER: TLog(); Expression1(); break;
        case INV: TLog(); Expression1(); break;
        case IDE: TLog(); Expression1(); break;
        case TRA: TLog(); Expression1(); break;
        case (token) '!': TLog(); Expression1(); break;
        case (token) '(': TLog(); Expression1(); break;
        case (token) '-': TLog(); Expression1(); break;
        case (token) '+': TLog(); Expression1(); break;
        //case BOO: TLog(); Expression1(); break;
        //case STR: TLog(); Expression1(); break;
        //case CHA: TLog(); Expression1(); break;
        //case FLO: TLog(); Expression1(); break;
        //case (token) '(': TLog(); Expression1(); break;
        default : error();
    }
}

void Return(){
    switch(tok) {
        case RET: eat(RET); eat((token)'('); Expression(); eat((token)')'); eat((token) ';'); break;
        default : error();
    }
}


void Print(){
    switch(tok) {
        case PRI: eat(PRI); eat((token)'('); Expression(); eat((token)')'); eat((token) ';'); break;
        default : error();
    }
}

void Read(){
    switch(tok) {
        case REA: eat(REA); eat((token)'('); eat(ID); eat((token) ','); Var(); eat((token)')'); eat((token) ';'); break;
        default : error();
    }
}

void FELEMENT(){
    switch(tok) {
        case (token) ',': eat((token) ','); ELEMENTS(); break;
    }
}

void ELEMENT(){
    switch(tok) {
        case ID: Expression(); break;
        case INT: Expression(); break;
        case FLO: Expression(); break;
        case CHA: Expression(); break;
        case BOO: Expression(); break;
        case STR: Expression(); break;
        case (token) '[': Matrix_line(); break;
        case (token) '!': Expression(); break;
        case (token) '-': Expression(); break;
        case (token) '+': Expression(); break;
        case (token) '(': Expression(); break;
        case ZER: Expression(); break;
        case IDE: Expression(); break;
        case INV: Expression(); break;
        case TRA: Expression(); break;
    }
}

void ELEMENTS(){
    switch(tok) {
        case ID: ELEMENT(); FELEMENT(); break;
        case INT: ELEMENT(); FELEMENT(); break;
        case FLO: ELEMENT(); FELEMENT(); break;
        case CHA: ELEMENT(); FELEMENT(); break;
        case BOO: ELEMENT(); FELEMENT(); break;
        case STR: ELEMENT(); FELEMENT(); break;
        case (token) '[': ELEMENT(); FELEMENT(); break;
        case (token) '!': ELEMENT(); FELEMENT(); break;
        case (token) '-': ELEMENT(); FELEMENT(); break;
        case (token) '+': ELEMENT(); FELEMENT(); break;
        case (token) '(': ELEMENT(); FELEMENT(); break;
        case ZER: ELEMENT(); FELEMENT(); break;
        case IDE: ELEMENT(); FELEMENT(); break;
        case INV: ELEMENT(); FELEMENT(); break;
        case TRA: ELEMENT(); FELEMENT(); break;
    }
}

void Matrix_line(){
    switch(tok) {
        case (token) '[': eat((token) '['); ELEMENTS(); eat((token) ']'); break;
    }
}

void Fassign(){
    switch(tok) {
        case ID: Expression(); break;
        case INT: Expression(); break;
        case FLO: Expression(); break;
        case CHA: Expression(); break;
        case BOO: Expression(); break;
        case STR: Expression(); break;
        case (token) '[': Matrix_line(); break;
        case (token) '!': Expression(); break;
        case (token) '-': Expression(); break;
        case (token) '+': Expression(); break;
        case (token) '(': Expression(); break;
        case ZER: Expression(); break;
        case IDE: Expression(); break;
        case INV: Expression(); break;
        case TRA: Expression(); break;
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
        case FLO: Expression(); FExpression(); break;
        case CHA: Expression(); FExpression(); break;
        case BOO: Expression(); FExpression(); break;
        case STR: Expression(); FExpression(); break;
        case (token) '!': Expression(); FExpression(); break;
        case (token) '-': Expression(); FExpression(); break;
        case (token) '+': Expression(); FExpression(); break;
        case (token) '(': Expression(); FExpression(); break;
        case ZER: Expression(); FExpression(); break;
        case IDE: Expression(); FExpression(); break;
        case INV: Expression(); FExpression(); break;
        case TRA: Expression(); FExpression(); break;
    }
}

void Fid_token1(){
    switch(tok) {
        case (token)'=':  eat((token)'='); Fassign(); break;
        case AMI: eat((token)'-'); eat((token)'=') ; Fassign(); break;
        case APL: eat((token)'+'); eat((token)'=') ; Fassign(); break;
        case AMU: eat((token)'*'); eat((token)'=') ; Fassign(); break;
        case ADI: eat((token)'/'); eat((token)'=') ; Expression(); break;
        case UAD: eat(UAD); break;
        case USU: eat(USU); break;
        case (token)'(': eat((token)'('); Arguments() ; eat((token) ')'); break;
        default : error();
    }
}

void Assignment(){
    switch(tok) {
        case ID:  eat(ID); Dim(); Fid_token1(); break;
        default : error();
    }
}

void Assign1(){
    switch(tok) {
        case ID: Assignment(); break;
        case VAR: Instantiation(); break;
        default : error();
    }
}

void Assign(){
    switch(tok) {
        case ID: Assign1(); eat((token) ';'); break;
        case VAR: Assign1(); eat((token) ';'); break;
        default : error();
    }
}

void Elif_Aux(){
    switch(tok){
        case IF: If_block(); break;
        case (token) '{': Block(); break;
    }
}

void Else_Block(){
    switch(tok) {
        case ELS: eat(ELS); Elif_Aux(); break;
        case IF:  break;
        case FOR: break;
        case WHI: break;
        case RET: break;
        case PRI: break;
        case REA: break;
        case ID:  break;
        case VAR: break;
    }
}

void If_block(){
    switch(tok) {
        case IF: eat(IF); eat((token)'('); Expression(); eat((token)')'); Block(); Else_Block(); break;
        case FOR: break;
        case WHI: break;
        case RET: break;
        case PRI: break;
        case REA: break;
        case ID: break;
        case VAR: break;
        default : error();
    }
}

void F1(){
    switch(tok) {
        case ID: Assignment() ; eat((token)';') ; Expression() ; eat((token)';') ; Assignment() ; eat((token)')') ; Block(); break;
        case (token) ';': eat((token)';') ; Expression() ; eat((token)';') ; Assignment() ; eat((token)')') ; Block(); break;
        default : error();
    }
}

void Ffor(){
    switch(tok) {
        case (token) '(': eat((token) '('); F1(); break;
        default : error();
    }
}

void For_block(){
    switch(tok) {
        case FOR: eat(FOR); Ffor(); break;
        default : error();
    }
}

void While_block(){
    switch(tok) {
        case WHI: eat(WHI); eat((token) '('); Expression(); eat((token) ')'); Block(); break;
        default : error();
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
        default : error();
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
        default : error();
    }
}

void Block(){
    switch(tok) {
        case (token) '{': eat((token) '{'); Statements(); eat((token)'}'); break;
        default : error();
    }
}

void Function(){
    switch(tok) {
        case FUN: eat(FUN); eat(ID); eat((token)'('); Function1(); eat((token)')'); Block(); break;
        default : error();
    }
}

void Definition(){
    switch(tok) {
        case VAR: Instantiation(); eat((token)';'); break;
        case STU: Struct(); break;
        case FUN: Function(); break;
        default : error();
    }
}

void Program() {
    switch(tok) {
        case VAR: Definition(); Program(); break;
        case STU: Definition(); Program(); break;
        case FUN: Definition(); Program(); break;
        case EOFF: break;
        default:  error();
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

    advance();    Program();

    printf("Finished!\n");
}