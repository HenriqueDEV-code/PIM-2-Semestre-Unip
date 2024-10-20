#include <stdio.h>
#include <windows.h>  
#include <conio.h>    
#include "../../include/menu.h"
#include "../../include/product.h"
#include "../../include/misc.h" 

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