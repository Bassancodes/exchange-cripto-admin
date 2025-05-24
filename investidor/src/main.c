#include <stdio.h>
#include <string.h>
#include "../include/usuario.h"


int main() {
    Usuario usuarios[10];
    int totalUsuarios = 0;
    carregarUsuarios(usuarios, &totalUsuarios);

    int opcao, usuarioLogado = -1;
    char cpf[12], senha[20];

 while (1) {
        printf("\nCriptomoedas do Bassan\n");

        if (usuarioLogado == -1) {
            printf("1. Login\n");
            printf("2. Criar novo usuario\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

if (opcao == 1) {
                printf("CPF: ");
                scanf("%s", cpf);
                printf("Senha: ");
                scanf("%s", senha);
                usuarioLogado = login(usuarios, totalUsuarios, cpf, senha);

                if (usuarioLogado == -1) {
                    printf("Login invalido.\n");
                }
            } else if (opcao == 2) {
                if (totalUsuarios < 10) {
                    criarUsuario(usuarios, &totalUsuarios);
                    salvarUsuarios(usuarios, totalUsuarios);
                } else {
                    printf("Limite de usuarios atingido.\n");
                }
            } else if (opcao == 0) {
                break;
            }
        } else {
            printf("1. Consultar saldo\n");
            printf("2. Consultar extrato\n");
            printf("3. Depositar reais\n");
            printf("4. Sacar reais\n");
            printf("5. Comprar criptomoedas\n");
            printf("6. Vender criptomoedas\n");
            printf("7. Atualizar cotacoes\n");
            printf("0. Logout\n");

            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                consultarSaldo(&usuarios[usuarioLogado]);
            } else if (opcao == 2) {
                consultarExtrato(&usuarios[usuarioLogado]);
            } else if (opcao == 3) {
                float valor;
                printf("Valor para depositar: ");
                scanf("%f", &valor);
                depositarReais(&usuarios[usuarioLogado], valor);
            } else if (opcao == 4) {
                float valor;
                printf("Valor para sacar: ");
                scanf("%f", &valor);
                printf("Senha: ");
                scanf("%s", senha);
                sacarReais(&usuarios[usuarioLogado], valor, senha);
            } else if (opcao == 5) {
                float valor;
                char criptomoeda[10];
                printf("Criptomoeda (Bitcoin, Ethereum, Ripple): ");
                scanf("%s", criptomoeda);
                printf("Valor para comprar: ");
                scanf("%f", &valor);
                printf("Senha: ");
                scanf("%s", senha);
                comprarCripto(&usuarios[usuarioLogado], criptomoeda, valor, senha);
            } else if (opcao == 6) {
                float valor;
                char criptomoeda[10];
                printf("Criptomoeda (Bitcoin, Ethereum, Ripple): ");
                scanf("%s", criptomoeda);
                printf("Valor para vender: ");
                scanf("%f", &valor);
                printf("Senha: ");
                scanf("%s", senha);
                venderCripto(&usuarios[usuarioLogado], criptomoeda, valor, senha);
            } else if (opcao == 7) {
                atualizarCotacoes();
                printf("Cotacoes atualizadas!\n");
            } else if (opcao == 0) {
                usuarioLogado = -1;
            }

            salvarUsuarios(usuarios, totalUsuarios);
        }
    }

    return 0;
}

