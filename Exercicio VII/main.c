#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char cargo[30];
    short int numCandi;
    char nome[30];
    char partido[4];
    int votos;
} candidato;

typedef candidato elemento;
const elemento VL_NULO = {"", 0, "", "", 0};

#include "candidatoCRUD.h"

tipo_lista listaCandidato;

void manutencao()
{
    printf("OPÇÃO EM MANUTENÇÃO");
}

void limpatela() { system("CLS||reset"); }

void entra_cargo(char* cargo{
    printf("\nQual o cargo do Candidato? ");
    fflush(stdin);
    scanf("%s", cargo);
}

void entra_nome(char *nome) {
  printf("\nQual o nome do Candidato? ");
  fflush(stdin);
  scanf("%s", nome);
}

void entra_partido(char* partido){
    printf("\nQual o partido do Candidato? ");
    fflush(stdin);
    scanf("%s", partido);
}

void entra_voto(int *votos,char* nome){
    printf("\nQuantos votos recebeu o candidato %s? ",*nome);
    fflush(stdin);
    scanf("%d",votos);
}

void entra_numero(short int *numero){
    while (1){
        printf ("\nQual o numero do Candidato? ");
        if (!scanf ("%hi", &numero)){
	        printf ("NC:mero invalido para uso");
	        printf ("%d", numero);
	    }
        else{
	      break;
	    }
    }
}

int calcula_seq() {
    int pos;
    return pos= listaCandidato.tamanho+1;
}

void cadastrar(){

}

void listar() {
  int i, tam;
  elemento elem;
  limpatela();
  printf("\n");
  tam = tamanho(listaCandidato);
  if (tam > 0) {
    for (i = 1; i <= tam; i++) {
      if (obter_elemento(listaCandidato, i, &elem))
        printf("\n%d - %d - %s", i, elem.matricula, elem.nome);
    }
  } else
    printf("Lista vazia");
  printf("\n<tecle ENTER para continuar>");
  getchar();
  getchar();
}

void incluir() {
  int pos, seq;
  elemento elem = VL_NULO;
  limpatela();
  entra_nome(&elem.nome);
  entra_cargo(&elem.cargo);
  entra_numero(&elem.numCandi);
  entra_partido(&elem.partido);
  entra_voto(&elem.votos,&elem.nome);
  pos = calcula_seq();
  if (incluir_elemento(&listaCandidato, elem.sequencial,elem))
    printf("Elemento incluído com sucesso!");
  getchar();
}

void alterar() {
  int pos;
  elemento elem = VL_NULO;
  limpatela();
  listar();
  pos = posicao_para_alterar(tamanho(listaCandidato));
  entra_codigo(&elem.matricula);
  entra_nome(&elem.nome);
  if (alterar_elemento(&listaCandidato, pos, elem))
    printf("Elemento alterado com sucesso!");
  getchar();
}

void excluir() {
  int pos;
  elemento elem = VL_NULO;
  limpatela();
  listar();
  pos = escolhe_excluir(tamanho(listaCandidato));
  if (excluir_elemento(&listaCandidato, pos))
    printf("Aluno excluido com sucesso");
  getchar();
}


int mostraMenu() {
    int op;
    printf("----------------------------\n");
    printf("1 - Ler arquivo\n");
    printf("2 - Listar candidatos com quantidade de votos\n");
    printf("3 - Cadastrar candidato\n");
    printf("4 - Editar dados do candidato\n");
    printf("5 - Excluir candidato\n");
    printf("6 - Votar (simula a urna eletrônica)\n");
    printf("9 - Salvar e sair\n");
    printf("----------------------------\nOpcao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        incluir();
        return 1;
    case 2:
        alterar();
        return 1;
    case 3:
        limpatela();
        excluir();
        return 1;
    case 4:
        limpatela();
        manutencao();
        return 1;
    case 5:
        limpatela();
        // pesquisar();
        return 1;
    case 6:
        limpatela();
        carregar_lista(&listaCandidato);
        return 1;
    case 7:
        limpatela();
        gravar_lista(listaCandidato);
        return 0;
    default:
        printf("Opcao inválida\n");
        return 1;
    }
}

int main(void) {
    int op;
    inicializa_lista(&listaCandidato);
    do
    {
        mostraMenu();
    } while (mostraMenu());
    return 0;
}