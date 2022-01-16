#ifndef FUNCOES_H 
#define FUNCOES_H
#include <limits.h>
#include "estruturas.h"


void CloseRoute(Graph G,int ini, int *dist);
int Search_CloseRoute(int *visited, int *dist,Graph G);
void Imprimir(int *dist,Graph G,int ini);



#endif
