#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"
#include "funcao.h"
#include "menu.h"
#include "funcoes.h"

//função para adicionar um novo funcionario
void addFuncionario(){
    int qtd;
    printf("\n");
    printf("Quantos funcionarios serão cadastrados? ");
    scanf(" %d", &qtd); printf("\n");
    struct funcionario *cadastroFunc = (struct funcionario *)malloc(qtd * sizeof(struct funcionario));

    for (int i = 0; i < qtd; i++){
        printf("Informe o nome do %dº funcionario: ", i+1);
        scanf(" %s", cadastroFunc[i].nomeFuncionario);
        printf("Informe a função do funcionario: ");
        scanf(" %s", cadastroFunc[i].funcao);
        printf("Informe o CPF do funcionario: ");
        scanf(" %s", cadastroFunc[i].cpf);
        printf("Informe o RG do funcionario: ");
        scanf(" %s", cadastroFunc[i].rg);
        printf("Funcionario cadastrado com sucesso!\n\n");
    } registrarFuncionario(cadastroFunc, qtd, "funcionarios.txt");
    free(cadastroFunc);
    menu();
}

void mostrarFun(){
    char nomeFuncionario[50], funcao[20], cpf[13], rg[13];

    FILE *arqFun=fopen("funcionarios.txt", "r");
    if(arqFun==NULL){
        printf("Falha ao abrir o arquivo.\n");
        return;
    }

    while (fscanf(arqFun, " %s %s %s %s", nomeFuncionario, funcao, cpf, rg) != EOF) {

        printf("Nome: %s\n", nomeFuncionario);
        printf("Função: %s\n", funcao);
        printf("CPF: %s\n", cpf);
        printf("RG: %s\n\n", rg);
    }fclose(arqFun);
    menu();
}

//função para adicionar ingredientes
void addAlimento(){
    int qtd;
    printf("Quantos ingredientes serão adicionados?");
    scanf(" %d", &qtd);
    struct ingrediente *novoIngrediente = (struct ingrediente *)malloc(qtd * sizeof(struct ingrediente));

    for (int i = 0; i < qtd; i++) {
        printf("Informe o nome do ingrediente %d: ", i+1);
        scanf(" %s", novoIngrediente[i].nome);

        printf("Informe a quantidade do ingrediente %d: ", i+1);
        scanf(" %f", &novoIngrediente[i].quantidade);

        printf("Informe a data de validade do ingrediente %d (DD/MM/AAAA): ", i+1);
        scanf(" %s", novoIngrediente[i].dataValidade);
    } registrarIngrediente(novoIngrediente, qtd, "ingrediente.txt");
    free(novoIngrediente);
    printf("\n");
    menu();
};

void addItem(){
    int qtd;
        printf("Informe a quantidade de itens a serem cadastrados: ");
        scanf(" %d", &qtd);
        struct estoque *cadastro = (struct estoque *)malloc(qtd * sizeof(struct estoque));
        if(cadastro==NULL){
            printf("Falha ao alocar memoria\n");
            return;
        }

        for(int i=0; i<qtd; i++){
            printf("Informe o nome do 1º item: ");
            scanf(" %s", cadastro[i].nomeItem);
            printf("Informe a quantidade do 1º item: ");
            scanf(" %d", &cadastro[i].qtd);
            printf("Informe a data de validade do 1º item: ");
            scanf(" %s", cadastro[i].dataValidade);
        } registrarItem(cadastro, qtd, "estoque.txt");

}

void mostrarEstoqueIng() {
    FILE *arqIng = fopen("ingrediente.txt", "r");
    if (arqIng == NULL) {
        printf("Falha ao abrir o arquivo\n");
        return;
    }

    char nomeIng[50], dataVal[15];
    float qtdIng;

    while (fscanf(arqIng, "%s %f %s", nomeIng, &qtdIng, dataVal) != EOF) {

        printf("\n");
        printf("Nome do Ingrediente: %s\n", nomeIng);
        printf("Quantidade: %.2f\n", qtdIng);
        printf("Data de Validade: %s\n", dataVal);
    }fclose(arqIng);

    menu();
}

// Função para mostrar todo estoque
void mostrarEst(){
    FILE *arqEtq = fopen("estoque.txt", "r");

    if (arqEtq==NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    char nomeItem[30], dataValidade[15];
    int qtd;

    while (fscanf(arqEtq, " %s %d %s ", nomeItem, &qtd, dataValidade) != EOF) {

        printf("Informações gerais:\n");
        printf("Nome do produto: %s\n", nomeItem);
        printf("Quantidade: %d\n", qtd);
        printf("Data de Validade: %s\n", dataValidade);
        printf("\n");
    }fclose(arqEtq);
    printf("Informações sobre ingredientes:");
    mostrarEstoqueIng();

}

int main() {
    setlocale(LC_ALL, "Portuguese");

    menu();

}
