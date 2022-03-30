#include<stdio.h>
#include<string.h>
#include "poltrCRUD.h"

FILE* carregarArquivo(poltronas poltr[LMAX][CMAX]){
    FILE* arqPoltrona=fopen("binPoltrona.bin","rb");
    if(arqPoltrona==NULL){
        arqPoltrona=fopen("binPoltrona.bin","wb");
        if(arqPoltrona==NULL)
            return 0;
        else{
            for(int i=0;i<LMAX;i++){
                for(int j=0;j<CMAX;j++){
                    strcpy(poltr[i][j].nome,"");
                    poltr[i][j].valor=0;
                    poltr[i][j].estado=1;
                }
            }
            
            fwrite(poltr,sizeof(poltronas),sizeof(poltronas),arqPoltrona);
            fclose(arqPoltrona);
            return arqPoltrona;
        }
    }
    else{
        while(!feof(arqPoltrona)){
            fread(poltr, sizeof(poltronas), LMAX*CMAX, arqPoltrona);
        }
        fclose(arqPoltrona);
        return arqPoltrona;
    }
}

int salvarArquivo(FILE *arqPoltrona,poltronas poltr[LMAX][CMAX]){
    arqPoltrona=fopen("binPoltrona.bin","wb");
    if(arqPoltrona!=NULL){
        fwrite(poltr,sizeof(poltronas),CMAX*LMAX,arqPoltrona);
        fclose(arqPoltrona);
        return 0;
    }
    else
        return 1;
}