#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* OpenFile(char modo, char caminho[30]){
    FILE *arq;
    switch(modo){
        case 'g':
            arq = fopen(caminho,"wt");
            break;
        case 'l':
            arq = fopen(caminho,"rt");
            break;
        case 'a':
            arq = fopen(caminho,"a");
            break;
    }
    if(arq==NULL){
        printf("Nao foi possivel abrir o arq");
        exit(0);
    }
    return arq;
}

void CloseFile(FILE *arq){
    fclose(arq);
}

void Cadastra(char nome[30], int preco, char validade[30]){
    FILE *arq;
    arq = OpenFile('a', "farmacia.txt");
    fprintf(arq, "%s %d %s\n", nome, preco, validade);
    CloseFile(arq);
}

void Listar(){
    FILE *arq;
    char nome[30];
    int preco;
    char validade[30];

    arq = OpenFile('l',"farmacia.txt");

    while(!feof(arq)){
        fscanf(arq,"%s %d %s", &nome, &preco, &validade);
        printf("Nome: %s  -  Preco: %d R$  -  Validade: %s\n", nome, preco, validade);
    }
    CloseFile(arq);
}

int main(){

    char senha[4];
    char senhaGerente[] = "1111";
    char senhaFuncionario[] = "2222";

    int opcao;
    char nome[30];
    int preco;
    char validade[30];
    do{
        system("cls");
        printf("\n\n\t\tBem Vindo ao programa da Farmacia\n");
        printf("\nMENU");
        printf("\n 1 - Registrar Medicamentos - Gerente/Funcionario");
        printf("\n 2 - Area do Cliente");
        printf("\n 3 - Sair");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao){
            case 1:
                printf("Digite sua senha: ");
                scanf("%s", &senha);

                if (strcmp(senha, senhaGerente) == 0) {
                    printf("\n\nOla Gerente. Seja Bem Vindo!\n\n");
                    printf("\nDigite o nome: ");
                    scanf("%s", &nome);
                    printf("\nDigite o Preco: ");
                    scanf("%d", &preco);
                    printf("\nDigite o Validade no formato 'dd/mm/aaaa': ");
                    scanf("%s", &validade);
                    Cadastra(nome, preco, validade);
                    system("pause");
                    break;
                    }

                else if (strcmp(senha, senhaFuncionario) == 0) {
                    printf("\n\nOla, Funcionario. Seja Bem Vindo!\n\n");
                    printf("\nDigite o nome: ");
                    scanf("%s", &nome);
                    printf("\nDigite o Preco: ");
                    scanf("%d", &preco);
                    printf("\nDigite o Validade no formato 'dd/mm/aaaa': ");
                    scanf("%s", &validade);
                    Cadastra(nome, preco, validade);
                    system("pause");
                    break;
                    }

                else {
                    printf("\nAcesso negado!");
                    system("pause");
                    break;
                    }
            case 2:
                Listar();
                system("pause");
                break;
            case 3:
                printf("\n\nFinalizando...\n\n");
                system("pause");
                exit(0);
                break;

            default:
                printf("\n\nOpcao invalida! Tente Novamente!\n\n");
                system("pause");

        }
    }

    while(opcao!=3);

    return 0;
}
