
#ifndef CRIPTOMOEDA_H
#define CRIPTOMOEDA_H

typedef struct {
    char nome[50];
    char sigla[10];
    float cotacao;
} Criptomoeda;

void cadastrarCriptomoeda();
void excluirCriptomoeda();


#endif
