#include <stdio.h>
#include <windows.h>  // Para Sleep e system
#include <conio.h>    // Para getch
#include "../../include/menu.h"
#include "../../include/product.h"
#include "../../include/misc.h" 

typedef struct {
    int coluna;
    int linha;
} Posicao;

void ExibirMenu() {
    borda(120, 30);
    borda(120, 5);
    borda(120, 11);
    borda(120, 28);
    Console(116, 1);
    printf("❌");
    Console(2, 1);

    printf("\033[33m▒█▀▀▀█ ▀█▀ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀▀ ▒█▀▄▀█ ░█▀▀█ 　 ▒█▀▀▄ ▒█▀▀▀ 　 ▒█▀▀█ ░█▀▀█ ▒█▀▀▄ ░█▀▀█ ▒█▀▀▀█ ▀▀█▀▀ ▒█▀▀█ ▒█▀▀▀█"); Console(2, 2);
    printf("░▀▀▀▄▄ ▒█░ ░▀▀▀▄▄ ░▒█░░ ▒█▀▀▀ ▒█▒█▒█ ▒█▄▄█ 　 ▒█░▒█ ▒█▀▀▀ 　 ▒█░░░ ▒█▄▄█ ▒█░▒█ ▒█▄▄█ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄▀ ▒█░░▒█"); Console(2, 3);
    printf("▒█▄▄▄█ ▄█▄ ▒█▄▄▄█ ░▒█░░ ▒█▄▄▄ ▒█░░▒█ ▒█░▒█ 　 ▒█▄▄▀ ▒█▄▄▄ 　 ▒█▄▄█ ▒█░▒█ ▒█▄▄▀ ▒█░▒█ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█\033[0m");

    Console(12, 28);
    printf("Usar -> \033[31m↑ ↓\033[0m para se guiar no menu. O \033[32mENTER\033[0m para Acessar e o ❌ para sair ou retornar");

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
}

void ProcessarEscolha(int escolha) {
    switch (escolha) {
        case 1:
            CadastroProduto();
            break;
        case 2:
            EditeProduto();
            break;
        case 3:
            ExcluirProduto();
            break;
        case 4:
            BuscarProduto();
            break;
        case 5:
            ListarProduto();
            break;
        case 0:
            MenuDeGestaoHortifrut();
            break;
    }
}

// Função para atualizar a posição do cursor
void AtualizarCursor(int escolha, int *coluna, int *linha) {
    Posicao posicoes[] = {
        {115, 1},  // escolha 0
        {3, 12},   // escolha 1
        {3, 14},   // escolha 2
        {3, 16},   // escolha 3
        {3, 18},   // escolha 4
        {3, 20}    // escolha 5
    };

    if (escolha >= 0 && escolha < (int)(sizeof(posicoes) / sizeof(posicoes[0]))) {
        *coluna = posicoes[escolha].coluna;
        *linha = posicoes[escolha].linha;
    }
}

void EntradaMercadoria() {
    int coluna = 3, linha = 12;
    int escolha = 1;

    do {
        Sleep(2);
        system("CLS");
        ExibirMenu();

        Console(coluna, linha);
        printf("\033[34m➤\033[0m");

        while (1) {
            int tecla;
            setvbuf(stdin, NULL, _IONBF, 0); 
            tecla = getch();

            if (tecla == 13) {
                ProcessarEscolha(escolha);
                break;
            }

            if (tecla == 72 || tecla == 80) {
                Console(coluna, linha);
                printf(" ");

                if (tecla == 72) escolha--;
                else if (tecla == 80) escolha++;

                if (escolha < 0) escolha = 5;
                else if (escolha > 5) escolha = 0;

                AtualizarCursor(escolha, &coluna, &linha);
                Console(coluna, linha);
                printf("\033[34m➤\033[0m");
            }
        }
    } while (1);
}
