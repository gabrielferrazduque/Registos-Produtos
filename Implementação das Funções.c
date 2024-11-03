// acidentes.c
#include <stdio.h>
#include "acidentes.h"

// Procedimento para coletar dados dos estados
void coletar_dados(Estado estados[]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Informe o nome do estado: ");
        scanf(" %[^\n]", estados[i].nome);
        printf("Informe o número de veículos no estado: ");
        scanf("%d", &estados[i].num_veiculos);
        printf("Informe o número de acidentes de trânsito: ");
        scanf("%d", &estados[i].num_acidentes);
    }
}

// Procedimento para encontrar maior e menor número de acidentes
void encontrar_maior_menor_acidente(const Estado estados[], int *indice_maior, int *indice_menor) {
    *indice_maior = 0;
    *indice_menor = 0;

    for (int i = 1; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > estados[*indice_maior].num_acidentes) {
            *indice_maior = i;
        }
        if (estados[i].num_acidentes < estados[*indice_menor].num_acidentes) {
            *indice_menor = i;
        }
    }
}

// Função para calcular o percentual de acidentes por estado
float calcular_percentual_acidentes(const Estado estado) {
    if (estado.num_veiculos == 0) return 0.0;
    return ((float)estado.num_acidentes / estado.num_veiculos) * 100;
}

// Função para calcular a média de acidentes no país
float calcular_media_acidentes(const Estado estados[]) {
    int total_acidentes = 0;
    for (int i = 0; i < NUM_ESTADOS; i++) {
        total_acidentes += estados[i].num_acidentes;
    }
    return (float)total_acidentes / NUM_ESTADOS;
}

// Procedimento para listar estados com acidentes acima da média
void listar_acima_da_media(const Estado estados[], float media) {
    printf("Estados com acidentes acima da média:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        if (estados[i].num_acidentes > media) {
            printf("%s\n", estados[i].nome);
        }
    }
}
