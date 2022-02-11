#include "graph.h"
#include "file.h"

#include <stdbool.h>

#define TAMLAB 297

// matriz de entrada para o metodo printLabirinto
int labirintoPossivel[2][TAMLAB] = {
	{0,0,1,3,3,4,4,5,7,8,8,8,9,9,10,10,10,11,11,11,12,12,13,13,16,16,21,21,23,23,23,24,24,24,24,25,25,25,26,26,26,27,27,29,29,29,30,30,30,31,31,33,33,34,34,36,36,37,37,37,38,38,38,39,39,40,40,40,41,41,42,42,42,43,43,43,43,44,44,44,46,46,51,51,56,56,59,59,61,61,62,62,64,64,65,65,66,66,67,67,68,68,69,69,69,70,72,72,74,74,74,75,75,75,75,76,76,77,77,78,78,85,85,87,87,87,88,88,88,91,91,91,92,92,92,93,93,93,94,94,94,95,95,95,96,96,96,97,97,97,98,98,98,100,100,100,101,101,101,103,104,104,104,105,105,105,106,106,106,107,107,107,108,108,108,109,109,109,110,110,110,110,111,111,111,113,113,114,114,116,116,117,117,123,123,123,124,124,129,129,130,130,132,132,133,133,133,134,134,136,136,139,139,140,140,140,141,141,142,142,142,143,143,145,145,145,146,146,146,146,147,147,147,149,149,149,150,150,152,152,152,153,153,153,155,155,156,156,158,158,158,159,159,159,159,160,160,160,162,162,162,163,163,163,165,165,165,166,166,166,168,168,169,169,170,170,171,171,171,172,172,172,173,173,175,175,176,176,176,177,177,178,178,178,179,179,181},
	{1,13,0,4,16,3,5,4,8,7,9,21,8,10,9,11,23,10,12,24,11,25,0,26,3,29,8,34,10,24,36,11,23,25,37,12,24,38,13,27,39,26,40,16,30,42,29,31,43,30,44,34,46,21,33,23,37,24,36,38,25,37,51,26,40,27,39,41,40,42,29,41,44,30,42,44,56,31,43,56,33,59,38,64,43,69,46,72,62,74,61,75,51,77,66,78,65,67,66,69,67,69,56,68,70,69,59,85,61,75,87,62,74,76,88,75,77,64,76,65,91,72,98,74,88,100,75,87,101,78,92,104,91,93,105,92,94,106,93,95,107,94,96,108,95,97,109,96,98,110,85,97,111,87,101,113,88,100,114,116,91,105,117,92,104,106,93,105,107,94,106,108,95,107,109,96,108,110,97,109,111,123,98,110,124,100,114,101,113,103,129,104,130,110,124,136,111,123,116,142,117,143,133,145,132,134,146,133,147,123,149,140,152,139,141,153,140,142,129,141,155,130,156,132,146,158,133,145,147,159,134,146,160,136,150,162,149,163,139,153,165,140,152,166,142,168,143,169,145,159,171,146,158,160,172,147,159,173,149,163,175,150,162,176,152,166,178,153,165,179,155,181,156,170,169,171,158,170,172,159,171,173,160,172,162,176,163,175,177,176,178,165,177,179,166,178,168}
};

