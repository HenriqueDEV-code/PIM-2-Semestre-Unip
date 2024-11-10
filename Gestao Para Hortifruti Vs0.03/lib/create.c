#include <stdio.h>
#include <windows.h>
#include "../include/product.h"
#include "../include/vendas.h"
#include "../include/menu.h"
#include "../include/misc.h"

void CadastroProduto()
{
    Sleep(500);
    system("CLS");
 
    int idDuplicado = 0, tecla;
    Mercadoria produto;
    FILE *arquivo;


   // front
    ExibirBordas();
    Console(44,28);
    printf("Clica no " "\033[34mESC\033[0m" " para sair do relatorio");
    // ------------------------------//
   setvbuf(stdin, NULL, _IONBF,0);
    tecla = getch();
    if(tecla == 27) {return ExibirMenu();}


    Console(5, 8);
    Ler_Int(&produto.UID, "Digite o ID do produto: ");

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "r")) != NULL)
    {
        if (VerificarIdDuplicado(arquivo, produto.UID))
        {
            showNotification(L"Produto com Id Duplicado", MB_ICONERROR);
            fclose(arquivo);
            EntradaMercadoria();
            return;
        }
        fclose(arquivo);
    }

    Console(5, 3);

    ColetarDadosProduto(&produto);

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "a")) != NULL)
    {
        SalvarProduto(arquivo, &produto);
        fclose(arquivo);
        Console(5, 2);
        printf("Produto cadastrado com sucesso!\n");
        Sleep(1500);
    }
    else
    {
        showNotification(L"Erro no arquivo", MB_ICONEXCLAMATION);
    }

    EntradaMercadoria();
}

void ExibirBordas()
{
    borda(120, 5);
    borda(120, 30);
}

int VerificarIdDuplicado(FILE *arquivo, int id)
{
    char row[MAXCHAR];
    char* token;
    Mercadoria produto;

    while (fgets(row, MAXCHAR, arquivo) != NULL) {
        // Remover nova linha do final da string, se existir
        row[strcspn(row, "\n")] = 0;

        token = strtok(row, ";");
        produto.UID = atoi(token);

        if (produto.UID == id) {
            return 1;
        }
    }
    
    return 0;
}

void ColetarDadosProduto(Mercadoria *produto)
{
    Console(5, 9);
    Ler_String(produto->nome, sizeof(produto->nome), "Digite o nome do produto: ");
    Console(5, 10);
    Ler_String(produto->Grupo, sizeof(produto->Grupo), "Digite a categoria do produto: ");
    Console(5, 11);
    Ler_Float(&produto->preco, "Digite o preço do produto: ");
    Console(5, 12);
    Ler_Unidade_Medida(produto->Medida, sizeof(produto->Medida), "Digite a unidade de medida (UN, CX, KG): ");
    Console(5, 13);
    Ler_Int(&produto->QNT_Estoque, "Digite a quantidade em estoque: ");

    do
    {
        Console(5, 14);
        Ler_String(produto->Data_Validade, sizeof(produto->Data_Validade), "Digite a data de validade (YYYY-MM-DD): ");
    } while (!Validade_Data(produto->Data_Validade));
}

void SalvarProduto(FILE *arquivo, Mercadoria *produto)
{
    // Verifica se o arquivo está vazio
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    if (tamanho == 0) {
        // Se o arquivo estiver vazio, não adiciona nova linha
        fprintf(arquivo, "%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    } else {
        // Se o arquivo não estiver vazio, adiciona nova linha antes do produto
        fprintf(arquivo, "\n%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    }
}

void fluxoDeVendas() {
   int escolha, linha, coluna, tecla;
    sales vendas;
    vendas.total = 0;
Sleep(10);
system("CLS");
borda(120, 30);
borda(120, 5);
borda(120, 25);
borda(120, 28);



borda(30, 25);
borda(100, 25);
do
{
	Console(2, 1);
	printf("\033[33m▒█▀▀█ ░█▀▀█ ▀█▀ ▀▄▒▄▀ ░█▀▀█");
	Console(2, 2);
	printf("▒█░░░ ▒█▄▄█ ▒█░ ░▒█░░ ▒█▄▄█");
	Console(2, 3);
	printf("▒█▄▄█ ▒█░▒█ ▄█▄ ▄▀▒▀▄ ▒█░▒█\033[0m");
	Console(18, 28);
	printf("Usar -> \033[31m← →\033[0m para se guiar no menu. O \033[32mENTER\033[0m para confirmar e o " "\033[34mESC\033[0m" " para sair ou retornar");

	// menu superior

	Console(30, 3);
	printf("\033[36mITEM\033[0m");
	Console(38, 3);
	printf("\033[36mDESCRICAO\033[0m");
	Console(59, 3);
	printf("\033[36mQUANTIDADE\033[0m");
	Console(72, 3);
	printf("\033[36mTIPO\033[0m");
	Console(79, 3);
	printf("\033[36mVALOR\033[0m");
	Console(88, 3);
	printf("\033[36mTOTAL\033[0m");
	Console(100, 3);
	printf("\033[33mSUB TOTAL: \033[0m");

	// menu inferior

	Console(2, 26);
	printf("\033[35mID: \033[0m");
	Console(11, 26);
	printf("\033[35mQUANTIDADE: \033[0m");

	escolha = 1;
	linha = 26;
	coluna = 6;
	Console(coluna, linha);
	printf(" ");



	while(1)
	{
		setvbuf(stdin, NULL, _IONBF, 0);
		tecla = _getch();

		if (tecla == 13)
		{
			if(escolha == 1) { /* ID */ }
			if(escolha == 2) { /* QUANTIDADE */ }
			
		}
		else if (tecla == 27) // tecla ESC para retornar ao fluxo de caixa
		{
			return FluxoDeCaixa();
		}

		if (tecla == 77 || tecla == 75)
		{
			Console(coluna, linha);
			printf(" ");

			if (tecla == 77) escolha--;
			else if (tecla == 75) escolha++;

			if (escolha < 1) escolha = 2;
			else if (escolha > 2) escolha = 1;

			if (escolha == 1) { coluna = 6; linha = 26; }
			else if(escolha == 2) { coluna = 23; linha = 26; }
			Console(coluna, linha);
			printf(" ");
		}
	}
	
} while (1);

}
