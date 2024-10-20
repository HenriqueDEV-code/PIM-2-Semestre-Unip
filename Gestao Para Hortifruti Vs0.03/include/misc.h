#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

typedef enum {
	ENTER = 13
} Keys;



int Console(int x, int y);
void borda(int largura, int altura);
void Limpar_Buffer();
int Validade_Data(const char* data);
void Ler_Int(int* valor, const char* mensagem);
void Ler_Float(float* valor, const char* mensagem);
void Ler_String(char* str, int max_tamanho, const char* mensagem);
void Ler_Unidade_Medida(char* medida, int max_tamanho, const char* mensagem);
void showNotification(LPCWSTR message, UINT iconType);
void EntradaMercadoria(void);