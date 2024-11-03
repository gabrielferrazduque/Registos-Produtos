# Registos-Produtos
RegistosProdutos
/ produtos.c
#include <stdio.h>
#include "produtos.h"

// Procedimento para cadastrar um novo produto
void cadastrar_produto(Produto produtos[], int *tam) {
    if (*tam >= MAX_PRODUTOS) {
        printf("Cadastro de produtos cheio.\n");
        return;
    }

    Produto novo_produto;
    printf("Informe o código do produto: ");
    scanf("%d", &novo_produto.codigo);
    printf("Informe a descrição do produto: ");
    scanf(" %[^\n]", novo_produto.descricao);
    printf("Informe o valor unitário: ");
    scanf("%f", &novo_produto.valor_unitario);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade_estoque);

    produtos[*tam] = novo_produto;
    (*tam)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Procedimento para alterar o valor unitário
void alterar_valor_unitario(Produto produtos[], int tam, int codigo) {
    int i = 0;
    while (i < tam && produtos[i].codigo != codigo) i++;

    if (i < tam) {
        printf("Informe o novo valor unitário: ");
        scanf("%f", &produtos[i].valor_unitario);
        printf("Valor alterado com sucesso.\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

// Procedimento para realizar venda
void realizar_venda(Produto produtos[], int tam, int codigo, int quantidade) {
    int i = 0;
    while (i < tam && produtos[i].codigo != codigo) i++;

    if (i < tam) {
        if (produtos[i].quantidade_estoque >= quantidade) {
            produtos[i].quantidade_estoque -= quantidade;
            printf("Venda realizada. Total: R$%.2f\n", produtos[i].valor_unitario * quantidade);
        } else {
            printf("Quantidade insuficiente.\n");
        }
    } else {
        printf("Produto não encontrado.\n");
    }
}

// Outros procedimentos para manipulação dos produtos omitidos para brevidade...
