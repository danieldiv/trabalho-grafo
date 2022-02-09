#include "graph.h"

//// procs FILA
Fila* FFVazia(){
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  return f;
}

void Queue(Fila *f, int vertex){
  Item *d = (Item *) malloc (sizeof(Item));
  d->data = vertex;
  d->prox = NULL;

  if(f->head == NULL){
    f->head = d;
    f->tail = d;
  }else{
    f->tail->prox = d;
    f->tail = d;
  }

  f->size ++;
}

Item* Dequeue(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}

//// fim procs FILA

// procs para tratar com grafos

Vertex VertexInitialize(int value){
  Vertex v = malloc (sizeof(Vertex));
  v->value = value;
  v->prox  = NULL;
  return v;
}

Graph GraphInitialize(int V){
  Graph G = malloc (sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(Vertex));

  for(int v=0; v<V; v++)
    G->adj[v] = VertexInitialize(v);

  return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2){
  Vertex v = G->adj[v1->value];

  while(v->prox != NULL){
    if (v->value == v2->value)
      return;
    v = v->prox;
  }

  v->prox = VertexInitialize(v2->value);
  G->E ++;
}

void ImprimeGraph(Graph G){
  Vertex aux;

  for(int v=0; v<G->V; v++){
    aux = G->adj[v];

    while(aux != NULL){
      printf(" %d -> ", aux->value);
      aux = aux->prox;
    }

    printf("\n");
  }

}

// fim procs para tratar com grafos