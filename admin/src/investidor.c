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


void excluirInvestidor() {
    char cpf[12];
    printf("Digite o CPF do investidor que deseja excluir: ");
    scanf("%s", cpf);

    FILE *arquivo = fopen("data/usuarios.dat", "rb");
    FILE *temp = fopen("data/temp.dat", "wb");

    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    Admin usuario;
    int encontrado = 0;

    while (fread(&usuario, sizeof(Admin), 1, arquivo)) {
        if (strcmp(usuario.cpf, cpf) == 0) {
            encontrado = 1;
            printf("\nInvestidor encontrado:\n");
            printf("Nome: %s\nCPF: %s\n", usuario.nome, usuario.cpf);
            printf("Deseja realmente excluir este investidor? (s/n): ");
            char opcao;
            scanf(" %c", &opcao);
            if (opcao == 'n' || opcao == 'N') {
                fwrite(&usuario, sizeof(Admin), 1, temp);
            } else {
                printf("Investidor excluído com sucesso.\n");
            }
        } else {
            fwrite(&usuario, sizeof(Admin), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("data/usuarios.dat");
    rename("data/temp.dat", "data/usuarios.dat");

    if (!encontrado) {
        printf("Nenhum investidor encontrado com esse CPF.\n");
    }
}


void consultarSaldo() {
    char cpf[12];
    printf("Digite o CPF do investidor que deseja consultar: ");
    scanf("%s", cpf);

    FILE *arquivo = fopen("data/usuarios.dat", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Usuario usuario;
    int encontrado = 0;

    while (fread(&usuario, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(usuario.cpf, cpf) == 0) {
            printf("\n--- Dados do Investidor ---\n");
            printf("Nome: %s\n", usuario.nome);
            printf("CPF: %s\n", usuario.cpf);
            printf("Saldo em Reais: R$ %.2f\n", usuario.saldoReais);
            printf("Saldo em BTC: %.6f\n", usuario.saldoBTC);
            printf("Saldo em ETH: %.6f\n", usuario.saldoETH);
            printf("Saldo em XRP: %.6f\n", usuario.saldoXRP);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Investidor não encontrado.\n");
    }

    fclose(arquivo);
}


void consultarExtrato() {
    char cpf[12];
    printf("Digite o CPF do investidor: ");
    scanf("%s", cpf);

    FILE *arquivo = fopen("admin/data/users.dat", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    Usuario usuario;
    int encontrado = 0;

    while (fread(&usuario, sizeof(Usuario), 1, arquivo)) {
        if (strcmp(usuario.cpf, cpf) == 0) {
            encontrado = 1;
            printf("\n===== Extrato do Investidor =====\n");
            printf("Nome: %s\n", usuario.nome);
            printf("CPF: %s\n", usuario.cpf);
            printf("Saldo em Reais: R$ %.2f\n", usuario.saldoReais);
            printf("Bitcoin (BTC): %.6f\n", usuario.saldoBTC);
            printf("Ethereum (ETH): %.6f\n", usuario.saldoETH);
            printf("Ripple (XRP): %.6f\n", usuario.saldoXRP);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Investidor não encontrado.\n");
    }
}
