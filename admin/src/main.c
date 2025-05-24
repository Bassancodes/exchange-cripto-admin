#include <stdio.h>
#include <stdlib.h>
#include "../include/login.h"

#include "../include/investidor.h"
#include "../include/criptomoeda.h"



int main() {
    printf("=== SISTEMA ADMINISTRADOR ===\n");

    if (!autenticarAdmin()) {
        printf("Login inválido. Encerrando o programa.\n");
        return 1;
    }

    int opcao;
    do {
        printf("\n===== MENU ADMINISTRADOR =====\n");
        printf("1. Cadastrar novo investidor\n");
        printf("2. Excluir investidor\n");
        printf("3. Cadastrar criptomoeda\n");
        printf("4. Excluir criptomoeda\n");
        printf("5. Consultar saldo de investidor\n");
        printf("6. Consultar extrato de investidor\n");
        printf("7. Atualizar cotação de criptomoedas\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                 cadastrarInvestidor();
                break;
            case 2:
                 excluirInvestidor();
                break;
            case 3:
                 cadastrarCriptomoeda();
                break;
            case 4:
                 excluirCriptomoeda();
                break;
            case 5:
                 consultarSaldo();
                break;
            case 6:
                 consultarExtrato();
                break;
            case 7:
                atualizarCotacoes();
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 8);

    return 0;
}
