#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"



AVL* Create_AVL()
{
	return NULL;
}



void Insert_AVL(AVL **t,RecordAVL r)
{
	if(*t==NULL)
	{
		*t=(AVL*)malloc(sizeof(AVL));
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->reg=r;
		(*t)->peso=0;
	}
	else
	{
		if(r.key<(*t)->reg.key)
		{
			Insert_AVL(&(*t)->left,r);
			if((GetPeso(&(*t)->left)-GetPeso(&(*t)->right))==2)
			{
				if(r.key<(*t)->left->reg.key){GiroDireita(t);}else{GiroDuploDireita(t);}
			}
		}
		if(r.key>(*t)->reg.key)
		{
			Insert_AVL(&(*t)->right,r);
			if((GetPeso(&(*t)->right)-GetPeso(&(*t)->left))==2)
			{
				if(r.key>(*t)->right->reg.key){GiroEsquerda(t);}else{GiroDuploEsquerda(t);}
			}
		}
	}
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;

}


int GetPeso(AVL **t)
{
	if(*t == NULL){return -1;}
	return (*t)->peso;
}
int GetMaxPeso(int esq,int dir)
{
	
	if(esq > dir){return esq;}
	return dir;
}





void GiroDireita(AVL **t)
{
	AVL *aux;
	aux=(*t)->left;
	(*t)->left=aux->right;
	aux->right=(*t);
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;
	aux->peso=GetMaxPeso(GetPeso(&aux->left),(*t)->peso)+1;
	(*t)=aux;
}
void GiroDuploDireita(AVL **t)
{
	GiroEsquerda(&(*t)->left);
	GiroDireita(t);
	
}
void GiroEsquerda(AVL **t)
{
	AVL *aux;
	aux=(*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;
	aux->peso=GetMaxPeso(GetPeso(&aux->left),(*t)->peso)+1;
	(*t)=aux;	
}
void GiroDuploEsquerda(AVL **t)
{
	GiroDireita(&(*t)->right);
	GiroEsquerda(t);
}


int Buscador_AVL(AVL **t,RecordAVL r,int verificador)
{
	if(*t==NULL)
	{
		verificador=-1;
		return verificador;
	}
	if((*t)->reg.key>r.key)
	{
		verificador=Buscador_AVL(&(*t)->left,r,verificador);
		return verificador;
		
		
	}
	if((*t)->reg.key<r.key)
	{
		verificador=Buscador_AVL(&(*t)->right,r,verificador);
		return verificador;
	}
	
	verificador=1;
	return verificador;
}


void pos_ordem(AVL *t)
{
	if(!(t == NULL))
	{
	    pos_ordem(t->left); 
	    pos_ordem(t->right); 
	    
  	}
}


