#ifndef ESTRUTURAS_H 
#define ESTRUTURAS_H
#define MAX 100
#include<stdlib.h>
#include<stdio.h>
#include <limits.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;


struct TipoVertex{
  int value,grau;
  int *cost;
  Vertex *prox;
};


struct graph{
  int V;
  int E;
  Vertex *adj;
};

Vertex VertexInitialize(int value,Graph G);
Graph GraphInitialize(int V);
void VertexJumpCost(Vertex v, Vertex v2);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);




#endif
