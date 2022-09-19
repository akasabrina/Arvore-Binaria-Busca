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

void printa(tree *arvore, int p){
	if (arvore != NULL){
		int i;
		for(i=0; i<p; i++){
			printf("->");
		}
		printf("%d \n", arvore->cont);
		printa(arvore->esq, p+1);
		printa(arvore->dir, p+1);
	}
}

int main(int argc, char *argv[]) {
	tree *arvore = Tree(1,
					Tree(2, 
						Tree(3, NULL, NULL), 
						Tree(4, NULL, NULL)),
					Tree(5, 
						Tree(6, NULL, NULL), 
						Tree(7, NULL, NULL)));
	
	printa(arvore, 0);
	return 0;
}
