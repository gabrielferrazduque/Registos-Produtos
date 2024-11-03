// conta.c
#include <stdio.h>
#include <string.h>
#include "conta.h"

// Função de busca
int buscar_conta(const Conta contas[], int tam, int numero) {
    if (tam == 0) return -1;  // Cadastro vazio
    for (int i = 0; i < tam; i++) {
        if (contas[i].numero == numero) {
            return i;  // Retorna a posição onde a conta foi encontrada
        }
    }
    return -2;  // Conta não encontrada
}

// Procedimento para cadastrar uma nova conta
void cadastrar_conta(Conta contas[], int *tam, int numero) {
    if (*tam >= MAX_CONTAS) {
        printf("Cadastro cheio.\n");
        return;
    }
    
    int posicao = buscar_conta(contas, *tam, numero);
    if (posicao >= 0) {
        printf("Número de conta repetido.\n");
        return;
    }
    
    Conta nova_conta;
    nova_conta.numero = numero;
    
    printf("Informe o nome do titular: ");
    scanf(" %[^\n]", nova_conta.nome);
    printf("Informe o CPF: ");
    scanf(" %[^\n]", nova_conta.cpf);
    printf("Informe o telefone: ");
    scanf(" %[^\n]", nova_conta.telefone);
    nova_conta.saldo = 0.0;
    
    contas[*tam] = nova_conta;
    (*tam)++;
    printf("Conta cadastrada com sucesso!\n");
}

// Procedimento para consultar o saldo
void consultar_saldo(const Conta contas[], int tam, int numero) {
    int posicao = buscar_conta(contas, tam, numero);
    if (posicao >= 0) {
        printf("Saldo da conta %d: R$%.2f\n", contas[posicao].numero, contas[posicao].saldo);
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para fazer depósito
void fazer_deposito(Conta contas[], int tam, int numero) {
    int posicao = buscar_conta(contas, tam, numero);
    if (posicao >= 0) {
        float valor;
        printf("Informe o valor para depósito: ");
        scanf("%f", &valor);
        contas[posicao].saldo += valor;
        printf("Depósito realizado com sucesso. Novo saldo: R$%.2f\n", contas[posicao].saldo);
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para fazer saque
void fazer_saque(Conta contas[], int tam, int numero) {
    int posicao = buscar_conta(contas, tam, numero);
    if (posicao >= 0) {
        float valor;
        printf("Informe o valor para saque: ");
        scanf("%f", &valor);
        if (contas[posicao].saldo >= valor) {
            contas[posicao].saldo -= valor;
            printf("Saque realizado com sucesso. Novo saldo: R$%.2f\n", contas[posicao].saldo);
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para listar todas as contas
void listar_contas(const Conta contas[], int tam) {
    printf("Listagem de contas:\n");
    for (int i = 0; i < tam; i++) {
        printf("Conta: %d, Titular: %s, Telefone: %s\n", contas[i].numero, contas[i].nome, contas[i].telefone);
    }
}
