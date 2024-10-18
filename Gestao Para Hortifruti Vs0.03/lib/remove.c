void ExcluirProduto()
{
	Sleep(500);
	system("CLS");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\aERRO AO ABRIR O ARQUIVO❗\n");
		return;
	}
	FILE* temp = fopen("temp.csv", "w");
	if (temp == NULL) {
		Console(36, 2);
		printf("ERRO AO CRIAR ARQUIVO TEMPORARIO❗\n");
		fclose(arquivo);
		return;
	}

	Mercadoria produto;

	int id_produto = NULL, encontrado = 0;

	Console(5, 7);
	Ler_Int(&produto.UID, "Digite o ID do produto que deseja excluir do estoque: ");
	while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF)
	{
		if (id_produto == produto.UID)
		{
			encontrado = 1;
			Console(5, 2);
			printf("PRODUTO EXCLUIDO COM SUCESSO❗");
			Sleep(500);
			system("CLS");
			return EntradaMercadoria();
		}
		else {
			fprintf(temp, "%d%s%s%.2f%s%d%s\n", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
		}
	}
	fclose(arquivo);
	fclose(temp);
	remove(ARQUIVO_ESTOQUE);
	rename("temp.csv", ARQUIVO_ESTOQUE);
	if (!encontrado)
	{
		Console(5, 2);
		printf("PRODUTO NAO ENCONTRADO ❗");
		Sleep(500);
		system("CLS");
		return EntradaMercadoria();

	}

}