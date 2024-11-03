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
                if (escolha == 4) break;
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



int FluxoDeCaixa()
{
     /*
      Front Do fluxo de caixa 
      funcao responsavel por fornecer um visual mais amigavel para o usuario *Funcionario-caixa* para que 
      consiga trabalhar da melhor forma possivel
    */
    int escolha, linha, coluna, tecla;
    Sleep(10);
    system("CLS");
    borda(120,30);
    borda(120,7);
    borda(33,30);
    borda(120,28);

    do{
        // primeiro do para mostrar as informacoes do front de caixa 
        Console(114,2);
        printf("❌");
        Console(3,2);
        printf("ＣＡＩＸＡ－ＶＥＮＤＡＳ");

        Console(3, 5);
        printf("C̲O̲D̲I̲G̲O̲: ");
        Console(40, 5);
        printf("Q̲U̲A̲N̲T̲I̲D̲A̲D̲E̲: ");
        Console(77, 5);
        printf("T̲O̲T̲A̲L̲ I̲T̲E̲M̲: ");
        Console(57,8);
        printf("H̲I̲S̲T̲O̲R̲I̲C̲O̲ D̲E̲ C̲O̲M̲P̲R̲A̲S̲");
        Console(18,28);
        printf("Usar -> " "\033[31m← →\033[0m" " para se guiar no menu. O" "\033[32m ENTER \033[0m" "para confirmar e o ❌ para sair ou retorna");
        escolha = 1;
        linha = 5;
        coluna = 17;
        Console(coluna, linha);
        printf(" ");


        while(1)
        {
            
            setvbuf(stdin, NULL, _IONBF,0);
            
            tecla = getch();

            if(tecla == ENTER)
            {
                if (escolha == 1) { /* Codigo para receber valores  #Codigo*/}
                if (escolha == 2) { /* Codigo para receber valores  #Quantidade*/}
                if (escolha == 3) { /* Codigo para receber valores  #Total Item*/}
                if (escolha == 0) { return MenuDeGestaoHortifrut(); }
            }

            if (tecla == 77 || tecla == 75)
            {
                Console(coluna, linha);
                printf(" ");

                if (tecla == 77) escolha++;
                else if (tecla == 75) escolha--;

                if (escolha < 0) escolha = 3;
                else if (escolha > 3) escolha = 0;
                 

                 if (escolha == 0) { coluna = 110; linha = 2; }
                 else if (escolha == 1) { coluna = 17; linha = 5; }
                 else if (escolha == 2) { coluna = 61; linha = 5; }
                 else if (escolha == 3) { coluna = 99; linha = 5; }
                 Console(coluna, linha);
                 printf(" ");
            }
        }
    }while(1);
} 

void RelatorioDeSistema()
{
   
    Sleep(10);
    system("CLS");
    borda(120,30);
    borda(120,28); 
   int tecla;
    do
    {
        
        Console(10,2);
        printf("▒█▀▀█ ▒█▀▀▀ ▒█░░░ ░█▀▀█ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀█ ▀█▀ ▒█▀▀▀█");
        Console(10,3);
        printf("▒█▄▄▀ ▒█▀▀▀ ▒█░░░ ▒█▄▄█ ░▒█░░ ▒█░░▒█ ▒█▄▄▀ ▒█░ ▒█░░▒█");
        Console(10,4);
        printf("▒█░▒█ ▒█▄▄▄ ▒█▄▄█ ▒█░▒█ ░▒█░░ ▒█▄▄▄█ ▒█░▒█ ▄█▄ ▒█▄▄▄█");

     scanf("%d", &tecla);
       

    } while (1); // fim do
    


}//fim funcao
 
 

