#ifndef structs_h
#define structs_h

//struct para funcionario
struct funcionario{
    char nomeFuncionario[50];
    char funcao[20];
    char cpf[13];
    char rg[13];
};

//struct para itens alimenticios
struct ingrediente{
    char nome[50];
    float quantidade;
    char dataValidade[15];
};

//struct para estoque de itens não alimenticios
struct estoque{
    char nomeItem[50];
    int qtd;
    char dataValidade[15];
};

//struct para armazenar dados do arquivo de estoque total
struct estTotal{
    char nome[50];
    float qtd;
    char dataValidade[15];
};

#endif
