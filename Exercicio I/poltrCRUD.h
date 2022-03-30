#ifndef _POLTRCRUD_H
#include <stdio.h>
#define LMAX 10
#define CMAX 10
#define _TESTETABELA_ lin > LMAX || lin < 0 && col<0 || col> CMAX

FILE *carregarArquivo(int poltronas[LMAX][CMAX]);
int salvarArquivo(FILE *arqPoltrona, int poltronas[LMAX][CMAX]);
#endif