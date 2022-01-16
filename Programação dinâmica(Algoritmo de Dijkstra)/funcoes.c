#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "funcoes.h"
#include "estruturas.h"

int Search_CloseRoute(int *visited, int *dist,Graph G)//BUSCA OS VERTICES MAIS PROXIMOS NÃO VISITADOS
{
	int	min=INT_MAX,i,min_index;
 

    for(i=0;i<G->V;i++)
    {
		if (dist[i] < min && visited[i] == 0)
		{
			min = dist[i];
		    min_index = i;
		}
	}      
 
    return min_index;
}

void CloseRoute(Graph G,int ini, int *dist)//CALCULA A MENOR ROTA ENTRE OS VERTICES E IMPRIME AS DISTANCIAS
{
	int i,cont;
	int *visited=(int*)malloc(G->V * sizeof(int));
	for(i=0;i<G->V;i++)
	{
		dist[i]=INT_MAX;
		visited[i]=0;
	}

	dist[ini]=0;
	
	for(cont=0;cont<G->V;cont++) 
	{
		int u=Search_CloseRoute(visited,dist,G);
        visited[u]=1;
        
        for(i=0;i<G->V;i++)
        {	
       
        	if (G->adj[u]->cost[i] > 0 && visited[i] == 0 && dist[i] > dist[u] + G->adj[u]->cost[i])
            {
            	dist[i] = dist[u] + G->adj[u]->cost[i];
			}
		}
            
	}
						
	Imprimir(dist,G,ini);
}


void Imprimir(int *dist,Graph G,int ini)//IMPRIME A MENOR DISTANCIA ENTRE O VERTICE DE ORIGEM E OS DEMAIS VERTICES
{
	printf("\t[MENOR DISTANCIA DOS VERTICES PARTINDO DO VERTICE %d]\n\n",ini);
	int i;
	for (i=0;i<G->V;i++)
	{
		printf("\t[VERTICE %d = %d]\n",i,dist[i]);
	}
}
