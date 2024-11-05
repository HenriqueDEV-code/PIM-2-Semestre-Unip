#ifndef PRODUCT_H

#define PRODUCT_H
#define ARQUIVO_ESTOQUE "produtos.csv"
#define MAX_NOME 101

typedef struct {
	int UID;
	char nome[101];
	char Grupo[51];
	float preco;
	char Medida[4];
	int QNT_Estoque;
	char Data_Validade[11];  // Formato: YYYY-MM-DD
} Mercadoria;


void CadastroProduto();
void EditeProduto();
void ExcluirProduto();
void BuscarProduto();
void ListarProduto();


#endif 