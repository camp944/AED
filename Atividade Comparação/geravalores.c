#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "geravalores.h"
#include "BIN.h"
#include "AVL.h"
#include "RN.h"
#define MAX 100000




void geraValores_Insert()
{

	
	srand((unsigned int)time(NULL));
    float a=10;
    int indice[4]={4,1000,10000,1000000},i=1;

    
    
    for(i=1;i<indice[0];i++)
    {
    	int contador1=0,n=0;
    	int j=0;
    	float a=6;
    	char nome_arquivo[MAX]="";
		sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Insert_%d.txt",indice[i]);
		FILE *f=fopen(nome_arquivo,"w");
		
	
		
    	while(contador1<(indice[i]/20))
    	{
    		int contador2=0;
    		char row[MAX]="";
    		
    		while(contador2<20)
    		{
    			char value[MAX]="";
    			float b=((float)rand()/(float)(4548)) * a;
    			sprintf(value,"%f;",b);
    			strcat(row,value);
    			contador2++;
    			n++;
			}
			
			strcat(row,"\n");
			fputs(row,f);			
			contador1++;
		}
		fclose(f);
	}
    
    

    
    
    
   

}
void geraValores_Search()
{
	srand((unsigned int)time(NULL));
    float a=10;
    int indice[4]={4,5000,10000,100000},i=1;

    
    
    for(i=1;i<indice[0];i++)
    {
    	int contador1=0,n=0;
    	char nome_arquivo[MAX]="";
		sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Search_%d.txt",indice[i]);
		FILE *f=fopen(nome_arquivo,"w");
		
	
		
    	while(contador1<(indice[i]/20))
    	{
    		int contador2=0;
    		char row[MAX]="";
    		
    		while(contador2<20)
    		{
    			char value[MAX]="";
    			float b=((float)rand()/(float)(4548)) * a;
    			sprintf(value,"%f;",b);
    			strcat(row,value);
    			contador2++;
    			n++;
			}
			
			strcat(row,"\n");
			fputs(row,f);			
			contador1++;
		}
		fclose(f);
	}
    	
}
double Insere_valores_AVL(AVL **t,int n)
{
	Dado p;
	clock_t Ticks[2];
    
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Insert_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	RecordAVL rAVL;

	
	Ticks[0]=clock();
	while((fgets(leitor,MAX,f)!=NULL))
	{
		token=strtok(leitor,";");

        while(token!=NULL)
        {        
            
			char copia[MAX];
        	strcpy(copia,token);
        	
			float value=atof(copia);
			rAVL.key=value;
			rAVL.v=1;

			Insert_AVL(t,rAVL);	
				
            token=strtok(NULL,";");
        }
	}
	
	Ticks[1]=clock();

	
	return (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	
}

double Insere_valores_Binaria(BIN **t,int n)
{
	clock_t Ticks[2];
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Insert_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	RecordBIN rBIN;
	
	Ticks[0]=clock();
	while((fgets(leitor,MAX,f)!=NULL))
	{
		token=strtok(leitor,";");

        while(token!=NULL)
        {        
            
			char copia[MAX];
        	strcpy(copia,token);
            
			float value=atof(copia);
			
			rBIN.key=value;
			rBIN.v=1;

			Insert_BIN(t,rBIN);	
				
            token=strtok(NULL,";");
        }
	}
	
	Ticks[1]=clock();
	
	fclose(f);
	
	
	
	return (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
}

double Insere_valores_RN(RN **t,int n)
{
	clock_t Ticks[2];
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Insert_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	
	RecordRN rRN;
	
	Ticks[0]=clock();
	while((fgets(leitor,MAX,f)!=NULL))
	{
		token=strtok(leitor,";");

        while(token!=NULL)
        {        
            
			char copia[MAX];
        	strcpy(copia,token);
            
			float value=atof(copia);
			rRN.key=value;
			rRN.v=1;

			Insert_RN(t,rRN);
			(*t)->cor=0;	
				
            token=strtok(NULL,";");
        }
	}
	
	Ticks[1]=clock();
	
	fclose(f);


	
	return (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
	
}


Dado pesquisa_BIN(BIN **t,int n)
{
	
	Dado p;
    p.Encontrados=0;
    
	
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Search_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	
	RecordBIN rBIN;
	
	clock_t Ticks[2];
	p.Encontrados=0;
	
	
	
	Ticks[0]=clock();
	while((fgets(leitor,MAX,f)!=NULL))
	{
		token=strtok(leitor,";");
		
        while(token!=NULL)
        {   
    		
            int verificador=0;
			char copia[MAX];
        	strcpy(copia,token);
            
			float value=atof(copia);
			
			rBIN.key=value;
			rBIN.v=1;

			verificador=Buscador_BIN(t,rBIN,verificador);
			
			
			if(verificador>0){p.Encontrados++;}
				
            token=strtok(NULL,";");
        }
        
	}
	
	Ticks[1]=clock();
    
    p.tempo_total=(Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    p.tempo_medio=p.tempo_total/n;
	
	
	
	fclose(f);
	
	return p;
	
}
Dado pesquisa_AVL(AVL **t,int n)
{
	
    Dado p;
    p.Encontrados=0;
    
	
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Search_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	
	RecordAVL rAVL;
	
	clock_t Ticks[2];
	Ticks[0]=clock();
	
	while((fgets(leitor,MAX,f)!=NULL))
	{
		
		token=strtok(leitor,";");
		
        while(token!=NULL)
        {   
    		
            int verificador=1;
			char copia[MAX];
        	strcpy(copia,token);
            
			float value=atof(copia);
			
			rAVL.key=value;
			rAVL.v=1;

			verificador=Buscador_AVL(t,rAVL,verificador);
			
			if(verificador>0){p.Encontrados++;}
				
            token=strtok(NULL,";");
        }
        
	}
	
	Ticks[1]=clock();
    
    p.tempo_total=(Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    p.tempo_medio=p.tempo_total/n;
	
		
	fclose(f);
	return p;
	
}
Dado pesquisa_RN(RN **t,int n)
{
	
	
	Dado p;
    p.Encontrados=0;
    
	
	int contador1=0;
	char nome_arquivo[MAX]="",leitor[MAX];
	
	sprintf(nome_arquivo,"Conjuntos Gerados\\arquivo_Search_%d.txt",n);
	FILE *f=fopen(nome_arquivo,"r");
	char *token;
	
	RecordRN rRN;
	
	clock_t Ticks[2];
	Ticks[0]=clock();
		
		
		
		
	while((fgets(leitor,MAX,f)!=NULL))
	{
		
		token=strtok(leitor,";");
		
        while(token!=NULL)
        {   
    		
            int verificador=1;
			char copia[MAX];
        	strcpy(copia,token);
            
			float value=atof(copia);
			
			rRN.key=value;
			rRN.v=1;

			verificador=Buscador_RN(t,rRN,verificador);
			
			if(verificador>0){p.Encontrados++;}
				
            token=strtok(NULL,";");
        }
        
	}
	
	Ticks[1]=clock();
    
    p.tempo_total=(Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    p.tempo_medio=p.tempo_total/n;
	
	
	
	fclose(f);
	
	return p;
}










