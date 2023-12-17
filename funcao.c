#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcoes.h"

// Função para registrar ingredientes em um arquivo.
void registrarIngrediente(struct ingrediente *ingrediente, float qtd, char *nomeArq){
    FILE *arqIng = fopen("ingrediente.txt", "a");

    // Verifica se houve erro ao abrir o arquivo.
    if (arqIng==NULL){
        printf("Erro ao acessar ou criar arquivo\n");
        return;
    }

    // Loop para escrever os ingredientes no arquivo.
    for (int i = 0; i < qtd; i++) {
        fprintf(arqIng, "%s ", ingrediente[i].nome);
        fprintf(arqIng, "%.2f ", ingrediente[i].quantidade);
        fprintf(arqIng, "%s ", ingrediente[i].dataValidade);
        fprintf(arqIng, "\n");
    }
    fclose(arqIng);
}

// Função para atualizar informações de ingredientes em um arquivo
void attIng(){
    FILE *arquivo = fopen("ingrediente.txt", "r");// Abre o arquivo de ingredientes em modo de leitura

    // Verifica se houve erro ao abrir o arquivo
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linhaLida[100];
    int contador = 0;
    // Conta quantas linhas existem no arquivo
    while (fgets(linhaLida, sizeof(linhaLida), arquivo)){
        contador++;
    } struct ingrediente *ing = malloc(contador * sizeof(struct ingrediente));// Aloca memória para um array de estruturas de ingredientes com base no número de linhas.


    if (ing == NULL){
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return;
    } fseek(arquivo, 0, SEEK_SET);// Retorna o ponteiro do arquivo ao início para ler os dados novamente

    // Lê os dados do arquivo e armazena na estrutura de ingredientes
    for (int i = 0; i < contador; i++){
        if (fgets(linhaLida, sizeof(linhaLida), arquivo)){
            sscanf(linhaLida, "%s %f %s", ing[i].nome, &ing[i].quantidade, ing[i].dataValidade);
        }
    } fclose(arquivo);

    char busca[30];
    printf("Informe o nome para alterar o ing: ");
    scanf("%29s", busca);

    for (int i = 0; i < contador; i++){
        if (strcmp(busca, ing[i].nome) == 0){
            printf("Informe o novo nome para o ingrediente: ");
            scanf("%29s", ing[i].nome);
            printf("Informe a nova quantidade: ");
            scanf("%f", &ing[i].quantidade);
            printf("Informe a nova data de validade: ");
            scanf("%14s", ing[i].dataValidade);
        }
    }

    arquivo = fopen("ingrediente.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < contador; i++){
        fprintf(arquivo, "%s %.2f %s\n", ing[i].nome, ing[i].quantidade, ing[i].dataValidade);
    } fclose(arquivo);
    free(ing);

    menu();
}

// Função para registrar funcionarios em um arquivo.
void registrarFuncionario(struct funcionario *cadastro, int qtd, char *nomeArq){
    FILE *arqFun = fopen("funcionarios.txt", "a");

    if (arqFun==NULL){
        printf("Erro ao acessar ou criar arquivo\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(arqFun, "%s ", cadastro[i].nomeFuncionario);
        fprintf(arqFun, "%s ", cadastro[i].funcao);
        fprintf(arqFun, "%s ", cadastro[i].cpf);
        fprintf(arqFun, "%s ", cadastro[i].rg);
        fprintf(arqFun, "\n");
    } fclose(arqFun);
}

// Função para atualizar cadastro de funcionario em struct e arquivo.
void attCadastroFunc(){
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linhaLida[100];
    int contador = 0;

    while (fgets(linhaLida, sizeof(linhaLida), arquivo)){
        contador++;
    } struct funcionario *cadastro = malloc(contador * sizeof(struct funcionario));

    if (cadastro == NULL){
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return;
    }

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < contador; i++){
        if (fgets(linhaLida, sizeof(linhaLida), arquivo)){
            sscanf(linhaLida, "%s %s %s %s", cadastro[i].nomeFuncionario, cadastro[i].funcao, cadastro[i].cpf, cadastro[i].rg);
        }
    } fclose(arquivo);

    char busca[30];
    printf("Informe o nome para alterar o cadastro: ");
    scanf(" %s", busca);

    for (int i = 0; i < contador; i++) {
        if (strcmp(busca, cadastro[i].nomeFuncionario) == 0) {
            printf("Informe o novo nome: ");
            scanf(" %s", cadastro[i].nomeFuncionario);
            printf("Informe a nova função: ");
            scanf(" %s", cadastro[i].funcao);
            printf("Informe o novo cpf: ");
            scanf(" %s", cadastro[i].cpf);
            printf("Informe o novo rg: ");
            scanf(" %s", cadastro[i].rg);
        }
    }

    arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        fprintf(arquivo, "%s %s %s %s\n", cadastro[i].nomeFuncionario, cadastro[i].funcao, cadastro[i].cpf, cadastro[i].rg);
    } fclose(arquivo);

    free(cadastro);
    printf("\n");
    menu();
}

