#include <iostream>
#include <map>
#include <stdio.h>
#include "lex.yy.c"
#include "pilha.c"

using namespace std;

map< token, map<token, int> > tabela;

void erro(){
   fprintf(stderr, "Sintatical error (%d %d)\n", yylineno, offset );
}

int terminal(int x) {
   switch(x) {
      case '(': return 1;
      case ')': return 1;
      case '{': return 1;
      case '}': return 1;
      case '[': return 1;
      case ']': return 1;
      case '=': return 1;
      case '&': return 1;
      case '!': return 1;
      case '%': return 1;
      case '^': return 1;
      case ',': return 1;
      case ';': return 1;
      case '+': return 1;
      case '-': return 1;
      case '*': return 1;
      case '/': return 1;
   }

   if(x >= 258 && x <= 293) return 1;
   else return 0;
}

void empilhar_producao(int tokk) {
   switch (tokk){
      case 1:
         empilhar(Program);
         empilhar(Definition);
         break;

      case 2:
         break;

      case 3:
         empilhar(Struct);
         break;
      case 4:
         empilhar(Instantiation);
         empilhar(';');
         break;
      case 5:
         empilhar(Function);
         break;
      case 6:
         empilhar(STU);
         empilhar(ID);
         empilhar('{');
         empilhar(Function1);
         empilhar('}');
         break;
      case 7:
         empilhar(Instantiation);
         empilhar(';');
         empilhar(Instantiations);
         break;
      case 8:
         break;
      case 9:
         empilhar(VAR);
         empilhar(ID);
         empilhar(Matrix);
         break;
      case 10:
         empilhar(Assign1);
         break;
      case 11:
         empilhar(Assignment);
         break;
      case 12:
         empilhar(Instantiation);
         break;
      case 13:
         empilhar(Block);
         empilhar(')');
         empilhar(Function1);
         empilhar('(');
         empilhar(ID);
         empilhar(FUN);
         break;
      case 14:
         empilhar(Function_argument);
         break;
      case 15:
         break;
      case 16:
         empilhar(ID);
         empilhar(Fid_token);
         break;
      case 17:
         empilhar(',');
         empilhar(Function_argument);
         break;
      case 18:
         break;
      case 19:
         empilhar(Statement);
         empilhar(Statements);
         break;
      case 20:
         break;
      case 21:
         empilhar(If_block);
         break;
      case 22:
         empilhar(For_block);
         break;
      case 23:
         empilhar(While_block);
         break;
      case 24:
         empilhar(Assign);
         break;
      case 25:
         empilhar(Return_expr);
         break;
      case 26:
         empilhar(Print);
         break;
      case 27:
         empilhar(Read);
         break;
      case 28:
         empilhar(ID);
         empilhar(Dim);
         empilhar(Fid_token1);
         break;
      case 29:
         empilhar('=');
         empilhar(Fassign);
         break;
      case 30:
         empilhar(AMI);
         empilhar(Fsubassign);
         break;
      case 31:
         empilhar(APL);
         empilhar(Fsubassign);
         break;
      case 32:
         empilhar(AMU);
         empilhar(Fsubassign);
         break;
      case 33:
         empilhar(ADI);
         empilhar(Fsubassign);
         break;
      case 34:
         empilhar(UAD);
         break;
      case 35:
         empilhar(USU);
         break;
      case 36:
         empilhar('(');
         empilhar(Arguments);
         empilhar(')');
         break;
      case 37:
         empilhar(Expression);
         break;
      case 38:
         empilhar(Matrix_line);
         break;
      case 39:
         empilhar('[');
         empilhar(ELEMENTS);
         empilhar(']');
         break;
      case 40:
         empilhar(ELEMENTS);
         empilhar(FELEMENT);
         break;
      case 41:
         empilhar(',');
         empilhar(ELEMENTS);
         break;
      case 42:
         break;
      case 43:
         empilhar(Expression);
         break;
      case 44:
         empilhar(Matrix_line);
         break;		
      case 45:
         empilhar('[');
         empilhar(Statements);
         empilhar(']');
         break;
      case 46:
         empilhar(RET);
         empilhar('(');
         empilhar(Statements);
         empilhar(')');
         break;
      case 47:
         empilhar(FOR);
         empilhar(F1);
         break;	
      case 48:
         empilhar('(');
         empilhar(Ffor);
         break;	
      case 49:
         empilhar(Assignment);
         empilhar(';');
         empilhar(Expression);
         empilhar(';');
         empilhar(Assignment);
         empilhar(')');
         empilhar(Block);
         break;	

      case 50:
         empilhar(';');
         empilhar(Expression);
         empilhar(';');
         empilhar(Assignment);
         empilhar(')');
         empilhar(Block);
         break;

      case 51:
         empilhar(IF);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         empilhar(Block);
         empilhar(Else_Block);
         break;

      case 52:
         empilhar(ELS);
         empilhar(Elif_aux);
         break;

      case 53:
         break;

      case 54:
         empilhar(If_block);
         break;
      case 55:
         empilhar(Block);
         break;
      case 56:
         empilhar(WHI);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         empilhar(Block);
         break;
      case 57:
         empilhar(Expression);
         empilhar(FExpression);
         break;
      case 58:
         empilhar(',');
         empilhar(Arguments);
         break;
      case 59:
         break;
      case 60:
         empilhar('[');
         empilhar(Expression);
         empilhar(']');
         empilhar(Dim);
         break;
      case 61:
         break;
      case 62:
         empilhar('[');
         empilhar(Expression);
         empilhar(']');
         empilhar(Dim);
         break;
      case 63:
         break;
      case 64:
         empilhar(PRI);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         empilhar(';');
         break;
      case 65:
         empilhar(REA);
         empilhar('(');
         empilhar(ID);
         empilhar(',');
         empilhar(LIT);
         empilhar(')');
         empilhar(';');
         break;
      case 66:
         empilhar(TLog);
         empilhar(Expression1);
         break;
      case 67:
         empilhar(OR);
         empilhar(TLog);
         empilhar(Expression1);
         break;
      case 68:
         break;
      case 69:
         empilhar(FLog);
         empilhar(TLog1);
         break;
      case 70:
         empilhar('&');
         empilhar(FLog);
         empilhar(TLog1);
         break;
      case 71:
         break;
      case 72:
         empilhar('!');
         empilhar(ERel);
         break;
      case 73:
         empilhar(ERel);
         break;
      case 74:
         empilhar(LRel);
         empilhar(FLRel);
         break;
      case 75:
         empilhar(EQU);
         empilhar(LRel);
         break;
      case 76:
         break;
      case 77:
         empilhar(LERel);
         empilhar(FLERel);
         break;
      case 78:
         empilhar('<');
         empilhar(LRel);
         break;
      case 79:
         break;
      case 80:
         empilhar(GRel);
         empilhar(FGRel);
         break;
      case 81:
         empilhar(LEQ);
         empilhar(GRel);
         break;
      case 82:
         break;
      case 83:
         empilhar(GRel);
         empilhar(FGRel);
         break;
      case 84:
         empilhar('>');
         empilhar(GRel);
         break;
      case 85:
         break;
      case 86:
         empilhar(DRel);
         empilhar(FDRel);
         break;
      case 87:
         empilhar(GEQ);
         empilhar(DRel);
         break;
      case 88:
         break;
      case 89:
         empilhar(AOp);
         empilhar(FAOp);
         break;
      case 90:
         empilhar(DIO);
         empilhar(FAOp);
         break;
      case 91:
         break;
      case 92:
         empilhar(SOp);
         empilhar(AOp1);
         break;
      case 93:
         empilhar('+');
         empilhar(SOp);
         empilhar(AOp1);
         break;
      case 94:
         break;
      case 95:
         empilhar(MOp);
         empilhar(SOp1);
         break;
      case 96:
         empilhar('-');
         empilhar(MOp);
         empilhar(SOp1);
         break;
      case 97:
         break;
      case 98:
         empilhar(DOp);
         empilhar(MOp1);
         break;
      case 99:
         empilhar('*');
         empilhar(DOp);
         empilhar(MOp1);
         break;
      case 100:
         break;
      case 101:
         empilhar(EOp);
         empilhar(DOp1);
         break;
      case 102:
         empilhar('/');
         empilhar(EOp);
         empilhar(DOp1);
         break;
      case 103:
         break;		
      case 104:
         empilhar(MeUn);
         empilhar(FMeUn);
         break;
      case 105:
         empilhar('^');
         empilhar(EOp);
         break;		
      case 106:
         break;
      case 107:
         empilhar('-');
         empilhar(MaUn);
         break;
      case 108:
         empilhar(MaUn);
         break;
      case 109:
         empilhar('+');
         empilhar(Zer);
         break;
      case 110:
         empilhar(Zer);
         break;	
      case 111:
         empilhar(ZER);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         break;
      case 112:
         empilhar(ID);
         break;
      case 113:
         empilhar(ID);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         break;
      case 114:
         empilhar(Inv);
         break;	
      case 115:
         empilhar(ID);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         break;
      case 116:
         empilhar(Tra);
         break;	
      case 117:
         empilhar(TRA);
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         break;
      case 118:
         empilhar(Bra);
         break;
      case 119:
         empilhar('(');
         empilhar(Expression);
         empilhar(')');
         break;
      case 120:
         empilhar(Var);
         break;
      case 121:
         empilhar(ID);
         empilhar(Dim);
         empilhar(OptFunCall);
      case 122:
         empilhar(LIT);
      case 123:
         empilhar('(');
         empilhar(Arguments);
         empilhar(')');
         break;
      case 124:
         break;
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

   tabela[Program][STU] = 1;
   tabela[Program][VAR] = 1;
   tabela[Program][FUN] = 1;
   tabela[Definition][STU] = 3;
   tabela[Definition][VAR] = 4;
   tabela[Definition][FUN] = 5;
   tabela[Struct][STU] = 6;
   tabela[Instantiations][VAR] = 7;
   tabela[Instantiation][VAR] = 9;
   tabela[Assign][ID] = 10;
   tabela[Assign][VAR] = 10;
   tabela[Assign1][ID] = 11;
   tabela[Assign1][VAR] = 12;
   tabela[Function][FUN] = 13;
   tabela[Function1][ID] = 14;
   tabela[Function_argument][ID] = 16;
   tabela[Fid_token][(token) ','] = 17;
   tabela[Statements][ID] = 19;
   tabela[Statements][VAR] = 19;
   tabela[Statements][RET] = 19;
   tabela[Statements][FOR] = 19;
   tabela[Statements][IF] = 19;
   tabela[Statements][WHI] = 19;
   tabela[Statements][PRI] = 19;
   tabela[Statements][REA] = 19;
   tabela[Statement][ID] = 24;
   tabela[Statement][VAR] = 24;
   tabela[Statement][RET] = 25;
   tabela[Statement][FOR] = 22;
   tabela[Statement][IF] = 21;
   tabela[Statement][WHI] = 23;
   tabela[Statement][PRI] = 26;
   tabela[Statement][REA] = 27;
   tabela[Assignment][ID] = 28;
   tabela[Fid_token1][(token) '('] = 26;
   tabela[Fid_token1][(token) '='] = 29;
   tabela[Fid_token1][AMI] = 30;
   tabela[Fid_token1][APL] = 31;
   tabela[Fid_token1][AMU] = 32;
   tabela[Fid_token1][ADI] = 33;
   tabela[Fid_token1][UAD] = 34;
   tabela[Fid_token1][USU] = 35;
   tabela[Fassign][ID] = 37;
   tabela[Fassign][(token) '{'] = 38;
   tabela[Fassign][(token) '('] = 37;
   tabela[Fassign][LIT] = 37;
   tabela[Fassign][(token) '!'] = 37;
   tabela[Fassign][(token) '+'] = 37;
   tabela[Fassign][(token) '-'] = 37;
   tabela[Fassign][ZER] = 37;
   tabela[Fassign][IDE] = 37;
   tabela[Fassign][INV] = 37;
   tabela[Fassign][TRA] = 37;
   tabela[Matrix_line][(token) '{'] = 39;
   tabela[ELEMENTS][ID] = 40;
   tabela[ELEMENTS][(token) '{'] = 40;
   tabela[ELEMENTS][(token) '('] = 40;
   tabela[ELEMENTS][LIT] = 40;
   tabela[ELEMENTS][(token) '!'] = 40;
   tabela[ELEMENTS][(token) '+'] = 40;
   tabela[ELEMENTS][(token) '-'] = 40;
   tabela[ELEMENTS][ZER] = 40;
   tabela[ELEMENTS][IDE] = 40;
   tabela[ELEMENTS][INV] = 40;
   tabela[ELEMENTS][TRA] = 40;
   tabela[FELEMENT][(token) ','] = 41;
   tabela[ELEMENT][ID] = 43;
   tabela[ELEMENT][(token) '{'] = 44;
   tabela[ELEMENT][(token) '('] = 43;
   tabela[ELEMENT][LIT] = 43;
   tabela[ELEMENT][(token) '!'] = 43;
   tabela[ELEMENT][(token) '+'] = 43;
   tabela[ELEMENT][(token) '-'] = 43;
   tabela[ELEMENT][ZER] = 43;
   tabela[ELEMENT][IDE] = 43;
   tabela[ELEMENT][INV] = 43;
   tabela[ELEMENT][TRA] = 43;
   tabela[Block][(token) '{'] = 45;
   tabela[Return_expr][RET] = 46;
   tabela[For_block][FOR] = 47;
   tabela[Ffor][(token) '('] = 48;
   tabela[F1][(token) ';'] = 50;
   tabela[F1][ID] = 49;
   tabela[If_block][IF] = 51;
   tabela[Else_Block][ELS] = 52;
   tabela[Elif_Aux][(token) '{'] = 55;
   tabela[Elif_Aux][IF] = 54;
   tabela[While_block][WHI] = 56;
   tabela[Arguments][ID] = 57;
   tabela[Arguments][(token) '('] = 57;
   tabela[Arguments][LIT] = 57;
   tabela[Arguments][(token) '!'] = 57;
   tabela[Arguments][(token) '+'] = 57;
   tabela[Arguments][(token) '-'] = 57;
   tabela[Arguments][ZER] = 57;
   tabela[Arguments][IDE] = 57;
   tabela[Arguments][INV] = 57;
   tabela[Arguments][TRA] = 57;
   tabela[FExpression][(token) ','] = 58;
   tabela[Matrix][(token) '['] = 60;
   tabela[Dim][(token) '['] = 62;
   tabela[Print][PRI] = 64;
   tabela[Read][REA] = 65;
   tabela[Expression][ID] = 66;
   tabela[Expression][(token) '('] = 66;
   tabela[Expression][LIT] = 66;
   tabela[Expression][(token) '!'] = 66;
   tabela[Expression][(token) '+'] = 66;
   tabela[Expression][(token) '-'] = 66;
   tabela[Expression][ZER] = 66;
   tabela[Expression][IDE] = 66;
   tabela[Expression][INV] = 66;
   tabela[Expression][TRA] = 66;
   tabela[Expression1][OR] = 67;
   tabela[TLog][ID] = 69;
   tabela[TLog][(token) '('] = 69;
   tabela[TLog][LIT] = 69;
   tabela[TLog][(token) '!'] = 69;
   tabela[TLog][(token) '+'] = 69;
   tabela[TLog][(token) '-'] = 69;
   tabela[TLog][ZER] = 69;
   tabela[TLog][IDE] = 69;
   tabela[TLog][INV] = 69;
   tabela[TLog][TRA] = 69;
   tabela[TLog1][(token) '&'] = 70;
   tabela[FLog][ID] = 73;
   tabela[FLog][(token) '('] = 73;
   tabela[FLog][LIT] = 73;
   tabela[FLog][(token) '!'] = 72;
   tabela[FLog][(token) '+'] = 73;
   tabela[FLog][(token) '-'] = 73;
   tabela[FLog][ZER] = 73;
   tabela[FLog][IDE] = 73;
   tabela[FLog][INV] = 73;
   tabela[FLog][TRA] = 73;
   tabela[ERel][ID] = 74;
   tabela[ERel][(token) '('] = 74;
   tabela[ERel][LIT] = 74;
   tabela[ERel][(token) '+'] = 74;
   tabela[ERel][(token) '-'] = 74;
   tabela[ERel][ZER] = 74;
   tabela[ERel][IDE] = 74;
   tabela[ERel][INV] = 74;
   tabela[ERel][TRA] = 74;
   tabela[FLRel][EQU] = 75;
   tabela[LRel][ID] = 77;
   tabela[LRel][(token) '('] = 77;
   tabela[LRel][LIT] = 77;
   tabela[LRel][(token) '+'] = 77;
   tabela[LRel][(token) '-'] = 77;
   tabela[LRel][ZER] = 77;
   tabela[LRel][IDE] = 77;
   tabela[LRel][INV] = 77;
   tabela[LRel][TRA] = 77;
   tabela[FLERel][(token) '<'] = 78;
   tabela[LERel][ID] = 80;
   tabela[LERel][(token) '('] = 80;
   tabela[LERel][LIT] = 80;
   tabela[LERel][(token) '+'] = 80;
   tabela[LERel][(token) '-'] = 80;
   tabela[LERel][ZER] = 80;
   tabela[LERel][IDE] = 80;
   tabela[LERel][INV] = 80;
   tabela[LERel][TRA] = 80;
   tabela[FGRel][LEQ] = 81;
   tabela[GRel][ID] = 83;
   tabela[GRel][(token) '('] = 83;
   tabela[GRel][LIT] = 83;
   tabela[GRel][(token) '+'] = 83;
   tabela[GRel][(token) '-'] = 83;
   tabela[GRel][ZER] = 83;
   tabela[GRel][IDE] = 83;
   tabela[GRel][INV] = 83;
   tabela[GRel][TRA] = 83;
   tabela[FGERel][(token) '>'] = 84;
   tabela[GERel][ID] = 86;
   tabela[GERel][(token) '('] = 86;
   tabela[GERel][LIT] = 86;
   tabela[GERel][(token) '+'] = 86;
   tabela[GERel][(token) '-'] = 86;
   tabela[GERel][ZER] = 86;
   tabela[GERel][IDE] = 86;
   tabela[GERel][INV] = 86;
   tabela[GERel][TRA] = 86;
   tabela[FDRel][GEQ] = 87;
   tabela[DRel][ID] = 89;
   tabela[DRel][(token) '('] = 89;
   tabela[DRel][LIT] = 89;
   tabela[DRel][(token) '+'] = 89;
   tabela[DRel][(token) '-'] = 89;
   tabela[DRel][ZER] = 89;
   tabela[DRel][IDE] = 89;
   tabela[DRel][INV] = 89;
   tabela[DRel][TRA] = 89;
   tabela[FAOp][DIO] = 90;
   tabela[AOp][ID] = 92;
   tabela[AOp][(token) '('] = 92;
   tabela[AOp][LIT] = 92;
   tabela[AOp][(token) '+'] = 92;
   tabela[AOp][(token) '-'] = 92;
   tabela[AOp][ZER] = 92;
   tabela[AOp][IDE] = 92;
   tabela[AOp][INV] = 92;
   tabela[AOp][TRA] = 92;
   tabela[AOp1][(token) '+'] = 93;
   tabela[SOp][ID] = 95;
   tabela[SOp][(token) '('] = 95;
   tabela[SOp][LIT] = 95;
   tabela[SOp][(token) '+'] = 95;
   tabela[SOp][(token) '-'] = 95;
   tabela[SOp][ZER] = 95;
   tabela[SOp][IDE] = 95;
   tabela[SOp][INV] = 95;
   tabela[SOp][TRA] = 95;
   tabela[SOp1][(token) '-'] = 96;
   tabela[MOp][ID] = 98;
   tabela[MOp][(token) '('] = 98;
   tabela[MOp][LIT] = 98;
   tabela[MOp][(token) '+'] = 98;
   tabela[MOp][(token) '-'] = 98;
   tabela[MOp][ZER] = 98;
   tabela[MOp][IDE] = 98;
   tabela[MOp][INV] = 98;
   tabela[MOp][TRA] = 98;
   tabela[MOp1][(token) '*'] = 99;
   tabela[DOp][ID] = 101;
   tabela[DOp][(token) '('] = 101;
   tabela[DOp][LIT] = 101;
   tabela[DOp][(token) '+'] = 101;
   tabela[DOp][(token) '-'] = 101;
   tabela[DOp][ZER] = 101;
   tabela[DOp][IDE] = 101;
   tabela[DOp][INV] = 101;
   tabela[DOp][TRA] = 101;
   tabela[DOp1][(token) '/'] = 102;
   tabela[EOp][ID] = 104;
   tabela[EOp][(token) '('] = 104;
   tabela[EOp][LIT] = 104;
   tabela[EOp][(token) '+'] = 104;
   tabela[EOp][(token) '-'] = 104;
   tabela[EOp][ZER] = 104;
   tabela[EOp][IDE] = 104;
   tabela[EOp][INV] = 104;
   tabela[EOp][TRA] = 104;
   tabela[FMeUn][(token) '^'] = 105;
   tabela[MeUn][ID] = 108;
   tabela[MeUn][(token) '('] = 108;
   tabela[MeUn][LIT] = 108;
   tabela[MeUn][(token) '+'] = 108;
   tabela[MeUn][(token) '-'] = 107;
   tabela[MeUn][ZER] = 108;
   tabela[MeUn][IDE] = 108;
   tabela[MeUn][INV] = 108;
   tabela[MeUn][TRA] = 108;
   tabela[MaUn][ID] = 110;
   tabela[MaUn][(token) '('] = 110;
   tabela[MaUn][LIT] = 110;
   tabela[MaUn][(token) '+'] = 109;
   tabela[MaUn][ZER] = 110;
   tabela[MaUn][IDE] = 110;
   tabela[MaUn][INV] = 110;
   tabela[MaUn][TRA] = 110;
   tabela[Zer][ID] = 112;
   tabela[Zer][(token) '('] = 112;
   tabela[Zer][LIT] = 112;
   tabela[Zer][ZER] = 111;
   tabela[Zer][IDE] = 112;
   tabela[Zer][INV] = 112;
   tabela[Zer][TRA] = 112;
   tabela[Id][ID] = 114;
   tabela[Id][(token) '('] = 114;
   tabela[Id][LIT] = 114;
   tabela[Id][IDE] = 113;
   tabela[Id][INV] = 114;
   tabela[Id][TRA] = 114;
   tabela[Inv][ID] = 116;
   tabela[Inv][(token) '('] = 116;
   tabela[Inv][LIT] = 116;
   tabela[Inv][INV] = 115;
   tabela[Inv][TRA] = 116;
   tabela[Tra][ID] = 118;
   tabela[Tra][(token) '('] = 118;
   tabela[Tra][LIT] = 118;
   tabela[Tra][TRA] = 117;
   tabela[Bra][ID] = 120;
   tabela[Bra][(token) '('] = 119;
   tabela[Bra][LIT] = 120;
   tabela[Var][ID] = 121;
   tabela[Var][LIT] = 122;
   tabela[OptFunCall][(token) '('] = 123;

   empilhar(EOFF);
   empilhar(Program);
   enum token x = (token) topo();
   enum token a = (token) yylex();

   while(x != EOFF) {
      if(x == a) {
         desempilhar();
         x = (token) topo();
         a = (token) yylex();
      } else if(terminal(x)) {
         erro();
         return 0;
      } else if(tabela[x][a] == 0) {
         erro();
         return 0;
      } else if (tabela[x][a] != 0) {
         desempilhar();
         x = (token) topo();
         empilhar_producao(tabela[x][a]);
      }
   }

   printf("Finished!\n");
}