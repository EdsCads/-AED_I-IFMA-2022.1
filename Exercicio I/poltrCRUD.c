#include "poltrCRUD.h"

FILE *carregarArquivo(int poltronas[LMAX][CMAX])
{
    FILE *arqPoltrona = fopen("arqPoltrona.txt", "r");
    if (arqPoltrona == NULL)
    {
        arqPoltrona = fopen("arqPoltrona.txt", "w");
        if (arqPoltrona == NULL)
            return 0;
        else
        {
            for (int i = 0; i < LMAX; i++)
            {
                for (int j = 0; j < CMAX; j++)
                {
                    poltronas[i][j] = 1;
                    fprintf(arqPoltrona, "[%d]", poltronas[i][j]);
                }
                fprintf(arqPoltrona, "\n");
            }
            fclose(arqPoltrona);
            return arqPoltrona;
        }
    }
    else
    {
        for (int i = 0; i < LMAX; i++)
        {
            for (int j = 0; j < CMAX; j++)
            {
                fscanf(arqPoltrona, "[%d]", &poltronas[i][j]);
            }
            fscanf(arqPoltrona, "\n");
        }
        fclose(arqPoltrona);
        return arqPoltrona;
    }
}

int salvarArquivo(FILE *arqPoltrona, int poltronas[LMAX][CMAX])
{
    arqPoltrona = fopen("arqPoltrona.txt", "w");
    if (arqPoltrona == NULL)
        return 0;
    else
    {
        for (int i = 0; i < LMAX; i++)
        {
            for (int j = 0; j < CMAX; j++)
            {
                fprintf(arqPoltrona, "[%d]", poltronas[i][j]);
            }
            fprintf(arqPoltrona, "\n");
        }
        fclose(arqPoltrona);
        return 1;
    }
}