#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "pilha.h"
#include "base.h"
#include "ex2.h"
//PRONTOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo


void menuEx2()
{
	printf("\n\n\n");
	printf("      ##############################################\n");
	printf("      #                                            #\n");
	printf("      #        RESOLVER O EX 2 LETRA A -> 1        #\n");
	printf("      #        RESOLVER O EX 2 LETRA B -> 2        #\n");
	printf("      #        RESOLVER O EX 2 LETRA C -> 3        #\n");
	printf("      #          RESOLVER OUTROS EX -> 0           #\n");
	printf("      #                                            #\n");
	printf("      ##############################################\n\n\n");
}

int gcd(int a, int b)
{
	int i;
	int gcd;
	
	for(i=1;i<=a&&i<=b;++i)
    {
        
        if((b%i)==0&&(a%i==0))
        {
        	gcd = i;
		}
            
    }
    
    return gcd;
}

int totiente(int n)
{
	int resultado,i;
	resultado=1;
    for (i=2;i<n;i++)
	{
		if (gcd(i, n) == 1)
        {
			resultado++;
		}
	}
        
            
    return resultado;
}

void resolve2A()
{
	char expr[MAX];
	
	printf("INSIRA A EXPRESSAO MATEMATICA->");
	scanf("%s",&expr);
	
	
	Pilha2A ver;
	PDVazia2A(&ver);
	Item2A C;
	int cont,contp1,contp2;
	contp1=0;
	contp2=0;
	cont=0;
	while(expr[cont]!='\0')
	{
		C.caractere=expr[cont];
		PDEmpilha2A(&ver,C);
		if(expr[cont]=='(')
		{
			PDEmpilha2A(&ver,C);
			contp1++;
		}else
		{
			if(expr[cont]==')')
			{
				PDEmpilha2A(&ver,C);
				contp2++;
			}
		}
		cont++;
	}
	
	if(contp1==contp2)
	{
		printf("\n\n      A parentizacao esta correta!!!\n\n");
		
	}
	else
	{
		printf("\n\n      A parentizacao esta incorreta!!!\n\n");
	}
	
}
void resolve2B()
{
	srand(time(NULL));
	int cont;
	cont=0;
	Item i;
	Bloco *aux;
	PilhaD P1,P2;
	PDVazia(&P1);
	PDVazia(&P2);
	
	while(cont<10)
	{
		i.val=rand()%100;
		PDEmpilha(&P1,i);
		
		cont++;
	}
	printf("\n\n");
	
	PDImprime(&P1);
	
	aux=P1.last;
	
	while(aux!=P1.first)
	{
		PDEmpilha(&P2,aux->dado);
		aux=aux->prox;
	}
	
	PDImprime(&P2);
}
void resolve2C()
{
	srand(time(NULL));
	int cont;
	cont=0;
	Item i;
	Bloco *aux;
	PilhaD P,PTotiente;
	PDVazia(&P);
	PDVazia(&PTotiente);
	
	while(cont<20)
	{
		i.val=rand()%100;
		PDEmpilha(&P,i);
		cont++;
	}
	
	PDImprime(&P);
	
	aux=P.last;
	
	while(aux!=P.first)
	{
		Item i;
		i.val=totiente(aux->dado.val);
		PDEmpilha(&PTotiente,i);
		aux=aux->prox;
	
	}
	
	printf("Totiente da Pilha acima: \n");
	PDImprime(&PTotiente);
	
	
	
}
