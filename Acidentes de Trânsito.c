// acidentes.h
#ifndef ACIDENTES_H
#define ACIDENTES_H

#define NUM_ESTADOS 26

typedef struct {
    char nome[30];
    int num_veiculos;
    int num_acidentes;
} Estado;

void coletar_dados(Estado estados[]);
void encontrar_maior_menor_acidente(const Estado estados[], int *indice_maior, int *indice_menor);
float calcular_percentual_acidentes(const Estado estado);
float calcular_media_acidentes(const Estado estados[]);
void listar_acima_da_media(const Estado estados[], float media);

#endif
