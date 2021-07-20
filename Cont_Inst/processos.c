#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "processos.h"
#define MAX 10
#define MAX_TAM 100

void menu_inicial()
{
	printf("\n\n\n\n\n");
	printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("               @                                                       @\n");
	printf("               @                      MENU INICIAL                     @\n");
	printf("               @                                                       @\n");
	printf("               @             INICIAR UMA NOVA MATRIZ -> 1              @\n");
	printf("               @               ENCERRAR O PROGRAMA -> 0                @\n");
	printf("               @                                                       @\n");
	printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
}

void menu()
{
	printf("\n\n\n");
	printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("               @                                                       @\n");
	printf("               @                      MENU PRINCIPAL                   @\n");
	printf("               @                                                       @\n");
	printf("               @               SALTAR CASA NA MATRIZ -> 1              @\n");
	printf("               @                  IMPRIMIR POSICAO -> 2                @\n");
	printf("               @                  IMPRIMIR MATRIZ -> 3                 @\n");
	printf("               @                REINICIAR CAMINHADA -> 4               @\n");
	printf("               @                CAMINHAR ATE O FINAL -> 5              @\n");
	printf("               @             IMPRIRMIR SOMA DOS PASSOS -> 6            @\n");
	printf("               @               ENCERRAR O CAMINHADA -> 0               @\n");
	printf("               @                                                       @\n");
	printf("               @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n");
}



void inicio(int matriz[MAX][MAX],int tamanho,contador *c)
{
	printf("\n\n");
	int cont_e,cont_i;
	srand(time(NULL));
	for(cont_e=0;cont_e<tamanho;cont_e++)
	{
	
		printf("               ");
		for(cont_i=0;cont_i<tamanho;cont_i++)
		{
			matriz[cont_e][cont_i]=rand()%100;
			printf("  %d",matriz[cont_e][cont_i]);
		}
		printf("\n");
		
	}
	
	c->soma=matriz[0][0];
	c->cont_steps=0;
	c->tamanho=tamanho;
	c->vet_pos[0]=0;
	printf("\n\n %d   %d   %d",c->cont_steps,c->soma,c->vet_pos[0]);
	printf("\n\n");
	

}

void reinicio(int matriz[MAX][MAX],contador *c)
{
	c->cont_steps=0;
	c->vet_pos[c->cont_steps]=00;
}

