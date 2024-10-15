/*
* Arquivo criado responsavel para manter os scripts
* de estruturas e funcoes
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

#define MAX_NOME 101
#define ARQUIVO_ESTOQUE "produtos.csv"

/* Definicao da estrutura de cadastro de mercadoria */

typedef struct
{
	int UID;
	char nome[101];
	char Grupo[51];
	float preco;
	char Medida[4];
	int QNT_Estoque;
	char Data_Validade[11];  // Formato: YYYY-MM-DD
}Mercadoria;









int Console(int x, int y);
void borda(int largura, int altura);
void Limpar_Buffer();
int Validade_Data(const char* data);
void Ler_Int(int* valor, const char* mensagem);
void Ler_Float(float* valor, const char* mensagem);
void Ler_String(char* str, int max_tamanho, const char* mensagem);
void Ler_Unidade_Medida(char* medida, int max_tamanho, const char* mensagem);
void EntradaMercadoria();
int MenuDeGestaoHortifrut();
void CadastroProduto();
void EditeProduto();
void ExcluirProduto();
void BuscarProduto();
void ListarProduto();


int MenuDeGestaoHortifrut();
/*
 A funcao Console tem como responsabilidade manipular aonde sera exibido a
 informação no console do programa.
   +-----------------+
   |    Exemplo      |
   +-----------------+
*/
int Console(int x, int y)
{
	SetConsoleOutputCP(CP_UTF8);

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* Criei essa funcao para desenhar um limite de Console usando + - |
* Entrando com dois parametros largura e altura Ex.: 120, 30 que é o
* tamanho do console quando inicia
*/
void borda(int largura, int altura)
{

	/* Desenha o limite da area total do console
	*  Linha superior +----------+
	*/
	Console(0, 0);
	printf("\033[32m+\033[0m");
	for (int i = 0; i < largura - 2; i++)
	{
		printf("\033[32m-\033[0m");
	}
	printf("\033[32m+\033[0m");


	/* Colunas direita e esquerda
	*  +---------------------+
	*  |                     |
	*  +---------------------+
	*/

	for (int i = 1; i < altura - 1; i++)
	{
		Console(0, i);
		printf("\033[32m|\033[0m");
		Console(largura - 1, i);
		printf("\033[32m|\033[0m");
	}

	/* Linha superior +----------+ */
	Console(0, altura - 1);
	printf("\033[32m+\033[0m");
	for (int i = 0; i < largura - 2; i++)
	{
		printf("\033[32m-\033[0m");
	}
	printf("\033[32m+\033[0m");

}


/* Funcao para limpar o buffer da entrada de dados */
void Limpar_Buffer()
{
	int c = 0;
	while ((c = getchar() != '\n' && c != EOF));
}


/* Funcao para validar a data em formato em YYYY-MM-DD */
int Validade_Data(const char* data)
{
	if (strlen(data) != 10 || data[4] != '-' || data[7] != '-') return 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7) continue;
		if (!isdigit(data[i])) return 0;
	}
	return 1;
}

/* Funcao para ler entrada do tipo inteiro com validação */
void Ler_Int(int* valor, const char* mensagem)
{
	printf("%s", mensagem);
	while (scanf("%d", valor) != 1 || *valor < 0)
	{

		Console(5, 2);
		printf("\aENTRADA INVALIDA❗ TENTE NOVAMENTE.");
		Limpar_Buffer();
		Sleep(500);
		system("CLS");
		return EntradaMercadoria();
	}
	Limpar_Buffer();
}

/* Funcao para ler entrada do tipo float com validação */
void Ler_Float(float* valor, const char* mensagem)
{
	printf("%s", mensagem);
	while (scanf("%f", valor) != 1 || *valor < 0)
	{
		Console(5, 2);
		printf("\aENTRADA INVALIDA❗ TENTE NOVAMENTE.");
		Limpar_Buffer();
		Sleep(500);
		system("CLS");
		return EntradaMercadoria();
	}
	Limpar_Buffer();
}

void Ler_String(char* str, int max_tamanho, const char* mensagem)
{
	printf("%s", mensagem);
	fgets(str, max_tamanho, stdin);
	str[strcspn(str, "\n")] = 0; // Remove o '\n' da string
}

