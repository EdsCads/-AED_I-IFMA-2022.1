#ifndef _POLTRCRUD_H
#include <stdio.h>
#define LMAX 10
#define CMAX 10
#define _TESTETABELA_ lin > LMAX || lin < 0 && col<0 || col> CMAX

typedef struct
{
    char nome[30];
    float valor;
    int estado;
} poltronas;

poltronas poltr;

FILE *carregarArquivo(poltronas poltronas[LMAX][CMAX]);
int salvarArquivo(FILE *arqPoltrona, poltronas poltronas[LMAX][CMAX]);
#endif