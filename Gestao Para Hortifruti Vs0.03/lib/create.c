#include <stdio.h>
#include "../include/product.h"

void CadastroProduto() {
	Sleep(500);
	system("CLS");
	
	int idDuplicado = 0;
	Mercadoria produto;
	borda(120, 5);
	borda(120, 30);
	Console(5, 8);
	Ler_Int(&produto.UID, "Digite o ID do produto: ");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\aERRO AO ABRIR O ARQUIVO❗\n");
		return EntradaMercadoria();
	}

	// Verifica se o ID já existe no arquivo
	Mercadoria temp;
	while (fscanf(arquivo, "%d;%*[^;];%*[^;];%*f;%*[^;];%*d;%*[^;]\n", &temp.UID) != EOF)
	{
		if (temp.UID == produto.UID) { // Compara o ID lido no arquivo com o ID inserido
			Console(5, 2);
			printf("ERRO: O ID %d JA EXISTE NO SISTEMA❗", produto.UID);
			idDuplicado = 1; // Marca como duplicado
			break; // Não precisa continuar verificando, já sabemos que o ID é duplicado
		}
	}

	fclose(arquivo); // Fecha o arquivo após a verificação

	if (idDuplicado == 1) {
		// Caso o ID seja duplicado, o processo não continua
		Console(5, 3);
		printf("CADASTRO ABORTADO DEVIDO A DUPLICIDADE DE ID.");
		Sleep(500);
		system("CLS");
		return EntradaMercadoria(); // Retorna para a entrada de mercadorias
	}
	else {
		// Segue com o fluxo do programa, pois o ID é único
		Console(5, 3);
		printf("ID %d CADASTRADO COM SUCESSO❗", produto.UID);

	}
	
	Console(5, 9);
	Ler_String(produto.nome, sizeof(produto.nome), "Digite o nome do produto: ");
	Console(5, 10);
	Ler_String(produto.Grupo, sizeof(produto.Grupo), "Digite a categoria do produto: ");
	Console(5, 11);
	Ler_Float(&produto.preco, "Digite o preço do produto: ");
	Console(5, 12);
	Ler_Unidade_Medida(&produto.Medida, sizeof(produto.Medida), "Digite a unidade de medida (UN, CX, KG): ");
	Console(5, 13);
	Ler_Int(&produto.QNT_Estoque, "Digite a quantidade em estoque: ");

	// Validação da data de validade
	do {
		Console(5, 14);
		Ler_String(produto.Data_Validade, sizeof(produto.Data_Validade), "Digite a data de validade (YYYY-MM-DD): ");
	} while (!Validade_Data(produto.Data_Validade));

	fprintf(arquivo, "\n%d;%s;%s;%.2f;%s;%d;%s", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
	fclose(arquivo);
	Console(5, 2);
	printf("Produto cadastrado com sucesso!\n");
	Sleep(1500);
	return EntradaMercadoria();
}