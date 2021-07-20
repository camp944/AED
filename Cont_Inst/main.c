#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "processos.h"
#define MAX 10
#define MAX_TAM 100

int main(int argc, char *argv[]) {
	
	int select_inicio=1,select_operacao=1,tamanho,verificador;
	contador f;
	int matriz[MAX][MAX];
	while(select_inicio!=0)
	{ 
		menu_inicial();
		printf("               INSIRA A OPCAO DESEJADA -> ");
		scanf("%d",&select_inicio);
		
		if(select_inicio==1)
		{
			verificador=0;
			while(verificador!=1)
			{
				printf("               INSIRA O TAMANHO DA MATRIZ (DE 1 A 10) -> ");
				scanf("%d",&tamanho);
				if(tamanho>=1||tamanho<=20)
				{ 
					verificador=1;

	
				}	
			}
			inicio(matriz,tamanho,&f);
			select_operacao=1;
		
			while(select_operacao!=0)
			{
				menu();
				printf("               INSIRA A OPCAO DESEJADA -> ");
				scanf("%d",&select_operacao);
			
			
					if(select_operacao==0)
					{
						break;
					}
					
					if(select_operacao==1)
					{
						if(f.vet_pos[f.cont_steps]!=(f.tamanho-1)*10+(f.tamanho-1))
						{
							andar(matriz,&f);
						}
						else
						{
							printf("\n               VOCE CHEGOU AO FINAL DA MATRIZ\n\n");
						}
					}
					
					if(select_operacao==2)
					{
						imprimir_posicao(&f);
					}
					
					if(select_operacao==3)
					{
						imprimir_matriz(&f,matriz);
					}
					
					if(select_operacao==4)
					{
						reinicio(matriz,&f);
					}
						
						
					if(select_operacao==5)
					{
					
						while(f.vet_pos[f.cont_steps]!=(f.tamanho-1)*10+(f.tamanho-1))
						{
							andar(matriz,&f);
						}
						printf("\n               VOCE CHEGOU AO FINAL DA MATRIZ\n\n");
					}
					
					if(select_operacao==6)
					{
						imprimir_resultados(&f);
					}
			
			}
		}
		else{
			
		}
		
	}
		
	
	return 0;
}
