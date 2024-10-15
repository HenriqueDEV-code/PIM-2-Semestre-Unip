#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>
#include "../include/Titulos.h"
#include "../include/Estruturas.h"
#include "../include/csv.h"
#include "../include/validation.h"

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

			if (tecla == 72 || tecla == 80) {
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
			printf("\033[34m➤\033[0m");
		}

	} while (1);


}

int Cadastro() {
    Products mercadorias;
    Position posicoes[] = {
        {115, 1},  // escolha 0
        {23, 4},   // escolha 1
        {20, 6},   // escolha 2
        {31, 8},   // escolha 3
        {42, 10},  // escolha 4
        {29, 12},  // escolha 5
        {29, 14},  // escolha 6
        {34, 16},  // escolha 7
        {23, 18}   // escolha 8
    };
    
    Sleep(2);
    system("CLS");
    do {
        int coluna, linha;
        int escolha;
        MenuCadastroMercadorias();
        escolha = 1;
        linha = 4;
        coluna = 23;
        CL(coluna, linha);
        printf(" ");

        while (1) {
            int tecla;
            setvbuf(stdin, NULL, _IONBF, 0);

            tecla = _getch();

            if (tecla == ENTER) {
                switch(escolha) {
                    case 0: 
                        MenuPrincipalSistema();
                        break;
                    case 1: 
                        fgets(mercadorias.descProduct, sizeof(mercadorias.descProduct), stdin);
                        break;
                    case 2:
                        fgets(mercadorias.GroupProduct, sizeof(mercadorias.GroupProduct), stdin);
                        break;
                    case 3:
                        scanf_s("%d-%d-%d", &mercadorias.NEWdata.dia, &mercadorias.NEWdata.mes, &mercadorias.NEWdata.ano);
                        break;
                    case 4: 
                        fgets(mercadorias.UNProductMedida, sizeof(mercadorias.UNProductMedida), stdin);
                        break;
                    case 5:
                        scanf_s("%lf", &mercadorias.PrecoProductCompra);
                        break;
                    case 6: 
                        scanf_s("%lf", &mercadorias.MargemProduct);
                        break;
                    case 7:
                        scanf_s("%d", &mercadorias.EstoqueEnterProduct);
                        break;
                    case 8:
                        if (ValidateProductFields(&mercadorias)) {
                            SaveProductsToCSV(&mercadorias);
                            showNotification(L"Produto cadastrado com sucesso!", MB_ICONINFORMATION);
                        } else {
                            showNotification(L"Preencha todos os campos obrigatórios.", MB_ICONWARNING);
                        }
                        break;
                }
            }

            if (tecla == 72 || tecla == 80) {
                CL(coluna, linha);
                printf(" ");
                
                if (tecla == 72) {
                    escolha--;
                } else if (tecla == 80) {
                    escolha++;
                }
            }

            if (escolha < 0) {
                escolha = 8;
            } else if (escolha > 8) {
                escolha = 0;
            }

            coluna = posicoes[escolha].x; // Use o campo x da estrutura
            linha = posicoes[escolha].y;   // Use o campo y da estrutura

            CL(coluna, linha);
            printf("➤ ");
        }
    } while (1);
}

void Vendas(){}
void PesquisaPreco(){}
void RelatoriosGerais(){}
void QuemSomos(){}
void Sujestao(){}


int main() {
	SetConsoleOutputCP(CP_UTF8);
	MenuPrincipalSistema();
	return 0;
}