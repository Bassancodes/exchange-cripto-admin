#ifndef CRIPTO_H
#define CRIPTO_H

typedef struct {
    char nome[20];
    float cotacao;
    float taxaCompra;
    float taxaVenda;
} Criptomoeda;

void cadastrarCriptomoeda();

#endif
