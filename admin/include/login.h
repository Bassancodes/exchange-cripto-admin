#ifndef LOGIN_H
#define LOGIN_H

typedef struct {
    char nome[50];
    char cpf[12];
    char senha[20];
} Admin;


int autenticarAdmin();
int excluirInvestidor();




#endif