void andar(int matriz[MAX][MAX],contador *c)
{
	int valor_atual,valor_e,valor_d,valor_b;
	valor_atual=matriz[c->vet_pos[c->cont_steps]/10][c->vet_pos[c->cont_steps]%10];
	valor_e=matriz[(c->vet_pos[c->cont_steps]/10)][(c->vet_pos[c->cont_steps]%10)-1];
	valor_d=matriz[(c->vet_pos[c->cont_steps]/10)][(c->vet_pos[c->cont_steps]%10)+1];
	valor_b=matriz[(c->vet_pos[c->cont_steps]/10)+1][(c->vet_pos[c->cont_steps]%10)];
	
	if(((c->vet_pos[c->cont_steps]/10)<c->tamanho-1)||((c->vet_pos[c->cont_steps]%10)<c->tamanho-1))//se o contador não estiver na ultima linha/ultima coluna
	{
		if(c->vet_pos[c->cont_steps]%10==0) //coluna 0
		{
			if(c->vet_pos[c->cont_steps]/10==0) //linha 0
			{
				if(valor_d>valor_b) //valor_d maior
				{
					c->cont_steps++;
					c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
					c->soma=c->soma+valor_d;
				}
				else//valor_b maior 
				{
					c->cont_steps++;
					c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
					c->soma=c->soma+valor_b;
				}
			}
			else//linha != 0
			{
				if(c->vet_pos[c->cont_steps]/10<(c->tamanho-1))//linha < tamanho-1
				{
					if(c->vet_pos[c->cont_steps-1]!=c->vet_pos[c->cont_steps]+1)//se o anterior não for o valor_d
					{
						if(valor_d>valor_b) //valor_d maior
						{
							c->cont_steps++;
							c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
							c->soma=c->soma+valor_d;
						}
						else//valor_b maior 
						{
							c->cont_steps++;
							c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
							c->soma=c->soma+valor_b;
						}	
					}
					else //se o anterior for o valor_d
					{
						c->cont_steps++;
						c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
						c->soma=c->soma+valor_b;
					}
				}
				else//linha=tamnaho-1
				{
					c->cont_steps++;
					c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
					c->soma=c->soma+valor_d;
				}
			}
		}
		else//coluna != 0
		{
			if((c->vet_pos[c->cont_steps]%10)==(c->tamanho-1))//coluna=tamanho-1
			{
				if(c->vet_pos[c->cont_steps-1]==c->vet_pos[c->cont_steps]-1)//se o valor_e for o anterior
				{
					c->cont_steps++;
					c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
					c->soma=c->soma+valor_b;
				}
				else//se o valor_e não for anterior
				{
					if(valor_e>valor_b)//se o valor_e for maior que valor_b
					{
						c->cont_steps++;
						c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]-1;
						c->soma=c->soma+valor_e;
					}
					else//se o valor_b for maior que valor_e
					{
						c->cont_steps++;
						c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
						c->soma=c->soma+valor_b;
					}
					
				}
			}
			else//0 < coluna < tamanho-1
			{
				if((c->vet_pos[c->cont_steps]/10)==(c->tamanho-1))//linha=tamanho-1
				{
					c->cont_steps++;
					c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
					c->soma=c->soma+valor_d;
				}
				else//linha<tamanho-1
				{
					if(c->vet_pos[c->cont_steps-1]==c->vet_pos[c->cont_steps]-1)//se o valor_e for o anterior
					{
						if(valor_d>valor_b)//se o valor_d for maior que o valor_b
						{
							c->cont_steps++;
							c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
							c->soma=c->soma+valor_d;
						}
						else//se o valor_b for maior ou igual ao valor_d
						{
							c->cont_steps++;
							c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
							c->soma=c->soma+valor_b;
						}
					}
					else
					{
						if(c->vet_pos[c->cont_steps-1]==c->vet_pos[c->cont_steps]+1)//se o valor_d for o anterior
						{
							if(valor_e>valor_b)//se o valor_e for maior que o valor_b
							{
								c->cont_steps++;
								c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]-1;
								c->soma=c->soma+valor_e;
							}
							else//se o valor_b for maior ou igual ao valor_e
							{
								c->cont_steps++;
								c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
								c->soma=c->soma+valor_b;
							}
						}
						else//se o anterior for o de cima
						{
							if((valor_e>valor_b)&&(valor_e>valor_d))//se o valor_e for maior que valor_d e valor_b
							{
								c->cont_steps++;
								c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]-1;
								c->soma=c->soma+valor_e;
							}
							else
							{
								if((valor_d>=valor_e)&&(valor_d>valor_b))//se o valor_d for maior ou igual a valor_e e maior que valor_b
								{
									c->cont_steps++;
									c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+1;
									c->soma=c->soma+valor_d;
								}
								else//se o valor_b for maior ou igual a valor_e e a valor_b
								{
									c->cont_steps++;
									c->vet_pos[c->cont_steps]=c->vet_pos[c->cont_steps-1]+10;
									c->soma=c->soma+valor_b;
									
								}
							}
						}
					}
				}
			}
		}

	}
	else//se o contador estiver na ultima linha/ultima coluna
	{
		printf("\n\n               VOCE CHEGOU AO FINAL \n\n");
	}
	
}

void imprimir_posicao(contador *c)
{
	if(c->vet_pos[c->cont_steps]==(c->tamanho-1)*10+c->tamanho)
	{
		printf("\n\n               VOCE CHEGOU AO FINAL \n\n");
	}
	else
	{
		printf("\n\n               VOCE CHEGOU NA POSICAO -> %d,%d\n\n",(c->vet_pos[c->cont_steps])/10,(c->vet_pos[c->cont_steps])%10);
	
	}
}

void imprimir_matriz(contador *c,int matriz[MAX][MAX])
{
	int cont_l,cont_c,cont_caminho;
	for(cont_l=0;cont_l<c->tamanho;cont_l++)
	{
		printf("               ");
		for(cont_c=0;cont_c<c->tamanho;cont_c++)
		{
			if((cont_l*10+cont_c)==c->vet_pos[cont_caminho])
			{
				printf("  X");
				cont_caminho++;
			}
			else
			{
				printf("  %d",matriz[cont_l][cont_c]);
			}
		}
		printf("\n");
	}
	printf("\n               X-> Caminho realizado  \n");
}
 
void imprimir_resultados(contador *c)
{
	printf("\n\n\n               PASSOS DADOS -> %d",c->cont_steps+1);
	printf("\n               SOMA DA DOS PASSOS -> %d",c->soma);
}
