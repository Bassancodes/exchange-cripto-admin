
#ifndef INVESTIDOR_H
#define INVESTIDOR_H

typedef struct {
    char nome[50];
    char cpf[12];
    char senha[20];
} Investidor;

void cadastrarInvestidor();
void excluirInvestidor();

#endif
