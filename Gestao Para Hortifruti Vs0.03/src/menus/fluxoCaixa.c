#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../../include/menu.h"
#include "../../include/misc.h"

void FluxoDeCaixa() {
    int linha, coluna, tecla, escolha;

    do
    {
        Sleep(2);
        system("CLS");
        borda(120, 30);
        borda(120, 5);
        borda(120, 28);
        Console(10, 1);
        printf("\033[33m▒█▀▀▀ ▒█░░░ ▒█░▒█ ▀▄▒▄▀ ▒█▀▀▀█ 　 ▒█▀▀▄ ▒█▀▀▀ 　 ▒█▀▀█ ░█▀▀█ ▀█▀ ▀▄▒▄▀ ░█▀▀█");
        Console(10, 2);
        printf("▒█▀▀▀ ▒█░░░ ▒█░▒█ ░▒█░░ ▒█░░▒█ 　 ▒█░▒█ ▒█▀▀▀ 　 ▒█░░░ ▒█▄▄█ ▒█░ ░▒█░░ ▒█▄▄█");
        Console(10, 3);
        printf("▒█░░░ ▒█▄▄█ ░▀▄▄▀ ▄▀▒▀▄ ▒█▄▄▄█ 　 ▒█▄▄▀ ▒█▄▄▄ 　 ▒█▄▄█ ▒█░▒█ ▄█▄ ▄▀▒▀▄ ▒█░▒█\033[0m");
        Console(12, 28);
        printf("Usar -> \033[31m↑ ↓\033[0m para se guiar no menu. O \033[32mENTER\033[0m para Acessar e digitar e o " "\033[34mESC\033[0m" " para sair do relatorio");

        Console(10, 7);
        printf("\033[35m1. VENDA\033[0m");
        Console(10, 9);
        printf("\033[35m2. CANCELAR UMA VENDA\033[0m");
        Console(10, 11);
        printf("\033[35m3. LISTA DE VENDAS\033[0m");

        escolha = 1;
        linha = 7;
        coluna = 8;
        Console(coluna, linha);
        printf("➤");
        
            setvbuf(stdin, NULL, _IONBF,0);
            tecla = getch();

        do
        {
            setvbuf(stdin, NULL, _IONBF, 0);

            tecla = getch();

            if (tecla == 13) {
                switch (escolha) {
                    case 1:
                        // Função para processar a venda
                        fluxoDeVendas();
                        break;
                    case 2:
                        // Função para cancelar uma venda
                        cancelVendas();
                        break;
                    case 3:
                        // Função para listar vendas
                        printf("Listando Vendas...\n");
                        break;
                    case 0:
                        // Função para sair ou retornar ao menu anterior
                        printf("Saindo...\n");
                        break;
                }
            }

            if (tecla == 72 || tecla == 80) // Up or Down arrow keys
            {
                Console(coluna, linha);
                printf(" ");

                if (tecla == 72)
                    escolha--;
                else if (tecla == 80)
                    escolha++;
            }
            if (escolha < 1)
                escolha = 3;
            else if (escolha > 3)
                escolha = 1;

            if (escolha == 1)
            {
                coluna = 8;
                linha = 7;
            }
            else if (escolha == 2)
            {
                coluna = 8;
                linha = 9;
            }
            else if (escolha == 3)
            {
                coluna = 8;
                linha = 11;
            }

            Console(coluna, linha);
            printf("➤");

           
        }while(tecla != 27);

      return MenuDeGestaoHortifrut();
      
    } while (1);
    
}


void cancelVendas()
{
   int tecla;
int uid; // trocar a variavel para a variavel correta, o id venda

Sleep(10);
system("CLS");
borda(120, 30);
borda(120, 5);
borda(120, 25);
borda(120, 28);
borda(28, 28);


do
{
	Console(30, 1);
	printf("\033[31m░█▀▀█ ─█▀▀█ ░█▄─░█ ░█▀▀█ ░█▀▀▀ ░█─── ─█▀▀█ ░█▀▄▀█ ░█▀▀▀ ░█▄─░█ ▀▀█▀▀ ░█▀▀▀█");
	Console(30, 2);
	printf("░█─── ░█▄▄█ ░█░█░█ ░█─── ░█▀▀▀ ░█─── ░█▄▄█ ░█░█░█ ░█▀▀▀ ░█░█░█ ─░█── ░█──░█ ");
	Console(30, 3);
	printf("░█▄▄█ ░█─░█ ░█──▀█ ░█▄▄█ ░█▄▄▄ ░█▄▄█ ░█─░█ ░█──░█ ░█▄▄▄ ░█──▀█ ─░█── ░█▄▄▄█\033[0m");
	Console(15, 28);
	printf("Clica no " "\033[34mESC\033[0m" " para sair do Cancelamento da venda. O \033[32mENTER\033[0m para Confirmar o cancelamento");


	Console(2, 26);
	printf("\033[35mID: \033[0m");


	setvbuf(stdin, NULL, _IONBF, 0);
	tecla = _getch();
	if (tecla == 13) {
		Console(6, 26);
		scanf_s("%d", &uid);
	}
} while (tecla != 27);

return FluxoDeCaixa();
}





void listVendas()
{

}