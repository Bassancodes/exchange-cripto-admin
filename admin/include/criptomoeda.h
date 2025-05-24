

#ifndef CRIPTOMOEDA_H
#define CRIPTOMOEDA_H

typedef struct {
    char nome[50];
    char sigla[10];
    float cotacao;
} Criptomoeda;

extern double cotacaoBTC, cotacaoETH, cotacaoXRP;


void cadastrarCriptomoeda();
void excluirCriptomoeda();
void atualizarCotacoes();

#endif
