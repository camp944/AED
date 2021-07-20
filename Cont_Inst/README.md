# COMPILANDO O PROGRAMA<br>

1º ABRA O PROMPT DE COMANDO;<br>
2º DIGITE O SEGUINTE COMANDO : ```cd <ENDEREÇO DO DIRETÓRIO DO PROGRAMA>```;<br>
3º DIGITE O COMANDO: ```gcc -o <nome do que deseja dar ao arquivo  .exe> main.c processos.c processos.h```;<br>

# DESCRIÇÃO DO PROGRAMA<br>
Este programa está dividido em 2 menus, um que possiblita ao usuário criar uma matriz N x N e<br> 
outro que possibilita ao usuário que ele caminhe pela matriz criada. Além disso, no segundo<br>
menu, o usuário pode verificar a soma dos números da matriz por onde ele caminhou e o número<br>
de saltos que ele fez pela matriz. Por fim, fim ele pode retornar ao menu inicial e criar outra<br>
matriz ou finalizar o programa.<br>

# OBSERVAÇÕES
As matrizes criadas precisam ter pelo menos 2 linhas e 2 colunas e, no máximo, 10 linhas e 10 <br>
colunas. Caso o valor inserido para a dimensão matriz não atenda à essa condição, o programa<br>
redireciona o usuário para que ele insira novamente a dimensão da matriz, visto que a utilização<br>
de valores fora desse intervalo impossibilita o rastreio da caminhada pela matriz quando se utiliza<br>
o método implementado.<br>