// matriz de entrada para o metodo printLabirinto
int labirintoImpossivel[2][TAMLAB - 4] = {
	{0,0,1,3,3,4,4,5,7,8,8,8,9,9,10,10,10,11,11,11,12,12,13,13,16,16,21,21,23,23,23,24,24,24,24,25,25,25,26,26,26,27,27,29,29,29,30,30,30,31,31,33,33,34,34,36,36,37,37,37,38,38,38,39,39,40,40,40,41,41,42,42,42,43,43,43,43,44,44,44,46,46,51,51,56,56,59,59,61,61,62,62,64,64,65,65,66,66,67,67,68,68,69,69,69,70,72,72,74,74,74,75,75,75,75,76,76,77,77,78,78,85,85,87,87,87,88,88,88,91,91,91,92,92,92,93,93,93,94,94,94,95,95,95,96,96,96,97,97,97,98,98,98,100,100,100,101,101,101,103,104,104,104,105,105,105,106,106,106,107,107,107,108,108,108,109,109,109,110,110,110,110,111,111,111,113,113,114,114,116,116,117,117,123,123,123,124,124,129,129,130,130,132,132,133,133,133,134,134,136,136,139,139,140,140,140,141,141,142,142,142,143,143,145,145,145,146,146,146,146,147,147,147,149,149,149,150,150,152,152,152,153,153,153,155,155,156,156,158,158,158,159,159,159,159,160,160,160,162,162,162,163,163,163,165,165,165,166,166,166,168,168,169,169,170,170,171,171,171,172,172,172,173,173,175,175,176,176,            178,    178,179,179,181},
	{1,13,0,4,16,3,5,4,8,7,9,21,8,10,9,11,23,10,12,24,11,25,0,26,3,29,8,34,10,24,36,11,23,25,37,12,24,38,13,27,39,26,40,16,30,42,29,31,43,30,44,34,46,21,33,23,37,24,36,38,25,37,51,26,40,27,39,41,40,42,29,41,44,30,42,44,56,31,43,56,33,59,38,64,43,69,46,72,62,74,61,75,51,77,66,78,65,67,66,69,67,69,56,68,70,69,59,85,61,75,87,62,74,76,88,75,77,64,76,65,91,72,98,74,88,100,75,87,101,78,92,104,91,93,105,92,94,106,93,95,107,94,96,108,95,97,109,96,98,110,85,97,111,87,101,113,88,100,114,116,91,105,117,92,104,106,93,105,107,94,106,108,95,107,109,96,108,110,97,109,111,123,98,110,124,100,114,101,113,103,129,104,130,110,124,136,111,123,116,142,117,143,133,145,132,134,146,133,147,123,149,140,152,139,141,153,140,142,129,141,155,130,156,132,146,158,133,145,147,159,134,146,160,136,150,162,149,163,139,153,165,140,152,166,142,168,143,169,145,159,171,146,158,160,172,147,159,173,149,163,175,150,162,176,152,166,178,153,165,179,155,181,156,170,169,171,158,170,172,159,171,173,160,172,162,176,163,175,            165,    179,166,178,168}
};

void printLabirinto();
int menu();

void labirinto(int file);
void gerarGrafo(bool type);
void exemploAula();

int main(){
    int op;

    do {
        system("clear");
        op = menu();

        switch(op) {
            case 1:
                labirinto(1);
            break;
            case 2:
                labirinto(2);
            break;
            case 3:
				gerarGrafo(true);
            break;
            case 4:
				gerarGrafo(false);
            break;
            case 5:
                exemploAula();
            break;
            case 0:
                printf("O programa sera finalizado!\n");
                return EXIT_SUCCESS;
            default:
                printf("Opcao invalida!\n");
        }
        system("read -p \"\nPressione enter para continuar...\" continue");
	} while (op != 0);

	return EXIT_SUCCESS;
}

// menu de opcoes principal
int menu() {
	int op;

	printf("====================\n");
	printf("   MENU DE OPCOES\n");
	printf("====================\n\n");

	printf("1 - Labirinto (caminho 1)\n");
	printf("2 - Labirinto (caminho 2)\n");
	printf("3 - Rota de aviao em grafo denso\n");
	printf("4 - Rota de aviao em grafo esparso\n");
	printf("5 - Grafo do exemplo da aula\n");
	printf("0 - Sair\n\n");

	printf("Escolha uma opção: ");
	scanf("%d", &op);

	return op;
}

