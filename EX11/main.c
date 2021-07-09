#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "resgate.h"
#define MAX_TAM 10
#define MAX 5
#define MAX_NAME 30


int main(int argc, char *argv[]) {
	
	FILE *arquivo;
	int discoF[MAX_TAM][MAX_NAME],select=1,n_linhas,busca_linha,busca_elemento;
	item a;
	TP transportador;
	char discoI[MAX_TAM][MAX_NAME],leitor[30],arquivo_nome[MAX_NAME];
	fila f;
	
	arquivo=NULL;
	
	
	while(arquivo==NULL)
	{
		printf("\n\n   INSIRA O NOME DO ARQUIVO DE DISCO: ");
		gets(arquivo_nome);
		arquivo=fopen(arquivo_nome,"r+");
		if(arquivo==NULL)
		{
			printf("\n          ERRO AO ABRIR\n\n\n");
		}else
		{
			printf("\n          ARQUIVO ABERTO\n\n\n");
		}
	}    
	
	
	Read_txt(discoI,arquivo,discoF,n_linhas);
	Inicio(&f);
		
	while(select!=0)
	{
		if(discoF[0][0]>MAX_TAM)
		{
			printf("          O ARQUIVO NAO SEGUE OS PADROES ESPECIFICADOS\n\n\n\n");
			break;
			
		}
		else
		{	
			int cont=1;
			while(cont<discoF[0][0])
			{
				if(discoF[0][cont]>MAX_NAME)
				{
					printf("          O ARQUIVO NAO SEGUE OS PADROES ESPECIFICADOS\n\n\n\n");
					break;
				}
				cont++;
			}
		}
		
		printf("\n\n\n\n");
		printf("                              MENU                    \n");
		printf("          ____________________________________________\n");
		printf("          |                                          |\n");
		printf("          |        BUSCAR VALOR NO DISCO -> 1        |\n");
		printf("          |             IMPRIMIR FILA -> 2           |\n");
		printf("          |           ENCERRAR PROGRAMA -> 0         |\n");
		printf("          |                                          |\n");
		printf("          --------------------------------------------\n\n\n");
		
		printf("          INSIRA A OPCAO DESJADA:");
		scanf("%d",&select);
		
		if(select==1)
		{
			printDisco(discoF);
			printf("INSIRA A LINHA EM QUE DESEJA BUSCAR O VALOR PARA A MEMORIA: A");
			scanf("%d",&busca_linha);
			printf("INSIRA O VALOR QUE DESEJA BUSCAR O VALOR PARA A MEMORIA: ");
			scanf("%d",&busca_elemento);
			transportador=GetDisco(discoF,busca_linha,busca_elemento,&f);
			if((transportador.passageiro.pos_disc[0]==-1)||(transportador.passageiro.pos_disc[0]==-2))
			{
				
			}
			else
			{
				
				if(f.full==5)
				{
					
					FullQueue(&f,discoF);
					
				}
				
				InQueue(&f,transportador.passageiro);
			
				printf("\n\n        ARQUIVO ENCONTRADO E INSERIDO NA FILA\n\n");
			
				
				
			}
			
		
		}
		else
		{
			if(select==2)
			{
				printf("\n          ");
				printFila(&f);
			}
			
		
		}
				
		
			
	}
	
	
	fclose(arquivo);
	


	return 0;
}
