#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/usuario.h"

float cotacaoBitcoin = 100000.0;
float cotacaoEthereum = 5000.0;
float cotacaoRipple = 1.0;

int login(Usuario usuarios[], int totalUsuarios, char cpf[], char senha[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return i;
        }
    }
    return -1;
}


void criarUsuario(Usuario usuarios[], int *totalUsuarios) {
    Usuario novoUsuario;

    printf("Digite o CPF (11 digitos): ");
    scanf("%s", novoUsuario.cpf);

    for (int i = 0; i < *totalUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, novoUsuario.cpf) == 0) {
            printf("Erro: Usuario com este CPF ja existe.\n");
            return;
        }
    }

    printf("Digite a senha: ");
    scanf("%s", novoUsuario.senha);

    novoUsuario.saldoReais = 0.0;
    novoUsuario.saldoBitcoin = 0.0;
    novoUsuario.saldoEthereum = 0.0;
    novoUsuario.saldoRipple = 0.0;
    novoUsuario.totalTransacoes = 0;

    usuarios[*totalUsuarios] = novoUsuario;
    (*totalUsuarios)++;

    printf("Usuario criado com sucesso!\n");
}
void consultarSaldo(Usuario *usuario) {
    printf("Saldo em Reais: %.2f\n", usuario->saldoReais);
    printf("Saldo em Bitcoin: %.6f\n", usuario->saldoBitcoin);
    printf("Saldo em Ethereum: %.6f\n", usuario->saldoEthereum);
    printf("Saldo em Ripple: %.6f\n", usuario->saldoRipple);
}

void consultarExtrato(Usuario *usuario) {
    printf("Historico de transacoes:\n");
    for (int i = 0; i < usuario->totalTransacoes; i++) {
        printf("%s\n", usuario->historicoTransacoes[i]);
    }
}
void depositarReais(Usuario *usuario, float valor) {
    usuario->saldoReais += valor;
    printf("Deposito realizado com sucesso!\n");
}

int sacarReais(Usuario *usuario, float valor, char senha[]) {
    if (strcmp(usuario->senha, senha) == 0 && usuario->saldoReais >= valor) {
        usuario->saldoReais -= valor;
        printf("Saque realizado com sucesso!\n");
        return 1;
    }
    printf("Erro no saque: senha incorreta ou saldo insuficiente.\n");
    return 0;
}
void comprarCripto(Usuario *usuario, char criptomoeda[], float valorCompra, char senha[]) {
    if (strcmp(usuario->senha, senha) == 0 && usuario->saldoReais >= valorCompra) {
        float taxa = 0.0;
        float valorLiquido = 0.0;

        if (strcmp(criptomoeda, "Bitcoin") == 0) {
            taxa = 0.02 * valorCompra;
            valorLiquido = valorCompra / cotacaoBitcoin;
            usuario->saldoBitcoin += valorLiquido;
        } else if (strcmp(criptomoeda, "Ethereum") == 0) {
            taxa = 0.01 * valorCompra;
            valorLiquido = valorCompra / cotacaoEthereum;
            usuario->saldoEthereum += valorLiquido;
        } else if (strcmp(criptomoeda, "Ripple") == 0) {
            taxa = 0.01 * valorCompra;
            valorLiquido = valorCompra / cotacaoRipple;
            usuario->saldoRipple += valorLiquido;
        }

        usuario->saldoReais -= (valorCompra + taxa);
        printf("Compra realizada com sucesso! Taxa: %.2f\n", taxa);
    } else {
        printf("Erro na compra: senha incorreta ou saldo insuficiente.\n");
    }
}
void venderCripto(Usuario *usuario, char criptomoeda[], float valorVenda, char senha[]) {
    if (strcmp(usuario->senha, senha) == 0) {
        float taxa = 0.0;
        float valorLiquido = 0.0;

        if (strcmp(criptomoeda, "Bitcoin") == 0) {
            valorLiquido = valorVenda / cotacaoBitcoin;
            if (usuario->saldoBitcoin >= valorLiquido) {
                taxa = 0.03 * valorVenda;
                usuario->saldoBitcoin -= valorLiquido;
                usuario->saldoReais += valorVenda - taxa;
                printf("Venda de Bitcoin realizada com sucesso! Valor: %.2f, Taxa: %.2f\n", valorVenda, taxa);
            } else {
                printf("Saldo insuficiente de Bitcoin.\n");
            }
        } else if (strcmp(criptomoeda, "Ethereum") == 0) {
            valorLiquido = valorVenda / cotacaoEthereum;
            if (usuario->saldoEthereum >= valorLiquido) {
                taxa = 0.02 * valorVenda;
                usuario->saldoEthereum -= valorLiquido;
                usuario->saldoReais += valorVenda - taxa;
                printf("Venda de Ethereum realizada com sucesso! Valor: %.2f, Taxa: %.2f\n", valorVenda, taxa);
            } else {
                printf("Saldo insuficiente de Ethereum.\n");
            }
        } else if (strcmp(criptomoeda, "Ripple") == 0) {
            valorLiquido = valorVenda / cotacaoRipple;
            if (usuario->saldoRipple >= valorLiquido) {
                taxa = 0.01 * valorVenda;
                usuario->saldoRipple -= valorLiquido;
                usuario->saldoReais += valorVenda - taxa;
                printf("Venda de Ripple realizada com sucesso! Valor: %.2f, Taxa: %.2f\n", valorVenda, taxa);
            } else {
                printf("Saldo insuficiente de Ripple.\n");
            }
        } else {
            printf("Criptomoeda invalida.\n");
        }
    } else {
        printf("Erro na venda: senha incorreta.\n");
    }
}
void atualizarCotacoes() {
    srand(time(NULL));
    cotacaoBitcoin += cotacaoBitcoin * ((rand() % 11 - 5) / 100.0);
    cotacaoEthereum += cotacaoEthereum * ((rand() % 11 - 5) / 100.0);
    cotacaoRipple += cotacaoRipple * ((rand() % 11 - 5) / 100.0);
}
void salvarUsuarios(Usuario usuarios[], int totalUsuarios) {
    FILE *file = fopen("usuarios.dat", "wb");
    if (file != NULL) {
        fwrite(usuarios, sizeof(Usuario), totalUsuarios, file);
        fclose(file);
    } else {
        printf("Erro ao salvar usuarios.\n");
    }
}

void carregarUsuarios(Usuario usuarios[], int *totalUsuarios) {
    FILE *file = fopen("usuarios.dat", "rb");
    if (file != NULL) {
        fread(usuarios, sizeof(Usuario), 10, file);
        fclose(file);
    } else {
        printf("Nenhum usuario cadastrado ainda.\n");
    }
}

