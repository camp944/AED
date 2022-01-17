## Problema do Caminho Mínimo

O problema do caminho mínimo ou caminho mais curto consiste em encontrar o melhor caminho entre dois vértices. Assim, resolver esse problema pode significar determinar o caminho entre dois nós (vértices no caso de grafos) com o custo mínimo de viagem.
Em uma representação de grafo, dependendo de suas características, pode existir vários caminhos entre um par de vértices, definidos como origem e destino. Entre os diversos caminhos possíveis, aquele que possui o menor “peso” é chamado de caminho mínimo. Este peso representa a soma total dos valores das arestas que compõem o caminho a estes valores, no qual podem ser: o tempo da viagem, a distância percorrida ou um outro custo qualquer que pode conter cada aresta.

## Algoritmo de Dijkstra
O algoritmo de Dijkstra é uma solução para o problema do caminho mínimo de origem única, visto que a busca em largura ignora qualquer tipo de peso de um nó. Funciona em grafos orientados e não orientados, no entanto, todas as arestas devem ter custos não negativos. Se houver custos negativos, usa-se o algoritmo de Bellman-Ford. 
O algoritmo de Dijkstra irá calcular o caminho mais curto, em termos do peso total das arestas, entre um vértice inicial e todos os demais vértices no grafo. O peso total das arestas é a soma dos pesos das arestas que compõem o caminho. Seu custo computacional na complexidade de pior caso é ![image](https://user-images.githubusercontent.com/78819692/149826865-575e8908-7f80-4172-bc1c-6d54d759bd6e.png)
  sendo V o número de vértices e E o número de arestas.



### Onde pode ser aplicado:

- Problemas de logística
- Rede de computadores 
- Tráfego humano
- Sistema Rodoviários e Aéreos 

### Funcionamento:
<p>Dado um exemplo, no qual queremos sair do ponto S para o ponto T com o melhor caminho a ser percorrido. Sendo assim, resolveremos os subproblemas, calculando o custo ótimo de um ponto ao outro para que depois possamos usar desses custos ótimos encontrados para solucionar o problema maior.<p>
  
 <br />
 
  
  
  ![Untitled Diagram drawio (1)](https://user-images.githubusercontent.com/78819692/149779782-fa7cd2d2-201d-40b6-af61-29be63d24297.png)


 <br />
  
  
  |  Vértice | Peso 1 | Peso 2 | Peso 3 | Peso 4 | Peso 5 | Peso 6 |
  |   :---:  | :---:  | :---:  |:---:   |  :---: | :---:  | :---:  |
  |S         |**(0,S)**   |-       |-       |-       |-       |-       |
  |B         |(4,S)   |(3,C)   |**(3,C)**   |-       |-       |-       |
  |C         |(2,S)   |**(2,S)**   |-       |-       |-       |-       |
  |D         |-       |(10,C)  |(8,B)   |**(8,B)**   |-       |-       |
  |E         |-       |(12,C)  |(12,C)  |(10,D)  |**(10,D)**  |-       |
  |T         |-       |-       |-       |(14,D)  |**(12,E)**  |-       |
  
   <br />
   <br />
  

  
1. Em um primeiro momento atribuímos o valor 0 para S e os demais atribuímos valores infinitos, com isso a etiqueta inicial será o valor de 0 vindo de S (0, S). O ponto S faz conexões (arestas) com o ponto B e C, o caminho para B possui o peso 4, somando com o 0 de S temos então a etiqueta (4, S) em B e usando da mesma lógica teremos para C a etiqueta (2, S).
  
2. Analisando esses dois custos, C terá o melhor caminho sendo assim partiremos a partir dele. O ponto C possui arestas com os pontos B, com o peso da aresta valendo 1, com D com o peso valendo 8 e com E com a aresta de peso 10. Sendo assim, somando com o valor de 2 da etiqueta do ponto C, o ponto B terá uma nova etiqueta de (3, C), o ponto D terá (10, C) e ponto E terá a etiqueta (12, C).
  
3. Analisando os três custos anteriores, temos na etiqueta B (3, C) o menor caminho, sendo assim partiremos a partir dele. O ponto B tem aresta com o ponto D, sendo essa aresta o valor de 5 no qual somando com o valor já presente na etiqueta B, teremos em D a nova etiqueta (8, B). 
  
4. Analisando a partir do ponto D, temos que de C até D passamos pelo ponto E, no qual já calculamos o valor de (12, C), sendo assim o valor vindo de B será o de menor peso. O ponto D faz conexão com o ponto E que contém o peso dessa aresta 2, sendo adicionada então em E a etiqueta de (10, D), sendo esse valor a soma da aresta entre os dois pontos e o valor antigo da etiqueta D. O ponto D também faz conexão com o ponto T, sendo a aresta peso 6 que somado com o valor de sua etiqueta (valor esse o peso das arestas anteriores até chegar nesse ponto) teremos em T (14, D).
  
5. Por fim, calculando o caminho do ponto E teremos o valor em T de (12, E) sendo que o valor anterior de E era (10, D). Portanto, ao chegar no ponto de destino e analisarmos os dois caminhos encontrados (14, D) e (12, E) temos que o caminho vindo de E tem o menor custo.

  ### Apresentação do código:
  
 #### Estruturação do Grafo

  
  - Iniciação do Vértice:
	
```sh
	Vertex VertexInitialize(int value,Graph G)//INICIALIZA O VERTICE
	{	
	int i;
	Vertex v=(Vertex)malloc(sizeof(Vertex));
	v->prox=(Vertex*)malloc(G->V * sizeof(Vertex));
	v->cost=(int*)malloc(G->V * sizeof(int));
	for(i=0;i<G->V;i++)
	{		
		v->prox[i] = NULL;
		v->cost[i]=0; // ATRIBUI 0 PARA TODOS OS PESOS DAS ARESTAS VIZINHAS
	}
	v->grau=0; //ATRIBUO 0 PARA AS CONEXÕES
	v->value = value; // ADICIONA O VALOR DO VÉRTICE
	
	return v;
}
```
. Função chamada na iniciação do grafo GraphInitialize(int V) atribuindo os valores padrões iniciais a todos os vértices V passado por parâmetro através de um for.
	
 <br />
		
 - Adicionando aresta
	
	
```sh
void GraphInsertEdge(Graph G, Vertex v1, Vertex v2)//ADICIONA UMA ARESTA 
{
	int i;
	for(i=0;i<G->V;i++)
	{
		//CASO EU TIVER ARESTA VIZINHAS NO INDICE DETERMINADO DO MEU VÉRTICE//
		if(v1->prox[i] != NULL ) 
		{	
			if((v1->prox[i]->value == v2->value)) //CONFIRO SE JA TENHO A ARESTA
			{
  				return;	// CASO TRUE, ENCERRO A EXECUÇÃO
			}			
		}
	}
	
	// CASO NAO TIVER ARESTA REPETIDA//
	
	v1->grau++; //ADICIONO +1 NA MINHA VARIÁVEL DE QTD DE VIZINHOS DO MEU VÉRTICE
	VertexJumpCost(v1,v2);//CRIO UM VALOR ALEATÓRIO (ENTRE 1 E 16) PARA ESSA ARESTA
	
	/*COMO O GRAFO TRABALHADO NÃO É DIRIGIDO, PARA CADA ARESTA V1->V2, O GRAFO TAMBÉM TERÁ V2->V1*/
	
	v1->prox[v2->value]=v2;
	v2->prox[v1->value]=v1;
	G->E++; // SOMO +1 NA QTD DE ARESTA DO MEU GRAFO
}
```
. No parâmetro da função, recebo o grafo e os vértices do qual eu quero partir e do qual eu vou me direcionar. Na função VertexJumpCost(v1,v2), eu crio um valor aleatóro entre 1 e 16 e adiciono no vetor cost no índice querepresenta os pesos das minhas arestas vizinhas. 

 <br />

#### Funções do programa
	
- Procura do vértice de menor distância:
	
```sh
int Search_CloseRoute(int *visited, int *dist,Graph G)
{
	int	min=INT_MAX,i,min_index;
 

    for(i=0;i<G->V;i++) // PARA CADA VÉRTICE DO MEU GRAFO 
    {
    	/* NO PRIMEIRO LOOP, DIST[0]=0 E NÃO FOI VISITADO, ENTRA NO LOOP.
	A PARTIR DO SEGUNDO COMPARA SE O PERCUSO NO INDICE DO VETOR DIST
	É MENOR QUE O MÍNIMO JA CADASTRADO E NAO VISITADO*/
		if (dist[i] < min && visited[i] == 0) 		
		{
		    min = dist[i]; // MODIFICA O MIN, QUE SERVE PARA A COMPARAÇÃO
		    min_index = i;// SALVA O INDICE DA POSIÇÃO DE MENOR DISTÂNCIA NAO VISITADO
		}
	}      
 
    return min_index; //RETORNA O INDICE DO VÉRTICE DE MENOR DISTÂNCIA E QUE NÃO FOI VISITADO AINDA
}	
```
				 
. O parâmetro int *dist será criado no main e servirá de vetor auxiliar para armazenar as rotas de menor custo. 

- Calculo entre as menores rotas :
		
```sh	
void CloseRoute(Graph G,int ini, int *dist)//CALCULA A MENOR ROTA ENTRE OS VERTICES E IMPRIME AS DISTANCIAS
{
	int i,cont;
	int *visited=(int*)malloc(G->V * sizeof(int));
	for(i=0;i<G->V;i++) //CRIA VETOR AUXILIAR, INICIALIZA DISTÂNCIAS 
	{
		dist[i]=INT_MAX; //ADICIONA O MAIOR VALOR POSSIVEL DE INT PARA TODAS AS DISTÂNCIA
		visited[i]=0; // MARCA COMO NAO VISITADO
	}
	dist[ini]=0; 
	
	for(cont=0;cont<G->V;cont++)  // PARA CADA VÉRTICE DO MEU GRAFO
	{
		int u=Search_CloseRoute(visited,dist,G); /*RETORNA PARA U O VÉRTICE DE MENOR DISTÂNCIA E QUE NÃO FOI VISITADO*/
        visited[u]=1;
        
        for(i=0;i<G->V;i++)//PARA CADA VÉRTICE DO MEU GRAFO...
        {	            		
       	 /* SE NO VÉRTICE DE MENOR DISTÂNCIA EU ENCONTRAR UM VALOR DO PESO DE UMA DAS SUAS ARESTAS MAIOR QUE 0, 
	  NA QUAL NÃO FOI VISITADA E O VALOR NO VETOR DE DISTÂNCIA(dist) DESSE INDICE FOR MAIOR QUE A SOMA DA POSIÇÃO 
	  DE MENOR CAMINHO ATE ENTAO CADASTRADA COM O PESO DA ARESTA ENCONTRADA, EU ATUALIZO O VETOR NESSE INDICE
	
        	if (G->adj[u]->cost[i] > 0 && visited[i] == 0 && dist[i] > dist[u] + G->adj[u]->cost[i]) 
            {
            	dist[i] = dist[u] + G->adj[u]->cost[i];//ATUALIZO A MINHA DISTANCIA
			}
		}          
	}						
	Imprimir(dist,G,ini);
}
```
	
### Entradas e Saídas:
	
![image](https://user-images.githubusercontent.com/78819692/149825229-03893cbf-1539-4900-9a6a-dda474edbc58.png)

- O programa contém duas entradas, na qual a primeira o usuário inseri quantos vértices ele quer que o grafo tenha. A segunda entrada determinará qual é o vértice de partida que ele deseja.
	
![image](https://user-images.githubusercontent.com/78819692/149825398-9cb2a429-3cce-4f82-a3de-fdb310b13ba2.png)
	
- A partir do vértice de partida, o programa terá como saída os valores dos caminhos menores do vértice de partida para todos os outros, informando as arestas repetidas não inseridas e as inseridas. 
	
- É válido resaltar que as combinações de vértices que serão ligados por  uma aresta a ser inserida será a partir de um numero aleatório que varia entre 1 a (V x 8) sendo V o número de vértices escolhido pelo usuário.

```sh
	for(i=0;i<V*8;i++)
	{	
		int a=rand()%V;
		int b=rand()%V;
		if(a!=b)
		{
			GraphInsertEdge(G, G->adj[a], G->adj[b]);//INSERCAO DA ARESTA
			laco++;
		}	
	}
```
