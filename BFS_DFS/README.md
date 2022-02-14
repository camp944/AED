# ESTRUTURA
<p>O presente programa tem que como objetivo apresentar os resultados da aplicação
da busca em largura e busca em profundidade para a construção de matrizes de
adjacência e matrizes de incidência.<p>
<p>Para isso, foram criados os seguintes arquivos: os arquivos grph.h e grph.c, 
que contêm asestruturas de grafo, e suas funções, filas, e suas funções, e
a função que incia as matrizes a serem analizadas, os arquivos dfs.h e dfs.c,
que contêm as funções que realizam a busca em profundidade e registram os 
valores nas matrizes, os arquivos bfs.h e bfs.c, que contêm as funções que 
realizam a busca em largura e registram os valores nas matrizes, e o arquivo
main.c, que realiza do o processos processos de busca e marcação de tempo.<p>

# COMPILANDO
## LINUX
Navegue aé o diretório do programa, pelo console, e insira os seguintes comandos:
1.
```sh
  gcc -o BFS_DFS main.c dfs.c dfs.h bfs.c bfs.h grph.c grph.h  
```
