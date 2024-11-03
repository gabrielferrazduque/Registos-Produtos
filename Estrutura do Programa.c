// conta.h
#ifndef CONTA_H
#define CONTA_H

#define MAX_CONTAS 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[12];
    char telefone[15];
    float saldo;
} Conta;

int buscar_conta(const Conta contas[], int tam, int numero);
void cadastrar_conta(Conta contas[], int *tam, int numero);
void consultar_saldo(const Conta contas[], int tam, int numero);
void fazer_deposito(Conta contas[], int tam, int numero);
void fazer_saque(Conta contas[], int tam, int numero);
void listar_contas(const Conta contas[], int tam);

#endif
