#ifndef FILE_H
#define FILE_H

#define PATH_LABIRINTO "src/files/inputLabirinto"

#include "lista.h"

#include <string.h>
#include <stdbool.h>

void readFile(Lista *l, int valor, int *quant);
void tokenizar(char *str, ItemLista *item);

#endif