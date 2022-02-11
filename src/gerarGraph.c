#include "graph.h"

// vetor utilizado pelo metodo checkPrimo
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

// vetor utilizado pelo metodo exemploAula
int example[] = {S,R,S,W,W,S,W,T,W,X,R,S,R,V_,V_,R,T,W,T,X,T,U,X,W,X,T,X,U,X,Y,U,T,U,X,U,Y,Y,U,Y,X};

/**
 * @brief verifica se um numero é primo em um vetor com numeros primos de 2 a 997
 * @param p valor que ira verificar se é primo
 *
 * utilizado pela funcao grafoEsparso
*/
bool checkPrimo(int p) {
	for(int i=0; i < 168; i++) {
		if(primos[i] == p) return true;
	}
	return false;
}

/**
 * @brief gera um grafo denso com todos os vertices conectados a todos os demais vertices
 *
 * utilizado pelo metodo gerar grafo
*/
void grafoDenso(Graph G, int tam) {
	for(int i=0; i < tam; i++) {
		for(int j=0; j < tam; j++) {
			if(i != j)
				GraphInsertEdge(G, G->adj[i], G->adj[j]);
		}
	}
}

/**
 * @brief gera um grafo orientado com desconexoes para que seja esparso
 *
 * utilizado pelo metodo gerar grafo
*/
void grafoEsparso(Graph G, int tam) {
	int aux, i, j;
	int **matriz = (int**)malloc(tam * sizeof(int*));

	srand(0);
	for(i=0; i < tam; i++) {
		matriz[i] = (int*)malloc(tam * sizeof(int));

		for(j=0; j < tam; j++) {
			matriz[i][j] = -1;
		}
	}

	for(i=0; i < tam; i++) {
		aux = rand() % tam;

		if(checkPrimo(aux)) {
			for(j=0; j < tam / 2; j++) {
				aux = rand() % tam;
				if(i != j)
					matriz[i][aux] = aux;
			}
		} else i++;
	}

	for(i=0; i < tam; i++) {
		for(j=0; j < tam; j++) {
			if(matriz[i][j] != -1 && matriz[i][j] != i && i != j)
				GraphInsertEdge(G, G->adj[i], G->adj[matriz[i][j]]);
		}
	}
}

// utilizado pelo metodo exemploAula
void grafoExemplo(Graph G) {
    for(int i=0; i < 40; i+=2)
        GraphInsertEdge(G, G->adj[example[i]], G->adj[example[i+1]]);
}
