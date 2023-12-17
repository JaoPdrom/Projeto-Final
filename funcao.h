#ifndef funcao_h
#define funcao_h

void registrarIngrediente(struct ingrediente *ingrediente, float qtd, char *nomeArq);
void registrarFuncionario(struct funcionario *cadastro, int qtd, char *nomeArq);
void registrarItem(struct estoque *cadEst, int qtd, char *nomeArq);
void unirEstoque();
void attCadastroFunc();
void attIng();
void buscaEst();
void unirEstoque();

#endif
