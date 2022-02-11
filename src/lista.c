#include "lista.h"

void FLVazia(Lista *l) {
	l->first = (Block *) malloc(sizeof(Block));
	l->last = l->first;
	l->first->prox = NULL;
}

void LInsere(Lista *l, ItemLista d) {
	l->last->prox = (Block *) malloc(sizeof(Block));
	l->last = l->last->prox;
	l->last->dado = d;
	l->last->prox = NULL;
}

void Limprime(Lista *l) {
	Block *aux;
	int i;

	aux = l->first->prox;
	while(aux != NULL) {
		printf("[%d]-", aux->dado.vertice);

		i=0;
		while(i < aux->dado.cont) {
			printf("%d-", aux->dado.adj[i++]);
		}
		printf("\n");
		aux = aux->prox;
	}
}