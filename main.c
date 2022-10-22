#include <stdio.h>
#include <string.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    int contFut = 0;
    char sair;

    struct jogador{
        char jogador[30], posicao[30];
        int idade;
        float peso, altura;
    } futebol[20], volei[20], basquete[20];

    printf("\n1 - Futebol\n2 - Volei\n3 - Basquete\n0 - Sair");
    printf("\nEscolha qual de qual esporte é o time: ");
    scanf("%d", &op);

    switch(op){
        case 1:
            do{
                printf("\nDigite o nome do jogador: ");
                fflush(stdin);
                gets(futebol[contFut].jogador);

                printf("Digite a idade: ");
                scanf("%d", &futebol[contFut].idade);

                printf("Digite o peso em kg: ");
                scanf("%f", &futebol[contFut].peso);

                printf("Digite a altura em metros: ");
                scanf("%f", &futebol[contFut].altura);

                printf("Digite a posição em que o jogador atua: ");
                fflush(stdin);
                gets(futebol[contFut].posicao);

                printf("Deseja continuar? <y|n> ");
                scanf("%c", &sair);

                contFut++;
            } while(sair == 'y' || sair == 'Y');

            for(int cont = 0; cont < contFut; cont++){
                printf("\nJogador: %s", futebol[cont].jogador);
                printf("\nIdade: %d", futebol[cont].idade);
                printf("\nPeso: %.2f", futebol[cont].peso);
                printf("\nAltura: %.2f", futebol[cont].altura);
                printf("\nPosição: %s", futebol[cont].posicao);
            }
        break;
    }
}