// cria um grafo com o exemplo utilizado em aula
void exemploAula() {
    Graph G = GraphInitialize(10);
    int cont = 0;

    grafoExemplo(G);

    printf("\nImpressao do grafo\n\n");
    ImprimeGraph(G);

    printf("\nBusca em largura\n\n");
    BFS(G, G->adj[0], &cont);

    printf("\nBusca em profundidade\n\n");
    BFS(G, G->adj[0], &cont);
}

/**
 * @brief cria um grafo onde todos os vertices estao conectados ou esparsos
 * @param type tipo do grafo a ser utilizado, true -> todos os caminhos conectados, false -> alguns caminhos desconectados
*/
void gerarGrafo(bool type) {
	int V, cont = 0;

	printf("Quantidade de vertices do grafo: ");
	scanf("%d", &V);

    if(V > 0) {
        Graph G = GraphInitialize(V);

        if(type) {
            grafoDenso(G, G->V);
        } else
            grafoEsparso(G, G->V);

        printf("\nImpressao do grafo\n\n");
        ImprimeGraph(G);

        printf("\nBusca em largura\n\n");
        BFS(G, G->adj[0], &cont);
        printf("\ncont: %d\n", cont);

        // caso o grafo possua um vertice isolado, o BFS nao conseguira visitar, fazendo o contador ser menor do que V
        if(cont == G->V) {
            if(cont == 1)
                printf("Nao existe rotas para o aviao viajar\n");
            else
                printf("É possivel o aviao viajar em todas as rotas\n");
        }

        else if(cont == 1)
            printf("O aviao nao consegue sair da origem\n");
        else
            printf("Possui vertices (rotas) que nao estao conectadas, logo o aviao nao pode viajar em todas as rotas\n");
    } else
        printf("O valor precisa ser maior do que 0\n");
}

/**
 * @brief verifica a possibilidade de se chegar ao final de um labirinto
 * @param file nome do arquivo .txt que sera aberto
 *
 * existe dois labirintos para se percorre, o primeiro contem as paredes e os caminhos, sendo possivel chegar em qualquer vertice que nao seja parede
 * o segundo labirinto mantem a mesma base do primeiro, porem, o vertice (caminho) 77 é desconectado dos demais, simulando uma parede em seu lugar
*/
void labirinto(int file) {
    Lista l;

    FLVazia(&l);
    readFile(&l, file);
	Graph G = GraphInitialize(182);

    Block *aux;
    int i, cont = 0;

	aux = l.first->prox;
	while(aux != NULL) {
        i = 0;
		while(i < aux->dado.cont)
		    GraphInsertEdge(G, G->adj[aux->dado.vertice], G->adj[aux->dado.adj[i++]]);
		aux = aux->prox;
	}

    int fimLabirinto; // < 0 -> nao ira buscar o fim do labirinto, >= 0 -> ira buscar o fim do labirinto

    printf("Informe o vertice final para o fim do labirinto (0 to 181): ");
    scanf("%d", &fimLabirinto);

    ImprimeGraph(G);

    printf("\nBuscando pela BFS:\n\n");
    BFS(G, G->adj[0], &cont);

    printf("\nBuscando pela DFS:\n\n");
    DFS(G, fimLabirinto);

    if(fimLabirinto < 0)
        printf("\nNao existe caminho negativo no labirinto!\n");
    else
        printf("cont: %d\n", cont);
}

// Gera valores para serem salvos em um arquivo txt, utilizando uma matriz como entrada
void printLabirinto() {
    int aux = labirintoImpossivel[0][0];
    int control = 0;

	for(int j=0; j < TAMLAB; j++) {
        if(aux == labirintoImpossivel[0][j]) {
            if(control == 0) {
                control = 1;
                printf("%3d,%d", aux, labirintoImpossivel[1][j]);
            } else
                printf(",%d", labirintoImpossivel[1][j]);
        }
        else {
            printf("\n");
            aux = labirintoImpossivel[0][j];
            control = 0;
            j--;
        }
	}
    printf("\n");
}