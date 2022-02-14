#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dfs.h"
#include "grph.h"
#include "bfs.h"
#include <Windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	Graph G = GraphInitialize(100);
	int i,j;

	int V=G->V;
	clock_t Time_BFS[2]={0,0},Time_DFS[2]={0,0};
	for(i=0;i<10;i++)
	{
		for(i=0;i<V*8;i++)//GERA AS COMBINACOES DE VERTICES QUE SERAO LIGADOS POR UMA ARESTA A SER INSERIDA
		{	
			int a=rand()%V;
			int b=rand()%V;
			if(a!=b)
			{
				GraphInsertEdge(G, G->adj[a], G->adj[b]);//INSERCAO DA ARESTA
				
			}
			
		}
		
		
		
		int **matriz_adj_BFS=init_matriz(G,0),**matriz_adj_DFS=init_matriz(G,0),**matriz_inc_BFS=init_matriz(G,1),**matriz_inc_DFS=init_matriz(G,1);
		clock_t t[2];
		
		t[0]=clock();
		BFS_adj(G,G->adj[0],matriz_adj_BFS);
		t[1]=clock();
		Time_BFS[0]+=(t[1] - t[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		t[0]=clock();
		DFS_adj(G,matriz_adj_DFS);
		t[1]=clock();
		Time_DFS[0]+=(t[1] - t[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		t[0]=clock();
		BFS_inc(G,G->adj[0],matriz_inc_BFS);
		t[1]=clock();
		Time_BFS[1]+=(t[1] - t[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		t[0]=clock();
		DFS_inc(G,matriz_inc_DFS);
		t[1]=clock();
		Time_DFS[1]+=(t[1] - t[0]) * 1000.0 / CLOCKS_PER_SEC;
	
	
	}
	
	printf("\t[BFS]\n\n");
	printf("\t[ADJACENCIA] = %g\t[INCIDENCIA] = %g\n\n\n",Time_BFS[0]/10,Time_BFS[1]/10);
	printf("\t[DFS]\n\n");
	printf("\t[ADJACENCIA] = %g\t[INCIDENCIA] = %g\n\n\n",Time_DFS[0]/10,Time_DFS[1]/10);
	
	system("pause");
	return 0;
	

}
