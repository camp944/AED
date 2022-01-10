#include "operacoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "estruturas.h"

void geraCPF()
{

	srand(time(NULL) );
    
	int contador1=0;

	char nome_arquivo[MAX]="";
	sprintf(nome_arquivo,"Dados Pessoas\\CPF.txt");
	FILE *f=fopen(nome_arquivo,"w");
	
	while(contador1<1000)
	{
		char value[MAX]="";
		
		
		long long int a=(rand()%100000000*rand()%100000000*167568697788)%100000000000;
		if(a>10000000000)
		{
			sprintf(value,"%lld\n",a);
			fputs(value,f);			
			contador1++;
		}
	}
	fclose(f);

}

void Cria_vetor(char nomes[1000][MAX],long long int cpfs[1000])
{

	FILE *nome=fopen("Dados Pessoas\\Nomes.txt","r");
	FILE *cpf=fopen("Dados Pessoas\\CPF.txt","r");
	char leitor_nome[MAX],leitor_cpf[MAX],*token;
	int cont,i=0;
	
	
	for(i=0;i<1000;i++)
	{
		fgets(leitor_nome,MAX,nome);
		fgets(leitor_cpf,MAX,cpf);
		char *token_nome,*token_cpf;
		token_nome=strtok(leitor_nome,"\n");
		token_cpf=strtok(leitor_cpf,"\n");
		strcpy(leitor_cpf,token_cpf);
		
	
		cpfs[i]=atoll(leitor_cpf);
		strcpy(nomes[i],leitor_nome);	
				
	}
	
	
}

void Insere_Conjunto(char nomes[1000][MAX],long long int Cpfs[1000],Pagina *p[10])
{
	int i,j;
	record r;
	for(i=0;i<1000;i++)
	{
		r.key=Cpfs[i];
		strcpy(r.nome,nomes[i]);
		
		for(j=0;j<10;j++)
		{
			if(r.key%100<(j*10+10) && r.key%100>=j*10){Insere(&p[j],r);}
		}
	}
}

void Pesquisa(Pagina **p,long long int key)
{
	long i,j=1;
	Pagina *aux;
	
	if(*p==NULL)
	{ 
		printf("\n\t[RESULTADO]: CPF NAO ENCONTRADO!\n"); 
		return;
	}
	
	aux = *p;
	while(j<aux->n && key>aux->r[j-1].key){j++;};
	
	if(key==aux->r[j-1].key){ 
		printf("\n\n[RESULTADO]: CPF ENCONTRADO! [%s]\n",aux->r[j-1].nome);	
		return;
	}
	
	if(key>aux->r[j-1].key){j++;}
	
	Pesquisa(&aux->p[j-1],key);
	
	
}

void Buscador(long long int key,Pagina *p[10])
{
	int j;

	for(j=0;j<10;j++)
	{
		if(key%100<(j*10+10) && key%100>=j*10){Pesquisa(&p[j],key);return;}
	}

}

void Add(record r,Pagina *p[10])
{
	int j;
	
	for(j=0;j<10;j++)
		{
		if(r.key%100<(j*10+10) && r.key%100>=j*10){Insere(&p[j],r);}
		}
	
}
void Delet(record r,Pagina *p[10])
{
	int j;

	for(j=0;j<10;j++)
	{
		if(r.key%100<(j*10+10) && r.key%100>=j*10){Retira(&p[j],r.key);return;}
	}
	
}

