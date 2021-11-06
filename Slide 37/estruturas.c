#include <stdlib.h>
#include <stdio.h>
#include "estruturas.h"

Tree* Create()
{
	return NULL;
}

void Insert(Tree **t,Record r)
{
	if(*t==NULL)
	{
		*t=(Tree*)malloc(sizeof(Tree));
		(*t)->left=NULL;
		(*t)->right=NULL;
		(*t)->reg=r;
	}
	else
	{
		if(r.key<(*t)->reg.key)
		{
			Insert(&(*t)->left,r);
		}
		if(r.key>(*t)->reg.key)
		{
			Insert(&(*t)->right,r);
		}
	}
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

void Remove(Tree **t,Record r)
{
	Tree *aux;
	
	if (*t == NULL){ 
		printf("[ERROR]: Not found!!!\n");
		return;
	}
	
	if (r.key < (*t)->reg.key)
	{
		Remove(&(*t)->left,r); 
		return; 
	}
	
	if (r.key > (*t)->reg.key)
	{ 
		Remove(&(*t)->right, r); 
		return; 
	}
	
	if ((*t)->right == NULL){ 
		aux = *t;  
		*t = (*t)->left;
		free(aux);
		return;
	}
	
	if ((*t)->left != NULL)
	{
		Antecessor(&(*t)->left, *t); 
		return; 
	}
	
	aux = *t;  
	*t = (*t)->right;
	free(aux);
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

void central(Tree *t)
{
	if(!(t == NULL))
	{
	    central(t->left); 
	    printf("%d ", t->reg.key);
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



