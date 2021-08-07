#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "base.h"


void PDVazia(PilhaD *p)
{
	p->first=(Bloco*)malloc(sizeof(Bloco));
	p->last=p->first;
	p->first->prox=NULL;

}
void PDEmpilha(PilhaD *p,Item i)
{
	Bloco *aux=(Bloco*)malloc(sizeof(Bloco));
	aux->dado.val=i.val;
	aux->prox=p->last;
	p->last=aux;
	
}
void PDDesempilha(PilhaD *p,Item i)
{
	
	Bloco *aux;
	
	if(p->last==p->first)
	{
		printf("PILHA VAZIA!!!\n\n");
		return;
	}
	
	aux=p->last;
	p->last=aux->prox;
	i.val=aux->dado.val;
	free(aux);
}

void PDImprime(PilhaD *p)
{
	Bloco *aux;

	aux=p->last;
	while(aux!=p->first){
		printf("      %d\n", aux->dado.val);
		aux = aux->prox;
	}
	printf("\n\n");

}



void PDVazia2A(Pilha2A *p)
{
	p->first=(Bloco2A*)malloc(sizeof(Bloco2A));
	p->last=p->first;
	p->first->prox=NULL;
}
void PDEmpilha2A(Pilha2A *p,Item2A i)
{
	Bloco2A *aux=(Bloco2A*)malloc(sizeof(Bloco2A));
	aux->dado.caractere=i.caractere;
	aux->prox=p->last;
	p->last=aux;
	
	
	
}
void PDDesempilha2A(Pilha2A *p,Item2A i)
{
	
	Bloco2A *aux;
	
	if(p->last==p->first)
	{
		printf("PILHA VAZIA!!!\n\n");
		return;
	}
	
	aux=p->last;
	p->last=aux->prox;
	i=aux->dado;
	free(aux);
}

void PDImprime2A(Pilha2A *p)
{
	Bloco2A *aux;
	aux=p->first;
	
	printf("\n\n\n");
	
	while(aux!=p->last->prox)
	{
		printf(" %c",aux->dado.caractere);
		aux=aux->prox;
	}
	printf("\n\n\n");
}

