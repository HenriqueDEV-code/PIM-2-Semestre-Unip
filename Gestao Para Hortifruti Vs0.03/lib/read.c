#include <stdio.h>
#include "../include/product.h"

void BuscarProduto() {
	Sleep(500);
	system("CLS");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\aERRO AO ABRIR O ARQUIVO!\n");
		return;
	}

	Mercadoria produto;
	char nome_busca[MAX_NOME];
	int encontrado = 0;
	Console(5, 7);
	Ler_String(nome_busca, MAX_NOME, "Digite o nome do produto: ");

	while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF)
	{
		if (strstr(produto.nome, nome_busca))
		{
			Console(5, 9);
			printf("PRODUTO ENCONTRADO: ");
			Console(5, 12);
			printf("ID: %d", produto.UID);
			Console(5, 13);
			printf("NOME: %s", produto.nome);
			Console(5, 14);
			printf("CATEGORIA: %s", produto.Grupo);
			Console(5, 15);
			printf("PRECO: R$ %.2f", produto.preco);
			Console(5, 16);
			printf("UNIDADE DE MEDIDA: %s", produto.Medida);
			Console(5, 17);
			printf("ESTOQUE: %d", produto.QNT_Estoque);
			Console(5, 18);
			printf("VALIDADE: %s", produto.Data_Validade);
			encontrado = 1;
		}

	}
	if (!encontrado)
	{
		Console(5, 2);
		printf("PRODUTO NAO ENCONTRADO ❗");
		Sleep(500);
		system("CLS");
		return EntradaMercadoria();

	}
	fclose(arquivo);
}


void ListarProduto() {
	Sleep(500);
	system("CLS");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\aERRO AO ABRIR O ARQUIVO❗\n");
		return;
	}

	Mercadoria produto;
	Console(5, 9);
	printf("Lista de produtos cadastrados: ");
	while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF)
	{
		Console(5, 12);
		printf("-----------------------------------------\nID: %d", produto.UID);
		Console(5, 13);
		printf("NOME: %s", produto.nome);
		Console(5, 14);
		printf("CATEGORIA: %s", produto.Grupo);
		Console(5, 15);
		printf("PRECO: R$ %.2f", produto.preco);
		Console(5, 16);
		printf("UNIDADE DE MEDIDA: %s", produto.Medida);
		Console(5, 17);
		printf("ESTOQUE: %d", produto.QNT_Estoque);
		Console(5, 18);
		printf("VALIDADE: %s\n-----------------------------------------", produto.Data_Validade);

	}
}