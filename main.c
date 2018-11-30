#include <stdio.h>
#include <stdlib.h>

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

void Cadastra(char nome[30], int preco){
    FILE *arq;
    arq = OpenFile('a', "farmacia.txt");
    fprintf(arq, "%s %d\n", nome, preco);
    CloseFile(arq);
}

void Listar(){
    FILE *arq;
    char nome[30];
    int preco;

    arq = OpenFile('l',"farmacia.txt");

    while(!feof(arq)){
        fscanf(arq,"%s %d ", &nome, &preco);
        printf("Nome: %s  -  Preco: %d R$\n", nome, preco);
    }
    CloseFile(arq);
}

int main(){
    int opcao;
    char nome[30];
    int preco;
    do{
        system("cls");
        printf("\n\n\t\tBem Vindo ao programa da Farmacia\n");
        printf("\nMENU");
        printf("\n 1 - Registrar Produto");
        printf("\n 2 - Listar de Produtos");
        printf("\n 3 - Sair");

        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao){
            case 1:
                printf("\nDigite o nome: ");
                setbuf(stdin,NULL);
                gets(nome);
                printf("\nDigite o Preco: ");
                scanf("%d", &preco);
                Cadastra(nome, preco);
                system("pause");
                break;
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
    }while(opcao!=3);

    return 0;
}
