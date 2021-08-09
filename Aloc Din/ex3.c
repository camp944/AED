#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "fila.h"
#include "base.h"
#include "ex3.h"
#include "ex2.h"


void menuEx3()
{
	printf("\n\n\n");
	printf("      ##############################################\n");
	printf("      #                                            #\n");
	printf("      #        RESOLVER O EX 3 LETRA A -> 1        #\n");
	printf("      #        RESOLVER O EX 3 LETRA B -> 2        #\n");
	printf("      #          RESOLVER OUTROS EX -> 0           #\n");
	printf("      #                                            #\n");
	printf("      ##############################################\n\n\n");
}

int combina(int fator,int base)
{
	int fat1,fat2,fat3,aux;
	int combinacao;
	fat1=1;
	fat2=1;
	fat3=1;
	
	
	if(fator==0||fator==base)
	{
		return 1;
	}
	
	for(aux=base;aux>1;aux--)
	{
		fat1=fat1*aux;
	}
	
	for(aux=fator;aux>1;aux--)
	{
		fat2=fat2*aux;
	}
	
	for(aux=(base-fator);aux>1;aux--)
	{
		fat3=fat3*aux;
	}
	
	combinacao=fat1/(fat2*fat3);
	
	return combinacao;
	
}

void resolve3A()//PRONTO
{
	int dimen,fator;
	Item binomio;
	FilaD f;
	FDVazia(&f);
	
	printf("      INSIRA A DIMENSAO DO POLINOMIO ->");
	scanf("%d",&dimen);
	
	for(fator=0;fator<=dimen;fator++)
	{
		binomio.val=combina(fator,dimen);
		FDEnfileira(&f,binomio);
	}
	
	FDImprime(&f);
}

void resolve3B()
{
	srand(time(NULL));

	int info[5]={1,2,3,4,5},cont;//pares=1 impares=2 quadrados=3 cubos=4 e primos=5
	cont=0;
	FilaD Entrada,classificados;
	
	FDVazia(&Entrada);
	FDVazia(&classificados);
	Item i;
	while(cont<5)
	{
		i.val=rand()%100;
		FDEnfileira(&Entrada,i);
		cont++;
	}
	
	Bloco *aux;
	
	aux=Entrada.first->prox;
	
	printf("\n\n      FILA ENTRADA:");
	FDImprime(&Entrada);
	
	while(aux!=Entrada.last->prox)
	{
		int testePar,testeImpar,testeQuadrado,testeCubo,testePrimo;
		
		testePrimo=totiente(aux->dado.val);
		if(testePrimo==aux->dado.val-1)
		{
			i.val=info[4];
			FDEnfileira(&classificados,i);
		}
		else
		{
			testeCubo=cbrt(aux->dado.val);
			if((testeCubo-cbrt(aux->dado.val))==0)
			{
				i.val=info[3];
				FDEnfileira(&classificados,i);
			}
			else
			{
				testeQuadrado=sqrt(aux->dado.val);
				if((testeQuadrado-sqrt(aux->dado.val))==0)
				{
					i.val=info[2];
					FDEnfileira(&classificados,i);
				}
				else
				{
					testeImpar=aux->dado.val%2;
					
					if(testeImpar==1)
					{
						i.val=info[1];
						FDEnfileira(&classificados,i);
					}
					else
					{
						
						i.val=info[0];
						FDEnfileira(&classificados,i);
						
					}
					
				}
			}	
		}
		
		aux=aux->prox;
		
	}
	
	aux=classificados.first->prox;
	int soma=0;
	
	while(aux!=classificados.last->prox)
	{
			
		soma=soma+aux->dado.val;	
				
		if(aux==classificados.last)
		{
			
			int testePar,testeImpar,testeQuadrado,testeCubo,testePrimo;
		
			testePrimo=totiente(soma);
			if(testePrimo==soma)
			{
				i.val=info[4];
				
			}
			else
			{
				testeCubo=cbrt(soma);
				if((testeCubo-cbrt(soma))==0)
				{
					i.val=info[3];
				
				}
				else
				{
					testeQuadrado=sqrt(soma);
					if((testeQuadrado-sqrt(soma))==0)
					{
						i.val=info[2];
						
					}
					else
					{
						testeImpar=soma%2;
						
						if(testeImpar==1)
						{
							i.val=info[1];
							
						}
						else
						{
							
							i.val=info[0];
							
							
						}
						
					}
				}	
			}
			
		}
		
		aux=aux->prox;
		
	}	
	
	printf("\n\n      FILA CLASIFFICADA:");
	FDImprime(&classificados);
	
	printf("\n\n      CLASIFICACAO FINAL DA FILA ======= %d\n\n",i.val);
	
}
