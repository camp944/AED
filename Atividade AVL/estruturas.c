#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"



Tree* Create()
{
	return NULL;
}



void Insert_Item(Tree **t,Record r)
{
	if(*t==NULL)
	{
		*t=(Tree*)malloc(sizeof(Tree));
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->reg=r;
		(*t)->peso=0;
	}
	else
	{
		if(r.key<(*t)->reg.key)
		{
			Insert_Item(&(*t)->left,r);
			if((GetPeso(&(*t)->left)-GetPeso(&(*t)->right))==2)
			{
				if(r.key<(*t)->left->reg.key){GiroDireita(t);}else{GiroDuploDireita(t);}
			}
		}
		if(r.key>(*t)->reg.key)
		{
			Insert_Item(&(*t)->right,r);
			if((GetPeso(&(*t)->right)-GetPeso(&(*t)->left))==2)
			{
				if(r.key>(*t)->right->reg.key){GiroEsquerda(t);}else{GiroDuploEsquerda(t);}
			}
		}
	}
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;

}

void Search(Tree **t,Tree **aux,Record r)
{
	
	if(*t==NULL)
	{
		printf("ERRO: Not found!");
		return;
	}
	if((*t)->reg.key>r.key)
	{
		Search(&(*t)->left,aux,r);
		return;
	}
	if((*t)->reg.key<r.key)
	{
		Search(&(*t)->right,aux,r);
		return;
	}
}

void IsInTree(Tree *t,Record r)
{
	if(t==NULL){ 
	   
	    return;
	}
	  
	return IsInTree(t->right, r);
}

void Remove(Tree **t,Tree **pai,Record r)
{
	Tree *aux;
	if(*t==NULL)
	{
		printf("ERROR:Not Found!!\n");
		return;
	}
	if(r.key<(*t)->reg.key){Remove(&(*t)->left,t,r);return;}
	if(r.key>(*t)->reg.key){Remove(&(*t)->right,t,r);return;}
	
	if((*t)->right==NULL)
	{
		aux=*t;
		*t=(*t)->left;
		free(aux);
		rebalance(pai);
		return;
	}
	
	if((*t)->left!=NULL)
	{
		Antecessor(&(*t)->left,*t);
		rebalance(pai);
		return;
	}
	
	aux=*t;
	*t=(*t)->right;
	free(aux);
	rebalance(pai);
}

void Antecessor(Tree **t,Tree *aux)
{
	if ((*t)->right != NULL){ 
		Antecessor(&(*t)->right, aux);
		return;
  	}
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->left;
  free(aux);
}


void rebalance(Tree **t)
{
	int balanco;
	int left_b=0,right_b=0;
	balanco=GetPeso(&(*t)->left)-GetPeso(&(*t)->right);
	
	if((*t)->left){left_b=GetPeso(&(*t)->left->left)-GetPeso(&(*t)->left->right);}
	if((*t)->right){right_b=GetPeso(&(*t)->right->left)-GetPeso(&(*t)->right->right);}

	if(balanco==2 && left_b>=0){GiroDireita(t);}
	if(balanco==2 && left_b<0){GiroDuploDireita(t);}
	if(balanco==2 && right_b<=0){GiroEsquerda(t);}
	if(balanco==2 && right_b>0){GiroDuploEsquerda(t);}

}
int GetPeso(Tree **t)
{
	if(*t == NULL){return -1;}
	return (*t)->peso;
}
int GetMaxPeso(int esq,int dir)
{
	
	if(esq > dir){return esq;}
	return dir;
}


void central(Tree *t)
{
	if(!(t == NULL)){
    central(t->left); 
    printf("%d\t", t->reg.key);
    central(t->right); 
  }
}
void pre_ordem(Tree *t)
{
	if(!(t == NULL))
	{
		printf("%d ", t->reg.key);
		pre_ordem(t->left); 
		pre_ordem(t->right); 
	}		
}
void pos_ordem(Tree *t)
{
	if(!(t == NULL))
	{
	    pos_ordem(t->left); 
	    pos_ordem(t->right); 
	    printf("%d ", t->reg.key);
  	}
}



void GiroDireita(Tree **t)
{
	Tree *aux;
	aux=(*t)->left;
	(*t)->left=aux->right;
	aux->right=(*t);
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;
	aux->peso=GetMaxPeso(GetPeso(&aux->left),(*t)->peso)+1;
	(*t)=aux;
}
void GiroDuploDireita(Tree **t)
{
	GiroEsquerda(&(*t)->left);
	GiroDireita(t);
	
}
void GiroEsquerda(Tree **t)
{
	Tree *aux;
	aux=(*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->peso=GetMaxPeso(GetPeso(&(*t)->left),GetPeso(&(*t)->right))+1;
	aux->peso=GetMaxPeso(GetPeso(&aux->left),(*t)->peso)+1;
	(*t)=aux;	
}
void GiroDuploEsquerda(Tree **t)
{
	GiroDireita(&(*t)->right);
	GiroEsquerda(t);
}





