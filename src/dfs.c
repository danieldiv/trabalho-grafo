#include "graph.h"

void DFS_VISIT(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo, int *found, int fimLabirinto){
  cor[v->value]  = 1;
  *tempo        += 1;
  d[v->value]    = *tempo;

  for(Vertex u = G->adj[v->value]; u != NULL; u=u->prox)
    if(cor[u->value] == 0)
      DFS_VISIT(G, u, cor, d, f, tempo, found, fimLabirinto);


  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;

  if(*found != -1) {
    if(v->value == fimLabirinto) // verifica se chegou no fim do labirinto
      *found = 1;
  }

  printf("Vertex:%d D:%d, F:%d \n", v->value, d[v->value], f[v->value]);
}

void DFS(Graph G, int fimLabirinto){
  int cor[G->V]; // Branco 0, Cinza 1, Preto 2
  int d[G->V];   // Tempo de descoberta
  int f[G->V];   // Tempo de finalização
  int tempo = 0;

  bool controle = false;
  bool enter = true;
  int found;

  found = (fimLabirinto < 0) ? -1 : 0;

  for(int v=0; v<G->V; v++)
    cor[v] = 0;

  for(int v=0; v<G->V; v++) {
      if(cor[v] == 0)
        DFS_VISIT(G, G->adj[v], cor, d, f, &tempo, &found, fimLabirinto);

      controle = (!controle && found == 0) ? true : controle;
      if(found == 1) break;

      if(enter) {
        enter = false;
        printf("\n");
      }
  }

  if(found != -1) {
    printf("\n");
    if(!controle && found == 1)
      printf("E possivel chegar ao final do labirinto (%d) !\n", fimLabirinto);
    else
      printf("Nao e possivel chegar ao final do labirinto (%d), caminho inacessivel ou inexistente!\n", fimLabirinto);
  }
}