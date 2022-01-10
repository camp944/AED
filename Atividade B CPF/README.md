<h1>Descrição<h1>
<h3>Este programa foi desenvolvido para a resolução de uma atividade que
consiste no desenvolvimento de uma estrutura de árvore B que armazene os 
dados de um indivíduo, e na inserção de um conjunto de 1000 indivíduos, 
que podem ter os seus valores de CPF gerados no momento da execução ou 
podem ser utilizados valores previamente disponibilizados na pasta Dados 
Pessoas. Em seguida, são disponibilizadas, para o usuário, as opções de
pesquisar, adicionar e ou remover uma pessoa do banco de dados.<h3>
<h3>Para melhor organizar as inserções, foi criado um vetor com 10 ponteiros 
Pagina que recebe as inserções de acordo com os 2 algarismos mais à direita 
do CPF, sendo que o primeiro elemento do vetor recebe os CPFs que terminam 
de 00 e 09 e o último elemento do vetor os que têm final de 90 a 99.<h3>
  
<h1>Compilando<h1>
<h3>Para compilar o program basta seguir os passos e comandos de console abaixo ou,
caso esteja executando em Windows, basta executar o arquivo "Compila.bat" e,
em seguida, o arquivo "arvoreB.exe" .<h3>
  
  <h3>1. Navegar até o diretório que contém o programa.<h3>
  <h3>2. Executar o comando:```sh gcc -o arvoreB estruturas.c estruturas.h operacoes.c operacoes.h main.c```
  <h3>3. Executar o comando: <h3> ```sh ./arvoreB```

  
