#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/investidor.h"

void cadastrarInvestidor() {
    FILE *arquivo = fopen("admin/data/investidores.dat", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de investidores.\n");
        return;
    }

    Investidor novo;
    printf("\n=== Cadastro de Investidor ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);

    printf("CPF: ");
    scanf("%s", novo.cpf);

    printf("Senha: ");
    scanf("%s", novo.senha);

    fwrite(&novo, sizeof(Investidor), 1, arquivo);
    fclose(arquivo);

    printf("Investidor cadastrado com sucesso!\n");
}
