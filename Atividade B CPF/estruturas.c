#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX 100

Pagina* CreateTree()
{
	return NULL;
}



void InsereNaPagina(Pagina *p, Pagina *pdir, record r)
{
	
	int k;
	k = p->n;
	
	short verificador;  
	verificador=(k>0);
	
	while(verificador)
	{ 
		if (r.key >= p->r[k-1].key)
		{ 
			verificador = FALSE;
			break;
		}
	
		p->r[k]=p->r[k-1];
		p->p[k+1]=p->p[k];
		k--;
		
		if(k<1){verificador = FALSE;}
		
	}
	
	p->r[k] = r; 
	p->p[k+1] = pdir;
	p->n++;
	  
}
void InsereFix(Pagina **p, Pagina **pr, record r, record *rr, int *Overflow)
{
	long i=1,j;
	Pagina *paux;
	if(*p==NULL)
	{ 
		*Overflow=TRUE; 
		*rr=r; 
		*pr=NULL;
		return;
	}
	
	while(i<(*p)->n && r.key>(*p)->r[i-1].key){i++;}

	
	if (r.key==(*p)->r[i-1].key)
	{ 
		printf("\n\t[ERROR]: O VALOR JA EXISTE\n"); 
		*Overflow = FALSE;
		return;
	}
	
	if(r.key<(*p)->r[i-1].key){i--;} 
	
	
	InsereFix(&(*p)->p[i],pr,r,rr,Overflow);
	
	
	if(!*Overflow){return;}
	
	if((*p)->n < MM)
	{
		InsereNaPagina(*p,*pr,*rr);
		*Overflow = FALSE;
		return;
	}
	
	paux=(Pagina*)malloc(sizeof(Pagina));
	paux->n=0;  
	paux->p[0]=NULL;
	
	if(i<M+1)
	{ 
		InsereNaPagina(paux,(*p)->p[MM],(*p)->r[MM-1]);
		(*p)->n--;
		InsereNaPagina(*p,*pr,*rr);
	
	}
	else
	{
		InsereNaPagina(paux,*pr,*rr);
	}
	
	
	for (j=M+2;j<=MM;j++){InsereNaPagina(paux,(*p)->p[j],(*p)->r[j-1]);}
	
	
	(*p)->n=M;  
	paux->p[0]=(*p)->p[M+1];
	*rr=(*p)->r[M];  
	*pr=paux;

}	

void Insere(Pagina **p, record r)
{
	int Overflow;
	record rr;
	Pagina *pr,*paux;
	
	InsereFix(p, &pr, r, &rr, &Overflow);
	
	if (Overflow)
	{
		paux=(Pagina *)malloc(sizeof(Pagina));
		paux->n=1;  
		paux->r[0]=rr;
		paux->p[0]=*p;  
		paux->p[1] =pr;
		*p=paux;
	}
}

void RemoveFix(Pagina *p, Pagina *pai,long long int PosPai, int *underflow)
{
	Pagina *aux; 
	long disp, j;
	
	if (PosPai < pai->n){ 
		aux = pai->p[PosPai + 1];  
		disp = (aux->n - M + 1) / 2;
		p->r[p->n] = pai->r[PosPai];
		p->p[p->n + 1] = aux->p[0];  
		p->n++;
		
		if (disp > 0){ 
		
			for (j = 1; j < disp; j++){InsereNaPagina(p, aux->p[j], aux->r[j-1]);}
			
			pai->r[PosPai] = aux->r[disp-1];  
			aux->n -= disp;
			
			for (j = 0; j < aux->n; j++){aux->r[j] = aux->r[j + disp];}			
			for (j = 0; j <= aux->n; j++){aux->p[j] = aux->p[j + disp];} 
			
			*underflow = FALSE;
		
		}else{ 
		
			for (j = 1; j <= M; j++){InsereNaPagina(p, aux->p[j], aux->r[j-1]);}
			free(aux);
			
			for (j = PosPai + 1; j < pai->n; j++)
			{ 
				pai->r[j-1] = pai->r[j];
				pai->p[j] = pai->p[j+1];
			}
			pai->n--;
			if (pai->n >= M){*underflow = FALSE;}
		}
	
	}else{ 
		aux = pai->p[PosPai-1]; 
		disp = (aux->n - M + 1) / 2;
		
		for (j = p->n; j >= 1; j--){p->r[j] = p->r[j-1];}
		
		
		p->r[0] = pai->r[PosPai-1];
		
		for (j = p->n; j >= 0; j--){p->p[j+1] = p->p[j];}
		
		p->n++;
		
		if (disp > 0){ 
			for (j = 1; j < disp; j++){InsereNaPagina(p, aux->p[aux->n - j + 1], aux->r[aux->n - j]);}
			
			
			p->p[0] = aux->p[aux->n - disp + 1];
			pai->r[PosPai-1] = aux->r[aux->n - disp];
			aux->n -= disp;  
			*underflow = FALSE;
		
		}else{
		
			for (j = 1; j <= M; j++){InsereNaPagina(aux, p->p[j], p->r[j-1]);}			
			free(p);  
			pai->n--;
			if (pai->n >= M){*underflow = FALSE;}  
			
		}
	}
}
void Antecessor(Pagina *p,long long int i, Pagina *pai, int *underflow)
{
	if (pai->p[pai->n] != NULL)
	{ 
		Antecessor(p, i, pai->p[pai->n], underflow);
		if (*underflow){RemoveFix(pai->p[pai->n], pai, pai->n, underflow);}
		return;
	}
	p->r[i-1]=pai->r[pai->n-1]; 
	pai->n--;  
	*underflow=(pai->n<M);
}
void Remove(Pagina **p,long long int key, int *underflow)
{
	long long int i,j=1;
	Pagina *aux;
	if(*p==NULL)
	{ 
		printf("\n\t[ERROR]: CPF NAO ENCONTRADO!\n"); 
		*underflow=FALSE;
		return;
	}
	
	aux = *p;
	while(j<aux->n && key>aux->r[j-1].key){j++;};
	
	if(key==aux->r[j-1].key){ 
		if(aux->p[j-1]==NULL){ 
		
			aux->n--;
			*underflow=(aux->n<M);
			for(i=j;i<=aux->n;i++)
			{ 
				aux->r[i-1]=aux->r[i];  
				aux->p[i]=aux->p[i+1]; 
			}
			return;
		}
	
		Antecessor(*p,j,aux->p[j-1],underflow);
		if (*underflow){RemoveFix(aux->p[j-1],*p,j-1,underflow);}    
		return;
	}
	
	if(key>aux->r[j-1].key){j++;}
	
	Remove(&aux->p[j-1],key,underflow);
	
	if (*underflow){RemoveFix(aux->p[j-1],*p,j-1,underflow);}

}

void Retira(Pagina **p,long long int key)
{ 
	int underflow;
	Pagina *aux;
	
	Remove(p,key,&underflow);
	
	if(underflow && (*p)->n==0)
	{ 
		aux = *p;   
		*p = aux->p[0]; 
		free(aux);
	}

} 
void Imprime(Pagina **p, int lvl)
{
	long contador;
	if (*p == NULL){return;} 
	
	printf("\t[LINHA %d]: ", lvl);
	
	
	for (contador=0;contador<(*p)->n;contador++){printf("%lld ",(*p)->r[contador].key);}
	
	
	putchar('\n');
	lvl++;
	
	for(contador=0;contador<=(*p)->n;contador++){Imprime(&(*p)->p[contador],lvl);}

}


