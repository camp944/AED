#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <time.h>
#include "geravalores.h"
#include "BIN.h"
#include "AVL.h"


int main() {
	

	Pesquisador p[3];
	double mediasAVL[3][3],mediasBIN[3][3],mediasRN[3][3],media_Insert[3][3],media_Found[3][3];
	int Insert[3]={1000,10000,1000000};
	int j,k,i;
	
	char row[MAX],nome_arquivo[MAX];;
	for(j=0;j<3;j++)
	{
		p[j].n[0]=5000;
		p[j].n[1]=10000;
		p[j].n[2]=100000;
		for(k=0;k<3;k++)
		{
			mediasBIN[j][k]=0;
			mediasAVL[j][k]=0;
			mediasRN[j][k]=0;
			media_Found[j][k]=0;
			media_Insert[j][k]=0;
		}
	}
	
	
	
//Realizando 10 testes, com cada conjunto de dados, para calcular uma media dos tempos obtidos e a quantidade de valores encontrados durante as pesquisas.	
	for(k=0;k<10;k++)
	{
		geraValores_Insert();
		geraValores_Search();
		printf(row,"\n\n\n\n\n\t\t[TESTE %d]",k+1);
		
		
		for(j=0;j<3;j++)
		{	
			
			printf("\n\n\n\n\n\t[PESQUISA]NUMEROS INSERIDOS -> %d\n",Insert[j]);
			BIN *b=Create_BIN();
			AVL *a=Create_AVL();
			RN *r=Create_RN();
			
			
			
			media_Insert[0][j]+=Insere_valores_Binaria(&b,Insert[j]);
			media_Insert[1][j]+=Insere_valores_AVL(&a,Insert[j]);
			media_Insert[2][j]+=Insere_valores_RN(&r,Insert[j]);
			
			
			for (i=0;i<3;i++)
			{
				
				p[j].d[i][0]=pesquisa_BIN(&b,p[j].n[i]);	
				p[j].d[i][1]=pesquisa_AVL(&a,p[j].n[i]);	
				p[j].d[i][2]=pesquisa_RN(&r,p[j].n[i]);
				
				mediasBIN[j][i]+=p[j].d[i][0].tempo_total;
				mediasAVL[j][i]+=p[j].d[i][1].tempo_total;
				mediasRN[j][i]+=p[j].d[i][2].tempo_total;
				
				media_Found[j][i]+=p[j].d[i][0].Encontrados;
				
				printf("\n\n\t[RESULTADO TEMPO] PESQUISA DE %d VALORES ->\tBINARIA= %g ms\tAVL= %g ms\tRUBRO-NEGRA= %g ms\tFound=%d",p[j].n[i],p[j].d[i][0].tempo_total,p[j].d[i][1].tempo_total,p[j].d[i][2].tempo_total,p[j].d[i][0].Encontrados);
				
			}	
			
		}
		
		
		
	}
	
//Gerando o Arquivo com os resultados obtidos
	sprintf(nome_arquivo,"Resultados\\Resultado.txt");
	FILE *f=fopen(nome_arquivo,"w");
	for(j=0;j<3;j++)
	{
		
		sprintf(row,"\n\n\n\t[PESQUISA]NUMEROS INSERIDOS -> %d\n",Insert[j]);
		fputs(row,f);
		strcpy(row,"");
		
		media_Insert[0][j]/=10;
		media_Insert[1][j]/=10;
		media_Insert[2][j]/=10;
		
		sprintf(row,"\n\n\t[RESULTADO TEMPO] INSERCAO DE %d VALORES ->\tBINARIA= %g ms\tAVL= %g ms\tRUBRO-NEGRA= %g ms",Insert[j],media_Insert[0][j],media_Insert[1][j],media_Insert[2][j]);
		fputs(row,f);
		strcpy(row,"");
		for(i=0;i<3;i++)
		{
			mediasBIN[j][i]=mediasBIN[j][i]/10;
			mediasAVL[j][i]=mediasAVL[j][i]/10;
			mediasRN[j][i]=mediasRN[j][i]/10;
			media_Found[j][i]/=10;
			
			
			sprintf(row,"\n\n\t[RESULTADO TEMPO] PESQUISA DE %d VALORES ->\tBINARIA= %g ms\tAVL= %g ms\tRUBRO-NEGRA= %g ms\tFOUND=%g",p[j].n[i],mediasBIN[j][i],mediasAVL[j][i],mediasRN[j][i],media_Found[j][i]);
			fputs(row,f);
			strcpy(row,"");
		}
		
	}
	
	fclose(f);
	
	
	return 0;
}
