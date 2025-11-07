#include <stdio.h> 
#include <string.h>
#include <stdlib.h> //inclui como orientado na atividade
#include <time.h> //inclui como orientado na atividade

typedef struct 
{
    char nome[30];
    char cor[10];
    int tropa;
} Territorio;

//criando void de ataque
void menuAtaque(Territorio* territorios);

void atacar (Territorio*atacante, Territorio* defensor) {
    printf("\n INICIANDO ATAQUE \n");
    printf("%s (%s) ataca %s (%s)",
        atacante->nome, atacante->cor,
        defensor->nome, defensor->cor);
    int dadoAtacante = rand() %6 + 1; //Dado de 1 a 6
    int dadoDefensor = rand() %6 + 1; 
    //Informacoes sobre os dados
    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);
    //Implementar o ataque
    if (dadoAtacante>dadoDefensor){
        printf("ATACANTE VENCEU ! \n");
    } else if (dadoDefensor > dadoAtacante){
        printf("DEFENSOR VENCEU !\n");
    } else {
        printf("EMPATE !\n");
    }
    
    }

int main () {
    srand(time(NULL)); //Para dados serem aleatorios
    //Utilizacao do malloc
    Territorio* territorios = (Territorio*)malloc(5 * sizeof(Territorio));
     if (territorios == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }
    int i; //contador para o laco for
    //utilizando for como orientado na atividade
    printf("CADASTRO DE TERRITORIOS\n");
    //entrada de dados 
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
    printf(" Território %d ", i + 1);
    printf("Nome: %s\n", territorios[i].nome);
    printf("Cor: %s\n", territorios[i].cor);
    printf("Número de tropas: %d\n", territorios[i].tropa);
    }
    
    menuAtaque(territorios);
    free(territorios);
    printf("Memoria liberada com sucesso!\n");

    return 0;

    }

    //Sistema de ataque
void menuAtaque(Territorio* territorios) {
    int opcao, atacante, defensor;
    
    printf("\n SISTEMA DE ATAQUE \n");
    printf("Deseja realizar um ataque?\n");
    printf("1 - SIM\n");
    printf("2 - NÃO\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        printf("\nEscolha o território ATACANTE (1 a 5): ");
        scanf("%d", &atacante);
        printf("Escolha o território DEFENSOR (1 a 5): ");
        scanf("%d", &defensor);
        
    
        atacante--; //Ajustando indices
        defensor--;
        
        
        atacar(&territorios[atacante], &territorios[defensor]);
    } else {
        printf("Saindo do sistema...\n");
    }
}