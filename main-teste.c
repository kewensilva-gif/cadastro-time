#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op, contFut, cfut, contVol, cvol, contBas, cbas, check, flag, flag2;
    contFut = cfut = contVol = cvol = contBas = cbas = flag = flag2 = 0;
    char sair, auxNome[30], aux;
    float calculo;

    struct jogador{
        char jogador[30], posicao[30], tabIMC[30];
        int idade;
        float peso, altura, imc, proteina, carbo, lipidios, calorias;
    };

    struct time {
        char nome[30];
        struct jogador jogadores[20];
    } futebol[20];

    do{
        printf("1 - Futebol\n2 - Volei\n3 - Basquete\n0 - Sair");
        printf("\nEscolha o esporte: ");
        scanf("%d", &op);
        system("cls");

        switch(op){
            case 1:
                printf("Digite o nome do time: ");
                fflush(stdin);
                gets(futebol[cfut].nome);

                do{
                    printf("\nDigite o nome do jogador: ");
                    fflush(stdin);
                    gets(futebol[cfut].jogadores[contFut].jogador);

                    printf("Digite a idade: ");
                    scanf("%d", &futebol[cfut].jogadores[contFut].idade);

                    printf("Digite o peso em kg: ");
                    scanf("%f", &futebol[cfut].jogadores[contFut].peso);

                    printf("Digite a altura em metros: ");
                    scanf("%f", &futebol[cfut].jogadores[contFut].altura);

                    printf("Digite a posi��o em que o jogador atua: ");
                    fflush(stdin);
                    gets(futebol[cfut].jogadores[contFut].posicao);

                    futebol[cfut].jogadores[contFut].imc = futebol[cfut].jogadores[contFut].peso / pow(futebol[cfut].jogadores[contFut].altura,2);

                    printf("Deseja continuar? <y|n> ");
                    scanf("%c", &sair);
                    system("cls");
                    contFut++;
                } while(sair == 'y' || sair == 'Y');
                cfut++;
                contFut = 0;
            break;

            case 0:
                printf("\nSaindo do programa...");
            break;

            default:
                printf("\nOpcao invalida");
        }

        printf("Deseja fazer avalia��o de jogadores ou cadastrar um novo time? <1 - 2> ");
        scanf("%d", &check);

        if(check == 1){
            do{
                printf("A - Exibir time\nB - Exibir dados de um jogador\nC - Exibir medias do time\nD - Modificar dados do jogador\nS - Sair");
                printf("\nDigite a op��o desejada: ");
                fflush(stdin);
                scanf("%c", &sair);
                system("cls");

                switch(sair){
                case 'a':
                case 'A':
                    printf("\nDigite o nome do Time: ");
                    fflush(stdin);
                    gets(auxNome);
                    flag = 0;
                    flag2 = 0;
                    for(int x = 0; x < cfut; x++){
                        for(int y = 0; y < 20; y++){
                            if(strcmp(auxNome, futebol[x].nome) == 0){
                                flag = 1;
                                printf("\nJogadores do Time %s\n", futebol[x].nome);
                                if(futebol[x].jogadores[y].idade == 0 && futebol[x].jogadores[y].peso == 0 && futebol[x].jogadores[y].altura == 0)
                                    break;
                                else {
                                    flag2 = 1;
                                    printf("\nJogador: %s", futebol[x].jogadores[y].jogador);
                                    printf("\tPosi��o: %s", futebol[x].jogadores[y].posicao);
                                    printf("\n");
                                }
                            }
                        }
                        if(!flag2)
                            printf("\nN�o h� jogadores cadastrados nesse time");
                        if(!flag)
                            printf("\nEste time n�o est� cadastrados no banco de dados");
                    }
                    break;
                case 'b':
                case 'B':
                printf("\nDigite o nome do Jogador: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < cfut; x++){
                    for(int y = 0; y < 20; y++){
                        if(futebol[x].jogadores[y].idade == 0 && futebol[x].jogadores[y].peso == 0 && futebol[x].jogadores[y].altura == 0)
                            break;

                        else if(strcmp(auxNome, futebol[x].jogadores[y].jogador) == 0){
                            flag = 1;
                            printf("Jogador: %s", futebol[x].jogadores[y].jogador);
                            printf("\nIdade: %d", futebol[x].jogadores[y].idade);
                            printf("\nPeso: %.2f", futebol[x].jogadores[y].peso);
                            printf("\nAltura: %.2f", futebol[x].jogadores[y].altura);
                            printf("\nPosi��o: %s", futebol[x].jogadores[y].posicao);
                            printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                            calculo = 15.057 * futebol[x].jogadores[y].peso + 692.2;
                            printf("\nCalculo: %.2f", calculo);
                            // Tabela IMC
                            if(futebol[x].jogadores[y].imc < 19){
                                printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� abaixo do peso.\nDeve consumir %.2f kcal di�rias para engordar 2kg por m�s",  calculo + 500);
                            } else if(futebol[x].jogadores[y].imc < 25){
                                printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� com o peso regular/normal.\nDeve consumir %.2f kcal di�rias para manter o peso atual", calculo);
                            } else if(futebol[x].jogadores[y].imc < 30){
                                printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� com excesso de peso.\nDeve consumir %.2f kcal di�rias para emagrecer 2kg por m�s", calculo - 500);
                            } else if(futebol[x].jogadores[y].imc < 35){
                                printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� com Obesidade classe I.\nDeve consumir %.2f kcal di�rias para emagrecer 2kg por m�s", calculo - 500);
                            } else if(futebol[x].jogadores[y].imc < 40){
                                printf("\nIMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� com Obesidade classe II.\nDeve consumir %.2f kcal di�rias para emagrecer 2kg por m�s", calculo - 500);
                            } else {
                                printf("\IMC: %.2f", futebol[x].jogadores[y].imc);
                                printf("O jogador est� com Obesidade classe III.\nDeve consumir %.2f kcal di�rias para emagrecer 2kg por m�s", calculo - 500);
                            }
                        }
                    }
                }
                if(!flag)
                    printf("\nEsse jogador n�o est� cadastrado no banco de dados");
                break;
                case 's':
                case 'S':
                    printf("\nVoltando ao menu inicial...");
                    system("cls");
                    break;
                default:
                    printf("\nop��o inv�lida");
                }
                printf("\n");
            } while(sair != 's' && sair != 'S');
        }

    } while(op != 0);

}
