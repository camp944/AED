#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "fila.h"
#include "pilha.h"
#include "base.h"
#include "ex4.h"
#define MAX 100

void menuEx4()
{
	printf("\n\n\n");
	printf("      ##################################################\n");
	printf("      #                                                #\n");
	printf("      #               CONSULTAR PRODUTO -> 1           #\n");
	printf("      #         IMPRIMIR HISTORICO DE BUSCAS -> 2      #\n");
	printf("      #              FINALIZAR A COMPRA -> 3           #\n");
	printf("      #              RESOLVER OUTROS EX -> 0           #\n");
	printf("      #                                                #\n");
	printf("      ##################################################\n\n\n");
}
void menuCarrinho()
{
	printf("\n\n\n");
	printf("      ###################################################\n");
	printf("      #                                                 #\n");
	printf("      #     DESEJA ADICIONAR O PRODUTO AO CARRINHO ?    #\n");
	printf("      #                                                 #\n");
	printf("      #                      SIM -> 1                   #\n");
	printf("      #                      NAO -> 0                   #\n");
	printf("      #                                                 #\n");
	printf("      ###################################################\n\n\n");
}

int Busca_produto(int id,FilaD ID,FilaD valor,PilhaD Hist)
{
	Bloco *aux_ID,*aux_valor;
	int valorf,cont,pos;
	valorf=-1;
	aux_ID=ID.first->prox;
	aux_valor=valor.first->prox;
	
	cont=0;
	pos=0;
	
	printf("\n\n         ID                VALOR EM R$\n");
	while(aux_ID!=NULL)
	{
		printf("\n\n         %d                     %d\n",aux_ID->dado.val,aux_valor->dado.val);
	 	if(id==aux_ID->dado.val)
	 	{
	 		valorf=aux_valor->dado.val;
		}
		aux_valor=aux_valor->prox;
	 	aux_ID=aux_ID->prox;
	 	pos++;
	 	
	}
	
	Item i;
	i.val=id;
	PDEmpilha(&Hist,i);
	
	
	return valorf;
}




void Imprime_tabela(FilaD ID,FilaC Nome)
{
	Bloco *aux_ID;
	Bloco1C *aux_nome;
	
	aux_ID=ID.first->prox;
	aux_nome=Nome.first->prox;
	
	printf("\n\n         ID                 PRODUTO\n");
	while(aux_ID!=NULL)
	{
	 	printf("      %d                 %s\n",aux_ID->dado.val,aux_nome->dado.caract);
	 	aux_ID=aux_ID->prox;
	 	aux_nome=aux_nome->prox;
	}
	printf("\n\n\n");
}

void Gera_tabela(FILE *arquivo,FilaD ID,FilaC Nome,FilaD valor)
{
	char leitor[MAX],token1[MAX];
	char *token;
	Item aux_int;
	Item1C aux_string;
	int contador_colunas=0;
	char separador[MAX]="><";
	while((fgets(leitor,100,arquivo)!=NULL))
	{
		token=strtok(leitor,separador);
		while(token!=NULL)
		{
			
			if(contador_colunas==0)
			{
				strcpy(aux_string.caract,token);
				aux_int.val=atoi(aux_string.caract);
				FDEnfileira(&ID,aux_int);
				token=strtok(NULL,separador);
				contador_colunas++;
				
			}
			else
			{
				if(contador_colunas==1)
				{
					strcpy(aux_string.caract,token);
					FCEnfileira(&Nome,aux_string);
					token=strtok(NULL,separador);
					contador_colunas++;
				}
				else
				{
					strcpy(aux_string.caract,token);
					aux_int.val=atoi(aux_string.caract);
					FDEnfileira(&valor,aux_int);
					token=strtok(NULL,separador);
					contador_colunas=0;
				}
			}
			
			
		}
		
	}
		

	
}


void resolve4()
{
	
	FILE *arquivo;
	int select=1;
	char leitor[MAX],arquivo_nome[MAX];
	Item aux;
	
	PilhaD hist_ID;
	Lista carrinho_valor,carrinho_ID;
	FilaD ID,valor;
	FilaC Nome;
	
	PDVazia(&hist_ID);
	LVazia(&carrinho_valor);
	LVazia(&carrinho_ID);
	FDVazia(&ID);
	FDVazia(&valor);
	FCVazia(&Nome);
	
	
	
	arquivo=NULL;
	
	
	while(arquivo==NULL)
	{
		printf("\n\n   INSIRA O NOME DO ARQUIVO DE DISCO: ");
		gets(arquivo_nome);
		arquivo=fopen(arquivo_nome,"r+");
		
		if(arquivo==NULL)
		{
		
		}else
		{
			printf("\n          ARQUIVO ABERTO\n\n\n");
		}
	}    
	
	Gera_tabela(arquivo,ID,Nome,valor);
	
	while(select!=0)
	{
		menuEx4();
		printf("      ->");
		scanf("%d",&select);
		
		if(select==0)
		{
			break;
		}
		if(select==1)
		{
			int select_ID,pos,valorf;
			valorf=-1;
			while(valorf<0)
			{
				Imprime_tabela(ID,Nome);
				printf("      INSIRA O ID DO PRODUTO DESEJADO ->");
				scanf("%d",&select_ID);
				valorf=Busca_produto(select_ID,ID,valor,hist_ID);
				if(valorf<0)
				{
					printf("\n\n      O ID INSERIDO NAO ESTA REGISTRADO");
				}
			}
			aux.val=select_ID;
			PDEmpilha(&hist_ID,aux);
			
			
			select_ID=1;
			while(select_ID!=0)
			{
				menuCarrinho();
				printf("       ->");
				scanf("%d",&select_ID);	
				
				if(select_ID==1)
				{
					int unidades;
					LInserir(&carrinho_ID,aux);
					printf("      INSIRA A QUANTIDADE DESEJADA DO PRODUTO ->");
					scanf("%d",&unidades);
					aux.val=valorf*unidades;
					LInserir(&carrinho_valor,aux);
					
				}
			}
			
			
			
		}
		if(select==2)
		{
			printf("\n     HISTORICO DE PRODUTOS BUSCADOS (ID)\n");
			PDImprime(&hist_ID);
				
		}
		if(select==3)
		{
			Bloco *valor_final;
			int soma;
			soma=0;
			valor_final=carrinho_valor.primeiro->prox;
			while(valor_final!=carrinho_valor.ultimo->prox)
			{
				soma=soma+valor_final->dado.val;
				valor_final=valor_final->prox;
			}
			
			printf("\n\n\n      VALOR FINAL DA COMPRA ==> R$%d,00\n\n",soma);
			break;
		}
	}
	
}
