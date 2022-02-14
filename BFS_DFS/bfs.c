#include "bfs.h"


void BFS_adj(Graph G, Vertex s,int **matriz){
  int cor[G->V]; 
  int d[G->V];
  int pi[G->V]; 
  Fila *f = FFVazia();
  int i;
  for(i=0; i<G->V; i++)
    if(i != s->value){
      cor[i] = 0;
      d[i]   = -1; //infinito
      pi[i]  = -1; // ? não tem pai ainda
    }

  cor[s->value] = 1;
  d[s->value]   = 0;
  pi[s->value]  = -1;

  Queue(f, s->value);

  while (f->size > 0){
    Item *u = Dequeue(f);
    Vertex v,aux=NULL;
    for(v = G->adj[u->data]; v != NULL; v=v->prox){
      if(cor[v->value] == 0){
        cor[v->value] = 1;
        d[v->value]   = d[u->data] + 1;
        pi[v->value]  = u->data;
        Queue(f, v->value);
      }
      if(aux!=NULL)
      {
	  	matriz[aux->value][v->value]=1;
	  	matriz[v->value][aux->value]=1;
      }
      aux=v;
    }

    cor[u->data] = 2;
    
  }
}

void BFS_inc(Graph G, Vertex s,int **matriz){
  int cor[G->V]; //0 Branco, 1 Cinza, 2 Preto
  int d[G->V];
  int pi[G->V]; // -1 == NULL
  Fila *f = FFVazia();
  int i,cont_edge=0;
  for(i=0; i<G->V; i++)
    if(i != s->value){
      cor[i] = 0;
      d[i]   = -1; //infinito
      pi[i]  = -1; // ? não tem pai ainda
    }

  cor[s->value] = 1;
  d[s->value]   = 0;
  pi[s->value]  = -1;

  Queue(f, s->value);

  while (f->size > 0){
    Item *u = Dequeue(f);
    Vertex v,aux=NULL;
    for(v = G->adj[u->data]; v != NULL; v=v->prox){
      if(cor[v->value] == 0){
        cor[v->value] = 1;
        d[v->value]   = d[u->data] + 1;
        pi[v->value]  = u->data;
        Queue(f, v->value);
      }
      if(aux!=NULL)
      {
      	matriz[v->value][cont_edge]=1;
      	matriz[aux->value][cont_edge]=1;
      	cont_edge++;
	  }
      aux=v;
    }

    cor[u->data] = 2;
  
  }
}





	  
	  


