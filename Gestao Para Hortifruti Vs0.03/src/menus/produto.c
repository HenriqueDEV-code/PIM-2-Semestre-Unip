#include <stdio.h>
#include "../../include/menu.h"
#include "../../include/product.h"

void EntradaMercadoria() {
    int coluna, linha;
    int escolha;

	do {
		Sleep(2);
		system("CLS");
		borda(120, 30);
		borda(120, 5);
		borda(120, 11);
		Console(116, 1);
		printf("❌");
		Console(2, 1);

		printf("\033[33m▒█▀▀▀█ ▀█▀ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀▀ ▒█▀▄▀█ ░█▀▀█ 　 ▒█▀▀▄ ▒█▀▀▀ 　 ▒█▀▀█ ░█▀▀█ ▒█▀▀▄ ░█▀▀█ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀█ ▒█▀▀▀█"); Console(2, 2);
		printf("░▀▀▀▄▄ ▒█░ ░▀▀▀▄▄ ░▒█░░ ▒█▀▀▀ ▒█▒█▒█ ▒█▄▄█ 　 ▒█░▒█ ▒█▀▀▀ 　 ▒█░░░ ▒█▄▄█ ▒█░▒█ ▒█▄▄█ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄▀ ▒█░░▒█"); Console(2, 3);
		printf("▒█▄▄▄█ ▄█▄ ▒█▄▄▄█ ░▒█░░ ▒█▄▄▄ ▒█░░▒█ ▒█░▒█ 　 ▒█▄▄▀ ▒█▄▄▄ 　 ▒█▄▄█ ▒█░▒█ ▒█▄▄▀ ▒█░▒█ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█\033[0m");

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