#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/criptomoeda.h"

void cadastrarCriptomoeda() {
    Criptomoeda nova;

    printf("\n=== Cadastro de Criptomoeda ===\n");
    printf("Nome da criptomoeda: ");
    scanf(" %[^\n]", nova.nome);

    printf("Sigla (ex: BTC): ");
    scanf("%s", nova.sigla);

    printf("Cotação inicial (ex: 312000.50): ");
    scanf("%f", &nova.cotacao);

    FILE *arquivo = fopen("admin/data/criptos.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de criptomoedas.\n");
        return;
    }

    fwrite(&nova, sizeof(Criptomoeda), 1, arquivo);
    fclose(arquivo);

    printf("Criptomoeda cadastrada com sucesso!\n");
}


void excluirCriptomoeda() {
    char sigla[10];
    printf("Digite a sigla da criptomoeda que deseja excluir: ");
    scanf("%s", sigla);

    FILE *arquivo = fopen("admin/data/criptos.dat", "rb");
    FILE *temp = fopen("admin/data/temp.dat", "wb");

    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    Criptomoeda cripto;
    int encontrado = 0;

    while (fread(&cripto, sizeof(Criptomoeda), 1, arquivo)) {
        if (strcmp(cripto.sigla, sigla) == 0) {
            encontrado = 1;
            printf("Criptomoeda encontrada: %s (%s) - R$ %.2f\n", cripto.nome, cripto.sigla, cripto.cotacao);
            printf("Deseja realmente excluir? (s/n): ");
            char opcao;
            scanf(" %c", &opcao);
            if (opcao == 'n' || opcao == 'N') {
                fwrite(&cripto, sizeof(Criptomoeda), 1, temp);
            } else {
                printf("Criptomoeda excluída.\n");
            }
        } else {
            fwrite(&cripto, sizeof(Criptomoeda), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("admin/data/criptos.dat");
    rename("admin/data/temp.dat", "admin/data/criptos.dat");

    if (!encontrado) {
        printf("Criptomoeda não encontrada.\n");
    }
}
