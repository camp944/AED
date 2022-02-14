#include "grph.h"

Vertex VertexInitialize(int value){
	int i;
	Vertex v=(Vertex)malloc(sizeof(Vertex));
	v->prox=NULL;
	v->value = value;
	
	return v;
}

Graph GraphInitialize(int V){
	Graph G=(Graph)malloc(sizeof(Graph*));
	G->V=V;
	G->E=0;
	G->adj=(Vertex*)malloc(V*sizeof(Vertex));
	int v;
	for(v=0; v<V; v++)
	{
		G->adj[v] = VertexInitialize(v);
	}
	
	return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2){
	Vertex v;
	for(v=v1;v->prox!=NULL;v=v->prox)
	{
		if(v->value==v2->value){return;}
	}
	
	G->adj[v->value]->prox = VertexInitialize(v2->value);
 	G->E++;
	
}





Fila* FFVazia(){
  Fila *f = (Fila*) malloc(sizeof(Fila));
  f->head = NULL;
  f->tail = NULL;
  return f;
}

void Queue(Fila *f, int vertex){
  Item *d = (Item *) malloc (sizeof(Item));
  d->data = vertex;
  d->prox = NULL;

  if(f->head == NULL){
    f->head = d;
    f->tail = d;
  }else{
    f->tail->prox = d;
    f->tail = d;
  }

  f->size ++;
}

Item* Dequeue(Fila *f){
  Item *aux;

  if(f->head == NULL)
    return NULL;

  aux = f->head;
  f->head = f->head->prox;
  f->size --;

  return aux;
}






int** init_matriz(Graph G,int tipo)
{
	int **mat=(int**)malloc(G->V * sizeof(int)),i,j;
	if(tipo==0)
	{
		for(i=0;i<G->V;i++)
		{
			mat[i]=(int*)malloc(G->V * sizeof(int));
			for(j=0;j<G->V;j++)
			{
				mat[i][j]=0;
			}
		}
	}
	else
	{
		for(i=0;i<G->V;i++)
		{
			mat[i]=(int*)malloc(G->E * sizeof(int));
			for(j=0;j<G->E;j++)
			{
				mat[i][j]=0;
			}
		}
	}
	

	return mat;
}


