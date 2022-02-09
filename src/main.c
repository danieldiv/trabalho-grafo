#include "graph.h"
#include <stdbool.h>

#define TAM 300 // maximo ate 1000 por causo dos numeros primos

int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int labirinto[2][297] = {
	{0,0,1,3,3,4,4,5,7,8,8,8,9,9,10,10,10,11,11,11,12,12,13,13,16,16,21,21,23,23,23,24,24,24,24,25,25,25,26,26,26,27,27,29,29,29,30,30,30,31,31,33,33,34,34,36,36,37,37,37,38,38,38,39,39,40,40,40,41,41,42,42,42,43,43,43,43,44,44,44,46,46,51,51,56,56,59,59,61,61,62,62,64,64,65,65,66,66,67,67,68,68,69,69,69,70,72,72,74,74,74,75,75,75,75,76,76,77,77,78,78,85,85,87,87,87,88,88,88,91,91,91,92,92,92,93,93,93,94,94,94,95,95,95,96,96,96,97,97,97,98,98,98,100,100,100,101,101,101,103,104,104,104,105,105,105,106,106,106,107,107,107,108,108,108,109,109,109,110,110,110,110,111,111,111,113,113,114,114,116,116,117,117,123,123,123,124,124,129,129,130,130,132,132,133,133,133,134,134,136,136,139,139,140,140,140,141,141,142,142,142,143,143,145,145,145,146,146,146,146,147,147,147,149,149,149,150,150,152,152,152,153,153,153,155,155,156,156,158,158,158,159,159,159,159,160,160,160,162,162,162,163,163,163,165,165,165,166,166,166,168,168,169,169,170,170,171,171,171,172,172,172,173,173,175,175,176,176,176,177,177,178,178,178,179,179,181},
	{1,13,0,4,16,3,5,4,8,7,9,21,8,10,9,11,23,10,12,24,11,25,0,26,3,29,8,34,10,24,36,11,23,25,37,12,24,38,13,27,39,26,40,16,30,42,29,31,43,30,44,34,46,21,33,23,37,24,36,38,25,37,51,26,40,27,39,41,40,42,29,41,44,30,42,44,56,31,43,56,33,59,38,64,43,69,46,72,62,74,61,75,51,77,66,78,65,67,66,69,67,69,56,68,70,69,59,85,61,75,87,62,74,76,88,75,77,64,76,65,91,72,98,74,88,100,75,87,101,78,92,104,91,93,105,92,94,106,93,95,107,94,96,108,95,97,109,96,98,110,85,97,111,87,101,113,88,100,114,116,91,105,117,92,104,106,93,105,107,94,106,108,95,107,109,96,108,110,97,109,111,123,98,110,124,100,114,101,113,103,129,104,130,110,124,136,111,123,116,142,117,143,133,145,132,134,146,133,147,123,149,140,152,139,141,153,140,142,129,141,155,130,156,132,146,158,133,145,147,159,134,146,160,136,150,162,149,163,139,153,165,140,152,166,142,168,143,169,145,159,171,146,158,160,172,147,159,173,149,163,175,150,162,176,152,166,178,153,165,179,155,181,156,170,169,171,158,170,172,159,171,173,160,172,162,176,163,175,177,176,178,165,177,179,166,178,168}
};

bool checkPrimo(int p) {
	for(int i=0; i < 168; i++) {
		if(primos[i] == p)
			return true;
	}
	return false;
}

void printLabirinto() {
	for(int j=0; j < 200; j++) {
		printf("%3d-%d\n ", labirinto[0][j], labirinto[1][j]);
	}
}

