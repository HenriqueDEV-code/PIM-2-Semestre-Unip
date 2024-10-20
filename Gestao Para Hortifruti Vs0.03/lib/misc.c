#include "../include/misc.h"

/*
@params [message], indica a mensagem que será feita para mostrar na tela de notificação
@params [iconType], indica o tipo do icone a ser usado da mensagem
@samples 
		showNotification(L"Cadastro realizado com sucesso!", MB_ICONINFORMATION);
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

/*
 A funcao Console tem como responsabilidade manipular aonde sera exibido a
 informação no console do programa.
   +-----------------+
   |    Exemplo      |
   +-----------------+
*/
int Console(int x, int y)
{
	SetConsoleOutputCP(CP_UTF8);

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* Criei essa funcao para desenhar um limite de Console usando + - |
* Entrando com dois parametros largura e altura Ex.: 120, 30 que é o
* tamanho do console quando inicia
*/
void borda(int largura, int altura)
{

	/* Desenha o limite da area total do console
	*  Linha superior +----------+
	*/
	Console(0, 0);
	printf("\033[32m+\033[0m");
	for (int i = 0; i < largura - 2; i++)
	{
		printf("\033[32m-\033[0m");
	}
	printf("\033[32m+\033[0m");


	/* Colunas direita e esquerda
	*  +---------------------+
	*  |                     |
	*  +---------------------+
	*/

	for (int i = 1; i < altura - 1; i++)
	{
		Console(0, i);
		printf("\033[32m|\033[0m");
		Console(largura - 1, i);
		printf("\033[32m|\033[0m");
	}

	/* Linha superior +----------+ */
	Console(0, altura - 1);
	printf("\033[32m+\033[0m");
	for (int i = 0; i < largura - 2; i++)
	{
		printf("\033[32m-\033[0m");
	}
	printf("\033[32m+\033[0m");

}


/* Funcao para limpar o buffer da entrada de dados */
void Limpar_Buffer()
{
	int c = 0;
	while ((c = getchar() != '\n' && c != EOF));
}


/* Funcao para ler entrada do tipo inteiro com validação */
void Ler_Int(int* valor, const char* mensagem)
{
	printf("%s", mensagem);
	while (scanf("%d", valor) != 1 || *valor < 0)
	{
		Console(5, 2);
		printf("\aENTRADA INVALIDA❗ TENTE NOVAMENTE.");
		Limpar_Buffer();
		Sleep(500);
		system("CLS");
		// EntradaMercadoria();
	}
	Limpar_Buffer();
}

/* Funcao para ler entrada do tipo float com validação */
void Ler_Float(float* valor, const char* mensagem)
{
	printf("%s", mensagem);
	while (scanf("%f", valor) != 1 || *valor < 0)
	{
		Console(5, 2);
		printf("\aENTRADA INVALIDA❗ TENTE NOVAMENTE.");
		Limpar_Buffer();
		Sleep(500);
		system("CLS");
		return EntradaMercadoria();
	}
	Limpar_Buffer();
}

void Ler_String(char* str, int max_tamanho, const char* mensagem)
{
	printf("%s", mensagem);
	fgets(str, max_tamanho, stdin);
	str[strcspn(str, "\n")] = 0; // Remove o '\n' da string
}

void Ler_Unidade_Medida(char* medida, int max_tamanho, const char* mensagem)
{
	int valido = 0;

	while (!valido)
	{
		printf("%s", mensagem);
		fgets(medida, max_tamanho, stdin); // le ate 3 caracteres + '\0'
		medida[strcspn(medida, "\n")] = 0; // Remove o '\n'

		/* Verifica se a entrada e uma das tres opcoes sao validas */
		if (strcmp(medida, "UN") == 0 || strcmp(medida, "CX") == 0 || strcmp(medida, "KG") == 0)
		{
			valido = 1; // entrada valida
		}
		else
		{
			Console(5, 2);
			printf("\aENTRADA INVALIDA❗ POR FAVOR, INSIRA UN, CX OU KG.");
			Sleep(500);
			system("CLS");
			return EntradaMercadoria();
		}
	}
}


/* Funcao para validar a data em formato em YYYY-MM-DD */
int Validade_Data(const char* data) {
	if (strlen(data) != 10 || data[4] != '-' || data[7] != '-') return 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7) continue;
		if (!isdigit(data[i])) return 0;
	}
	return 1;
}
