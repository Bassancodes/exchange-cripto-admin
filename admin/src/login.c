#include <stdio.h>
#include <string.h>
#include "../include/login.h"

int autenticarAdmin() {
    char cpfDigitado[12];
    char senhaDigitada[20];

    printf("\n===== LOGIN DO ADMINISTRADOR =====\n");
    printf("Digite o CPF: ");
    scanf("%s", cpfDigitado);

    printf("Digite a senha: ");
    scanf("%s", senhaDigitada);

    // Dados fixos do administrador
    if (strcmp(cpfDigitado, "12345678900") == 0 && strcmp(senhaDigitada, "admin123") == 0) {
        printf("Login realizado com sucesso!\n");
        return 1;
    } else {
        printf("CPF ou senha inválidos.\n");
        return 0;
    }
}

int excluirInvestidorAdmin() {
    char cpf[12];
    FILE *arquivo = fopen("data/users.dat", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    printf("Digite o CPF do investidor a ser excluído: ");
    scanf("%s", cpf);

    Admin usuario;
    int encontrado = 0;
    long pos;

    while (fread(&usuario, sizeof(Admin), 1, arquivo)) {
        if (strcmp(usuario.cpf, cpf) == 0) {
            encontrado = 1;
            pos = ftell(arquivo) - sizeof(Admin);
            fseek(arquivo, pos, SEEK_SET);

            Admin vazio = { "", "", "" };
            fwrite(&vazio, sizeof(Admin), 1, arquivo);

            printf("Investidor com CPF %s foi excluído.\n", cpf);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Investidor não encontrado.\n");
    }

    return encontrado;
}