void Ler_Unidade_Medida(char* medida, int max_tamanho, const char* mensagem)
{
	int valido = 0;

	while (!valido)
	{
		printf("%s", mensagem);
		fgets(medida, max_tamanho, stdin); // le ate 3 caracteres + '\0'
		medida[strcspn(medida, "\n")] = 0; // Remove o '\n'

		/* Verifica se a entrada e uma das tres opcoes sao validas */
		if (strcmp(medida, "UN") == 0 || strcmp(medida, "CX") == 0 || strcmp(medida, "KG") == 0)
		{
			valido = 1; // entrada valida
		}
		else
		{
			Console(5, 2);
			printf("\aENTRADA INVALIDA❗ POR FAVOR, INSIRA UN, CX OU KG.");
			Sleep(500);
			system("CLS");
			return EntradaMercadoria();
		}
	}
}



int MenuDeGestaoHortifrut()
{

	do
	{
		Sleep(2);
		system("CLS");
		borda(120, 30);
		borda(120, 5);
		borda(120, 28);
		Console(116, 1);
		printf("❌");
		/*=======================================================LOGO-MENU======================================================*/
		Console(10, 1);
		printf("\033[33m▒█▀▀█ ▒█▀▀▀ ▒█▀▀▀█ ▀▀█▀▀ ░█▀▀█ ▒█▀▀▀█ 　 ▒█░▒█ ▒█▀▀▀█ ▒█▀▀█ ▀▀█▀▀ ▀█▀ ▒█▀▀▀ ▒█▀▀█ ▒█░▒█ ▀▀█▀▀ ▀█▀"); Console(10, 2);
		printf("▒█░▄▄ ▒█▀▀▀ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄█ ▒█░░▒█ 　 ▒█▀▀█ ▒█░░▒█ ▒█▄▄▀ ░▒█░░ ▒█░ ▒█▀▀▀ ▒█▄▄▀ ▒█░▒█ ░▒█░░ ▒█░"); Console(10, 3);
		printf("▒█▄▄█ ▒█▄▄▄ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█ 　 ▒█░▒█ ▒█▄▄▄█ ▒█░▒█ ░▒█░░ ▄█▄ ▒█░░░ ▒█░▒█ ░▀▄▄▀ ░▒█░░ ▄█▄\033[0m");
		/*=====================================================================================================================*/


		/*===========================================================================================================================*/
		Console(11, 11); printf("\033[35mCADASTRO 💻");
		Console(11, 13); printf("VENDAS 💳");
		Console(11, 17); printf("QUEM SOMOS 📎");
		Console(11, 19); printf("SUGESTOES 🗣");
		Console(11, 21); printf("AREA DE DOACOES 🎁");
		Console(11, 15); printf("RELATORIO GERAL DO SISTEMA 📊\033[0m");
		/*===========================================================================================================================*/
		Console(12, 28);
		printf("Usar -> " "\033[31m↑ ↓\033[0m" " para se guiar no menu. O" "\033[32m ENTER \033[0m" "para confirmar e o ❌ para sair ou retorna");
		Console(43, 5);
		printf("\033[36m𝕮𝖔𝖓𝖓𝖊𝖈𝖙𝖎𝖔𝖓 𝖆𝖓𝖉 𝕾𝖔𝖑𝖚𝖙𝖎𝖔𝖓 ©");
		Console(105, 28);
		printf(" \033[36m Vs 0.0.3\033[0m");

		int coluna, linha;
		int escolha;
		escolha = 1;
		linha = 11;
		coluna = 8;
		Console(coluna, linha);
		printf("\033[34m➤\033[0m");

		/*===========================================================================================================================*/

		while (1)
		{
			int tecla;
			setvbuf(stdin, NULL, _IONBF, 0); /* Limpa o buffer de entrada */

			tecla = getch(); /* Funcao que recebe o valor do teclado precionado */


			if (tecla == 13) // 13 é a tecla enter do teclado
			{
				if (escolha == 1) EntradaMercadoria();;
				if (escolha == 2);
				if (escolha == 3);
				if (escolha == 4);
				if (escolha == 5);
				if (escolha == 6);
				if (escolha == 0) exit(0);
				break;
			}
			if (tecla == 72 || tecla == 80)
			{
				Console(coluna, linha);
				printf(" ");

				if (tecla == 72) escolha--;
				else if (tecla == 80)escolha++;

			}
			if (escolha < 0)escolha = 6;
			else if (escolha > 6) escolha = 0;

			if (escolha == 0) { coluna = 115; linha = 1; }
			else if (escolha == 1) { coluna = 8; linha = 11; }
			else if (escolha == 2) { coluna = 8; linha = 13; }
			else if (escolha == 3) { coluna = 8; linha = 15; }
			else if (escolha == 4) { coluna = 8; linha = 17; }
			else if (escolha == 5) { coluna = 8; linha = 19; }
			else if (escolha == 6) { coluna = 8; linha = 21; }

			Console(coluna, linha);
			printf("\033[34m➤\033[0m");;
		}
	} while (1);
}



