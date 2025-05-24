#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cripto.h"

void cadastrarCriptomoeda() {
    FILE *arquivo = fopen("data/criptos.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de criptomoedas.\n");
        return;
    }

    Criptomoeda nova;
    printf("Nome da criptomoeda: ");
    scanf("%s", nova.nome);

    printf("Cotação inicial (R$): ");
    scanf("%f", &nova.cotacao);

    printf("Taxa de compra (0.0 ~ 1.0): ");
    scanf("%f", &nova.taxaCompra);

    printf("Taxa de venda (0.0 ~ 1.0): ");
    scanf("%f", &nova.taxaVenda);

    fwrite(&nova, sizeof(Criptomoeda), 1, arquivo);
    fclose(arquivo);

    printf("Criptomoeda cadastrada com sucesso!\n");
}
]
