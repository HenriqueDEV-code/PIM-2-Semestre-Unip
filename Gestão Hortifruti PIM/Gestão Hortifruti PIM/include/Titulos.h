
#include <stdio.h>
#include <Windows.h>
#include <strsafe.h>
#include <conio.h>

/* Responsavel por posicionar o ponteiro no console para onde a informacao sera exibida ou extraida E|S */
int CL(int coluna, int linha)
{
	COORD coord;
	coord.X = coluna;
	coord.Y = linha;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void MenuDeGestao()
{
	

	Sleep(2);
	system("CLS");
	CL(118,1);
	printf("❌");
	/*=======================================================LOGO-CAIXA======================================================*/
	CL(11, 3);
	printf("\033[33m▒█▀▀█ ▒█▀▀▀ ▒█▀▀▀█ ▀▀█▀▀ ░█▀▀█ ▒█▀▀▀█ 　 ░░ 　 ▒█░▒█ ▒█▀▀▀█ ▒█▀▀█ ▀▀█▀▀ ▒█▀▀▀ ▒█▀▀█ ▒█░▒█ ▀▀█▀▀ ▀█▀");
	CL(11, 4);
	printf("▒█░▄▄ ▒█▀▀▀ ░▀▀▀▄▄ ░▒█░░ ▒█▄▄█ ▒█░░▒█ 　 ▀▀ 　 ▒█▀▀█ ▒█░░▒█ ▒█▄▄▀ ░▒█░░ ▒█▀▀▀ ▒█▄▄▀ ▒█░▒█ ░▒█░░ ▒█░");
	CL(11, 5);
	printf("▒█▄▄█ ▒█▄▄▄ ▒█▄▄▄█ ░▒█░░ ▒█░▒█ ▒█▄▄▄█ 　 ░░ 　 ▒█░▒█ ▒█▄▄▄█ ▒█░▒█ ░▒█░░ ▒█░░░ ▒█░▒█ ░▀▄▄▀ ░▒█░░ ▄█▄\033[0m");
	/*=====================================================================================================================*/


	/*===========================================================================================================================*/
	CL(11, 11); printf("\033[35m𝗖𝗔𝗗𝗔𝗦𝗧𝗥𝗢𝗦 💻");                     CL(11, 17); printf("𝗥𝗘𝗟𝗔𝗧𝗢𝗥𝗜𝗢 𝗚𝗘𝗥𝗔𝗟 𝗗𝗢 𝗦𝗜𝗦𝗧𝗘𝗠𝗔 📊");
	CL(11, 13); printf("𝗩𝗘𝗡𝗗𝗔𝗦 💳");                                CL(11, 19); printf("𝗤𝗨𝗘𝗠 𝗦𝗢𝗠𝗢𝗦 📎");
	CL(11, 15); printf("𝗣𝗘𝗦𝗤𝗨𝗜𝗦𝗔 𝗗𝗘 𝗣𝗥𝗢𝗗𝗨𝗧𝗢𝗦 🔎");                  CL(11, 21); printf("𝗦𝗨𝗚𝗘𝗦𝗧𝗢𝗘𝗦 🗣");
																     CL(11, 23); printf("𝗦𝗜𝗦𝗧𝗘𝗠𝗔 𝗗𝗘 𝗗𝗢𝗔𝗖𝗢𝗘𝗦 🎁\033[0m");
	/*===========================================================================================================================*/
	CL(12, 28);
	printf("Usar -> " "\033[31m↑ ↓\033[0m" " para se guiar no menu. O" "\033[32m ENTER \033[0m" "para confirmar e o ❌ para sair ou retorna");
	CL(43, 8);
	printf("\033[36m𝕮𝖔𝖓𝖓𝖊𝖈𝖙𝖎𝖔𝖓 𝖆𝖓𝖉 𝕾𝖔𝖑𝖚𝖙𝖎𝖔𝖓 ©");
	CL(105, 28);
	printf(" \033[36m Vs 0.0.2\033[0m");

	
}



void MenuCadastroMercadorias() {
	
		CL(118, 1);
		printf("❌");

		/*=====================================================================================================================*/
		CL(40, 2);
		printf("\033[33mＥＮＴＲＡＤＡ ＤＥ ＭＥＲＣＡＤＯＲＩＡ\033[0m");
		/*=====================================================================================================================*/

		CL(11, 4);
		printf("\033[31m*\033[0m""DESCRICAO: ");
		CL(11, 6);
		printf(" GRUPO: ");
		CL(11, 8);
		printf(" DATA (00-00-0000): ");
		CL(11, 10);
		printf("\033[31m*\033[0m""UNIDADE DE MEDIDA (UN|CX|KG): ");
		CL(11, 12);
		printf("\033[31m*\033[0m""PRECO DE COMPRA: ");
		CL(11, 14);
		printf("\033[31m*\033[0m""MARGEM DE LUCRO: ");
		CL(11, 16);
		printf("QUANTIDADE DE ESTOQUE: ");
		CL(12, 27);
		printf("Usar -> " "\033[31m↑ ↓\033[0m" " para se guiar no menu. O" "\033[32m ENTER \033[0m" "para confirmar e o ❌ para sair ou retorna");
		CL(27, 28);
		printf("Linhas com marcacao -> " "\033[31m*\033[0m" " sao obrigatorio o preenchimento");
		CL(11, 18);
    	printf(" CONFIRMAR: ");
}

/*
@params [message], indica a mensagem que será feita para mostrar na tela de notificação
@params [iconType], indica o tipo do icone a ser usado da mensagem
@samples showNotification(L"Cadastro realizado com sucesso!", MB_ICONINFORMATION);
		showNotification(L"Erro ao realizar cadastro!", MB_ICONERROR);
		showNotification(L"Atenção: Verifique os dados inseridos.", MB_ICONWARNING);

*/
void showNotification(LPCWSTR message, UINT iconType) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd == NULL) {
        MessageBoxW(NULL, L"Failed to get console window handle", L"Error", MB_OK | MB_ICONERROR);
        return;
    }

    MessageBoxW(hwnd, message, L"Notification", MB_OK | iconType);
}

void MenuFluxoDeCaixa() {}
void MenuDePesquisaPreco(){}