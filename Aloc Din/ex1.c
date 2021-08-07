#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "base.h"
#include "lista.h"
#include "ex1.h"

void menuEx1()
{
	printf("\n\n\n");
	printf("      ##############################################\n");
	printf("      #                                            #\n");
	printf("      #        RESOLVER o EX 1 letra A -> 1        #\n");
	printf("      #        RESOLVER o EX 1 letra B -> 2        #\n");
	printf("      #        RESOLVER o EX 1 letra C -> 3        #\n");
	printf("      #          RESOLVER OUTROS EX -> 0           #\n");
	printf("      #                                            #\n");
	printf("      ##############################################\n\n\n");
}

void resolve1A()//Pronto
{

	srand(time(NULL));
	int cont;
	cont=0;
	Item i;
	Lista l1,l2,lf;
	LVazia(&l1);
	LVazia(&l2);

	
	
	while(cont<100)//GERA AS LISTAS
	{
		
		i.val=rand()%200;
		LInserir(&l1,i);
		i.val=rand()%200;
		LInserir(&l2,i);
		cont++;
	}
		
	
	cont=0;
	LVazia(&lf);
	
	Bloco *aux1,*aux2;
	aux1=l1.primeiro->prox;
	aux2=l2.primeiro->prox;
	
	
	
	while(cont<100)//CONCATENA AS LISTAS
	{
		if(lf.primeiro==lf.ultimo)
		{
			LInserir(&lf,aux1->dado);
			LInserir(&lf,aux2->dado);
		}
		else
		{
			aux1=aux1->prox;
			LInserir(&lf,aux1->dado);
			aux2=aux2->prox;
			LInserir(&lf,aux2->dado);
			
		}
		cont++;
	}
	
	printf("      LISTA 1:\n\n");
	LImprime(&l1);
	printf("\n\n      LISTA 2:\n\n");
	LImprime(&l2);
	printf("\n\n      LISTA 3:\n\n");
	LImprime(&lf);
	
}
void resolve1B()//Pronto
{
	int tam,cont,subt,soma1,soma2;
	tam=4;
	soma1=0;
	soma2=0;
	Lista l1,l2,lauxPares;
	LVazia(&l1);
	LVazia(&l2);
	Item i;
	
	while(tam>3||tam<1)//LÊ O TAMANHO DAS LISTAS
	{
		printf("INSIRA O TAMANHO DA LISTA-> ");
		scanf("%d",&tam);
	}
	
	srand(time(NULL));
	cont=0;
	
	while(cont<tam)//CRIA AS DUAS LISTAS
	{
		i.val=(rand()%10+2);
		LInserir(&l1,i);
		i.val=(rand()%10+2);
		LInserir(&l2,i);
		cont++;
	}
	
	subt=(rand()%10+2);
	
	Bloco *aux1,*aux2;
	aux1=l1.primeiro->prox;
	aux2=l2.primeiro->prox;
	LVazia(&lauxPares);
	cont=0;
	printf("\n      VALOR ALEATORIO GERADO ========= %d\n",subt);
	
	while(cont<tam)//CRIA A LISTA DE PARES, SUBTRAI O VALOR DOS PARES E SOMA AS LISTAS
	{
		if(lauxPares.primeiro==lauxPares.ultimo)
		{
			LInserir(&lauxPares,aux1->dado);
			soma1=soma1+aux1->dado.val-subt;
			LInserir(&lauxPares,aux2->dado);
			soma2=soma2+aux2->dado.val-subt;
			
		}
		else
		{
			aux1=aux1->prox;
			LInserir(&lauxPares,aux1->dado);
			soma1=soma1+aux1->dado.val-subt;
			
			aux2=aux2->prox;
			LInserir(&lauxPares,aux2->dado);
			soma2=soma2+aux2->dado.val-subt;
			
		}
		
		cont++;
	}
	
	printf("\n      LISTA COM OS PARES\n\n");
	LImprime(&lauxPares);
	
	if(soma1>soma2)//IMPRIME O VENCEDOR
	{
		printf("\n\n\n      A LISTA 1 GANHOU!!!\n\n");
		LImprime(&l1);
	}
	else
	{
		if(soma1>soma2)
		{
			printf("\n\n\n      A LISTA 2 GANHOU!!!\n\n");
			LImprime(&l2);
		}
		else
		{
			printf("\n\n\n      HOUVE UM EMPATE!!!\n\n");
			
		}
	}
	
}
void resolve1C()//FALTA FAZER
{
	
}
