
#include <stdio.h>
#include "produtos.h"

int main() {
    Produto produtos[MAX_PRODUTOS];
    int tam = 0, codigo, quantidade;
    
    cadastrar_produto(produtos, &tam);
    printf("Realizar venda. Informe o código do produto e a quantidade: ");
    scanf("%d %d", &codigo, &quantidade);
    realizar_venda(produtos, tam, codigo, quantidade);

    return 0;
}
