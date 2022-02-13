#ifndef FILE_H
#define FILE_H

#define PATH_LABIRINTO "src/files/inputLabirinto"
#define PATH_MATRIZ "src/files/inputMatriz"

#include "lista.h"

#include <string.h>
#include <stdbool.h>
#include <time.h>

void readFile(Lista *l, char *path, int *cont, int valor);
void tokenizar(char *str, bool controle, ItemLista *item);

#endif