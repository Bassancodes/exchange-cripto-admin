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
