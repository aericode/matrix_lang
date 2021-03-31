const int tamanho = 1024;
int pilha[tamanho];
int indice = -1;

int vazia() {
   if(indice == -1) return 1;
   else return 0;
}

int cheia() {
   if(indice == tamanho) return 1;
   else return 0;
}

int topo() {
   return pilha[indice];
}

int desempilhar() {
   int dados;
	
   if(!vazia()) {
      dados = pilha[indice];
      indice = indice - 1;   
      return dados;
   } else {
      printf("Erro ao desempilhar, a pilha está vazia.\n");
      return -1;
   }
}

void empilhar(int dados) {
   if(!cheia()) {
      indice = indice + 1;   
      pilha[indice] = dados;
   } else {
      printf("Erro ao inserir, a pilha está cheia.\n");
   }
}