int main(){
	Graph G = GraphInitialize(185);

	for(int j=0; j < 297; j++) {
		GraphInsertEdge(G, G->adj[labirinto[0][j]], G->adj[labirinto[1][j]]);
	}

	// int b;
	// int vetor[TAM][TAM];

	// srand(0);
	// for(int i=0; i < TAM; i++) {
	// 	for(int j=0; j < TAM; j++) {
	// 		vetor[i][j] = -1;
	// 	}
	// }

	// for(int i=0; i < TAM; i++) {
	// 	b = rand() % TAM;
	// 	if(checkPrimo(b)) {
	// 		for(int j=0; j < TAM / 20; j++) {
	// 			b = rand() % TAM;
	// 			if(i != j)
	// 				vetor[i][b] = b;
	// 		}
	// 	} else i++;
	// }

	// grafo denso
	// for(int i=0; i < TAM; i++) {
	// 	for(int j=0; j < TAM; j++) {
	// 		if(i != j) {
	// 			GraphInsertEdge(G, G->adj[i], G->adj[j]);
	// 		}
	// 	}
	// }

	// grafo esparso
	// srand(0);
	// for(int i=0; i < TAM; i++) {
	// 	for(int j=0; j < TAM / 2; j++) {
	// 		if(vetor[i][j] != -1 && vetor[i][j] != i && i != j) {
	// 			GraphInsertEdge(G, G->adj[i], G->adj[vetor[i][j]]);
	// 			GraphInsertEdge(G, G->adj[vetor[i][j]], G->adj[i]);
	// 		}
	// 	}
	// }

	int cont = 0;

	ImprimeGraph(G);

	// busca em profundidade
	// DFS(G);

	// busca em largura
	// BFS(G, G->adj[0], &cont);
	// printf("\ncont: %d\n", cont);


	return 0;
}

// 0,1,13
// 1,0
// 3,4,16
// 4,3,5
// 5,4
// 7,8
// 8,7,9,21
// 9,8,10
// 10,9,11,23
// 11,10,12,24
// 12,11,25
// 13,0,26
// 16,3,29
// 21,8,34
// 23,10,24,36
// 24,11,23,25,37
// 25,12,24,38
// 26,13,27,39
// 27,26,40
// 29,16,30,42
// 30,29,31,43
// 31,30,44
// 33,34,46
// 34,21,33
// 36,23,37
// 37,24,36,38
// 38,25,37,51
// 39,26,40
// 40,27,39,41
// 41,40,42
// 42,30,42,44
// 43,30,42,44,56
// 44,31,43,56
// 46,33,59
// 51,38,64
// 56,43,69
// 59,46,72
// 61,62,74
// 62,61,75
// 64,51,77
// 65,66,78
// 66,65,67
// 67,68,69
// 68,67,69
// 69,56,68,70
// 70,69
// 72,59,85
// 74,61,75,87
// 75,62,74,76,88
// 76,75,77
// 77,64,76
// 78,65,91
// 85,72,98
// 87,74,88,100
// 88,75,87,101
// 91,78,92,104
// 92,91,93,105
// 93,92,94,106
// 94,93,95,107
// 95,94,96,108
// 96,95,97,109
// 97,96,98,110
// 98,85,97,111
// 100,87,101,113
// 101,88,100,114
// 103,116
// 104,91,105,117
// 105,92,104,106
// 106,93,105,107
// 107,94,106,108
// 108,95,107,109
// 109,96,108,110
// 110,97,109,111
// 111,98,110,124
// 113,100,114
// 114,101,113
// 116,103,129
// 117,104,130
// 123,110,124,136
// 124,111,123
// 129,116,142
// 130,117,143
// 132,133,145
// 133,132,134,146
// 134,133,147
// 136,123,149
// 139,140,152
// 140,139,141,153
// 141,140,142
// 142,129,141,155
// 143,130,156
// 145,132,146,158
// 146,133,145,147,159
// 147,134,146,160
// 149,136,150,162
// 150,149,163
// 152,139,153,165
// 153,140,152,166
// 155,142,168
// 156,143,169
// 158,145,159,171
// 159,146,158,160,172
// 160,147,159,173
// 162,149,163,175
// 163,150,162,176
// 165,152,166,178
// 166,153,165,179
// 168,155,181
// 169,156,170
// 170,169,171
// 171,158,170,172
// 172,159,171,173
// 173,160,172
// 175,162,176
// 176,163,175,177
// 177,176,178
// 178,165,177,179
// 179,166,178
// 181,168
