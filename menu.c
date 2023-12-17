#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "structs.h"
#include "funcoes.h"

//função para o menu principal
void menu(){
int opcao;

    printf("Selecione uma opção para prosseguir:\n");
    printf("1 - Gerenciamento de funcionarios\n");
    printf("2 - Gerenciamento de alimentos\n");
    printf("3 - Gerenciamento de estoque\n");
    printf("4 - Fechar programa\n");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        gerenciamentoFuncionario();
        break;

    case 2:
        gerenciamentoAlimentos();
        break;

    case 3:
        gerenciarEstoque();
        break;
    case 4:
        break;
    default:
        break;
    }
}

void gerenciamentoFuncionario(){
    int opcao;
    printf("\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Atualizar cadastro funcionario\n");
    printf("3 - Vizualizar todos funcionarios\n");
    printf("4 - Retornar ao menu principal\n");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        addFuncionario();
        break;
    case 2:
        attCadastroFunc();
        break;
    case 3:
        mostrarFun();
        break;
    case 4:
        menu();
        break;
    default:
        break;
    }
}


void gerenciamentoAlimentos(){
    int opcao;
    printf("\n");
    printf("1 - Adicionar ingrediente\n");
    printf("2 - Atualizar informação sobre ingredientes\n");
    printf("3 - Verificar estoque de ingredientes\n");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        addAlimento();
        break;

    case 2:
        attIng();
        break;

    case 3:
        mostrarEstoqueIng();
        break;

    default:
        break;
    }
}


void subMenuAli(){
    int opcao;
    printf("Selecione uma opcao:\n");
    printf("1 - Adicionar novo produto\n");
    printf("2 - Retornar para o gerenciamento de alimentos\n");
    printf("3 - Retornar ao menu principal\n");
    printf("4 - Encerrar programa\n");
    scanf("%d", &opcao);
    switch (opcao){
    case 1:
        addAlimento();
        break;
    case 2:
        gerenciamentoAlimentos();
        break;
    case 3:
        menu();
        break;
    case 4:

        break;
    default:
        break;
    }}

void gerenciarEstoque(){
    int opcao;
    printf("\n");
    printf("Selecione uma opção:\n");
    printf("1 - Adicionar item\n");
    printf("2 - Buscar item\n");
    printf("3 - Mostrar estoque total\n");
    printf("4 - Retornar ao menu\n");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        addItem();
        break;

    case 2:
        char busca[50];
        printf("Informe o nome do produto para pesquisa: ");
        scanf(" %s", busca);

        buscaEst(busca);
        break;

    case 3:
        unirEstoque();
        mostrarEst();
        break;
    case 4:
        menu();
        break;
    default:
        break;

    }
}
