#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "poltrCRUD.h"

void salvar(FILE* binArquivo,poltronas poltr[LMAX][CMAX]){
    if(salvarArquivo(binArquivo,poltr)==0){
        printf("ARQUIVO SALVO\n\n");
    }
    else{
        printf("ARQUIVO NÂO SALVO\n\n");
    }
}

void exibirPoltrona(poltronas poltr[LMAX][CMAX]){
    for(int i=0;i<LMAX;i++){
        for(int j=0;j<CMAX;j++){
            printf("[%d]",poltr[i][j].estado);
        }
        printf("\n");
    }
}

void definirPreco(poltronas poltr[LMAX][CMAX],int lin, int col){
    if(col>3&&col<7){
        if(lin>5){
            poltr[lin][col].valor=8.00;
        }
        else if(lin<=5){
            poltr[lin][col].valor=5.00;
        }
    }
    else if(col<4||col>6){
        poltr[lin][col].valor=4.00;
    }
}

void estadoPoltrona(poltronas poltr[LMAX][CMAX],int lin, int col,int opEdit){
    char nome[30];
    if(poltr[lin][col].estado==opEdit){
        printf("Ja esta no estado pedido\n\n");
    }
    else if(opEdit>5||opEdit<1){
        printf("Opção não existe\n\n");
    }
    else{
        if(opEdit==4||opEdit==1){
            strcpy(poltr[lin][col].nome,"");
            poltr[lin][col].valor=0;
            poltr[lin][col].estado=opEdit;
        }
        else if(opEdit==2||opEdit==3){
            printf("Nome do comprador: ");
            fflush(stdin);
            gets(nome);
            strcpy(poltr[lin][col].nome,nome);
            poltr[lin][col].estado=opEdit;
            if(opEdit==2){
                definirPreco(poltr, lin,col);
            }
            else{
                poltr[lin][col].valor=0;
            }
        }
    }
}

void menuPoltronaEditar(poltronas poltr[LMAX][CMAX],int lin,int col){
    int opEdit;
    printf("Qual novo estado da poltrona?\n");
    printf("----------------------------\n");
    printf("1- Livre\n");
    printf("2- Comprada\n");
    printf("3- Reservada\n");
    printf("4- Bloqueada\n");
    printf("----------------------------\nOpcao: ");
    scanf("%d", &opEdit);
    switch(opEdit){
        case 1:
            estadoPoltrona(poltr,lin,col,opEdit);
            return;
        case 2:
            estadoPoltrona(poltr,lin,col,opEdit);
            return;
        case 3:
            estadoPoltrona(poltr,lin,col,opEdit);
            return;
        case 4:
            estadoPoltrona(poltr,lin,col,opEdit);
            return;
        case 0:
            printf("Operacao cancelada");
            return;
        default:
            printf("Operacao invalida");
            return;
    }
}

void editarPoltrona(poltronas poltr[LMAX][CMAX],int opEdit){
    int lin,col;
    do{
        printf("Escolha a poltrona\nLinha: ");
        scanf("%d",&lin);
        printf("Coluna: ");
        scanf("%d",&col);
        if(_TESTETABELA_){
            printf("poltrona inexistente\n\n"); 
        }
    }while(_TESTETABELA_);
    if(opEdit!=1){
        if(poltr[lin][col].estado!=1)
            printf("Cadeira indisponivel para acao\n\n");
        else estadoPoltrona(poltr,lin,col,opEdit);
    }
    else{
        menuPoltronaEditar(poltr,lin,col);
    }
}

void pesquisarCliente(poltronas poltr[LMAX][CMAX]){
    char nome[30];

    printf("Digite o nome do comprador: ");
    fflush(stdin);
    gets(nome);

    for(int i=0;i<LMAX;i++){
        for(int j=0;j<CMAX;j++){
            if(strcmp(poltr[i][j].nome,nome)==0){
                printf("Nome: %s\nValor: %.2f\nPoltrona: %d %d\n\n",poltr[i][j].nome,poltr[i][j].valor,i,j);
            }
        }
    }

}

void somarValorBilhete(poltronas poltr[LMAX][CMAX]){
    float total;

    for(int i=0;i<LMAX;i++){
        for(int j=0;j<CMAX;j++){
            total=total+poltr[i][j].valor; 
        }
    }

    printf("O valor arrecadado de todos os bilhetes é de RS %.2f\n",total);
}

int menuPoltronaGeral(FILE *binPoltrona,poltronas poltr[LMAX][CMAX]){
    int op;
        printf("----------------------------\n");
        printf("1- Exibir Poltronas\n");
        printf("2- Editar\n");
        printf("3- Comprar\n");
        printf("4- Reservar\n");
        printf("5- Bloquear\n");
        printf("6- Pesquisar Cliente\n");
        printf("7- Somar valor total\n");
        printf("0- Salvar e Sair\n");
        printf("----------------------------\nOpcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                system("CLS||clean");
                exibirPoltrona(poltr);
                return;
            case 2:
                system("CLS||clean");
                editarPoltrona(poltr,1);
                return;
            case 3:
                system("CLS||clean");
                editarPoltrona(poltr,2);
                return 1;
            case 4:
                system("CLS||clean");
                editarPoltrona(poltr,3);
                return 1;
            case 5:
                system("CLS||clean");
                editarPoltrona(poltr,4);
                return 1;
            case 6:
                system("CLS||clean");
                pesquisarCliente(poltr);
                return 1;
            case 7:
                system("CLS||clean");
                somarValorBilhete(poltr);
                return 1;
            case 0:
                salvar(binPoltrona,poltr);
                return 0;
            default:
                printf("Opcao inválida\n");
                return;
        }
        if(op==0)
            return 0;
        else
            return 1;
    }

int main(){
    poltronas poltr[LMAX][CMAX];
    FILE* binPoltrona = carregarArquivo(poltr);

    do{
        menuPoltronaGeral(binPoltrona,poltr);
    }while(menuPoltronaGeral(binPoltrona,poltr)!=0);
 
    
    return 0;
}