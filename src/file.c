#include "file.h"

/**
 * @brief realiza a leitura de um arquivo e tokeniza os valores
 * @param l lista para salvar os valores do arquivo
 * @param valor parametro utilizado para definir qual arquivo ira abrir
 *
 * utilizada pelo metodo labirinto
*/
void readFile(Lista *l, char *PATH, int *cont, int valor) {
	FILE *file;
	char *path = (char*)malloc(50 * sizeof(char));

	char *result, linha[400];
	bool controle = (strcmp(PATH, PATH_LABIRINTO) == 0) ? true : false;

	ItemLista item;

	sprintf(path, "%s%d.txt", PATH, valor);
	file = fopen(path, "r");
	item.contVetor = 0;

	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo em: %s\n", path);
		return;
	} else {
		while(!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if(result) {
				tokenizar(linha, controle, &item);
				LInsere(l, item);
				(*cont)++;
			}
		}
	}
	printf("\n");

	fclose(file);
	free(path);
}

/**
 * @brief tokeniza o valor utilizando o parametro ","
 * @param linha string que sera tokenizada
 * @param item lista que ira armazenar os valores tokenizados
 * @param controle para verificar se o path e labirinto ou matriz
 *
 * utilizado pelo metodo readFile
*/
void tokenizar(char *linha, bool controle, ItemLista *item) {
	const char sep[] = ",";
	bool aux = true;

	char *tokens = strtok(linha, sep);
	item->cont = 0;
	item->contVetor = 0;
	item->vetor = malloc((item->contVetor + 1) * sizeof(int));

	while(tokens != NULL) {
		if(controle) {
			if(aux) {
				aux = !aux;
				item->vertice = atoi(tokens);
			}
			else
				item->adj[item->cont++] = atoi(tokens);
		} else {
			item->vetor[item->contVetor++] = atoi(tokens);
			item->vetor = realloc(item->vetor ,(item->contVetor + 1) * sizeof(int));
		}
		tokens = strtok(NULL, sep);
	}
}