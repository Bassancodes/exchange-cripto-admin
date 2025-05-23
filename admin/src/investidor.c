#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/investidor.h"

void cadastrarInvestidor() {
    FILE *arquivo = fopen("data/users.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    Usuario novo;
    printf("Digite o nome do novo investidor: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    strtok(novo.nome, "\n"); // remove \n
    printf("Digite o CPF: ");
    fgets(novo.cpf, sizeof(novo.cpf), stdin);
    strtok(novo.cpf, "\n");
    printf("Digite a senha: ");
    fgets(novo.senha, sizeof(novo.senha), stdin);
    strtok(novo.senha, "\n");

    // Inicializa saldos com zero
    novo.saldoReais = 0.0;
    novo.saldoBTC = 0.0;
    novo.saldoETH = 0.0;
    novo.saldoXRP = 0.0;

    fwrite(&novo, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);

    printf("Investidor cadastrado com sucesso!\n");
}
