#include <stdio.h> 
#include <string.h>

typedef struct 
{
    char nome[30];
    char cor[10];
    int tropa;
} Territorio;


int main () {
    
    Territorio territorios[5]; //capacidade para 5
    int i; //contador para o laco for
    //utilizando for como orientado na atividade
    printf("CADASTRO DE TERRITORIOS\n");
    //entrada de dados no laco
    for(i=0;i<5;i++){
        printf("\nTerritório %d\n", i+1);

        printf("Digite o nome: ");    
        scanf("%s", territorios[i].nome);

        printf("Qual é a cor: ");
        scanf("%s", territorios[i].cor);

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropa);

    }
    
     //exibicao dos dados
    printf("\nTERRITORIOS CADASTRADOS\n");
    
    for (i=0; i<5; i++){
    printf("\n Território %d\n ", i + 1);
    printf("Nome: %s\n", territorios[i].nome);
    printf("Cor: %s\n", territorios[i].cor);
    printf("Número de tropas: %d\n", territorios[i].tropa);
    }
    
    return 0;

}