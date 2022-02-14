# ESTRUTURA
<p>O presente programa tem que como objetivo apresentar os resultados da aplicação
da busca em largura e busca em profundidade para a construção de matrizes de
adjacência e matrizes de incidência.<p>
<p>Para isso, foram criados os seguintes arquivos: os arquivos "grph.h" e "grph.c", 
que contêm asestruturas de grafo, e suas funções, filas, e suas funções, e
a função que incia as matrizes a serem analizadas, os arquivos "dfs.h" e "dfs.c",
que contêm as funções que realizam a busca em profundidade e registram os 
valores nas matrizes, os arquivos "bfs.h" e "bfs.c", que contêm as funções que 
realizam a busca em largura e registram os valores nas matrizes, e o arquivo
"main.c", que realiza do o processos processos de busca e marcação de tempo.<p>
  
OBSERVAÇÃO: ESTOU COM PROBLEMAS NO COMPUTADOR E NÃO ESTOU CONSEGUINDO COMPILAR
PROGRAMAS EM C (JA DESINSTALEI E INSTALEI O MINGW 2 VEZES E NADA), LOGO PEÇO 
DESCULPAS CASO HAJAM FALHAS MUITO GRAVES.

# COMPILANDO E EXECUTANDO
## LINUX
Para compilar e executar os arquivos, basta navegar até o diretório do programa,
pelo console, e insira os seguintes comandos:
  
1º  ```sh  gcc -o BFS_DFS main.c dfs.c dfs.h bfs.c bfs.h grph.c grph.h  ```
  
2º  ```sh  ./BFS_DFS ```
  
## WINDOWS
Para compilar os arquivos e executaá-los no Windows, basta executar o arquivo 
"AEDS.bat" e em seguida o executável "BFS_DFS.exe".
