
#include <stdio.h>
#include <string.h>
#include "../include/login.h"

int autenticarAdmin() {
    char cpfDigitado[12];
    char senhaDigitada[20];

    printf("\n=== LOGIN DO ADMINISTRADOR ===\n");
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
