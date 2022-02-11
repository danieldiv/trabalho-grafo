#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ItemLista ItemLista;
typedef struct Block Block;
typedef struct Lista Lista;

struct ItemLista {
	int vertice;
	int adj[4];
	int cont;
};

struct Block {
	ItemLista dado;
	Block *prox;
};

struct Lista {
	Block *first;
	Block *last;
};

void FLVazia(Lista *l);
void LInsere(Lista *l, ItemLista d);
void Limprime(Lista *l);

#endif