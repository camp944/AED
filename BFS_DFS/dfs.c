#include "dfs.h"


void DFS_VISIT_adj(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo,int **matriz){
  cor[v->value]  = 1;
  *tempo += 1;
  d[v->value] = *tempo;
  Vertex u,aux=NULL;
  for(u = G->adj[v->value]; u != NULL; u=u->prox)
  {
  	if(cor[u->value] == 0)
      DFS_VISIT_adj(G, u, cor, d, f, tempo,matriz);
    if(aux!=NULL)
    {
	  matriz[aux->value][u->value]=1;
	  matriz[u->value][aux->value]=1;
    }
    aux=u;
  }
  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;
}

void DFS_adj(Graph G,int **matriz){
  int cor[G->V]; 
  int d[G->V];   
  int f[G->V];   
  int tempo = 0;
  int v;
  for(v=0; v<G->V; v++)
    cor[v] = 0;
  
  for(v=0; v<G->V; v++)
  {
  	if(cor[v] == 0)
      DFS_VISIT_adj(G, G->adj[v], cor, d, f, &tempo,matriz);
  }	
    
}


int DFS_VISIT_inc(Graph G, Vertex v, int *cor, int *d, int *f, int *tempo,int **matriz,int cont_edge){
  cor[v->value]  = 1;
  *tempo += 1;
  d[v->value] = *tempo;
  Vertex u,aux=NULL;
  for(u = G->adj[v->value]; u != NULL; u=u->prox)
  {
  	if(cor[u->value] == 0)
      cont_edge=DFS_VISIT_inc(G, u, cor, d, f, tempo,matriz,cont_edge);
    if(aux!=NULL && aux!=v)
    {
	  matriz[aux->value][cont_edge]=1;
	  matriz[u->value][cont_edge]=1;
	  cont_edge++;
    }
    aux=u;
  }
  cor[v->value] = 2;
  *tempo += 1;
  f[v->value] = *tempo;
 
  
  return cont_edge;
}

void DFS_inc(Graph G,int **matriz){
  int cor[G->V]; 
  int d[G->V];   
  int f[G->V];   
  int tempo = 0;
  int v,cont_edge=0;
  for(v=0; v<G->V; v++)
    cor[v] = 0;
  
  for(v=0; v<G->V; v++)
  {
  	if(cor[v] == 0)
      cont_edge=DFS_VISIT_inc(G, G->adj[v], cor, d, f, &tempo,matriz,cont_edge);
  }	
    
}


