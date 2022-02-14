#ifndef BFS_H 
#define BFS_H

#include "grph.h"

#include<stdio.h>
#include<stdlib.h>

void BFS_adj(Graph G, Vertex s,int **matriz);
void BFS_inc(Graph G, Vertex s,int **matriz);

#endif
