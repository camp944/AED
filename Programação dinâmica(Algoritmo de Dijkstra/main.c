#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "estruturas.h"
#include "funcoes.h"

int main()
{

	srand(time(NULL));
	
	Graph G = GraphInitialize(10);//INICIALIZA O GRAFO
	int *dist=(int*)malloc(G->V * sizeof(int));//INICIA O ARRAY QUE ARMAZENARA AS DISTANCIAS
	int i,j,ini=-1,laco=0;
	
	printf("\n");
	
	while(ini<0 || ini>9)
	{
		printf("\nDeseja partir de qual vertice?(0 a 9)-> ");// LE O VERTICE QUE SERA USADO COMO BASE
		scanf("%d",&ini);
	}
	

	for(i=0;i<80;i++)//GERA AS COMBINACOES DE VERTICES QUE SERAO LIGADOS POR UMA ARESTA A SER INSERIDA
	{	
		int a=rand()%10;
		int b=rand()%10;
		if(a!=b)
		{
			GraphInsertEdge(G, G->adj[a], G->adj[b]);//INSERCAO DA ARESTA
			laco++;
		}
		
	}
	
	printf("\n\n");
	printf("\n\tARESTAS REPETIDAS NAO INSERIDAS -> %d",laco-G->E);
	printf("\n\tARESTAS INSERIDAS -> %d",G->E);
	printf("\n\n");
	CloseRoute(G,ini,dist);//BUSCA E IMPRESSÃO DOS MENORES CAMINHOS
	printf("\n\n");
	system("pause");;

	return 0;
}
