#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define R 2
#define S 0
#define T 4
#define U 6
#define V_ 3
#define W 1
#define X 5
#define Y 7

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

struct TipoVertex{
  int value;
  Vertex prox;
};

struct graph{
  int V;
  int E;
  Vertex *adj;
};


//fila
struct TipoItem{
    int data;
  Item *prox;
};

struct TipoFila{
  Item *head;
  Item *tail;
  int size;
};

Vertex VertexInitialize(int value);
Graph GraphInitialize(int V);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph(Graph G);

Fila* FFVazia();
void Queue(Fila *f, int vertex);
Item* Dequeue(Fila *f);

void listToMatriz(Graph G, int **matriz);

void BFS(Graph G, Vertex s, int *cont);

void DFS(Graph G, int fimLabirinto);
void DFS_VISIT(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo, int *found, int fimLabirinto);

void grafoDenso(Graph G, int tam);
void grafoEsparso(Graph G, int tam);
void grafoExemplo();
bool checkPrimo(int p);

#endif