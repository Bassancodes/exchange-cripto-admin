#ifndef INVESTIDOR_H
#define INVESTIDOR_H

typedef struct {
    char nome[50];
    char cpf[12];
    char senha[20];
    double saldoReais;
    double saldoBTC;
    double saldoETH;
    double saldoXRP;
} Usuario;

void cadastrarInvestidor();
void excluirinvestidor();
void consultarSaldo();
void consultarExtrato();




#endif
