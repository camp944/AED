#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 100
#include "base.h"

typedef struct FilaD FilaD;
typedef struct FilaE FilaE;


struct FilaD
{
	Bloco *first,*last;
	
	
};


struct FilaE
{
	Item elements[MAX];
	int pos_old,pos_new;
	int full,tam;
	
};

void FDVazia(FilaD *f);
void FDEnfileira(FilaD *f,Item i);
void FDDesenfileira(FilaD *f);
void FDImprime(FilaD *f);

void FEVazia(FilaE *f,int tam);
void FEEnfileira(FilaE *f,int i);
int FEDesenfileira(FilaE *f);
void FullQueue(FilaE *f);


#endif