void EntradaMercadoria()
{
	do
	{
		int coluna, linha;
		int escolha;
		Sleep(2);
		system("CLS");
		borda(120, 30);
		borda(120, 5);
		borda(120, 11);
		Console(116, 1);
		printf("❌");
		/*=======================================================LOGO-CADASTRO======================================================*/
		Console(2, 1);
		printf("\033[33m▒█▀▀▀█ ▀█▀ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀▀ ▒█▀▄▀█ ░█▀▀█ 　 ▒█▀▀▄ ▒█▀▀▀ 　 ▒█▀▀█ ░█▀▀█ ▒█▀▀▄ ░█▀▀█ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀█ ▒█▀▀▀█"); Console(2, 2);
		printf("░▀▀▀▄▄ ▒█░ ░▀▀▀▄▄ ░▒█░░ ▒█▀▀▀ ▒█▒█▒█ ▒█▄▄█ 　 ▒█░▒█ ▒█▀▀▀ 　 ▒█░░░ ▒█▄▄█ ▒█░▒█ ▒█▄▄█ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄▀ ▒█░░▒█"); Console(2, 3);
		printf("▒█▄▄▄█ ▄█▄ ▒█▄▄▄█ ░▒█░░ ▒█▄▄▄ ▒█░░▒█ ▒█░▒█ 　 ▒█▄▄▀ ▒█▄▄▄ 　 ▒█▄▄█ ▒█░▒█ ▒█▄▄▀ ▒█░▒█ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█\033[0m");
		/*=====================================================================================================================*/

		Console(5, 12);
		printf("CADASTRAR PRODUTO");
		Console(5, 14);
		printf("EDITAR INFORMAÇOES DO PRODUTO");
		Console(5, 16);
		printf("DELETAR O PRODUTO DO ESTOQUE");
		Console(5, 18);
		printf("BUSCAR PRODUTO NO ESTOQUE");
		Console(5, 20);
		printf("LISTAR TODOS PRODUTOS");

		escolha = 1;
		linha = 12;
		coluna = 3;

		Console(coluna, linha);
		printf("\033[34m➤\033[0m");

		while (1)
		{
			int tecla;
			setvbuf(stdin, NULL, _IONBF, 0); /* Limpa o buffer da entrada */

			tecla = getch(); /* recebe a informacao do teclado para saber o que foi precionado */

			if (tecla == 13)
			{
				if (escolha == 1)
				{
					CadastroProduto();
				}
				/*===============================================================================================================================================================*/
				if (escolha == 2)
				{
					EditeProduto();
				}
				if (escolha == 3)
				{
					ExcluirProduto();
				}
				if (escolha == 4)
				{
					BuscarProduto();
				}
				if (escolha == 5)
				{
					ListarProduto();
				}
				if (escolha == 0)
				{
					return MenuDeGestaoHortifrut();
				}
			}
			if (tecla == 72 || tecla == 80)
			{
				Console(coluna, linha);
				printf(" ");

				if (tecla == 72) escolha--;
				else if (tecla == 80)escolha++;
			}
			if (escolha < 0)escolha = 5;
			else if (escolha > 5) escolha = 0;

			if (escolha == 0) { coluna = 115; linha = 1; }
			else if (escolha == 1) { coluna = 3; linha = 12; }
			else if (escolha == 2) { coluna = 3; linha = 14; }
			else if (escolha == 3) { coluna = 3; linha = 16; }
			else if (escolha == 4) { coluna = 3; linha = 18; }
			else if (escolha == 5) { coluna = 3; linha = 20; }
			Console(coluna, linha);
			printf("\033[34m➤\033[0m");;
		}
	} while (1);
}



void CadastroProduto()
{
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

void EditeProduto()
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
		printf("Produto editado com sucesso!\n");
	}
	else {
		Console(5, 2);
		printf("Produto nao encontrado!\n");
	}
	Sleep(1500);
	return EntradaMercadoria();
}

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

void BuscarProduto()
{
	Sleep(500);
	system("CLS");
	FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
	if (arquivo == NULL) {
		Console(5, 2);
		printf("\aERRO AO ABRIR O ARQUIVO❗\n");
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


void ListarProduto()
{
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