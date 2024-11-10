#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "../../include/menu.h"
#include "../../include/product.h"
#include "../../include/misc.h"

int MenuDeGestaoHortifrut() {
    int coluna, linha, escolha;
    int posicoes[7][2] = {
        {115, 1}, {8, 11}, {8, 13}, {8, 15}, {8, 17}, {8, 19}, {8, 21}
    };

    do {
        Sleep(2);
        system("CLS");
        borda(120, 30);
        borda(120, 5);
        borda(120, 28);
        Console(116, 1);
        printf("❌");

        Console(10, 1);
        printf("\033[33m▒█▀▀█ ▒█▀▀▀ ▒█▀▀▀█ ▀▀█▀▀ ░█▀▀█ ▒█▀▀▀█ 　 ▒█░▒█ ▒█▀▀▀█ ▒█▀▀█ ▀▀█▀▀ ▀█▀ ▒█▀▀▀ ▒█▀▀█ ▒█░▒█ ▀▀█▀▀ ▀█▀");
        Console(10, 2);
        printf("▒█░▄▄ ▒█▀▀▀ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄█ ▒█░░▒█ 　 ▒█▀▀█ ▒█░░▒█ ▒█▄▄▀ ░▒█░░ ▒█░ ▒█▀▀▀ ▒█▄▄▀ ▒█░▒█ ░▒█░░ ▒█░");
        Console(10, 3);
        printf("▒█▄▄█ ▒█▄▄▄ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█ 　 ▒█░▒█ ▒█▄▄▄█ ▒█░▒█ ░▒█░░ ▄█▄ ▒█░░░ ▒█░▒█ ░▀▄▄▀ ░▒█░░ ▄█▄\033[0m");

        Console(11, 11); printf("\033[35mCADASTRO 💻");
        Console(11, 13); printf("FLUXO DE CAIXA 💳");
        Console(11, 15); printf("RELATORIO GERAL DO SISTEMA 📊");
        Console(11, 17); printf("QUEM SOMOS 📎");
        Console(11, 19); printf("SUGESTOES 🗣");
        Console(11, 21); printf("AREA DE DOACOES 🎁");

        Console(12, 28);
        printf("Usar -> \033[31m↑ ↓\033[0m para se guiar no menu. O \033[32mENTER\033[0m para Acessar e o ❌ para sair ou retornar");
        Console(43, 5);
        printf("\033[36m𝕮𝖔𝖓𝖓𝖊𝖈𝖙𝖎𝖔𝖓 𝖆𝖓𝖉 𝕾𝖔𝖑𝖚𝖙𝖎𝖔𝖓 ©");
        Console(105, 28);
        printf(" \033[36mVs 0.0.3\033[0m");

        escolha = 1;
        coluna = posicoes[escolha][0];
        linha = posicoes[escolha][1];
        Console(coluna, linha);
        printf("\033[34m➤\033[0m");

        while (1) {
            int tecla = getch();

            if (tecla == ENTER) {
                if (escolha == 1) EntradaMercadoria();
                if (escolha == 2) FluxoDeCaixa();
                if (escolha == 3) RelatorioDeSistema();  /* Coloquei break ate criar a funcao */
                if (escolha == 4) QUEMSOMOS();
                if (escolha == 5) break;
                if (escolha == 6) break;
                if (escolha == 0) exit(0);
                break;
            }
            if (tecla == 72 || tecla == 80) {
                Console(coluna, linha);
                printf(" ");

                if (tecla == 72) escolha--;
                else if (tecla == 80) escolha++;

                if (escolha < 0) escolha = 6;
                else if (escolha > 6) escolha = 0;

                coluna = posicoes[escolha][0];
                linha = posicoes[escolha][1];
                Console(coluna, linha);
                printf("\033[34m➤\033[0m");
            }
        }
    } while (1);
}

void RelatorioDeSistema() {
    int tecla;
   
    Sleep(10);
    system("CLS");
    borda(120,30);
    borda(120,28); 
    borda(120, 7);
    do {
        
        Console(35,2);
        printf("\033[33m▒█▀▀█ ▒█▀▀▀ ▒█░░░ ░█▀▀█ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀█ ▀█▀ ▒█▀▀▀█");
        Console(35,3);
        printf("▒█▄▄▀ ▒█▀▀▀ ▒█░░░ ▒█▄▄█ ░▒█░░ ▒█░░▒█ ▒█▄▄▀ ▒█░ ▒█░░▒█");
        Console(35,4);
        printf("▒█░▒█ ▒█▄▄▄ ▒█▄▄█ ▒█░▒█ ░▒█░░ ▒█▄▄▄█ ▒█░▒█ ▄█▄ ▒█▄▄▄█\033[0m");
        Console(44,28);
        printf("Clica no " "\033[34mESC\033[0m" " para sair do relatorio");
        



        setvbuf(stdin, NULL, _IONBF,0);
        tecla = getch();
    } while (tecla != 27); // fim do
    
   return MenuDeGestaoHortifrut();

}//fim funcao

void QUEMSOMOS(void)
{
    Sleep(10);
    system("CLS");
    borda(120,30);
    borda(120,28); 
    borda(120, 7);

    int tecla;
    do
    {
        
        Console(35,2);
        printf("\033[33m▒█▀▀█ ▒█░▒█ ▒█▀▀▀ ▒█▀▄▀█ 　 ▒█▀▀▀█ ▒█▀▀▀█ ▒█▀▄▀█ ▒█▀▀▀█ ▒█▀▀▀█ ");
        Console(35,3);
        printf("▒█░▒█ ▒█░▒█ ▒█▀▀▀ ▒█▒█▒█ 　 ░▀▀▀▄▄ ▒█░░▒█ ▒█▒█▒█ ▒█░░▒█ ░▀▀▀▄▄");
        Console(35,4);
        printf("░▀▀█▄ ░▀▄▄▀ ▒█▄▄▄ ▒█░░▒█ 　 ▒█▄▄▄█ ▒█▄▄▄█ ▒█░░▒█ ▒█▄▄▄█ ▒█▄▄▄█\033[0m");
        Console(44,28);
        printf("Clica no " "\033[34mESC\033[0m" " para sair do relatorio");

         Console(2,8);
         printf("Somos a " "\033[36mConnection and Solution\033[0m" ", uma empresa de tecnologia dedicada a transformar a gesta do setor hortifruti");
         Console(2,9);
         printf("com solucoes eficientes e sustentaveis. Nosso objetivo e simplificar a administracao com um sistema completo e facil de usar.");
         Console(2,10);
         printf("Nosso software oferece recursos essenciais como cadastramento de produtos, fluxo de caixa e relatorio de entrada e saida, ");
         Console(2,11);
         printf("tudo em uma interface intuitiva e amigavel para o colaborador. Tambem entendemos a importancia de reduzir o desperdicios e fortalecer");





         setvbuf(stdin, NULL, _IONBF,0);
         tecla = getch();
    } while (tecla != 27); // fim do

        
    return MenuDeGestaoHortifrut();
}