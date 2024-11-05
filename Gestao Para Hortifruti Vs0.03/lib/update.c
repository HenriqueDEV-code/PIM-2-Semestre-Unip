#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../include/product.h"

void EditeProduto() {
	Sleep(500);
	system("CLS");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\a\033[31mERRO AO ABRIR O ARQUIVO❗\033[0m\n");
		return;
	}

	FILE* temp = fopen("temp.csv", "w");
	if (temp == NULL) {
		Console(36, 2);
		printf("\033[31mERRO AO CRIAR ARQUIVO TEMPORARIO❗\033[0m\n");
		fclose(arquivo);
		return;
	}

	Mercadoria produto;
	int id_produto = NULL, encontrado = 0;
	Console(5, 7);
	Ler_Int(&id_produto, "Digite o ID do produto que deseja editar: ");

	while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF)
	{
		if (produto.UID == id_produto) {
			encontrado = 1;
			Console(5, 2);
			printf("Produto encontrado! Atualize os dados:\n");
			Console(5, 8);
			Ler_String(produto.nome, sizeof(produto.nome), "Novo nome: ");
			Console(5, 9);
			Ler_String(produto.Grupo, sizeof(produto.Grupo), "Nova categoria: ");
			Console(5, 10);
			Ler_Float(&produto.preco, "Novo preço: ");
			Console(5, 11);
			Ler_Int(&produto.QNT_Estoque, "Nova quantidade em estoque: ");

			// Validação da nova data de validade
			do {
				Console(5, 12);
				Ler_String(produto.Data_Validade, sizeof(produto.Data_Validade), "Nova data de validade (YYYY-MM-DD): ");
			} while (!Validade_Data(produto.Data_Validade));
		}
		fprintf(temp, "\n%d;%s;%s;%.2f;%s;%d;%s", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
	}

	fclose(arquivo);
	fclose(temp);

	remove(ARQUIVO_ESTOQUE);
	rename("temp.csv", ARQUIVO_ESTOQUE);

	if (encontrado) {
		Console(5, 2);
		printf("\033[32mProduto editado com sucesso!\033[0m\n");
	}
	else {
		Console(5, 2);
		printf("\033[31mProduto nao encontrado!\033[0m\n");
	}
	Sleep(1500);
	EntradaMercadoria();
}