#include <stdio.h>
#include <stdlib.h>

#include "arvorebinaria.c"
int OPERACAO;
int elem;

int main()
{
    printf("Hello world!\n");
    menu();
    return 0;
}

int menuOp()
{
    OPERACAO = -1;
    printf(" _______________________________________\n");
    printf("|                                       |\n");
    printf("|-----Selecione a Arvore que deseja-----|\n");
    printf("|_______________________________________|\n");
    printf("| [ 1 ] Arvore Binaria                  |\n");
    printf("| [ 2 ] Arvore Binaria de Busca         |\n");
    printf("| [ 0 ] Sair                            |\n");
    printf("|_______________________________________|\n");
    scanf("%i", &OPERACAO);
    if(OPERACAO != 1 && OPERACAO != 2 && OPERACAO != 0) {
        system("cls");
        printf("\n/*****Selecione uma das opcoes 1 ou 2*****/\n\n");
        menuOp();
    } else {
        return OPERACAO;
    }
}

void showMenuArbin()
{
    OPERACAO = -1;
    printf(" _________________________________________\n");
    printf("|                                         |\n");
    printf("|-------------Arvore Binaria--------------|\n");
    printf("|-----Selecione a operacao que deseja-----|\n");
    printf("|_________________________________________|\n");
    printf("| [ 1 ] Inserir elemento                  |\n");
    printf("| [ 2 ] Buscar elemento                   |\n");
    printf("| [ 3 ] Imprimir                          |\n");
    printf("| [ 4 ] Peso                              |\n");
    printf("| [ 5 ] Numero de folhas                  |\n");
    printf("| [ 6 ] Numero de ocorrencias             |\n");
    printf("| [ 7 ] Existe caminho                    |\n");
    printf("| [ 8 ] Verificar se esta vazia           |\n");
    printf("| [ 0 ] Voltar                            |\n");
    printf("|_________________________________________|\n");

    scanf("%i", &OPERACAO);
}

void menuArbin()
{
    printf("\n\n...Inicializa Arvore Binara...\n\n");
    Arbin* a = criaArbinVazia();
    do
    {
        showMenuArbin();
        if(OPERACAO != 1 && OPERACAO != 2 && OPERACAO != 0 && OPERACAO != 3 && OPERACAO != 4 && OPERACAO != 5 && OPERACAO != 6 && OPERACAO != 7 && OPERACAO != 8) {
            showMenuArbin();
        } else {
            switch(OPERACAO) {
                case 1:
                   elem = escolhaElem();
                   a = insArbin(a, elem);
                   printf("Elemento inserido\n\n");
                    break;
                case 2:
                    elem = escolhaElem();
                    if(estaArbin(a, elem) == 1) {
                        printf("Elemento está na arvore\n\n");
                    } else {
                        printf("Elemento nao esta na arvore\n\n");
                    }
                    break;
                case 3:
                    imprimeArbin(a);
                    break;
                case 0:
                    menu();
                    break;
                default:
                    printf("opcao default");
                    break;
            }
        }
    }while(OPERACAO != 0);
}

void menuArbinBusca()
{
    printf("Menu arvore binaria BUSCA");
}

void menu()
 {
    switch(menuOp())
    {
        case 0:
            printf("Sistema finalizado!");
            system("exit");
            break;
        case 1:
            system("cls");
            menuArbin();
            break;
        case 2:
            system("cls");
            menuArbinBusca();
            break;
        default:
            printf("Opcao invalida");
    }
}

int escolhaElem() {
    int elem = -1;
    printf("Digite o elemento(inteiro) que deseja: ");
    scanf("%i", &elem);
    return elem;
}
