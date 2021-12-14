#include <stdlib.h>
#include <stdio.h>
#include "RN.h"



RN* Create_RN()
{
	
	return NULL;
}



void Insert_RN(RN **t,RecordRN r)
{
	if(*t==NULL)
	{
		*t=(RN*)malloc(sizeof(RN));
		(*t)->cor=1;
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->reg=r;
	}
	else
	{
		if(r.key<(*t)->reg.key)
		{
			Insert_RN(&(*t)->left,r);
			
		}
		if(r.key>(*t)->reg.key)
		{
			Insert_RN(&(*t)->right,r);
			
		}
		
		if(CorRN((*t)->right)==1 && CorRN((*t)->left)==0){GiroEsquerdaRN(t);}
		if(CorRN((*t)->left)==1 && CorRN((*t)->left->left)==1){GiroDireitaRN(t);}
		if(CorRN((*t)->left)==1 && CorRN((*t)->right)==1){TrocaCor(t);}
	}

}


void GiroDireitaRN(RN **t)
{
	RN *aux;
	aux=(*t)->left;
	(*t)->left=aux->right;
	aux->right=(*t);
	aux->cor=(*t)->cor;
	(*t)->cor=1;
	(*t)=aux;
}
void TrocaCor(RN **t)
{
	(*t)->cor = !(*t)->cor;
	if((*t)->left!=NULL){(*t)->left->cor=!(*t)->left->cor;}
	if((*t)->right!=NULL){(*t)->right->cor=!(*t)->right->cor;}
	
}
void GiroEsquerdaRN(RN **t)
{
	RN *aux;
	aux=(*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	aux->cor=(*t)->cor;
	(*t)->cor=1;
	(*t)=aux;	
}
void GiroDuploEsquerdaRN(RN **t)
{
	GiroDireitaRN(&(*t)->right);
	GiroEsquerdaRN(t);
}

int CorRN(RN *t)
{
	if(&(*t)==NULL){return 0;}else{return t->cor;}
}


int Buscador_RN(RN **t,RecordRN r,int verificador)
{
	if(*t==NULL)
	{
		verificador=-1;
		return verificador;
	}
	if((*t)->reg.key>r.key)
	{
		verificador=Buscador_RN(&(*t)->left,r,verificador);
		return verificador;
		
		
	}
	if((*t)->reg.key<r.key)
	{
		verificador=Buscador_RN(&(*t)->right,r,verificador);
		return verificador;
	}
	
	verificador=1;
	return verificador;
}


