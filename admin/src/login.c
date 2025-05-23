#include <stdio.h>
#include <string.h>
#include "../include/login.h"

int autenticarAdmin() {
    Admin adminPadrao = {"Admin", "00000000000", "admin123"};

    char cpf[12], senha[20];

    printf("Digite o CPF do administrador: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    if (strcmp(cpf, adminPadrao.cpf) == 0 && strcmp(senha, adminPadrao.senha) == 0) {
        printf("Login bem-sucedido!\n");
        return 1;
    } else {
        printf("CPF ou senha incorretos.\n");
        return 0;
    }
}
