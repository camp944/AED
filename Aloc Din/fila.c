#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <conio.h>
#define MAX 100



void FDVazia(FilaD *f)
{
	f->first=(Bloco*) malloc (sizeof(Bloco));
	f->last=f->first;
	f->first->prox = NULL;
	
}
void FDEnfileira(FilaD *f,Item i)
{
	f->last->prox =(Bloco*)malloc(sizeof(Bloco));
	f->last=f->last->prox;
	f->last->dado=i;
	f->last->prox=NULL;
}
void FDDesemfileira(FilaD *f,Item i)
{
	Bloco *aux;
	
	if(f->first==f->last)
	{
		printf("\n\n      FILA VAZIA!!!\n\n");
	}
	
	aux=f->first;
	f->first=f->first->prox;
	i=aux->dado;
	free(aux);
}
void FDImprime(FilaD *f)
{
	Bloco *aux;
	aux=f->first->prox;
	printf("\n\n\n      ");
	while(aux!=f->last->prox)
	{
		printf(" %d",aux->dado.val);
		aux=aux->prox;
	}
	printf("\n\n\n");
}


void FEVazia(FilaE *f,int tam)
{
	f->pos_new=0;
	f->pos_old=0;
	f->tam=tam;
}

void FEEnfileira(FilaE *f,int a)
{
	if(f->full==(f->tam-1))	
	{
		FullQueue(f);
	}
	
	if(f->full==0)
	{
		f->elements[f->pos_new].val=a;
		f->full++;
	}
	else
	{
		
		
		if(f->pos_new<(f->tam-1))
		{	f->pos_new++;
			f->elements[f->pos_new].val=a;
			f->full++;
			
		}
		else
		{
			f->pos_new=0;
			f->elements[f->pos_new].val=a;
			f->full++;
			
		}
	
	}
}
int FEDesenfileira(FilaE *f)
{
	int a;
	a=f->elements[f->pos_old].val;
	if(f->pos_old<4)
	{
		f->pos_old++;
	}
	else
	{
		f->pos_old=0;
	}
	f->full--;
	
	return a;
	
}

void FullQueue(FilaE *f)
{ 
	Item b;
	b.val=FEDesenfileira(f);	
}




