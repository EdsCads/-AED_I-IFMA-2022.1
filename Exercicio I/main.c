#include <stdio.h>
#include <stdlib.h>
#include "poltrCRUD.h"

int salvar(FILE *arqPoltrona, int poltronas[LMAX][CMAX])
{
    if (salvarArquivo(arqPoltrona, poltronas))
        printf("Arquivo Salvo\n\n");
    else
        printf("Arquivo Não Salvo\n\n");
}

void exibirPoltrona(int poltronas[LMAX][CMAX])
{
    for (int i = 0; i < LMAX; i++)
    {
        for (int j = 0; j < LMAX; j++)
            printf("[%d]", poltronas[i][j]);
        printf("\n");
    }
}

void estadoPoltrona(int poltronas[LMAX][CMAX], int lin, int col, int estado)
{
    if (poltronas[lin][col] == estado)
    {
        printf("Ja esta no estado pedido\n\n");
    }
    else if (estado > 5 || estado < 1)
    {
        printf("Opção não existe\n\n");
    }
    else
    {
        poltronas[lin][col] = estado;
        printf("Estado da poltrona alterada\n\n");
    }
}

void menuPoltronaEditar(int poltronas[LMAX][CMAX], int lin, int col)
{
    int opEdit;
    printf("Qual novo estado da poltrona?\n");
    printf("----------------------------\n");
    printf("1- Livre\n");
    printf("2- Comprada\n");
    printf("3- Reservada\n");
    printf("4- Bloqueada\n");
    printf("----------------------------\nOpcao: ");
    scanf("%d", &opEdit);
    switch (opEdit)
    {
    case 1:
        estadoPoltrona(poltronas, lin, col, opEdit);
        return;
    case 2:
        estadoPoltrona(poltronas, lin, col, opEdit);
        return;
    case 3:
        estadoPoltrona(poltronas, lin, col, opEdit);
        return;
    case 4:
        estadoPoltrona(poltronas, lin, col, opEdit);
        return;
    case 0:
        printf("Operacao cancelada");
        return;
    default:
        printf("Operacao invalida");
        return;
    }
}

void editarPoltrona(int poltronas[LMAX][CMAX], int opEdit)
{
    int lin, col;
    do
    {
        printf("Escolha a poltrona\nLinha: ");
        scanf("%d", &lin);
        printf("Coluna: ");
        scanf("%d", &col);
        if (_TESTETABELA_)
        {
            printf("poltrona inexistente\n\n");
        }
    } while (_TESTETABELA_);
    if (opEdit != 2)
    {
        if (poltronas[lin][col] != 1)
            printf("Cadeira indisponivel para acao\n\n");
        else
            estadoPoltrona(poltronas, lin, col, opEdit);
    }
    else
    {
        menuPoltronaEditar(poltronas, lin, col);
    }
}

int menuPoltronaGeral(FILE *arqPoltrona, int poltronas[LMAX][CMAX])
{
    int op;
    printf("----------------------------\n");
    printf("1- Exibir Poltronas\n");
    printf("2- Editar\n");
    printf("3- Comprar\n");
    printf("4- Reservar\n");
    printf("5- Bloquear\n");
    printf("0- Salvar e Sair\n");
    printf("----------------------------\nOpcao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        system("CLS||clean");
        exibirPoltrona(poltronas);
        return 1;
    case 2:
        system("CLS||clean");
        editarPoltrona(poltronas, 2);
        return 1;
    case 3:
        system("CLS||clean");
        editarPoltrona(poltronas, 3);
        return 1;
    case 4:
        system("CLS||clean");
        editarPoltrona(poltronas, 4);
        return 1;
    case 5:
        system("CLS||clean");
        editarPoltrona(poltronas, 5);
        return 1;
    case 0:
        salvar(arqPoltrona, poltronas);
        return 0;
    default:
        printf("Opcao inválida\n");
        return 1;
    }
}

int main()
{
    int poltronas[LMAX][CMAX];
    FILE *arqPoltrona = carregarArquivo(poltronas);
    do
    {
        menuPoltronaGeral(arqPoltrona, poltronas);
    } while (menuPoltronaGeral(arqPoltrona, poltronas) != 0);

    return 0;
}