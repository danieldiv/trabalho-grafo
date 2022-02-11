#include "file.h"

/**
 * @brief realiza a leitura de um arquivo e tokeniza os valores
 * @param l lista para salvar os valores do arquivo
 * @param valor parametro utilizado para definir qual arquivo ira abrir
 *
 * utilizada pelo metodo labirinto
*/
void readFile(Lista *l,  int valor) {
	FILE *file;
	char *path = (char*)malloc(50 * sizeof(char));

	char *result, linha[100];

	ItemLista item;

	sprintf(path, "%s%d.txt", PATH_LABIRINTO, valor);

	file = fopen(path, "r");

	if(file == NULL) {
		printf("Nao foi possivel abrir o arquivo em: %s\n", path);
		return;
	} else {
		while(!feof(file)) {
			result = fgets(linha, sizeof(linha), file);

			if(result) {
				tokenizar(linha, &item);
				LInsere(l, item);
			}
		}
	}

	fclose(file);
	free(path);
}

/**
 * @brief tokeniza o valor utilizando o parametro ","
 * @param linha string que sera tokenizada
 * @param item lista que ira armazenar os valores tokenizados
 *
 * utilizado pelo metodo readFile
*/
void tokenizar(char *linha, ItemLista *item) {
	const char sep[] = ",";
	bool aux = true;

	char *tokens = strtok(linha, sep);
	item->cont = 0;

	while(tokens != NULL) {
		if(aux) {
			aux = !aux;
			item->vertice = atoi(tokens);
		}
		else {
			item->adj[item->cont++] = atoi(tokens);
		}
		tokens = strtok(NULL, sep);
	}
}