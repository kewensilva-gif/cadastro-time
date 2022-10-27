#include <stdio.h>
#include <string.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op, cont, ctime, check, flag, flag2, direto;
    cont = ctime = flag = flag2 = direto = 0;
    char sair, auxNome[30], aux, op2;
    float calculo, caloria;

    struct jogador{
        char jogador[30], posicao[30], tabIMC[30];
        int idade;
        float peso, altura, imc;
    } auxTimes;

    struct time {
        char nome[30];
        struct jogador jogadores[20];
    } times[20];

    printf("1 - Inserir time\n0 - Sair");
    printf("\nSelecione a opção desejada: ");
    scanf("%d", &op);
    system("cls");

    do{
        switch(op){
            case 1:
                printf("Digite o nome do time: ");
                fflush(stdin);
                gets(times[ctime].nome);
                printf("\n");
                do{
                    printf("Digite o nome do jogador: ");
                    fflush(stdin);
                    gets(times[ctime].jogadores[cont].jogador);

                    printf("Digite a idade: ");
                    scanf("%d", &times[ctime].jogadores[cont].idade);

                    printf("Digite o peso em kg: ");
                    scanf("%f", &times[ctime].jogadores[cont].peso);

                    printf("Digite a altura em metros: ");
                    scanf("%f", &times[ctime].jogadores[cont].altura);

                    printf("Digite a posição em que o jogador atua: ");
                    fflush(stdin);
                    gets(times[ctime].jogadores[cont].posicao);

                    times[ctime].jogadores[cont].imc = times[ctime].jogadores[cont].peso / pow(times[ctime].jogadores[cont].altura,2);

                    printf("Deseja continuar? <s|n> ");
                    scanf("%c", &sair);
                    system("cls");
                    cont++;
                } while(sair == 's' || sair == 'S');
                ctime++;
                cont = 0;
            break;

            case 2:
                printf("\nDigite o time que deseja alterar o nome: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < ctime; x++){
                    if(strcmp(auxNome, times[x].nome) == 0){
                    flag = 1;
                    printf("\nDigite o novo nome do time: ");
                    fflush(stdin);
                    gets(times[x].nome);
                    }
                }
                if(!flag)
                    printf("\nEste time não está cadastrados no banco de dados");
                break;

            case 3:
                printf("\nDigite o time em que deseja inserir novos jogadores: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < ctime; x++){
                    if(strcmp(auxNome, times[x].nome) == 0){
                        flag = 1;
                        for(int y = 0; y < 20; y++){
                            if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0){
                                printf("Digite o nome do jogador: ");
                                fflush(stdin);
                                gets(times[x].jogadores[y].jogador);

                                printf("Digite a idade: ");
                                scanf("%d", &times[x].jogadores[y].idade);

                                printf("Digite o peso em kg: ");
                                scanf("%f", &times[x].jogadores[y].peso);

                                printf("Digite a altura em metros: ");
                                scanf("%f", &times[x].jogadores[y].altura);

                                printf("Digite a posição em que o jogador atua: ");
                                fflush(stdin);
                                gets(times[x].jogadores[y].posicao);

                                break;
                            }
                        }
                    }
                }
                if(!flag)
                printf("\nEste time não está cadastrados no banco de dados");
                break;

            case 4:
                printf("\nDigite o time em que o jogador atua: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < ctime; x++){
                    if(strcmp(auxNome, times[x].nome) == 0){
                        flag = 1;
                        printf("\nDigite o nome do jogador que deseja modificar os dados: ");
                        fflush(stdin);
                        gets(auxNome);
                            for(int y = 0; y < 20; y++){
                                if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0)
                                    break;

                                else if(strcmp(auxNome, times[x].jogadores[y].jogador) == 0){
                                        flag2 = 1;
                                        printf("\n****Atenção****\nNessa etapa todos os dados do jogador serão modificados\n");
                                        printf("\nDigite nome do jogador: ");
                                        fflush(stdin);
                                        gets(times[x].jogadores[y].jogador);

                                        printf("Digite a idade: ");
                                        scanf("%d", &times[x].jogadores[y].idade);

                                        printf("Digite o peso em kg: ");
                                        scanf("%f", &times[x].jogadores[y].peso);

                                        printf("Digite a altura em metros: ");
                                        scanf("%f", &times[x].jogadores[y].altura);

                                        printf("Digite a posição em que o jogador atua: ");
                                        fflush(stdin);
                                        gets(times[x].jogadores[y].posicao);

                                        break;
                                }
                            }
                        }
                    }

                if(!flag)
                printf("\nEste time não está cadastrados no banco de dados");
                if(!flag2)
                printf("\nEste jogador não foi cadastrado");
                break;

            case 5:
                printf("\nDigite o time em que o jogador atua: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < ctime; x++){
                    if(strcmp(auxNome, times[x].nome) == 0){
                        flag = 1;
                        printf("\nDigite o nome do jogador que deseja modificar os dados: ");
                        fflush(stdin);
                        gets(auxNome);
                            for(int y = 0; y < 20; y++){
                                if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0)
                                    break;

                                else if(strcmp(auxNome, times[x].jogadores[y].jogador) == 0){
                                        flag2 = 1;
                                        printf("\nA - Modificar o nome\nB - Modificar a idade\nC - Modificar o peso\nD - Modificar a altura\nE - Modificar a posição");
                                        printf("\nSelecione a opção desejada: ");
                                        fflush(stdin);
                                        scanf("%c", &op2);
                                        switch(op2){
                                        case 'a':
                                        case 'A':
                                            printf("\nDigite o nome atualizado do jogador: ");
                                            fflush(stdin);
                                            gets(times[x].jogadores[y].jogador);
                                            break;

                                        case 'b':
                                        case 'B':
                                            printf("Digite a idade atualizada: ");
                                            scanf("%d", &times[x].jogadores[y].idade);
                                            break;

                                        case 'c':
                                        case 'C':
                                            printf("Digite o peso em kg atualizado: ");
                                            scanf("%f", &times[x].jogadores[y].peso);
                                            break;

                                        case 'd':
                                        case 'D':
                                            printf("Digite a altura em metros atualizada: ");
                                            scanf("%f", &times[x].jogadores[y].altura);
                                            break;

                                        case 'e':
                                        case 'E':
                                            printf("Digite a posição em que o jogador atua atualizada: ");
                                            fflush(stdin);
                                            gets(times[x].jogadores[y].posicao);
                                            break;

                                        default:
                                            printf("\nOpção inválida");
                                        }
                                        break;
                                }
                            }
                        }
                    }

                if(!flag)
                printf("\nEste time não está cadastrados no banco de dados");
                if(!flag2)
                printf("\nEste jogador não foi cadastrado");
                break;

            case 6:
                direto = 1;
                break;

            case 0:
                printf("\nSaindo do programa...");
            break;

            default:
                printf("\nOpção inválida");
        }
        if(!direto){
            printf("\nDeseja avançar para o menu de estatisticas e informações ou voltar ao menu de cadastro? <1 - 2> ");
            scanf("%d", &check);
            fflush(stdin);
            system("cls");
        } else{
            check = 1;
        }
        if(check == 1){
            do{
                printf("A - Exibir times cadastrados\nB - Exibir jogadores do time\nC - Exibir dados de um jogador\nS - Sair");
                printf("\nDigite a opção desejada: ");
                fflush(stdin);
                scanf("%c", &sair);
                system("cls");

                switch(sair){
                case 'a':
                case 'A':
                printf("\n-------Lista de times cadastrados-------");
                for(int x = 0; x < ctime; x++){
                    printf("\n%s", times[x].nome);
                    for(int y = 0; y < 20; y++){
                        if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0)
                            break;
                        else
                            cont++;
                    }
                    printf("\nQuantidade de jogadores: %d", cont);
                    cont = 0;
                }
                printf("\n");
                    break;

                case 'b':
                case 'B':
                    printf("\nDigite o nome do Time: ");
                    fflush(stdin);
                    gets(auxNome);
                    flag = 0;
                    flag2 = 0;
                    for(int x = 0; x < ctime; x++){
                        if(strcmp(auxNome, times[x].nome) == 0){
                            flag = 1;
                            printf("\nJogadores do Time %s\n", times[x].nome);
                            for(int y = 0; y < 20; y++){
                                if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0)
                                    break;
                                else {
                                    flag2 = 1;
                                    printf("\nJogador: %s", times[x].jogadores[y].jogador);
                                    printf("\tPosição: %s", times[x].jogadores[y].posicao);
                                    printf("\n");
                                }
                            }
                        }
                        if(!flag)
                            printf("\nEste time não está cadastrados no banco de dados");
                        if(!flag2)
                            printf("\nNão há jogadores cadastrados nesse time");
                    }
                    break;
                case 'c':
                case 'C':
                printf("\nDigite o nome do Jogador: ");
                fflush(stdin);
                gets(auxNome);
                for(int x = 0; x < ctime; x++){
                    for(int y = 0; y < 20; y++){
                        if(times[x].jogadores[y].idade == 0 && times[x].jogadores[y].peso == 0 && times[x].jogadores[y].altura == 0)
                            break;

                        else if(strcmp(auxNome, times[x].jogadores[y].jogador) == 0){
                            flag = 1;
                            printf("Jogador: %s", times[x].jogadores[y].jogador);
                            printf("\nIdade: %d", times[x].jogadores[y].idade);
                            printf("\nPeso: %.2f", times[x].jogadores[y].peso);
                            printf("\nAltura: %.2f", times[x].jogadores[y].altura);
                            printf("\nPosição: %s", times[x].jogadores[y].posicao);
                            printf("\nIMC: %.2f", times[x].jogadores[y].imc);
                            calculo = 15.057 * times[x].jogadores[y].peso + 692.2;
                            // Tabela IMC
                            if(times[x].jogadores[y].imc < 19){
                                caloria = calculo + 500;
                                printf("\nO jogador está abaixo do peso.\nDeve consumir %.2f kcal diárias para engordar 2kg por mês",  caloria);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", caloria);
                                printf("\n        Proteína    :                 %.2fkcal", caloria*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", caloria*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", caloria*0.5);
                            } else if(times[x].jogadores[y].imc < 25){
                                printf("\n\nO jogador está com o peso regular/normal.\nDeve consumir %.2f kcal diárias para manter o peso atual", calculo);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", calculo);
                                printf("\n        Proteína    :                 %.2fkcal", calculo*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", calculo*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", calculo*0.5);
                            } else if(times[x].jogadores[y].imc < 30){
                                caloria = calculo - 500;
                                printf("\nO jogador está com excesso de peso.\nDeve consumir %.2f kcal diárias para emagrecer 2kg por mês", caloria);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", caloria);
                                printf("\n        Proteína    :                 %.2fkcal", caloria*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", caloria*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", caloria*0.5);
                            } else if(times[x].jogadores[y].imc < 35){
                                caloria = calculo - 500;
                                printf("\nO jogador está com Obesidade classe I.\nDeve consumir %.2f kcal diárias para emagrecer 2kg por mês", caloria);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", caloria);
                                printf("\n        Proteína    :                 %.2fkcal", caloria*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", caloria*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", caloria*0.5);
                            } else if(times[x].jogadores[y].imc < 40){
                                caloria = calculo - 500;
                                printf("\nO jogador está com Obesidade classe II.\nDeve consumir %.2f kcal diárias para emagrecer 2kg por mês", caloria);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", caloria);
                                printf("\n        Proteína    :                 %.2fkcal", caloria*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", caloria*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", caloria*0.5);
                            } else {
                                caloria = calculo - 500;
                                printf("\nO jogador está com Obesidade classe III.\nDeve consumir %.2f kcal diárias para emagrecer 2kg por mês", caloria);
                                printf("\n--------Tabela de macronutrientes a serem consumidos--------\n");
                                printf("\n        Calorias    :                %.2fkcal", caloria);
                                printf("\n        Proteína    :                 %.2fkcal", caloria*0.35);
                                printf("\n        Lipídios    :                 %.2fkcal", caloria*0.15);
                                printf("\n        Carboidratos:                 %.2fkcal", caloria*0.5);
                            }
                            printf("\n");
                        }
                    }
                }
                if(!flag)
                    printf("\nEsse jogador não está cadastrado no banco de dados");
                break;

                case 's':
                case 'S':
                    printf("\nVoltando ao menu inicial...");
                    system("cls");
                    break;
                default:
                    printf("\nopção inválida");
                }
                printf("\n");
            } while(sair != 's' && sair != 'S');
        }

        printf("1 - Inserir novo time\n2 - Modificar nome do time\n3 - Inserir novos jogadores em um time\n4 - Modificar todos os dados do jogador\n5 - Modificar dados específicos do jogador\n6 - Avançar para o menu de estatísticas\n0 - Sair");
        printf("\nEscolha o esporte: ");
        scanf("%d", &op);
        system("cls");
    } while(op != 0);
}
