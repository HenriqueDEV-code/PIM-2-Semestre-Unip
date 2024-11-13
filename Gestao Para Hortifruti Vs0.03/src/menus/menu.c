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
        printf("Clica no " "\033[34mESC\033[0m" " para sair QUEM SOMOS");

         Console(2,10);
         printf("Somos a " "\033[36mConnection and Solution ©\033[0m" ", uma empresa de tecnologia dedicada a transformar a gesta do setor hortifruti");
         Console(2,11);
         printf("com solucoes eficientes e sustentaveis. Nosso objetivo e simplificar a administracao com um sistema completo e facil");
         Console(2,12);
         printf("de usar.");
         Console(2,14);
         printf("Nosso software oferece recursos essenciais como cadastramento de produtos, vendas e relatorio, tudo em uma interface");
         Console(2,15);
         printf("intuitiva e amigavel para o colaborador. Tambem entendemos a importancia de reduzir o desperdicio e fortalecer a");
         Console(2,16);
         printf("responsabilidade social. Por isso, incluimos uma funcionalidade especifica para doacoes, facilitando a distribuicao");
         Console(2,17);
         printf("de produtos excelentes para quem mais precisa.");
         Console(2,19);
         printf("Combinamos tecnologia e proposito para ajudar nossos clientes a manter suas operacoes organizadas e eficientes,");
         Console(2,20);
         printf("ao mesmo tempo que criam impacto positivo na comunidade. Nossa equipe esta comprometidaem entregar ferramentas");
         Console(2,21);
         printf("praticas, com suporte dedicado, garantindo uma gestao eficiente e produtos sempre frescos e de qualidade.");


         





         setvbuf(stdin, NULL, _IONBF,0);
         tecla = getch();
    } while (tecla != 27); // fim do

        
    return MenuDeGestaoHortifrut();
}


void Sugestao(void)
{
	
	int tecla;
	int satisfacao1a5;
	char pergunta1[101];
	char pergunta2[101];
	char pergunta3[101];
	char pergunta4[101];
	Sleep(10);
	system("CLS");
	borda(120, 30);
	borda(120, 8);
	borda(120, 28);
	
	do
	{
		Console(30, 1);
		printf("\033[33m███████╗███████╗███████╗██████╗░██████╗░░█████╗░░█████╗░██╗░░██╗");
		Console(30, 2);
		printf("██╔════╝██╔════╝██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║░██╔");
		Console(30, 3);
		printf("█████╗░░█████╗░░█████╗░░██║░░██║██████╦╝███████║██║░░╚═╝█████═╝");
		Console(30, 4);
		printf("██╔══╝░░██╔══╝░░██╔══╝░░██║░░██║██╔══██╗██╔══██║██║░░██╗██╔═██╗");
		Console(30, 5);
		printf("██║░░░░░███████╗███████╗██████╔╝██████╦╝██║░░██║╚█████╔╝██║░╚██");
		Console(30, 6);
		printf("╚═╝░░░░░╚══════╝╚══════╝╚═════╝░╚═════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝\033[0m");
		Console(40, 28);
		printf("Clica no " "\033[34mESC\033[0m" " para sair da aba FeedBack.");
		Console(5, 9);
		printf("Ola! tudo bem?");
		Console(5, 10);
		printf("Somos a \033[36mConnection and Solution ©\033[0m e gostariamos de compartilhar o feedback sobre a ultima sessao e saber");
		Console(5, 11);
		printf("mum pouco sobre sua experiencia com o sistema. Para isso, gostariamos de pergunta:");
		Console(5, 13);
		printf("\033[33m(Por favor, utilize uma escala de 1 a 5, onde \033[31m1\033[33m representa \"muito insatisfeito\" e \033[32m5 \033[33mrepresenta \"satisfeito\")");
		Console(5, 14);
		printf("\033[33mQUAL O SEU NIVEL DE SATISFACAO COM O SISTEMA? : \033[0m");
		scanf_s("%d", &satisfacao1a5);
		setvbuf(stdin, NULL, _IONBF, 0);
		Console(5, 16);
		printf("Alem disso, para nos ajudar a aprimorar o sistema, pedimos que voce compartilhe algumas observacoes:");
		Console(5, 18);
		printf("1. \033[36mQuais aspectos voce mais gostou? \033[0m");
		fgets(pergunta1, sizeof(pergunta1), stdin);
		Console(5, 20);
		printf("2. \033[36mQuais aspectos voce acha que poderiam ser melhorados? \033[0m");
		fgets(pergunta2, sizeof(pergunta2), stdin);

		Console(5, 22);
		printf("3. \033[36mHa algum recurso que voce gostaria de ver adcionado? \033[0m");
		fgets(pergunta3, sizeof(pergunta3), stdin);

		Console(5, 24);
		printf("4. \033[36mAlgum outro comentario ou sugestao? \033[0m");
		fgets(pergunta4, sizeof(pergunta4), stdin);

		Console(99, 26);
		printf("SALVAR? (\033[32mS\033[0m/\033[31mN\033[0m):");
		scanf_s("%d", &tecla);
	

		
		
		
	} while (1);
	return MenuDeGestaoHortifrut();
}