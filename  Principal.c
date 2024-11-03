// main.c
#include <stdio.h>
#include "acidentes.h"

int main() {
    Estado estados[NUM_ESTADOS];
    int indice_maior, indice_menor;
    
    coletar_dados(estados);

    encontrar_maior_menor_acidente(estados, &indice_maior, &indice_menor);
    printf("Estado com maior número de acidentes: %s (%d acidentes)\n", estados[indice_maior].nome, estados[indice_maior].num_acidentes);
    printf("Estado com menor número de acidentes: %s (%d acidentes)\n", estados[indice_menor].nome, estados[indice_menor].num_acidentes);

    for (int i = 0; i < NUM_ESTADOS; i++) {
        printf("Percentual de veículos envolvidos em acidentes em %s: %.2f%%\n", estados[i].nome, calcular_percentual_acidentes(estados[i]));
    }

    float media_acidentes = calcular_media_acidentes(estados);
    printf("Média de acidentes no país: %.2f\n", media_acidentes);

    listar_acima_da_media(estados, media_acidentes);
    
    return 0;
}
