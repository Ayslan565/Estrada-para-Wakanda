#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"
/*
typedef struct {
char Nome[256]; // Nome do cidade
int Posicao; // Posição da cidade
} Cidade;


typedef struct {
int N; // Número de cidades
int T; // Comprimento da estrada
Cidade *C; // Vetor de cidades
} Estrada;
Estrada *getEstrada(const char *nomeArquivo); // Inicializa cidades no TAD indicado acima.
double calcularMenorVizinhanca(const char *nomeArquivo); // Retorna a menor vizinhança.
char *cidadeMenorVizinhanca(const char *nomeArquivo); // Retorna a cidade que tem menor vizinhança.
#endif*/

void bubble_sort(Estrada *estrada) {
    int n = estrada->N;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (estrada->C[j].Posicao > estrada->C[j + 1].Posicao) {
            
                // Troca as cidades
                Cidade temp = estrada->C[j];
                estrada->C[j] = estrada->C[j + 1];
                estrada->C[j + 1] = temp;
            }
        }
    }
}


Estrada *getEstrada(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);  // ou: return NULL;
    }

    // PEGANDO O TAMANHO E N CIDADES  
    Estrada *estrada = malloc(sizeof(Estrada));
    fscanf(arquivo, "%d %d", &estrada->T, &estrada->N);
    estrada->C = malloc(estrada->N * sizeof(Cidade));


    //Vou colocando no vetor cidades, esta acompanhando posicao e nome juntos 
    // na hora de ordenar tenho que lembrar de usar a struct (Cidade)
    for (int i = 0; i < estrada->N; i++) {
        fscanf(arquivo, "%d %[^\n]s", &estrada->C[i].Posicao, estrada->C[i].Nome);
    }

    fclose(arquivo);

    bubble_sort(estrada);


    return estrada; 
}
double calcularMenorVizinhanca(const char *nomeArquivo) {
    int cidade_anterior = 0;
    int cidade_posterior = 0;
    double limite_vizinhanca = 0;
    double apoio =0;

    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada == NULL) {
        return -1;
    }

        else {
        
        for (int i = 0; i < estrada->N - 1; i++) {
            int cidade_anterior = estrada->C[i].Posicao;
            int cidade_posterior = estrada->C[i + 1].Posicao;
            double limite_vizinhanca = (double) (cidade_posterior - cidade_anterior);
        
            printf("Entre %s (%d) e %s (%d): %.2f unidades\n\n",
                estrada->C[i].Nome, estrada->C[i].Posicao,
                estrada->C[i+1].Nome, estrada->C[i+1].Posicao,
                limite_vizinhanca);
                }
        
    } 
    return limite_vizinhanca;
    }

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    
    return "a";
}