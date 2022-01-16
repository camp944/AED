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
	int i,j,ini=-1,laco=0,V;
	
	printf("\n");
	printf("\n\tDeseja inserir quantos vertices? -> ");// LE O NUMERO DE VERTICES QUE SERAO INSERIDOS
	scanf("%d",&V);
	while(ini<0 || ini>V)
	{
		printf("\n\tDeseja partir de qual vertice?(0 a %d)-> ",V-1);// LE O VERTICE QUE SERA USADO COMO BASE
		scanf("%d",&ini);
	}
	

	for(i=0;i<V*6;i++)//GERA AS COMBINACOES DE VERTICES QUE SERAO LIGADOS POR UMA ARESTA A SER INSERIDA
	{	
		int a=rand()%V;
		int b=rand()%V;
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
	system("pause");

	return 0;
}
