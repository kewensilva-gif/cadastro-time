#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op, op2, contFut, cfut, contVol, cvol, contBas, cbas, check, flag, teste;
    contFut = cfut = contVol = cvol = contBas = cbas = flag = 0;
    char sair, auxNome[30];

    struct jogador{
        char jogador[30], posicao[30], tabIMC[30];
        int idade;
        float peso, altura, imc, proteina, carbo, lipidios, calorias;
    };

    struct time {
        char nome[30];
        struct jogador jogadores[50];
    } futebol[20], volei[20], basquete[20];

    do{
        printf("\n1 - Futebol\n2 - Volei\n3 - Basquete\n0 - Sair");
        printf("\nEscolha o esporte: ");
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

                    futebol[cfut].jogadores[contFut].imc = futebol[cfut].jogadores[contFut].peso / pow(futebol[cfut].jogadores[contFut].altura,2);
                    printf("\n%.2f\n", futebol[cfut].jogadores[contFut].imc);

                    // Tabela IMC
                    if(futebol[cfut].jogadores[contFut].imc < 18,5){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Abaixo do peso");
                    } else if(futebol[cfut].jogadores[contFut].imc < 24,9){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Peso normal");
                    } else if(futebol[cfut].jogadores[contFut].imc < 29,9){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Excesso de peso");
                    } else if(futebol[cfut].jogadores[contFut].imc < 34,9){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Obesidade classe I");
                    } else if(futebol[cfut].jogadores[contFut].imc < 39,9){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Obesidade classe II");
                    } else if(futebol[cfut].jogadores[contFut].imc < 39,9){
                        strcpy(futebol[cfut].jogadores[contFut].tabIMC, "Obesidade classe III");
                    }

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

        printf("Deseja fazer avaliação de jogadores ou cadastrar um novo time? <1 - 2> ");
        scanf("%d", &check);

        if(check == 1){
            do{
                printf("\n1 - Exibir time\n2 - Exibir dados de um jogador\n3 - Exibir medias do time\n0 - Sair");
                scanf("%d", &op2);

                switch(op2){
                case 1:
                printf("\nDigite o nome do Time: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < cfut; x++)
                    for(int y = 0; y < contFut; y++){
                        teste = strcmp(auxNome, futebol[x].jogadores[y].jogador);
                        printf("\n\n%d\n\n", teste);
                        if(strcmp(auxNome, futebol[x].nome) == 0){
                            flag = 1;
                            printf("Jogador: %s", futebol[x].jogadores[y].jogador);
                            printf("\nIdade: %d", futebol[x].jogadores[y].idade);
                            printf("\nPeso: %.2f", futebol[x].jogadores[y].peso);
                            printf("\nAltura: %.2f", futebol[x].jogadores[y].altura);
                            printf("\nPosição: %s", futebol[x].jogadores[y].posicao);
                        }
                    }
                if(!flag)
                    printf("\nEsse jogador não está cadastrados no banco de dados");
                break;
                case 2:
                    printf("\nDigite o nome do jogador: ");
                    fflush(stdin);
                    gets(auxNome);
                    for(int x = 0; x < cfut; x++)
                        for(int y = 0; y < contFut; y++){
                            teste = strcmp(auxNome, futebol[x].jogadores[y].jogador);
                            printf("\n\n%d\n\n", teste);
                            if(strcmp(auxNome, futebol[x].jogadores[y].jogador) == 0){
                                flag = 1;
                                printf("Jogador: %s", futebol[x].jogadores[y].jogador);
                                printf("\nIdade: %d", futebol[x].jogadores[y].idade);
                                printf("\nPeso: %.2f", futebol[x].jogadores[y].peso);
                                printf("\nAltura: %.2f", futebol[x].jogadores[y].altura);
                                printf("\nPosição: %s", futebol[x].jogadores[y].posicao);
                            }
                        }
                    if(!flag)
                        printf("\nEsse jogador não está cadastrados no banco de dados");
                    break;
                default:
                    printf("\nopção inválida");
                }
            } while(op2 != 0);
        }

    } while(op != 0);

}
