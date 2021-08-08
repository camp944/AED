#ifndef EX4_H
#define EX4_H

void menuEx4();
void menuCarrinho();

int Busca_produto(int id,FilaD ID,FilaD valor,PilhaD Hist);

void Imprime_tabela(FilaD ID,FilaC Nome);
void Gera_tabela(FILE *arquivo,FilaD ID,FilaC Nome,FilaD valor);

void resolve4();

#endif
