#ifndef DFS_H 
#define DFS_H

#include "grph.h"

#include<stdio.h>
#include<stdlib.h>


void DFS_adj(Graph G,int **matriz);
void DFS_VISIT_adj(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo,int **matriz);
void DFS_inc(Graph G,int **matriz);
int DFS_VISIT_inc(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo,int **matriz,int cont_edge);
#endif
