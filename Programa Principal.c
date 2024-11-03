// main.c
#include <stdio.h>
#include "conta.h"

int main() {
    Conta contas[MAX_CONTAS];
    int tam = 0;
    int opcao, numero;
    
    do {
        printf("\nBanco Dinheiro Certo - Menu de Opções:\n");
        printf("1. Cadastrar nova conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Fazer depósito\n");
        printf("4. Fazer saque\n");
        printf("5. Listar contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Informe o número da nova conta: ");
                scanf("%d", &numero);
                cadastrar_conta(contas, &tam, numero);
                break;
            case 2:
                printf("Informe o número da conta para consulta de saldo: ");
                scanf("%d", &numero);
                consultar_saldo(contas, tam, numero);
                break;
            case 3:
                printf("Informe o número da conta para depósito: ");
                scanf("%d", &numero);
                fazer_deposito(contas, tam, numero);
                break;
            case 4:
                printf("Informe o número da conta para saque: ");
                scanf("%d", &numero);
                fazer_saque(contas, tam, numero);
                break;
            case 5:
                listar_contas(contas, tam);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while(opcao != 0);
    
    return 0;
}
