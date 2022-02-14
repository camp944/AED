#ifndef GRPH_H 
#define GRPH_H

#include<stdlib.h>
#include<stdio.h>

typedef struct graph *Graph;
typedef struct TipoVertex *Vertex;

typedef struct TipoItem Item;
typedef struct TipoFila Fila;

//fila
struct TipoItem{
    int data;
  Item *prox;
};

struct TipoFila{
  Item *head;
  Item *tail;
  int size;
};


struct TipoVertex{
  int value;
  Vertex prox;
};


struct graph{
  int V;
  int E;
  Vertex *adj;
};


Fila* FFVazia();
void Queue(Fila *f, int vertex);
Item* Dequeue(Fila *f);


Vertex VertexInitialize(int value);
Graph GraphInitialize(int V);
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2);
void ImprimeGraph(Graph G);


int** init_matriz(Graph G,int tipo);

#endif
