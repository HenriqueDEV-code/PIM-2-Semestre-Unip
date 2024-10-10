#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include "../include/Titulos.h"
#include "../include/Estruturas.h"
#include "../include/csv.h"

int main() {

	SetConsoleOutputCP(CP_UTF8);
	MenuPrincipalSistema();

	return 0;
}

int MenuPrincipalSistema(){
	int coluna, linha;
	int escolha;

	do {
		MenuDeGestao();
		escolha = 1;
		linha = 11;
		coluna = 8;
		CL(coluna, linha);
		printf("\033[34m➤\033[0m");
		while (1) {
			int tecla;
			setvbuf(stdin, NULL, _IONBF, 0); /* Limpa o buffer de entrada */

			tecla = _getch(); /* Funcao que recebe o valor do teclado precionado */


			if (tecla == ENTER) {
				switch(escolha) {
					case 1:
						Cadastro();
						break;
					case 2: 
						Vendas();
						break;
					case 3: 
						PesquisaPreco();
						break;
					case 4: 
						RelatoriosGerais();
						break;
					case 5: 
						QuemSomos();
						break;
					case 6: 
						Sujestao();
						break;
					case 0:
						return 0;
						break;			
				}
			};

			if (tecla == 72 || tecla == 80)
			{
				CL(coluna, linha);
				printf(" ");

				if (tecla == 72) escolha--;
				else if (tecla == 80)escolha++;

			}
			if (escolha < 0)escolha = 7;
			else if (escolha > 7) escolha = 0;

			if (escolha == 0) { coluna = 115; linha = 1; }
			else if (escolha == 1) { coluna = 8; linha = 11; }
			else if (escolha == 2) { coluna = 8; linha = 13; }
			else if (escolha == 3) { coluna = 8; linha = 15; }
			else if (escolha == 4) { coluna = 8; linha = 17; }
			else if (escolha == 5) { coluna = 8; linha = 19; }
			else if (escolha == 6) { coluna = 8; linha = 21; }
			else if (escolha == 7) { coluna = 8; linha = 23; }

			CL(coluna, linha);
			printf("\033[34m➤\033[0m");;
		}

	} while (1);


}

int Cadastro()
{
	Products mercadorias;
	Sleep(2);
	system("CLS");
	do
	{
		int coluna, linha;
		int escolha;
		MenuCadastroMercadorias();
		escolha = 1;
		linha = 4;
		coluna = 23;
		CL(coluna, linha);
		printf(" ");
		
		while (1)
		{
			int tecla;
			setvbuf(stdin, NULL, _IONBF, 0); /* Limpa o buffer de entrada */

			tecla = _getch(); /* Funcao que recebe o valor do teclado precionado */

			if (tecla == ENTER) {
				switch(escolha) {
					case 0: 
						MenuPrincipalSistema();
						break;
					case 1: 
						fgets(mercadorias.descProduct, sizeof(mercadorias.descProduct), stdin);
						break;
					case 2:
						fgets(mercadorias.GrupProduct,sizeof(mercadorias.GrupProduct), stdin);
						break;
					case 3:
						scanf_s("%d-%d-%d", &mercadorias.NEWdata.dia, &mercadorias.NEWdata.mes, &mercadorias.NEWdata.ano);
						break;
					case 4: 
						fgets(mercadorias.UNProductMedida, sizeof(mercadorias.UNProductMedida), stdin);
						break;
					case 5:
						scanf_s("%.2f", &mercadorias.PrecoProductCompra);
						break;
					case 6: 
						scanf_s("%.2f", &mercadorias.MargemProduct);
						break;
					case 7:
						scanf_s("%d", &mercadorias.EstoqueEnterProduct);
						break; 
				}
			}

			if (tecla == 72 || tecla == 80)
			{
				CL(coluna, linha);
				printf(" ");
				if (tecla == 72) escolha--;
				else if (tecla == 80) escolha++;
			}

			if (escolha < 0) escolha = 8;
			else if (escolha > 8) escolha = 0;

			if (escolha == 0) { coluna = 115; linha = 1; }
			else if (escolha == 1) { coluna = 23; linha = 4; }
			else if (escolha == 2) { coluna = 20; linha = 6; }
			else if (escolha == 3) { coluna = 31; linha = 8; }
			else if (escolha == 4) { coluna = 42; linha = 10; }
			else if (escolha == 5) { coluna = 29; linha = 12; }
			else if (escolha == 6) { coluna = 29; linha = 14; }
			else if (escolha == 7) { coluna = 34; linha = 16; }
			CL(coluna, linha);
			printf(" ");;
		}

	} while (1);
}
void Vendas(){}
void PesquisaPreco(){}
void RelatoriosGerais(){}
void QuemSomos(){}
void Sujestao(){}
