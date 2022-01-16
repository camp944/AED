#include "estruturas.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>



Vertex VertexInitialize(int value,Graph G)//INICIALIZA O VERTICE
{
	
	int i;
	Vertex v=(Vertex)malloc(sizeof(Vertex));
	v->prox=(Vertex*)malloc(G->V * sizeof(Vertex));
	v->cost=(int*)malloc(G->V * sizeof(int));
	for(i=0;i<G->V;i++)
	{		
		v->prox[i] = NULL;
		v->cost[i]=0;
	}
	v->grau=0;
	v->value = value;
	
	return v;
}

void VertexJumpCost(Vertex v,Vertex v2)//GERA O TAMNHO OU PESO DA ARESTA QUE SERA ADICIONADA
{
	int a=-1;
	while(a<=0)
	{
		a=rand()%16;
	}
	v2->cost[v->value]=a;
	v->cost[v2->value]=a;
}

Graph GraphInitialize(int V)//INICIALIZA O GRAFO
{
	Graph G=(Graph)malloc(sizeof(Graph*));
	G->V=V;
	G->E=0;
	G->adj=(Vertex*)malloc(V*sizeof(Vertex));
	
		
	int v;
	for(v=0;v<V;v++)
	{
		G->adj[v]=VertexInitialize(v,G);
		
	}
	
	return G;
}

void GraphInsertEdge(Graph G, Vertex v1, Vertex v2)//ADICIONA UMA ARESTA 
{
	
	int i;
	for(i=0;i<G->V;i++)
	{

		if(v1->prox[i] != NULL )
		{	
			if((v1->prox[i]->value == v2->value))
			{
//				printf("[ERROR] A ARESTA GERADA JA EXISTE!!\n");
  				return;	
			}			
		}
	}
		
	v1->grau++;
	VertexJumpCost(v1,v2);
//	printf(" %d to %d = %d\n",v1->value,v2->value,v2->cost[v1->value]);
	v1->prox[v2->value]=v2;
	v2->prox[v1->value]=v1;
	G->E++;
	
}



 
