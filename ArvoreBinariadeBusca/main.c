#include <stdio.h>
#include <stdlib.h>

struct no{
	int cont;
	struct no *esq;
	struct no *dir;
};

typedef struct no tree;

tree *Tree(int cont, tree *esq, tree *dir){
	tree *nova = malloc(sizeof(tree));
	nova->cont = cont;
	nova->esq = esq;
	nova->dir = dir;
	
	return nova;
}

void printa(tree *arv, int p){
	if (arv != NULL){
		int i;
		for(i=0; i<p; i++){
			printf("->");
		}
		printf("%d \n", arv->cont);
		printa(arv->esq, p+1);
		printa(arv->dir, p+1);
	}
}

tree *insere (tree *arv, int cont){
	if (arv == NULL) return Tree(cont, NULL, NULL);
	if (arv->cont > cont) arv->esq = insere(arv->esq, cont);
	else arv->dir = insere(arv->dir, cont);
	return arv;
}

tree *busca(tree* arv, int k){
	if (arv == NULL || arv->cont == k) return arv;
	if (arv->cont > k) return busca(arv->esq, k);
	else return busca(arv->dir, k);
}

int main() {
	tree *arvore = NULL;
	arvore = insere(arvore,10);
	arvore = insere(arvore,7);
	arvore = insere(arvore,15);
	arvore = insere(arvore,3);
	arvore = insere(arvore,11);
	
	printa(arvore, 0);
	printf("\n");
	
	int k = 11;
	printf("Buscando o numero %d\n",k);
	
	if(busca(arvore, k) == NULL) printf("Nao achou!!!\n");
	else printf("Achou!!!\n");
	
	return 0;
}
