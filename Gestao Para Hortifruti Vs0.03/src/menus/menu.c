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
        Console(11, 13); printf("VENDAS 💳");
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
                if (escolha == 3) break;  /* Coloquei break ate criar a funcao */
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



void FluxoDeCaixa(void)
{
     /*
      Front Do fluxo de caixa  
    */
    
    int linha, coluna, tecla, escolha;

  do
  {
   
        Sleep(2);
        system("CLS");
        borda(120, 30);
        borda(120, 5);
        borda(120, 28);
        Console(116, 1);
        printf("❌");
        Console(10,1);
        printf("▒█▀▀▀ ▒█░░░ ▒█░▒█ ▀▄▒▄▀ ▒█▀▀▀█ 　 ▒█▀▀▄ ▒█▀▀▀ 　 ▒█▀▀█ ░█▀▀█ ▀█▀ ▀▄▒▄▀ ░█▀▀█");
        Console(10,2);
        printf("▒█▀▀▀ ▒█░░░ ▒█░▒█ ░▒█░░ ▒█░░▒█ 　 ▒█░▒█ ▒█▀▀▀ 　 ▒█░░░ ▒█▄▄█ ▒█░ ░▒█░░ ▒█▄▄█");
        Console(10,3);
        printf("▒█░░░ ▒█▄▄█ ░▀▄▄▀ ▄▀▒▀▄ ▒█▄▄▄█ 　 ▒█▄▄▀ ▒█▄▄▄ 　 ▒█▄▄█ ▒█░▒█ ▄█▄ ▄▀▒▀▄ ▒█░▒█");
        Console(12, 28);
        printf("Usar -> \033[31m↑ ↓\033[0m para se guiar no menu. O \033[32mENTER\033[0m para Acessar e digitar e o ❌ para sair ou retornar");


        Console(10,7);
        printf("CODIGO DA MERCADORIA: ");
        Console(10,9);
        printf("MERCADORIA: ");
        Console(10,11);
        printf("PRECO: ");
        Console(10,13);
        printf("QUANTIDADE: ");
       
      escolha = 1;
      linha = 7;
      coluna = 32;
      Console(coluna, linha);
      printf(" ");

      while (1)
      {
          setvbuf(stdin,NULL,_IONBF,0);

          tecla = getch();
          
          if(escolha == ENTER)
          {
           if(escolha == 1) break; /* Coloquei break ate criar a funcao */
           if (escolha == 2) break;
           if(escolha == 3) break;
           if(escolha == 4) break;
           if(escolha == 0) exit(0);
           break;
         }
          if(tecla == 72 || tecla == 80)
          {
            Console(coluna, linha);
            printf(" ");

            if(tecla == 72) escolha--;
            else if(tecla == 80) escolha++;


         }
         if(escolha < 0) escolha = 4;
         else if(escolha > 4) escolha = 0;

         if (escolha == 0) { coluna = 115; linha = 1; }
         else if (escolha == 1) { coluna = 32; linha = 7; }
         else if (escolha == 2) { coluna = 22; linha = 9; }
         else if (escolha == 3) { coluna = 17; linha = 11; }
         else if (escolha == 4) { coluna = 22; linha = 13; }
       }
    }while (1);
} 

 
 

