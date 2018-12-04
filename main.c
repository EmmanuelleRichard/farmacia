#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

FILE *arq;
char nome[30];
int preco;
char validade[30];

FILE* OpenFile(char modo, char caminho[30]){
    switch(modo){
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
    arq = OpenFile('a', "farmacia.txt");
    fprintf(arq, "%s\n %d\n %s\n\n", nome, preco, validade);
    CloseFile(arq);
}

void Listar(){
    arq = OpenFile('l',"farmacia.txt");
    while(!feof(arq)){
        fscanf(arq,"%s %d %s ", &nome, &preco, &validade);
        printf("Nome: %s  -  Preco: %d R$  -  Validade: %s\n", nome, preco, validade);
    }
    CloseFile(arq);
}

void consultar(){
    char pesq[30];

    arq = OpenFile('l',"farmacia.txt");
    printf("\nDigite o nome do medicamento: ");
    scanf("%s", &pesq);
    while(fscanf(arq, "%s\n %d\n", nome, &preco) != EOF){
	if(strcmp(nome, pesq) == 0){
		printf("%s\n %d\n", nome, preco);
        }
    }
    CloseFile(arq);
}

int main(){

    char senha[4];
    char senhaGerente[] = "1111";
    char senhaFuncionario[] = "2222";
    int opcao;

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

                if (strcmp(senha, senhaGerente) == 0 || strcmp(senha, senhaFuncionario) == 0) {
                    printf("\n\nOla. Seja Bem Vindo!\n\n");
                    int i;
                    int quant;
                    printf("Quantos cadastros deseja fazer ? ");
                    scanf("%d",&quant);

                    for(i=0;i<quant;i++){
                    printf("\nDigite o nome do medicamento: ");
                    scanf("%s", &nome);
                    printf("\nDigite o Preco: ");
                    scanf("%d", &preco);
                    printf("\nDigite o Validade no formato 'dd/mm/aaaa': ");
                    scanf("%s", &validade);
                    Cadastra(nome, preco, validade);
                    }
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
                consultar();
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
