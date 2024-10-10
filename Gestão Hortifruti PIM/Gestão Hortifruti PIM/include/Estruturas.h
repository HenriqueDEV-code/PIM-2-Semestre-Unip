#include <stdio.h>

enum keys {
    ENTER = 13,
};

typedef struct Date
{
	int dia;
	int mes;
	int ano;
} data;

typedef struct Mercadoria
{
	const int UIDProduct;
	char descProduct[101];
	char GrupProduct[51];
	data NEWdata;/* 00/00/0000 */
	int EstoqueEnterProduct;
	char UNProductMedida[3];/* UN|CX|KG */
	float PrecoProductCompra;
	float MargemProduct;

} Products;

int MenuPrincipalSistema();
int Cadastro();
void Vendas();
void PesquisaPreco();
void RelatoriosGerais();
void QuemSomos();
void Sujestao();