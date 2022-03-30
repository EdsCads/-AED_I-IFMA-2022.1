#include <stdio.h>
#include <stdlib.h>


void contarLetra(char letra,int contLetra[26]){
    if(letra=='a'){contLetra[0]++;}
    else if(letra=='b'){contLetra[1]++;}
    else if(letra=='c'){contLetra[2]++;}
    else if(letra=='d'){contLetra[3]++;}
    else if(letra=='e'){contLetra[4]++;}
    else if(letra=='f'){contLetra[5]++;}
    else if(letra=='g'){contLetra[6]++;}
    else if(letra=='h'){contLetra[7]++;}
    else if(letra=='i'){contLetra[8]++;}
    else if(letra=='j'){contLetra[9]++;}
    else if(letra=='k'){contLetra[10]++;}
    else if(letra=='l'){contLetra[11]++;}
    else if(letra=='m'){contLetra[12]++;}
    else if(letra=='n'){contLetra[13]++;}
    else if(letra=='o'){contLetra[14]++;}
    else if(letra=='p'){contLetra[15]++;}
    else if(letra=='q'){contLetra[16]++;}
    else if(letra=='r'){contLetra[17]++;}
    else if(letra=='s'){contLetra[18]++;}
    else if(letra=='t'){contLetra[19]++;}
    else if(letra=='u'){contLetra[20]++;}
    else if(letra=='v'){contLetra[21]++;}
    else if(letra=='w'){contLetra[22]++;}
    else if(letra=='x'){contLetra[23]++;}
    else if(letra=='y'){contLetra[24]++;}
    else if(letra=='z'){contLetra[25]++;}
    else{return ;}
}

char reconhecerLetra(int num){
    if(num==0){return 'a';}
    else if(num==1){return 'b';}
    else if(num==2){return 'c';}
    else if(num==3){return 'd';}
    else if(num==4){return 'e';}
    else if(num==5){return 'f';}
    else if(num==6){return 'g';}
    else if(num==7){return 'h';}
    else if(num==8){return 'i';}
    else if(num==9){return 'j';}
    else if(num==10){return 'k';}
    else if(num==11){return 'l';}
    else if(num==12){return 'm';}
    else if(num==13){return 'n';}
    else if(num==14){return 'o';}
    else if(num==15){return 'p';}
    else if(num==16){return 'q';}
    else if(num==17){return 'r';}
    else if(num==18){return 's';}
    else if(num==19){return 't';}
    else if(num==20){return 'u';}
    else if(num==21){return 'v';}
    else if(num==22){return 'w';}
    else if(num==23){return 'x';}
    else if(num==24){return 'y';}
    else if(num==25){return 'z';}
}

int main(){

    FILE* arqLeitura = fopen("entrada.txt","a+");
    char letra;
    int contLetra[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    while (!feof(arqLeitura))
    {
        contarLetra(getc(arqLeitura),contLetra);
    }
    int maisVezes=0;
    for(int i=0;i<26;i++){
        printf("%d %c %d\n",i,reconhecerLetra(i),contLetra[i]);
        if(contLetra[i]>maisVezes){
            maisVezes=contLetra[i];
            letra=reconhecerLetra(i);
            printf("  %c %d - - ",reconhecerLetra(i),contLetra[i]);
        }
    }
    fprintf(arqLeitura,"\n\nA letra que apareceu mais vezes é a Letra %c com %d numero de repetições",letra,maisVezes);
    fclose(arqLeitura);
    return 0;
}