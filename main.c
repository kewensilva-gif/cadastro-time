#include <stdio.h>
#include <string.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op, contFut, cfut, contVol, cvol, contBas, cbas;
    contFut = cfut = contVol = cvol = contBas = cbas = 0;
    char sair;

    struct jogador{
        char jogador[30], posicao[30];
        int idade;
        float peso, altura;
    };

    struct time {
        char nome[30];
        struct jogador jogadores[50];
    } futebol[20], volei[20], basquete[20];

    printf("\n1 - Futebol\n2 - Volei\n3 - Basquete\n0 - Sair");
    printf("\nEscolha qual de qual esporte é o time: ");
    scanf("%d", &op);

    switch(op){
        case 1:
            printf("Digite o nome do time: ");
            fflush(stdin);
            gets(futebol[cfut].nome);
            cfut++;
            do{
                printf("\nDigite o nome do jogador: ");
                fflush(stdin);
                gets(futebol[cfut].jogadores[contFut].jogador);
                printf("\n%s\n", futebol[cfut].jogadores[contFut].jogador);

                printf("Digite a idade: ");
                scanf("%d", &futebol[cfut].jogadores[contFut].idade);
                printf("\n%d\n", futebol[cfut].jogadores[contFut].idade);

                printf("Digite o peso em kg: ");
                scanf("%f", &futebol[cfut].jogadores[contFut].peso);
                printf("\n%.2f\n", futebol[cfut].jogadores[contFut].peso);

                printf("Digite a altura em metros: ");
                scanf("%f", &futebol[cfut].jogadores[contFut].altura);
                printf("\n%.2f\n", futebol[cfut].jogadores[contFut].altura);

                printf("Digite a posição em que o jogador atua: ");
                fflush(stdin);
                gets(futebol[cfut].jogadores[contFut].posicao);
                printf("\n%s\n", futebol[cfut].jogadores[contFut].posicao);

                printf("Deseja continuar? <y|n> ");
                scanf("%c", &sair);

                contFut++;
            } while(sair == 'y' || sair == 'Y');

        break;

        case 2:
            printf("Digite o nome do time: ");
            fflush(stdin);
            gets(volei[cvol].nome);
            cvol++;
            do{
                printf("\nDigite o nome do jogador: ");
                fflush(stdin);
                gets(volei[cvol].jogadores[contVol].jogador);
                printf("\n%s\n", volei[cvol].jogadores[contVol].jogador);

                printf("Digite a idade: ");
                scanf("%d", &volei[cvol].jogadores[contVol].idade);
                printf("\n%d\n", volei[cvol].jogadores[contVol].idade);

                printf("Digite o peso em kg: ");
                scanf("%f", &volei[cvol].jogadores[contVol].peso);
                printf("\n%.2f\n", volei[cvol].jogadores[contVol].peso);

                printf("Digite a altura em metros: ");
                scanf("%f", &volei[cvol].jogadores[contVol].altura);
                printf("\n%.2f\n", volei[cvol].jogadores[contVol].altura);

                printf("Digite a posição em que o jogador atua: ");
                fflush(stdin);
                gets(volei[cvol].jogadores[contVol].posicao);
                printf("\n%s\n", volei[cvol].jogadores[contVol].posicao);

                printf("Deseja continuar? <y|n> ");
                scanf("%c", &sair);

                contVol++;
            } while(sair == 'y' || sair == 'Y');

        break;

        case 3:
            printf("Digite o nome do time: ");
            fflush(stdin);
            gets(basquete[cbas].nome);
            cvol++;
            do{
                printf("\nDigite o nome do jogador: ");
                fflush(stdin);
                gets(basquete[cbas].jogadores[contBas].jogador);
                printf("\n%s\n", basquete[cbas].jogadores[contBas].jogador);

                printf("Digite a idade: ");
                scanf("%d", &basquete[cbas].jogadores[contBas].idade);
                printf("\n%d\n", basquete[cbas].jogadores[contBas].idade);

                printf("Digite o peso em kg: ");
                scanf("%f", &basquete[cbas].jogadores[contBas].peso);
                printf("\n%.2f\n", basquete[cbas].jogadores[contBas].peso);

                printf("Digite a altura em metros: ");
                scanf("%f", &basquete[cbas].jogadores[contBas].altura);
                printf("\n%.2f\n", basquete[cbas].jogadores[contBas].altura);

                printf("Digite a posição em que o jogador atua: ");
                fflush(stdin);
                gets(basquete[cbas].jogadores[contBas].posicao);
                printf("\n%s\n", basquete[cbas].jogadores[contBas].posicao);

                printf("Deseja continuar? <y|n> ");
                scanf("%c", &sair);

                contBas++;
            } while(sair == 'y' || sair == 'Y');

        break;

        case 0:
            printf("\nSaindo do programa...");
        break;

        default:
            printf("\nOpcao invalida");
    }
}
