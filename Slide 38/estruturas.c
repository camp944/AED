#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
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
		printf("ERRO: Not found!!\n");
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
	
	if(strcmp(r.word,(*t)->reg.word)==0)
	{
		*aux = *t;
		printf("Word Found!!\n");
	}
	else
	{
		printf("ERRO: Not found!!\n");
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


double Get_word_value(char word[MAX],char caracteres_m[27],char caracteres_M[27],int primos[26])
{
	int cont_letras=0,cont_alfabeto=0;
	double soma=0;
	for(cont_letras=0;cont_letras<3;cont_letras++)
	{
		for(cont_alfabeto=0;cont_alfabeto<13;cont_alfabeto++)
		{
			if((word[cont_letras]==caracteres_m[cont_alfabeto])||(word[cont_letras]==caracteres_M[cont_alfabeto]))
			{
				soma=soma+primos[cont_alfabeto]*pow(10,cont_letras);
				break;
			}
			if((word[cont_letras]==caracteres_m[26-cont_alfabeto])||(word[cont_letras]==caracteres_M[26-cont_alfabeto]))
			{
				soma=soma+primos[26-cont_alfabeto]*pow(10,cont_letras);
			}
		}	
	}
	
	return soma;
}


void central(Tree *t)
{
	if(!(t == NULL))
	{
	    central(t->left); 
	    printf("%s ", t->reg.word);
	    central(t->right); 
  	}
}
void pre_ordem(Tree *t)
{
	if(!(t == NULL))
	{
		printf("%s ", t->reg.word);
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
	    printf("%s ", t->reg.word);
  	}
}