// Função para registrar itens do estoque em um arquivo.
void registrarItem(struct estoque *cadEst, int qtd, char *nomeArq){
    FILE *arqEtq = fopen("estoque.txt", "a");

    if (arqEtq==NULL){
        printf("Erro ao acessar ou criar arquivo\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        fprintf(arqEtq, "%s ", cadEst[i].nomeItem);
        fprintf(arqEtq, "%d ", cadEst[i].qtd);
        fprintf(arqEtq, "%s ", cadEst[i].dataValidade);
        fprintf(arqEtq, "\n");
    } fclose(arqEtq);

    menu();
}


// Função para realizar busca de alimentos ou itens no estoque.
void buscaEst(char *busca) {
    FILE *estoque = fopen("estoqueTotal.txt", "r");
    if (estoque == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    char linhaLida[100];
    int contador = 0;

    while (fgets(linhaLida, sizeof(linhaLida), estoque)) {
        contador++;
    }

    struct estTotal *est = malloc(contador * sizeof(struct estTotal));

    if (est == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(estoque);
        return;
    }fseek(estoque, 0, SEEK_SET);

    for (int i = 0; i < contador; i++) {
        if (fgets(linhaLida, sizeof(linhaLida), estoque)) {
            sscanf(linhaLida, "%s %f %s", est[i].nome, &est[i].qtd, est[i].dataValidade);
        }
    }fclose(estoque);

    int encontrado = 0;

    for (int i = 0; i < contador; i++) {
        if (strcmp(busca, est[i].nome) == 0) {
            printf("Produto: %s\n", est[i].nome);
            printf("Quantidade: %.2f\n", est[i].qtd);
            printf("Data de validade: %s\n", est[i].dataValidade);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
        menu();
    }free(est);

    menu();
}

void unirEstoque() {
    FILE *arqEtq = fopen("estoque.txt", "r");
    FILE *arqIng = fopen("ingrediente.txt", "r");
    FILE *arqEstTotal = fopen("estoqueTotal.txt", "w");

    if (arqEtq == NULL || arqIng == NULL || arqEstTotal == NULL) {
        printf("Erro ao abrir um dos arquivos!\n");
        return;
    }

    char nomeItem[30], dataValidade[15];
    float qtd;

    while (fscanf(arqEtq, "%s %f %s", nomeItem, &qtd, dataValidade) == 3) {
        fprintf(arqEstTotal, "%s %.2f %s\n", nomeItem, qtd, dataValidade);
    }

    char nomeIngrediente[30], dataValidadeIng[15];
    float quantidadeIngrediente;

    while (fscanf(arqIng, "%s %f %s", nomeIngrediente, &quantidadeIngrediente, dataValidadeIng) == 3) {
        fprintf(arqEstTotal, "%s %.2f %s\n", nomeIngrediente, quantidadeIngrediente, dataValidadeIng);
    }

    fclose(arqEtq);
    fclose(arqIng);
    fclose(arqEstTotal);
}
// Função para contar quantos produtos tem no estoque

