#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char sexo;
    char nome[30];
    int idade;
} pessoas;


int main(){
    FILE* arqEntrada=fopen("Entrada.txt","r");
    int numPessoas,numHomens=0,numMulheres=0,idadeMaior=0;
    fscanf(arqEntrada,"%d\n",&numPessoas);
    pessoas pess[numPessoas];
    for (int i = 0; !feof(arqEntrada); i++)
    {
        fscanf(arqEntrada,"%c %s %d\n",&pess[i].sexo,&pess[i].nome,&pess[i].idade);
    }
    for(int i=0;i<numPessoas;i++){
        if(pess[i].sexo=='M'){
            numHomens++;
        }
        else if(pess[i].sexo=='F'){
            printf("%c",pess[i].sexo);
            numMulheres++;
            printf("%d",numMulheres);
        }
        if(idadeMaior<pess[i].idade){
            idadeMaior=pess[i].idade;
        }
    }
    fclose(arqEntrada);
    arqEntrada=fopen("Saida.txt","w");
    fprintf(arqEntrada,"Numero de Homens: %d\nNumero de Mulheres: %d\nA idade da pessoa mais velha: %d",numHomens,numMulheres,idadeMaior);
    fclose(arqEntrada);
    return 0;
}