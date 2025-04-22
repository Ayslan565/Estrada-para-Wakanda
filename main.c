#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"
#include "cidades.c"
int main () {
    int Soma = 0;
    int NumTeste = 0;
    FILE *Resposta = fopen("Resultado.txt", "w");
    Estrada *T1 = getEstrada("nomeArquivo.txt");
    double D1 = calcularMenorVizinhanca("nomeArquivo.txt");
    char *C1 = cidadeMenorVizinhanca("nomeArquivo.txt");
    if (T1->T == 30) Soma++;
    NumTeste++;
    if (T1->N == 15) Soma++;
    NumTeste++;

    if (D1 == 3.5) Soma++;
    NumTeste++;
    if (strcmp(C1, "Birnin Zana")==0) Soma++;
    NumTeste++;
    fprintf(Resposta, "\n\nATENÇÃO: Você acertou %d de %d itens. Logo, em 2.00 pontos, sua nota foi %.2f.\n", Soma, NumTeste, 2.0 * (float)Soma/(float)NumTeste);
}
