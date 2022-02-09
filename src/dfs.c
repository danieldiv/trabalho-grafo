#include "graph.h"

void DFS_VISIT(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo){
  cor[v->value]  = 1;
  *tempo        += 1;
  d[v->value]    = *tempo;

  for(Vertex u = G->adj[v->value]; u != NULL; u=u->prox)
    if(cor[u->value] == 0)
      DFS_VISIT(G, u, cor, d, f, tempo);


  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;
  printf("Vertex:%d D:%d, F:%d \n", v->value, d[v->value], f[v->value]);
}

void DFS(Graph G){
  int cor[G->V]; // Branco 0, Cinza 1, Preto 2
  int d[G->V];   // Tempo de descoberta
  int f[G->V];   // Tempo de finalização
  int tempo = 0;

  for(int v=0; v<G->V; v++)
    cor[v] = 0;

  for(int v=0; v<G->V; v++) {
    if(cor[v] == 0)
      DFS_VISIT(G, G->adj[v], cor, d, f, &tempo);
    printf("no path\n");
  }

}