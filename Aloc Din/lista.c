#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "base.h"

void LVazia(Lista *l)
{
	l->primeiro=(Bloco*) malloc (sizeof(Bloco));
	l->ultimo=l->primeiro;
	l->primeiro->prox=NULL;	
}
void LInserir(Lista *l, Item i)
{
	l->ultimo->prox=(Bloco*)malloc(sizeof(Bloco));
	l->ultimo=l->ultimo->prox;
	l->ultimo->dado=i;
	l->ultimo->prox=NULL;
	
}
void LRemove(Lista *l,Item i)
{
	Bloco *aux1,*aux2;
	
	if(l->primeiro==l->ultimo||l->primeiro==NULL)
	{
		
		printf("      LISTA VAZIA!!!\n\n\n");
		return;
	}
	
	aux1=l->primeiro;
	
	while(aux1->prox!=NULL)
	{
		if(aux1->prox->dado.val!=i.val)
		{
			aux1=aux1->prox;			
		}
		else
		{
			aux2=aux1;
			aux1=aux1->prox;
			aux2->prox=aux1->prox;
			free(aux1);
		}
		
	}
	
}

void LImprime(Lista *l)
{
	int cont=0;
	Bloco *aux;
	aux=l->primeiro->prox;
	
	printf("      ");
	while(aux!=NULL)
	{
		if(cont==20)
		{
			printf("\n      ");
			cont=0;
		}
		
		printf("%d  ",aux->dado.val);
		aux=aux->prox;
		
		
		cont++;
	}
}

void LCVazia(ListaC *l)
{
	l->primeiro=(Bloco1C*)malloc(sizeof(Bloco1C));
	l->ultimo=l->primeiro;
	l->primeiro->prox=NULL;	
	
}
void LCInserir(ListaC *l, Item1C i)
{
	l->ultimo->prox=(Bloco1C*)malloc(sizeof(Bloco1C));
	l->ultimo=l->ultimo->prox;
	l->ultimo->dado=i;
	l->ultimo->prox=NULL;
	
}
void LCRemove(ListaC *l,Item1C i)
{
	Bloco1C *aux1,*aux2;
	
	if(l->primeiro==l->ultimo||l->primeiro==NULL)
	{
		
		printf("      LISTA VAZIA!!!\n\n\n");
		return;
	}
	
	aux1=l->primeiro;
	
	while(aux1->prox!=NULL)
	{
		if(aux1->prox->dado.caract!=i.caract)
		{
			aux1=aux1->prox;			
		}
		else
		{
			aux2=aux1;
			aux1=aux1->prox;
			aux2->prox=aux1->prox;
			free(aux1);
		}
		
	}
	
}
void LCImprime(ListaC *l)
{
	int cont=0;
	Bloco1C *aux;
	aux=l->primeiro->prox;
	while(aux!=NULL)
	{
		if(cont==20)
		{
			printf("\n");
			cont=0;
		}
		
		printf(" %d",aux->dado.caract);
		aux=aux->prox;
		
		
		cont++;
	}
}
